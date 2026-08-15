package bin.nt.dex2c.basic_blocks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.MethodImplementation;
import com.android.tools.smali.dexlib2.iface.instruction.Instruction;
import com.android.tools.smali.dexlib2.iface.instruction.OffsetInstruction;
import com.android.tools.smali.dexlib2.iface.instruction.ReferenceInstruction;
import com.android.tools.smali.dexlib2.iface.reference.Reference;

import bin.nt.dex2c.graph.Graph;
import bin.nt.dex2c.instruction.DexInstruction;

/**
 * Materializes the DEX instruction stream into per-block IR instruction
 * lists.
 *
 * <p>Each DEX instruction is adapted to a {@link DexInstruction} carrying its
 * opcode, registers, literal, reference, branch target and switch payload.
 * Register ranges and switch elements are read reflectively so that the
 * adapter does not depend on every dexlib2 accessor interface.</p>
 */
public final class BlockLifter {

    private BlockLifter() {
    }

    /**
     * Fills every block of {@code g} with its DEX instructions.
     *
     * @param method the source method
     * @param g      the method's control-flow graph
     */
    public static void lift(Method method, Graph g) {
        MethodImplementation impl = method.getImplementation();
        if (impl == null) {
            return;
        }
        List<Instruction> ins = new ArrayList<>();
        for (Instruction q : impl.getInstructions()) {
            ins.add(q);
        }
        Map<Integer, Instruction> at = new HashMap<>();
        int p = 0;
        for (Instruction i : ins) {
            at.put(p, i);
            p += i.getCodeUnits();
        }
        int codeSize = p;
        for (IrBasicBlock b : g.nodes) {
            if (b.start < 0) {
                continue;
            }
            int end = codeSize;
            for (IrBasicBlock x : g.nodes) {
                if (x.start > b.start) {
                    end = Math.min(end, x.start);
                }
            }
            int pc = b.start;
            while (pc < end) {
                Instruction d = at.get(pc);
                if (d == null) {
                    break;
                }
                b.addIns(adapt(d, pc));
                pc += d.getCodeUnits();
            }
            b.filled = true;
        }
    }

    /** Converts one DEX instruction into a {@link DexInstruction}. */
    private static DexInstruction adapt(Instruction d, int pc) {
        String op = d.getOpcode().name().toLowerCase(Locale.ROOT).replace('_', '-');
        int[] regs = regs(d);
        Long lit = literal(d);
        Reference ref = d instanceof ReferenceInstruction ? ((ReferenceInstruction) d).getReference() : null;
        int target = d instanceof OffsetInstruction ? pc + ((OffsetInstruction) d).getCodeOffset() : -1;
        Map<Integer, Integer> sw = new LinkedHashMap<>();
        try {
            java.lang.reflect.Method m = d.getClass().getMethod("getSwitchElements");
            Object x = m.invoke(d);
            if (x instanceof Iterable<?>) {
                for (Object e : (Iterable<?>) x) {
                    int k = ((Number) e.getClass().getMethod("getKey").invoke(e)).intValue();
                    int t = ((Number) e.getClass().getMethod("getOffset").invoke(e)).intValue() + pc;
                    sw.put(k, t);
                }
            }
        } catch (Exception ignored) {
        }
        DexInstruction ir = new DexInstruction(op, regs, lit, ref, target, sw);
        ir.setOffset(pc);
        ir.setNextOffset(pc + d.getCodeUnits());
        ir.setDexInstruction(d);
        return ir;
    }

    /**
     * Extracts the register operands of a DEX instruction, preferring the
     * range accessors ({@code getRegisterCount}/{@code getStartRegister})
     * and falling back to individual {@code getRegisterA..G} accessors.
     *
     * @param d the DEX instruction
     * @return the register indices
     */
    static int[] regs(Instruction d) {
        try {
            java.lang.reflect.Method c = d.getClass().getMethod("getRegisterCount");
            int n = ((Number) c.invoke(d)).intValue();
            java.lang.reflect.Method s = d.getClass().getMethod("getStartRegister");
            int start = ((Number) s.invoke(d)).intValue();
            int[] r = new int[n];
            for (int i = 0; i < n; i++) {
                r[i] = start + i;
            }
            return r;
        } catch (Exception ignored) {
        }
        int[] tmp = new int[7];
        int n = 0;
        for (char x = 'A'; x <= 'G'; x++) {
            try {
                java.lang.reflect.Method m = d.getClass().getMethod("getRegister" + x);
                tmp[n++] = ((Number) m.invoke(d)).intValue();
            } catch (Exception ignored) {
            }
        }
        return Arrays.copyOf(tmp, n);
    }

    /**
     * Extracts the literal of a DEX instruction, preferring the wide accessor.
     *
     * @param d the DEX instruction
     * @return the literal, or {@code null} when the instruction has none
     */
    static Long literal(Instruction d) {
        try {
            java.lang.reflect.Method m = d.getClass().getMethod("getWideLiteral");
            return ((Number) m.invoke(d)).longValue();
        } catch (Exception ignored) {
        }
        try {
            java.lang.reflect.Method m = d.getClass().getMethod("getNarrowLiteral");
            return ((Number) m.invoke(d)).longValue();
        } catch (Exception ignored) {
        }
        return null;
    }
}
