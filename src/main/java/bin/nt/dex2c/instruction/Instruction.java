package bin.nt.dex2c.instruction;

import java.util.ArrayList;
import java.util.List;

/**
 * Base IR instruction.
 *
 * <p>Carries the instruction's result value, its operand values, its DEX
 * code-unit offset and the underlying DEX instruction object.</p>
 */
public abstract class Instruction {

    /** Result value of the instruction, or {@code null}. */
    protected Value value;

    /** Operand values of the instruction. */
    protected final List<Value> operands = new ArrayList<>();

    /** Code-unit offset of the instruction. */
    protected int offset;

    /** Code-unit offset of the following instruction. */
    protected int nextOffset = -1;

    /** Owning basic block. */
    protected Object parent;

    /** The underlying DEX instruction object. */
    protected Object dexInstruction;

    /** The result value, or {@code null}. */
    public Value getValue() {
        return value;
    }

    /** Sets the result value and records this instruction as its definition. */
    public void setValue(Value v) {
        value = v;
        if (v != null) {
            v.setDefinition(this);
        }
    }

    /** The operand values. */
    public List<Value> getOperands() {
        return operands;
    }

    /** Records an operand and registers this instruction as its user. */
    public void addOperand(Value v) {
        if (v != null) {
            operands.add(v);
            v.addUser(this);
        }
    }

    /** Redirects an operand from {@code old} to {@code n}. */
    public void replaceUse(Value old, Value n) {
        for (int i = 0; i < operands.size(); i++) {
            if (operands.get(i) == old) {
                old.removeUser(this);
                operands.set(i, n);
                n.addUser(this);
            }
        }
    }

    /** Code-unit offset of the instruction. */
    public int getOffset() {
        return offset;
    }

    /** Code-unit offset of the instruction. */
    public void setOffset(int o) {
        offset = o;
    }

    /** Code-unit offset of the following instruction. */
    public int getNextOffset() {
        return nextOffset;
    }

    /** Code-unit offset of the following instruction. */
    public void setNextOffset(int o) {
        nextOffset = o;
    }

    /** The owning basic block, or {@code null}. */
    public void setParent(Object p) {
        parent = p;
    }

    /** The owning basic block, or {@code null}. */
    public Object getParent() {
        return parent;
    }

    /** The underlying DEX instruction object. */
    public void setDexInstruction(Object d) {
        dexInstruction = d;
    }

    /** The underlying DEX instruction object. */
    public Object getDexInstruction() {
        return dexInstruction;
    }

    /** Refines this instruction's result type; base returns {@code false}. */
    public boolean resolveType() {
        return false;
    }

    /** Emits the instruction's textual representation. */
    public abstract String emit();

    @Override
    public String toString() {
        return emit();
    }
}
