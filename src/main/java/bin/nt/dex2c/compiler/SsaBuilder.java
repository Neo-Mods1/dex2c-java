package bin.nt.dex2c.compiler;
import java.util.*;import com.android.tools.smali.dexlib2.*;import com.android.tools.smali.dexlib2.iface.Method;import com.android.tools.smali.dexlib2.iface.reference.*;import bin.nt.dex2c.basic_blocks.*;import bin.nt.dex2c.graph.*;import bin.nt.dex2c.instruction.*;
public final class SsaBuilder{
 private final Graph g;private final Method method;private final Map<Integer,Integer> versions=new HashMap<>();private final Map<IrBasicBlock,Boolean> processed=new IdentityHashMap<>();private IrBasicBlock current;
 public SsaBuilder(Graph g,Method m){this.g=g;this.method=m;}
 public IrMethod build(){
  defineParams();g.entry.sealed=true;ArrayDeque<IrBasicBlock> q=new ArrayDeque<>();q.add(g.entry);
  while(!q.isEmpty()){IrBasicBlock b=q.removeFirst();if(b.filled&&processed.put(b,true)!=null)continue;current=b;for(bin.nt.dex2c.instruction.Instruction ii:b.instrList)process((DexInstruction)ii);b.filled=true;trySeal(b);q.addAll(g.allSucs(b));}
  removeTrivial();inferTypes();fixConstTypes();verify();IrMethod ir=new IrMethod(method,g);for(IrBasicBlock b:g.rpo)for(Value v:b.varToDeclare){};for(IrBasicBlock b:g.nodes){for(bin.nt.dex2c.instruction.Instruction i:b.instrList)if(i.getValue()!=null)b.varToDeclare.add(i.getValue());for(Phi p:b.phis)b.varToDeclare.add(p);}ir.collect();return ir;
 }
 private void defineParams(){
  int reg;try{reg=method.getImplementation().getRegisterCount()-parameterSlots(method);}catch(Exception e){reg=0;}if((method.getAccessFlags()&0x8)==0){Variable v=newVar(reg,false);v.setType(method.getDefiningClass());g.entry.updateCurrentDefinition(reg,v);g.entry.varToDeclare.add(v);reg++;}
  for(CharSequence p:method.getParameterTypes()){String t=p.toString();Variable v=newVar(reg,false);v.setType(t);g.entry.updateCurrentDefinition(reg,v);g.entry.varToDeclare.add(v);reg+=slots(t);}
 }
  private static int parameterSlots(Method m){int n=0;if((m.getAccessFlags()&0x8)==0)n++;for(CharSequence p:m.getParameterTypes())n+=slots(p.toString());return n;}
 private static int slots(String t){return "J".equals(t)||"D".equals(t)?2:1;}
 private Variable newVar(int r,boolean phi){int v=versions.getOrDefault(r,0);versions.put(r,v+1);return phi?new Phi(r,v):new Variable(r,v);}
 private Variable write(int r){Variable v=newVar(r,false);current.updateCurrentDefinition(r,v);return v;}
 private Value read(int r){Variable v=current.readCurrentDefinition(r);if(v!=null)return v;return readRecursive(r,current);}
 private Value readRecursive(int r,IrBasicBlock b){List<IrBasicBlock> ps=g.allPreds(b);Phi phi=(Phi)newVar(r,true);if(!b.sealed){b.addIncompletePhi(phi);phi.setBlock(b);b.updateCurrentDefinition(r,phi);return phi;}if(ps.size()==1){Value x=readFrom(r,ps.get(0));b.updateCurrentDefinition(r,(Variable)x);return x;}b.updateCurrentDefinition(r,phi);b.addPhi(phi);for(IrBasicBlock p:ps)phi.addOperand(p,readFrom(r,p));return phi;}
 private Value readFrom(int r,IrBasicBlock b){Variable v=b.readCurrentDefinition(r);if(v!=null)return v;IrBasicBlock old=current;current=b;Value x=read(r);current=old;return x;}
 private void trySeal(IrBasicBlock b){for(IrBasicBlock s:g.allSucs(b)){List<IrBasicBlock> ps=g.allPreds(s);boolean all=true;for(IrBasicBlock p:ps)if(!p.filled)all=false;if(all)seal(s);}}
 private void seal(IrBasicBlock b){if(b.sealed)return;b.sealed=true;for(Phi p:new ArrayList<>(b.incompletePhis)){for(IrBasicBlock pred:g.allPreds(b))p.addOperand(pred,readFrom(p.getRegister(),pred));b.addPhi(p);}b.clearIncompletePhis();}
 private void process(DexInstruction d){String o=d.opcode();int[] r=d.registers();boolean writes=setsRegister(d);int dest=writes&&r.length>0?r[0]:Integer.MIN_VALUE;
  if(isMoveResult(o)){Value src=read(-1);Variable out=write(dest);out.refineType(src.getType());d.setValue(out);d.addOperand(src);return;}
  if(isInvoke(o)){for(int x:r)d.addOperand(read(x));String rt=invokeReturn(d);if(rt!=null&&!"V".equals(rt)){Variable res=write(-1);res.refineType(rt);d.setValue(res);}return;}
  if(writes){Variable out=write(dest);d.setValue(out);out.refineType(typeFor(d));for(int i=1;i<r.length;i++)d.addOperand(read(r[i]));}
  else for(int x:r)d.addOperand(read(x));
  if(isConst(d)&&d.getValue()!=null&&d.getValue().getType()==null){/* inferred later */}
 }
 private static boolean setsRegister(DexInstruction d){try{return d.getDexInstruction() instanceof com.android.tools.smali.dexlib2.iface.instruction.Instruction && ((com.android.tools.smali.dexlib2.iface.instruction.Instruction)d.getDexInstruction()).getOpcode().setsRegister();}catch(Exception e){return writesByName(d.opcode());}}
 private static boolean writesByName(String o){return o.startsWith("move")||o.startsWith("const")||o.startsWith("aget")||o.startsWith("iget")||o.startsWith("sget")||o.startsWith("new-")||o.startsWith("add-")||o.startsWith("sub-")||o.startsWith("mul-")||o.startsWith("div-")||o.startsWith("rem-")||o.startsWith("and-")||o.startsWith("or-")||o.startsWith("xor-")||o.startsWith("shl-")||o.startsWith("shr-")||o.startsWith("ushr-")||o.startsWith("neg-")||o.startsWith("not-")||o.startsWith("int-to-")||o.startsWith("long-to-")||o.startsWith("float-to-")||o.startsWith("double-to-")||o.startsWith("cmp");}
 private static boolean isMoveResult(String o){return o.startsWith("move-result");} private static boolean isInvoke(String o){return o.startsWith("invoke-");}
 private static boolean isConst(DexInstruction d){return d.opcode().startsWith("const");}
 private String invokeReturn(DexInstruction d){if(d.reference() instanceof MethodReference)return ((MethodReference)d.reference()).getReturnType();return "V";}
 private String typeFor(DexInstruction d){String o=d.opcode();if(o.equals("const-string")||o.equals("const-string/jumbo"))return "Ljava/lang/String;";if(o.equals("const-class"))return "Ljava/lang/Class;";if(o.equals("new-instance")&&d.reference() instanceof TypeReference)return ((TypeReference)d.reference()).getType();if(o.equals("new-array")&&d.reference() instanceof TypeReference)return ((TypeReference)d.reference()).getType();if(d.reference() instanceof FieldReference && (o.startsWith("iget")||o.startsWith("sget")))return ((FieldReference)d.reference()).getType();if(o.startsWith("const-wide"))return "J";if(o.startsWith("const"))return "I";if(o.startsWith("cmp"))return "I";if(o.startsWith("neg-int")||o.startsWith("not-int")||o.startsWith("add-int")||o.startsWith("sub-int")||o.startsWith("mul-int")||o.startsWith("div-int")||o.startsWith("rem-int")||o.startsWith("and-int")||o.startsWith("or-int")||o.startsWith("xor-int")||o.startsWith("shl-int")||o.startsWith("shr-int")||o.startsWith("ushr-int")||o.startsWith("if-"))return "I";if(o.contains("long"))return "J";if(o.contains("double"))return "D";if(o.contains("float"))return "F";if(o.contains("object"))return "Ljava/lang/Object;";if(o.equals("move-exception"))return current.catchType==null?"Ljava/lang/Throwable;":current.catchType;return null;}
 private void removeTrivial(){boolean changed;do{changed=false;for(IrBasicBlock b:g.rpo)for(Phi p:new ArrayList<>(b.phis))changed|=p.removeTrivialPhi();}while(changed);}
 private void inferTypes(){for(int pass=0;pass<500;pass++){boolean changed=false;for(IrBasicBlock b:g.rpo){for(Phi p:b.phis)changed|=p.resolveType();for(bin.nt.dex2c.instruction.Instruction i:b.instrList)changed|=inferInstruction((DexInstruction)i);}if(!changed)return;}throw new IllegalStateException("type inference did not converge");}
 private boolean inferInstruction(DexInstruction d){Value v=d.getValue();if(v==null)return false;String t=typeFor(d);if(t==null&&d.getOperands().size()>0){t=d.getOperands().get(0).getType();if(("aget".equals(d.opcode())||"aget-wide".equals(d.opcode()))&&t!=null&&t.startsWith("[")&&t.length()>1)t=t.substring(1);}return v.refineType(t);}
 private void fixConstTypes(){for(IrBasicBlock b:g.rpo)for(bin.nt.dex2c.instruction.Instruction i:b.instrList)if(i.getValue()!=null&&i.getValue().getType()==null)i.getValue().refineType("I");}
 private void verify(){for(IrBasicBlock b:g.rpo)for(bin.nt.dex2c.instruction.Instruction i:b.instrList)if(i.getValue()!=null&&i.getValue().getType()==null)throw new IllegalStateException("unknown type at "+i);for(IrBasicBlock b:g.rpo)for(Phi p:b.phis)if(p.getType()==null)throw new IllegalStateException("unknown phi type "+p);}
}
