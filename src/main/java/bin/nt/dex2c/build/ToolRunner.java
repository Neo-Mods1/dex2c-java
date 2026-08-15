package bin.nt.dex2c.build;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Runs external toolchain binaries (ndk-build, baksmali, smali, zipalign,
 * apksigner, keytool) as subprocesses.
 *
 * <p>Output is streamed to stdout so CI logs stay useful, and any non-zero
 * exit status aborts the build with the full command line.</p>
 */
final class ToolRunner {

    private ToolRunner() {
    }

    /** Runs a command and throws on a non-zero exit. */
    static void run(List<String> cmd) throws IOException {
        System.out.println("+ " + String.join(" ", cmd));
        ProcessBuilder pb = new ProcessBuilder(cmd);
        pb.redirectErrorStream(true);
        Process p;
        try {
            p = pb.start();
        } catch (IOException e) {
            throw new IOException("Failed to start " + cmd.get(0) + ": " + e.getMessage(), e);
        }
        try (Reader r = new InputStreamReader(p.getInputStream(), StandardCharsets.UTF_8);
             BufferedReader br = new BufferedReader(r)) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }
        int code;
        try {
            code = p.waitFor();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new IOException("Interrupted while running " + cmd.get(0), e);
        }
        if (code != 0) {
            throw new IOException("Command failed with exit code " + code + ": " + String.join(" ", cmd));
        }
    }

    /** Runs a CLI entry point from this application's own classpath. */
    static void javaMain(String mainClass, List<String> args) throws IOException {
        String java = Paths.get(System.getProperty("java.home"), "bin", "java").toString();
        List<String> cmd = new ArrayList<>();
        cmd.add(java);
        cmd.add("-cp");
        cmd.add(System.getProperty("java.class.path"));
        cmd.add(mainClass);
        cmd.addAll(args);
        run(cmd);
    }

    /** Resolves {@code ndk-build} from a flag, env vars or the SDK layout. */
    static String findNdkBuild(String ndkDir) throws IOException {
        if (ndkDir != null) {
            Path b = Paths.get(ndkDir, "ndk-build");
            if (Files.isExecutable(b)) {
                return b.toString();
            }
            throw new IOException("ndk-build not found in --ndk-dir " + ndkDir);
        }
        for (String env : new String[] {"ANDROID_NDK_HOME", "ANDROID_NDK_ROOT", "ANDROID_NDK", "ANDROID_NDK_LATEST_HOME"}) {
            String v = System.getenv(env);
            if (v != null && Files.isExecutable(Paths.get(v, "ndk-build"))) {
                return Paths.get(v, "ndk-build").toString();
            }
        }
        for (String sdk : new String[] {System.getenv("ANDROID_HOME"), System.getenv("ANDROID_SDK_ROOT"),
                "/usr/local/lib/android/sdk"}) {
            if (sdk == null) {
                continue;
            }
            Path ndk = Paths.get(sdk, "ndk");
            if (Files.isDirectory(ndk)) {
                String found = firstExecutable(ndk, "ndk-build");
                if (found != null) {
                    return found;
                }
            }
        }
        throw new IOException("ndk-build not found; pass --ndk-dir or set ANDROID_NDK_HOME");
    }

    /** Resolves {@code zipalign} or {@code apksigner} from a flag, build-tools or PATH. */
    static String findTool(String flagValue, String name) throws IOException {
        if (flagValue != null && !"PATH".equals(flagValue)) {
            Path t = Paths.get(flagValue);
            if (Files.isExecutable(t)) {
                return t.toString();
            }
            throw new IOException(name + " not found at " + flagValue);
        }
        for (String sdk : new String[] {System.getenv("ANDROID_HOME"), System.getenv("ANDROID_SDK_ROOT")}) {
            if (sdk == null) {
                continue;
            }
            Path bt = Paths.get(sdk, "build-tools");
            if (Files.isDirectory(bt)) {
                String found = firstExecutable(bt, name);
                if (found != null) {
                    return found;
                }
            }
        }
        String path = System.getenv("PATH");
        if (path != null) {
            for (String dir : path.split(java.io.File.pathSeparator)) {
                if (dir.isEmpty()) {
                    continue;
                }
                Path t = Paths.get(dir, name);
                if (Files.isExecutable(t)) {
                    return t.toString();
                }
            }
        }
        throw new IOException(name + " not found; pass --" + name.toLowerCase(Locale.ROOT) + " or set ANDROID_HOME");
    }

    /** Highest-sorted subdirectory containing an executable of the given name. */
    private static String firstExecutable(Path dir, String name) throws IOException {
        try (Stream<Path> vs = Files.list(dir)) {
            List<Path> dirs = vs.filter(Files::isDirectory)
                    .sorted(Comparator.reverseOrder())
                    .collect(Collectors.toList());
            for (Path p : dirs) {
                Path t = p.resolve(name);
                if (Files.isExecutable(t)) {
                    return t.toString();
                }
            }
        }
        return null;
    }

    /** Ensures a debug keystore exists, generating one via keytool when needed. */
    static Path debugKeystore(Path workDir) throws IOException {
        Path ks = workDir.resolve("debug.keystore");
        if (Files.exists(ks)) {
            return ks;
        }
        String keytool = Paths.get(System.getProperty("java.home"), "bin", "keytool").toString();
        run(List.of(keytool, "-genkeypair",
                "-keystore", ks.toString(),
                "-alias", "androiddebugkey",
                "-keyalg", "RSA", "-keysize", "2048", "-validity", "10000",
                "-storepass", "android", "-keypass", "android",
                "-dname", "CN=Android Debug,O=Android,C=US"));
        return ks;
    }
}
