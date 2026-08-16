package bin.nt.dex2c.compiler;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import com.android.tools.smali.dexlib2.iface.Method;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.graph.Graph;
import bin.nt.dex2c.instruction.Instruction;
import bin.nt.dex2c.instruction.Phi;
import bin.nt.dex2c.instruction.Value;

/**
 * The lowered representation of one method.
 *
 * <p>Binds the source {@link Method} to its {@link Graph} and provides the
 * block order, the collected SSA values and the register allocator used by
 * the native writer.</p>
 */
public final class IrMethod {

    /** The source method. */
    public final Method method;

    /** The method's control-flow graph. */
    public final Graph graph;

    /** Blocks in emission (RPO) order. */
    public final List<IrBasicBlock> irblocks;

    /** Every SSA value that needs a register slot. */
    public final List<Value> values = new ArrayList<>();

    /** Register allocator assigned to this method. */
    public RegisterAllocator ra;

    /** Return type of the method, e.g. {@code I} or {@code V}. */
    public String returnType;

    /**
     * @param m the source method
     * @param g its control-flow graph
     */
    public IrMethod(Method m, Graph g) {
        method = m;
        graph = g;
        irblocks = g.computeBlockOrder();
        returnType = m.getReturnType();
    }

    /**
     * Collects the SSA values (phis, instruction results and operands) and
     * allocates their registers. Must be called before the writer runs.
     */
    public void collect() {
        values.clear();
        java.util.Set<Value> seen = java.util.Collections.newSetFromMap(new java.util.IdentityHashMap<>());
        for (IrBasicBlock b : irblocks) {
            for (Value v : b.varToDeclare) {
                addValue(seen, v);
            }
            for (Phi p : b.phis) {
                addValue(seen, p);
                addValue(seen, p.getOperands().values());
            }
            for (Instruction i : b.instrList) {
                if (i.getValue() != null) {
                    addValue(seen, i.getValue());
                }
                for (Value o : i.getOperands()) {
                    addValue(seen, o);
                }
            }
        }
        ra = new RegisterAllocator(values);
    }

    private void addValue(Set<Value> seen, Value v) {
        if (seen.add(v)) {
            values.add(v);
        }
    }

    private void addValue(Set<Value> seen, java.util.Collection<Value> vs) {
        for (Value v : vs) {
            addValue(seen, v);
        }
    }
}
