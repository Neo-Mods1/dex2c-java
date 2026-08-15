package bin.nt.dex2c.instruction;
import java.util.*;
/** Base IR instruction. */
public abstract class Instruction {
    protected Value value; protected final List<Value> operands=new ArrayList<>();
    protected int offset,nextOffset=-1; protected Object parent; protected Object dexInstruction;
    public Value getValue(){return value;} public void setValue(Value v){value=v;if(v!=null)v.setDefinition(this);}
    public List<Value> getOperands(){return operands;} public void addOperand(Value v){if(v!=null){operands.add(v);v.addUser(this);}}
    public void replaceUse(Value old,Value n){for(int i=0;i<operands.size();i++)if(operands.get(i)==old){old.removeUser(this);operands.set(i,n);n.addUser(this);}}
    public int getOffset(){return offset;} public void setOffset(int o){offset=o;} public int getNextOffset(){return nextOffset;} public void setNextOffset(int o){nextOffset=o;}
    public void setParent(Object p){parent=p;} public Object getParent(){return parent;}
    public void setDexInstruction(Object d){dexInstruction=d;} public Object getDexInstruction(){return dexInstruction;}
    public boolean resolveType(){return false;} public abstract String emit();
    @Override public String toString(){return emit();}
}
