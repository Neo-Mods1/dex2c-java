package bin.nt.dex2c.compiler;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;

import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.reference.FieldReference;
import com.android.tools.smali.dexlib2.iface.reference.CallSiteReference;
import com.android.tools.smali.dexlib2.iface.reference.MethodReference;
import com.android.tools.smali.dexlib2.iface.reference.TypeReference;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.graph.Graph;
import bin.nt.dex2c.instruction.DexInstruction;
import bin.nt.dex2c.instruction.Constant;
import bin.nt.dex2c.instruction.Instruction;
import bin.nt.dex2c.instruction.Phi;
import bin.nt.dex2c.instruction.Value;
import bin.nt.dex2c.instruction.Variable;

/**
 * Builds SSA form for a single method.
 *
 * <p>Implements the classic Braun &amp; Buchwald &amp; Hack SSA construction
 * algorithm: the graph is walked with current-definition maps, incomplete
 * phis are patched when blocks are sealed, and trivial phis are removed
 * afterwards. Value types are propagated and verified once SSA is done.</p>
 */
public final class SsaBuilder {

    private final Graph g;
    private final Method method;
    private final Map<Integer, Integer> versions = new HashMap<>();
    private final Map<IrBasicBlock, Boolean> processed = new IdentityHashMap<>();
    private IrBasicBlock current;

    /**
     * @param g      the method's control-flow graph (already lifted)
     * @param method the source method
     */
    public SsaBuilder(Graph g, Method m) {
        this.g = g;
        this.method = m;
    }

    /**
     * Runs the SSA construction and returns the ready-to-write IR method.
     *
     * @return the lowered method
     */
    public IrMethod build() {
        defineParams();
        g.entry.sealed = true;
        ArrayDeque<IrBasicBlock> q = new ArrayDeque<>();
        q.add(g.entry);
        while (!q.isEmpty()) {
            IrBasicBlock b = q.removeFirst();
            if (b.filled && processed.put(b, true) != null) {
                continue;
            }
            current = b;
            for (Instruction ii : b.instrList) {
                process((DexInstruction) ii);
            }
            b.filled = true;
            trySeal(b);
            q.addAll(g.allSucs(b));
        }
        removeTrivial();
        hackPolymorphicConstants();
        inferTypes();
        fixConstTypes();
        // The fallback constant type can unlock dependent phis/results, so
        // always run inference once more exactly like the reference builder.
        inferTypes();
        IrMethod ir = new IrMethod(method, g);
        IrVerifier.verify(ir);
        verifyIRInvariants();
        verifyOperandTypes();
        verifyPhiOperandTypes();
        for (IrBasicBlock b : g.nodes) {
            for (Instruction i : b.instrList) {
                if (i.getValue() != null) {
                    b.varToDeclare.add(i.getValue());
                }
            }
            for (Phi p : b.phis) {
                b.varToDeclare.add(p);
            }
        }
        ir.collect();
        return ir;
    }

    /**
     * Creates SSA variables for the method's parameters, including the
     * implicit {@code this} reference of instance methods.
     */
    private void defineParams() {
        int reg;
        try {
            reg = method.getImplementation().getRegisterCount() - parameterSlots(method);
        } catch (Exception e) {
            reg = 0;
        }
        if ((method.getAccessFlags() & 0x8) == 0) {
            Variable v = newVar(reg, false);
            v.setType(method.getDefiningClass());
            g.entry.updateCurrentDefinition(reg, v);
            g.entry.varToDeclare.add(v);
            reg++;
        }
        for (CharSequence p : method.getParameterTypes()) {
            String t = p.toString();
            Variable v = newVar(reg, false);
            v.setType(t);
            g.entry.updateCurrentDefinition(reg, v);
            g.entry.varToDeclare.add(v);
            reg += slots(t);
        }
    }

