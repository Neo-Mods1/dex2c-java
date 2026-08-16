package bin.nt.dex2c.build;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import com.android.tools.smali.dexlib2.iface.Method;

import bin.nt.dex2c.Main;
import bin.nt.dex2c.util.Types;
import bin.nt.dex2c.writer.CppWriter;

/**
 * Generates a self-contained {@code ndk-build} project from the compiled
 * method sources.
 *
 * <p>Layout mirrors the reference dex2c {@code project/jni} tree:
 * {@code jni/Android.mk}, {@code jni/Application.mk} and the compiled sources
 * under {@code jni/nc}. With {@code --dynamic-register} a
 * {@code DynamicRegister.cpp} table registers every compiled method through
 * {@code JNI_OnLoad}; otherwise a no-op stub is emitted and the exports are
 * resolved by name.</p>
 */
final class NdkProject {

    private static final int ACC_STATIC = 0x8;

    private NdkProject() {
    }

    /**
     * Writes the complete JNI project.
     *
     * @param project     the project root (contains {@code jni/})
     * @param libName     the {@code LOCAL_MODULE} name
     * @param minSdk      minimum Android API level
     * @param abis        target ABIs
     * @param dynamic     emit RegisterNatives registration
     * @param compiled    successfully compiled methods
     * @param dex2cSource the combined C++ for all methods
     * @throws IOException on I/O failure
     */
    static void write(Path project, String libName, int minSdk, List<String> abis,
            boolean dynamic, List<Method> compiled, String dex2cSource) throws IOException {
        Path nc = project.resolve("jni").resolve("nc");
        Files.createDirectories(nc);

        Files.write(project.resolve("jni").resolve("Android.mk"),
                androidMk(libName).getBytes(StandardCharsets.UTF_8));
        Files.write(project.resolve("jni").resolve("Application.mk"),
                applicationMk(abis, minSdk).getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("NT.h"), ntH().getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("NT.cpp"), ntCpp().getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("DynamicRegister.cpp"),
                dynamicRegister(dynamic, compiled).getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("dex2c.cpp"), dex2cSource.getBytes(StandardCharsets.UTF_8));
    }

    private static String androidMk(String libName) {
        return "LOCAL_PATH := $(call my-dir)\n"
                + "\n"
                + "include $(CLEAR_VARS)\n"
                + "LOCAL_MODULE    := " + libName + "\n"
                + "LOCAL_CFLAGS    := -O2\n"
                + "LOCAL_CPPFLAGS  := -fno-exceptions -fno-rtti\n"
                + "LOCAL_LDLIBS    := -llog\n"
                + "LOCAL_SRC_FILES := $(call all-cpp-files-under, nc)\n"
                + "include $(BUILD_SHARED_LIBRARY)\n";
    }

    private static String applicationMk(List<String> abis, int minSdk) {
        String abiList = abis == null || abis.isEmpty() ? "all" : String.join(" ", abis);
        return "APP_ABI := " + abiList + "\n"
                + "APP_PLATFORM := android-" + minSdk + "\n"
                + "APP_STL := c++_static\n"
                + "APP_OPTIM := release\n";
    }

    private static String ntH() {
        return "#ifndef NT_H_\n"
                + "#define NT_H_\n"
                + "#include <jni.h>\n"
                + "\n"
                + "const char *dynamic_register_compile_methods(JNIEnv *env);\n"
                + "\n"
                + "#endif\n";
    }

    private static String ntCpp() {
        return "#include \"NT.h\"\n"
                + "\n"
                + "JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {\n"
                + "    JNIEnv *env = NULL;\n"
                + "    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {\n"
                + "        return JNI_ERR;\n"
                + "    }\n"
                + "    const char *err = dynamic_register_compile_methods(env);\n"
                + "    if (err != NULL) {\n"
                + "        return JNI_ERR;\n"
                + "    }\n"
                + "    return JNI_VERSION_1_6;\n"
                + "}\n";
    }

    private static String dynamicRegister(boolean dynamic, List<Method> compiled) {
        if (!dynamic || compiled == null || compiled.isEmpty()) {
            return "#include \"NT.h\"\n"
                    + "\n"
                    + "const char *dynamic_register_compile_methods(JNIEnv *env) { return NULL; }\n";
        }
        Map<String, List<Method>> byClass = new TreeMap<>();
        for (Method m : compiled) {
            byClass.computeIfAbsent(Types.descToClass(m.getDefiningClass()), k -> new ArrayList<>()).add(m);
        }
        StringBuilder b = new StringBuilder("#include \"NT.h\"\n\n");
        for (Map.Entry<String, List<Method>> e : byClass.entrySet()) {
            for (Method m : e.getValue()) {
                b.append("extern ").append(Types.c(m.getReturnType()))
                 .append(" ").append(CppWriter.JniNames.name(m))
                 .append(signature(m)).append(";\n");
            }
        }
        b.append("\nconst char *dynamic_register_compile_methods(JNIEnv *env) {\n");
        b.append("    jclass clazz;\n");
        int idx = 0;
        for (Map.Entry<String, List<Method>> e : byClass.entrySet()) {
            b.append("    clazz = env->FindClass(\"").append(e.getKey()).append("\");\n");
            b.append("    if (clazz == NULL) return \"Class not found: ").append(e.getKey()).append("\";\n");
            b.append("    const JNINativeMethod export_method_").append(idx).append("[] = {\n");
            for (Method m : e.getValue()) {
                b.append("        {\"").append(m.getName()).append("\", \"")
                 .append(Main.descriptor(m)).append("\", (void *)")
                 .append(CppWriter.JniNames.name(m)).append("},\n");
            }
            b.append("    };\n");
            b.append("    env->RegisterNatives(clazz, export_method_").append(idx)
             .append(", ").append(e.getValue().size()).append(");\n");
            b.append("    env->DeleteLocalRef(clazz);\n\n");
            idx++;
        }
        b.append("    return NULL;\n}\n");
        return b.toString();
    }

    /** The parameter portion of a method's JNI function signature. */
    private static String signature(Method m) {
        StringBuilder s = new StringBuilder("(JNIEnv* env, ");
        s.append((m.getAccessFlags() & ACC_STATIC) != 0 ? "jclass clazz" : "jobject thiz");
        int pi = 0;
        for (CharSequence p : m.getParameterTypes()) {
            s.append(", ").append(Types.c(p.toString())).append(" p").append(pi++);
        }
        return s.append(')').toString();
    }
}
