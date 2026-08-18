package bin.nt.dex2c.compiler;

import java.util.IdentityHashMap;
import java.util.Map;
import java.util.Set;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.instruction.Instruction;
import bin.nt.dex2c.instruction.Phi;
import bin.nt.dex2c.instruction.Value;

/** Strict pre-codegen verifier for the Java IR. */
public final class IrVerifier {
    private IrVerifier() {}

    public static void verify(IrMethod ir) {
        Set<Value> defs = java.util.Collections.newSetFromMap(new IdentityHashMap<>());
        for (IrBasicBlock b : ir.irblocks) {
            for (Phi p : b.phis) {
                if (p.getBlock() != b) fail("phi has wrong block", b, p);
                if (p.getType() == null) fail("phi has no type", b, p);
                defs.add(p);
                if (p.getOperands().size() != ir.graph.allPreds(b).size())
                    fail("phi predecessor count mismatch", b, p);
                for (Map.Entry<IrBasicBlock, Value> e : p.getOperands().entrySet()) {
                    if (!ir.graph.allPreds(b).contains(e.getKey())) fail("phi contains non-predecessor", b, p);
                    requireValue(e.getValue(), defs, b, p);
                    if (!compatible(p.getType(), e.getValue().getType()))
                        fail("phi type mismatch: " + p.getType() + " vs " + e.getValue().getType(), b, p);
                }
            }
            for (Instruction i : b.instrList) {
                if (i.getValue() != null) {
                    if (i.getValue().getDefinition() != i) fail("definition pointer mismatch", b, i);
                    if (i.getValue().getType() == null) fail("untyped result", b, i);
                    defs.add(i.getValue());
                }
                for (Value v : i.getOperands()) requireValue(v, defs, b, i);
            }
        }
    }

    private static void requireValue(Value v, Set<Value> defs, IrBasicBlock b, Instruction i) {
        if (v == null) fail("null operand", b, i);
        if (v.getType() == null) fail("untyped operand", b, i);
        if (!v.isConstant() && v.getDefinition() == null && !defs.contains(v))
            fail("use without definition", b, i);
    }

    private static boolean compatible(String a, String b) {
        if (a == null || b == null) return false;
        if (a.equals(b)) return true;
        if (Value.TypeUtil.isInt(a) && Value.TypeUtil.isInt(b)) return true;
        if (Value.TypeUtil.isFloat(a) && Value.TypeUtil.isFloat(b)) return true;
        return Value.TypeUtil.isRef(a) && Value.TypeUtil.isRef(b);
    }

    private static void fail(String message, IrBasicBlock b, Object node) {
        throw new IllegalStateException("IR verification failed at " + b.label() + ": " + message + " [" + node + "]");
    }
}
