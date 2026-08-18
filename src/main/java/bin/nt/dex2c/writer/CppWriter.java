package bin.nt.dex2c.writer;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.reference.MethodReference;
import com.android.tools.smali.dexlib2.iface.reference.CallSiteReference;
import com.android.tools.smali.dexlib2.iface.reference.MethodHandleReference;
import com.android.tools.smali.dexlib2.iface.reference.MethodProtoReference;
import com.android.tools.smali.dexlib2.iface.reference.FieldReference;
import com.android.tools.smali.dexlib2.iface.value.*;
import com.android.tools.smali.dexlib2.iface.reference.StringReference;
import com.android.tools.smali.dexlib2.iface.reference.TypeReference;

import bin.nt.dex2c.basic_blocks.IrBasicBlock;
import bin.nt.dex2c.basic_blocks.LandingPad;
import bin.nt.dex2c.compiler.IrMethod;
import bin.nt.dex2c.instruction.Constant;
import bin.nt.dex2c.instruction.DexInstruction;
import bin.nt.dex2c.instruction.Instruction;
import bin.nt.dex2c.instruction.Phi;
import bin.nt.dex2c.instruction.Value;
import bin.nt.dex2c.instruction.Variable;
import bin.nt.dex2c.util.Types;

/**
 * Native writer for a lowered method.
 *
 * <p>Deliberately emits ordinary JNI instead of relying on an Android runtime
 * library. Every helper the output needs (division/modulo with checked
 * overflow, float/double bit reinterpretation, exception dispatch) is
 * self-contained, so the generated source compiles with a stock NDK
 * toolchain.</p>
 */
public final class CppWriter {

    /** Bit flag for static methods in a DEX access-flags word. */
    private static final int ACC_STATIC = 0x8;

    /**
     * Emits the complete C++ body for one method.
     *
     * @param ir      the lowered method
     * @param dynamic whether to append the RegisterNatives metadata comment
     * @return the C++ source
     */
    public String write(IrMethod ir, boolean dynamic) {
        Method m = ir.method;
        String jni = JniNames.name(m);
        StringBuilder b = new StringBuilder();
        appendFunctionComment(b, m);
        appendSignature(b, m, jni, dynamic);
        appendVariableDeclarations(b, ir);
        appendBody(b, ir);
        appendLandingPads(b, ir);
        appendReturnEpilogue(b, m);
        if (dynamic) {
            b.append(dynamicTable(m, jni));
        }
        return b.toString();
    }

    /** Emits the header comment identifying the compiled method. */
    private void appendFunctionComment(StringBuilder b, Method m) {
        b.append("\n/* ").append(m.getDefiningClass()).append("->")
         .append(m.getName()).append(descriptor(m)).append(" */\n");
    }

    /** Emits the JNI function signature and parameter list. */
    private void appendSignature(StringBuilder b, Method m, String jni, boolean dynamic) {
        if (!dynamic) {
            b.append("extern \"C\" JNIEXPORT ").append(Types.c(m.getReturnType()))
             .append(" JNICALL ").append(jni).append("(JNIEnv* env, ");
        } else {
            b.append(Types.c(m.getReturnType())).append(" ").append(jni)
             .append("(JNIEnv* env, ");
        }
        b.append((m.getAccessFlags() & ACC_STATIC) != 0 ? "jclass clazz" : "jobject thiz");
        int pi = 0;
        for (CharSequence p : m.getParameterTypes()) {
            b.append(", ").append(Types.c(p.toString())).append(" p").append(pi++);
        }
        b.append(") {\n");
        b.append("  if (env->PushLocalFrame(512) != 0) goto EX_UnwindBlock;\n");
    }

    /** Emits the {@code pendingException} holder and every SSA variable. */
    private void appendVariableDeclarations(StringBuilder b, IrMethod ir) {
        b.append("  jthrowable pendingException = NULL;\n");
        if (!"V".equals(ir.returnType)) {
            String rt = Types.c(ir.returnType);
            b.append("  ").append(rt).append(" __nt_return").append(cTypeInit(rt)).append(";\n");
        }
        Map<String, String[]> slots = new TreeMap<>();
        for (Value v : allVars(ir)) {
            if (v instanceof Variable) {
                Variable x = (Variable) v;
                String n = var(x, ir);
                String t = Types.c(x.getType());
                String[] prev = slots.get(n);
                if (prev == null || cTypePriority(t) > cTypePriority(prev[1])) {
                    slots.put(n, new String[]{n, t, x.getType()});
                }
            }
        }
        for (String[] e : slots.values()) {
            String t = e[1];
            b.append("  ").append(t).append(" ").append(e[0])
             .append(cTypeInit(t)).append(";\n");
        }
        slotTypes.clear();
        for (String[] e : slots.values()) {
            slotTypes.put(e[0], e[1]);
        }
    }

    /** Stable precedence when the same slot is used with conflicting types. */
    private static int cTypePriority(String t) {
        if (t == null || t.contains("Array") || t.equals("jobject") || t.equals("jstring")
                || t.equals("jclass") || t.equals("jthrowable") || t.equals("jweak")
                || t.equals("jchar")) {
            return 100;
        }
        if (t.equals("jlong") || t.equals("jdouble")) {
            return 50;
        }
        return 10;
    }

    /** Default initializer for a declared C++ type. */
    private static String cTypeInit(String t) {
        if (t != null && (t.contains("Array") || t.equals("jobject") || t.equals("jstring")
                || t.equals("jclass") || t.equals("jthrowable") || t.equals("jweak"))) {
            return " = NULL";
        }
        return " = 0";
    }

    /** Declared C++ types of every emitted variable, keyed by slot name. */
    private final Map<String, String> slotTypes = new HashMap<>();

    /** Emits every basic block: instructions and the block terminator. */
    private void appendBody(StringBuilder b, IrMethod ir) {
        for (IrBasicBlock n : ir.irblocks) {
            if (n.start < 0) {
                continue;
            }
            b.append("\n").append(n.label()).append(":\n");
            for (Instruction ii : n.instrList) {
                b.append("  ").append(lower((DexInstruction) ii, ir, n)).append("\n");
            }
            emitTerminator(b, n, ir);
        }
    }

    /** Emits the exception landing pads and their handler dispatch. */
    private void appendLandingPads(StringBuilder b, IrMethod ir) {
        Set<IrBasicBlock> live = Collections.newSetFromMap(new IdentityHashMap<>());
        live.addAll(ir.irblocks);
        for (LandingPad lp : ir.graph.landingPads) {
            if (!live.contains(lp.source)) {
                continue;
            }
            b.append("\n").append(lp.label())
             .append(":\n  pendingException = env->ExceptionOccurred(); env->ExceptionClear();\n");
            for (Map.Entry<String, IrBasicBlock> h : lp.handles.entrySet()) {
                b.append("  if (pendingException && env->IsInstanceOf(pendingException, nt_resolve_class(env, \"")
                 .append(Types.descToClass(h.getKey())).append("\"))) goto ")
                 .append(h.getValue().label()).append(";\n");
            }
            b.append("  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;\n");
        }
    }

