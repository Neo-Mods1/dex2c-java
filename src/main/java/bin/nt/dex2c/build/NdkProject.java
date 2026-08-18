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
    static void write(Path project, String libName, int minSdk, int nativeApi, List<String> abis,
            boolean dynamic, List<Method> compiled, String dex2cSource) throws IOException {
        Path nc = project.resolve("jni").resolve("nc");
        Files.createDirectories(nc);

        Files.write(project.resolve("jni").resolve("Android.mk"),
                androidMk(libName, dynamic).getBytes(StandardCharsets.UTF_8));
        Files.write(project.resolve("jni").resolve("Application.mk"),
                applicationMk(abis, nativeApi).getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("NT.h"), ntH().getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("NT.cpp"), ntCpp().getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("dex2c_runtime.h"), runtimeH().getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("dex2c_runtime.cpp"), runtimeCpp().getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("dex2c.hpp"), dex2cHpp(compiled, dynamic).getBytes(StandardCharsets.UTF_8));
        Files.write(nc.resolve("DynamicRegister.cpp"),
                dynamicRegister(dynamic, compiled).getBytes(StandardCharsets.UTF_8));
        writeMethodSources(nc.resolve("methods"), dex2cSource);
        Files.write(nc.resolve("dex2c.cpp"),
                "#include \"dex2c.hpp\"\n".getBytes(StandardCharsets.UTF_8));
    }

    /** Splits the monolithic compiler output into one translation unit per method. */
    private static void writeMethodSources(Path methods, String source) throws IOException {
        Files.createDirectories(methods);
        if (source == null || source.isEmpty()) {
            return;
        }
        int first = source.indexOf("/* L");
        if (first < 0) {
            return;
        }
        String body = source.substring(first);
        String[] chunks = body.split("(?=\\n/\\* L)");
        int index = 0;
        for (String chunk : chunks) {
            chunk = chunk.trim();
            if (chunk.isEmpty()) continue;
            int endComment = chunk.indexOf(" */");
            String label = endComment > 0 ? chunk.substring(3, endComment) : "method";
            String safe = label.replaceAll("[^A-Za-z0-9_$.-]", "_");
            if (safe.length() > 160) safe = safe.substring(0, 160);
            Path out = methods.resolve(String.format("%04d_%s.cpp", index++, safe));
            Files.writeString(out, "#include \"dex2c.hpp\"\n\n" + chunk + "\n", StandardCharsets.UTF_8);
        }
    }

    private static String androidMk(String libName, boolean dynamic) {
        return "LOCAL_PATH := $(call my-dir)\n"
                + "\n"
                + "include $(CLEAR_VARS)\n"
                + "LOCAL_MODULE    := " + libName + "\n"
                + "LOCAL_CFLAGS    := -O2 -fvisibility=hidden\n"
                + "LOCAL_CPPFLAGS  := -fno-exceptions -fno-rtti\n"
                + "LOCAL_LDLIBS    := -llog\n"
                + "LOCAL_SRC_FILES := nc/NT.cpp nc/dex2c_runtime.cpp nc/DynamicRegister.cpp $(wildcard nc/methods/*.cpp)\n"
                + "include $(BUILD_SHARED_LIBRARY)\n";
    }

    private static String applicationMk(List<String> abis, int nativeApi) {
        String abiList = abis == null || abis.isEmpty() ? "all" : String.join(" ", abis);
        return "APP_ABI := " + abiList + "\n"
                + "APP_PLATFORM := android-" + nativeApi + "\n"
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
        return "#include <jni.h>\n"
                + "\n"
                + "#include \"NT.h\"\n"
                + "\n"
                + "extern \"C\" {\n"
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
                + "}\n"
                + "\n"
                + "}\n";
    }

    private static String runtimeH() {
        return "#ifndef DEX2C_RUNTIME_H_\n"
                + "#define DEX2C_RUNTIME_H_\n"
                + "#include <jni.h>\n"
                + "#include <stdint.h>\n"
                + "#include <math.h>\n"
                + "jint nt_div_i(JNIEnv*, jint, jint);\n"
                + "jint nt_rem_i(JNIEnv*, jint, jint);\n"
                + "jlong nt_div_l(JNIEnv*, jlong, jlong);\n"
                + "jlong nt_rem_l(JNIEnv*, jlong, jlong);\n"
                + "jint nt_float_to_int(jfloat); jlong nt_float_to_long(jfloat);\n"
                + "jint nt_double_to_int(jdouble); jlong nt_double_to_long(jdouble);\n"
                + "jfloat nt_f32(uint32_t); jdouble nt_f64(uint64_t);\n"
                + "jclass nt_resolve_class(JNIEnv*, const char*);\n"
                + "jmethodID nt_resolve_method(JNIEnv*, jclass, const char*, const char*, const char*, bool);\n"
                + "jfieldID nt_resolve_field(JNIEnv*, jclass, const char*, const char*, const char*, bool);\n"
                + "jobject nt_new_local(JNIEnv*, jobject);\n"
                + "void nt_delete_local(JNIEnv*, jobject);\n"
                + "jobject nt_box(JNIEnv*, const char*, jvalue);\n"
                + "jobject nt_box_i(JNIEnv*, jint); jobject nt_box_j(JNIEnv*, jlong); jobject nt_box_f(JNIEnv*, jfloat); jobject nt_box_d(JNIEnv*, jdouble); jobject nt_box_z(JNIEnv*, jboolean);\n"
                + "jobject nt_new_lookup(JNIEnv*, jclass);\n"
                + "jobject nt_make_method_type(JNIEnv*, const char*);\n"
                + "jobject nt_make_method_handle(JNIEnv*, jobject, jclass, const char*, const char*, const char*, const char*, jclass);\n"
                + "jobject nt_invoke_custom(JNIEnv*, jclass, const char*, const char*, const char*, const char*, const char*, jobjectArray, jobjectArray);\n"
                + "jvalue nt_unbox(JNIEnv*, jobject, const char*);\n"
                + "#endif\n";
    }

    private static String runtimeCpp() {
        return "#include \"dex2c_runtime.h\"\n"
                + "#include <limits.h>\n#include <string.h>\n#include <stdint.h>\n#include <mutex>\n#include <unordered_map>\n#include <string>\n\n"
                + "static void nt_arith(JNIEnv* e,const char* m){if(!e)return; jclass c=e->FindClass(\"java/lang/ArithmeticException\"); if(c){e->ThrowNew(c,m);e->DeleteLocalRef(c);}}\n"
                + "jint nt_div_i(JNIEnv* e,jint a,jint b){if(!b){nt_arith(e,\"/ by zero\");return 0;}if(a==INT32_MIN&&b==-1)return INT32_MIN;return a/b;}\n"
                + "jint nt_rem_i(JNIEnv* e,jint a,jint b){if(!b){nt_arith(e,\"% by zero\");return 0;}if(a==INT32_MIN&&b==-1)return 0;return a%b;}\n"
                + "jlong nt_div_l(JNIEnv* e,jlong a,jlong b){if(!b){nt_arith(e,\"/ by zero\");return 0;}if(a==INT64_MIN&&b==-1)return INT64_MIN;return a/b;}\n"
                + "jlong nt_rem_l(JNIEnv* e,jlong a,jlong b){if(!b){nt_arith(e,\"% by zero\");return 0;}if(a==INT64_MIN&&b==-1)return 0;return a%b;}\n"
                + "jint nt_float_to_int(jfloat x){if(isnan(x))return 0;if(x>=2147483647.0f)return INT32_MAX;if(x<=-2147483648.0f)return INT32_MIN;return(jint)x;}\n"
                + "jlong nt_float_to_long(jfloat x){if(isnan(x))return 0;if((double)x>=9223372036854775807.0)return INT64_MAX;if((double)x<=-9223372036854775808.0)return INT64_MIN;return(jlong)x;}\n"
                + "jint nt_double_to_int(jdouble x){if(isnan(x))return 0;if(x>=2147483647.0)return INT32_MAX;if(x<=-2147483648.0)return INT32_MIN;return(jint)x;}\n"
                + "jlong nt_double_to_long(jdouble x){if(isnan(x))return 0;if(x>=9223372036854775807.0)return INT64_MAX;if(x<=-9223372036854775808.0)return INT64_MIN;return(jlong)x;}\n"
                + "jfloat nt_f32(uint32_t x){jfloat v;memcpy(&v,&x,sizeof(v));return v;} jdouble nt_f64(uint64_t x){jdouble v;memcpy(&v,&x,sizeof(v));return v;}\n\n"
                + "static std::mutex g_nt_lock; static std::unordered_map<std::string,jclass> g_cls; static std::unordered_map<std::string,jmethodID> g_mid; static std::unordered_map<std::string,jfieldID> g_fid; static std::unordered_map<std::string,jobject> g_callsite;\n"
                + "jclass nt_resolve_class(JNIEnv* e,const char* n){std::lock_guard<std::mutex> l(g_nt_lock);auto it=g_cls.find(n);if(it!=g_cls.end())return it->second;jclass c=e->FindClass(n);if(!c)return NULL;jclass g=(jclass)e->NewGlobalRef(c);e->DeleteLocalRef(c);if(!g)return NULL;g_cls.emplace(n,g);return g;}\n"
                + "jmethodID nt_resolve_method(JNIEnv* e,jclass c,const char* cls,const char* n,const char* s,bool st){std::string k=std::string(cls)+\"|\"+n+\"|\"+s+\"|\"+(st?\"S\":\"I\");std::lock_guard<std::mutex> l(g_nt_lock);auto it=g_mid.find(k);if(it!=g_mid.end())return it->second;jmethodID id=st?e->GetStaticMethodID(c,n,s):e->GetMethodID(c,n,s);if(id)g_mid.emplace(k,id);return id;}\n"
                + "jfieldID nt_resolve_field(JNIEnv* e,jclass c,const char* cls,const char* n,const char* s,bool st){std::string k=std::string(cls)+\"|\"+n+\"|\"+s+\"|\"+(st?\"S\":\"I\");std::lock_guard<std::mutex> l(g_nt_lock);auto it=g_fid.find(k);if(it!=g_fid.end())return it->second;jfieldID id=st?e->GetStaticFieldID(c,n,s):e->GetFieldID(c,n,s);if(id)g_fid.emplace(k,id);return id;}\n"
                + "jobject nt_new_local(JNIEnv* e,jobject x){return x?e->NewLocalRef(x):NULL;} void nt_delete_local(JNIEnv* e,jobject x){if(x)e->DeleteLocalRef(x);}\n"
                + "jobject nt_box(JNIEnv* e,const char* t,jvalue v){const char* c=\"java/lang/Integer\";const char* m=\"valueOf\";const char* s=\"(I)Ljava/lang/Integer;\";if(!strcmp(t,\"J\")){c=\"java/lang/Long\";s=\"(J)Ljava/lang/Long;\";}else if(!strcmp(t,\"F\")){c=\"java/lang/Float\";s=\"(F)Ljava/lang/Float;\";}else if(!strcmp(t,\"D\")){c=\"java/lang/Double\";s=\"(D)Ljava/lang/Double;\";}else if(!strcmp(t,\"Z\")){c=\"java/lang/Boolean\";s=\"(Z)Ljava/lang/Boolean;\";}jclass k=e->FindClass(c);if(!k)return NULL;jmethodID id=e->GetStaticMethodID(k,m,s);if(!id){e->DeleteLocalRef(k);return NULL;}jobject o=e->CallStaticObjectMethodV(k,id,&v);e->DeleteLocalRef(k);return o;}\n"
                + "jobject nt_box_i(JNIEnv* e,jint v){jvalue x{};x.i=v;return nt_box(e,\"I\",x);} jobject nt_box_j(JNIEnv* e,jlong v){jvalue x{};x.j=v;return nt_box(e,\"J\",x);} jobject nt_box_f(JNIEnv* e,jfloat v){jvalue x{};x.f=v;return nt_box(e,\"F\",x);} jobject nt_box_d(JNIEnv* e,jdouble v){jvalue x{};x.d=v;return nt_box(e,\"D\",x);} jobject nt_box_z(JNIEnv* e,jboolean v){jvalue x{};x.z=v;return nt_box(e,\"Z\",x);}\n"
                + "jobject nt_make_method_type(JNIEnv* e,const char* d){jclass mt=e->FindClass(\"java/lang/invoke/MethodType\");if(!mt)return NULL;jmethodID id=e->GetStaticMethodID(mt,\"fromMethodDescriptorString\",\"(Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/invoke/MethodType;\");if(!id){e->DeleteLocalRef(mt);return NULL;}jstring ds=e->NewStringUTF(d);jobject r=e->CallStaticObjectMethod(mt,id,ds,NULL);e->DeleteLocalRef(ds);e->DeleteLocalRef(mt);return r;}\n"
                + "jobject nt_new_lookup(JNIEnv* e,jclass caller){jclass mh=e->FindClass(\"java/lang/invoke/MethodHandles\");if(!mh)return NULL;jmethodID l=e->GetStaticMethodID(mh,\"lookup\",\"()Ljava/lang/invoke/MethodHandles$Lookup;\");jobject base=e->CallStaticObjectMethod(mh,l);jmethodID pl=e->GetStaticMethodID(mh,\"privateLookupIn\",\"(Ljava/lang/Class;Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandles$Lookup;\");jobject r=NULL;if(pl!=NULL){r=e->CallStaticObjectMethod(mh,pl,caller,base);if(e->ExceptionCheck()){e->ExceptionClear();pl=NULL;}}if(pl==NULL)r=e->NewLocalRef(base);e->DeleteLocalRef(base);e->DeleteLocalRef(mh);return r;}\n"
                + "static jobject nt_bootstrap_handle(JNIEnv* e,jobject lookup,jclass owner,const char* name,const char* desc){jclass lk=e->GetObjectClass(lookup);jmethodID fs=e->GetMethodID(lk,\"findStatic\",\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;\");jstring n=e->NewStringUTF(name);jobject mt=nt_make_method_type(e,desc);jobject r=e->CallObjectMethod(lookup,fs,owner,n,mt);e->DeleteLocalRef(n);e->DeleteLocalRef(mt);e->DeleteLocalRef(lk);return r;}\n"
                + "jobject nt_make_method_handle(JNIEnv* e,jobject lookup,jclass owner,const char* kind,const char* name,const char* desc,const char* targetOwner,jclass caller){jclass lk=e->GetObjectClass(lookup);jstring n=e->NewStringUTF(name);jobject r=NULL;int wantsMt=!strcmp(kind,\"INVOKE_STATIC\")||!strcmp(kind,\"INVOKE_INSTANCE\")||!strcmp(kind,\"INVOKE_DIRECT\")||!strcmp(kind,\"INVOKE_INTERFACE\")||!strcmp(kind,\"INVOKE_CONSTRUCTOR\");jobject mt=wantsMt?nt_make_method_type(e,desc):NULL;if(wantsMt&&!mt){e->DeleteLocalRef(n);e->DeleteLocalRef(lk);return NULL;}if(!strcmp(kind,\"INVOKE_STATIC\")){jmethodID m=e->GetMethodID(lk,\"findStatic\",\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;\");r=e->CallObjectMethod(lookup,m,owner,n,mt);}else if(!strcmp(kind,\"INVOKE_INSTANCE\")||!strcmp(kind,\"INVOKE_INTERFACE\")){jmethodID m=e->GetMethodID(lk,\"findVirtual\",\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;\");r=e->CallObjectMethod(lookup,m,owner,n,mt);}else if(!strcmp(kind,\"INVOKE_DIRECT\")){jmethodID m=e->GetMethodID(lk,\"findSpecial\",\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/invoke/MethodType;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;\");r=e->CallObjectMethod(lookup,m,owner,n,mt,caller);}else if(!strcmp(kind,\"INVOKE_CONSTRUCTOR\")){jmethodID m=e->GetMethodID(lk,\"findConstructor\",\"(Ljava/lang/Class;Ljava/lang/invoke/MethodType;)Ljava/lang/invoke/MethodHandle;\");r=e->CallObjectMethod(lookup,m,owner,mt);}else{const char* mn=NULL; const char* ms=NULL; if(!strcmp(kind,\"STATIC_GET\")){mn=\"findStaticGetter\";ms=\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;\";} else if(!strcmp(kind,\"STATIC_PUT\")){mn=\"findStaticSetter\";ms=\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;\";} else if(!strcmp(kind,\"INSTANCE_GET\")){mn=\"findGetter\";ms=\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;\";} else {mn=\"findSetter\";ms=\"(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;\";} jmethodID m=e->GetMethodID(lk,mn,ms);jclass ft=NULL;if(!strcmp(targetOwner,\"I\")){jclass z=e->FindClass(\"java/lang/Integer\");jfieldID f=e->GetStaticFieldID(z,\"TYPE\",\"Ljava/lang/Class;\");ft=(jclass)e->GetStaticObjectField(z,f);e->DeleteLocalRef(z);}else if(!strcmp(targetOwner,\"J\")){jclass z=e->FindClass(\"java/lang/Long\");jfieldID f=e->GetStaticFieldID(z,\"TYPE\",\"Ljava/lang/Class;\");ft=(jclass)e->GetStaticObjectField(z,f);e->DeleteLocalRef(z);}else if(!strcmp(targetOwner,\"F\")){jclass z=e->FindClass(\"java/lang/Float\");jfieldID f=e->GetStaticFieldID(z,\"TYPE\",\"Ljava/lang/Class;\");ft=(jclass)e->GetStaticObjectField(z,f);e->DeleteLocalRef(z);}else if(!strcmp(targetOwner,\"D\")){jclass z=e->FindClass(\"java/lang/Double\");jfieldID f=e->GetStaticFieldID(z,\"TYPE\",\"Ljava/lang/Class;\");ft=(jclass)e->GetStaticObjectField(z,f);e->DeleteLocalRef(z);}else if(!strcmp(targetOwner,\"Z\")){jclass z=e->FindClass(\"java/lang/Boolean\");jfieldID f=e->GetStaticFieldID(z,\"TYPE\",\"Ljava/lang/Class;\");ft=(jclass)e->GetStaticObjectField(z,f);e->DeleteLocalRef(z);}else ft=nt_resolve_class(e,targetOwner);r=e->CallObjectMethod(lookup,m,owner,n,ft);}e->DeleteLocalRef(n);e->DeleteLocalRef(mt);e->DeleteLocalRef(lk);return r;}\n"
                + "jobject nt_invoke_custom(JNIEnv* e,jclass caller,const char* bo,const char* bn,const char* bd,const char* cn,const char* cd,jobjectArray extras,jobjectArray args){\n std::string key=std::to_string((uintptr_t)caller)+\"|\"+bo+\"|\"+bn+\"|\"+bd+\"|\"+cn+\"|\"+cd;\n jobject cs=NULL;\n {std::lock_guard<std::mutex> l(g_nt_lock);auto it=g_callsite.find(key);if(it!=g_callsite.end())cs=it->second;}\n if(cs)return e->NewLocalRef(cs);jobject lk=nt_new_lookup(e,caller);if(!lk)return NULL;jclass owner=nt_resolve_class(e,bo);if(!owner)return NULL;\n if(!cs){\n  jobject boot=nt_bootstrap_handle(e,lk,owner,bn,bd);if(!boot)return NULL;\n  jobject mt0=nt_make_method_type(e,cd);if(!mt0)return NULL;\n  jclass arr0=e->FindClass(\"java/util/ArrayList\");jmethodID ctor0=e->GetMethodID(arr0,\"<init>\",\"()V\");jmethodID add0=e->GetMethodID(arr0,\"add\",\"(Ljava/lang/Object;)Z\");\n  jobject list0=e->NewObject(arr0,ctor0);jclass mh0=e->GetObjectClass(boot);jmethodID mwa0=e->GetMethodID(mh0,\"invokeWithArguments\",\"(Ljava/util/List;)Ljava/lang/Object;\");\n  e->CallBooleanMethod(list0,add0,lk);jstring jn0=e->NewStringUTF(cn);e->CallBooleanMethod(list0,add0,jn0);e->CallBooleanMethod(list0,add0,mt0);\n  if(extras){jsize n0=e->GetArrayLength(extras);for(jsize i0=0;i0<n0;i0++){jobject ex0=e->GetObjectArrayElement(extras,i0);e->CallBooleanMethod(list0,add0,ex0);if(ex0)e->DeleteLocalRef(ex0);}}\n  cs=e->CallObjectMethod(boot,mwa0,list0);if(!cs)return NULL;\n  jobject global=e->NewGlobalRef(cs);{std::lock_guard<std::mutex> l(g_nt_lock);auto it=g_callsite.emplace(key,global);if(!it.second){e->DeleteGlobalRef(global);cs=it.first->second;}else cs=global;}\n  e->DeleteLocalRef(boot);e->DeleteLocalRef(mt0);e->DeleteLocalRef(arr0);e->DeleteLocalRef(list0);e->DeleteLocalRef(mh0);e->DeleteLocalRef(jn0);\n }\n jclass csc=e->GetObjectClass(cs);jmethodID gt=e->GetMethodID(csc,\"getTarget\",\"()Ljava/lang/invoke/MethodHandle;\");jobject target=e->CallObjectMethod(cs,gt);if(!target)return NULL;\n jclass arr=e->FindClass(\"java/util/ArrayList\");jmethodID ctor=e->GetMethodID(arr,\"<init>\",\"()V\");jmethodID add=e->GetMethodID(arr,\"add\",\"(Ljava/lang/Object;)Z\");jobject list=e->NewObject(arr,ctor);jclass mhcls=e->GetObjectClass(target);jmethodID mwa=e->GetMethodID(mhcls,\"invokeWithArguments\",\"(Ljava/util/List;)Ljava/lang/Object;\");\n if(args){jsize n=e->GetArrayLength(args);for(jsize i=0;i<n;i++){jobject a=e->GetObjectArrayElement(args,i);e->CallBooleanMethod(list,add,a);if(a)e->DeleteLocalRef(a);}}\n jobject out=e->CallObjectMethod(target,mwa,list);\n e->DeleteLocalRef(lk);e->DeleteLocalRef(owner);e->DeleteLocalRef(csc);e->DeleteLocalRef(target);e->DeleteLocalRef(arr);e->DeleteLocalRef(list);e->DeleteLocalRef(mhcls);return out;\n}"
                + "jvalue nt_unbox(JNIEnv* e,jobject o,const char* t){jvalue v{};if(!o)return v;const char* c=\"java/lang/Integer\";const char* m=\"intValue\";const char* s=\"()I\";if(!strcmp(t,\"J\")){c=\"java/lang/Long\";m=\"longValue\";s=\"()J\";}else if(!strcmp(t,\"F\")){c=\"java/lang/Float\";m=\"floatValue\";s=\"()F\";}else if(!strcmp(t,\"D\")){c=\"java/lang/Double\";m=\"doubleValue\";s=\"()D\";}else if(!strcmp(t,\"Z\")){c=\"java/lang/Boolean\";m=\"booleanValue\";s=\"()Z\";}jclass k=e->FindClass(c);jmethodID id=e->GetMethodID(k,m,s);if(!strcmp(t,\"J\"))v.j=e->CallLongMethod(o,id);else if(!strcmp(t,\"F\"))v.f=e->CallFloatMethod(o,id);else if(!strcmp(t,\"D\"))v.d=e->CallDoubleMethod(o,id);else if(!strcmp(t,\"Z\"))v.z=e->CallBooleanMethod(o,id);else v.i=e->CallIntMethod(o,id);e->DeleteLocalRef(k);return v;}\n";
    }

    /** Declarations of every compiled function, consumed by Dex2C.cpp and DynamicRegister.cpp. */
    private static String dex2cHpp(List<Method> compiled, boolean dynamic) {
        StringBuilder b = new StringBuilder("#ifndef DEX2C_HPP_\n"
                + "#define DEX2C_HPP_\n"
                + "\n"
                + "#include <jni.h>\n"
                + "#include <stdint.h>\n"
                + "#include \"dex2c_runtime.h\"\n"
                + "\n"
                + (dynamic ? "" : "extern \"C\" {\n"));
        if (compiled != null) {
            for (Method m : compiled) {
                b.append(Types.c(m.getReturnType())).append(" ")
                 .append(CppWriter.JniNames.name(m)).append(signature(m)).append(";\n");
            }
        }
        return b.append(dynamic ? "" : "}\n").append("\n#endif\n").toString();
    }

    private static String dynamicRegister(boolean dynamic, List<Method> compiled) {
        if (!dynamic || compiled == null || compiled.isEmpty()) {
            return "#include <jni.h>\n"
                    + "\n"
                    + "#include \"NT.h\"\n"
                    + "\n"
                    + "const char *dynamic_register_compile_methods(JNIEnv *env) { return NULL; }\n";
        }
        Map<String, List<Method>> byClass = new TreeMap<>();
        for (Method m : compiled) {
            byClass.computeIfAbsent(Types.descToClass(m.getDefiningClass()), k -> new ArrayList<>()).add(m);
        }
        StringBuilder b = new StringBuilder("#include <jni.h>\n\n#include \"dex2c.hpp\"\n\n");
        b.append("const char *dynamic_register_compile_methods(JNIEnv *env) {\n");
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
            b.append("    if (env->RegisterNatives(clazz, export_method_").append(idx)
             .append(", ").append(e.getValue().size()).append(") != JNI_OK) return \"RegisterNatives failed: ").append(e.getKey()).append("\";\n");
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
