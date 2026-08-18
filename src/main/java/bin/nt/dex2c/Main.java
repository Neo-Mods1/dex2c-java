package bin.nt.dex2c;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Set;
import java.util.regex.Pattern;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import com.android.tools.smali.dexlib2.DexFileFactory;
import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;
import com.android.tools.smali.dexlib2.iface.ClassDef;
import com.android.tools.smali.dexlib2.iface.Method;

import bin.nt.dex2c.build.BinaryXml;
import bin.nt.dex2c.build.Config;
import bin.nt.dex2c.writer.CppWriter;

/**
 * Command-line entry point for {@code dex2c-cli}.
 *
 * <p>Reads an APK, ZIP or raw DEX file, extracts every {@code classes*.dex}
 * (for archives), compiles the contained methods into JNI C++ source and
 * writes the result plus a compile report into the output directory.</p>
 */
public final class Main {

    /** Version reported by {@code --version}. */
    private static final String VERSION = "2.2.0";

    private Main() {
    }

    /**
     * Program entry point.
     *
     * @param args command-line arguments, see {@link Cli#usage()}
     * @throws Exception on I/O, argument or compilation failure
     */
    public static void main(String[] args) throws Exception {
        Cli cli = Cli.parse(args);
        if (cli.help) {
            Cli.usage();
            return;
        }
        if (cli.version) {
            System.out.println("dex2c-cli " + VERSION);
            return;
        }
        Path config = Cli.configPath(cli.configPath);
        if (config != null) {
            cli.apply(Config.load(config));
        }
        validateSdkOptions(cli);
        if (cli.input == null) {
            throw new IllegalArgumentException("Missing --input");
        }
        Path input = Paths.get(cli.input);
        if (!Files.isRegularFile(input)) {
            throw new FileNotFoundException(input.toString());
        }
        if ("inspect".equals(cli.command)) {
            new Inspector().run(input);
            return;
        }
        Path out = cli.output == null ? Paths.get("dex2c-out") : Paths.get(cli.output);
        if ("build".equals(cli.command)) {
            bin.nt.dex2c.build.Build.run(cli, input, out);
            return;
        }
        Files.createDirectories(out);
        applyFilterFile(cli);
        List<Path> dexes = InputDexes.extract(input, out.resolve(".input"));
        if (cli.filter == null) {
            BinaryXml.Manifest man = null;
            try {
                man = BinaryXml.read(input);
            } catch (IOException ignored) {
            }
            String def = defaultFilter(man);
            if (def != null) {
                cli.filter = def;
                info(cli, "dex2c: default filter " + def
                        + " (compile only the app package tree, pass --filter to override)");
            }
        }
        if (!cli.allowGlobal && ".*".equals(cli.filter)) {
            throw new IllegalArgumentException("Global filter .* requires --allow-global"
                    + " (converting all classes to native is unstable)");
        }
        applyAugments(cli, dexes);
        Compiler compiler = new Compiler(cli);
        int methods = 0;
        int compiled = 0;
        for (Path dex : dexes) {
            DexBackedDexFile df = DexFileFactory.loadDexFile(dex.toFile(), null);
            Result r = compiler.compile(df, out);
            methods += r.methods;
            compiled += r.compiled;
        }
        info(cli, "dex2c: scanned " + methods + " methods, emitted " + compiled + " -> "
                + out.toAbsolutePath());
    }

    private static void validateSdkOptions(Cli c) {
        if (c.minSdk < 21 || c.minSdk > 37) {
            throw new IllegalArgumentException("--min-sdk must be between 21 and 37");
        }
        if (c.targetSdk < 0 || c.targetSdk > 37) {
            throw new IllegalArgumentException("--target-sdk must be between 21 and 37 when specified");
        }
        if (c.targetSdk > 0 && c.targetSdk < c.minSdk) {
            throw new IllegalArgumentException("--target-sdk cannot be below --min-sdk");
        }
        if (c.nativeApi != 0 && (c.nativeApi < 21 || c.nativeApi > 37)) {
            throw new IllegalArgumentException("--native-api must be between 21 and 37");
        }
        if (c.maxSdk < c.minSdk || c.maxSdk > 37) {
            throw new IllegalArgumentException("--max-sdk must be between minSdk and 37");
        }
    }

