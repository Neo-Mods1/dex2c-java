package bin.nt.dex2c.graph;

import java.util.IdentityHashMap;
import java.util.Map;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.basic_blocks.LandingPad;

/**
 * Compact exception-edge model used by the native writer.
 *
 * <p>Maps every block of a protected region to the landing pad that
 * dispatches its exceptions.</p>
 */
public final class ExceptionModel {

    /** Block → landing pad of the enclosing try region. */
    public final Map<IrBasicBlock, LandingPad> landingPads = new IdentityHashMap<>();

    /** The landing pad of a block, or {@code null} when not protected. */
    public LandingPad get(IrBasicBlock b) {
        return landingPads.get(b);
    }

    /** Registers a landing pad for a block. */
    public void put(IrBasicBlock b, LandingPad p) {
        landingPads.put(b, p);
    }
}
