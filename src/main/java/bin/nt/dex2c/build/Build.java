package bin.nt.dex2c.build;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import com.android.tools.smali.dexlib2.DexFileFactory;
import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;
import com.android.tools.smali.dexlib2.iface.Method;

import bin.nt.dex2c.Compiler;
import bin.nt.dex2c.Main;

/**
 * Full dex2c APK pipeline: compile → NDK build → mark native → repack →
 * zipalign → sign.
 *
 * <p>Mirrors the reference {@code dcc.py} flow: every compiled method is
 * declared {@code native} in a rewritten DEX, a {@code System.loadLibrary}
 * call is injected into the Application class {@code <clinit>}, the JNI
 * library built with ndk-build is dropped into {@code lib/<abi>/}, and the
 * result is aligned and signed.</p>
 */
public final class Build {

    private static final Set<String> SUPPORTED_ABIS =
            new HashSet<>(Arrays.asList("armeabi-v7a", "arm64-v8a", "x86", "x86_64"));

    private Build() {
    }

    /**
     * Runs the full pipeline.
     *
     * @param cli    the parsed command line
     * @param input  the input APK
     * @param outApk the output APK path
     * @throws Exception on any failure
     */
    public static void run(Main.Cli cli, Path input, Path outApk) throws Exception {
        if (!input.getFileName().toString().toLowerCase(Locale.ROOT).endsWith(".apk")) {
            throw new IOException("build requires an .apk input");
        }
        Path parent = outApk.toAbsolutePath().getParent();
        if (parent != null) {
            Files.createDirectories(parent);
        }
        Path work = Files.createTempDirectory("dex2c-build-");
        String libName = cli.libName != null && !cli.libName.isEmpty() ? cli.libName : "stub";
        int minSdk = cli.minSdk > 0 ? cli.minSdk : 21;

        List<Path> dexes = Main.InputDexes.extract(input, work.resolve("dex"));
        List<Method> compiled = new ArrayList<>();
        StringBuilder cpp = new StringBuilder(Compiler.HEADER);
        Compiler compiler = new Compiler(cli);
        for (Path dex : dexes) {
            DexBackedDexFile df = DexFileFactory.loadDexFile(dex.toFile(), null);
            compiler.compileInto(df, cpp, compiled);
        }
        System.out.println("build: " + compiled.size() + " methods compiled to native");
        if (compiled.isEmpty()) {
            System.out.println("build: warning - nothing was compiled; the APK will still load the library");
        }

        List<String> abis = cli.libAbis != null ? splitAbis(cli.libAbis) : apkAbis(input);
        Path proj = cli.sourceDir != null ? Paths.get(cli.sourceDir) : work.resolve("project");
        NdkProject.write(proj, libName, minSdk, abis, cli.dynamicRegister, compiled,
                Compiler.mappable(cpp.toString()));

        if (cli.noBuild) {
            System.out.println("build: source only, project at " + proj.toAbsolutePath());
            return;
        }
        ToolRunner.run(List.of(ToolRunner.findNdkBuild(cli.ndkDir), "-C", proj.toString()));

        BinaryXml.Manifest man = BinaryXml.read(input);
        String appClass = resolveAppClass(man);
        if (appClass == null) {
            throw new IOException("AndroidManifest.xml has no application android:name; cannot inject System.loadLibrary");
        }

        Set<String> compiledSet = new HashSet<>();
        for (Method m : compiled) {
            compiledSet.add(m.getDefiningClass() + m.getName() + Main.descriptor(m));
        }
        Map<String, Path> newDexes = new LinkedHashMap<>();
        int di = 0;
        for (Path dex : dexes) {
            String dexName = dex.getFileName().toString();
            NativeMarker.mark(dex, work.resolve("new-" + dexName), work.resolve("smali" + di++),
                    compiledSet, appClass, libName);
            newDexes.put(dexName, work.resolve("new-" + dexName));
        }

        Map<String, Path> libs = new LinkedHashMap<>();
        for (String abi : abis) {
            Path so = proj.resolve("libs").resolve(abi).resolve("lib" + libName + ".so");
            if (Files.isRegularFile(so)) {
                libs.put(abi, so);
            }
        }

        Path unsigned = work.resolve("unsigned.apk");
        ApkRebuilder.rebuild(input, unsigned, newDexes, libs, libName);
        if (cli.disableSigning) {
            ToolRunner.run(List.of(ToolRunner.findTool(cli.zipalign, "zipalign"), "-f", "4",
                    unsigned.toString(), outApk.toString()));
        } else {
            Path aligned = work.resolve("aligned.apk");
            ToolRunner.run(List.of(ToolRunner.findTool(cli.zipalign, "zipalign"), "-f", "4",
                    unsigned.toString(), aligned.toString()));
            List<String> sign = new ArrayList<>();
            sign.add(ToolRunner.findTool(cli.apksigner, "apksigner"));
            sign.add("sign");
            sign.add("--ks");
            sign.add((cli.keystore != null ? Paths.get(cli.keystore) : ToolRunner.debugKeystore(work)).toString());
            sign.add("--ks-key-alias");
            sign.add(cli.alias != null ? cli.alias : "androiddebugkey");
            sign.add("--ks-pass");
            sign.add("pass:" + (cli.ksPass != null ? cli.ksPass : "android"));
            sign.add("--key-pass");
            sign.add("pass:" + (cli.keyPass != null ? cli.keyPass : "android"));
            sign.add("--min-sdk-version");
            sign.add(String.valueOf(minSdk));
            sign.add("--out");
            sign.add(outApk.toString());
            sign.add(aligned.toString());
            ToolRunner.run(sign);
        }
        System.out.println("build: wrote " + outApk.toAbsolutePath()
                + " (" + compiled.size() + " native methods, libs=" + libs.keySet() + ")");
    }

    /** Resolves the Application class descriptor, handling relative names. */
    static String resolveAppClass(BinaryXml.Manifest man) {
        String app = man == null ? null : man.appName;
        if (app == null || app.isEmpty()) {
            return null;
        }
        if (app.startsWith(".")) {
            if (man.pkg == null || man.pkg.isEmpty()) {
                return null;
            }
            return "L" + man.pkg + app + ";";
        }
        return "L" + app.replace('.', '/') + ";";
    }

    private static List<String> splitAbis(String s) {
        List<String> r = new ArrayList<>();
        for (String x : s.split(",")) {
            x = x.trim();
            if (!x.isEmpty() && !r.contains(x)) {
                r.add(x);
            }
        }
        return r;
    }

    /** ABIs present in the APK's {@code lib/} directory. */
    static List<String> apkAbis(Path input) throws IOException {
        List<String> r = new ArrayList<>();
        try (ZipFile z = new ZipFile(input.toFile())) {
            Enumeration<? extends ZipEntry> e = z.entries();
            while (e.hasMoreElements()) {
                String en = e.nextElement().getName();
                if (en.startsWith("lib/")) {
                    int sl = en.indexOf('/', 4);
                    if (sl > 4) {
                        String abi = en.substring(4, sl);
                        if (SUPPORTED_ABIS.contains(abi) && !r.contains(abi)) {
                            r.add(abi);
                        }
                    }
                }
            }
        }
        return r.isEmpty() ? Arrays.asList("arm64-v8a", "armeabi-v7a") : r;
    }
}
