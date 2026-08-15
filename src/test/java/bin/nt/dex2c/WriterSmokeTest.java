package bin.nt.dex2c;
import java.util.*;import com.android.tools.smali.dexlib2.iface.*;import bin.nt.dex2c.basic_blocks.*;import bin.nt.dex2c.compiler.*;import bin.nt.dex2c.graph.*;import bin.nt.dex2c.instruction.*;import bin.nt.dex2c.writer.*;
public final class WriterSmokeTest {
 static final class M implements Method { public MethodImplementation getImplementation(){return null;} public int getAccessFlags(){return 8;} public String getDefiningClass(){return "LTest;";} public String getName(){return "add";} public List<String> getParameterTypes(){return Arrays.asList("I","I");} public String getReturnType(){return "I";} public String getDescriptor(){return "(II)I";} }
 public static void main(String[] args)throws Exception{
  Graph g=new Graph();IrBasicBlock b=new IrBasicBlock(0,null);g.addNode(b);g.entry=b;g.computeRpo();
  Variable v=new Variable(0,0);v.setType("I");DexInstruction c=new DexInstruction("const/4",new int[]{0},42L,null,-1,Collections.<Integer,Integer>emptyMap());c.setValue(v);b.addIns(c);
  DexInstruction r=new DexInstruction("return",new int[]{0},null,null,-1,Collections.<Integer,Integer>emptyMap());r.addOperand(v);b.addIns(r);IrMethod ir=new IrMethod(new M(),g);ir.collect();String cpp=new CppWriter().write(ir,false);java.nio.file.Files.writeString(java.nio.file.Paths.get("build/writer-smoke.cpp"),cpp);if(!cpp.contains("JNIEXPORT jint"))throw new AssertionError();System.out.println("writer smoke: PASS");
 }
}
