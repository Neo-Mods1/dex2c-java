package bin.nt.dex2c.util;

import java.util.ArrayList;
import java.util.List;

/**
 * Type mapping and descriptor helpers shared by the compiler and writer.
 */
public final class Types {

    private Types() {
    }

    /** Whether a type is a reference type ({@code L...} or {@code [...]}). */
    public static boolean ref(String t) {
        return t != null && (t.startsWith("L") || t.startsWith("["));
    }

    /** Whether a type occupies two registers. */
    public static boolean wide(String t) {
        return "J".equals(t) || "D".equals(t);
    }

    /** Maps a JVM type to its C++/JNI type name. */
    public static String c(String t) {
        if (t == null) {
            return "jlong";
        }
        if ("V".equals(t)) {
            return "void";
        }
        if ("Z".equals(t)) {
            return "jboolean";
        }
        if ("B".equals(t)) {
            return "jbyte";
        }
        if ("S".equals(t)) {
            return "jshort";
        }
        if ("C".equals(t)) {
            return "jchar";
        }
        if ("I".equals(t)) {
            return "jint";
        }
        if ("J".equals(t)) {
            return "jlong";
        }
        if ("F".equals(t)) {
            return "jfloat";
        }
        if ("D".equals(t)) {
            return "jdouble";
        }
        if (t.startsWith("[") && t.length() > 1) {
            char e = t.charAt(1);
            if (e == 'Z') {
                return "jbooleanArray";
            }
            if (e == 'B') {
                return "jbyteArray";
            }
            if (e == 'C') {
                return "jcharArray";
            }
            if (e == 'S') {
                return "jshortArray";
            }
            if (e == 'I') {
                return "jintArray";
            }
            if (e == 'J') {
                return "jlongArray";
            }
            if (e == 'F') {
                return "jfloatArray";
            }
            if (e == 'D') {
                return "jdoubleArray";
            }
            return "jobjectArray";
        }
        return t.startsWith("[") ? "jarray" : "jobject";
    }

    /** Maps a JVM type to its JNI accessor suffix, e.g. {@code Int}. */
    public static String jniSuffix(String t) {
        if (t == null) {
            return "Object";
        }
        if ("V".equals(t)) {
            return "Void";
        }
        if ("Z".equals(t)) {
            return "Boolean";
        }
        if ("B".equals(t)) {
            return "Byte";
        }
        if ("C".equals(t)) {
            return "Char";
        }
        if ("S".equals(t)) {
            return "Short";
        }
        if ("I".equals(t)) {
            return "Int";
        }
        if ("J".equals(t)) {
            return "Long";
        }
        if ("F".equals(t)) {
            return "Float";
        }
        if ("D".equals(t)) {
            return "Double";
        }
        return "Object";
    }

    /** Converts a JVM descriptor to its class name, e.g. {@code Lfoo/Bar;} → {@code foo/Bar}. */
    public static String descToClass(String d) {
        if (d == null) {
            return "java/lang/Object";
        }
        if (d.startsWith("L") && d.endsWith(";")) {
            return d.substring(1, d.length() - 1);
        }
        return d;
    }

    /** Escapes a string for embedding in a C++ string literal. */
    public static String escape(String s) {
        return s.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n")
                .replace("\r", "\\r").replace("\t", "\\t");
    }

    /**
     * Splits the parameter types of a method descriptor.
     *
     * @param desc the descriptor, e.g. {@code (IILjava/lang/String;)I}
     * @return the parameter types
     */
    public static List<String> params(String desc) {
        List<String> r = new ArrayList<>();
        int i = 1;
        while (i < desc.length() && desc.charAt(i) != ')') {
            int s = i;
            if (desc.charAt(i) == '[') {
                while (desc.charAt(i) == '[') {
                    i++;
                }
                if (desc.charAt(i) == 'L') {
                    while (desc.charAt(i++) != ';') {
                    }
                } else {
                    i++;
                }
            } else if (desc.charAt(i) == 'L') {
                while (desc.charAt(i++) != ';') {
                }
            } else {
                i++;
            }
            r.add(desc.substring(s, i));
        }
        return r;
    }

    /** The return type of a method descriptor. */
    public static String ret(String desc) {
        return desc.substring(desc.indexOf(')') + 1);
    }
}