    /** Number of registers occupied by the method's parameters. */
    private static int parameterSlots(Method m) {
        int n = 0;
        if ((m.getAccessFlags() & 0x8) == 0) {
            n++;
        }
        for (CharSequence p : m.getParameterTypes()) {
            n += slots(p.toString());
        }
        return n;
    }

    /** Register slots consumed by a type: wide types take two. */
    private static int slots(String t) {
        return "J".equals(t) || "D".equals(t) ? 2 : 1;
    }

    /** Creates a new (or phi) versioned variable for a register. */
    private Variable newVar(int r, boolean phi) {
        int v = versions.getOrDefault(r, 0);
        versions.put(r, v + 1);
        return phi ? new Phi(r, v) : new Variable(r, v);
    }

    /** Declares a fresh definition of a register in the current block. */
    private Variable write(int r) {
        Variable v = newVar(r, false);
        current.updateCurrentDefinition(r, v);
        return v;
    }

    /** Reads the current value of a register, following back-edges if needed. */
    private Value read(int r) {
        Variable v = current.readCurrentDefinition(r);
        if (v != null) {
            return v;
        }
        return readRecursive(r, current);
    }

    /** Braun recursion: inserts a phi at join blocks or walks predecessors. */
    private Value readRecursive(int r, IrBasicBlock b) {
        List<IrBasicBlock> ps = g.allPreds(b);
        Phi phi = (Phi) newVar(r, true);
        if (!b.sealed) {
            b.addIncompletePhi(phi);
            phi.setBlock(b);
            b.updateCurrentDefinition(r, phi);
            return phi;
        }
        if (ps.size() == 1) {
            Value x = readFrom(r, ps.get(0));
            b.updateCurrentDefinition(r, (Variable) x);
            return x;
        }
        b.updateCurrentDefinition(r, phi);
        b.addPhi(phi);
        for (IrBasicBlock p : ps) {
            phi.addOperand(p, readFrom(r, p));
        }
        return phi;
    }

    /** Reads a register in another block, swapping the "current" context. */
    private Value readFrom(int r, IrBasicBlock b) {
        Variable v = b.readCurrentDefinition(r);
        if (v != null) {
            return v;
        }
        IrBasicBlock old = current;
        current = b;
        Value x = read(r);
        current = old;
        return x;
    }

    /** Seals every successor whose predecessors are all processed. */
    private void trySeal(IrBasicBlock b) {
        for (IrBasicBlock s : g.allSucs(b)) {
            List<IrBasicBlock> ps = g.allPreds(s);
            boolean all = true;
            for (IrBasicBlock p : ps) {
                if (!p.filled) {
                    all = false;
                }
            }
            if (all) {
                seal(s);
            }
        }
    }

    /** Finalizes a block: patches its incomplete phis from all predecessors. */
    private void seal(IrBasicBlock b) {
        if (b.sealed) {
            return;
        }
        b.sealed = true;
        for (Phi p : new ArrayList<>(b.incompletePhis)) {
            for (IrBasicBlock pred : g.allPreds(b)) {
                p.addOperand(pred, readFrom(p.getRegister(), pred));
            }
            b.addPhi(p);
        }
        b.clearIncompletePhis();
    }

