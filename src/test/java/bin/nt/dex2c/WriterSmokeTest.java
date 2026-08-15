package bin.nt.dex2c;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;

import com.android.tools.smali.dexlib2.HiddenApiRestriction;
import com.android.tools.smali.dexlib2.iface.Annotation;
import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.MethodImplementation;
import com.android.tools.smali.dexlib2.iface.MethodParameter;
import com.android.tools.smali.dexlib2.iface.reference.MethodReference;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.compiler.IrMethod;
import bin.nt.dex2c.graph.Graph;
import bin.nt.dex2c.instruction.DexInstruction;
import bin.nt.dex2c.instruction.Variable;
import bin.nt.dex2c.writer.CppWriter;

/**
 * End-to-end smoke test of the IR pipeline and the JNI C++ writer.
 *
 * <p>Builds a tiny two-instruction method ({@code const/4} + {@code return})
 * directly on the IR, lowers it through the writer and asserts that the
 * emitted C++ contains a JNI export for {@code jint}.</p>
 */
public final class WriterSmokeTest {

    private WriterSmokeTest() {
    }

    /** Minimal {@link Method} stub exposing {@code (II)I add}. */
    static final class M implements Method {
        @Override
        public void validateReference() {
        }

        @Override
        public MethodImplementation getImplementation() {
            return null;
        }

        @Override
        public int getAccessFlags() {
            return 8;
        }

        @Override
        public String getDefiningClass() {
            return "LTest;";
        }

        @Override
        public String getName() {
            return "add";
        }

        @Override
        public List<String> getParameterTypes() {
            return Arrays.asList("I", "I");
        }

        @Override
        public String getReturnType() {
            return "I";
        }

        @Override
        public List<? extends MethodParameter> getParameters() {
            return Collections.emptyList();
        }

        @Override
        public Set<? extends Annotation> getAnnotations() {
            return Collections.emptySet();
        }

        @Override
        public Set<HiddenApiRestriction> getHiddenApiRestrictions() {
            return Collections.emptySet();
        }

        @Override
        public int compareTo(MethodReference o) {
            return 0;
        }
    }

    public static void main(String[] args) throws Exception {
        Graph g = new Graph();
        IrBasicBlock b = new IrBasicBlock(0, null);
        g.addNode(b);
        g.entry = b;
        g.computeRpo();

        Variable v = new Variable(0, 0);
        v.setType("I");
        DexInstruction c = new DexInstruction("const/4", new int[] {0}, 42L, null, -1, Collections.<Integer, Integer>emptyMap());
        c.setValue(v);
        b.addIns(c);

        DexInstruction r = new DexInstruction("return", new int[] {0}, null, null, -1, Collections.<Integer, Integer>emptyMap());
        r.addOperand(v);
        b.addIns(r);

        IrMethod ir = new IrMethod(new M(), g);
        ir.collect();
        String cpp = new CppWriter().write(ir, false);
        java.nio.file.Files.writeString(java.nio.file.Paths.get("build/writer-smoke.cpp"), cpp);
        if (!cpp.contains("JNIEXPORT jint")) {
            throw new AssertionError();
        }
        System.out.println("writer smoke: PASS");
    }
}
