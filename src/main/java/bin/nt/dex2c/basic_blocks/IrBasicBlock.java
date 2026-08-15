package bin.nt.dex2c.basic_blocks;
import java.util.*;
import bin.nt.dex2c.instruction.*;
public class IrBasicBlock {
    public final int start; public int num=-1; public boolean filled,sealed,inCatch; public String catchType;
    public final Object dvmBasicBlock; public final List<Instruction> instrList=new ArrayList<>(), moveParamInsns=new ArrayList<>();
    public final List<Value> varToDeclare=new ArrayList<>(); public final List<Object> classToDeclare=new ArrayList<>(),fieldToDeclare=new ArrayList<>(),methodToDeclare=new ArrayList<>();
    public final Map<Integer,Variable> currentDefinitions=new HashMap<>(); public final Set<Phi> incompletePhis=Collections.newSetFromMap(new IdentityHashMap<>()); public final Set<Phi> phis=Collections.newSetFromMap(new IdentityHashMap<>()); public final Set<IrBasicBlock> catchSuccessors=Collections.newSetFromMap(new IdentityHashMap<>());
    public IrBasicBlock(int start,Object dvm){this.start=start;this.dvmBasicBlock=dvm;}
    public String label(){return "L_"+Integer.toHexString(Math.max(start,0));}
    public void addIns(Instruction i){i.setParent(this);instrList.add(i);} public void addInsBefore(Instruction n,Instruction before){int i=instrList.indexOf(before);if(i<0)instrList.add(n);else instrList.add(i,n);n.setParent(this);}
    public void removeIns(Instruction i){instrList.remove(i);} public List<Instruction> getInstrList(){return instrList;}
    public void updateCurrentDefinition(int r,Variable v){currentDefinitions.put(r,v);} public Variable readCurrentDefinition(int r){return currentDefinitions.get(r);}
    public void addIncompletePhi(Phi p){incompletePhis.add(p);} public void clearIncompletePhis(){incompletePhis.clear();} public void addPhi(Phi p){p.setBlock(this);phis.add(p);} public void removePhi(Phi p){phis.remove(p);}
    @Override public String toString(){return label();}
}
