package bin.nt.dex2c.instruction;
import java.util.*;
import com.android.tools.smali.dexlib2.iface.reference.Reference;
/** DEX instruction adapter; keeps raw DEX semantics available to the lowering phase. */
public final class DexInstruction extends Instruction {
    private final String opcode; private final int[] regs; private final Long literal; private final Reference reference;
    private final int branchTarget; private final LinkedHashMap<Integer,Integer> switchTargets;
    public DexInstruction(String opcode,int[] regs,Long literal,Reference ref,int branchTarget,Map<Integer,Integer> switches){
        this.opcode=opcode;this.regs=regs;this.literal=literal;this.reference=ref;this.branchTarget=branchTarget;this.switchTargets=new LinkedHashMap<>(switches);
    }
    public String opcode(){return opcode;} public int[] registers(){return regs;} public Long literal(){return literal;} public Reference reference(){return reference;}
    public int branchTarget(){return branchTarget;} public Map<Integer,Integer> switchTargets(){return switchTargets;}
    @Override public String emit(){return opcode+Arrays.toString(regs)+(literal==null?"":" #"+literal);}
}
