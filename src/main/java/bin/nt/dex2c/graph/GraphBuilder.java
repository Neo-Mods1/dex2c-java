package bin.nt.dex2c.graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.MethodImplementation;
import com.android.tools.smali.dexlib2.iface.instruction.Instruction;
import com.android.tools.smali.dexlib2.iface.instruction.OffsetInstruction;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.basic_blocks.LandingPad;

/**
 * Constructs the control-flow graph of a method.
 *
 * <p>Basic-block leaders are found first (entry, branch and switch targets,
 * instruction after a terminator, try-block boundaries), then edges are
 * added for conditional/goto/switch/fall-through control flow, try/catch
 * regions are wired through catch edges, and landing pads are created for
 * every protected region.</p>
 */
public final class GraphBuilder {

    private GraphBuilder() {
    }

    /**
     * Builds the graph of a method.
     *
     * @param method the source method
     * @return the control-flow graph in RPO
     */
    public static Graph build(Method method) {
        Graph g = new Graph();
        MethodImplementation impl = method.getImplementation();
        if (impl == null) {
            return g;
        }
        List<Instruction> list = new ArrayList<>();
        for (Instruction q : impl.getInstructions()) {
            list.add(q);
        }
        Map<Integer, Instruction> at = new LinkedHashMap<>();
        Map<Instruction, Integer> off = new IdentityHashMap<>();
        int pc = 0;
        for (Instruction i : list) {
            at.put(pc, i);
            off.put(i, pc);
            pc += i.getCodeUnits();
        }
        int codeSize = pc;

        Set<Integer> leaders = new TreeSet<>();
        leaders.add(0);
        for (Map.Entry<Integer, Instruction> e : at.entrySet()) {
            int p = e.getKey();
            Instruction i = e.getValue();
            String op = op(i);
            if (i instanceof OffsetInstruction) {
                int t = p + ((OffsetInstruction) i).getCodeOffset();
                if (t >= 0 && t < codeSize) {
                    leaders.add(t);
                }
            }
            for (int t : switchTargets(i, p)) {
                if (t >= 0 && t < codeSize) {
                    leaders.add(t);
                }
            }
            if (isConditional(op) || isSwitch(op) || isGoto(op) || isTerminal(op)) {
                int n = p + i.getCodeUnits();
                if (n < codeSize) {
                    leaders.add(n);
                }
            }
        }
        addTryLeaders(impl, leaders, codeSize);

        List<Integer> ls = new ArrayList<>(leaders);
        Map<Integer, IrBasicBlock> bm = new HashMap<>();
        for (int s : ls) {
            IrBasicBlock b = new IrBasicBlock(s, null);
            g.addNode(b);
            bm.put(s, b);
        }
        g.entry = bm.get(0);

        for (int idx = 0; idx < ls.size(); idx++) {
            int s = ls.get(idx);
            int e = idx + 1 < ls.size() ? ls.get(idx + 1) : codeSize;
            Instruction last = null;
            int p = s;
            while (p < e) {
                last = at.get(p);
                p += last.getCodeUnits();
            }
            if (last == null) {
                continue;
            }
            IrBasicBlock b = bm.get(s);
            String op = op(last);
            if (isSwitch(op)) {
                for (int t : switchTargets(last, off.get(last))) {
                    if (bm.containsKey(t)) {
                        g.addEdge(b, bm.get(t));
                    }
                }
                if (!isTerminal(op) && e < codeSize) {
                    g.addEdge(b, bm.get(e));
                }
            } else if (isConditional(op)) {
                int t = off.get(last) + ((OffsetInstruction) last).getCodeOffset();
                if (bm.containsKey(t)) {
                    g.addEdge(b, bm.get(t));
                }
                if (e < codeSize) {
                    g.addEdge(b, bm.get(e));
                }
            } else if (isGoto(op)) {
                int t = off.get(last) + ((OffsetInstruction) last).getCodeOffset();
                if (bm.containsKey(t)) {
                    g.addEdge(b, bm.get(t));
                }
            } else if (!isTerminal(op) && e < codeSize) {
                g.addEdge(b, bm.get(e));
            }
        }

        addTryEdges(method, impl, g, bm, codeSize);
        buildLandingPads(impl, g, bm);
        g.computeRpo();
        return g;
    }

    /** DEX opcode name in the IR's dash-separated form. */
    static String op(Instruction i) {
        return i.getOpcode().name().toLowerCase(Locale.ROOT).replace('_', '-');
    }

    private static boolean isConditional(String o) {
        return o.startsWith("if-");
    }

    private static boolean isSwitch(String o) {
        return o.equals("packed-switch") || o.equals("sparse-switch");
    }

    private static boolean isGoto(String o) {
        return o.startsWith("goto");
    }