    /** Emits the shared return/unwind epilogue labels. */
    private void appendReturnEpilogue(StringBuilder b, Method m) {
        if ("V".equals(m.getReturnType())) {
            b.append("EX_Return: env->PopLocalFrame(NULL); return;\nEX_UnwindBlock: env->PopLocalFrame(NULL); return;\n");
        } else if (Types.ref(m.getReturnType())) {
            b.append("EX_Return: return (").append(Types.c(m.getReturnType())).append(")env->PopLocalFrame((jobject)__nt_return);\n")
             .append("EX_UnwindBlock: env->PopLocalFrame(NULL); return (").append(Types.c(m.getReturnType())).append(")0;\n");
        } else {
            b.append("EX_Return: env->PopLocalFrame(NULL); return __nt_return;\n")
             .append("EX_UnwindBlock: env->PopLocalFrame(NULL); return (").append(Types.c(m.getReturnType())).append(")0;\n");
        }
        b.append("}\n");
    }

    /** Collects every value the function must declare, in visit order. */
    private Collection<Value> allVars(IrMethod ir) {
        Set<Value> s = Collections.newSetFromMap(new IdentityHashMap<>());
        for (IrBasicBlock n : ir.irblocks) {
            s.addAll(n.varToDeclare);
            for (Phi p : n.phis) {
                s.add(p);
                s.addAll(p.getOperands().values());
            }
            for (Instruction i : n.instrList) {
                if (i.getValue() != null) {
                    s.add(i.getValue());
                }
                s.addAll(i.getOperands());
            }
        }
        return s;
    }

    /** The SSA variable that the following {@code move-result} in the block will receive. */
    private String moveResultVar(IrBasicBlock block, DexInstruction d, IrMethod ir) {
        boolean past = false;
        for (Instruction i : block.instrList) {
            if (!past) {
                if (i == d) {
                    past = true;
                }
                continue;
            }
            if (((DexInstruction) i).opcode().startsWith("move-result")
                    && i.getValue() instanceof Variable) {
                return var((Variable) i.getValue(), ir);
            }
        }
        return null;
    }

    /** JNI name of the local variable holding an SSA value. */
    private String var(Variable v, IrMethod ir) {
        return "v" + ir.ra.get(v);
    }

    /** Initializer for a C++ variable based on its type. */
    private String defaultInit(String t) {
        return Types.ref(t) ? " = NULL" : " = 0";
    }

