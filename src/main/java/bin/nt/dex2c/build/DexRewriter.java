package bin.nt.dex2c.build;

import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Set;

import com.android.tools.smali.dexlib2.AccessFlags;
import com.android.tools.smali.dexlib2.DexFileFactory;
import com.android.tools.smali.dexlib2.Opcode;
import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;
import com.android.tools.smali.dexlib2.iface.Annotation;
import com.android.tools.smali.dexlib2.iface.ClassDef;
import com.android.tools.smali.dexlib2.iface.DexFile;
import com.android.tools.smali.dexlib2.iface.Field;
import com.android.tools.smali.dexlib2.iface.Method;
import com.android.tools.smali.dexlib2.iface.MethodImplementation;
import com.android.tools.smali.dexlib2.iface.reference.MethodReference;
import com.android.tools.smali.dexlib2.immutable.ImmutableClassDef;
import com.android.tools.smali.dexlib2.immutable.ImmutableDexFile;
import com.android.tools.smali.dexlib2.immutable.ImmutableMethod;
import com.android.tools.smali.dexlib2.immutable.ImmutableMethodImplementation;
import com.android.tools.smali.dexlib2.immutable.instruction.ImmutableInstruction10x;
import com.android.tools.smali.dexlib2.immutable.instruction.ImmutableInstruction21c;
import com.android.tools.smali.dexlib2.immutable.instruction.ImmutableInstruction35c;
import com.android.tools.smali.dexlib2.immutable.reference.ImmutableMethodReference;
import com.android.tools.smali.dexlib2.immutable.reference.ImmutableStringReference;
import com.android.tools.smali.dexlib2.iface.instruction.Instruction;

import bin.nt.dex2c.Main;

/**
 * Rewrites a DEX in memory: every compiled method is declared {@code native}
 * (body removed, annotations kept), and a {@code System.loadLibrary} call is
 * prepended to the Application class {@code <clinit>} (a new {@code <clinit>}
 * is created when the class has none).
 *
 * <p>Replaces the fragile baksmali/smali text round-trip used by the
 * reference: real-world dex can carry duplicate annotations that the smali
 * assembler rejects, whereas dexlib2 preserves them as-is and the immutable
 * conversion deduplicates without error.</p>
 */
final class DexRewriter {

    private DexRewriter() {
    }

    /** Reference for {@code System.loadLibrary(String)}. */
    private static final MethodReference LOAD_LIBRARY = new ImmutableMethodReference(
            "Ljava/lang/System;", "loadLibrary",
            Collections.singletonList("Ljava/lang/String;"), "V");

    /** Reference for {@code Application.onCreate()}. */
    private static final MethodReference ON_CREATE = new ImmutableMethodReference(
            "Landroid/app/Application;", "onCreate", Collections.emptyList(), "V");

    /** Reference for {@code Application.<init>()}. */
    private static final MethodReference APP_CTOR = new ImmutableMethodReference(
            "Landroid/app/Application;", "<init>", Collections.emptyList(), "V");

    /**
     * Writes a rewritten copy of {@code dex} to {@code dexOut} where every
     * method in {@code compiled} is native, the Application class (when
     * given) loads the native library from its {@code <clinit>}, and the
     * optional loader class (when given) is added as a new class.
     *
     * @param dex       the source DEX
     * @param dexOut    the rewritten DEX path
     * @param compiled  (class, name, descriptor) triples compiled to native
     * @param appClass  the Application class ({@code L...;}) or {@code null}
     * @param libName   the {@code System.loadLibrary} argument
     * @param extra     an extra class to add (the generated loader), or {@code null}
     * @throws IOException on write failure
     */
    static void rewrite(DexBackedDexFile dex, Path dexOut, Set<String> compiled,
            String appClass, String libName, ClassDef extra) throws IOException {
        List<ClassDef> classes = new ArrayList<>();
        for (ClassDef c : dex.getClasses()) {
            classes.add(rewriteClass(c, compiled, appClass, libName));
        }
        if (extra != null) {
            classes.add(extra);
        }
        DexFile nde = new ImmutableDexFile(dex.getOpcodes(), classes);
        DexFileFactory.writeDexFile(dexOut.toString(), nde);
    }

    /** Rewrites one class: mark compiled methods native, inject the app clinit. */
    private static ClassDef rewriteClass(ClassDef c, Set<String> compiled, String appClass,
            String libName) {
        boolean isApp = appClass != null && appClass.equals(c.getType());
        List<Method> direct = new ArrayList<>();
        boolean appClinit = false;
        for (Method m : c.getDirectMethods()) {
            if (isApp && "<clinit>".equals(m.getName())) {
                direct.add(clinit(m, libName));
                appClinit = true;
            } else if (marked(c, m, compiled)) {
                direct.add(asNative(m));
            } else {
                direct.add(ImmutableMethod.of(m));
            }
        }
        List<Method> virtual = new ArrayList<>();
        for (Method m : c.getVirtualMethods()) {
            if (marked(c, m, compiled)) {
                virtual.add(asNative(m));
            } else {
                virtual.add(ImmutableMethod.of(m));
            }
        }
        if (isApp && !appClinit) {
            direct.add(freshClinit(c, libName));
        }
        return new ImmutableClassDef(c.getType(), c.getAccessFlags(),
                c.getSuperclass(), c.getInterfaces(), c.getSourceFile(),
                c.getAnnotations(), c.getStaticFields(), c.getInstanceFields(),
                direct, virtual);
    }

