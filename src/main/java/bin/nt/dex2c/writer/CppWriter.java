package bin.nt.dex2c.writer;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.reference.FieldReference;
import com.android.tools.smali.dexlib2.iface.reference.MethodReference;
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
    }

    /** Emits the {@code pendingException} holder and every SSA variable. */
    private void appendVariableDeclarations(StringBuilder b, IrMethod ir) {
        b.append("  jthrowable pendingException = NULL;\n");
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
        for (LandingPad lp : ir.graph.landingPads) {
            b.append("\n").append(lp.label())
             .append(":\n  pendingException = env->ExceptionOccurred(); env->ExceptionClear();\n");
            for (Map.Entry<String, IrBasicBlock> h : lp.handles.entrySet()) {
                b.append("  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass(\"")
                 .append(Types.descToClass(h.getKey())).append("\"))) goto ")
                 .append(h.getValue().label()).append(";\n");
            }
            b.append("  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;\n");
        }
    }

    /** Emits the shared return/unwind epilogue labels. */
    private void appendReturnEpilogue(StringBuilder b, Method m) {
        if ("V".equals(m.getReturnType())) {
            b.append("EX_Return: return;\nEX_UnwindBlock: return;\n");
        } else {
            b.append("EX_Return: return (").append(Types.c(m.getReturnType())).append(")0;\n")
             .append("EX_UnwindBlock: return (").append(Types.c(m.getReturnType())).append(")0;\n");
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
        if (o.startsWith("move-result")) {
            String rv = d.getOperands().isEmpty() ? null : valueVar(d.getOperands().get(0), ir);
            if (rv == null) {
                return dst + " = NULL;";
            }
            String dv = d.getValue() == null ? null : d.getValue().getType();
            String sv = d.getOperands().get(0).getType();
            if (dv != null && sv != null && !dv.equals(sv)) {
                rv = "(" + Types.c(dv) + ")(intptr_t)" + rv;
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
            return dst + " = pendingException;";
        }
        if (o.startsWith("const-string")) {
            String sv = d.reference() instanceof StringReference
                    ? ((StringReference) d.reference()).getString()
                    : String.valueOf(d.reference());
            return dst + " = env->NewStringUTF(\"" + Types.escape(sv) + "\");";
        }
        if (o.equals("const-class")) {
            return dst + " = env->FindClass(\"" + Types.escape(Types.descToClass(refType(d))) + "\");";
        }
        if (o.startsWith("const")) {
            String ct = d.getValue() == null ? "I" : d.getValue().getType();
            if ("F".equals(ct)) {
                return dst + " = nt_f32((uint32_t)" + literal(d) + ");";
            }
            if ("D".equals(ct)) {
                return dst + " = nt_f64((uint64_t)" + literal(d) + ");";
            }
            return dst + " = " + literal(d) + ";";
        }
        if (o.equals("array-length")) {
            return dst + " = env->GetArrayLength((jarray)" + b + ");";
        }
        if (o.equals("new-instance")) {
            return dst + " = env->AllocObject(env->FindClass(\""
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
            return "pendingException = (jthrowable)" + a + "; env->Throw(pendingException);";
        }
        if (o.equals("monitor-enter")) {
            return "env->MonitorEnter((jobject)" + a + ");" + checkException(block, ir);
        }
        if (o.equals("monitor-exit")) {
            return "env->MonitorExit((jobject)" + a + ");" + checkException(block, ir);
        }
        if (o.equals("check-cast")) {
            return "if(" + a + " && !env->IsInstanceOf((jobject)" + a + ", env->FindClass(\""
                    + Types.descToClass(refType(d))
                    + "\"))) { env->ThrowNew(env->FindClass(\"java/lang/ClassCastException\"), \"check-cast\"); goto EX_UnwindBlock; }";
        }
        if (o.equals("instance-of")) {
            return dst + " = " + assignCast(dst) + "(" + a
                    + " && env->IsInstanceOf((jobject)" + a + ", env->FindClass(\""
                    + Types.descToClass(refType(d)) + "\")) ? 1 : 0);";
        }
        if (o.startsWith("aget")) {
            return arrayGet(d, dst, b, c) + checkException(block, ir);
        }
        if (o.startsWith("aput")) {
            return arrayPut(d, a, b, c) + checkException(block, ir);
        }
        if (o.equals("fill-array-data")) {
            return "/* fill-array-data payload is lowered when payload metadata is available */";
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
        if (o.startsWith("invoke-")) {
            return invoke(d, ir) + checkException(block, ir);
        }
        if (o.startsWith("return")) {
            return "/* return terminator */";
        }
        if (o.startsWith("neg-")) {
            return dst + " = -" + b + ";";
        }
        if (o.startsWith("not-")) {
            return dst + " = ~" + b + ";";
        }
        String cast = castOp(o, b);
        if (cast != null) {
            return dst + " = " + cast + ";";
        }
        String bin = binOp(o);
        if (bin != null) {
            return binaryLower(o, bin, a, b, c, dst, d);
        }
        if (o.startsWith("cmp")) {
            return dst + " = (" + b + " > " + c + " ? 1 : (" + b + " < " + c + " ? -1 : 0));";
        }
        return "/* UNSUPPORTED: " + o + " */";
    }

    /** Lowers a binary arithmetic operation, honoring literal and /2addr forms. */
    private String binaryLower(String o, String bin, String a, String b, String c, String dst, DexInstruction d) {
        String rhs;
        if (o.contains("lit")) {
            long lit = d.literal() == null ? 0 : d.literal();
            rhs = o.startsWith("rsub") ? "(" + lit + " - " + b + ")" : "(" + b + " " + bin + " " + lit + ")";
        } else if (o.contains("2addr")) {
            rhs = "(" + a + " " + bin + " " + b + ")";
        } else {
            rhs = "(" + b + " " + bin + " " + c + ")";
        }
        if (bin.equals("/") && o.contains("int")) {
            rhs = "nt_div_i(env," + b + "," + c + ")";
        }
        if (bin.equals("%") && o.contains("int")) {
            rhs = "nt_rem_i(env," + b + "," + c + ")";
        }
        if (bin.equals("/") && o.contains("long")) {
            rhs = "nt_div_l(env," + b + "," + c + ")";
        }
        if (bin.equals("%") && o.contains("long")) {
            rhs = "nt_rem_l(env," + b + "," + c + ")";
        }
        if (bin.equals("%") && o.contains("float")) {
            rhs = "fmodf(" + b + "," + c + ")";
        }
        if (bin.equals("%") && o.contains("double")) {
            rhs = "fmod(" + b + "," + c + ")";
        }
        if (o.startsWith("ushr")) {
            rhs = "((uint64_t)" + b + " >> (" + c + " & " + (o.contains("long") ? "63" : "31") + "))";
        }
        if (o.startsWith("shl") || o.startsWith("shr")) {
            rhs = "(" + b + " " + bin + " (" + c + " & " + (o.contains("long") ? "63" : "31") + "))";
        }
        return dst + " = " + rhs + ";";
    }

    /** Emits the pending-exception check routed to the block's landing pad. */
    private String checkException(IrBasicBlock block, IrMethod ir) {
        LandingPad lp = ir.graph.nodeToLandingPad.get(block);
        return lp == null ? ""
                : " if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto "
                        + lp.label() + "; }";
    }

    /** Resolves the emitted variable name for a register. */
    private String value(int reg, DexInstruction d, IrMethod ir) {
        for (Value v : d.getOperands()) {
            if (v instanceof Variable && ((Variable) v).getRegister() == reg) {
                return var((Variable) v, ir);
            }
        }
        return "v0";
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

    /** Resolves the referenced type of a typed instruction. */
    private String refType(DexInstruction d) {
        if (d.reference() instanceof TypeReference) {
            return ((TypeReference) d.reference()).getType();
        }
        return "Ljava/lang/Object;";
    }

    /** Emits a filled-new-array allocation and its element stores. */
    private String filledArray(String dst, int[] regs, String t, DexInstruction d, IrMethod ir) {
        StringBuilder x = new StringBuilder();
        x.append(newArray(dst, Integer.toString(regs.length), t));
        String e = t == null ? "Ljava/lang/Object;" : t.substring(1);
        for (int i = 0; i < regs.length; i++) {
            String v = value(regs[i], d, ir);
            if (e.startsWith("L") || e.startsWith("[")) {
                x.append(" env->SetObjectArrayElement((jobjectArray)").append(dst).append(", ").append(i)
                 .append(", (jobject)").append(v).append(");");
            } else {
                x.append(" /* fill primitive */ ");
            }
        }
        return x.toString();
    }

    /** Emits a typed array allocation. */
    private String newArray(String dst, String size, String t) {
        if (t == null || !t.startsWith("[")) {
            return dst + " = NULL;";
        }
        String e = t.substring(1);
        String sz = "(jsize)(intptr_t)" + size;
        if ("Z".equals(e)) {
            return dst + " = env->NewBooleanArray(" + sz + ");";
        }
        if ("B".equals(e)) {
            return dst + " = env->NewByteArray(" + sz + ");";
        }
        if ("C".equals(e)) {
            return dst + " = env->NewCharArray(" + sz + ");";
        }
        if ("S".equals(e)) {
            return dst + " = env->NewShortArray(" + sz + ");";
        }
        if ("I".equals(e)) {
            return dst + " = env->NewIntArray(" + sz + ");";
        }
        if ("J".equals(e)) {
            return dst + " = env->NewLongArray(" + sz + ");";
        }
        if ("F".equals(e)) {
            return dst + " = env->NewFloatArray(" + sz + ");";
        }
        if ("D".equals(e)) {
            return dst + " = env->NewDoubleArray(" + sz + ");";
        }
        return dst + " = env->NewObjectArray(" + sz + ", env->FindClass(\""
                + Types.descToClass(e) + "\"), NULL);";
    }

    /** Maps an opcode to its C cast, or {@code null} when not a conversion. */
    private String castOp(String o, String b) {
        if (o.equals("int-to-long")) return "(jlong)" + b;
        if (o.equals("int-to-float")) return "(jfloat)" + b;
        if (o.equals("int-to-double")) return "(jdouble)" + b;
        if (o.equals("long-to-int")) return "(jint)" + b;
        if (o.equals("long-to-float")) return "(jfloat)" + b;
        if (o.equals("long-to-double")) return "(jdouble)" + b;
        if (o.equals("float-to-int")) return "(jint)" + b;
        if (o.equals("float-to-long")) return "(jlong)" + b;
        if (o.equals("float-to-double")) return "(jdouble)" + b;
        if (o.equals("double-to-int")) return "(jint)" + b;
        if (o.equals("double-to-long")) return "(jlong)" + b;
        if (o.equals("double-to-float")) return "(jfloat)" + b;
        if (o.equals("int-to-byte")) return "(jbyte)" + b;
        if (o.equals("int-to-char")) return "(jchar)" + b;
        if (o.equals("int-to-short")) return "(jshort)" + b;
        return null;
    }

    /** Maps an opcode to its C++ operator, or {@code null} when not binary. */
    private String binOp(String o) {
        if (o.contains("-add-")) return "+";
        if (o.contains("-sub-") || o.startsWith("rsub")) return "-";
        if (o.contains("-mul-")) return "*";
        if (o.contains("-div-")) return "/";
        if (o.contains("-rem-")) return "%";
        if (o.contains("-and-")) return "&";
        if (o.contains("-or-")) return "|";
        if (o.contains("-xor-")) return "^";
        if (o.contains("-shl-")) return "<<";
        if (o.contains("-shr-")) return ">>";
        if (o.contains("-ushr-")) return ">>";
        return null;
    }

    /** Emits a primitive or object array read. */
    private String arrayGet(DexInstruction d, String dst, String arr, String idx) {
        String s = arrayKind(d);
        if ("Object".equals(s)) {
            return dst + " = " + assignCast(dst)
                    + "env->GetObjectArrayElement((jobjectArray)" + arr + ", (jsize)(intptr_t)" + idx + ");";
        }
        return "env->Get" + s + "ArrayRegion((" + arrayType(s) + ")" + arr + ", (jsize)(intptr_t)" + idx
                + ", 1, (" + elemType(s) + "*)&" + dst + ");";
    }

    /** Emits a primitive or object array write. */
    private String arrayPut(DexInstruction d, String val, String arr, String idx) {
        String s = arrayKind(d);
        if ("Object".equals(s)) {
            return "env->SetObjectArrayElement((jobjectArray)" + arr + ", (jsize)" + idx
                    + ", (jobject)(intptr_t)" + val + ");";
        }
        return "env->Set" + s + "ArrayRegion((" + arrayType(s) + ")" + arr + ", (jsize)(intptr_t)" + idx
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
            return "/* bad field */";
        }
        FieldReference f = (FieldReference) d.reference();
        String cls = Types.descToClass(f.getDefiningClass());
        String name = Types.escape(f.getName());
        String sig = Types.escape(f.getType());
        String id = "env->Get" + (stat ? "Static" : "") + "FieldID(env->FindClass(\"" + cls + "\"), \""
                + name + "\", \"" + sig + "\")";
        String suf = Types.jniSuffix(f.getType());
        return dst + " = " + assignCast(dst)
                + "env->Get" + (stat ? "Static" : "") + suf + "Field("
                + (stat ? "env->FindClass(\"" + cls + "\")" : "(jobject)(intptr_t)" + obj)
                + ", " + id + ");";
    }

    /** Emits an instance or static field write. */
    private String fieldPut(DexInstruction d, String val, String obj, boolean stat) {
        if (!(d.reference() instanceof FieldReference)) {
            return "/* bad field */";
        }
        FieldReference f = (FieldReference) d.reference();
        String cls = Types.descToClass(f.getDefiningClass());
        String name = Types.escape(f.getName());
        String sig = Types.escape(f.getType());
        String id = "env->Get" + (stat ? "Static" : "") + "FieldID(env->FindClass(\"" + cls + "\"), \""
                + name + "\", \"" + sig + "\")";
        return "env->Set" + (stat ? "Static" : "") + Types.jniSuffix(f.getType()) + "Field("
                + (stat ? "env->FindClass(\"" + cls + "\")" : "(jobject)(intptr_t)" + obj)
                + ", " + id + ", "
                + (Types.ref(f.getType()) ? "(jobject)(intptr_t)" : "") + val + ");";
    }

    /** Emits a method invocation, including range and static forms. */
    private String invoke(DexInstruction d, IrMethod ir) {
        if (!(d.reference() instanceof MethodReference)) {
            return "/* unsupported invoke ref */";
        }
        MethodReference m = (MethodReference) d.reference();
        String cls = Types.descToClass(m.getDefiningClass());
        String sig = Types.escape(descriptor(m));
        String name = Types.escape(m.getName());
        boolean stat = d.opcode().contains("static");
        String call = stat ? "CallStatic" : "Call";
        String suf = Types.jniSuffix(m.getReturnType());
        String obj = stat ? "env->FindClass(\"" + cls + "\")"
                : "(jobject)" + (d.registers().length > 0 ? value(d.registers()[0], d, ir) : "thiz");
        StringBuilder args = new StringBuilder();
        int start = stat ? 0 : 1;
        for (int i = start; i < d.registers().length; i++) {
            if (args.length() > 0) {
                args.append(", ");
            }
            args.append(value(d.registers()[i], d, ir));
        }
        String expr = "env->Get" + (stat ? "Static" : "") + "MethodID(env->FindClass(\"" + cls + "\"), \""
                + name + "\", \"" + sig + "\")";
        String result = d.getValue() instanceof Variable ? var((Variable) d.getValue(), ir) : null;
        String callExpr = "env->" + call + suf + "Method(" + obj + ", " + expr
                + (args.length() > 0 ? ", " + args : "") + ")";
        if (result == null) {
            return "env->" + call + suf + "Method(" + obj + ", " + expr
                    + (args.length() > 0 ? ", " + args : "") + ");";
        }
        return result + " = " + assignCast(result) + callExpr + ";";
    }

    /** C-style cast to the declared C++ type of an emitted variable. */
    private String assignCast(String dst) {
        String dct = slotTypes.get(dst);
        return dct != null ? "(" + dct + ")(intptr_t)" : "(jobject)(intptr_t)";
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
                b.append("  return;\n");
            } else {
                b.append("  return ").append(rv.isEmpty() ? "0" : "(" + Types.c(ir.returnType) + ")(intptr_t)" + rv).append(";\n");
            }
            return;
        }
        if (o.equals("throw")) {
            b.append("  goto EX_UnwindBlock;\n");
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
             .append(d.getOperands().isEmpty() ? "0" : valueVar(d.getOperands().get(0), ir)).append(") {\n");
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