    /**
     * Lowers a single DEX instruction to one (or more) C++ statements.
     *
     * @param d     the DEX instruction
     * @param ir    the containing method
     * @param block the owning basic block
     * @return the emitted C++
     */
    private String lower(DexInstruction d, IrMethod ir, IrBasicBlock block) {
        String o = d.opcode();
        int[] r = d.registers();
        String dst = d.getValue() instanceof Variable ? var((Variable) d.getValue(), ir) : null;
        String a = r.length > 0 ? value(r[0], d, ir) : "0";
        String b = r.length > 1 ? value(r[1], d, ir) : "0";
        String c = r.length > 2 ? value(r[2], d, ir) : "0";

        if (o.equals("nop")) {
            return ";";
        }
        // Control-flow opcodes are emitted by emitTerminator(), not as body
        // expressions. Keep the instruction slot syntactically valid.
        if (o.startsWith("if-") || o.startsWith("goto")
                || o.equals("packed-switch") || o.equals("sparse-switch")
                || o.startsWith("return")) {
            return ";";
        }
        if (o.startsWith("move-result")) {
            String rv = d.getOperands().isEmpty() ? null : valueVar(d.getOperands().get(0), ir);
            if (rv == null) {
                return dst + " = " + assignCast(dst) + "NULL;";
            }
            String dv = d.getValue() == null ? null : d.getValue().getType();
            String sv = d.getOperands().get(0).getType();
            String dct = slotTypes.get(dst);
            String sct = d.getOperands().get(0) instanceof Variable
                    ? slotTypes.get(var((Variable) d.getOperands().get(0), ir)) : null;
            if (dv != null && sv != null && !dv.equals(sv)) {
                rv = "(" + Types.c(dv) + ")(intptr_t)" + rv;
            } else if (dct != null && sct != null && !dct.equals(sct)) {
                rv = "(" + dct + ")(intptr_t)" + rv;
            }
            return dst + " = " + rv + ";";
        }
        if (o.startsWith("move") && !o.startsWith("move-result") && !o.equals("move-exception")) {
            Value src = null;
            if (r.length > 1) {
                for (Value v : d.getOperands()) {
                    if (v instanceof Variable && ((Variable) v).getRegister() == r[1]) {
                        src = v;
                        break;
                    }
                }
            }
            String dct = slotTypes.get(dst);
            String sct = src instanceof Variable ? slotTypes.get(var((Variable) src, ir)) : null;
            if (dct != null && sct != null && !dct.equals(sct)) {
                b = "(" + dct + ")(intptr_t)" + b;
            }
            return dst + " = " + b + ";";
        }
        if (o.equals("move-exception")) {
            return dst + " = " + assignCast(dst) + "pendingException;";
        }
        if (o.startsWith("const-string")) {
            String sv = d.reference() instanceof StringReference
                    ? ((StringReference) d.reference()).getString()
                    : String.valueOf(d.reference());
            return dst + " = " + assignCast(dst) + "env->NewStringUTF(\"" + Types.escape(sv) + "\");";
        }
        if (o.equals("const-class")) {
            return dst + " = " + assignCast(dst) + "nt_resolve_class(env, \""
                    + Types.escape(Types.descToClass(refType(d))) + "\");";
        }
        if (o.equals("const-method-type") && d.reference() instanceof MethodProtoReference) {
            return dst + " = " + assignCast(dst) + "nt_make_method_type(env, \"" + Types.escape(protoDescriptor((MethodProtoReference)d.reference())) + "\");";
        }
        if (o.equals("const-method-handle") && d.reference() instanceof MethodHandleReference) {
            MethodHandleReference mh=(MethodHandleReference)d.reference();
            String lookup="nt_lk_"+Integer.toHexString(d.getOffset());
            String caller="nt_resolve_class(env, \""+Types.descToClass(ir.method.getDefiningClass())+"\")";
            if (mh.getMemberReference() instanceof MethodReference) {
                MethodReference m=(MethodReference)mh.getMemberReference();
                return "{ jobject "+lookup+"=nt_new_lookup(env,"+caller+"); "+dst+"="+assignCast(dst)+"nt_make_method_handle(env,"+lookup+",nt_resolve_class(env,\""+Types.descToClass(m.getDefiningClass())+"\"),\""+mh.getMethodHandleType()+"\",\""+Types.escape(m.getName())+"\",\""+Types.escape(descriptor(m))+"\",\""+Types.descToClass(m.getDefiningClass())+"\","+caller+"); }";
            }
            if (mh.getMemberReference() instanceof FieldReference) {
                FieldReference f=(FieldReference)mh.getMemberReference();
                return "{ jobject "+lookup+"=nt_new_lookup(env,"+caller+"); "+dst+"="+assignCast(dst)+"nt_make_method_handle(env,"+lookup+",nt_resolve_class(env,\""+Types.descToClass(f.getDefiningClass())+"\"),\""+mh.getMethodHandleType()+"\",\""+Types.escape(f.getName())+"\",\""+Types.escape(f.getType())+"\",\""+Types.escape(f.getType())+"\","+caller+"); }";
            }
        }
        if (o.startsWith("const")) {
            String ct = d.getValue() == null ? "I" : d.getValue().getType();
            if ("F".equals(ct)) {
                return dst + " = " + intCast(dst) + "nt_f32((uint32_t)" + literal(d) + ");";
            }
            if ("D".equals(ct)) {
                return dst + " = " + intCast(dst) + "nt_f64((uint64_t)" + literal(d) + ");";
            }
            return dst + " = " + intCast(dst) + literal(d) + ";";
        }
        if (o.equals("array-length")) {
            return dst + " = " + intCast(dst) + "env->GetArrayLength((jarray)(intptr_t)" + b + ");";
        }
        if (o.equals("new-instance")) {
            return dst + " = " + assignCast(dst) + "env->AllocObject(nt_resolve_class(env, \""
                    + Types.escape(Types.descToClass(refType(d))) + "\"));" + checkException(block, ir);
        }
        if (o.equals("new-array")) {
            return newArray(dst, b, refType(d)) + checkException(block, ir);
        }
        if (o.equals("filled-new-array") || o.equals("filled-new-array/range")) {
            String dstNew = dst != null ? dst : moveResultVar(block, d, ir);
            if (dstNew == null) {
                return "/* filled-new-array discarded */";
            }
            return filledArray(dstNew, r, refType(d), d, ir);
        }
        if (o.equals("throw")) {
            return "pendingException = (jthrowable)(intptr_t)" + a + "; env->Throw(pendingException);";
        }
        if (o.equals("monitor-enter")) {
            return "env->MonitorEnter((jobject)(intptr_t)" + a + ");" + checkException(block, ir);
        }
        if (o.equals("monitor-exit")) {
            return "env->MonitorExit((jobject)(intptr_t)" + a + ");" + checkException(block, ir);
        }
        if (o.equals("check-cast")) {
            LandingPad lp = ir.graph.nodeToLandingPad.get(block);
            return "if(" + a + " && !env->IsInstanceOf((jobject)(intptr_t)" + a + ", nt_resolve_class(env, \""
                    + Types.descToClass(refType(d))
                    + "\"))) { env->ThrowNew(nt_resolve_class(env, \"java/lang/ClassCastException\"), \"check-cast\"); goto "
                    + (lp == null ? "EX_UnwindBlock" : lp.label()) + "; }";
        }
        if (o.equals("instance-of")) {
            String obj = d.getOperands().isEmpty() ? b : valueVar(d.getOperands().get(0), ir);
            return dst + " = " + assignCast(dst) + "(" + obj
                    + " != NULL && env->IsInstanceOf((jobject)(intptr_t)" + obj + ", nt_resolve_class(env, \""
                    + Types.descToClass(refType(d)) + "\")) ? 1 : 0);";
        }
        if (o.startsWith("aget")) {
            return arrayGet(d, dst, b, c) + checkException(block, ir);
        }
        if (o.startsWith("aput")) {
            return arrayPut(d, a, b, c) + checkException(block, ir);
        }
        if (o.equals("fill-array-data")) {
            return fillArrayData(d, a, ir);
        }
        if (o.startsWith("iget")) {
            return fieldGet(d, dst, b, false) + checkException(block, ir);
        }
        if (o.startsWith("iput")) {
            return fieldPut(d, a, b, false) + checkException(block, ir);
        }
        if (o.startsWith("sget")) {
            return fieldGet(d, dst, null, true) + checkException(block, ir);
        }
        if (o.startsWith("sput")) {
            return fieldPut(d, a, null, true) + checkException(block, ir);
        }
        if (o.equals("invoke-custom") || o.equals("invoke-custom/range")) {
            return invokeCustom(d, ir, block) + checkException(block, ir);
        }
        if (o.equals("invoke-polymorphic") || o.equals("invoke-polymorphic/range")) {
            return invokePolymorphic(d, ir) + checkException(block, ir);
        }
        if (o.startsWith("invoke-")) {
            return invoke(d, ir) + checkException(block, ir);
        }
        if (o.startsWith("return")) {
            return "/* return terminator */";
        }
        if (o.startsWith("neg-")) {
            return dst + " = " + intCast(dst) + "(-" + numIfPtr(b) + ");";
        }
        if (o.startsWith("not-")) {
            return dst + " = " + intCast(dst) + "(~" + numIfPtr(b) + ");";
        }
        String cast = castOp(o, numIfPtr(b));
        if (cast != null) {
            return dst + " = " + intCast(dst) + cast + ";";
        }
        String bin = binOp(o);
        if (bin != null) {
            return binaryLower(o, bin, a, b, c, dst, d);
        }
        if (o.startsWith("cmp")) {
            String t = numIfPtr(b);
            String u = numIfPtr(c);
            String rhs;
            if (o.contains("cmpl")) {
                rhs = "((" + t + " == " + u + ") ? 0 : (" + t + " > " + u + ") ? 1 : -1)";
            } else if (o.contains("cmpg")) {
                rhs = "((" + t + " == " + u + ") ? 0 : (" + t + " < " + u + ") ? -1 : 1)";
            } else {
                rhs = "(" + t + " > " + u + " ? 1 : " + t + " < " + u + " ? -1 : 0)";
            }
            return dst + " = " + intCast(dst) + rhs + ";";
        }
        throw new IllegalStateException("Unsupported opcode " + o + " at 0x"
                + Integer.toHexString(d.getOffset()));
    }

