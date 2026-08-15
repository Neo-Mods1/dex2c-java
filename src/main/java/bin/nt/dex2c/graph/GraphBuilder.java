package bin.nt.dex2c.graph;

import java.util.*;
import com.android.tools.smali.dexlib2.iface.MethodImplementation;
import com.android.tools.smali.dexlib2.iface.instruction.Instruction;
import com.android.tools.smali.dexlib2.iface.instruction.OffsetInstruction;
import com.android.tools.smali.dexlib2.iface.reference.*;
import bin.nt.dex2c.basic_blocks.*;


/** Builds the same normal/catch CFG model used by the Python dex2c implementation. */
public final class GraphBuilder {
    private GraphBuilder(){}
    public static Graph build(com.android.tools.smali.dexlib2.iface.Method method){
        Graph g=new Graph(); MethodImplementation impl=method.getImplementation(); if(impl==null)return g;
        List<Instruction> list=new ArrayList<>();for(Instruction q:impl.getInstructions())list.add(q);
        Map<Integer,Instruction> at=new LinkedHashMap<>(); Map<Instruction,Integer> off=new IdentityHashMap<>();
        int pc=0; for(Instruction i:list){at.put(pc,i);off.put(i,pc);pc+=i.getCodeUnits();}
        Set<Integer> leaders=new TreeSet<>(); leaders.add(0);
        for(var e:at.entrySet()){
            int p=e.getKey(); Instruction i=e.getValue(); String op=op(i);
            if(i instanceof OffsetInstruction){int t=p+((OffsetInstruction)i).getCodeOffset();if(t>=0&&t<pc)leaders.add(t);}
            for(int t:switchTargets(i,p))if(t>=0&&t<pc)leaders.add(t);
            if(isConditional(op)||isSwitch(op)||isGoto(op)||isTerminal(op)){int n=p+i.getCodeUnits();if(n<pc)leaders.add(n);}
        }
        addTryLeaders(impl,leaders,pc);
        List<Integer> ls=new ArrayList<>(leaders); Map<Integer,IrBasicBlock> bm=new HashMap<>();
        for(int s:ls){IrBasicBlock b=new IrBasicBlock(s,null);g.addNode(b);bm.put(s,b);} g.entry=bm.get(0);
        for(int idx=0;idx<ls.size();idx++){
            int s=ls.get(idx), e=idx+1<ls.size()?ls.get(idx+1):pc; Instruction last=null; int p=s;
            while(p<e){last=at.get(p);p+=last.getCodeUnits();}
            if(last==null)continue; IrBasicBlock b=bm.get(s); String op=op(last);
            if(isSwitch(op)){for(int t:switchTargets(last,off.get(last)))if(bm.containsKey(t))g.addEdge(b,bm.get(t)); if(!isTerminal(op)&&e<pc)g.addEdge(b,bm.get(e));}
            else if(isConditional(op)){int t=off.get(last)+((OffsetInstruction)last).getCodeOffset();if(bm.containsKey(t))g.addEdge(b,bm.get(t));if(e<pc)g.addEdge(b,bm.get(e));}
            else if(isGoto(op)){int t=off.get(last)+((OffsetInstruction)last).getCodeOffset();if(bm.containsKey(t))g.addEdge(b,bm.get(t));}
            else if(!isTerminal(op)&&e<pc)g.addEdge(b,bm.get(e));
        }
        addTryEdges(method,impl,g,bm,pc);
        buildLandingPads(impl,g,bm);
        g.computeRpo(); return g;
    }
    static String op(Instruction i){return i.getOpcode().name().toLowerCase(Locale.ROOT).replace('_','-');}
    static boolean isConditional(String o){return o.startsWith("if-");}
    static boolean isSwitch(String o){return o.equals("packed-switch")||o.equals("sparse-switch");}
    static boolean isGoto(String o){return o.startsWith("goto");}
    static boolean isTerminal(String o){return o.startsWith("return")||o.equals("throw")||o.equals("throw-verification-error");}
    static List<Integer> switchTargets(Instruction i,int base){
        List<Integer> r=new ArrayList<>();
        try{java.lang.reflect.Method m=i.getClass().getMethod("getSwitchElements"); Object x=m.invoke(i);if(x instanceof Iterable<?>)for(Object e:(Iterable<?>)x){java.lang.reflect.Method q=e.getClass().getMethod("getOffset");r.add(base+((Number)q.invoke(e)).intValue());}}catch(Exception ignored){}
        return r;
    }
    static void addTryLeaders(MethodImplementation impl,Set<Integer> leaders,int codeSize){
        try{for(Object tb:(Iterable<?>)impl.getClass().getMethod("getTryBlocks").invoke(impl)){
            int s=num(tb,"getStartCodeAddress"), end=s+num(tb,"getCodeUnitCount");if(s>=0&&s<codeSize)leaders.add(s);if(end>=0&&end<codeSize)leaders.add(end);
            Object hs=tb.getClass().getMethod("getExceptionHandlers").invoke(tb);for(Object h:(Iterable<?>)hs){int a=num(h,"getHandlerCodeAddress");if(a>=0&&a<codeSize)leaders.add(a);}
        }}catch(Exception ignored){}
    }
    static void addTryEdges(com.android.tools.smali.dexlib2.iface.Method method,MethodImplementation impl,Graph g,Map<Integer,IrBasicBlock> bm,int codeSize){
        try{for(Object tb:(Iterable<?>)impl.getClass().getMethod("getTryBlocks").invoke(impl)){
            int s=num(tb,"getStartCodeAddress"), end=s+num(tb,"getCodeUnitCount"); Object hs=tb.getClass().getMethod("getExceptionHandlers").invoke(tb);
            for(Object h:(Iterable<?>)hs){int target=num(h,"getHandlerCodeAddress");IrBasicBlock dst=bm.get(target);if(dst==null)continue;String type=null;try{Object t=h.getClass().getMethod("getExceptionType").invoke(h);type=t==null?"Ljava/lang/Throwable;":t.toString();}catch(Exception ignored){type="Ljava/lang/Throwable;";}dst.inCatch=true;dst.catchType=type;
                for(IrBasicBlock src:g.nodes){if(src.start>=s&&src.start<end){g.addCatchEdge(src,dst);src.catchSuccessors.add(dst);}}
            }
        }}catch(Exception ignored){}
    }
    static int num(Object o,String method)throws Exception{return ((Number)o.getClass().getMethod(method).invoke(o)).intValue();}
    static void buildLandingPads(MethodImplementation impl,Graph g,Map<Integer,IrBasicBlock> bm){
        try{for(Object tb:(Iterable<?>)impl.getClass().getMethod("getTryBlocks").invoke(impl)){int s=num(tb,"getStartCodeAddress"),end=s+num(tb,"getCodeUnitCount");LandingPad lp=null;Object hs=tb.getClass().getMethod("getExceptionHandlers").invoke(tb);for(Object h:(Iterable<?>)hs){int target=num(h,"getHandlerCodeAddress");IrBasicBlock dst=bm.get(target);if(dst==null)continue;if(lp==null){IrBasicBlock src=bm.get(s);if(src==null)continue;lp=new LandingPad(src);g.landingPads.add(lp);g.nodeToLandingPad.put(src,lp);}String type=null;try{Object t=h.getClass().getMethod("getExceptionType").invoke(h);type=t==null?"Ljava/lang/Throwable;":t.toString();}catch(Exception ignored){type="Ljava/lang/Throwable;";}lp.addCatchHandle(type,dst);}
                if(lp!=null)for(IrBasicBlock src:g.nodes)if(src.start>=s&&src.start<end){g.nodeToLandingPad.putIfAbsent(src,lp);}
        }}catch(Exception ignored){}
    }
}