    /**
     * A generated {@code Application} subclass whose {@code onCreate} loads
     * the native library, used when the APK's manifest declares none. It is
     * placed in the app's own package so it looks like one of the user's
     * classes.
     *
     * @param type    the class type ({@code L...;})
     * @param libName the {@code System.loadLibrary} argument
     * @return the generated class
     */
    static ClassDef loaderClass(String type, String libName) {
        List<Instruction> ctor = new ArrayList<>();
        ctor.add(new ImmutableInstruction35c(Opcode.INVOKE_DIRECT, 1, 0, 0, 0, 0, 0, APP_CTOR));
        ctor.add(new ImmutableInstruction10x(Opcode.RETURN_VOID));
        List<Instruction> onCreate = new ArrayList<>();
        onCreate.add(new ImmutableInstruction35c(Opcode.INVOKE_SUPER, 1, 0, 0, 0, 0, 0, ON_CREATE));
        onCreate.add(new ImmutableInstruction21c(Opcode.CONST_STRING, 0,
                new ImmutableStringReference(libName)));
        onCreate.add(new ImmutableInstruction35c(Opcode.INVOKE_STATIC, 1, 0, 0, 0, 0, 0, LOAD_LIBRARY));
        onCreate.add(new ImmutableInstruction10x(Opcode.RETURN_VOID));
        List<Method> direct = new ArrayList<>();
        direct.add(new ImmutableMethod(type, "<init>",
                Collections.emptyList(), "V", AccessFlags.PUBLIC.getValue() | AccessFlags.CONSTRUCTOR.getValue(),
                Collections.<Annotation>emptySet(), Collections.emptySet(),
                new ImmutableMethodImplementation(1, ctor,
                        Collections.emptyList(), Collections.emptyList())));
        direct.add(new ImmutableMethod(type, "onCreate",
                Collections.emptyList(), "V", AccessFlags.PUBLIC.getValue(),
                Collections.<Annotation>emptySet(), Collections.emptySet(),
                new ImmutableMethodImplementation(1, onCreate,
                        Collections.emptyList(), Collections.emptyList())));
        return new ImmutableClassDef(type,
                AccessFlags.PUBLIC.getValue() | AccessFlags.FINAL.getValue(),
                "Landroid/app/Application;", Collections.<String>emptyList(), null,
                Collections.<Annotation>emptySet(),
                Collections.<Field>emptySet(), Collections.<Field>emptySet(),
                direct, Collections.<Method>emptyList());
    }

    /**
     * Whether the method was compiled and must become native. Static and
     * instance constructors stay in the DEX: the Application {@code <clinit>}
     * must keep running the injected library load.
     */
    private static boolean marked(ClassDef c, Method m, Set<String> compiled) {
        String name = m.getName();
        return !"<clinit>".equals(name) && !"<init>".equals(name)
                && compiled.contains(c.getType() + name + Main.descriptor(m));
    }

    /** The same method with {@code native} access and no implementation. */
    private static ImmutableMethod asNative(Method m) {
        return new ImmutableMethod(m.getDefiningClass(), m.getName(), m.getParameters(),
                m.getReturnType(), m.getAccessFlags() | AccessFlags.NATIVE.getValue(),
                m.getAnnotations(), m.getHiddenApiRestrictions(), null);
    }

    /** Existing {@code <clinit>} with the library load prepended. */
    private static ImmutableMethod clinit(Method clinit, String libName) {
        List<Instruction> ins = new ArrayList<>();
        ins.add(new ImmutableInstruction21c(Opcode.CONST_STRING, 0,
                new ImmutableStringReference(libName)));
        ins.add(new ImmutableInstruction35c(Opcode.INVOKE_STATIC, 1, 0, 0, 0, 0, 0, LOAD_LIBRARY));
        int regs = 1;
        MethodImplementation impl = clinit.getImplementation();
        if (impl != null) {
            regs = Math.max(1, impl.getRegisterCount());
            for (Instruction i : impl.getInstructions()) {
                ins.add(i);
            }
        } else {
            ins.add(new ImmutableInstruction10x(Opcode.RETURN_VOID));
        }
        return new ImmutableMethod(clinit.getDefiningClass(), clinit.getName(),
                clinit.getParameters(), clinit.getReturnType(), clinit.getAccessFlags(),
                clinit.getAnnotations(), clinit.getHiddenApiRestrictions(),
                new ImmutableMethodImplementation(regs, ins,
                        Collections.emptyList(), Collections.emptyList()));
    }

    /** Fresh {@code <clinit>} that loads the library and returns. */
    private static ImmutableMethod freshClinit(ClassDef c, String libName) {
        List<Instruction> ins = new ArrayList<>();
        ins.add(new ImmutableInstruction21c(Opcode.CONST_STRING, 0,
                new ImmutableStringReference(libName)));
        ins.add(new ImmutableInstruction35c(Opcode.INVOKE_STATIC, 1, 0, 0, 0, 0, 0, LOAD_LIBRARY));
        ins.add(new ImmutableInstruction10x(Opcode.RETURN_VOID));
        return new ImmutableMethod(c.getType(), "<clinit>",
                Collections.emptyList(), "V", AccessFlags.CONSTRUCTOR.getValue() | AccessFlags.STATIC.getValue(),
                Collections.<Annotation>emptySet(), Collections.emptySet(),
                new ImmutableMethodImplementation(1, ins,
                        Collections.emptyList(), Collections.emptyList()));
    }
}