    /** Lowers a binary arithmetic operation, honoring literal and /2addr forms. */
    private String binaryLower(String o, String bin, String a, String b, String c, String dst, DexInstruction d) {
        boolean lit = o.contains("lit") || o.startsWith("rsub-int");
        boolean addr = o.contains("2addr");
        long litv = d.literal() == null ? 0 : d.literal();
        String x1 = addr ? a : b;
        String x2 = lit ? Long.toString(litv) : (addr ? b : c);
        String rhs;
        if (o.startsWith("rsub")) {
            rhs = "(" + x2 + " - " + numIfPtr(x1) + ")";
        } else {
            rhs = "(" + numIfPtr(x1) + " " + bin + " " + numIfPtr(x2) + ")";
        }
        if (bin.equals("/") && o.contains("int")) {
            rhs = "nt_div_i(env," + numIfPtr(x1) + "," + numIfPtr(x2) + ")";
        }
        if (bin.equals("%") && o.contains("int")) {
            rhs = "nt_rem_i(env," + numIfPtr(x1) + "," + numIfPtr(x2) + ")";
        }
        if (bin.equals("/") && o.contains("long")) {
            rhs = "nt_div_l(env," + numIfPtr(x1) + "," + numIfPtr(x2) + ")";
        }
        if (bin.equals("%") && o.contains("long")) {
            rhs = "nt_rem_l(env," + numIfPtr(x1) + "," + numIfPtr(x2) + ")";
        }
        if (bin.equals("%") && o.contains("float")) {
            rhs = "fmodf(" + numIfPtr(x1) + "," + numIfPtr(x2) + ")";
        }
        if (bin.equals("%") && o.contains("double")) {
            rhs = "fmod(" + numIfPtr(x1) + "," + numIfPtr(x2) + ")";
        }
        if (o.startsWith("ushr")) {
            rhs = "((uint" + (o.contains("long") ? "64_t" : "32_t") + ")" + numIfPtr(x1)
                    + " >> ((intptr_t)" + x2 + " & " + (o.contains("long") ? "63" : "31") + "))";
        }
        if (o.startsWith("shl") || o.startsWith("shr")) {
            rhs = "(" + numIfPtr(x1) + " " + bin + " ((intptr_t)" + x2 + " & "
                    + (o.contains("long") ? "63" : "31") + "))";
        }
        return dst + " = " + intCast(dst) + rhs + ";";
    }

    /** Emits the pending-exception check routed to the block's landing pad. */
    private String checkException(IrBasicBlock block, IrMethod ir) {
        LandingPad lp = ir.graph.nodeToLandingPad.get(block);
        return lp == null
                ? " if(env->ExceptionCheck()) goto EX_UnwindBlock;"
                : " if(env->ExceptionCheck()) goto " + lp.label() + ";";
    }

    /** Resolves the emitted variable name for a register. */
    private String value(int reg, DexInstruction d, IrMethod ir) {
        for (Value v : d.getOperands()) {
            if (v instanceof Variable && ((Variable) v).getRegister() == reg) {
                return var((Variable) v, ir);
            }
        }
        // A missing SSA definition is a compiler invariant violation.
        // Emitting v0 here used to turn compiler bugs into valid-looking but
        // catastrophically wrong native code.
        throw new IllegalStateException("Missing SSA value for register v" + reg
                + " in " + d.opcode() + " at 0x" + Integer.toHexString(d.getOffset()));
    }

    /** Emits a value as a C++ expression (variable, constant or default). */
    private String valueVar(Value v, IrMethod ir) {
        return v instanceof Variable ? var((Variable) v, ir)
                : v instanceof Constant ? String.valueOf(((Constant) v).getConstant())
                : "0";
    }

    /** Emits the literal of a const instruction. */
    private String literal(DexInstruction d) {
        if (d.literal() == null) {
            return "0";
        }
        return Long.toString(d.literal());
    }

    /** Whether a declared C++ type is a pointer-typed slot. */
    private static boolean isPtrSlot(String t) {
        return t != null && (t.contains("Array") || t.equals("jobject") || t.equals("jstring")
                || t.equals("jclass") || t.equals("jthrowable") || t.equals("jweak"));
    }

    /** Casts a value to an integer when its slot is pointer-typed. */
    private String numIfPtr(String x) {
        String t = slotTypes.get(x);
        return isPtrSlot(t) ? "(intptr_t)" + x : x;
    }

    /** Casts an expression to the exact destination type. */
    private String intCast(String dst) {
        String t = slotTypes.get(dst);
        return t == null ? "" : "(" + t + ")";
    }

    /** Number of register operands the DEX instruction actually declares. */
    private static int regCount(DexInstruction d, int fallback) {
        Object x = d.getDexInstruction();
        if (x != null) {
            try {
                Number n = (Number) x.getClass().getMethod("getRegisterCount").invoke(x);
                if (n != null && n.intValue() >= 0) {
                    return n.intValue();
                }
            } catch (Exception ignored) {
            }
        }
        return fallback;
    }

    /** Resolves the referenced type of a typed instruction. */
    private String refType(DexInstruction d) {
        if (d.reference() instanceof TypeReference) {
            return ((TypeReference) d.reference()).getType();
        }
        return "Ljava/lang/Object;";
    }

    /** Emits a filled-new-array allocation and its element stores. */
    private String filledArray(String dst, int[] regs, String t, DexInstruction d, IrMethod ir) {
        int n = regCount(d, regs.length);
        if (n > regs.length) {
            n = regs.length;
        }
        StringBuilder x = new StringBuilder();
        x.append(newArray(dst, Integer.toString(n), t));
        String e = t == null ? "Ljava/lang/Object;" : t.substring(1);
        for (int i = 0; i < n; i++) {
            String v = value(regs[i], d, ir);
            if (e.startsWith("L") || e.startsWith("[")) {
                x.append(" env->SetObjectArrayElement((jobjectArray)(intptr_t)").append(dst).append(", ").append(i)
                 .append(", (jobject)(intptr_t)").append(v).append(");");
            } else {
                String kind = kindOf(e);
                x.append(" env->Set").append(kind).append("ArrayRegion((").append(arrayType(kind))
                 .append(")(intptr_t)").append(dst).append(", ").append(i).append(", 1, (")
                 .append(elemType(kind)).append("*)&").append(v).append(");");
            }
        }
        return x.toString();
    }

    /** Lowers a fill-array-data payload into a static byte blob and a Set*ArrayRegion call. */
    private String fillArrayData(DexInstruction d, String arr, IrMethod ir) {
        Integer n = d.fillArraySize();
        Integer w = d.fillArrayElementWidth();
        byte[] data = d.fillArrayData();
        if (n == null || w == null || data == null || n <= 0) {
            throw new IllegalStateException("Missing fill-array-data payload at 0x"
                    + Integer.toHexString(d.getOffset()));
        }
        String t = slotTypes.get(arr);
        String e = t != null && t.startsWith("[") ? t.substring(1) : "B";
        StringBuilder x = new StringBuilder();
        x.append(" { static const unsigned char _fa[").append(data.length).append("] = {");
        for (int i = 0; i < data.length; i++) {
            if (i % 12 == 0) {
                x.append("\n");
            }
            x.append(data[i] & 0xff).append(", ");
        }
        x.append("}; env->Set").append(kindOf(e)).append("ArrayRegion((").append(arrayType(kindOf(e)))
         .append(")(intptr_t)").append(arr).append(", 0, ").append(n).append(", (")
         .append(elemType(kindOf(e))).append("*)&_fa[0]); }");
        return x.toString();
    }

    /** JNI accessor suffix implied by a primitive element descriptor. */
    private static String kindOf(String e) {
        if ("Z".equals(e)) return "Boolean";
        if ("B".equals(e)) return "Byte";
        if ("C".equals(e)) return "Char";
        if ("S".equals(e)) return "Short";
        if ("J".equals(e)) return "Long";
        if ("F".equals(e)) return "Float";
        if ("D".equals(e)) return "Double";
        return "Int";
    }

