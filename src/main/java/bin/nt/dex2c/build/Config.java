package bin.nt.dex2c.build;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * INI-style configuration compatible with the NT Protector {@code protector.cfg}
 * shared by {@code protect.py} and dex2c-cli.
 *
 * <p>Format (identical to the Python loader):
 * {@code #} starts a comment, sections are {@code [name]}, entries are
 * {@code key = value} with optional {@code "quoted"} strings, booleans, and
 * {@code [ "a", "b" ]} arrays which may span multiple lines. Unknown keys and
 * sections are ignored so the same file serves both tools.</p>
 */
public final class Config {

    /** Whether the native protection stage is enabled. */
    public boolean nativeEnabled = true;
    /** Native library name ({@code System.loadLibrary} argument). */
    public String nativeLib;
    /** Loader class override, used when the APK has no Application class. */
    public String loaderClass = "";
    /** Input APK path, resolved against the working directory. */
    public String inputApk = "";
    /** Output APK path, resolved against the working directory. */
    public String outputApk = "";
    /** NDK root directory. */
    public String ndkDir = "";
    /** apksigner binary or jar. */
    public String apksigner = "";
    /** zipalign binary. */
    public String zipalign = "";
    /** Signing keystore path. */
    public String keystore = "";
    /** Keystore alias. */
    public String alias = "";
    /** Keystore password. */
    public String keystorePass = "";
    /** Key password. */
    public String storePass = "";
    /** v1/v2/v3 signing scheme flags. */
    public boolean v1Enabled = true;
    public boolean v2Enabled = true;
    public boolean v3Enabled = true;
    /** Include filter patterns ({@code pkg/**} style class paths). */
    public List<String> include = new ArrayList<>();
    /** Exclude filter patterns. */
    public List<String> exclude = new ArrayList<>();

    private Config() {
    }

    /**
     * Loads a config file, falling back to built-in defaults on I/O errors.
     *
     * @param path the config file
     * @return the parsed configuration
     * @throws IOException on read failure
     */
    public static Config load(Path path) throws IOException {
        return parse(Files.readAllLines(path, StandardCharsets.UTF_8));
    }

    private static Config parse(List<String> lines) {
        Config cfg = new Config();
        String section = "";
        for (int i = 0; i < lines.size(); i++) {
            String line = stripComment(lines.get(i)).trim();
            if (line.isEmpty()) {
                continue;
            }
            if (line.startsWith("[") && line.endsWith("]")) {
                section = line.substring(1, line.length() - 1).trim();
                continue;
            }
            int eq = line.indexOf('=');
            if (eq < 0) {
                continue;
            }
            String key = line.substring(0, eq).trim();
            String value = line.substring(eq + 1).trim();
            if (value.startsWith("[")) {
                StringBuilder joined = new StringBuilder(value);
                while (!joined.toString().contains("]") && i + 1 < lines.size()) {
                    joined.append(' ').append(stripComment(lines.get(++i)).trim());
                }
                value = joined.toString();
                if (value.startsWith("[") && value.contains("]")) {
                    value = value.substring(value.indexOf('[') + 1, value.lastIndexOf(']'));
                    for (String item : value.split(",")) {
                        item = item.trim();
                        if (!item.isEmpty()) {
                            applyList(cfg, section, key, unquote(item));
                        }
                    }
                }
                continue;
            }
            apply(cfg, section, key, value);
        }
        return cfg;
    }

    private static String stripComment(String line) {
        int idx = line.indexOf('#');
        return idx >= 0 ? line.substring(0, idx) : line;
    }

    private static String unquote(String value) {
        value = value.trim();
        if (value.length() >= 2 && value.startsWith("\"") && value.endsWith("\"")) {
            return value.substring(1, value.length() - 1);
        }
        return value;
    }

    private static boolean bool(String value, String key) {
        value = value.trim();
        if ("true".equals(value)) {
            return true;
        }
        if ("false".equals(value)) {
            return false;
        }
        throw new IllegalArgumentException("Invalid boolean for " + key + ": " + value);
    }

    private static void apply(Config cfg, String section, String key, String raw) {
        String value = unquote(raw);
        switch (section) {
            case "protection":
                switch (key) {
                    case "enabled":
                        cfg.nativeEnabled = bool(value, key);
                        break;
                    case "native_lib":
                        cfg.nativeLib = value;
                        break;
                    case "loader_class":
                        cfg.loaderClass = value;
                        break;
                    default:
                        break;
                }
                break;
            case "paths":
                switch (key) {
                    case "input_apk":
                        cfg.inputApk = value;
                        break;
                    case "output_apk":
                        cfg.outputApk = value;
                        break;
                    case "ndk_dir":
                        cfg.ndkDir = value;
                        break;
                    case "apksigner":
                        cfg.apksigner = value;
                        break;
                    case "zipalign":
                        cfg.zipalign = value;
                        break;
                    default:
                        break;
                }
                break;
            case "signing":
                switch (key) {
                    case "keystore":
                        cfg.keystore = value;
                        break;
                    case "alias":
                        cfg.alias = value;
                        break;
                    case "keystore_pass":
                        cfg.keystorePass = value;
                        break;
                    case "store_pass":
                        cfg.storePass = value;
                        break;
                    case "v1_enabled":
                        cfg.v1Enabled = bool(value, key);
                        break;
                    case "v2_enabled":
                        cfg.v2Enabled = bool(value, key);
                        break;
                    case "v3_enabled":
                        cfg.v3Enabled = bool(value, key);
                        break;
                    default:
                        break;
                }
                break;
            case "filter":
                switch (key) {
                    case "include":
                        cfg.include.add(value);
                        break;
                    case "exclude":
                        cfg.exclude.add(value);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    private static void applyList(Config cfg, String section, String key, String value) {
        if ("filter".equals(section) && ("include".equals(key) || "exclude".equals(key))) {
            apply(cfg, section, key, "\"" + value + "\"");
        }
    }

    /**
     * Translates a config pattern to a dex2c regex fragment following the
     * reference translator: {@code **} crosses path segments ({@code .*}),
     * {@code *} matches within one segment ({@code [^/]*}), and every other
     * regex metacharacter is escaped.
     *
     * @param pattern the config pattern, e.g. {@code bin/nt/**}
     * @return the regex fragment
     */
    public static String translatePattern(String pattern) {
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            if (ch == '*') {
                if (i + 1 < pattern.length() && pattern.charAt(i + 1) == '*') {
                    out.append(".*");
                    i++;
                    continue;
                }
                out.append("[^/]*");
                continue;
            }
            if (".^$+?()[]{}|\\".indexOf(ch) >= 0) {
                out.append('\\');
            }
            out.append(ch);
        }
        return out.toString();
    }

    /**
     * Builds a single include regex from the include patterns, each matched
     * against internal class names ({@code Lpkg/**}).
     *
     * @return the combined regex, or {@code null} when no includes exist
     */
    public String includeRegex() {
        if (include.isEmpty()) {
            return null;
        }
        StringBuilder out = new StringBuilder();
        for (String pat : include) {
            if (out.length() > 0) {
                out.append('|');
            }
            out.append('L').append(translatePattern(pat));
        }
        return out.toString();
    }

    /**
     * Builds keep-filter regexes from the exclude patterns, each guarded by
     * {@code (;|$)} so a prefix like {@code App} cannot exclude
     * {@code Application}.
     *
     * @return the keep-filter list
     */
    public List<String> excludeRegexes() {
        List<String> out = new ArrayList<>();
        for (String pat : exclude) {
            out.add("L" + translatePattern(pat) + "(;|$)");
        }
        return out;
    }
}