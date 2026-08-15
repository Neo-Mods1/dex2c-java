package bin.nt.dex2c;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.regex.Pattern;

import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;
import com.android.tools.smali.dexlib2.iface.ClassDef;
import com.android.tools.smali.dexlib2.iface.Method;

import bin.nt.dex2c.basic_blocks.BlockLifter;
import bin.nt.dex2c.compiler.IrMethod;
import bin.nt.dex2c.compiler.SsaBuilder;
import bin.nt.dex2c.graph.Graph;
import bin.nt.dex2c.graph.GraphBuilder;
import bin.nt.dex2c.writer.CppWriter;

/**
 * Drives a single compilation pass over one DEX file.
 *
 * <p>For every method with an implementation the pipeline runs
 * {@link GraphBuilder} → {@link BlockLifter} → {@link SsaBuilder} →
 * {@link CppWriter}; the concatenated C++ sources and a compile report are
 * written into the output directory. Methods that fail are recorded in the
 * report and never abort the pass.</p>
 */
final class Compiler {

    /** C++ prelude emitted at the top of every generated source file. */
    private static final String HEADER =
            "#include <jni.h>\n"
            + "#include <cstdint>\n"
            + "#include <cmath>\n"
            + "#include <limits>\n"
            + "#include <string>\n"
            + "\n"
            + "static jint nt_div_i(JNIEnv* e,jint a,jint b){if(!b){e->ThrowNew(e->FindClass(\"java/lang/ArithmeticException\"),\"/ by zero\");return 0;}if(a==INT32_MIN&&b==-1)return INT32_MIN;return a/b;}\n"
            + "static jint nt_rem_i(JNIEnv* e,jint a,jint b){if(!b){e->ThrowNew(e->FindClass(\"java/lang/ArithmeticException\"),\"/ by zero\");return 0;}if(a==INT32_MIN&&b==-1)return 0;return a%b;}\n"
            + "static jlong nt_div_l(JNIEnv* e,jlong a,jlong b){if(!b){e->ThrowNew(e->FindClass(\"java/lang/ArithmeticException\"),\"/ by zero\");return 0;}if(a==INT64_MIN&&b==-1)return INT64_MIN;return a/b;}\n"
            + "static jlong nt_rem_l(JNIEnv* e,jlong a,jlong b){if(!b){e->ThrowNew(e->FindClass(\"java/lang/ArithmeticException\"),\"/ by zero\");return 0;}if(a==INT64_MIN&&b==-1)return 0;return a%b;}\n"
            + "static jfloat nt_f32(uint32_t x){union{uint32_t i;jfloat f;}u{ x };return u.f;} static jdouble nt_f64(uint64_t x){union{uint64_t i;jdouble d;}u{ x };return u.d;}\n"
            + "\n";

    private final Main.Cli cli;
    private final Pattern filter;
    private final Pattern classFilter;
    private final Pattern methodFilter;

    Compiler(Main.Cli c) {
        cli = c;
        filter = p(c.filter);
        classFilter = p(c.classFilter);
        methodFilter = p(c.methodFilter);
    }

    private static Pattern p(String s) {
        return s == null ? null : Pattern.compile(s);
    }

    /**
     * Compiles every selected method of {@code dex} into {@code dex2c.cpp}
     * next to a {@code compile-report.txt} summary.
     *
     * @param dex the DEX file
     * @param out the output directory
     * @return the pass statistics
     * @throws IOException on I/O failure
     */
    Main.Result compile(DexBackedDexFile dex, Path out) throws IOException {
        Files.createDirectories(out);
        Main.Result r = new Main.Result();
        StringBuilder cpp = new StringBuilder(HEADER);
        for (ClassDef c : dex.getClasses()) {
            for (Method m : c.getMethods()) {
                r.methods++;
                if (!selected(c, m)) {
                    continue;
                }
                try {
                    Graph g = GraphBuilder.build(m);
                    BlockLifter.lift(m, g);
                    IrMethod ir = new SsaBuilder(g, m).build();
                    cpp.append(new CppWriter().write(ir, cli.dynamicRegister));
                    r.compiled++;
                } catch (Throwable t) {
                    r.unsupported++;
                    cpp.append("\n/* FAILED ")
                       .append(safe(c.getType() + "->" + m.getName() + descriptor(m) + ": " + t))
                       .append(" */\n");
                }
            }
        }
        Files.writeString(out.resolve("dex2c.cpp"), cpp, StandardCharsets.UTF_8);
        Files.writeString(out.resolve("compile-report.txt"),
                "methods=" + r.methods + "\ncompiled=" + r.compiled + "\nfailed=" + r.unsupported + "\n",
                StandardCharsets.UTF_8);
        return r;
    }

    /**
     * Decides whether a method should be compiled, honoring the CLI filters.
     *
     * @param c the defining class
     * @param m the method
     * @return {@code true} if the method must be compiled
     */
    private boolean selected(ClassDef c, Method m) {
        if (m.getImplementation() == null) {
            return false;
        }
        String x = c.getType() + "->" + m.getName() + descriptor(m);
        return (filter == null || filter.matcher(x).find())
                && (classFilter == null || classFilter.matcher(c.getType()).find())
                && (methodFilter == null || methodFilter.matcher(m.getName()).find());
    }

    /**
     * Builds the JVM descriptor of a method, e.g. {@code (II)I}.
     *
     * @param m the method
     * @return the descriptor
     */
    private static String descriptor(Method m) {
        StringBuilder x = new StringBuilder("(");
        for (CharSequence p : m.getParameterTypes()) {
            x.append(p);
        }
        return x.append(")").append(m.getReturnType()).toString();
    }

    /**
     * Sanitizes arbitrary text for use inside a C++ comment.
     *
     * @param x the raw text
     * @return the sanitized text
     */
    private static String safe(String x) {
        return x.replace("*/", "* /").replace("\n", " ");
    }
}