    /** Emits a typed array allocation. */
    private String newArray(String dst, String size, String t) {
        if (t == null || !t.startsWith("[")) {
            return dst + " = NULL;";
        }
        String e = t.substring(1);
        String sz = "(jsize)(intptr_t)" + size;
        String rhs;
        if ("Z".equals(e)) {
            rhs = "env->NewBooleanArray(" + sz + ")";
        } else if ("B".equals(e)) {
            rhs = "env->NewByteArray(" + sz + ")";
        } else if ("C".equals(e)) {
            rhs = "env->NewCharArray(" + sz + ")";
        } else if ("S".equals(e)) {
            rhs = "env->NewShortArray(" + sz + ")";
        } else if ("I".equals(e)) {
            rhs = "env->NewIntArray(" + sz + ")";
        } else if ("J".equals(e)) {
            rhs = "env->NewLongArray(" + sz + ")";
        } else if ("F".equals(e)) {
            rhs = "env->NewFloatArray(" + sz + ")";
        } else if ("D".equals(e)) {
            rhs = "env->NewDoubleArray(" + sz + ")";
        } else {
            rhs = "env->NewObjectArray(" + sz + ", nt_resolve_class(env, \""
                    + Types.descToClass(e) + "\"), NULL)";
        }
        return dst + " = " + assignCast(dst) + rhs + ";";
    }

    /** Maps an opcode to its C cast, or {@code null} when not a conversion. */
    private String castOp(String o, String b) {
        if (o.equals("int-to-long")) return "(jlong)" + b;
        if (o.equals("int-to-float")) return "(jfloat)" + b;
        if (o.equals("int-to-double")) return "(jdouble)" + b;
        if (o.equals("long-to-int")) return "(jint)" + b;
        if (o.equals("long-to-float")) return "(jfloat)" + b;
        if (o.equals("long-to-double")) return "(jdouble)" + b;
        if (o.equals("float-to-int")) return "nt_float_to_int(" + b + ")";
        if (o.equals("float-to-long")) return "nt_float_to_long(" + b + ")";
        if (o.equals("float-to-double")) return "(jdouble)" + b;
        if (o.equals("double-to-int")) return "nt_double_to_int(" + b + ")";
        if (o.equals("double-to-long")) return "nt_double_to_long(" + b + ")";
        if (o.equals("double-to-float")) return "(jfloat)" + b;
        if (o.equals("int-to-byte")) return "(jbyte)" + b;
        if (o.equals("int-to-char")) return "(jchar)" + b;
        if (o.equals("int-to-short")) return "(jshort)" + b;
        return null;
    }

    /** Maps an opcode to its C++ operator, or {@code null} when not binary. */
    private String binOp(String o) {
        // DEX names are add-int, sub-long/2addr, add-int/lit8, etc.
        // The old implementation looked for "-add-", which never occurs.
        // Keep this table deliberately explicit so new opcode families cannot
        // silently fall through to UNSUPPORTED.
        if (o.startsWith("add-")) return "+";
        if (o.startsWith("sub-") || o.startsWith("rsub")) return "-";
        if (o.startsWith("mul-")) return "*";
        if (o.startsWith("div-")) return "/";
        if (o.startsWith("rem-")) return "%";
        if (o.startsWith("and-")) return "&";
        if (o.startsWith("or-")) return "|";
        if (o.startsWith("xor-")) return "^";
        if (o.startsWith("shl-")) return "<<";
        if (o.startsWith("shr-")) return ">>";
        if (o.startsWith("ushr-")) return ">>";
        return null;
    }

    /** Emits a primitive or object array read. */
    private String arrayGet(DexInstruction d, String dst, String arr, String idx) {
        String s = arrayKind(d);
        if ("Object".equals(s)) {
            return dst + " = " + assignCast(dst)
                    + "env->GetObjectArrayElement((jobjectArray)(intptr_t)" + arr + ", (jsize)(intptr_t)" + idx + ");";
        }
        return "env->Get" + s + "ArrayRegion((" + arrayType(s) + ")(intptr_t)" + arr
                + ", (jsize)(intptr_t)" + idx
                + ", 1, (" + elemType(s) + "*)&" + dst + ");";
    }

    /** Emits a primitive or object array write. */
    private String arrayPut(DexInstruction d, String val, String arr, String idx) {
        String s = arrayKind(d);
        if ("Object".equals(s)) {
            return "env->SetObjectArrayElement((jobjectArray)(intptr_t)" + arr + ", (jsize)(intptr_t)" + idx
                    + ", (jobject)(intptr_t)" + val + ");";
        }
        return "env->Set" + s + "ArrayRegion((" + arrayType(s) + ")(intptr_t)" + arr + ", (jsize)(intptr_t)" + idx
                + ", 1, (" + elemType(s) + "*)&" + val + ");";
    }

    /** JNI array accessor suffix implied by the opcode. */
    private String arrayKind(DexInstruction d) {
        String o = d.opcode();
        if (o.contains("object")) return "Object";
        if (o.contains("boolean")) return "Boolean";
        if (o.contains("byte")) return "Byte";
        if (o.contains("char")) return "Char";
        if (o.contains("short")) return "Short";
        if (o.contains("wide")) return "Long";
        return "Int";
    }

    /** JNI array type for a primitive accessor suffix. */
    private String arrayType(String s) {
        if ("Boolean".equals(s)) return "jbooleanArray";
        if ("Byte".equals(s)) return "jbyteArray";
        if ("Char".equals(s)) return "jcharArray";
        if ("Short".equals(s)) return "jshortArray";
        if ("Long".equals(s)) return "jlongArray";
        if ("Float".equals(s)) return "jfloatArray";
        if ("Double".equals(s)) return "jdoubleArray";
        return "jintArray";
    }

    /** JNI element type for a primitive accessor suffix. */
    private String elemType(String s) {
        if ("Boolean".equals(s)) return "jboolean";
        if ("Byte".equals(s)) return "jbyte";
        if ("Char".equals(s)) return "jchar";
        if ("Short".equals(s)) return "jshort";
        if ("Long".equals(s)) return "jlong";
        if ("Float".equals(s)) return "jfloat";
        if ("Double".equals(s)) return "jdouble";
        return "jint";
    }

    /** Emits an instance or static field read. */
    private String fieldGet(DexInstruction d, String dst, String obj, boolean stat) {
        if (!(d.reference() instanceof FieldReference)) {
            throw new IllegalStateException("Invalid field reference for " + d.opcode());
        }
        FieldReference f = (FieldReference) d.reference();
        String cls = Types.descToClass(f.getDefiningClass());
        String name = Types.escape(f.getName());
        String sig = Types.escape(f.getType());
        String id = "nt_resolve_field(env, nt_resolve_class(env, \"" + cls + "\"), \"" + cls + "\", \"" + name + "\", \"" + sig + "\", " + stat + ")";
        String suf = Types.jniSuffix(f.getType());
        return dst + " = " + assignCast(dst)
                + "env->Get" + (stat ? "Static" : "") + suf + "Field("
                + (stat ? "nt_resolve_class(env, \"" + cls + "\")" : "(jobject)(intptr_t)" + obj)
                + ", " + id + ");";
    }

