#include <jni.h>

#include "NT.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    const char *err = dynamic_register_compile_methods(env);
    if (err != NULL) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}
