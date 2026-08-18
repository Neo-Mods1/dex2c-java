package bin.nt.dex2c.instruction;

import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Map;

import com.android.tools.smali.dexlib2.iface.reference.Reference;

/**
 * DEX instruction adapter.
 *
 * <p>Keeps the raw DEX semantics — opcode, registers, literal, reference,
 * branch target and switch payload — available to the lowering phase without
 * depending on dexlib2 instruction interfaces directly.</p>
 */
public final class DexInstruction extends Instruction {

    private final String opcode;
    private final int[] regs;
    private final Long literal;
    private final Reference reference;
    private final int branchTarget;
    private final LinkedHashMap<Integer, Integer> switchTargets;
    private final Integer fillArraySize;
    private final Integer fillArrayElementWidth;
    private final byte[] fillArrayData;

    /**
     * @param opcode       the opcode in dash-separated form, e.g. {@code const/4}
     * @param regs         the register operands
     * @param literal      the instruction literal, or {@code null}
     * @param ref          the referenced item, or {@code null}
     * @param branchTarget absolute branch target offset, or {@code -1}
     * @param switches     switch key → target offset map
     */
    public DexInstruction(String opcode, int[] regs, Long literal, Reference ref, int branchTarget,
                          Map<Integer, Integer> switches) {
        this(opcode, regs, literal, ref, branchTarget, switches, null, null, null);
    }

    /**
     * @param opcode       the opcode in dash-separated form, e.g. {@code const/4}
     * @param regs         the register operands
     * @param literal      the instruction literal, or {@code null}
     * @param ref          the referenced item, or {@code null}
     * @param branchTarget absolute branch target offset, or {@code -1}
     * @param switches     switch key → target offset map
     * @param fillSize     element count of the fill-array-data payload, or {@code null}
     * @param fillWidth    element width in bytes of the fill-array-data payload, or {@code null}
     * @param fillData     raw payload bytes, or {@code null}
     */
    public DexInstruction(String opcode, int[] regs, Long literal, Reference ref, int branchTarget,
                          Map<Integer, Integer> switches, Integer fillSize, Integer fillWidth, byte[] fillData) {
        this.opcode = opcode;
        this.regs = regs;
        this.literal = literal;
        this.reference = ref;
        this.branchTarget = branchTarget;
        this.switchTargets = new LinkedHashMap<>(switches);
        this.fillArraySize = fillSize;
        this.fillArrayElementWidth = fillWidth;
        this.fillArrayData = fillData;
    }

    /** The opcode, e.g. {@code const/4}. */
    public String opcode() {
        return opcode;
    }

    /** The register operands. */
    public int[] registers() {
        return regs;
    }

    /** The literal, or {@code null}. */
    public Long literal() {
        return literal;
    }

    /** The referenced item, or {@code null}. */
    public Reference reference() {
        return reference;
    }

    /** Absolute branch target offset, or {@code -1}. */
    public int branchTarget() {
        return branchTarget;
    }

    /** Switch key → absolute target offset map. */
    public Map<Integer, Integer> switchTargets() {
        return switchTargets;
    }

    /** Element count of the fill-array-data payload, or {@code null}. */
    public Integer fillArraySize() {
        return fillArraySize;
    }

    /** Element width in bytes of the fill-array-data payload, or {@code null}. */
    public Integer fillArrayElementWidth() {
        return fillArrayElementWidth;
    }

    /** Raw payload bytes, or {@code null}. */
    public byte[] fillArrayData() {
        return fillArrayData;
    }

    @Override
    public String emit() {
        return opcode + Arrays.toString(regs) + (literal == null ? "" : " #" + literal);
    }
}