    /** Emits an instance or static field write. */
    private String fieldPut(DexInstruction d, String val, String obj, boolean stat) {
        if (!(d.reference() instanceof FieldReference)) {
            throw new IllegalStateException("Invalid field reference for " + d.opcode());
        }
        FieldReference f = (FieldReference) d.reference();
        String cls = Types.descToClass(f.getDefiningClass());
        String name = Types.escape(f.getName());
        String sig = Types.escape(f.getType());
        String id = "nt_resolve_field(env, nt_resolve_class(env, \"" + cls + "\"), \"" + cls + "\", \"" + name + "\", \"" + sig + "\", " + stat + ")";
        return "env->Set" + (stat ? "Static" : "") + Types.jniSuffix(f.getType()) + "Field("
                + (stat ? "nt_resolve_class(env, \"" + cls + "\")" : "(jobject)(intptr_t)" + obj)
                + ", " + id + ", "
                + (Types.ref(f.getType()) ? "(jobject)(intptr_t)" + val : castToParam(val, f.getType())) + ");";
    }

    /** Emits a method invocation, including range, static and super forms. */
    private String invoke(DexInstruction d, IrMethod ir) {
        if (!(d.reference() instanceof MethodReference)) {
            throw new IllegalStateException("Unsupported invoke reference for " + d.opcode());
        }
        MethodReference m = (MethodReference) d.reference();
        String cls = Types.descToClass(m.getDefiningClass());
        String sig = Types.escape(descriptor(m));
        String name = Types.escape(m.getName());
        boolean stat = d.opcode().contains("static");
        boolean sup = d.opcode().contains("super");
        String call = stat ? "CallStatic" : sup ? "CallNonvirtual" : "Call";
        String suf = Types.jniSuffix(m.getReturnType());
        String clsExpr = "nt_resolve_class(env, \"" + cls + "\")";
        String obj = stat || sup ? clsExpr
                : "(jobject)(intptr_t)" + (d.registers().length > 0 ? value(d.registers()[0], d, ir) : "thiz");
        List<CharSequence> params = new ArrayList<>(m.getParameterTypes());
        StringBuilder args = new StringBuilder();
        int cursor = stat ? 0 : 1;
        for (int pi = 0; pi < params.size(); pi++) {
            if (cursor >= d.registers().length) throw new IllegalStateException("invoke register/parameter mismatch at 0x" + Integer.toHexString(d.getOffset()));
            if (args.length() > 0) args.append(", ");
            String av = castToParam(value(d.registers()[cursor], d, ir), params.get(pi).toString());
            args.append(av);
            cursor += slots(params.get(pi).toString());
        }
        String expr = "nt_resolve_method(env, " + clsExpr + ", \"" + cls + "\", \"" + name + "\", \"" + sig + "\", " + stat + ")";
        String callExpr = "env->" + call + suf + "Method(" + obj + (sup ? ", " + clsExpr : "")
                + ", " + expr + (args.length() > 0 ? ", " + args : "") + ")";
        String result = d.getValue() instanceof Variable ? var((Variable) d.getValue(), ir) : null;
        if (result == null) {
            return callExpr + ";";
        }
        return result + " = " + assignCast(result) + callExpr + ";";
    }

    private static int slots(String t) { return ("J".equals(t) || "D".equals(t)) ? 2 : 1; }

    /** Signature-polymorphic MethodHandle invocation. API 26+. */
    private String invokePolymorphic(DexInstruction d, IrMethod ir) {
        if (!(d.reference() instanceof MethodReference)) throw new IllegalStateException("invoke-polymorphic requires MethodReference");
        MethodReference m=(MethodReference)d.reference();
        String cls=Types.descToClass(m.getDefiningClass());
        String sig=Types.escape(descriptor(m));
        String name=Types.escape(m.getName());
        String clsExpr="nt_resolve_class(env, \""+cls+"\")";
        String obj="(jobject)(intptr_t)"+value(d.registers()[0],d,ir);
        StringBuilder args=new StringBuilder(); int cursor=1;
        for(CharSequence p:m.getParameterTypes()) { if(args.length()>0)args.append(", "); args.append(castToParam(value(d.registers()[cursor],d,ir),p.toString())); cursor+=slots(p.toString()); }
        String id="nt_resolve_method(env, "+clsExpr+", \""+cls+"\", \""+name+"\", \""+sig+"\", false)";
        String call="env->Call"+Types.jniSuffix(m.getReturnType())+"Method("+obj+", "+id+(args.length()>0?", "+args:"")+")";
        if(d.getValue()==null) return call+";";
        String out=var((Variable)d.getValue(),ir);
        return out+" = "+assignCast(out)+call+";";
    }

    /** Lowers invoke-custom by explicitly running its API-26 bootstrap CallSite. */
    private String invokeCustom(DexInstruction d, IrMethod ir, IrBasicBlock block) {
        if (!(d.reference() instanceof CallSiteReference)) throw new IllegalStateException("invoke-custom requires CallSiteReference");
        CallSiteReference cs=(CallSiteReference)d.reference();
        MethodProtoReference proto=cs.getMethodProto();
        MethodHandleReference bh=cs.getMethodHandle();
        if (!(bh.getMemberReference() instanceof MethodReference)) throw new IllegalStateException("invoke-custom bootstrap is not a method");
        MethodReference bm=(MethodReference)bh.getMemberReference();
        String bowner=Types.descToClass(bm.getDefiningClass());
        String bdesc=Types.escape(descriptor(bm));
        String cdesc=Types.escape(protoDescriptor(proto));
        StringBuilder x=new StringBuilder("({ ");
        String tag="__nt_args_"+Integer.toHexString(d.getOffset());
        String extras="__nt_extras_"+Integer.toHexString(d.getOffset());
        String caller="nt_resolve_class(env, \""+Types.descToClass(ir.method.getDefiningClass())+"\")";
        String lookup="__nt_lk_"+Integer.toHexString(d.getOffset());
        x.append("jobject ").append(lookup).append("=nt_new_lookup(env,").append(caller).append("); ");
        x.append("jobjectArray ").append(extras).append("=env->NewObjectArray(").append(cs.getExtraArguments().size()).append(", nt_resolve_class(env, \"java/lang/Object\"), NULL); ");
        int exi=0;
        for (EncodedValue ev : cs.getExtraArguments()) {
            x.append("env->SetObjectArrayElement(").append(extras).append(",").append(exi).append(",");
            x.append(customExtraExpression(ev,lookup,caller));
            x.append("); "); exi++;
        }
        x.append("jobjectArray ").append(tag).append("=env->NewObjectArray(").append(proto.getParameterTypes().size()).append(", nt_resolve_class(env, \"java/lang/Object\"), NULL); ");
        int cursor=0; int pi=0;
        for(CharSequence p:proto.getParameterTypes()) {
            String t=p.toString(); String av=value(d.registers()[cursor],d,ir);
            x.append("jvalue __v{}; ".replace("{}",Integer.toString(pi)));
            if("J".equals(t)) x.append("__v").append(pi).append(".j=(jlong)").append(av).append("; ");
            else if("F".equals(t)) x.append("__v").append(pi).append(".f=(jfloat)").append(av).append("; ");
            else if("D".equals(t)) x.append("__v").append(pi).append(".d=(jdouble)").append(av).append("; ");
            else if("Z".equals(t)) x.append("__v").append(pi).append(".z=(jboolean)").append(av).append("; ");
            else if(Types.ref(t)) x.append("__v").append(pi).append(".l=(jobject)(intptr_t)").append(av).append("; ");
            else x.append("__v").append(pi).append(".i=(jint)").append(av).append("; ");
            x.append("env->SetObjectArrayElement(").append(tag).append(",").append(pi).append(",nt_box(env,\"").append(t).append("\",__v").append(pi).append(")); ");
            cursor+=slots(t); pi++;
        }
        String ret=proto.getReturnType();
        x.append("jobject __nt_out=nt_invoke_custom(env,").append(caller).append(",\"").append(bowner).append("\",\"").append(Types.escape(bm.getName())).append("\",\"").append(bdesc).append("\",\"").append(Types.escape(cs.getName())).append("\",\"").append(cdesc).append("\",").append(extras).append(",").append(tag).append("); ");
        if(d.getValue()!=null) {
            String out=var((Variable)d.getValue(),ir);
            if(Types.ref(ret)) x.append(out).append("=").append(assignCast(out)).append("__nt_out; ");
            else x.append("jvalue __r=nt_unbox(env,__nt_out,\"").append(ret).append("\"); ");
            if("J".equals(ret)) x.append(out).append("=__r.j; "); else if("F".equals(ret)) x.append(out).append("=__r.f; "); else if("D".equals(ret)) x.append(out).append("=__r.d; "); else if(!Types.ref(ret)) x.append(out).append("=__r.i; ");
        }
        x.append("});");
        return x.toString();
    }