    /**
     * Loads {@code --filter} as a reference-style rules file when it names an
     * existing file: {@code #} comments, {@code !} keep rules, {@code =} exact
     * method matches and plain compile regexes, mirroring {@code dcc.py}'s
     * filter.txt handling. Plain inline regexes are left untouched.
     */
    public static void applyFilterFile(Cli c) {
        if (c.filter == null || !Files.isRegularFile(Paths.get(c.filter))) {
            return;
        }
        StringBuilder compile = new StringBuilder();
        boolean any = false;
        try {
            for (String raw : Files.readAllLines(Paths.get(c.filter), StandardCharsets.UTF_8)) {
                String line = raw.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }
                if (line.startsWith("!")) {
                    String keep = line.substring(1).trim();
                    if (c.excludes == null) {
                        c.excludes = new ArrayList<>();
                    }
                    if (!c.excludes.contains(keep)) {
                        c.excludes.add(keep);
                    }
                    String av = arrowVariant(keep);
                    if (av != null && !c.excludes.contains(av)) {
                        c.excludes.add(av);
                    }
                    any = true;
                } else if (line.startsWith("=")) {
                    String exact = line.substring(1).trim();
                    String arrow = arrowVariant(exact);
                    if (arrow == null) {
                        arrow = exact;
                    }
                    appendRule(compile, "^(?:" + Pattern.quote(exact) + "|" + Pattern.quote(arrow) + ")$");
                    any = true;
                } else {
                    appendRule(compile, line);
                    String av = arrowVariant(line);
                    if (av != null) {
                        appendRule(compile, av);
                    }
                    any = true;
                }
            }
        } catch (IOException e) {
            throw new IllegalArgumentException("Cannot read filter file " + c.filter + ": " + e.getMessage());
        }
        if (compile.length() > 0) {
            c.filter = compile.toString();
        } else if (any) {
            c.filter = "a^";
        }
    }

    private static String arrowVariant(String rule) {
        int semi = rule.lastIndexOf(';');
        if (semi >= 0 && !rule.contains("->")) {
            return rule.substring(0, semi + 1) + "->" + rule.substring(semi + 1);
        }
        return null;
    }

    private static void appendRule(StringBuilder b, String rule) {
        if (b.length() > 0) {
            b.append('|');
        }
        b.append("(?:").append(rule).append(")");
    }

    /**
     * The effective default compile filter: the app package tree, dropping the
     * last segment of a three-plus-segment package ({@code bin.nt.main} ->
     * {@code ^Lbin/nt/}) so library folders under the package still match.
     *
     * @param man the manifest facts, or {@code null}
     * @return the default filter, or {@code null} when no package exists
     */
    public static String defaultFilter(BinaryXml.Manifest man) {
        if (man == null || man.pkg == null || man.pkg.isEmpty()) {
            return null;
        }
        String[] seg = man.pkg.split("\\.");
        String root = seg.length >= 3
                ? String.join(".", java.util.Arrays.copyOf(seg, seg.length - 1))
                : man.pkg;
        return "^L" + Pattern.quote(root.replace('.', '/')) + "/";
    }

    /**
     * Applies the reference {@code MethodFilter} exclusions that are not part
     * of {@link Compiler}: {@code <clinit>} is never compiled, methods sharing
     * a name with a native method of the same class are skipped, synthetic
     * methods are skipped with {@code --skip-synthetic}, and methods whose
     * long JNI name exceeds 220 characters are skipped exactly like
     * {@code dcc.py} {@code compile_dex}.
     *
     * @param c     the CLI options (mutated in place)
     * @param dexes the extracted DEX files
     */
    public static void applyAugments(Cli c, List<Path> dexes) {
        List<String> extra = new ArrayList<>();
        extra.add(Pattern.quote("-><clinit>("));
        Set<String> natives = new HashSet<>();
        Set<String> synthetic = new HashSet<>();
        Set<String> longNames = new HashSet<>();
        for (Path dex : dexes) {
            try {
                DexBackedDexFile df = (DexBackedDexFile) DexFileFactory.loadDexFile(dex.toFile(), null);
                for (ClassDef cls : df.getClasses()) {
                    for (Method m : cls.getMethods()) {
                        int flags = m.getAccessFlags();
                        if ((flags & 0x100) != 0) {
                            natives.add(cls.getType() + "->" + m.getName());
                        }
                        if (c.skipSynthetic && (flags & 0x1000) != 0) {
                            synthetic.add(cls.getType() + "->" + m.getName() + descriptor(m));
                        }
                        if (CppWriter.JniNames.name(m).length() > 220) {
                            longNames.add(cls.getType() + "->" + m.getName() + descriptor(m));
                        }
                    }
                }
            } catch (IOException e) {
                throw new IllegalStateException("Cannot scan " + dex + ": " + e.getMessage(), e);
            }
        }
        for (String n : natives) {
            extra.add(Pattern.quote(n) + "\\(");
        }
        for (String s : synthetic) {
            extra.add(Pattern.quote(s));
        }
        for (String l : longNames) {
            extra.add(Pattern.quote(l));
        }
        if (c.excludes == null) {
            c.excludes = new ArrayList<>();
        }
        for (String e : extra) {
            if (!c.excludes.contains(e)) {
                c.excludes.add(e);
            }
        }
    }

    /** Prints to stdout unless {@code --silent} is given. */
    public static void info(Cli c, String msg) {
        if (!c.silent) {
            System.out.println(msg);
        }
    }

    /**
     * Builds the JVM method descriptor (e.g. {@code (II)I}) for a method.
     *
     * @param m the method
     * @return the descriptor string
     */
    public static String descriptor(Method m) {
        StringBuilder x = new StringBuilder("(");
        for (CharSequence p : m.getParameterTypes()) {
            x.append(p);
        }
        return x.append(")").append(m.getReturnType()).toString();
    }

    /** Counts and reports the outcome of a compilation pass. */
    static final class Result {
        int methods;
        int compiled;
        int unsupported;
    }

    /**
     * Command-line option container.
     *
     * <p>Supports both long ({@code --input}) and short ({@code -i}) forms,
     * positional input, and compile-time filters.</p>
     */
    public static final class Cli {
        public String command = "compile";
        public String input;
        public String output;
        public String filter;
        public String classFilter;
        public String methodFilter;
        public boolean help;
        public boolean version;
        public boolean dynamicRegister = true;
        public boolean skipSynthetic;
        public boolean comments = true;
        public boolean silent;
        public boolean allowGlobal;
        public String libName;
        public String customLoader;
        public String ndkDir;

        public String apktool;
        public String zipalign;
        public String apksigner;
        public String keystore;
        public String alias;
        public String ksPass;
        public String keyPass;
        public String sourceDir;
        public String libAbis;
        public int minSdk = 21;
        /** Target SDK used for signing/manifest policy when explicitly overridden. */
        public int targetSdk = 0;
        /** Native NDK API level; independent from the APK target SDK. */
        public int nativeApi = 0;
        public int maxSdk = 37;
        public boolean noBuild;
        public boolean disableSigning;
        public String configPath;
        public List<String> excludes;
        public Boolean signV1;
        public Boolean signV2;
        public Boolean signV3;
        public Boolean nativeEnabled;

        private Cli() {
        }

        /**
         * Parses the raw argument array.
         *
         * @param a the arguments
         * @return the parsed options
         */
        static Cli parse(String[] a) {
            Cli c = new Cli();
            for (int i = 0; i < a.length; i++) {
                String x = a[i];
                switch (x) {
                    case "-h":
                    case "--help":
                        c.help = true;
                        break;
                    case "-v":
                    case "--version":
                        c.version = true;
                        break;
                    case "--command":
                        c.command = a[++i];
                        break;
                    case "-i":
                    case "-a":
                    case "--input":
                        c.input = a[++i];
                        break;
                    case "-o":
                    case "--out":
                    case "--output":
                        c.output = a[++i];
                        break;
                    case "--filter":
                        c.filter = a[++i];
                        break;
                    case "--class":
                        c.classFilter = a[++i];
                        break;
                    case "--method":
                        c.methodFilter = a[++i];
                        break;
                    case "--dynamic-register":
                        c.dynamicRegister = true;
                        break;
                    case "--skip-synthetic":
                        c.skipSynthetic = true;
                        break;
                    case "--keep-synthetic":
                        c.skipSynthetic = false;
                        break;
                    case "--silent":
                        c.silent = true;
                        break;
                    case "--allow-global":
                        c.allowGlobal = true;
                        break;
                    case "--no-comments":
                        c.comments = false;
                        break;
                    case "--lib-name":
                        c.libName = a[++i];
                        break;
                    case "--custom-loader":
                        c.customLoader = a[++i];
                        break;
                    case "--ndk-dir":
                        c.ndkDir = a[++i];
                        break;
                    case "--apktool":
                        c.apktool = a[++i];
                        break;
                    case "--zipalign":
                        c.zipalign = a[++i];
                        break;
                    case "--apksigner":
                        c.apksigner = a[++i];
                        break;
                    case "--keystore":
                        c.keystore = a[++i];
                        break;
                    case "--alias":
                        c.alias = a[++i];
                        break;
                    case "--ks-pass":
                        c.ksPass = a[++i];
                        break;
                    case "--key-pass":
                        c.keyPass = a[++i];
                        break;
                    case "--source-dir":
                        c.sourceDir = a[++i];
                        break;
                    case "--lib-abis":
                        c.libAbis = a[++i];
                        break;
                    case "--min-sdk":
                        c.minSdk = Integer.parseInt(a[++i]);
                        break;
                    case "--target-sdk":
                        c.targetSdk = Integer.parseInt(a[++i]);
                        break;
                    case "--native-api":
                        c.nativeApi = Integer.parseInt(a[++i]);
                        break;
                    case "--max-sdk":
                        c.maxSdk = Integer.parseInt(a[++i]);
                        break;
                    case "--no-build":
                        c.noBuild = true;
                        break;
                    case "--disable-signing":
                        c.disableSigning = true;
                        break;
                    case "-c":
                    case "--config":
                        c.configPath = a[++i];
                        break;
                    case "--exclude":
                        if (c.excludes == null) {
                            c.excludes = new ArrayList<>();
                        }
                        c.excludes.add(a[++i]);
                        break;
                    case "--sign-v1":
                        c.signV1 = Boolean.TRUE;
                        break;
                    case "--no-sign-v1":
                        c.signV1 = Boolean.FALSE;
                        break;
                    case "--sign-v2":
                        c.signV2 = Boolean.TRUE;
                        break;
                    case "--no-sign-v2":
                        c.signV2 = Boolean.FALSE;
                        break;
                    case "--sign-v3":
                        c.signV3 = Boolean.TRUE;
                        break;
                    case "--no-sign-v3":
                        c.signV3 = Boolean.FALSE;
                        break;
                    default:
                        if (!x.startsWith("-") && c.input == null) {
                            c.input = x;
                        } else {
                            throw new IllegalArgumentException("Unknown option: " + x);
                        }
                }
            }
            return c;
        }

        /** Loads the effective config: explicit {@code --config}, else {@code protector.cfg} in CWD when present. */
        static Path configPath(String explicit) {
            if (explicit != null) {
                Path p = Paths.get(explicit);
                if (!Files.isRegularFile(p)) {
                    throw new IllegalArgumentException("Config file not found: " + explicit);
                }
                return p;
            }
            Path auto = Paths.get("protector.cfg");
            return Files.isRegularFile(auto) ? auto.toAbsolutePath() : null;
        }

        /**
         * Fills every unset option from the config file. Relative paths are
         * resolved against the CWD, exactly like {@code protect.py}, so the
         * same {@code protector.cfg} keeps working for both tools no matter
         * where {@code --config} points.
         *
         * @param cfg the parsed configuration
         */
        void apply(Config cfg) {
            nativeEnabled = cfg.nativeEnabled;
            if (input == null && !cfg.inputApk.isEmpty()) {
                input = resolve(cfg.inputApk);
            }
            if (output == null && !cfg.outputApk.isEmpty()) {
                output = resolve(cfg.outputApk);
            }
            if (filter == null) {
                filter = cfg.includeRegex();
                if (excludes == null) {
                    excludes = cfg.excludeRegexes();
                } else {
                    excludes = new ArrayList<>(excludes);
                    excludes.addAll(cfg.excludeRegexes());
                }
            }
            if (libName == null) {
                libName = cfg.nativeLib;
            }
            if (customLoader == null && !cfg.loaderClass.isEmpty()) {
                customLoader = cfg.loaderClass;
            }
            if (ndkDir == null && !cfg.ndkDir.isEmpty()) {
                ndkDir = resolve(cfg.ndkDir);
            }
            if (zipalign == null && !cfg.zipalign.isEmpty()) {
                zipalign = resolve(cfg.zipalign);
            }
            if (apksigner == null && !cfg.apksigner.isEmpty()) {
                apksigner = resolve(cfg.apksigner);
            }
            if (keystore == null && !cfg.keystore.isEmpty()) {
                keystore = resolve(cfg.keystore);
            }
            if (alias == null) {
                alias = cfg.alias;
            }
            if (ksPass == null) {
                ksPass = cfg.keystorePass;
            }
            if (keyPass == null) {
                keyPass = cfg.storePass;
            }
            if (signV1 == null) {
                signV1 = cfg.v1Enabled;
            }
            if (signV2 == null) {
                signV2 = cfg.v2Enabled;
            }
            if (signV3 == null) {
                signV3 = cfg.v3Enabled;
            }
        }

        private static String resolve(String p) {
            return Paths.get(p).toAbsolutePath().toString();
        }

        /** Prints usage information to stdout. */
        static void usage() {
            System.out.println("dex2c-cli - DEX/APK to JNI C++ source compiler\n"
                    + "Usage: java -jar dex2c-cli-all.jar [options]\n"
                    + "  -i, -a, --input <apk|dex>    Input APK or DEX\n"
                    + "  -o, --out, --output <dir|apk> Output dir (compile) or APK file (build)\n"
                    + "  --filter <regex|file>        Method filter; path to a dcc.py-style rules\n"
                    + "                               file (! keep, = exact, else regex) when it exists\n"
                    + "  --exclude <regex>            Keep methods matched (repeatable)\n"
                    + "  --class <regex>              Class descriptor filter\n"
                    + "  --method <regex>             Method name filter\n"
                    + "  --skip-synthetic             Skip synthetic methods (default: compile them)\n"
                    + "  --allow-global               Permit a global '.*' filter (not recommended)\n"
                    + "  -c, --config <file>          protector.cfg-style config (default: CWD protector.cfg)\n"
                    + "  --dynamic-register           Register natives via RegisterNatives (default)\n"
                    + "  --command <compile|build|inspect>\n"
                    + "  --silent                     Suppress informational output\n"
                    + "Build options:\n"
                    + "  --lib-name <name>            Native library module name (default: stub)\n"
                    + "  --custom-loader <class>      Loader class when no Application (default: <pkg>.App)\n"
                    + "  --ndk-dir <dir>              Android NDK root (default: discover from env)\n"
                    + "  --min-sdk <n>                APK/native minimum API (21..37, default: 21)\n"
                    + "  --target-sdk <n>             Explicit APK target API (21..37; default: preserve APK)\n"
                    + "  --native-api <n>             NDK APP_PLATFORM API (21..37; default: min SDK)\n"
                    + "  --max-sdk <n>                Max SDK passed to apksigner (default: 37)\n"
                    + "  --lib-abis <a,b,c>          Override target ABIs (default: APK lib dirs)\n"
                    + "  --no-build                  Generate the JNI project without running ndk-build\n"
                    + "  --source-dir <dir>          Write the JNI project here (default: temp)\n"
                    + "  --disable-signing           Skip zipalign/apksigner\n"
                    + "  --keystore <path>           Signing keystore (default: generated debug key)\n"
                    + "  --alias <alias>             Keystore alias (default: androiddebugkey)\n"
                    + "  --ks-pass <pass>            Keystore password (default: android)\n"
                    + "  --key-pass <pass>           Key password (default: android)\n"
                    + "  --zipalign <path>           zipalign binary (default: from build-tools)\n"
                    + "  --apksigner <path>          apksigner binary (default: from build-tools)\n"
                    + "  --apktool <jar>             apktool jar for APK assembly (default: $APKTOOL_JAR or apktool)\n"
                    + "  --sign-v1/--no-sign-v1      apksigner v1 scheme (default: v1+v2+v3)\n"
                    + "  --sign-v2/--no-sign-v2      apksigner v2 scheme\n"
                    + "  --sign-v3/--no-sign-v3      apksigner v3 scheme\n"
                    + "  -h, --help                  Show help\n");
        }
    }

    /**
     * Locates the DEX payload of an input file.
     *
     * <p>Raw {@code .dex} inputs are returned as-is; {@code .apk} and
     * {@code .zip} inputs are opened and every {@code classes*.dex} entry is
     * extracted into the given directory, sorted by dex number.</p>
     */
    public static final class InputDexes {
        private InputDexes() {
        }

        /**
         * Extracts or resolves the DEX files contained in the input.
         *
         * @param in  the input file
         * @param dir directory to receive extracted DEX files
         * @return the list of DEX paths
         * @throws IOException on I/O failure
         */
        public static List<Path> extract(Path in, Path dir) throws IOException {
            Files.createDirectories(dir);
            String n = in.getFileName().toString().toLowerCase(Locale.ROOT);
            if (n.endsWith(".dex")) {
                return List.of(in);
            }
            if (!n.endsWith(".apk") && !n.endsWith(".zip")) {
                throw new IOException("Input must be .dex, .apk or .zip");
            }
            List<Path> r = new ArrayList<>();
            try (ZipFile z = new ZipFile(in.toFile())) {
                Enumeration<? extends ZipEntry> e = z.entries();
                while (e.hasMoreElements()) {
                    ZipEntry ze = e.nextElement();
                    if (ze.isDirectory()) {
                        continue;
                    }
                    String p = ze.getName();
                    if (p.matches("classes(\\d*)\\.dex")) {
                        Path d = dir.resolve(Paths.get(p).getFileName().toString());
                        try (InputStream is = z.getInputStream(ze)) {
                            Files.copy(is, d, StandardCopyOption.REPLACE_EXISTING);
                        }
                        r.add(d);
                    }
                }
            }
            if (r.isEmpty()) {
                throw new IOException("No classes*.dex found in " + in);
            }
            r.sort(Comparator.comparingInt(Main::dexNumber));
            return r;
        }
    }

    /**
     * Orders DEX payloads so {@code classes.dex} is always processed first.
     *
     * @param p the path to a {@code classes*.dex} file
     * @return its numeric position
     */
    static int dexNumber(Path p) {
        String n = p.getFileName().toString();
        if ("classes.dex".equals(n)) {
            return 1;
        }
        if (n.startsWith("classes") && n.endsWith(".dex")) {
            try {
                return Integer.parseInt(n.substring(7, n.length() - 4));
            } catch (Exception ignored) {
            }
        }
        return Integer.MAX_VALUE;
    }

    /**
     * Dumps classes and methods of an input without compiling anything.
     */
    static final class Inspector {
        private Inspector() {
        }

        /**
         * Prints every class and method of the given input to stdout.
         *
         * @param input the APK/ZIP/DEX file to inspect
         * @throws Exception on I/O failure
         */
        void run(Path input) throws Exception {
            Path temp = Files.createTempDirectory("dex2c-inspect-");
            for (Path dex : InputDexes.extract(input, temp)) {
                DexBackedDexFile df = DexFileFactory.loadDexFile(dex.toFile(), null);
                int cls = 0;
                int m = 0;
                for (ClassDef c : df.getClasses()) {
                    cls++;
                    System.out.println(c.getType() + "  super=" + c.getSuperclass()
                            + "  flags=0x" + Integer.toHexString(c.getAccessFlags()));
                    for (Method x : c.getMethods()) {
                        m++;
                        String nativeFlag = (x.getAccessFlags() & 0x100) != 0 ? " native" : "";
                        System.out.printf("  %s%s  flags=0x%x%s%n", x.getName(), descriptor(x),
                                x.getAccessFlags(), nativeFlag);
                    }
                }
                System.out.printf("-- %s: %d classes, %d methods --%n", dex.getFileName(), cls, m);
            }
        }
    }
}
