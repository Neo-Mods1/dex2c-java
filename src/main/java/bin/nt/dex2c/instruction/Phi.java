package bin.nt.dex2c.instruction;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;

/**
 * A phi node: an SSA join point selecting one operand per predecessor block.
 *
 * <p>Operands are keyed by the incoming block. Phis are added incrementally
 * during SSA construction and are patched when a block is sealed. Trivial
 * phis (all operands identical) are removed at the end of the pass.</p>
 */
public final class Phi extends Variable {

    private final LinkedHashMap<IrBasicBlock, Value> operands = new LinkedHashMap<>();
    private IrBasicBlock block;

    /** Adapter that lets the phi be a user of its operands. */
    private final Instruction userAdapter = new Instruction() {
        @Override
        public String emit() {
            return Phi.this.toString();
        }
    };

    /**
     * @param r the DEX register
     * @param v the SSA version
     */
    public Phi(int r, int v) {
        super(r, v);
    }

    /** The block holding this phi. */
    public void setBlock(IrBasicBlock b) {
        block = b;
    }

    /** The block holding this phi, or {@code null} before placement. */
    public IrBasicBlock getBlock() {
        return block;
    }

    /** Operands keyed by predecessor block. */
    public Map<IrBasicBlock, Value> getOperands() {
        return operands;
    }

    /** Records the incoming value of a predecessor. */
    public void addOperand(IrBasicBlock pred, Value value) {
        operands.put(pred, value);
        value.addUser(userAdapter);
    }

    /** Drops the incoming value of a predecessor. */
    public void removeOperand(IrBasicBlock pred) {
        Value v = operands.remove(pred);
        if (v != null) {
            v.removeUser(userAdapter);
        }
    }

    /** Redirects one operand from {@code old} to {@code n}. */
    public void replaceUse(Value old, Value n) {
        for (Map.Entry<IrBasicBlock, Value> e : new ArrayList<>(operands.entrySet())) {
            if (e.getValue() == old) {
                old.removeUser(userAdapter);
                n.addUser(userAdapter);
                operands.put(e.getKey(), n);
            }
        }
    }

    /**
     * Merges the operand types into the phi's type.
     *
     * @return {@code true} if the type changed
     */
    public boolean resolveType() {
        String t = getType();
        for (Value v : operands.values()) {
            if (v.getType() != null) {
                t = t == null ? v.getType() : TypeUtil.merge(t, v.getType());
            }
        }
        return t != null && !t.equals(getType()) && refineType(t);
    }

    /**
     * Removes the phi when all operands are the same value.
     *
     * @return {@code true} if the phi was removed
     */
    public boolean removeTrivialPhi() {
        Value same = null;
        for (Value v : operands.values()) {
            if (v == this) {
                continue;
            }
            if (same == null) {
                same = v;
            } else if (same != v) {
                return false;
            }
        }
        if (same == null) {
            return false;
        }
        replaceAllUsesWith(same);
        if (block != null) {
            block.removePhi(this);
        }
        return true;
    }

    @Override
    public String toString() {
        return super.toString() + " = phi" + operands.values();
    }
}