    private String customExtraExpression(EncodedValue ev, String lookup, String caller) {
        if (ev instanceof StringEncodedValue) return "env->NewStringUTF(\"" + Types.escape(((StringEncodedValue)ev).getValue()) + "\")";
        if (ev instanceof MethodTypeEncodedValue) return "nt_make_method_type(env,\"" + Types.escape(protoDescriptor(((MethodTypeEncodedValue)ev).getValue())) + "\")";
        if (ev instanceof MethodHandleEncodedValue) {
            MethodHandleReference mh=((MethodHandleEncodedValue)ev).getValue();
            if (mh.getMemberReference() instanceof MethodReference) {
                MethodReference m=(MethodReference)mh.getMemberReference();
                return "nt_make_method_handle(env,"+lookup+",nt_resolve_class(env,\""+Types.descToClass(m.getDefiningClass())+"\"),\""+mh.getMethodHandleType()+"\",\""+Types.escape(m.getName())+"\",\""+Types.escape(descriptor(m))+"\",\""+Types.descToClass(m.getDefiningClass())+"\","+caller+")";
            }
            if (mh.getMemberReference() instanceof FieldReference) {
                FieldReference f=(FieldReference)mh.getMemberReference();
                return "nt_make_method_handle(env,"+lookup+",nt_resolve_class(env,\""+Types.descToClass(f.getDefiningClass())+"\"),\""+mh.getMethodHandleType()+"\",\""+Types.escape(f.getName())+"\",\""+Types.escape(f.getType())+"\",\""+Types.escape(f.getType())+"\","+caller+")";
            }
        }
        if (ev instanceof NullEncodedValue) return "NULL";
        if (ev instanceof BooleanEncodedValue) return "nt_box_z(env,"+(((BooleanEncodedValue)ev).getValue()?"JNI_TRUE":"JNI_FALSE")+")";
        if (ev instanceof ByteEncodedValue) return "nt_box_i(env,"+((ByteEncodedValue)ev).getValue()+")";
        if (ev instanceof ShortEncodedValue) return "nt_box_i(env,"+((ShortEncodedValue)ev).getValue()+")";
        if (ev instanceof CharEncodedValue) return "nt_box_i(env,"+((int)((CharEncodedValue)ev).getValue())+")";
        if (ev instanceof IntEncodedValue) return "nt_box_i(env,"+((IntEncodedValue)ev).getValue()+")";
        if (ev instanceof LongEncodedValue) return "nt_box_j(env,"+((LongEncodedValue)ev).getValue()+")";
        if (ev instanceof FloatEncodedValue) return "nt_box_f(env,"+((FloatEncodedValue)ev).getValue()+"f)";
        if (ev instanceof DoubleEncodedValue) return "nt_box_d(env,"+((DoubleEncodedValue)ev).getValue()+")";
        throw new IllegalStateException("Unsupported invoke-custom bootstrap argument: "+ev.getClass().getName());
    }

    private static String protoDescriptor(MethodProtoReference p) {
        StringBuilder b=new StringBuilder("("); for(CharSequence t:p.getParameterTypes()) b.append(t); return b.append(')').append(p.getReturnType()).toString();
    }

    /** C-style cast to the declared C++ type of an emitted variable. */
    private String assignCast(String dst) {
        String dct = slotTypes.get(dst);
        if (dct == null) {
            throw new IllegalStateException("Missing C++ type for destination " + dst);
        }
        return "(" + dct + ")";
    }

    /** Casts a call argument to the JNI type of its descriptor parameter. */
    private String castToParam(String av, String p) {
        String want = p.startsWith("L") || p.startsWith("[") ? "jobject"
                : "J".equals(p) ? "jlong"
                : "D".equals(p) ? "jdouble"
                : "F".equals(p) ? "jfloat" : "jint";
        String at = slotTypes.get(av);
        if (at == null || want.equals(at)) {
            return av;
        }
        if (want.equals("jobject")) {
            return "(jobject)(intptr_t)" + av;
        }
        return "(" + want + ")" + av;
    }

