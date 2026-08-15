package bin.nt.dex2c.basic_blocks;

import java.util.LinkedHashMap;

/**
 * Synthetic block collecting the exception handlers of a protected region.
 *
 * <p>One landing pad is created per try block and is dispatched from the
 * generated C++ via {@code ExceptionOccurred}/{@code IsInstanceOf} chains
 * before control flows to the matching handler block.</p>
 */
public final class LandingPad extends IrBasicBlock {

    /** First block of the protected region. */
    public final IrBasicBlock source;

    /** Exception type → handler block, in declaration order. */
    public final LinkedHashMap<String, IrBasicBlock> handles = new LinkedHashMap<>();

    /**
     * @param source the first block of the protected region
     */
    public LandingPad(IrBasicBlock source) {
        super(-1, null);
        this.source = source;
    }

    /**
     * Registers a catch handle for an exception type.
     *
     * @param type the exception descriptor, e.g. {@code Ljava/io/IOException;}
     * @param node the handler block
     */
    public void addCatchHandle(String type, IrBasicBlock node) {
        if (handles.containsKey(type) && !"Ljava/lang/Throwable;".equals(type)) {
            throw new IllegalStateException("duplicate catch " + type);
        }
        handles.putIfAbsent(type, node);
    }

    @Override
    public String label() {
        return "EX_LandingPad_" + source.num;
    }
}
