package bin.nt.dex2c.basic_blocks;
import java.lang.reflect.Method;import java.util.*;
import com.android.tools.smali.dexlib2.iface.MethodImplementation;import com.android.tools.smali.dexlib2.iface.instruction.Instruction;
import com.android.tools.smali.dexlib2.iface.instruction.OffsetInstruction;
import com.android.tools.smali.dexlib2.iface.instruction.ReferenceInstruction;import com.android.tools.smali.dexlib2.iface.reference.*;
import bin.nt.dex2c.graph.*;import bin.nt.dex2c.instruction.*;
public final class BlockLifter{
 private BlockLifter(){}
 public static void lift(com.android.tools.smali.dexlib2.iface.Method method,Graph g){
  MethodImplementation impl=method.getImplementation();if(impl==null)return;List<Instruction> ins=new ArrayList<>();for(Instruction q:impl.getInstructions())ins.add(q);Map<Integer,Instruction> at=new HashMap<>();int p=0;for(Instruction i:ins){at.put(p,i);p+=i.getCodeUnits();}
  for(IrBasicBlock b:g.nodes){if(b.start<0)continue;int end=p;for(IrBasicBlock x:g.nodes)if(x.start>b.start)end=Math.min(end,x.start);int pc=b.start;while(pc<end){Instruction d=at.get(pc);if(d==null)break;DexInstruction x=adapt(d,pc);b.addIns(x);pc+=d.getCodeUnits();}b.filled=true;}
 }
 private static DexInstruction adapt(Instruction d,int pc){
  String op=d.getOpcode().name().toLowerCase(Locale.ROOT).replace('_','-');int[] regs=regs(d);Long lit=literal(d);Reference ref=d instanceof ReferenceInstruction?((ReferenceInstruction)d).getReference():null;int target=d instanceof OffsetInstruction?pc+((OffsetInstruction)d).getCodeOffset():-1;Map<Integer,Integer> sw=new LinkedHashMap<>();
  try{java.lang.reflect.Method m=d.getClass().getMethod("getSwitchElements");Object x=m.invoke(d);if(x instanceof Iterable<?>)for(Object e:(Iterable<?>)x){int k=((Number)e.getClass().getMethod("getKey").invoke(e)).intValue();int t=((Number)e.getClass().getMethod("getOffset").invoke(e)).intValue()+pc;sw.put(k,t);}}catch(Exception ignored){}
  DexInstruction ir=new DexInstruction(op,regs,lit,ref,target,sw);ir.setOffset(pc);ir.setNextOffset(pc+d.getCodeUnits());ir.setDexInstruction(d);return ir;
 }
 static int[] regs(Instruction d){
  try{java.lang.reflect.Method c=d.getClass().getMethod("getRegisterCount");int n=((Number)c.invoke(d)).intValue();java.lang.reflect.Method s=d.getClass().getMethod("getStartRegister");int start=((Number)s.invoke(d)).intValue();int[] r=new int[n];for(int i=0;i<n;i++)r[i]=start+i;return r;}catch(Exception ignored){}
  int[] tmp=new int[7];int n=0;for(char x='A';x<='G';x++){try{java.lang.reflect.Method m=d.getClass().getMethod("getRegister"+x);tmp[n++]=((Number)m.invoke(d)).intValue();}catch(Exception ignored){}}return Arrays.copyOf(tmp,n);
 }
 static Long literal(Instruction d){try{java.lang.reflect.Method m=d.getClass().getMethod("getWideLiteral");return ((Number)m.invoke(d)).longValue();}catch(Exception ignored){}try{java.lang.reflect.Method m=d.getClass().getMethod("getNarrowLiteral");return ((Number)m.invoke(d)).longValue();}catch(Exception ignored){}return null;}
}