    /** Emits the control-flow terminator of a basic block. */
    private void emitTerminator(StringBuilder b, IrBasicBlock n, IrMethod ir) {
        if (n.instrList.isEmpty()) {
            List<IrBasicBlock> es = ir.graph.sucs(n);
            if (es.size() == 1) {
                edge(b, n, es.get(0), ir);
            }
            return;
        }
        DexInstruction d = (DexInstruction) n.instrList.get(n.instrList.size() - 1);
        String o = d.opcode();
        List<IrBasicBlock> s = ir.graph.sucs(n);
        if (o.startsWith("return")) {
            String rv = d.getOperands().isEmpty() ? "" : valueVar(d.getOperands().get(0), ir);
            if ("V".equals(ir.returnType)) {
                b.append("  goto EX_Return;\n");
            } else {
                b.append("  __nt_return = ").append(rv.isEmpty() ? "0" : "(" + Types.c(ir.returnType) + ")" + rv).append("; goto EX_Return;\n");
            }
            return;
        }
        if (o.equals("throw")) {
            LandingPad lp = ir.graph.nodeToLandingPad.get(n);
            b.append("  goto ").append(lp == null ? "EX_UnwindBlock" : lp.label()).append(";\n");
            return;
        }
        if (o.startsWith("if-") && s.size() >= 2) {
            String cond = condition(o, d, ir);
            IrBasicBlock taken = s.get(0);
            IrBasicBlock fall = s.get(1);
            b.append("  if (").append(cond).append(") { ");
            edge(b, n, taken, ir);
            b.append(" } else { ");
            edge(b, n, fall, ir);
            b.append(" }\n");
            return;
        }
        if (o.startsWith("goto") && !s.isEmpty()) {
            edge(b, n, s.get(0), ir);
            return;
        }
        if ((o.equals("packed-switch") || o.equals("sparse-switch")) && !s.isEmpty()) {
            b.append("  switch((jint)")
             .append(numIfPtr(d.getOperands().isEmpty() ? "0" : valueVar(d.getOperands().get(0), ir))).append(") {\n");
            for (Map.Entry<Integer, Integer> e : d.switchTargets().entrySet()) {
                for (IrBasicBlock x : s) {
                    if (x.start == e.getValue()) {
                        b.append("    case ").append(e.getKey()).append(": ");
                        edge(b, n, x, ir);
                        break;
                    }
                }
            }
            b.append("    default: ");
            for (IrBasicBlock x : s) {
                boolean used = d.switchTargets().containsValue(x.start);
                if (!used) {
                    edge(b, n, x, ir);
                    break;
                }
            }
            b.append("  }\n");
            return;
        }
        if (s.size() == 1) {
            edge(b, n, s.get(0), ir);
        } else if (s.size() > 1) {
            edge(b, n, s.get(0), ir);
        } else {
            b.append("  goto EX_Return;\n");
        }
    }

    /** Builds the C++ boolean expression of a conditional branch. */
    private String condition(String o, DexInstruction d, IrMethod ir) {
        String a = d.getOperands().size() > 0 ? valueVar(d.getOperands().get(0), ir) : "0";
        String b = d.getOperands().size() > 1 ? valueVar(d.getOperands().get(1), ir) : "0";
        if (o.endsWith("eqz")) {
            b = "0";
        }
        boolean objectCompare = o.endsWith("-object") || (!d.getOperands().isEmpty() && Value.TypeUtil.isRef(d.getOperands().get(0).getType()));
        if (objectCompare && ("if-eq".equals(o) || "if-eq-object".equals(o) || "if-eqz".equals(o))) {
            if ("if-eqz".equals(o)) return "env->IsSameObject((jobject)(intptr_t)" + a + ", NULL)";
            return "env->IsSameObject((jobject)(intptr_t)" + a + ", (jobject)(intptr_t)" + b + ")";
        }
        if (objectCompare && ("if-ne".equals(o) || "if-ne-object".equals(o) || "if-nez".equals(o))) {
            if ("if-nez".equals(o)) return "!env->IsSameObject((jobject)(intptr_t)" + a + ", NULL)";
            return "!env->IsSameObject((jobject)(intptr_t)" + a + ", (jobject)(intptr_t)" + b + ")";
        }
        a = numIfPtr(a);
        b = numIfPtr(b);
        if ("if-eq".equals(o) || "if-eqz".equals(o)) return a + " == " + b;
        if ("if-ne".equals(o) || "if-nez".equals(o)) return a + " != " + b;
        if ("if-lt".equals(o) || "if-ltz".equals(o)) return a + " < " + b;
        if ("if-ge".equals(o) || "if-gez".equals(o)) return a + " >= " + b;
        if ("if-gt".equals(o) || "if-gtz".equals(o)) return a + " > " + b;
        if ("if-le".equals(o) || "if-lez".equals(o)) return a + " <= " + b;
        return "false";
    }

    /** Emits phi copies followed by the goto for one edge. */
    private void edge(StringBuilder b, IrBasicBlock from, IrBasicBlock to, IrMethod ir) {
        for (Phi p : to.phis) {
            Value in = p.getOperands().get(from);
            if (in != null) {
                String t = Types.c(p.getType());
                if (!p.getType().equals(in.getType())) {
                    t = "(" + t + ")(intptr_t)";
                } else {
                    t = "(" + t + ")";
                }
                b.append("v").append(ir.ra.get(p)).append(" = ").append(t)
                 .append(valueVar(in, ir)).append("; ");
            }
        }
        b.append("goto ").append(to.label()).append(";\n");
    }

    /** Emits the RegisterNatives metadata comment. */
    private String dynamicTable(Method m, String jni) {
        return "\n/* RegisterNatives entry for " + m.getName() + descriptor(m) + " -> " + jni + " */\n";
    }

    /** Builds the JVM descriptor of a method reference. */
    private static String descriptor(MethodReference m) {
        StringBuilder x = new StringBuilder("(");
        for (CharSequence p : m.getParameterTypes()) {
            x.append(p);
        }
        return x.append(")").append(m.getReturnType()).toString();
    }

    /** Builds the JVM descriptor of a method. */
    private static String descriptor(Method m) {
        StringBuilder x = new StringBuilder("(");
        for (CharSequence p : m.getParameterTypes()) {
            x.append(p);
        }
        return x.append(")").append(m.getReturnType()).toString();
    }

    /**
     * JNI symbol name helpers.
     *
     * <p>Emits the long form ({@code Java_<class>_<method>__<mangled-sig>})
     * exactly as the reference dex2c does, so overloaded methods always resolve
     * to distinct exported symbols.</p>
     */
    public static final class JniNames {
        private JniNames() {
        }

        /** Long JNI name of a method. */
        public static String name(Method m) {
            return longName(m.getDefiningClass(), m.getName(), descriptor(m));
        }

        /** Builds {@code Java_<class>_<method>__<mangled-params>}. */
        public static String longName(String cls, String method, String desc) {
            return shortName(cls, method) + "__" + mangle(desc.substring(1, desc.indexOf(')')));
        }

        /** Builds {@code Java_<class>_<method>}. */
        public static String shortName(String cls, String method) {
            return "Java_" + mangle(cls.substring(1, cls.length() - 1)) + "_" + mangle(method);
        }

        /** JNI mangling of one UTF-16 string. */
        public static String mangle(String s) {
            StringBuilder r = new StringBuilder(s.length() * 2);
            for (int i = 0; i < s.length(); i++) {
                char ch = s.charAt(i);
                if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9')) {
                    r.append(ch);
                } else if (ch == '.' || ch == '/') {
                    r.append('_');
                } else if (ch == '_') {
                    r.append("_1");
                } else if (ch == ';') {
                    r.append("_2");
                } else if (ch == '[') {
                    r.append("_3");
                } else {
                    r.append(String.format("_0%04x", (int) ch));
                }
            }
            return r.toString();
        }
    }
}
