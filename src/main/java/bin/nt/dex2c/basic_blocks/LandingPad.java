package bin.nt.dex2c.basic_blocks;
import java.util.*;
public final class LandingPad extends IrBasicBlock {
    public final IrBasicBlock source; public final LinkedHashMap<String,IrBasicBlock> handles=new LinkedHashMap<>();
    public LandingPad(IrBasicBlock source){super(-1,null);this.source=source;}
    public void addCatchHandle(String type,IrBasicBlock node){if(handles.containsKey(type)&&!"Ljava/lang/Throwable;".equals(type))throw new IllegalStateException("duplicate catch "+type);handles.putIfAbsent(type,node);}
    @Override public String label(){return "EX_LandingPad_"+source.num;}
}