    /**
     * Lowers one DEX instruction into the SSA representation: reads its
     * register operands, writes its destination and records the result.
     *
     * @param d the DEX instruction
     */
    private void process(DexInstruction d) {
        String o = d.opcode();
        int[] r = d.registers();
        boolean writes = setsRegister(d);
        int dest = writes && r.length > 0 ? r[0] : Integer.MIN_VALUE;
        if (isMoveResult(o)) {
            Value src = read(-1);
            Variable out = write(dest);
            out.refineType(src.getType());
            d.setValue(out);
            d.addOperand(src);
            return;
        }
        if (o.equals("filled-new-array") || o.equals("filled-new-array/range")) {
            // filled-new-array writes Dalvik's result register (-1); the
            // following move-result* consumes it. Do not synthesize the
            // destination register here or the writer will bypass the
            // result-register semantics.
            for (int x : r) {
                d.addOperand(read(x));
            }
            String at = typeFor(d);
            Variable res = write(-1);
            res.refineType(at);
            d.setValue(res);
            return;
        }
        if (isConst(d) && !o.equals("const-string") && !o.equals("const-string/jumbo") && !o.equals("const-class")) {
            Variable out = write(dest);
            d.setValue(out);
            if (d.literal() != null) {
                d.addOperand(new Constant(d.literal(), null));
            }
            return;
        }
        if (isInvoke(o)) {
            int i = 0;
            if (!isStaticInvoke(o) && !o.startsWith("invoke-custom") && r.length > 0) {
                d.addOperand(read(r[i++]));
            }
            if (d.reference() instanceof MethodReference) {
                int j = i;
                for (CharSequence p : ((MethodReference) d.reference()).getParameterTypes()) {
                    d.addOperand(read(r[j])); j += slots(p.toString());
                }
                i = j;
            } else if (d.reference() instanceof CallSiteReference) {
                int j = i;
                for (CharSequence p : ((CallSiteReference)d.reference()).getMethodProto().getParameterTypes()) {
                    d.addOperand(read(r[j])); j += slots(p.toString());
                }
                i = j;
            }
            for (; i < r.length; i++) d.addOperand(read(r[i]));
            String rt = invokeReturn(d);
            if (rt != null && !"V".equals(rt)) {
                Variable res = write(-1);
                res.refineType(rt);
                d.setValue(res);
            }
            return;
        }
        if (writes) {
            for (int i = 1; i < r.length; i++) {
                d.addOperand(read(r[i]));
            }
            Variable out = write(dest);
            d.setValue(out);
            String tf = typeFor(d);
            out.refineType(tf);
            if (tf == null && !d.getOperands().isEmpty()) {
                out.refineType(d.getOperands().get(0).getType());
            }
        } else {
            for (int x : r) {
                d.addOperand(read(x));
            }
        }
        if (isConst(d) && d.getValue() != null && d.getValue().getType() == null) {
            /* constant type is resolved during the inference pass */
        }
    }

    /** Whether the opcode writes a register, via the DEX opcode table. */
    private static boolean setsRegister(DexInstruction d) {
        try {
            return d.getDexInstruction() instanceof com.android.tools.smali.dexlib2.iface.instruction.Instruction
                    && ((com.android.tools.smali.dexlib2.iface.instruction.Instruction) d.getDexInstruction())
                            .getOpcode().setsRegister();
        } catch (Exception e) {
            return writesByName(d.opcode());
        }
    }

    /** Fallback opcode-name table used when the DEX metadata is unavailable. */
    private static boolean writesByName(String o) {
        return o.startsWith("move") || o.startsWith("const") || o.startsWith("aget") || o.startsWith("iget")
                || o.startsWith("sget") || o.startsWith("new-") || o.startsWith("add-") || o.startsWith("sub-")
                || o.startsWith("mul-") || o.startsWith("div-") || o.startsWith("rem-") || o.startsWith("and-")
                || o.startsWith("or-") || o.startsWith("xor-") || o.startsWith("shl-") || o.startsWith("shr-")
                || o.startsWith("ushr-") || o.startsWith("neg-") || o.startsWith("not-") || o.startsWith("int-to-")
                || o.startsWith("long-to-") || o.startsWith("float-to-") || o.startsWith("double-to-")
                || o.startsWith("cmp");
    }

    private static boolean isMoveResult(String o) {
        return o.startsWith("move-result");
    }

    private static boolean isInvoke(String o) {
        return o.startsWith("invoke-");
    }

    private static boolean isStaticInvoke(String o) {
        return o.startsWith("invoke-static");
    }

    private static boolean isConst(DexInstruction d) {
        return d.opcode().startsWith("const");
    }

