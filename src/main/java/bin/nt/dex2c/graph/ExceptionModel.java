package bin.nt.dex2c.graph;
import java.util.*;import bin.nt.dex2c.basic_blocks.*;
/** Compact exception-edge model used by the native writer. */
public final class ExceptionModel{
 public final Map<IrBasicBlock,LandingPad> landingPads=new IdentityHashMap<>();
 public LandingPad get(IrBasicBlock b){return landingPads.get(b);} public void put(IrBasicBlock b,LandingPad p){landingPads.put(b,p);}
}
