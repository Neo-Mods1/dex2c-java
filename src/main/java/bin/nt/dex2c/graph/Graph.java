package bin.nt.dex2c.graph;
import java.util.*;
import bin.nt.dex2c.basic_blocks.*;
public final class Graph implements Iterable<IrBasicBlock>{
    public IrBasicBlock entry,exit; public final List<IrBasicBlock> nodes=new ArrayList<>(),rpo=new ArrayList<>(); public final List<LandingPad> landingPads=new ArrayList<>();
    public final Map<IrBasicBlock,List<IrBasicBlock>> edges=new IdentityHashMap<>(),catchEdges=new IdentityHashMap<>(),reverseEdges=new IdentityHashMap<>(),reverseCatchEdges=new IdentityHashMap<>(); public final Map<Integer,IrBasicBlock> offsetToNode=new HashMap<>(); public final Map<IrBasicBlock,LandingPad> nodeToLandingPad=new IdentityHashMap<>();
    public void addNode(IrBasicBlock n){nodes.add(n);edges.putIfAbsent(n,new ArrayList<>());catchEdges.putIfAbsent(n,new ArrayList<>());reverseEdges.putIfAbsent(n,new ArrayList<>());reverseCatchEdges.putIfAbsent(n,new ArrayList<>());}
    private static void add(Map<IrBasicBlock,List<IrBasicBlock>> m,IrBasicBlock a,IrBasicBlock b){m.computeIfAbsent(a,k->new ArrayList<>());if(!m.get(a).contains(b))m.get(a).add(b);}
    public void addEdge(IrBasicBlock a,IrBasicBlock b){add(edges,a,b);add(reverseEdges,b,a);} public void addCatchEdge(IrBasicBlock a,IrBasicBlock b){add(catchEdges,a,b);add(reverseCatchEdges,b,a);}
    public List<IrBasicBlock> sucs(IrBasicBlock n){return new ArrayList<>(edges.getOrDefault(n,List.of()));} public List<IrBasicBlock> allSucs(IrBasicBlock n){List<IrBasicBlock> r=sucs(n);r.addAll(catchEdges.getOrDefault(n,List.of()));return r;}
    public List<IrBasicBlock> preds(IrBasicBlock n){return new ArrayList<>(reverseEdges.getOrDefault(n,List.of()));} public List<IrBasicBlock> allPreds(IrBasicBlock n){List<IrBasicBlock> r=preds(n);r.addAll(reverseCatchEdges.getOrDefault(n,List.of()));return r;}
    public List<IrBasicBlock> allCatches(IrBasicBlock n){return new ArrayList<>(catchEdges.getOrDefault(n,List.of()));}
    public void addLandingPad(LandingPad p){landingPads.add(p);addNode(p);}
    public void computeRpo(){rpo.clear();Set<IrBasicBlock> seen=Collections.newSetFromMap(new IdentityHashMap<>());Deque<IrBasicBlock> post=new ArrayDeque<>();if(entry!=null)dfs(entry,seen,post);while(!post.isEmpty())rpo.add(post.pop());for(int i=0;i<rpo.size();i++){rpo.get(i).num=i;offsetToNode.put(rpo.get(i).start,rpo.get(i));}}
    private void dfs(IrBasicBlock n,Set<IrBasicBlock>s,Deque<IrBasicBlock>post){if(!s.add(n))return;for(IrBasicBlock x:allSucs(n))dfs(x,s,post);post.push(n);}
    public Map<IrBasicBlock,IrBasicBlock> immediateDominators(){
        Map<IrBasicBlock,IrBasicBlock> idom=new IdentityHashMap<>(); if(entry==null)return idom; idom.put(entry,null); boolean changed=true;
        List<IrBasicBlock> order=new ArrayList<>(rpo); while(changed){changed=false;for(IrBasicBlock b:order){if(b==entry)continue;IrBasicBlock candidate=null;for(IrBasicBlock p:preds(b)){if(idom.containsKey(p)){candidate=candidate==null?p:intersect(p,candidate,idom);}}if(candidate!=null&&candidate!=idom.get(b)){idom.put(b,candidate);changed=true;}}}return idom;
    }
    private IrBasicBlock intersect(IrBasicBlock a,IrBasicBlock b,Map<IrBasicBlock,IrBasicBlock> idom){Set<IrBasicBlock>s=Collections.newSetFromMap(new IdentityHashMap<>());while(a!=null){s.add(a);a=idom.get(a);}while(b!=null&&!s.contains(b))b=idom.get(b);return b;}
    public List<IrBasicBlock> computeBlockOrder(){return new ArrayList<>(rpo);}
    @Override public Iterator<IrBasicBlock> iterator(){return rpo.iterator();}
}
