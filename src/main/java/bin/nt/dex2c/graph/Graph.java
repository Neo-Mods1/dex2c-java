package bin.nt.dex2c.graph;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.basic_blocks.LandingPad;

/**
 * Control-flow graph of one method.
 *
 * <p>Maintains both the normal successor edges and the exceptional
 * (try/catch) edges, together with reverse adjacency lists for SSA
 * construction. Nodes are basic blocks; landing pads are synthetic blocks
 * holding the exception handlers of a protected region.</p>
 */
public final class Graph implements Iterable<IrBasicBlock> {

    /** Entry block of the method. */
    public IrBasicBlock entry;

    /** Synthetic exit block (unused by the current lowering). */
    public IrBasicBlock exit;

    /** Every node of the graph, including landing pads. */
    public final List<IrBasicBlock> nodes = new ArrayList<>();

    /** Nodes in reverse post-order (RPO). */
    public final List<IrBasicBlock> rpo = new ArrayList<>();

    /** Exception landing pads created for the method. */
    public final List<LandingPad> landingPads = new ArrayList<>();

    /** Normal successor edges. */
    public final Map<IrBasicBlock, List<IrBasicBlock>> edges = new IdentityHashMap<>();

    /** Exceptional (catch) successor edges. */
    public final Map<IrBasicBlock, List<IrBasicBlock>> catchEdges = new IdentityHashMap<>();

    /** Reverse of {@link #edges}. */
    public final Map<IrBasicBlock, List<IrBasicBlock>> reverseEdges = new IdentityHashMap<>();

    /** Reverse of {@link #catchEdges}. */
    public final Map<IrBasicBlock, List<IrBasicBlock>> reverseCatchEdges = new IdentityHashMap<>();

    /** Maps an instruction offset to its basic block. */
    public final Map<Integer, IrBasicBlock> offsetToNode = new HashMap<>();

    /** Maps a block inside a protected region to its landing pad. */
    public final Map<IrBasicBlock, LandingPad> nodeToLandingPad = new IdentityHashMap<>();

    /** Registers a node in the graph. */
    public void addNode(IrBasicBlock n) {
        nodes.add(n);
        edges.putIfAbsent(n, new ArrayList<>());
        catchEdges.putIfAbsent(n, new ArrayList<>());
        reverseEdges.putIfAbsent(n, new ArrayList<>());
        reverseCatchEdges.putIfAbsent(n, new ArrayList<>());
    }

    private static void add(Map<IrBasicBlock, List<IrBasicBlock>> m, IrBasicBlock a, IrBasicBlock b) {
        m.computeIfAbsent(a, k -> new ArrayList<>());
        if (!m.get(a).contains(b)) {
            m.get(a).add(b);
        }
    }

    /** Adds a normal edge {@code a -> b}. */
    public void addEdge(IrBasicBlock a, IrBasicBlock b) {
        add(edges, a, b);
        add(reverseEdges, b, a);
    }

    /** Adds an exceptional edge {@code a -> b}. */
    public void addCatchEdge(IrBasicBlock a, IrBasicBlock b) {
        add(catchEdges, a, b);
        add(reverseCatchEdges, b, a);
    }

    /** Normal successors of a block. */
    public List<IrBasicBlock> sucs(IrBasicBlock n) {
        return new ArrayList<>(edges.getOrDefault(n, List.of()));
    }

    /** Normal plus exceptional successors of a block. */
    public List<IrBasicBlock> allSucs(IrBasicBlock n) {
        List<IrBasicBlock> r = sucs(n);
        r.addAll(catchEdges.getOrDefault(n, List.of()));
        return r;
    }

    /** Normal predecessors of a block. */
    public List<IrBasicBlock> preds(IrBasicBlock n) {
        return new ArrayList<>(reverseEdges.getOrDefault(n, List.of()));
    }

    /** Normal plus exceptional predecessors of a block. */
    public List<IrBasicBlock> allPreds(IrBasicBlock n) {
        List<IrBasicBlock> r = preds(n);
        r.addAll(reverseCatchEdges.getOrDefault(n, List.of()));
        return r;
    }

    /** Exceptional successors of a block. */
    public List<IrBasicBlock> allCatches(IrBasicBlock n) {
        return new ArrayList<>(catchEdges.getOrDefault(n, List.of()));
    }

    /** Registers a landing pad as both a node and an exceptional block. */
    public void addLandingPad(LandingPad p) {
        landingPads.add(p);
        addNode(p);
    }

    /**
     * Computes the RPO ordering of the graph and assigns block numbers.
     */
    public void computeRpo() {
        rpo.clear();
        Set<IrBasicBlock> seen = Collections.newSetFromMap(new IdentityHashMap<>());
        Deque<IrBasicBlock> post = new ArrayDeque<>();
        if (entry != null) {
            dfs(entry, seen, post);
        }
        while (!post.isEmpty()) {
            rpo.add(post.pop());
        }
        for (int i = 0; i < rpo.size(); i++) {
            rpo.get(i).num = i;
            offsetToNode.put(rpo.get(i).start, rpo.get(i));
        }
    }

    private void dfs(IrBasicBlock n, Set<IrBasicBlock> s, Deque<IrBasicBlock> post) {
        if (!s.add(n)) {
            return;
        }
        for (IrBasicBlock x : allSucs(n)) {
            dfs(x, s, post);
        }
        post.push(n);
    }

    /**
     * Computes the immediate-dominator tree via the classic data-flow
     * iteration.
     *
     * @return a map from each block to its immediate dominator
     */
    public Map<IrBasicBlock, IrBasicBlock> immediateDominators() {
        Map<IrBasicBlock, IrBasicBlock> idom = new IdentityHashMap<>();
        if (entry == null) {
            return idom;
        }
        idom.put(entry, null);
        boolean changed = true;
        List<IrBasicBlock> order = new ArrayList<>(rpo);
        while (changed) {
            changed = false;
            for (IrBasicBlock b : order) {
                if (b == entry) {
                    continue;
                }
                IrBasicBlock candidate = null;
                for (IrBasicBlock p : preds(b)) {
                    if (idom.containsKey(p)) {
                        candidate = candidate == null ? p : intersect(p, candidate, idom);
                    }
                }
                if (candidate != null && candidate != idom.get(b)) {
                    idom.put(b, candidate);
                    changed = true;
                }
            }
        }
        return idom;
    }

    private IrBasicBlock intersect(IrBasicBlock a, IrBasicBlock b, Map<IrBasicBlock, IrBasicBlock> idom) {
        Set<IrBasicBlock> s = Collections.newSetFromMap(new IdentityHashMap<>());
        while (a != null) {
            s.add(a);
            a = idom.get(a);
        }
        while (b != null && !s.contains(b)) {
            b = idom.get(b);
        }
        return b;
    }

    /** Blocks in RPO, ready for the SSA construction walk. */
    public List<IrBasicBlock> computeBlockOrder() {
        return new ArrayList<>(rpo);
    }

    @Override
    public Iterator<IrBasicBlock> iterator() {
        return rpo.iterator();
    }
}