    private static boolean isTerminal(String o) {
        return o.startsWith("return") || o.equals("throw") || o.equals("throw-verification-error");
    }

    /**
     * Collects the absolute targets of a switch payload.
     *
     * @param i    the switch instruction
     * @param base the instruction's own offset
     * @return the target offsets
     */
    static List<Integer> switchTargets(Instruction i, int base) {
        List<Integer> r = new ArrayList<>();
        try {
            java.lang.reflect.Method m = i.getClass().getMethod("getSwitchElements");
            Object x = m.invoke(i);
            if (x instanceof Iterable<?>) {
                for (Object e : (Iterable<?>) x) {
                    java.lang.reflect.Method q = e.getClass().getMethod("getOffset");
                    r.add(base + ((Number) q.invoke(e)).intValue());
                }
            }
        } catch (Exception ignored) {
        }
        return r;
    }

    /** Marks try-block starts, ends and handler starts as leaders. */
    static void addTryLeaders(MethodImplementation impl, Set<Integer> leaders, int codeSize) {
        try {
            for (Object tb : (Iterable<?>) impl.getClass().getMethod("getTryBlocks").invoke(impl)) {
                int s = num(tb, "getStartCodeAddress");
                int end = s + num(tb, "getCodeUnitCount");
                if (s >= 0 && s < codeSize) {
                    leaders.add(s);
                }
                if (end >= 0 && end < codeSize) {
                    leaders.add(end);
                }
                Object hs = tb.getClass().getMethod("getExceptionHandlers").invoke(tb);
                for (Object h : (Iterable<?>) hs) {
                    int a = num(h, "getHandlerCodeAddress");
                    if (a >= 0 && a < codeSize) {
                        leaders.add(a);
                    }
                }
            }
        } catch (Exception ignored) {
        }
    }

    /** Wires catch edges from every block of a try region to its handlers. */
    static void addTryEdges(Method method, MethodImplementation impl, Graph g,
                            Map<Integer, IrBasicBlock> bm, int codeSize) {
        try {
            for (Object tb : (Iterable<?>) impl.getClass().getMethod("getTryBlocks").invoke(impl)) {
                int s = num(tb, "getStartCodeAddress");
                int end = s + num(tb, "getCodeUnitCount");
                Object hs = tb.getClass().getMethod("getExceptionHandlers").invoke(tb);
                for (Object h : (Iterable<?>) hs) {
                    int target = num(h, "getHandlerCodeAddress");
                    IrBasicBlock dst = bm.get(target);
                    if (dst == null) {
                        continue;
                    }
                    String type = exceptionType(h);
                    dst.inCatch = true;
                    dst.catchType = type;
                    for (IrBasicBlock src : g.nodes) {
                        if (src.start >= s && src.start < end) {
                            g.addCatchEdge(src, dst);
                            src.catchSuccessors.add(dst);
                        }
                    }
                }
            }
        } catch (Exception ignored) {
        }
    }

    /** Reads the caught exception type of a handler, defaulting to Throwable. */
    private static String exceptionType(Object h) {
        try {
            Object t = h.getClass().getMethod("getExceptionType").invoke(h);
            return t == null ? "Ljava/lang/Throwable;" : t.toString();
        } catch (Exception ignored) {
            return "Ljava/lang/Throwable;";
        }
    }

    /** Invokes a no-arg getter and returns its int value. */
    static int num(Object o, String method) throws Exception {
        return ((Number) o.getClass().getMethod(method).invoke(o)).intValue();
    }

    /** Creates a landing pad for every protected region. */
    static void buildLandingPads(MethodImplementation impl, Graph g, Map<Integer, IrBasicBlock> bm) {
        try {
            for (Object tb : (Iterable<?>) impl.getClass().getMethod("getTryBlocks").invoke(impl)) {
                int s = num(tb, "getStartCodeAddress");
                int end = s + num(tb, "getCodeUnitCount");
                LandingPad lp = null;
                Object hs = tb.getClass().getMethod("getExceptionHandlers").invoke(tb);
                for (Object h : (Iterable<?>) hs) {
                    int target = num(h, "getHandlerCodeAddress");
                    IrBasicBlock dst = bm.get(target);
                    if (dst == null) {
                        continue;
                    }
                    if (lp == null) {
                        IrBasicBlock src = bm.get(s);
                        if (src == null) {
                            continue;
                        }
                        lp = new LandingPad(src);
                        g.landingPads.add(lp);
                        g.nodeToLandingPad.put(src, lp);
                    }
                    lp.addCatchHandle(exceptionType(h), dst);
                }
                if (lp != null) {
                    for (IrBasicBlock src : g.nodes) {
                        if (src.start >= s && src.start < end) {
                            g.nodeToLandingPad.putIfAbsent(src, lp);
                        }
                    }
                }
            }
        } catch (Exception ignored) {
        }
    }
}
