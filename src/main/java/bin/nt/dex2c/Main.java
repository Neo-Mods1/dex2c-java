package bin.nt.dex2c;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Enumeration;
import java.util.List;
import java.util.Locale;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import com.android.tools.smali.dexlib2.DexFileFactory;
import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;
import com.android.tools.smali.dexlib2.iface.ClassDef;
import com.android.tools.smali.dexlib2.iface.Method;

/**
 * Command-line entry point for {@code dex2c-cli}.
 *
 * <p>Reads an APK, ZIP or raw DEX file, extracts every {@code classes*.dex}
 * (for archives), compiles the contained methods into JNI C++ source and
 * writes the result plus a compile report into the output directory.</p>
 */
public final class Main {

    /** Version reported by {@code --version}. */
    private static final String VERSION = "2.0.0";

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
        Files.createDirectories(out);
        List<Path> dexes = InputDexes.extract(input, out.resolve(".input"));
        Compiler compiler = new Compiler(cli);
        int methods = 0;
        int compiled = 0;
        for (Path dex : dexes) {
            DexBackedDexFile df = DexFileFactory.loadDexFile(dex.toFile(), null);
            Result r = compiler.compile(df, out);
            methods += r.methods;
            compiled += r.compiled;
        }
        System.out.printf("dex2c: scanned %d methods, emitted %d -> %s%n", methods, compiled, out.toAbsolutePath());
    }

    /**
     * Builds the JVM method descriptor (e.g. {@code (II)I}) for a method.
     *
     * @param m the method
     * @return the descriptor string
     */
    static String descriptor(Method m) {
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
    static final class Cli {
        String command = "compile";
        String input;
        String output;
        String filter;
        String classFilter;
        String methodFilter;
        boolean help;
        boolean version;
        boolean dynamicRegister;
        boolean keepSynthetic;
        boolean comments = true;

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
                    case "--input":
                        c.input = a[++i];
                        break;
                    case "-o":
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
                    case "--keep-synthetic":
                        c.keepSynthetic = true;
                        break;
                    case "--no-comments":
                        c.comments = false;
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

        /** Prints usage information to stdout. */
        static void usage() {
            System.out.println("dex2c-cli - DEX/APK to JNI C++ source compiler\n"
                    + "Usage: java -jar dex2c-cli-all.jar [options]\n"
                    + "  -i, --input <apk|dex>       Input APK or DEX\n"
                    + "  -o, --output <dir>          Output directory\n"
                    + "  --filter <regex>            Method descriptor filter\n"
                    + "  --class <regex>             Class descriptor filter\n"
                    + "  --method <regex>            Method name filter\n"
                    + "  --dynamic-register          Emit RegisterNatives metadata\n"
                    + "  --command <compile|inspect>\n"
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
    static final class InputDexes {
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
        static List<Path> extract(Path in, Path dir) throws IOException {
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
                        System.out.printf("  %s%s  flags=0x%x%n", x.getName(), descriptor(x), x.getAccessFlags());
                    }
                }
                System.out.printf("-- %s: %d classes, %d methods --%n", dex.getFileName(), cls, m);
            }
        }
    }
}
