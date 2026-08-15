package bin.nt.dex2c.instruction;
import java.util.*;
import bin.nt.dex2c.basic_blocks.IrBasicBlock;
public final class Phi extends Variable {
    private final LinkedHashMap<IrBasicBlock,Value> operands=new LinkedHashMap<>();
    private IrBasicBlock block;
    private final Instruction userAdapter=new Instruction(){@Override public String emit(){return Phi.this.toString();}};
    public Phi(int r,int v){super(r,v);}
    public void setBlock(IrBasicBlock b){block=b;} public IrBasicBlock getBlock(){return block;}
    public Map<IrBasicBlock,Value> getOperands(){return operands;}
    public void addOperand(IrBasicBlock pred,Value value){operands.put(pred,value);value.addUser(userAdapter);}
    public void removeOperand(IrBasicBlock pred){Value v=operands.remove(pred);if(v!=null)v.removeUser(userAdapter);}
    public void replaceUse(Value old,Value n){for(var e:new ArrayList<>(operands.entrySet()))if(e.getValue()==old){old.removeUser(userAdapter);n.addUser(userAdapter);operands.put(e.getKey(),n);}}
    public boolean resolveType(){
        String t=getType();
        for(Value v:operands.values()){if(v.getType()!=null)t=t==null?v.getType():TypeUtil.merge(t,v.getType());}
        return t!=null && !t.equals(getType()) && refineType(t);
    }
    public boolean removeTrivialPhi(){
        Value same=null;
        for(Value v:operands.values()){if(v==this)continue;if(same==null)same=v;else if(same!=v)return false;}
        if(same==null)return false; replaceAllUsesWith(same);if(block!=null)block.removePhi(this);return true;
    }
    @Override public String toString(){return super.toString()+" = phi"+operands.values();}
}
