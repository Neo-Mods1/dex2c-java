package bin.nt.dex2c.instruction;

/**
 * An SSA variable: a register plus a version.
 *
 * <p>Versions distinguish distinct definitions of the same DEX register
 * created during SSA construction; a negative register denotes a
 * pseudo-register (such as the move-result slot).</p>
 */
public class Variable extends Value {

    private final int register;
    private final int version;

    /**
     * @param register the DEX register (negative for pseudo-registers)
     * @param version  the SSA version
     */
    public Variable(int register, int version) {
        this.register = register;
        this.version = version;
    }

    /** The DEX register this variable belongs to. */
    public int getRegister() {
        return register;
    }

    /** The SSA version of this variable. */
    public int getVersion() {
        return version;
    }

    @Override
    public String toString() {
        return "v" + (register < 0 ? "Result" : register) + "_" + version;
    }
}
