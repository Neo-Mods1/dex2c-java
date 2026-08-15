package bin.nt.dex2c.basic_blocks;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import bin.nt.dex2c.instruction.Instruction;
import bin.nt.dex2c.instruction.Phi;
import bin.nt.dex2c.instruction.Value;
import bin.nt.dex2c.instruction.Variable;

/**
 * A single basic block of the IR.
 *
 * <p>Carries the instruction list, the SSA state produced by the builder
 * (current definitions, phis) and the declaration lists consumed by the
 * native writer. Offsets refer to DEX code-unit positions; synthetic blocks
 * (landing pads) use a negative start.</p>
 */
public class IrBasicBlock {

    /** DEX code-unit offset of the block's first instruction. */
    public final int start;

    /** RPO number assigned by {@link bin.nt.dex2c.graph.Graph#computeRpo()}. */
    public int num = -1;

    /** Whether the instruction list has been materialized. */
    public boolean filled;

    /** Whether all predecessors are known (SSA construction). */
    public boolean sealed;

    /** Whether the block lies inside a protected region. */
    public boolean inCatch;

    /** Exception type caught by the handler starting this block. */
    public String catchType;

    /** Underlying DEX basic block, when available. */
    public final Object dvmBasicBlock;

    /** Instructions in program order. */
    public final List<Instruction> instrList = new ArrayList<>();

    /** Unused move-parameter list, kept for parity with the IR model. */
    public final List<Instruction> moveParamInsns = new ArrayList<>();

    /** Values that must be declared before the block's body. */
    public final List<Value> varToDeclare = new ArrayList<>();

    /** Class, field and method declarations (reserved for future use). */
    public final List<Object> classToDeclare = new ArrayList<>();
    public final List<Object> fieldToDeclare = new ArrayList<>();
    public final List<Object> methodToDeclare = new ArrayList<>();

    /** SSA: current definition of each register in this block. */
    public final Map<Integer, Variable> currentDefinitions = new HashMap<>();

    /** SSA: phis waiting for their back-edge operands. */
    public final Set<Phi> incompletePhis = Collections.newSetFromMap(new IdentityHashMap<>());

    /** SSA: phis finalized in this block. */
    public final Set<Phi> phis = Collections.newSetFromMap(new IdentityHashMap<>());

    /** Blocks reachable via catch edges. */
    public final Set<IrBasicBlock> catchSuccessors = Collections.newSetFromMap(new IdentityHashMap<>());

    /**
     * @param start the DEX code-unit offset (negative for synthetic blocks)
     * @param dvm   the underlying DEX basic block, or {@code null}
     */
    public IrBasicBlock(int start, Object dvm) {
        this.start = start;
        this.dvmBasicBlock = dvm;
    }

    /** C++ label of this block. */
    public String label() {
        return "L_" + Integer.toHexString(Math.max(start, 0));
    }

    /** Appends an instruction to the block. */
    public void addIns(Instruction i) {
        i.setParent(this);
        instrList.add(i);
    }

    /** Inserts an instruction before another one. */
    public void addInsBefore(Instruction n, Instruction before) {
        int i = instrList.indexOf(before);
        if (i < 0) {
            instrList.add(n);
        } else {
            instrList.add(i, n);
        }
        n.setParent(this);
    }

    /** Removes an instruction from the block. */
    public void removeIns(Instruction i) {
        instrList.remove(i);
    }

    /** The block's instruction list. */
    public List<Instruction> getInstrList() {
        return instrList;
    }

    /** Records the current SSA definition of a register. */
    public void updateCurrentDefinition(int r, Variable v) {
        currentDefinitions.put(r, v);
    }

    /** Reads the current SSA definition of a register. */
    public Variable readCurrentDefinition(int r) {
        return currentDefinitions.get(r);
    }

    /** Tracks a phi whose operands are not all known yet. */
    public void addIncompletePhi(Phi p) {
        incompletePhis.add(p);
    }

    /** Drops all incomplete phis (block was sealed). */
    public void clearIncompletePhis() {
        incompletePhis.clear();
    }

    /** Finalizes a phi in this block. */
    public void addPhi(Phi p) {
        p.setBlock(this);
        phis.add(p);
    }

    /** Removes a phi from this block. */
    public void removePhi(Phi p) {
        phis.remove(p);
    }

    @Override
    public String toString() {
        return label();
    }
}
