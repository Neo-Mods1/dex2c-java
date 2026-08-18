package bin.nt.dex2c.build;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
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
import java.util.regex.Pattern;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import com.android.tools.smali.dexlib2.DexFileFactory;
import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;
import com.android.tools.smali.dexlib2.iface.ClassDef;
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
        int nativeApi = cli.nativeApi > 0 ? cli.nativeApi : minSdk;
        if (nativeApi < minSdk) {
            throw new IOException("native API " + nativeApi + " cannot be below min SDK " + minSdk);
        }

        List<Path> dexes = Main.InputDexes.extract(input, work.resolve("dex"));
        Main.applyFilterFile(cli);
        BinaryXml.Manifest man = BinaryXml.read(input);
        if (cli.filter == null && man != null) {
            String def = Main.defaultFilter(man);
            if (def != null) {
                cli.filter = def;
                Main.info(cli, "build: default filter " + cli.filter
                        + " (compile only the app package tree, pass --filter to override)");
            }
        }
        if (!cli.allowGlobal && ".*".equals(cli.filter)) {
            throw new IOException("Global filter .* requires --allow-global"
                    + " (converting all classes to native is unstable)");
        }
        Main.applyAugments(cli, dexes);
        String appClass = resolveAppClass(man);
        boolean nativeStage = cli.nativeEnabled == null || cli.nativeEnabled;
        ClassDef loader = null;
        String appOverride = null;
        if (appClass == null) {
            if (!nativeStage) {
                throw new IOException("no Application class; enable native protection or use --no-build");
            }
            String loaderType = loaderType(man, cli.customLoader, dexes);
            loader = DexRewriter.loaderClass(loaderType, libName);
            appOverride = loaderType.substring(1, loaderType.length() - 1).replace('/', '.');
            if (cli.excludes == null) {
                cli.excludes = new ArrayList<>();
            }
            String keep = Pattern.quote(loaderType);
            if (!cli.excludes.contains(keep)) {
                cli.excludes.add(keep);
            }
            Main.info(cli, "build: no Application class; generated loader " + loaderType);
        }
        List<Method> compiled = new ArrayList<>();
        StringBuilder cpp = new StringBuilder(Compiler.HEADER);
        Compiler compiler = new Compiler(cli, appClass != null && targeted(cli, appClass) ? appClass : null);
        for (Path dex : dexes) {
            DexBackedDexFile df = DexFileFactory.loadDexFile(dex.toFile(), null);
            long t0 = System.currentTimeMillis();
            System.err.println("compile: " + dex.getFileName());
            compiler.compileInto(df, cpp, compiled);
            System.err.println("compile: " + dex.getFileName() + " done in "
                    + (System.currentTimeMillis() - t0) + " ms");
        }
        Main.info(cli, "build: " + compiled.size() + " methods compiled to native");
        System.out.flush();
        if (compiled.isEmpty()) {
            System.out.println("build: warning - nothing was compiled; the APK will still load the library");
        }

        List<String> abis = cli.libAbis != null ? splitAbis(cli.libAbis) : apkAbis(input);
        Path proj = cli.sourceDir != null ? Paths.get(cli.sourceDir) : work.resolve("project");
        NdkProject.write(proj, libName, minSdk, nativeApi, abis, cli.dynamicRegister, compiled,
                Compiler.mappable(cpp.toString()));
        Main.info(cli, "build: project written to " + proj.toAbsolutePath()
                + " (" + compiled.size() + " methods in jni/nc)");
        System.out.flush();
        if (cli.sourceDir == null) {
            Path zip = Paths.get("project-source.zip");
            zipProject(proj, zip);
            Main.info(cli, "build: source archive at " + zip.toAbsolutePath());
            System.out.flush();
        }

        if (cli.noBuild || !nativeStage) {
            Main.info(cli, "build: source only, project at " + proj.toAbsolutePath());
            if (cli.noBuild) {
                return;
            }
        } else {
            ToolRunner.run(List.of(ToolRunner.findNdkBuild(cli.ndkDir), "-C", proj.toString()));
        }

        Set<String> compiledSet = new HashSet<>();
        for (Method m : compiled) {
            compiledSet.add(m.getDefiningClass() + m.getName() + Main.descriptor(m));
        }
        Map<String, Path> newDexes = new LinkedHashMap<>();
        boolean first = true;
        for (Path dex : dexes) {
            String dexName = dex.getFileName().toString();
            if (nativeStage) {
                Path rewritten = work.resolve("new-" + dexName);
                DexRewriter.rewrite((DexBackedDexFile) DexFileFactory.loadDexFile(dex.toFile(), null),
                        rewritten, compiledSet, appClass, libName, first ? loader : null);
                newDexes.put(dexName, rewritten);
            } else {
                newDexes.put(dexName, dex);
            }
            first = false;
        }

        Map<String, Path> libs = new LinkedHashMap<>();
        for (String abi : abis) {
            Path so = proj.resolve("libs").resolve(abi).resolve("lib" + libName + ".so");
            if (Files.isRegularFile(so)) {
                libs.put(abi, so);
            }
        }

        Path unsigned = work.resolve("unsigned.apk");
        assembleWithApkTool(resolveApktool(cli.apktool), input, work, unsigned,
                newDexes, libs, appOverride, cli.targetSdk);
        List<String> zipalign = new ArrayList<>();
        zipalign.add(ToolRunner.findTool(cli.zipalign, "zipalign"));
        zipalign.add("-f");
        zipalign.add("-P");
        zipalign.add("16");
        zipalign.add("4");
        if (cli.disableSigning) {
            List<String> out = new ArrayList<>(zipalign);
            out.add(unsigned.toString());
            out.add(outApk.toString());
            ToolRunner.run(out);
        } else {
            Path aligned = work.resolve("aligned.apk");
            List<String> out = new ArrayList<>(zipalign);
            out.add(unsigned.toString());
            out.add(aligned.toString());
            ToolRunner.run(out);
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
            sign.add("--max-sdk-version");
            sign.add(String.valueOf(cli.maxSdk > 0 ? cli.maxSdk : 37));
            if (cli.signV1 != null) {
                sign.add("--v1-signing-enabled");
                sign.add(String.valueOf(cli.signV1));
            }
            if (cli.signV2 != null) {
                sign.add("--v2-signing-enabled");
                sign.add(String.valueOf(cli.signV2));
            }
            if (cli.signV3 != null) {
                sign.add("--v3-signing-enabled");
                sign.add(String.valueOf(cli.signV3));
            }
            sign.add("--out");
            sign.add(outApk.toString());
            sign.add(aligned.toString());
            ToolRunner.run(sign);
        }
        Main.info(cli, "build: wrote " + outApk.toAbsolutePath()
                + " (" + compiled.size() + " native methods, libs=" + libs.keySet() + ")");
    }

    /**
     * Decides whether the Application class is itself a compile target, in
     * which case its {@code <clinit>} is spared so the injected
     * {@code System.loadLibrary} keeps running from the DEX.
     *
     * @param cli      the CLI options
     * @param appClass the Application class type ({@code L...;})
     * @return {@code true} when the class passes the filters
     */
    static boolean targeted(Main.Cli cli, String appClass) {
        if (cli.excludes != null) {
            for (String rx : cli.excludes) {
                if (Pattern.compile(rx).matcher(appClass).find()) {
                    return false;
                }
            }
        }
        return cli.filter == null || Pattern.compile(cli.filter).matcher(appClass).find();
    }

    /**
     * Picks the generated loader class type: {@code --custom-loader} when
     * given, otherwise the app package's own {@code App} class
     * ({@code <pkg>.App}), else the default {@code bin.nt.utils.NativeLoader}.
     * A numeric suffix avoids colliding with an existing class.
     */
    static String loaderType(BinaryXml.Manifest man, String custom, List<Path> dexes) {
        String dotted;
        if (custom != null && !custom.isEmpty()) {
            dotted = custom.startsWith("L") && custom.endsWith(";")
                    ? custom.substring(1, custom.length() - 1) : custom;
        } else if (man != null && man.pkg != null && !man.pkg.isEmpty()) {
            dotted = man.pkg + ".App";
        } else {
            dotted = "bin.nt.utils.NativeLoader";
        }
        Set<String> existing = new HashSet<>();
        for (Path dex : dexes) {
            try {
                DexBackedDexFile df = (DexBackedDexFile) DexFileFactory.loadDexFile(dex.toFile(), null);
                for (ClassDef c : df.getClasses()) {
                    existing.add(c.getType());
                }
            } catch (IOException ignored) {
            }
        }
        String type = "L" + dotted.replace('.', '/') + ";";
        if (!existing.contains(type)) {
            return type;
        }
        int slash = type.lastIndexOf('/');
        String pkgPrefix = type.substring(0, slash + 1);
        for (int n = 2; ; n++) {
            String alt = pkgPrefix + "App" + n + ";";
            if (!existing.contains(alt)) {
                return alt;
            }
        }
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

    /** Zips a project directory into {@code out} for archival. */
    private static void zipProject(Path root, Path out) throws IOException {
        try (java.util.zip.ZipOutputStream z = new java.util.zip.ZipOutputStream(
                java.nio.file.Files.newOutputStream(out))) {
            java.nio.file.Files.walk(root).filter(p -> java.nio.file.Files.isRegularFile(p))
                    .forEach(p -> {
                        try {
                            z.putNextEntry(new java.util.zip.ZipEntry(
                                    root.relativize(p).toString().replace('\\', '/')));
                            java.nio.file.Files.copy(p, z);
                            z.closeEntry();
                        } catch (IOException e) {
                            throw new java.io.UncheckedIOException(e);
                        }
                    });
        }
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

    /**
     * Resolves the apktool jar: {@code --apktool}, {@code APKTOOL_JAR}, or an
     * {@code apktool} executable on PATH.
     */
    static String resolveApktool(String flag) throws IOException {
        if (flag != null && !"PATH".equals(flag)) {
            Path t = Paths.get(flag);
            if (Files.isRegularFile(t)) {
                return t.toString();
            }
            throw new IOException("apktool jar not found at " + flag);
        }
        String env = System.getenv("APKTOOL_JAR");
        if (env != null && Files.isRegularFile(Paths.get(env))) {
            return env;
        }
        String path = System.getenv("PATH");
        if (path != null) {
            for (String dir : path.split(java.io.File.pathSeparator)) {
                if (dir.isEmpty()) {
                    continue;
                }
                Path t = Paths.get(dir, "apktool");
                if (Files.isExecutable(t)) {
                    return t.toString();
                }
            }
        }
        throw new IOException("apktool not found; pass --apktool or set APKTOOL_JAR");
    }

    /**
     * Rebuilds the APK with apktool: decodes with sources kept raw, splices
     * the rewritten dex files and the compiled JNI libraries, patches the
     * decoded manifest, and rebuilds the archive.
     */
    static void assembleWithApkTool(String apktool, Path input, Path work, Path out,
                                    Map<String, Path> dexes, Map<String, Path> libs,
                                    String appOverride, int targetSdk) throws IOException {
        Path dir = work.resolve("apktool-out");
        ToolRunner.run(List.of("java", "-jar", apktool, "d", "-f", "-s",
                input.toString(), "-o", dir.toString()));
        for (Map.Entry<String, Path> e : dexes.entrySet()) {
            Path dst = dir.resolve(e.getKey());
            if (Files.isRegularFile(dst)) {
                Files.copy(e.getValue(), dst, java.nio.file.StandardCopyOption.REPLACE_EXISTING);
            }
        }
        for (Map.Entry<String, Path> e : libs.entrySet()) {
            Path d = dir.resolve("lib").resolve(e.getKey());
            Files.createDirectories(d);
            Files.copy(e.getValue(), d.resolve(e.getValue().getFileName()),
                    java.nio.file.StandardCopyOption.REPLACE_EXISTING);
        }
        if (appOverride != null) {
            patchManifestApp(dir.resolve("AndroidManifest.xml"), appOverride);
        }
        if (targetSdk > 0) {
            patchManifestTargetSdk(dir.resolve("AndroidManifest.xml"), targetSdk);
        }
        patchApktoolNoCompress(dir);
        ToolRunner.run(List.of("java", "-jar", apktool, "b", dir.toString(),
                "-o", out.toString()));
        storeLibEntries(out);
    }

    /** Updates targetSdkVersion only when the user explicitly requested it. */
    static void patchManifestTargetSdk(Path manifest, int targetSdk) throws IOException {
        String xml = Files.readString(manifest, StandardCharsets.UTF_8);
        String attr = "android:targetSdkVersion=\"" + targetSdk + "\"";
        String patched;
        if (xml.matches("(?s).*android:targetSdkVersion=\"[^\"]*\".*")) {
            patched = xml.replaceFirst("android:targetSdkVersion=\"[^\"]*\"", attr);
        } else {
            patched = xml.replaceFirst("(<uses-sdk\\b[^>]*)", "$1 " + attr);
        }
        if (patched.equals(xml)) {
            throw new IOException("Could not patch targetSdkVersion in " + manifest);
        }
        Files.writeString(manifest, patched, StandardCharsets.UTF_8);
    }

    /** Adds {@code so} to the decoded {@code apktool.yml} no-compress list. */
    static void patchApktoolNoCompress(Path dir) throws IOException {
        Path yml = dir.resolve("apktool.yml");
        if (!Files.isRegularFile(yml)) {
            throw new IOException("apktool.yml missing after decode");
        }
        List<String> lines = new ArrayList<>(
                Files.readAllLines(yml, StandardCharsets.UTF_8));
        int idx = lines.indexOf("doNotCompress:");
        if (idx < 0) {
            lines.add("");
            lines.add("doNotCompress:");
            lines.add("- so");
        } else {
            boolean hasSo = false;
            int i = idx + 1;
            while (i < lines.size()) {
                String t = lines.get(i).trim();
                if (t.isEmpty() || t.startsWith("#")) {
                    i++;
                    continue;
                }
                if (!t.startsWith("-")) {
                    break;
                }
                if (t.equals("- so")) {
                    hasSo = true;
                    break;
                }
                i++;
            }
            if (!hasSo) {
                lines.add(idx + 1, "- so");
            }
        }
        Files.write(yml, lines, StandardCharsets.UTF_8);
    }

    /**
     * Rewrites the built APK so every {@code lib/} entry is stored
     * uncompressed, keeping every other entry byte-identical (compression
     * method included).
     */
    static void storeLibEntries(Path apk) throws IOException {
        Path tmp = apk.resolveSibling(apk.getFileName() + ".store");
        try (ZipFile z = new ZipFile(apk.toFile());
             java.util.zip.ZipOutputStream out = new java.util.zip.ZipOutputStream(
                     Files.newOutputStream(tmp))) {
            Enumeration<? extends ZipEntry> en = z.entries();
            while (en.hasMoreElements()) {
                ZipEntry e = en.nextElement();
                boolean lib = e.getName().startsWith("lib/");
                ZipEntry n = new ZipEntry(e.getName());
                n.setTime(e.getTime());
                n.setComment(e.getComment());
                n.setExtra(e.getExtra());
                n.setMethod(lib ? ZipEntry.STORED : e.getMethod());
                if (lib) {
                    n.setCompressedSize(e.getSize());
                    n.setCrc(e.getCrc() >= 0 ? e.getCrc() : crcOf(z, e));
                } else {
                    n.setCompressedSize(e.getCompressedSize());
                    n.setCrc(e.getCrc());
                }
                n.setSize(e.getSize());
                out.putNextEntry(n);
                try (java.io.InputStream in = z.getInputStream(e)) {
                    in.transferTo(out);
                }
                out.closeEntry();
            }
        }
        Files.move(tmp, apk, java.nio.file.StandardCopyOption.REPLACE_EXISTING);
    }

    private static long crcOf(ZipFile z, ZipEntry e) throws IOException {
        java.util.zip.CRC32 c = new java.util.zip.CRC32();
        try (java.io.InputStream in = z.getInputStream(e)) {
            byte[] buf = new byte[8192];
            int n;
            while ((n = in.read(buf)) >= 0) {
                c.update(buf, 0, n);
            }
        }
        return c.getValue();
    }

    /** Points the decoded manifest's application tag at the loader class. */
    static void patchManifestApp(Path manifest, String dotted) throws IOException {
        String xml = new String(Files.readAllBytes(manifest), StandardCharsets.UTF_8);
        String patched = xml.replaceFirst(
                "(<application[^>]*?\\bandroid:name=\")([^\"]*)(\")", "$1" + dotted + "$3");
        if (patched.equals(xml)) {
            throw new IOException("application android:name not found in " + manifest);
        }
        Files.write(manifest, patched.getBytes(StandardCharsets.UTF_8));
    }
}
