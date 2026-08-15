package bin.nt.dex2c;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.graph.Graph;
import bin.nt.dex2c.instruction.Constant;
import bin.nt.dex2c.instruction.Phi;
import bin.nt.dex2c.instruction.Variable;

/**
 * Smoke test for the IR core: values, the control-flow graph, RPO ordering,
 * immediate dominators and trivial-phi elimination.
 */
public final class PortSmokeTest {

    private PortSmokeTest() {
    }

    public static void main(String[] args) {
        Variable a = new Variable(0, 0);
        if (!a.setType("I")) {
            throw new AssertionError();
        }
        Constant z = new Constant(0, null);
        if (!z.isConstant()) {
            throw new AssertionError();
        }
        if (!z.refineType("I")) {
            throw new AssertionError();
        }

        IrBasicBlock e = new IrBasicBlock(0, null);
        IrBasicBlock b1 = new IrBasicBlock(2, null);
        IrBasicBlock b2 = new IrBasicBlock(4, null);
        IrBasicBlock join = new IrBasicBlock(6, null);
        Graph g = new Graph();
        g.addNode(e);
        g.addNode(b1);
        g.addNode(b2);
        g.addNode(join);
        g.entry = e;
        g.addEdge(e, b1);
        g.addEdge(e, b2);
        g.addEdge(b1, join);
        g.addEdge(b2, join);
        g.computeRpo();
        if (g.rpo.size() != 4) {
            throw new AssertionError("bad RPO");
        }
        if (g.immediateDominators().get(join) == null) {
            throw new AssertionError("bad dominator");
        }

        Phi p = new Phi(0, 1);
        p.setBlock(join);
        p.addOperand(b1, a);
        p.addOperand(b2, a);
        join.addPhi(p);
        if (!p.removeTrivialPhi()) {
            throw new AssertionError("phi cleanup");
        }
        System.out.println("dex2c IR smoke test: PASS");
    }
}
