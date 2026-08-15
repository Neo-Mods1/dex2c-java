package bin.nt.dex2c.compiler;
import java.util.*;import com.android.tools.smali.dexlib2.iface.Method;import bin.nt.dex2c.graph.*;import bin.nt.dex2c.basic_blocks.*;import bin.nt.dex2c.instruction.*;
public final class IrMethod{
 public final Method method;public final Graph graph;public final List<IrBasicBlock> irblocks;public final List<Value> values=new ArrayList<>();public RegisterAllocator ra;public String returnType;
 public IrMethod(Method m,Graph g){method=m;graph=g;irblocks=g.computeBlockOrder();returnType=m.getReturnType();}
 public void collect(){values.clear();for(IrBasicBlock b:irblocks){values.addAll(b.phis);for(Instruction i:b.instrList)if(i.getValue()!=null)values.add(i.getValue());}ra=new RegisterAllocator(values);}
}