    /** Return type of the invoked method, or {@code V} when unknown. */
    private String invokeReturn(DexInstruction d) {
        if (d.reference() instanceof MethodReference) return ((MethodReference) d.reference()).getReturnType();
        if (d.reference() instanceof CallSiteReference) return ((CallSiteReference)d.reference()).getMethodProto().getReturnType();
        return "V";
    }

    /**
     * Statically infers the destination type of a DEX instruction.
     *
     * @param d the instruction
     * @return the type, or {@code null} when it cannot be determined statically
     */
    private String typeFor(DexInstruction d) {
        String o = d.opcode();
        if (o.equals("const-string") || o.equals("const-string/jumbo")) {
            return "Ljava/lang/String;";
        }
        if (o.equals("array-length")) {
            return "I";
        }
        if (o.equals("const-class")) return "Ljava/lang/Class;";
        if (o.equals("const-method-handle")) return "Ljava/lang/invoke/MethodHandle;";
        if (o.equals("const-method-type")) return "Ljava/lang/invoke/MethodType;";
        if (o.equals("new-instance") && d.reference() instanceof TypeReference) {
            return ((TypeReference) d.reference()).getType();
        }
        if (o.equals("new-array") && d.reference() instanceof TypeReference) {
            return ((TypeReference) d.reference()).getType();
        }
        if ((o.equals("filled-new-array") || o.equals("filled-new-array/range"))
                && d.reference() instanceof TypeReference) {
            return ((TypeReference) d.reference()).getType();
        }
        if (d.reference() instanceof FieldReference && (o.startsWith("iget") || o.startsWith("sget"))) {
            return ((FieldReference) d.reference()).getType();
        }
        if (o.startsWith("const-wide")) {
            return "J";
        }
        if (o.startsWith("const")) {
            return null;
        }
        if (o.startsWith("cmp")) {
            return "I";
        }
        if (o.startsWith("neg-int") || o.startsWith("not-int") || o.startsWith("add-int") || o.startsWith("sub-int")
                || o.startsWith("mul-int") || o.startsWith("div-int") || o.startsWith("rem-int") || o.startsWith("and-int")
                || o.startsWith("or-int") || o.startsWith("xor-int") || o.startsWith("shl-int") || o.startsWith("shr-int")
                || o.startsWith("ushr-int") || o.startsWith("if-")) {
            return "I";
        }
        if (o.contains("long")) {
            return "J";
        }
        if (o.contains("double")) {
            return "D";
        }
        if (o.contains("float")) {
            return "F";
        }
        if (o.contains("object")) {
            return "Ljava/lang/Object;";
        }
        if (o.equals("move-exception")) {
            return current.catchType == null ? "Ljava/lang/Throwable;" : current.catchType;
        }
        return null;
    }

    /** Removes phis whose operands are all identical (trivial phis). */
    private void removeTrivial() {
        boolean changed;
        do {
            changed = false;
            for (IrBasicBlock b : g.rpo) {
                for (Phi p : new ArrayList<>(b.phis)) {
                    changed |= p.removeTrivialPhi();
                }
            }
        } while (changed);
    }

    /** Propagates types across the SSA graph until it converges. */
    private void inferTypes() {
        for (int pass = 0; pass < 500; pass++) {
            boolean changed = false;
            for (IrBasicBlock b : g.rpo) {
                inferExpectedOperandTypes();
                for (Phi p : b.phis) {
                    changed |= p.resolveType();
                }
                for (Instruction i : b.instrList) {
                    changed |= inferInstruction((DexInstruction) i);
                }
            }
            if (!changed) {
                return;
            }
        }
        throw new IllegalStateException("type inference did not converge");
    }

    /** Refines the destination type of a single instruction. */
    private boolean inferInstruction(DexInstruction d) {
        Value v = d.getValue();
        if (v == null) {
            return false;
        }
        String t = typeFor(d);
        if (t == null && d.getOperands().size() > 0) {
            t = d.getOperands().get(0).getType();
            if (("aget".equals(d.opcode()) || "aget-wide".equals(d.opcode()))
                    && t != null && t.startsWith("[") && t.length() > 1) {
                t = t.substring(1);
            }
        }
        return v.refineType(t);
    }

    /** Specializes unresolved literal constants per use, matching the reference. */
    private void hackPolymorphicConstants() {
        List<DexInstruction> constants = new ArrayList<>();
        for (IrBasicBlock b : g.rpo) {
            for (Instruction i : new ArrayList<>(b.instrList)) {
                if (i instanceof DexInstruction) {
                    DexInstruction d = (DexInstruction)i;
                    if (isPolymorphicLiteral(d) && d.getValue() != null && d.getValue().getType() == null) constants.add(d);
                }
            }
        }
        for (DexInstruction original : constants) {
            Value old = original.getValue();
            List<Instruction> users = new ArrayList<>(old.getUsers());
            if (users.size() <= 1) continue;
            IrBasicBlock block = (IrBasicBlock)original.getParent();
            for (Instruction user : users) {
                if (user == original) continue;
                DexInstruction copy = original.copyForSsa();
                int reg = old instanceof Variable ? ((Variable)old).getRegister() : 0;
                Variable nv = new Variable(reg, versions.getOrDefault(reg, 0));
                versions.put(reg, nv.getVersion() + 1);
                copy.setValue(nv);
                for (Value op : original.getOperands()) {
                    if (op instanceof Constant) copy.addOperand(new Constant(((Constant)op).getConstant(), null));
                    else copy.addOperand(op);
                }
                block.addInsBefore(copy, user);
                user.replaceUse(old, nv);
            }
        }
    }

    private static boolean isPolymorphicLiteral(DexInstruction d) {
        String o=d.opcode();
        return o.startsWith("const") && !o.startsWith("const-string") && !o.startsWith("const-class")
                && !o.startsWith("const-method") && d.literal()!=null;
    }

    /** Defaults unresolved constants by payload width, matching the reference. */
    private void fixConstTypes() {
        for (IrBasicBlock b : g.rpo) {
            for (Instruction i : b.instrList) {
                if (!(i instanceof DexInstruction) || i.getValue()==null || i.getValue().getType()!=null) continue;
                DexInstruction d=(DexInstruction)i;
                if (!isConst(d)) continue;
                Long n=d.literal();
                if (n!=null) i.getValue().refineType(n>=Integer.MIN_VALUE && n<=Integer.MAX_VALUE ? "I" : "J");
            }
        }
    }

    /** Pushes expected operand types backwards from consuming instructions. */
    private void inferExpectedOperandTypes() {
        for (IrBasicBlock b : g.rpo) for (Instruction ii : b.instrList) {
            DexInstruction d=(DexInstruction)ii;
            for (int i=0;i<d.getOperands().size();i++) {
                String t=expectedOperandType(d,i);
                if (t!=null) d.getOperands().get(i).refineType(t);
            }
        }
    }

    private String expectedOperandType(DexInstruction d,int index) {
        String o=d.opcode();
        if (o.startsWith("if-")) {
            if (o.contains("object")) return "Ljava/lang/Object;";
            for (Value existing : d.getOperands()) if (Value.TypeUtil.isRef(existing.getType())) return "Ljava/lang/Object;";
            if (o.contains("long")) return "J"; if (o.contains("float")) return "F";
            if (o.contains("double")) return "D"; return "I";
        }
        if (o.matches("(add|sub|mul|div|rem|and|or|xor|shl|shr|ushr)-.*")) {
            if (o.contains("long")) return "J"; if (o.contains("float")) return "F";
            if (o.contains("double")) return "D"; return "I";
        }
        if (o.startsWith("neg-")||o.startsWith("not-")) {
            if (o.contains("long")) return "J"; if (o.contains("float")) return "F"; if (o.contains("double")) return "D"; return "I";
        }
        if (o.startsWith("int-to-")) return "I"; if (o.startsWith("long-to-")) return "J";
        if (o.startsWith("float-to-")) return "F"; if (o.startsWith("double-to-")) return "D";
        if (o.startsWith("return-")) return method.getReturnType();
        if (o.equals("return") && !"V".equals(method.getReturnType())) return method.getReturnType();
        if (o.startsWith("invoke-") && d.reference() instanceof CallSiteReference) {
            CallSiteReference cs=(CallSiteReference)d.reference();
            int pos=index;
            if (pos>=0 && pos<cs.getMethodProto().getParameterTypes().size()) return cs.getMethodProto().getParameterTypes().get(pos).toString();
        }
        if (o.startsWith("invoke-") && d.reference() instanceof MethodReference) {
            MethodReference m=(MethodReference)d.reference();
            if (!isStaticInvoke(o) && index==0) return m.getDefiningClass();
            int pos=isStaticInvoke(o)?index:index-1;
            if (pos>=0 && pos<m.getParameterTypes().size()) return m.getParameterTypes().get(pos).toString();
        }
        if ((o.startsWith("iget")||o.startsWith("iput")||o.startsWith("sget")||o.startsWith("sput")) && d.reference() instanceof FieldReference) {
            FieldReference f=(FieldReference)d.reference();
            if (o.startsWith("iget")||o.startsWith("iput")) return index==0?f.getDefiningClass():f.getType();
            return f.getType();
        }
        if (o.equals("throw")||o.equals("monitor-enter")||o.equals("monitor-exit")) return "Ljava/lang/Object;";
        return null;
    }

    /** Verifies that every instruction result has a concrete type. */
    private void verifyOperandTypes() {
        for (IrBasicBlock b : g.rpo) {
            for (Instruction i : b.instrList) {
                if (i.getValue() != null && i.getValue().getType() == null) {
                    throw new IllegalStateException("unknown type at " + i
                            + " in block " + b.start);
                }
                for (Value v : i.getOperands()) {
                    if (v != null && v.getType() == null) {
                        throw new IllegalStateException("unknown operand type at " + i);
                    }
                }
            }
        }
    }

    /** Verifies phi incoming values against the reference's type families. */
    private void verifyPhiOperandTypes() {
        for (IrBasicBlock b : g.rpo) {
            for (Phi p : b.phis) {
                String pt = p.getType();
                if (pt == null) {
                    throw new IllegalStateException("unknown phi type " + p);
                }
                if (p.getOperands().size() != g.allPreds(b).size()) {
                    throw new IllegalStateException("phi predecessor mismatch at block " + b.start);
                }
                for (Value v : p.getOperands().values()) {
                    String vt = v.getType();
                    if (vt == null) {
                        throw new IllegalStateException("unknown phi operand type " + p);
                    }
                    if (Value.TypeUtil.isInt(pt) && Value.TypeUtil.isInt(vt)) continue;
                    if (Value.TypeUtil.isFloat(pt) && Value.TypeUtil.isFloat(vt)) continue;
                    if (Value.TypeUtil.isRef(pt) && Value.TypeUtil.isRef(vt)) continue;
                    if (!pt.equals(vt)) {
                        throw new IllegalStateException("inconsistent phi operand type " + p
                                + " " + pt + " " + vt);
                    }
                }
            }
        }
    }

    /** Verifies definition/use invariants before native lowering. */
    private void verifyIRInvariants() {
        for (IrBasicBlock b : g.rpo) for (Instruction i : b.instrList) {
            for (Value v : i.getOperands()) if (v.getDefinition()==null && !v.isConstant())
                throw new IllegalStateException("use without definition at "+i);
            if (i.getValue()!=null && i.getValue().getDefinition()!=i)
                throw new IllegalStateException("definition mismatch at "+i);
        }
    }


}
