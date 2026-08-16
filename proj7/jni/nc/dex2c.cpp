#include "dex2c.hpp"

#include <jni.h>
#include <cstdint>
#include <cmath>
#include <limits>
#include <string>

static jint nt_div_i(JNIEnv* e,jint a,jint b){if(!b){e->ThrowNew(e->FindClass("java/lang/ArithmeticException"),"/ by zero");return 0;}if(a==INT32_MIN&&b==-1)return INT32_MIN;return a/b;}
static jint nt_rem_i(JNIEnv* e,jint a,jint b){if(!b){e->ThrowNew(e->FindClass("java/lang/ArithmeticException"),"/ by zero");return 0;}if(a==INT32_MIN&&b==-1)return 0;return a%b;}
static jlong nt_div_l(JNIEnv* e,jlong a,jlong b){if(!b){e->ThrowNew(e->FindClass("java/lang/ArithmeticException"),"/ by zero");return 0;}if(a==INT64_MIN&&b==-1)return INT64_MIN;return a/b;}
static jlong nt_rem_l(JNIEnv* e,jlong a,jlong b){if(!b){e->ThrowNew(e->FindClass("java/lang/ArithmeticException"),"/ by zero");return 0;}if(a==INT64_MIN&&b==-1)return 0;return a%b;}
static jfloat nt_f32(uint32_t x){union{uint32_t i;jfloat f;}u{ x };return u.f;} static jdouble nt_f64(uint64_t x){union{uint64_t i;jdouble d;}u{ x };return u.d;}


/* LI/ᅟ︀︃;-><init>(Lbin/nt/main/App;)V */
void Java_I__0115f_0fe00_0fe03__0003cinit_0003e__Lbin_nt_main_App_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︃"), "ᅟ︀︀", "Lbin/nt/main/App;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/App;)V -> Java_I__0115f_0fe00_0fe03__0003cinit_0003e__Lbin_nt_main_App_2 */

/* LI/ᅟ︁︁;-><init>(Lbin/nt/main/BaseActivity;LI/ᅟ︎︀;Landroid/graphics/Bitmap;[F[Z)V */
void Java_I__0115f_0fe01_0fe01__0003cinit_0003e__Lbin_nt_main_BaseActivity_2LI__0115f_0fe0e_0fe00_2Landroid_graphics_Bitmap_2_3F_3Z(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jarray p3, jarray p4) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jint v6 = 0;
  jobject v1 = NULL;
  jarray v5 = NULL;
  jarray v4 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︁"), "ᅟ︄︀", "Landroid/app/Activity;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︁"), "ᅟ︅︀", "Landroid/view/View;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︁"), "ᅟ︆︀", "Landroid/graphics/Bitmap;"), (jobject)(intptr_t)v3);
  v6 = 0;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︁"), "ᅟ︇︀", "Ljava/lang/Runnable;"), (jobject)(intptr_t)v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︁"), "ᅟ︈︀", "[F"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︁"), "ᅟ︉︀", "[Z"), (jobject)(intptr_t)v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/BaseActivity;LI/ᅟ︎︀;Landroid/graphics/Bitmap;[F[Z)V -> Java_I__0115f_0fe01_0fe01__0003cinit_0003e__Lbin_nt_main_BaseActivity_2LI__0115f_0fe0e_0fe00_2Landroid_graphics_Bitmap_2_3F_3Z */

/* LI/ᅟ︁︌;->ᅟ︃︁(Lbin/nt/editor/widget/CodeEditor;FF)V */
void Java_I__0115f_0fe01_0fe0c__0115f_0fe03_0fe01__Lbin_nt_editor_widget_CodeEditor_2FF(JNIEnv* env, jclass clazz, jobject p0, jfloat p1, jfloat p2) {
  jthrowable pendingException = NULL;
  jboolean v3 = 0;
  jfloat v2 = 0;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  v3 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "showContextMenu", "(FF)Z"), v1, v2, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︁(Lbin/nt/editor/widget/CodeEditor;FF)V -> Java_I__0115f_0fe01_0fe0c__0115f_0fe03_0fe01__Lbin_nt_editor_widget_CodeEditor_2FF */

/* LI/ᅟ︁︎;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;)V */
void Java_I__0115f_0fe01_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︎"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︁︎"), "ᅟ︅︀", "Ljava/io/File;"), (jobject)(intptr_t)v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;)V -> Java_I__0115f_0fe01_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2 */

/* LI/ᅟ︃︁;->ᅟ︄︁(Lbin/nt/editor/widget/CodeEditor;FF)V */
void Java_I__0115f_0fe03_0fe01__0115f_0fe04_0fe01__Lbin_nt_editor_widget_CodeEditor_2FF(JNIEnv* env, jclass clazz, jobject p0, jfloat p1, jfloat p2) {
  jthrowable pendingException = NULL;
  jboolean v3 = 0;
  jobject v0 = NULL;
  jfloat v2 = 0;
  jfloat v1 = 0;

L_0:
  v3 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "performContextClick", "(FF)Z"), v1, v2, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︄︁(Lbin/nt/editor/widget/CodeEditor;FF)V -> Java_I__0115f_0fe03_0fe01__0115f_0fe04_0fe01__Lbin_nt_editor_widget_CodeEditor_2FF */

/* LI/ᅟ︃︆;-><init>(Lbin/nt/fragments/FileBrowserFragment;Z)V */
void Java_I__0115f_0fe03_0fe06__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jint v3 = 0;
  jboolean v2 = 0;
  jobject v0 = NULL;

L_0:
  v3 = 1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︆"), "ᅟ︄︀", "I"), v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︆"), "ᅟ︆︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︆"), "ᅟ︅︀", "Z"), v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Z)V -> Java_I__0115f_0fe03_0fe06__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Z */

/* LI/ᅟ︃︇;-><init>(Lbin/nt/main/CrashActivity;I)V */
void Java_I__0115f_0fe03_0fe07__0003cinit_0003e__Lbin_nt_main_CrashActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︇"), "ᅟ︄︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︇"), "ᅟ︅︀", "Lbin/nt/main/CrashActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/CrashActivity;I)V -> Java_I__0115f_0fe03_0fe07__0003cinit_0003e__Lbin_nt_main_CrashActivity_2I */

/* LI/ᅟ︃︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;ZILjava/lang/String;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;)V */
void Java_I__0115f_0fe03_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2ZILjava_lang_String_2Ljava_io_File_2Ljava_lang_String_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jboolean p2, jint p3, jobject p4, jobject p5, jobject p6, jobject p7) {
  jthrowable pendingException = NULL;
  jobject v5 = NULL;
  jobject v7 = NULL;
  jobject v6 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jboolean v3 = 0;
  jobject v8 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︅︀", "Landroid/content/Context;"), (jobject)(intptr_t)v2);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︆︀", "Z"), v3);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︇︀", "I"), v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︈︀", "Ljava/lang/String;"), (jobject)(intptr_t)v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︉︀", "Ljava/io/File;"), (jobject)(intptr_t)v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︊︀", "Ljava/lang/String;"), (jobject)(intptr_t)v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︃︍"), "ᅟ︋︀", "Ljava/lang/String;"), (jobject)(intptr_t)v8);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;ZILjava/lang/String;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;)V -> Java_I__0115f_0fe03_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2ZILjava_lang_String_2Ljava_io_File_2Ljava_lang_String_2Ljava_lang_String_2 */

/* LI/ᅟ︄︀;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/Object;Ljava/io/Serializable;Ljava/io/Serializable;)V */
void Java_I__0115f_0fe04_0fe00__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_Object_2Ljava_io_Serializable_2Ljava_io_Serializable_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︃︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︁︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︂︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v4);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/Object;Ljava/io/Serializable;Ljava/io/Serializable;)V -> Java_I__0115f_0fe04_0fe00__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_Object_2Ljava_io_Serializable_2Ljava_io_Serializable_2 */

/* FAILED LI/ᅟ︄︌;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ︄︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/net/Uri;Ljava/lang/String;Ljava/util/List;LI/ᅟ︋︋;Landroid/widget/EditText;Landroid/widget/EditText;Landroid/widget/EditText;)V */
void Java_I__0115f_0fe04_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_net_Uri_2Ljava_lang_String_2Ljava_util_List_2LI__0115f_0fe0b_0fe0b_2Landroid_widget_EditText_2Landroid_widget_EditText_2Landroid_widget_EditText_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4, jobject p5, jobject p6, jobject p7) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v7 = NULL;
  jobject v3 = NULL;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v8 = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︅︀", "Landroid/net/Uri;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︆︀", "Ljava/lang/String;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︇︀", "Ljava/util/List;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︈︀", "LI/ᅟ︋︋;"), (jobject)(intptr_t)v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︉︀", "Landroid/widget/EditText;"), (jobject)(intptr_t)v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︊︀", "Landroid/widget/EditText;"), (jobject)(intptr_t)v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︍"), "ᅟ︋︀", "Landroid/widget/EditText;"), (jobject)(intptr_t)v8);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/net/Uri;Ljava/lang/String;Ljava/util/List;LI/ᅟ︋︋;Landroid/widget/EditText;Landroid/widget/EditText;Landroid/widget/EditText;)V -> Java_I__0115f_0fe04_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_net_Uri_2Ljava_lang_String_2Ljava_util_List_2LI__0115f_0fe0b_0fe0b_2Landroid_widget_EditText_2Landroid_widget_EditText_2Landroid_widget_EditText_2 */

/* LI/ᅟ︄︎;-><init>(Lbin/nt/fragments/FileBrowserFragment;[ZLjava/util/List;Ljava/lang/String;)V */
void Java_I__0115f_0fe04_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2_3ZLjava_util_List_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jarray p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jarray v2 = NULL;
  jobject v4 = NULL;
  jobject v1 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︎"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︎"), "ᅟ︅︀", "[Z"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︎"), "ᅟ︆︀", "Ljava/util/List;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︎"), "ᅟ︇︀", "Ljava/lang/String;"), (jobject)(intptr_t)v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;[ZLjava/util/List;Ljava/lang/String;)V -> Java_I__0115f_0fe04_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2_3ZLjava_util_List_2Ljava_lang_String_2 */

/* LI/ᅟ︅︁;->ᅟ︆︁(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe05_0fe01__0115f_0fe06_0fe01__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = 0;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "setDefaultFocusHighlightEnabled", "(Z)V"), v1, v1, v1, v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︆︁(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe05_0fe01__0115f_0fe06_0fe01__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︅︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Z)V */
void Java_I__0115f_0fe05_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jboolean v2 = 0;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︅︍"), "ᅟ︀︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︅︍"), "ᅟ︁︀", "Z"), v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Z)V -> Java_I__0115f_0fe05_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Z */

/* LI/ᅟ︆︁;->ᅟ︃︁(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe06_0fe01__0115f_0fe03_0fe01__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "performContextClick", "()Z"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︁(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe06_0fe01__0115f_0fe03_0fe01__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︆︃;-><init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/io/File;LI/ᅟ︍︎;)V */
void Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_io_File_2LI__0115f_0fe0d_0fe0e_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jint v5 = 0;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;

L_0:
  v5 = 4;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︄︀", "I"), v5);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v5, v5, v5, v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︆︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︅︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︇︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︈︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/io/File;LI/ᅟ︍︎;)V -> Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_io_File_2LI__0115f_0fe0d_0fe0e_2 */

/* LI/ᅟ︆︃;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/util/ArrayList;Ljava/io/File;Ljava/lang/String;)V */
void Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_util_ArrayList_2Ljava_io_File_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v4 = NULL;
  jobject v2 = NULL;
  jint v5 = 0;
  jobject v3 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v5 = 5;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︄︀", "I"), v5);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v5, v5, v5, v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︅︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︇︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︈︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︆︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/util/ArrayList;Ljava/io/File;Ljava/lang/String;)V -> Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_util_ArrayList_2Ljava_io_File_2Ljava_lang_String_2 */

/* LI/ᅟ︆︃;-><init>(Lbin/nt/fragments/FileBrowserFragment;[ZLjava/lang/String;Ljava/io/File;)V */
void Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2_3ZLjava_lang_String_2Ljava_io_File_2(JNIEnv* env, jobject thiz, jobject p0, jarray p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;
  jint v5 = 0;
  jobject v4 = NULL;
  jobject v0 = NULL;
  jarray v2 = NULL;

L_0:
  v5 = 3;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︄︀", "I"), v5);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v5, v5, v5, v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︅︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︇︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︆︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︃"), "ᅟ︈︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;[ZLjava/lang/String;Ljava/io/File;)V -> Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2_3ZLjava_lang_String_2Ljava_io_File_2 */

/* LI/ᅟ︆︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;IILjava/lang/String;Ljava/lang/String;ZJLjava/util/ArrayList;Ljava/lang/String;)V */
void Java_I__0115f_0fe06_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2IILjava_lang_String_2Ljava_lang_String_2ZJLjava_util_ArrayList_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jint p1, jint p2, jobject p3, jobject p4, jboolean p5, jlong p6, jobject p7, jobject p8) {
  jthrowable pendingException = NULL;
  jboolean v6 = 0;
  jlong v7 = 0;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jint v2 = 0;
  jobject v8 = NULL;
  jobject v9 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jint v3 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︅︀", "I"), v2);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︆︀", "I"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︇︀", "Ljava/lang/String;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︈︀", "Ljava/lang/String;"), (jobject)(intptr_t)v5);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︉︀", "Z"), v6);
  env->SetLongField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︊︀", "J"), v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︋︀", "Ljava/util/List;"), (jobject)(intptr_t)v8);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︍"), "ᅟ︌︀", "Ljava/lang/String;"), (jobject)(intptr_t)v9);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;IILjava/lang/String;Ljava/lang/String;ZJLjava/util/ArrayList;Ljava/lang/String;)V -> Java_I__0115f_0fe06_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2IILjava_lang_String_2Ljava_lang_String_2ZJLjava_util_ArrayList_2Ljava_lang_String_2 */

/* FAILED LI/ᅟ︇︋;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ︇︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;LI/ᅟ︋︋;Landroid/content/Context;Ljava/lang/String;Ljava/util/List;)V */
void Java_I__0115f_0fe07_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2LI__0115f_0fe0b_0fe0b_2Landroid_content_Context_2Ljava_lang_String_2Ljava_util_List_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4, jobject p5, jobject p6, jobject p7, jobject p8) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v8 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v2 = NULL;
  jobject v5 = NULL;
  jobject v3 = NULL;
  jobject v7 = NULL;
  jobject v9 = NULL;
  jobject v6 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︅︀", "Ljava/io/File;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︆︀", "Ljava/lang/String;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︇︀", "Ljava/lang/String;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︈︀", "Ljava/lang/String;"), (jobject)(intptr_t)v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︉︀", "LI/ᅟ︋︋;"), (jobject)(intptr_t)v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︊︀", "Landroid/content/Context;"), (jobject)(intptr_t)v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︋︀", "Ljava/lang/String;"), (jobject)(intptr_t)v8);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︇︍"), "ᅟ︌︀", "Ljava/util/List;"), (jobject)(intptr_t)v9);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;LI/ᅟ︋︋;Landroid/content/Context;Ljava/lang/String;Ljava/util/List;)V -> Java_I__0115f_0fe07_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2LI__0115f_0fe0b_0fe0b_2Landroid_content_Context_2Ljava_lang_String_2Ljava_util_List_2 */

/* FAILED LI/ᅟ︈︋;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ︈︌;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe08_0fe0c__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jlong v2 = 0;

L_0:
  v2 = (jlong)(intptr_t)env->CallStaticLongMethod(env->FindClass("java/lang/System"), env->GetStaticMethodID(env->FindClass("java/lang/System"), "currentTimeMillis", "()J"), v0, v0, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  v3 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/util/Objects"), env->GetStaticMethodID(env->FindClass("java/util/Objects"), "requireNonNull", "(Ljava/lang/Object;)Ljava/lang/Object;"), v1, v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︌"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  v4 = 0;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︌"), "ᅟ︁︀", "I"), v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe08_0fe0c__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︈︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;ZLandroid/content/Context;IIZ)V */
void Java_I__0115f_0fe08_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2ZLandroid_content_Context_2IIZ(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jboolean p2, jobject p3, jint p4, jint p5, jboolean p6) {
  jthrowable pendingException = NULL;
  jboolean v3 = 0;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v4 = NULL;
  jboolean v7 = 0;
  jobject v0 = NULL;
  jint v5 = 0;
  jint v6 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︅︀", "Ljava/lang/String;"), (jobject)(intptr_t)v2);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︆︀", "Z"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︇︀", "Landroid/content/Context;"), (jobject)(intptr_t)v4);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︈︀", "I"), v5);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︉︀", "I"), v6);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︍"), "ᅟ︊︀", "Z"), v7);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;ZLandroid/content/Context;IIZ)V -> Java_I__0115f_0fe08_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2ZLandroid_content_Context_2IIZ */

/* LI/ᅟ︈︎;-><init>(Lbin/nt/fragments/FileBrowserFragment;)V */
void Java_I__0115f_0fe08_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︎"), "ᅟ︀︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;)V -> Java_I__0115f_0fe08_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2 */

/* LI/ᅟ︉︅;-><init>(Lbin/nt/editor/widget/CodeEditor;Ljava/lang/Runnable;I)V */
void Java_I__0115f_0fe09_0fe05__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Ljava_lang_Runnable_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jint p2) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jint v3 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︅"), "ᅟ︄︀", "I"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︅"), "ᅟ︅︀", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︅"), "ᅟ︆︀", "Ljava/lang/Runnable;"), (jobject)(intptr_t)v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;Ljava/lang/Runnable;I)V -> Java_I__0115f_0fe09_0fe05__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Ljava_lang_Runnable_2I */

/* LI/ᅟ︉︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/lang/String;LI/ᅟ️︁;LI/ᅟ︎︎;Z)V */
void Java_I__0115f_0fe09_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_lang_String_2LI__0115f_0fe0f_0fe01_2LI__0115f_0fe0e_0fe0e_2Z(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4, jboolean p5) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v3 = NULL;
  jobject v5 = NULL;
  jboolean v6 = 0;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︍"), "ᅟ︅︀", "Landroid/content/Context;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︍"), "ᅟ︆︀", "Ljava/lang/String;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︍"), "ᅟ︇︀", "LI/ᅟ️︁;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︍"), "ᅟ︈︀", "LI/ᅟ︎︎;"), (jobject)(intptr_t)v5);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︍"), "ᅟ︉︀", "Z"), v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/lang/String;LI/ᅟ️︁;LI/ᅟ︎︎;Z)V -> Java_I__0115f_0fe09_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_lang_String_2LI__0115f_0fe0f_0fe01_2LI__0115f_0fe0e_0fe0e_2Z */

/* LI/ᅟ︊︊;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe0a_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v9 = NULL;
  jint v2 = 0;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jobject v8 = NULL;
  jobject v0 = NULL;
  jobject v7 = NULL;
  jobject v3 = NULL;
  jint v6 = 0;
  jint v4 = 0;

L_0:
  v2 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/inputmethod/BaseInputConnection"), "<init>", "(Landroid/view/View;Z)V"), v1, v2, v2, v2);
  v3 = env->AllocObject(env->FindClass("I/ᅟ︇︆"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︁︀", "LI/ᅟ︇︆;"), (jobject)(intptr_t)v3);
  v4 = 0;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︂︀", "Z"), v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  v5 = env->AllocObject(env->FindClass("I/ᅟ︉︊"));
  v6 = 0;
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅟ︉︊"), "<init>", "(ILjava/lang/Object;)V"), v6, v0, v5, v5);
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v8 = env->FindClass("I/ᅟ︀︇");
  v9 = (jobject)env->CallObjectMethod((jobject)v7, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v8, v5, v5, v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe0a_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︊︋;-><init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/lang/String;Ljava/lang/Object;I)V */
void Java_I__0115f_0fe0a_0fe0b__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_lang_String_2Ljava_lang_Object_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jint p4) {
  jthrowable pendingException = NULL;
  jint v5 = 0;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;
  jobject v4 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︋"), "ᅟ︄︀", "I"), v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︋"), "ᅟ︅︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︋"), "ᅟ︆︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︋"), "ᅟ︇︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v4);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/lang/String;Ljava/lang/Object;I)V -> Java_I__0115f_0fe0a_0fe0b__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_lang_String_2Ljava_lang_Object_2I */

/* LI/ᅟ︊︎;-><init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Z)V */
void Java_I__0115f_0fe0a_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2Z(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jboolean p2) {
  jthrowable pendingException = NULL;
  jboolean v3 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︎"), "ᅟ︂︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︎"), "ᅟ︁︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︎"), "ᅟ︀︀", "Z"), v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Z)V -> Java_I__0115f_0fe0a_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2Z */

/* LI/ᅟ︋︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;I)V */
void Java_I__0115f_0fe0b_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jint p2) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v3 = 0;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︍"), "ᅟ︄︀", "I"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︍"), "ᅟ︅︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︍"), "ᅟ︆︀", "LI/ᅟ︎︎;"), (jobject)(intptr_t)v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;I)V -> Java_I__0115f_0fe0b_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2I */

/* FAILED LI/ᅟ︌︉;->ᅟ︀︀(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ︌︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;Ljava/io/File;LI/ᅟ︂︄;LI/ᅟ︎︎;Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V */
void Java_I__0115f_0fe0c_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2Ljava_io_File_2LI__0115f_0fe02_0fe04_2LI__0115f_0fe0e_0fe0e_2Landroid_content_Context_2Ljava_lang_String_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4, jobject p5, jobject p6, jobject p7) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v6 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jobject v2 = NULL;
  jobject v7 = NULL;
  jobject v8 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︅︀", "Ljava/io/File;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︆︀", "Ljava/io/File;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︇︀", "LI/ᅟ︂︄;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︈︀", "LI/ᅟ︎︎;"), (jobject)(intptr_t)v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︉︀", "Landroid/content/Context;"), (jobject)(intptr_t)v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︊︀", "Ljava/lang/String;"), (jobject)(intptr_t)v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︍"), "ᅟ︋︀", "Ljava/lang/String;"), (jobject)(intptr_t)v8);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;Ljava/io/File;LI/ᅟ︂︄;LI/ᅟ︎︎;Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V -> Java_I__0115f_0fe0c_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2Ljava_io_File_2LI__0115f_0fe02_0fe04_2LI__0115f_0fe0e_0fe0e_2Landroid_content_Context_2Ljava_lang_String_2Ljava_lang_String_2 */

/* FAILED LI/ᅟ︍︋;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ︍︌;-><init>(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V */
void Java_I__0115f_0fe0d_0fe0c__0003cinit_0003e__Lbin_nt_ui_fastscroll_FastScrollerRecyclerView_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︍︌"), "ᅟ︄︀", "Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V -> Java_I__0115f_0fe0d_0fe0c__0003cinit_0003e__Lbin_nt_ui_fastscroll_FastScrollerRecyclerView_2 */

/* LI/ᅟ︎︀;-><init>(Lbin/nt/main/BaseActivity;Landroid/graphics/Bitmap;Landroid/graphics/Paint;[Landroid/graphics/Rect;[FLandroid/graphics/Paint;)V */
void Java_I__0115f_0fe0e_0fe00__0003cinit_0003e__Lbin_nt_main_BaseActivity_2Landroid_graphics_Bitmap_2Landroid_graphics_Paint_2_3Landroid_graphics_Rect_2_3FLandroid_graphics_Paint_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jarray p3, jarray p4, jobject p5) {
  jthrowable pendingException = NULL;
  jarray v5 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jarray v4 = NULL;
  jobject v6 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︀"), "ᅟ︄︀", "Landroid/graphics/Bitmap;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︀"), "ᅟ︅︀", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︀"), "ᅟ︆︀", "[Landroid/graphics/Rect;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︀"), "ᅟ︇︀", "[F"), (jobject)(intptr_t)v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︀"), "ᅟ︈︀", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v6);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "<init>", "(Landroid/content/Context;)V"), v1, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/BaseActivity;Landroid/graphics/Bitmap;Landroid/graphics/Paint;[Landroid/graphics/Rect;[FLandroid/graphics/Paint;)V -> Java_I__0115f_0fe0e_0fe00__0003cinit_0003e__Lbin_nt_main_BaseActivity_2Landroid_graphics_Bitmap_2Landroid_graphics_Paint_2_3Landroid_graphics_Rect_2_3FLandroid_graphics_Paint_2 */

/* LI/ᅟ︎︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;[Z[Ljava/lang/String;Ljava/lang/String;)V */
void Java_I__0115f_0fe0e_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2_3Z_3Ljava_lang_String_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jarray p2, jarray p3, jobject p4) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jarray v3 = NULL;
  jobject v2 = NULL;
  jarray v4 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︍"), "ᅟ︄︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︍"), "ᅟ︅︀", "Ljava/lang/String;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︍"), "ᅟ︆︀", "[Z"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︍"), "ᅟ︇︀", "[Ljava/lang/String;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︍"), "ᅟ︈︀", "Ljava/lang/String;"), (jobject)(intptr_t)v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;[Z[Ljava/lang/String;Ljava/lang/String;)V -> Java_I__0115f_0fe0e_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2_3Z_3Ljava_lang_String_2Ljava_lang_String_2 */

/* FAILED LI/ᅟ️︊;-><init>(Lbin/nt/editor/widget/CodeEditor;I)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ️︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;LI/ᅟ︎︎;I)V */
void Java_I__0115f_0fe0f_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2LI__0115f_0fe0e_0fe0e_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jint p3) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︍"), "ᅟ︄︀", "I"), v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︍"), "ᅟ︅︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︍"), "ᅟ︆︀", "Ljava/lang/String;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︍"), "ᅟ︇︀", "LI/ᅟ︎︎;"), (jobject)(intptr_t)v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;LI/ᅟ︎︎;I)V -> Java_I__0115f_0fe0f_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2LI__0115f_0fe0e_0fe0e_2I */

/* LI/ᅠ︀︂;-><init>(Lbin/nt/main/MainActivity;I)V */
void Java_I__01160_0fe00_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jint v2 = 0;
  jobject v0 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︀︂"), "ᅟ︄︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︀︂"), "ᅟ︅︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;I)V -> Java_I__01160_0fe00_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I */

/* LI/ᅠ︁︄;-><init>(Lbin/nt/main/PhotoViewerActivity;I)V */
void Java_I__01160_0fe01_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jint v2 = 0;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︁︄"), "ᅟ︄︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︁︄"), "ᅟ︅︀", "Lbin/nt/main/PhotoViewerActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/PhotoViewerActivity;I)V -> Java_I__01160_0fe01_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2I */

/* LI/ᅠ︂︂;-><init>(Lbin/nt/main/MainActivity;I)V */
void Java_I__01160_0fe02_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︂"), "ᅟ︄︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︂"), "ᅟ︅︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;I)V -> Java_I__01160_0fe02_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I */

/* LI/ᅠ︂︃;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__01160_0fe02_0fe03__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v20 = NULL;
  jobject v25 = NULL;
  jobject v36 = NULL;
  jboolean v42 = 0;
  jobject v6 = NULL;
  jint v7 = 0;
  jobject v18 = NULL;
  jobject v40 = NULL;
  jint v16 = 0;
  jint v12 = 0;
  jboolean v35 = 0;
  jobject v2 = NULL;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jboolean v28 = 0;
  jobject v17 = NULL;
  jobject v19 = NULL;
  jobject v38 = NULL;
  jobject v32 = NULL;
  jint v10 = 0;
  jobject v3 = NULL;
  jobject v26 = NULL;
  jint v37 = 0;
  jobject v24 = NULL;
  jobject v13 = NULL;
  jint v30 = 0;
  jobject v31 = NULL;
  jint v14 = 0;
  jarray v8 = NULL;
  jobject v15 = NULL;
  jint v23 = 0;
  jobject v27 = NULL;
  jint v9 = 0;
  jobject v34 = NULL;
  jobject v33 = NULL;
  jobject v22 = NULL;
  jboolean v21 = 0;
  jobject v41 = NULL;
  jobject v29 = NULL;
  jobject v39 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jlong v11 = 0;

L_0:
  v2 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v2, v2, v2, v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︄︀", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  v3 = env->AllocObject(env->FindClass("I/ᅟ︆︎"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︆︎"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︅︀", "LI/ᅟ︆︎;"), (jobject)(intptr_t)v3);
  v4 = env->AllocObject(env->FindClass("android/graphics/RectF"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/graphics/RectF"), "<init>", "()V"), v4, v4, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︆︀", "Landroid/graphics/RectF;"), (jobject)(intptr_t)v4);
  v5 = env->AllocObject(env->FindClass("android/graphics/RectF"));
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/RectF"), "<init>", "()V"), v5, v5, v5, v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︇︀", "Landroid/graphics/RectF;"), (jobject)(intptr_t)v5);
  v6 = env->AllocObject(env->FindClass("I/ᅠ︎︃"));
  v7 = 0;
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅠ︎︃"), "<init>", "(Z)V"), v7, v6, v6, v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︈︀", "LI/ᅠ︎︃;"), (jobject)(intptr_t)v6);
  v8 = env->NewIntArray((jsize)(intptr_t)v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︊︀", "[I"), (jobject)(intptr_t)v8);
  v9 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︋︀", "I"), v9);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︌︀", "I"), v9);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︍︀", "I"), v9);
  v10 = -2147483648;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︎︀", "I"), v10);
  v11 = -9223372036854775808;
  env->SetLongField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ️︀", "J"), v11);
  v12 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︀︁", "Z"), v12);
  v13 = env->AllocObject(env->FindClass("java/util/ArrayList"));
  v14 = 4;
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/ArrayList"), "<init>", "(I)V"), v14, v13, v13, v13);
  v15 = env->AllocObject(env->FindClass("I/ᅠ︁︃"));
  v16 = 0;
  env->CallVoidMethod((jobject)v15, env->GetMethodID(env->FindClass("I/ᅠ︁︃"), "<init>", "(LI/ᅠ︂︃;I)V"), v0, v16, v13, v13);
  v17 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v18 = env->FindClass("I/ᅟ︀︇");
  v19 = (jobject)env->CallObjectMethod((jobject)v17, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v18, v15, v13, v13);
  v20 = v19;
  v21 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/ArrayList"), "add", "(Ljava/lang/Object;)Z"), v20, v13, v13, v13);
  v22 = env->AllocObject(env->FindClass("I/ᅠ︁︃"));
  v23 = 1;
  env->CallVoidMethod((jobject)v22, env->GetMethodID(env->FindClass("I/ᅠ︁︃"), "<init>", "(LI/ᅠ︂︃;I)V"), v0, v23, v13, v13);
  v24 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v25 = env->FindClass("I/ᅟ︀︆");
  v26 = (jobject)env->CallObjectMethod((jobject)v24, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v25, v22, v13, v13);
  v27 = v26;
  v28 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/ArrayList"), "add", "(Ljava/lang/Object;)Z"), v27, v13, v13, v13);
  v29 = env->AllocObject(env->FindClass("I/ᅠ︁︃"));
  v30 = 2;
  env->CallVoidMethod((jobject)v29, env->GetMethodID(env->FindClass("I/ᅠ︁︃"), "<init>", "(LI/ᅠ︂︃;I)V"), v0, v30, v13, v13);
  v31 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v32 = env->FindClass("I/ᅠ︎︊");
  v33 = (jobject)env->CallObjectMethod((jobject)v31, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v32, v29, v13, v13);
  v34 = v33;
  v35 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/ArrayList"), "add", "(Ljava/lang/Object;)Z"), v34, v13, v13, v13);
  v36 = env->AllocObject(env->FindClass("I/ᅠ︁︃"));
  v37 = 3;
  env->CallVoidMethod((jobject)v36, env->GetMethodID(env->FindClass("I/ᅠ︁︃"), "<init>", "(LI/ᅠ︂︃;I)V"), v0, v37, v13, v13);
  v38 = (jobject)env->GetObjectField((jobject)(intptr_t)v38, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v39 = env->FindClass("I/ᅟ︁︋");
  v40 = (jobject)env->CallObjectMethod((jobject)v38, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v39, v36, v13, v13);
  v41 = v40;
  v42 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/ArrayList"), "add", "(Ljava/lang/Object;)Z"), v41, v13, v13, v13);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︃"), "ᅟ︃︁", "Ljava/util/ArrayList;"), (jobject)(intptr_t)v13);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__01160_0fe02_0fe03__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅠ︃︂;-><init>(Lbin/nt/main/MainActivity;Ljava/io/File;Ljava/util/ArrayList;I)V */
void Java_I__01160_0fe03_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Ljava_io_File_2Ljava_util_ArrayList_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jint p3) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︂"), "ᅟ︄︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︂"), "ᅟ︅︀", "Ljava/io/File;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︂"), "ᅟ︆︀", "Ljava/util/List;"), (jobject)(intptr_t)v3);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︂"), "ᅟ︇︀", "I"), v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;Ljava/io/File;Ljava/util/ArrayList;I)V -> Java_I__01160_0fe03_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Ljava_io_File_2Ljava_util_ArrayList_2I */

/* FAILED LI/ᅠ︃︆;->ᅟ︌︁(Lbin/nt/editor/widget/CodeEditor;Landroid/view/MotionEvent;I)J: java.lang.IllegalStateException: unknown phi type v3_13 = phi[v3_21 = phi[v3_12 = phi[v3_0, v3_0], v3_12 = phi[v3_0, v3_0]], v3_23 = phi[v3_21 = phi[v3_12 = phi[v3_0, v3_0], v3_12 = phi[v3_0, v3_0]], v3_21 = phi[v3_12 = phi[v3_0, v3_0], v3_12 = phi[v3_0, v3_0]]]] */

/* LI/ᅠ︄︂;-><init>(Lbin/nt/main/MainActivity;ILjava/lang/String;ILjava/lang/String;)V */
void Java_I__01160_0fe04_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2ILjava_lang_String_2ILjava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jint p1, jobject p2, jint p3, jobject p4) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jint v2 = 0;
  jobject v5 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︄︂"), "ᅟ︄︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︄︂"), "ᅟ︅︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︄︂"), "ᅟ︆︀", "Ljava/lang/String;"), (jobject)(intptr_t)v3);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︄︂"), "ᅟ︇︀", "I"), v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︄︂"), "ᅟ︈︀", "Ljava/lang/String;"), (jobject)(intptr_t)v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;ILjava/lang/String;ILjava/lang/String;)V -> Java_I__01160_0fe04_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2ILjava_lang_String_2ILjava_lang_String_2 */

/* LI/ᅠ︄︉;->ᅟ︋︂(Lbin/nt/main/BaseActivity;II[Landroid/graphics/Rect;LI/ᅟ︈︈;)V */
void Java_I__01160_0fe04_0fe09__0115f_0fe0b_0fe02__Lbin_nt_main_BaseActivity_2II_3Landroid_graphics_Rect_2LI__0115f_0fe08_0fe08_2(JNIEnv* env, jclass clazz, jobject p0, jint p1, jint p2, jarray p3, jobject p4) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jint v27 = 0;
  jint v28 = 0;
  jint v107 = 0;
  jboolean v55 = 0;
  jint v71 = 0;
  jint v15 = 0;
  jobject v26 = NULL;
  jlong v75 = 0;
  jobject v108 = NULL;
  jlong v58 = 0;
  jobject v13 = NULL;
  jlong v40 = 0;
  jlong v76 = 0;
  jlong v77 = 0;
  jobject v97 = NULL;
  jobject v113 = NULL;
  jlong v79 = 0;
  jlong v51 = 0;
  jint v90 = 0;
  jint v46 = 0;
  jlong v38 = 0;
  jlong v42 = 0;
  jobject v91 = NULL;
  jobject v101 = NULL;
  jboolean v20 = 0;
  jobject v21 = NULL;
  jint v31 = 0;
  jint v32 = 0;
  jobject v87 = NULL;
  jint v93 = 0;
  jobject v89 = NULL;
  jint v34 = 0;
  jboolean v114 = 0;
  jobject v4 = NULL;
  jint v1 = 0;
  jobject v35 = NULL;
  jobject v57 = NULL;
  jint v6 = 0;
  jint v5 = 0;
  jobject v110 = NULL;
  jobject v60 = NULL;
  jobject v72 = NULL;
  jlong v52 = 0;
  jint v61 = 0;
  jint v47 = 0;
  jobject v25 = NULL;
  jlong v43 = 0;
  jlong v65 = 0;
  jlong v63 = 0;
  jobject v22 = NULL;
  jint v49 = 0;
  jlong v39 = 0;
  jobject v45 = NULL;
  jobject v0 = NULL;
  jlong v37 = 0;
  jboolean v7 = 0;
  jlong v53 = 0;
  jlong v78 = 0;
  jboolean v19 = 0;
  jint v74 = 0;
  jobject v23 = NULL;
  jobject v48 = NULL;
  jobject v18 = NULL;
  jobject v109 = NULL;
  jarray v94 = NULL;
  jint v30 = 0;
  jobject v82 = NULL;
  jlong v44 = 0;
  jobject v86 = NULL;
  jlong v36 = 0;
  jobject v106 = NULL;
  jobject v10 = NULL;
  jlong v64 = 0;
  jobject v11 = NULL;
  jboolean v83 = 0;
  jobject v95 = NULL;
  jobject v100 = NULL;
  jobject v105 = NULL;
  jobject v59 = NULL;
  jboolean v84 = 0;
  jint v14 = 0;
  jobject v98 = NULL;
  jobject v96 = NULL;
  jlong v66 = 0;
  jboolean v8 = 0;
  jint v62 = 0;
  jobject v88 = NULL;
  jobject v69 = NULL;
  jobject v104 = NULL;
  jarray v92 = NULL;
  jlong v67 = 0;
  jobject v103 = NULL;
  jlong v41 = 0;
  jobject v102 = NULL;
  jobject v12 = NULL;
  jobject v33 = NULL;
  jobject v112 = NULL;
  jint v16 = 0;
  jint v17 = 0;
  jarray v50 = NULL;
  jobject v85 = NULL;
  jlong v68 = 0;
  jobject v29 = NULL;
  jobject v54 = NULL;
  jint v9 = 0;
  jarray v70 = NULL;
  jboolean v56 = 0;
  jboolean v81 = 0;
  jobject v24 = NULL;
  jint v73 = 0;
  jboolean v80 = 0;
  jarray v3 = NULL;
  jobject v99 = NULL;
  jobject v111 = NULL;

L_0:
  v5 = 0;
  v6 = 1;
  v7 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Activity"), "isFinishing", "()Z"), v5, v5, v5, v5);
  v8 = v7;
  /* UNSUPPORTED: if-eqz */
  if (v8 == 0) { goto L_c;
 } else { goto L_8;
 }

L_8:
  env->CallStaticVoidMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︂", "(Ljava/lang/Runnable;)V"), v4, v5, v5, v5, v5);
  /* return terminator */
  return;

L_c:
  v9 = 0;
goto L_d;

L_d:
  v10 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Activity"), "getWindow", "()Landroid/view/Window;"), v5, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v11 = v10;
  v12 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/view/Window"), "getDecorView", "()Landroid/view/View;"), v5, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v13 = v12;
  v14 = (jint)(intptr_t)env->CallIntMethod((jobject)v13, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v5, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v15 = v14;
  v16 = (jint)(intptr_t)env->CallIntMethod((jobject)v13, env->GetMethodID(env->FindClass("android/view/View"), "getHeight", "()I"), v5, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v17 = v16;
  /* UNSUPPORTED: if-lez */
  if (v15 <= 0) { v69 = (jobject)v4; v70 = (jarray)v3; v71 = (jint)v5; v72 = (jobject)v0; v73 = (jint)v6; v74 = (jint)v9; goto L_5e;
 } else { goto L_1f;
 }

L_1f:
  /* UNSUPPORTED: if-gtz */
  if (v17 > 0) { goto L_22;
 } else { goto L_21;
 }

L_21:
  /* UNSUPPORTED: goto */
v69 = (jobject)(intptr_t)v51; v70 = (jarray)v3; v71 = (jint)v5; v72 = (jobject)v0; v73 = (jint)v6; v74 = (jint)v9; goto L_5e;

L_22:
  v18 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  /* UNSUPPORTED: if-eqz */
  if (v18 == 0) { v27 = (jint)v17; v28 = (jint)v15; v29 = (jobject)v13; v30 = (jint)v9; v31 = (jint)v5; v32 = (jint)v1; v33 = (jobject)v4; v34 = (jint)v2; v35 = (jobject)v0; goto L_34;
 } else { goto L_26;
 }

L_26:
  v19 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v18, env->GetMethodID(env->FindClass("android/graphics/Bitmap"), "isRecycled", "()Z"), v5, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v20 = v19;
  /* UNSUPPORTED: if-nez */
  if (v20 != 0) { v27 = (jint)v17; v28 = (jint)v15; v29 = (jobject)v13; v30 = (jint)v9; v31 = (jint)v5; v32 = (jint)v1; v33 = (jobject)v4; v34 = (jint)v2; v35 = (jobject)v0; goto L_34;
 } else { goto L_2c;
 }

L_2c:
  v21 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallVoidMethod((jobject)v21, env->GetMethodID(env->FindClass("android/graphics/Bitmap"), "recycle", "()V"), v5, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  /* UNSUPPORTED: goto */
v27 = (jint)(intptr_t)v36; v28 = (jint)(intptr_t)v37; v29 = (jobject)(intptr_t)v38; v30 = (jint)(intptr_t)v39; v31 = (jint)(intptr_t)v40; v32 = (jint)(intptr_t)v41; v33 = (jobject)(intptr_t)v42; v34 = (jint)(intptr_t)v43; v35 = (jobject)(intptr_t)v44; goto L_34;

L_34:
  env->SetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"), (jobject)(intptr_t)v30); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v22 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Bitmap$Config"), env->GetStaticFieldID(env->FindClass("android/graphics/Bitmap$Config"), "ARGB_8888", "Landroid/graphics/Bitmap$Config;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v23 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/graphics/Bitmap"), env->GetStaticMethodID(env->FindClass("android/graphics/Bitmap"), "createBitmap", "(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;"), v28, v27, v22, v31, v31); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v24 = (jobject)(intptr_t)v23;
  env->SetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"), (jobject)(intptr_t)v24); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v25 = env->AllocObject(env->FindClass("android/graphics/Canvas")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v26 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallVoidMethod((jobject)v25, env->GetMethodID(env->FindClass("android/graphics/Canvas"), "<init>", "(Landroid/graphics/Bitmap;)V"), v26, v31, v31, v31); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallVoidMethod((jobject)v29, env->GetMethodID(env->FindClass("android/view/View"), "draw", "(Landroid/graphics/Canvas;)V"), v25, v31, v31, v31); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->SetStaticIntField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︆︀", "I"), v32); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->SetStaticIntField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︇︀", "I"), v34); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
goto L_4c;

L_32:
  ;
  /* UNSUPPORTED: goto */
goto L_4d;

L_4d:
  v54 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"));
  /* UNSUPPORTED: if-eqz */
  if (v54 == 0) { v59 = (jobject)v45; v60 = (jobject)v48; v61 = (jint)v49; v62 = (jint)v46; goto L_5c;
 } else { goto L_51;
 }

L_51:
  v55 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v54, env->GetMethodID(env->FindClass("android/graphics/Bitmap"), "isRecycled", "()Z"), v49, v49, v49, v49);
  v56 = v55;
  /* UNSUPPORTED: if-nez */
  if (v56 != 0) { v59 = (jobject)(intptr_t)v63; v60 = (jobject)(intptr_t)v65; v61 = (jint)(intptr_t)v58; v62 = (jint)v46; goto L_5c;
 } else { goto L_57;
 }

L_57:
  v57 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"));
  env->CallVoidMethod((jobject)v57, env->GetMethodID(env->FindClass("android/graphics/Bitmap"), "recycle", "()V"), v58, v58, v58, v58);
v59 = (jobject)(intptr_t)v64; v60 = (jobject)(intptr_t)v66; v61 = (jint)(intptr_t)v67; v62 = (jint)(intptr_t)v68; goto L_5c;

L_5c:
  env->SetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"), (jobject)(intptr_t)v62);
v69 = (jobject)v59; v70 = (jarray)(intptr_t)v76; v71 = (jint)v61; v72 = (jobject)v60; v73 = (jint)(intptr_t)v79; v74 = (jint)v62; goto L_5e;

L_4c:
  /* UNSUPPORTED: goto */
v69 = (jobject)(intptr_t)v75; v70 = (jarray)(intptr_t)v53; v71 = (jint)(intptr_t)v77; v72 = (jobject)(intptr_t)v78; v73 = (jint)(intptr_t)v52; v74 = (jint)v30; goto L_5e;

L_5e:
  /* UNSUPPORTED: if-eqz */
  if (v69 == 0) { goto L_63;
 } else { goto L_60;
 }

L_60:
  env->CallVoidMethod((jobject)v69, env->GetMethodID(env->FindClass("I/ᅟ︈︈"), "run", "()V"), v71, v71, v71, v71);
goto L_63;

L_63:
  v80 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v72, env->GetMethodID(env->FindClass("android/app/Activity"), "isFinishing", "()Z"), v71, v71, v71, v71);
  v81 = v80;
  /* UNSUPPORTED: if-eqz */
  if (v81 == 0) { goto L_6a;
 } else { goto L_69;
 }

L_69:
  /* UNSUPPORTED: goto */
goto L_cb;

L_6a:
  v82 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"));
  /* UNSUPPORTED: if-eqz */
  if (v82 == 0) { goto L_cb;
 } else { goto L_6e;
 }

L_6e:
  v83 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v82, env->GetMethodID(env->FindClass("android/graphics/Bitmap"), "isRecycled", "()Z"), v71, v71, v71, v71);
  v84 = v83;
  /* UNSUPPORTED: if-eqz */
  if (v84 == 0) { goto L_75;
 } else { goto L_74;
 }

L_74:
  /* UNSUPPORTED: goto */
goto L_cb;

L_75:
  v85 = (jobject)env->CallObjectMethod((jobject)v72, env->GetMethodID(env->FindClass("android/app/Activity"), "getWindow", "()Landroid/view/Window;"), v71, v71, v71, v71);
  v86 = v85;
  v87 = (jobject)env->CallObjectMethod((jobject)v86, env->GetMethodID(env->FindClass("android/view/Window"), "getDecorView", "()Landroid/view/View;"), v71, v71, v71, v71);
  v88 = v87;
  v89 = (jobject)(v0 && env->IsInstanceOf((jobject)v0, env->FindClass("android/view/ViewGroup")) ? 1 : 0);
  /* UNSUPPORTED: if-nez */
  if (v89 != 0) { goto L_82;
 } else { goto L_81;
 }

L_81:
  /* UNSUPPORTED: goto */
goto L_cb;

L_82:
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/view/ViewGroup"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v91 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"));
  env->SetStaticObjectField(env->FindClass("I/ᅠ︄︉"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "Landroid/graphics/Bitmap;"), (jobject)(intptr_t)v74);
  v92 = env->NewFloatArray((jsize)(intptr_t)v73);
  v93 = 0;
  env->SetIntArrayRegion((jintArray)v92, (jsize)(intptr_t)v71, 1, (jint*)&v93);
  v94 = env->NewBooleanArray((jsize)(intptr_t)v73);
  env->SetBooleanArrayRegion((jbooleanArray)v94, (jsize)(intptr_t)v71, 1, (jboolean*)&v71);
  v95 = env->AllocObject(env->FindClass("android/graphics/Paint"));
  env->CallVoidMethod((jobject)v95, env->GetMethodID(env->FindClass("android/graphics/Paint"), "<init>", "(I)V"), v73, v71, v71, v71);
  env->CallVoidMethod((jobject)v95, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setFilterBitmap", "(Z)V"), v73, v71, v71, v71);
  v96 = env->AllocObject(env->FindClass("android/graphics/Paint"));
  env->CallVoidMethod((jobject)v96, env->GetMethodID(env->FindClass("android/graphics/Paint"), "<init>", "(I)V"), v73, v71, v71, v71);
  v97 = env->AllocObject(env->FindClass("android/graphics/PorterDuffXfermode"));
  v98 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/PorterDuff$Mode"), env->GetStaticFieldID(env->FindClass("android/graphics/PorterDuff$Mode"), "CLEAR", "Landroid/graphics/PorterDuff$Mode;"));
  env->CallVoidMethod((jobject)v97, env->GetMethodID(env->FindClass("android/graphics/PorterDuffXfermode"), "<init>", "(Landroid/graphics/PorterDuff$Mode;)V"), v98, v97, v97, v97);
  v99 = (jobject)env->CallObjectMethod((jobject)v96, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setXfermode", "(Landroid/graphics/Xfermode;)Landroid/graphics/Xfermode;"), v97, v97, v97, v97);
  v100 = env->AllocObject(env->FindClass("I/ᅟ︎︀"));
  /* dbg-move v101 v100 dv=Ljava/lang/Object; sv=LI/ᅟ︎︀; */
  /* dbg-move v102 v72 dv=Ljava/lang/Object; sv=Lbin/nt/main/BaseActivity; */
  /* dbg-move v103 v91 dv=Ljava/lang/Object; sv=Landroid/graphics/Bitmap; */
  /* dbg-move v104 v70 dv=Ljava/lang/Object; sv=[Landroid/graphics/Rect; */
  /* dbg-move v105 v92 dv=Ljava/lang/Object; sv=[F */
  env->CallVoidMethod((jobject)v101, env->GetMethodID(env->FindClass("I/ᅟ︎︀"), "<init>", "(Lbin/nt/main/BaseActivity;Landroid/graphics/Bitmap;Landroid/graphics/Paint;[Landroid/graphics/Rect;[FLandroid/graphics/Paint;)V"), v102, v103, v95, v104, v105, v96);
  env->CallVoidMethod((jobject)v100, env->GetMethodID(env->FindClass("android/view/View"), "setLayerType", "(ILandroid/graphics/Paint;)V"), v73, v74, v100, v100);
  v106 = env->AllocObject(env->FindClass("android/view/ViewGroup$LayoutParams"));
  v107 = -1;
  env->CallVoidMethod((jobject)v106, env->GetMethodID(env->FindClass("android/view/ViewGroup$LayoutParams"), "<init>", "(II)V"), v107, v107, v100, v100);
  env->CallVoidMethod((jobject)v90, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "addView", "(Landroid/view/View;Landroid/view/ViewGroup$LayoutParams;)V"), v100, v106, v100, v100);
  v108 = env->AllocObject(env->FindClass("I/ᅟ︁︁"));
  /* dbg-move v109 v108 dv=Ljava/lang/Object; sv=LI/ᅟ︁︁; */
  /* dbg-move v110 v100 dv=Ljava/lang/Object; sv=LI/ᅟ︎︀; */
  /* dbg-move v111 v91 dv=Ljava/lang/Object; sv=Landroid/graphics/Bitmap; */
  /* dbg-move v112 v92 dv=Ljava/lang/Object; sv=[F */
  /* dbg-move v113 v94 dv=Ljava/lang/Object; sv=[Z */
  env->CallVoidMethod((jobject)v109, env->GetMethodID(env->FindClass("I/ᅟ︁︁"), "<init>", "(Lbin/nt/main/BaseActivity;LI/ᅟ︎︀;Landroid/graphics/Bitmap;[F[Z)V"), v102, v110, v111, v112, v113);
  v114 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v100, env->GetMethodID(env->FindClass("android/view/View"), "post", "(Ljava/lang/Runnable;)Z"), v108, v100, v100, v100);
goto L_cb;

L_cb:
  /* return terminator */
  return;

EX_LandingPad_3:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_32;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︋︂(Lbin/nt/main/BaseActivity;II[Landroid/graphics/Rect;LI/ᅟ︈︈;)V -> Java_I__01160_0fe04_0fe09__0115f_0fe0b_0fe02__Lbin_nt_main_BaseActivity_2II_3Landroid_graphics_Rect_2LI__0115f_0fe08_0fe08_2 */

/* LI/ᅠ︅︂;-><init>(Lbin/nt/main/MainActivity;Landroid/view/MenuItem;Landroid/view/View;I)V */
void Java_I__01160_0fe05_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Landroid_view_MenuItem_2Landroid_view_View_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jint p3) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︅︂"), "ᅟ︄︀", "I"), v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︅︂"), "ᅟ︅︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︅︂"), "ᅟ︆︀", "Landroid/view/MenuItem;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︅︂"), "ᅟ︇︀", "Landroid/view/View;"), (jobject)(intptr_t)v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;Landroid/view/MenuItem;Landroid/view/View;I)V -> Java_I__01160_0fe05_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Landroid_view_MenuItem_2Landroid_view_View_2I */

/* LI/ᅠ︆︂;-><init>(Lbin/nt/main/MainActivity;)V */
void Java_I__01160_0fe06_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︆︂"), "ᅟ︄︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;)V -> Java_I__01160_0fe06_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2 */

/* FAILED LI/ᅠ︆︅;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_5 = phi[v0_4, v0_3] */

/* LI/ᅠ︆︈;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__01160_0fe06_0fe08__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v19 = NULL;
  jobject v23 = NULL;
  jobject v24 = NULL;
  jobject v3 = NULL;
  jobject v6 = NULL;
  jint v17 = 0;
  jint v4 = 0;
  jint v15 = 0;
  jobject v10 = NULL;
  jobject v12 = NULL;
  jobject v16 = NULL;
  jobject v1 = NULL;
  jobject v18 = NULL;
  jobject v8 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v22 = 0;
  jint v9 = 0;
  jobject v20 = NULL;
  jobject v25 = NULL;
  jobject v7 = NULL;
  jobject v14 = NULL;
  jint v11 = 0;
  jobject v21 = NULL;
  jint v5 = 0;
  jint v13 = 0;

L_0:
  v2 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v2, v2, v2, v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︆︈"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  v3 = env->AllocObject(env->FindClass("I/ᅟ︍︄"));
  v4 = 7;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︍︄"), "<init>", "(I)V"), v4, v3, v3, v3);
  v5 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︆︈"), "ᅟ︁︀", "I"), v5);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︆︈"), "ᅟ︂︀", "I"), v5);
  v6 = env->AllocObject(env->FindClass("I/ᅟ︈︆"));
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︈︆"), "<init>", "()V"), v3, v3, v3, v3);
  v7 = env->AllocObject(env->FindClass("I/ᅟ︍︄"));
  v8 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getClipboardManager", "()Landroid/content/ClipboardManager;"), v3, v3, v3, v3);
  v9 = 6;
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("I/ᅟ︍︄"), "<init>", "(I)V"), v9, v3, v3, v3);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︈︆"), "ᅟ︀︀", "(LI/ᅟ︍️;)V"), v7, v3, v3, v3);
  v10 = env->AllocObject(env->FindClass("I/ᅟ︍︄"));
  v11 = 8;
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("I/ᅟ︍︄"), "<init>", "(I)V"), v11, v3, v3, v3);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︈︆"), "ᅟ︀︀", "(LI/ᅟ︍️;)V"), v10, v3, v3, v3);
  v12 = env->AllocObject(env->FindClass("I/ᅟ︍︄"));
  v13 = 9;
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("I/ᅟ︍︄"), "<init>", "(I)V"), v13, v3, v3, v3);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︈︆"), "ᅟ︀︀", "(LI/ᅟ︍️;)V"), v12, v3, v3, v3);
  v14 = env->AllocObject(env->FindClass("I/ᅟ︍︄"));
  v15 = 10;
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("I/ᅟ︍︄"), "<init>", "(I)V"), v15, v3, v3, v3);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︈︆"), "ᅟ︀︀", "(LI/ᅟ︍️;)V"), v14, v3, v3, v3);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︈︆"), "ᅟ︀︀", "(LI/ᅟ︍️;)V"), v3, v3, v3, v3);
  v16 = env->AllocObject(env->FindClass("I/ᅠ︅︈"));
  v17 = 0;
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("I/ᅠ︅︈"), "<init>", "(LI/ᅠ︆︈;I)V"), v0, v17, v16, v16);
  v18 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v19 = env->FindClass("I/ᅠ︊︆");
  v20 = (jobject)env->CallObjectMethod((jobject)v18, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v19, v16, v16, v16);
  v21 = env->AllocObject(env->FindClass("I/ᅠ︅︈"));
  v22 = 1;
  env->CallVoidMethod((jobject)v21, env->GetMethodID(env->FindClass("I/ᅠ︅︈"), "<init>", "(LI/ᅠ︆︈;I)V"), v0, v22, v21, v21);
  v23 = (jobject)env->GetObjectField((jobject)(intptr_t)v23, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v24 = env->FindClass("I/ᅟ︀︇");
  v25 = (jobject)env->CallObjectMethod((jobject)v23, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v24, v21, v21, v21);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__01160_0fe06_0fe08__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅠ︆︉;-><init>(Lbin/nt/main/TextEditorActivity;I)V */
void Java_I__01160_0fe06_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︆︉"), "ᅟ︄︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︆︉"), "ᅟ︅︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;I)V -> Java_I__01160_0fe06_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I */

/* FAILED LI/ᅠ︇︄;-><init>(Lbin/nt/main/PhotoViewerActivity;Landroid/view/View;I)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅠ︇︉;-><init>(Lbin/nt/main/TextEditorActivity;I)V */
void Java_I__01160_0fe07_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v2 = 0;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︇︉"), "ᅟ︀︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︇︉"), "ᅟ︁︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;I)V -> Java_I__01160_0fe07_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I */

/* LI/ᅠ︈︂;-><init>(Lbin/nt/main/MainActivity;)V */
void Java_I__01160_0fe08_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jint v4 = 0;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jint v5 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︂"), "ᅟ︇︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  v2 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/view/ViewConfiguration"), env->GetStaticMethodID(env->FindClass("android/view/ViewConfiguration"), "get", "(Landroid/content/Context;)Landroid/view/ViewConfiguration;"), v1, v0, v0, v0, v0);
  v3 = v2;
  v4 = (jint)(intptr_t)env->CallIntMethod((jobject)v3, env->GetMethodID(env->FindClass("android/view/ViewConfiguration"), "getScaledTouchSlop", "()I"), v0, v0, v0, v0);
  v5 = v4;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︂"), "ᅟ︆︀", "I"), v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;)V -> Java_I__01160_0fe08_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2 */

/* LI/ᅠ︈︉;-><init>(Lbin/nt/main/TextEditorActivity;II)V */
void Java_I__01160_0fe08_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2II(JNIEnv* env, jobject thiz, jobject p0, jint p1, jint p2) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jint v3 = 0;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︉"), "ᅟ︄︀", "I"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︉"), "ᅟ︅︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︉"), "ᅟ︆︀", "I"), v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;II)V -> Java_I__01160_0fe08_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2II */

/* LI/ᅠ︊︉;-><init>(Lbin/nt/main/TextEditorActivity;I)V */
void Java_I__01160_0fe0a_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v2 = 0;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︊︉"), "ᅟ︄︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︊︉"), "ᅟ︅︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;I)V -> Java_I__01160_0fe0a_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I */

/* FAILED LI/ᅠ︌︀;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅠ︌︉;-><init>(Lbin/nt/main/TextEditorActivity;Landroid/widget/ProgressBar;I)V */
void Java_I__01160_0fe0c_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2Landroid_widget_ProgressBar_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jint p2) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jint v3 = 0;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︌︉"), "ᅟ︀︀", "I"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︌︉"), "ᅟ︂︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︌︉"), "ᅟ︁︀", "Landroid/widget/ProgressBar;"), (jobject)(intptr_t)v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;Landroid/widget/ProgressBar;I)V -> Java_I__01160_0fe0c_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2Landroid_widget_ProgressBar_2I */

/* FAILED LI/ᅠ︍︄;-><init>(Lbin/nt/fragments/PreferenceFragment;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅠ︍︈;->ᅟ︂︀(Lbin/nt/main/TextEditorActivity;)Ljava/lang/Object; */
jobject Java_I__01160_0fe0d_0fe08__0115f_0fe02_0fe00__Lbin_nt_main_TextEditorActivity_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = env->FindClass("android/view/inputmethod/InputMethodManager");
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Activity"), "getSystemService", "(Ljava/lang/Class;)Ljava/lang/Object;"), v1, v1, v1, v1);
  v3 = v2;
  /* return terminator */
  return (jobject)(intptr_t)v3;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︂︀(Lbin/nt/main/TextEditorActivity;)Ljava/lang/Object; -> Java_I__01160_0fe0d_0fe08__0115f_0fe02_0fe00__Lbin_nt_main_TextEditorActivity_2 */

/* LI/ᅠ︍︉;-><init>(Lbin/nt/main/TextEditorActivity;)V */
void Java_I__01160_0fe0d_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︉"), "ᅟ︄︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;)V -> Java_I__01160_0fe0d_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2 */

/* LI/ᅠ︍︊;-><init>(ILandroid/graphics/Paint$FontMetricsInt;IIIIIIFLbin/nt/editor/widget/CodeEditor;LI/ᅟ︌︉;LI/ᅠ︎︃;LI/ᅠ︎︃;Landroid/graphics/Paint$FontMetricsInt;)V */
void Java_I__01160_0fe0d_0fe0a__0003cinit_0003e__ILandroid_graphics_Paint_00024FontMetricsInt_2IIIIIIFLbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe0c_0fe09_2LI__01160_0fe0e_0fe03_2LI__01160_0fe0e_0fe03_2Landroid_graphics_Paint_00024FontMetricsInt_2(JNIEnv* env, jobject thiz, jint p0, jobject p1, jint p2, jint p3, jint p4, jint p5, jint p6, jint p7, jfloat p8, jobject p9, jobject p10, jobject p11, jobject p12, jobject p13) {
  jthrowable pendingException = NULL;
  jobject v12 = NULL;
  jobject v19 = NULL;
  jobject v20 = NULL;
  jobject v17 = NULL;
  jint v4 = 0;
  jobject v2 = NULL;
  jint v7 = 0;
  jobject v14 = NULL;
  jobject v11 = NULL;
  jobject v10 = NULL;
  jobject v15 = NULL;
  jint v8 = 0;
  jfloat v9 = 0;
  jint v3 = 0;
  jint v1 = 0;
  jint v6 = 0;
  jobject v16 = NULL;
  jobject v18 = NULL;
  jobject v13 = NULL;
  jobject v0 = NULL;
  jint v5 = 0;

L_0:
  v15 = env->NewStringUTF("textMetrics");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v2, v15, v15, v15, v15);
  v16 = env->NewStringUTF("inlayHintRendererProvider");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v10, v16, v16, v16, v16);
  v17 = env->NewStringUTF("colorScheme");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v11, v17, v17, v17, v17);
  v18 = env->NewStringUTF("miscPaint");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v12, v18, v18, v18, v18);
  v19 = env->NewStringUTF("graphPaint");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v13, v19, v19, v19, v19);
  v20 = env->NewStringUTF("graphMetrics");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v14, v20, v20, v20, v20);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v20, v20, v20, v20);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︀︀", "I"), v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︁︀", "Landroid/graphics/Paint$FontMetricsInt;"), (jobject)(intptr_t)v2);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︂︀", "I"), v3);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︃︀", "I"), v4);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︄︀", "I"), v5);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︅︀", "I"), v6);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︆︀", "I"), v7);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︇︀", "I"), v8);
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︈︀", "F"), v9);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︉︀", "LI/ᅟ︎️;"), (jobject)(intptr_t)v10);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︊︀", "LI/ᅟ︌︉;"), (jobject)(intptr_t)v11);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︋︀", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v12);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︌︀", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v13);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︍︊"), "ᅟ︍︀", "Landroid/graphics/Paint$FontMetricsInt;"), (jobject)(intptr_t)v14);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(ILandroid/graphics/Paint$FontMetricsInt;IIIIIIFLbin/nt/editor/widget/CodeEditor;LI/ᅟ︌︉;LI/ᅠ︎︃;LI/ᅠ︎︃;Landroid/graphics/Paint$FontMetricsInt;)V -> Java_I__01160_0fe0d_0fe0a__0003cinit_0003e__ILandroid_graphics_Paint_00024FontMetricsInt_2IIIIIIFLbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe0c_0fe09_2LI__01160_0fe0e_0fe03_2LI__01160_0fe0e_0fe03_2Landroid_graphics_Paint_00024FontMetricsInt_2 */

/* LI/ᅠ︎︆;->ᅟ︁︀(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︂︅;)LI/ᅟ︂︅; */
jobject Java_I__01160_0fe0e_0fe06__0115f_0fe01_0fe00__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe02_0fe05_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v5 = NULL;
  jobject v3 = NULL;
  jint v8 = 0;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jobject v7 = NULL;
  jobject v6 = NULL;

L_0:
  v3 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v3, v3, v3, v3);
  v4 = env->NewStringUTF("pos");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v2, v4, v4, v4, v4);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︎︆"), "computeFunc", "Lkotlin/jvm/functions/Function2;"));
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("kotlin/jvm/functions/Function2"), "ᅟ︎︀", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;"), v1, v2, v5, v5);
  v7 = v6;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅟ︂︅"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  /* return terminator */
  return (jobject)(intptr_t)v8;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︁︀(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︂︅;)LI/ᅟ︂︅; -> Java_I__01160_0fe0e_0fe06__0115f_0fe01_0fe00__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe02_0fe05_2 */

/* FAILED LI/ᅠ️︁;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Landroidx/appcompat/widget/PopupMenu;-><init>(Lbin/nt/main/BaseActivity;Landroid/view/View;I)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Landroidx/core/content/ContextCompat;->ᅟ︇︀(Landroid/content/Context;Lbin/nt/xapk/ApkInstallReceiver;Landroid/content/IntentFilter;)V */
void Java_androidx_core_content_ContextCompat__0115f_0fe07_0fe00__Landroid_content_Context_2Lbin_nt_xapk_ApkInstallReceiver_2Landroid_content_IntentFilter_2(JNIEnv* env, jclass clazz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v8 = NULL;
  jobject v19 = NULL;
  jobject v18 = NULL;
  jobject v2 = NULL;
  jobject v14 = NULL;
  jint v6 = 0;
  jobject v9 = NULL;
  jobject v13 = NULL;
  jobject v11 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jint v4 = 0;
  jobject v15 = NULL;
  jobject v17 = NULL;
  jint v5 = 0;
  jobject v10 = NULL;
  jint v7 = 0;
  jint v3 = 0;
  jint v12 = 0;
  jobject v16 = NULL;

L_0:
  v3 = (jint)(intptr_t)env->GetStaticIntField(env->FindClass("android/os/Build$VERSION"), env->GetStaticFieldID(env->FindClass("android/os/Build$VERSION"), "SDK_INT", "I"));
  v4 = 4;
  v5 = 33;
  v6 = 0;
  v7 = 0;
  /* UNSUPPORTED: if-lt */
  if (v3 < v5) { goto L_10;
 } else { goto L_9;
 }

L_9:
  /* dbg-move v8 v0 dv=Ljava/lang/Object; sv=Landroid/content/Context; */
  /* dbg-move v9 v1 dv=Ljava/lang/Object; sv=Lbin/nt/xapk/ApkInstallReceiver; */
  /* dbg-move v10 v2 dv=Ljava/lang/Object; sv=Landroid/content/IntentFilter; */
  v11 = (jobject)env->CallStaticObjectMethod(env->FindClass("androidx/core/content/ContextCompat$Api33Impl"), env->GetStaticMethodID(env->FindClass("androidx/core/content/ContextCompat$Api33Impl"), "ᅟ︀︀", "(Landroid/content/Context;Landroid/content/BroadcastReceiver;Landroid/content/IntentFilter;Ljava/lang/String;Landroid/os/Handler;I)Landroid/content/Intent;"), v8, v9, v10, v6, v7, v4);
  /* UNSUPPORTED: goto */
goto L_22;

L_10:
  v12 = 26;
  /* UNSUPPORTED: if-lt */
  if (v3 < v12) { goto L_1b;
 } else { goto L_14;
 }

L_14:
  /* dbg-move v13 v0 dv=Ljava/lang/Object; sv=Landroid/content/Context; */
  /* dbg-move v14 v1 dv=Ljava/lang/Object; sv=Lbin/nt/xapk/ApkInstallReceiver; */
  /* dbg-move v15 v2 dv=Ljava/lang/Object; sv=Landroid/content/IntentFilter; */
  v16 = (jobject)env->CallStaticObjectMethod(env->FindClass("androidx/core/content/ContextCompat$Api26Impl"), env->GetStaticMethodID(env->FindClass("androidx/core/content/ContextCompat$Api26Impl"), "ᅟ︀︀", "(Landroid/content/Context;Landroid/content/BroadcastReceiver;Landroid/content/IntentFilter;Ljava/lang/String;Landroid/os/Handler;I)Landroid/content/Intent;"), v13, v14, v15, v6, v7, v4);
  /* UNSUPPORTED: goto */
goto L_22;

L_1b:
  v17 = (jobject)env->CallStaticObjectMethod(env->FindClass("androidx/core/content/ContextCompat"), env->GetStaticMethodID(env->FindClass("androidx/core/content/ContextCompat"), "ᅟ︆︀", "(Landroid/content/Context;)Ljava/lang/String;"), v0, v3, v3, v3, v3);
  v18 = v17;
  v19 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "registerReceiver", "(Landroid/content/BroadcastReceiver;Landroid/content/IntentFilter;Ljava/lang/String;Landroid/os/Handler;)Landroid/content/Intent;"), v1, v2, v18, v7);
goto L_22;

L_22:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︇︀(Landroid/content/Context;Lbin/nt/xapk/ApkInstallReceiver;Landroid/content/IntentFilter;)V -> Java_androidx_core_content_ContextCompat__0115f_0fe07_0fe00__Landroid_content_Context_2Lbin_nt_xapk_ApkInstallReceiver_2Landroid_content_IntentFilter_2 */

/* Lbin/nt/main/App;-><init>()V */
void Java_bin_nt_main_App__0003cinit_0003e__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Application"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>()V -> Java_bin_nt_main_App__0003cinit_0003e__ */

/* Lbin/nt/main/App;->ᅟ︀︀(Ljava/lang/String;)V */
void Java_bin_nt_main_App__0115f_0fe00_0fe00__Ljava_lang_String_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jobject v14 = NULL;
  jobject v1 = NULL;
  jobject v10 = NULL;
  jobject v13 = NULL;
  jobject v4 = NULL;
  jboolean v7 = 0;
  jobject v2 = NULL;
  jboolean v6 = 0;
  jobject v8 = NULL;
  jobject v9 = NULL;
  jboolean v5 = 0;
  jobject v11 = NULL;
  jobject v12 = NULL;
  jint v15 = 0;

L_0:
  v1 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  v2 = (jobject)env->CallStaticObjectMethod(env->FindClass("bin/nt/main/App"), env->GetStaticMethodID(env->FindClass("bin/nt/main/App"), "ᅟ︃︀", "()Ljava/io/File;"), v1, v1, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v3 = v2;
  v4 = env->AllocObject(env->FindClass("java/io/File")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/io/File;Ljava/lang/String;)V"), v3, v0, v3, v3); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v5 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("java/io/File"), "exists", "()Z"), v3, v3, v3, v3); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v6 = v5;
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { goto L_15;
 } else { goto L_14;
 }

L_14:
  /* return terminator */
  return;

L_15:
  v7 = (jboolean)(intptr_t)env->CallStaticBooleanMethod(env->FindClass("bin/nt/main/App"), env->GetStaticMethodID(env->FindClass("bin/nt/main/App"), "ᅟ︂︀", "(Ljava/io/File;)Z"), v4, v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
goto L_18;

L_19:
  v8 = pendingException;
  v9 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  v10 = env->NewStringUTF("Failed to clean work directory: ");
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "(Ljava/lang/String;)V"), v10, v8, v8, v8);
  v11 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v0, v8, v8, v8);
  v12 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v8, v8, v8, v8);
  v13 = v12;
  v14 = env->NewStringUTF("App");
  v15 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/util/Log"), env->GetStaticMethodID(env->FindClass("android/util/Log"), "e", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)I"), v14, v13, v8, v8, v8);
  /* return terminator */
  return;

L_18:
  /* return terminator */
  return;

EX_LandingPad_0:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_19;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︀︀(Ljava/lang/String;)V -> Java_bin_nt_main_App__0115f_0fe00_0fe00__Ljava_lang_String_2 */

/* FAILED Lbin/nt/main/App;->ᅟ︁︀(Ljava/io/File;Ljava/io/File;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/App;->ᅟ︂︀(Ljava/io/File;)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/App;->ᅟ︃︀()Ljava/io/File; */
jobject Java_bin_nt_main_App__0115f_0fe03_0fe00__(JNIEnv* env, jclass clazz) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v2 = NULL;
  jint v1 = 0;
  jobject v0 = NULL;
  jobject v4 = NULL;

L_0:
  v0 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  v1 = 0;
  /* UNSUPPORTED: if-nez */
  if (v0 != 0) { goto L_6;
 } else { goto L_5;
 }

L_5:
  /* return terminator */
  return (jobject)(intptr_t)v1;

L_6:
  v2 = env->AllocObject(env->FindClass("java/io/File"));
  v3 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("android/content/Context"), "getExternalFilesDir", "(Ljava/lang/String;)Ljava/io/File;"), v1, v2, v2, v2);
  v5 = v4;
  v6 = env->NewStringUTF("CleanOnExit");
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/io/File;Ljava/lang/String;)V"), v5, v6, v2, v2);
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︃︀()Ljava/io/File; -> Java_bin_nt_main_App__0115f_0fe03_0fe00__ */

/* Lbin/nt/main/App;->ᅟ︄︀(Ljava/lang/String;)Ljava/io/File; */
jobject Java_bin_nt_main_App__0115f_0fe04_0fe00__Ljava_lang_String_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v4 = NULL;
  jobject v0 = NULL;
  jobject v9 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jboolean v6 = 0;
  jobject v8 = NULL;
  jboolean v5 = 0;
  jobject v1 = NULL;
  jboolean v7 = 0;

L_0:
  v1 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_17;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->CallStaticObjectMethod(env->FindClass("bin/nt/main/App"), env->GetStaticMethodID(env->FindClass("bin/nt/main/App"), "ᅟ︃︀", "()Ljava/io/File;"), v1, v1, v1, v1, v1);
  v3 = v2;
  v4 = env->AllocObject(env->FindClass("java/io/File"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/io/File;Ljava/lang/String;)V"), v3, v0, v3, v3);
  v5 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("java/io/File"), "exists", "()Z"), v3, v3, v3, v3);
  v6 = v5;
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { goto L_16;
 } else { goto L_13;
 }

L_13:
  v7 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("java/io/File"), "mkdirs", "()Z"), v3, v3, v3, v3);
goto L_16;

L_16:
  /* return terminator */
  return (jobject)(intptr_t)v4;

L_17:
  v8 = env->AllocObject(env->FindClass("java/lang/IllegalStateException"));
  v9 = env->NewStringUTF("App instance not initialized");
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/IllegalStateException"), "<init>", "(Ljava/lang/String;)V"), v9, v9, v9, v9);
  pendingException = (jthrowable)v8; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︄︀(Ljava/lang/String;)Ljava/io/File; -> Java_bin_nt_main_App__0115f_0fe04_0fe00__Ljava_lang_String_2 */

/* FAILED Lbin/nt/main/App;->ᅟ︅︀(Ljava/lang/String;)Ljava/io/File;: java.lang.StackOverflowError */

/* FAILED Lbin/nt/main/App;->ᅟ︆︀(Ljava/io/File;)Ljava/lang/String;: java.lang.IllegalStateException: unknown phi type v5_2 = phi[] */

/* FAILED Lbin/nt/main/App;->onCreate()V: java.lang.IllegalStateException: unknown phi type v1_31 = phi[v1_14 = phi[v1_8 = phi[v1_4 = phi[v1_2, v1_2], v1_4 = phi[v1_2, v1_2]]], v1_14 = phi[v1_8 = phi[v1_4 = phi[v1_2, v1_2], v1_4 = phi[v1_2, v1_2]]], v1_34 = phi[v1_14 = phi[v1_8 = phi[v1_4 = phi[v1_2, v1_2], v1_4 = phi[v1_2, v1_2]]]]] */

/* Lbin/nt/main/App;->ᅟ︇︀(Ljava/lang/String;)V */
void Java_bin_nt_main_App__0115f_0fe07_0fe00__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jint v6 = 0;
  jint v8 = 0;
  jobject v4 = NULL;
  jobject v7 = NULL;
  jobject v5 = NULL;
  jobject v1 = NULL;
  jint v10 = 0;
  jint v9 = 0;
  jobject v2 = NULL;

L_0:
  v2 = env->AllocObject(env->FindClass("android/content/Intent"));
  v3 = env->FindClass("bin/nt/main/CrashActivity");
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/content/Intent"), "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V"), v0, v3, v2, v2);
  v4 = env->NewStringUTF("crash_log");
  v5 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("android/content/Intent"), "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;"), v4, v1, v2, v2);
  v6 = 268468224;
  v7 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("android/content/Intent"), "addFlags", "(I)Landroid/content/Intent;"), v6, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "startActivity", "(Landroid/content/Intent;)V"), v2, v2, v2, v2);
  v8 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/os/Process"), env->GetStaticMethodID(env->FindClass("android/os/Process"), "myPid", "()I"), v2, v2, v2, v2, v2);
  v9 = v8;
  env->CallStaticVoidMethod(env->FindClass("android/os/Process"), env->GetStaticMethodID(env->FindClass("android/os/Process"), "killProcess", "(I)V"), v9, v2, v2, v2, v2);
  v10 = 1;
  env->CallStaticVoidMethod(env->FindClass("java/lang/System"), env->GetStaticMethodID(env->FindClass("java/lang/System"), "exit", "(I)V"), v10, v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︇︀(Ljava/lang/String;)V -> Java_bin_nt_main_App__0115f_0fe07_0fe00__Ljava_lang_String_2 */

/* FAILED Lbin/nt/ui/PanelView;-><init>(Landroid/content/Context;Landroid/util/AttributeSet;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/ui/PanelView;->dispatchTouchEvent(Landroid/view/MotionEvent;)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/ui/PanelView;->getLinearLayoutManager()Landroidx/recyclerview/widget/LinearLayoutManager; */
jobject Java_bin_nt_ui_PanelView_getLinearLayoutManager__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jint v4 = 0;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︅︀", "Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;"));
  v2 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "getLayoutManager", "()Landroidx/recyclerview/widget/RecyclerView$LayoutManager;"), v1, v1, v1, v1);
  v3 = v2;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  /* return terminator */
  return (jobject)(intptr_t)v4;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLinearLayoutManager()Landroidx/recyclerview/widget/LinearLayoutManager; -> Java_bin_nt_ui_PanelView_getLinearLayoutManager__ */

/* Lbin/nt/ui/PanelView;->getRecyclerView()Landroidx/recyclerview/widget/RecyclerView; */
jobject Java_bin_nt_ui_PanelView_getRecyclerView__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︅︀", "Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getRecyclerView()Landroidx/recyclerview/widget/RecyclerView; -> Java_bin_nt_ui_PanelView_getRecyclerView__ */

/* Lbin/nt/ui/PanelView;->setJellyColor(I)V */
void Java_bin_nt_ui_PanelView_setJellyColor__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︄︀", "Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "setJellyColor", "(I)V"), v1, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setJellyColor(I)V -> Java_bin_nt_ui_PanelView_setJellyColor__I */

/* Lbin/nt/ui/PanelView;->setOnPanelTouchedListener(LI/ᅠ️︃;)V */
void Java_bin_nt_ui_PanelView_setOnPanelTouchedListener__LI__01160_0fe0f_0fe03_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︆︀", "LI/ᅠ️︃;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setOnPanelTouchedListener(LI/ᅠ️︃;)V -> Java_bin_nt_ui_PanelView_setOnPanelTouchedListener__LI__01160_0fe0f_0fe03_2 */

/* Lbin/nt/ui/PanelView;->setPanelBackground(I)V */
void Java_bin_nt_ui_PanelView_setPanelBackground__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v1, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setPanelBackground(I)V -> Java_bin_nt_ui_PanelView_setPanelBackground__I */

/* Lbin/nt/ui/PanelView;->setPullToRefreshListener(LI/ᅠ︁︅;)V */
void Java_bin_nt_ui_PanelView_setPullToRefreshListener__LI__01160_0fe01_0fe05_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︄︀", "Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅠ︃︅"), "setPullToRefreshListener", "(LI/ᅠ︁︅;)V"), v1, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setPullToRefreshListener(LI/ᅠ︁︅;)V -> Java_bin_nt_ui_PanelView_setPullToRefreshListener__LI__01160_0fe01_0fe05_2 */

/* Lbin/nt/ui/PanelView;->setRefreshing(Z)V */
void Java_bin_nt_ui_PanelView_setRefreshing__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︄︀", "Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "setRefreshing", "(Z)V"), v1, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setRefreshing(Z)V -> Java_bin_nt_ui_PanelView_setRefreshing__Z */

/* FAILED Lbin/nt/ui/PanelView;->ᅟ︀︀(I)I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/ui/PanelView;->ᅟ︁︀(LI/ᅟ︁︍;Z)V */
void Java_bin_nt_ui_PanelView__0115f_0fe01_0fe00__LI__0115f_0fe01_0fe0d_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jboolean v2 = 0;
  jobject v7 = NULL;
  jobject v0 = NULL;
  jint v8 = 0;
  jobject v4 = NULL;
  jobject v9 = NULL;
  jobject v6 = NULL;
  jobject v1 = NULL;
  jint v5 = 0;
  jobject v3 = NULL;

L_0:
  v3 = env->AllocObject(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"));
  v4 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v5 = 1;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"), "<init>", "(I)V"), v5, v3, v3, v3);
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︅︀", "Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;"));
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "setLayoutManager", "(Landroidx/recyclerview/widget/RecyclerView$LayoutManager;)V"), v3, v3, v3, v3);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "setAdapter", "(Landroidx/recyclerview/widget/RecyclerView$Adapter;)V"), v1, v3, v3, v3);
  v7 = env->AllocObject(env->FindClass("androidx/recyclerview/widget/DefaultItemAnimator"));
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/DefaultItemAnimator"), "<init>", "()V"), v3, v3, v3, v3);
  v8 = 0;
  env->SetBooleanField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/SimpleItemAnimator"), "ᅟ︆︀", "Z"), v8);
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "setItemAnimator", "(Landroidx/recyclerview/widget/RecyclerView$ItemAnimator;)V"), v7, v8, v8, v8);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/PanelView"), "ᅟ︄︀", "Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;"));
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "setSweepDirection", "(Z)V"), v2, v8, v8, v8);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︀(LI/ᅟ︁︍;Z)V -> Java_bin_nt_ui_PanelView__0115f_0fe01_0fe00__LI__0115f_0fe01_0fe0d_2Z */

/* FAILED Lbin/nt/ui/animation/InnerShadow;-><init>(Landroid/content/Context;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/ui/animation/InnerShadow;-><init>(Landroid/content/Context;Landroid/util/AttributeSet;)V */
void Java_bin_nt_ui_animation_InnerShadow__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jint v4 = 0;
  jint v7 = 0;
  jobject v3 = NULL;
  jint v6 = 0;
  jobject v0 = NULL;
  jint v5 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;)V"), v1, v2, v0, v0);
  v3 = env->AllocObject(env->FindClass("android/graphics/Paint"));
  v4 = 1;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/graphics/Paint"), "<init>", "(I)V"), v4, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︄︀", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v3);
  v5 = 10;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︅︀", "I"), v5);
  v6 = 80;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︆︀", "I"), v6);
  v7 = -16777216;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︇︀", "I"), v7);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︈︀", "Z"), v4);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︉︀", "Z"), v4);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︊︀", "Z"), v4);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︋︀", "Z"), v4);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Landroid/content/Context;Landroid/util/AttributeSet;)V -> Java_bin_nt_ui_animation_InnerShadow__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2 */

/* Lbin/nt/ui/animation/InnerShadow;->onDraw(Landroid/graphics/Canvas;)V */
void Java_bin_nt_ui_animation_InnerShadow_onDraw__Landroid_graphics_Canvas_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v11 = 0;
  jlong v68 = 0;
  jint v96 = 0;
  jobject v1 = NULL;
  jint v8 = 0;
  jlong v74 = 0;
  jint v9 = 0;
  jboolean v36 = 0;
  jint v15 = 0;
  jlong v71 = 0;
  jobject v22 = NULL;
  jint v39 = 0;
  jlong v94 = 0;
  jlong v72 = 0;
  jboolean v73 = 0;
  jobject v48 = NULL;
  jint v56 = 0;
  jint v20 = 0;
  jint v58 = 0;
  jobject v64 = NULL;
  jobject v2 = NULL;
  jint v84 = 0;
  jint v80 = 0;
  jobject v75 = NULL;
  jint v28 = 0;
  jobject v32 = NULL;
  jfloat v51 = 0;
  jobject v33 = NULL;
  jobject v86 = NULL;
  jobject v29 = NULL;
  jobject v61 = NULL;
  jint v82 = 0;
  jlong v99 = 0;
  jint v14 = 0;
  jobject v65 = NULL;
  jfloat v30 = 0;
  jint v60 = 0;
  jint v13 = 0;
  jobject v25 = NULL;
  jobject v78 = NULL;
  jobject v87 = NULL;
  jboolean v53 = 0;
  jint v59 = 0;
  jlong v93 = 0;
  jlong v91 = 0;
  jfloat v45 = 0;
  jint v62 = 0;
  jobject v34 = NULL;
  jfloat v35 = 0;
  jlong v92 = 0;
  jint v6 = 0;
  jlong v69 = 0;
  jobject v40 = NULL;
  jlong v70 = 0;
  jint v18 = 0;
  jint v16 = 0;
  jint v19 = 0;
  jint v41 = 0;
  jint v90 = 0;
  jlong v98 = 0;
  jint v46 = 0;
  jobject v49 = NULL;
  jobject v57 = NULL;
  jobject v97 = NULL;
  jlong v95 = 0;
  jint v3 = 0;
  jobject v81 = NULL;
  jobject v0 = NULL;
  jobject v37 = NULL;
  jfloat v76 = 0;
  jobject v55 = NULL;
  jint v63 = 0;
  jint v67 = 0;
  jfloat v38 = 0;
  jint v42 = 0;
  jint v26 = 0;
  jint v24 = 0;
  jobject v23 = NULL;
  jint v31 = 0;
  jobject v47 = NULL;
  jfloat v50 = 0;
  jint v12 = 0;
  jfloat v88 = 0;
  jfloat v4 = 0;
  jobject v43 = NULL;
  jint v77 = 0;
  jint v5 = 0;
  jlong v54 = 0;
  jobject v85 = NULL;
  jfloat v44 = 0;
  jint v79 = 0;
  jfloat v52 = 0;
  jfloat v7 = 0;
  jint v27 = 0;
  jboolean v21 = 0;
  jint v89 = 0;
  jfloat v83 = 0;
  jfloat v10 = 0;
  jint v17 = 0;
  jobject v66 = NULL;

L_0:
  /* dbg-move v2 v0 dv=Ljava/lang/Object; sv=Lbin/nt/ui/animation/InnerShadow; */
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "onDraw", "(Landroid/graphics/Canvas;)V"), v1);
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︅︀", "I"));
  v4 = (jfloat)v4;
  v5 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"));
  v6 = v5;
  v7 = (jfloat)v6;
  v8 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getHeight", "()I"));
  v9 = v8;
  v10 = (jfloat)v9;
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︇︀", "I"));
  v12 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/graphics/Color"), env->GetStaticMethodID(env->FindClass("android/graphics/Color"), "red", "(I)I"), v11, v2, v2, v2, v2);
  v13 = v12;
  v14 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/graphics/Color"), env->GetStaticMethodID(env->FindClass("android/graphics/Color"), "green", "(I)I"), v11, v2, v2, v2, v2);
  v15 = v14;
  v16 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/graphics/Color"), env->GetStaticMethodID(env->FindClass("android/graphics/Color"), "blue", "(I)I"), v11, v2, v2, v2, v2);
  v17 = v16;
  v18 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︆︀", "I"));
  v19 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/graphics/Color"), env->GetStaticMethodID(env->FindClass("android/graphics/Color"), "argb", "(IIII)I"), v18, v13, v15, v17, v2);
  v20 = v19;
  v21 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︈︀", "Z"));
  v22 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︄︀", "Landroid/graphics/Paint;"));
  /* UNSUPPORTED: if-eqz */
  if (v21 == 0) { goto L_45;
 } else { goto L_2c;
 }

L_2c:
  v23 = env->AllocObject(env->FindClass("android/graphics/LinearGradient"));
  v24 = 0;
  v25 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Shader$TileMode"), env->GetStaticFieldID(env->FindClass("android/graphics/Shader$TileMode"), "CLAMP", "Landroid/graphics/Shader$TileMode;"));
  v26 = 0;
  v27 = 0;
  v28 = 0;
  /* dbg-move v29 v23 dv=Ljava/lang/Object; sv=Landroid/graphics/LinearGradient; */
  /* dbg-move v30 v4 dv=F sv=F */
  /* dbg-move v31 v20 dv=I sv=I */
  env->CallVoidMethod((jobject)v29, env->GetMethodID(env->FindClass("android/graphics/LinearGradient"), "<init>", "(FFFFIILandroid/graphics/Shader$TileMode;)V"), v26, v27, v28, v30, v31, v24, v25);
  v32 = (jobject)env->CallObjectMethod((jobject)v22, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setShader", "(Landroid/graphics/Shader;)Landroid/graphics/Shader;"), v23, v2, v2, v2);
  v33 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︄︀", "Landroid/graphics/Paint;"));
  /* dbg-move v34 v1 dv=Ljava/lang/Object; sv=Landroid/graphics/Canvas; */
  /* dbg-move v35 v7 dv=F sv=F */
  env->CallVoidMethod((jobject)v34, env->GetMethodID(env->FindClass("android/graphics/Canvas"), "drawRect", "(FFFFLandroid/graphics/Paint;)V"), v26, v27, v35, v30, v33);
goto L_45;

L_45:
  v36 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︉︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v36 == 0) { goto L_66;
 } else { goto L_49;
 }

L_49:
  v37 = env->AllocObject(env->FindClass("android/graphics/LinearGradient"));
  /* UNSUPPORTED: sub-float */
  v39 = 0;
  v40 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Shader$TileMode"), env->GetStaticFieldID(env->FindClass("android/graphics/Shader$TileMode"), "CLAMP", "Landroid/graphics/Shader$TileMode;"));
  v41 = 0;
  v42 = 0;
  /* dbg-move v43 v37 dv=Ljava/lang/Object; sv=Landroid/graphics/LinearGradient; */
  /* dbg-move v44 v10 dv=F sv=F */
  /* dbg-move v45 v38 dv=F sv=F */
  /* dbg-move v46 v20 dv=I sv=I */
  env->CallVoidMethod((jobject)v43, env->GetMethodID(env->FindClass("android/graphics/LinearGradient"), "<init>", "(FFFFIILandroid/graphics/Shader$TileMode;)V"), v41, v44, v42, v45, v46, v39, v40);
  v47 = (jobject)env->CallObjectMethod((jobject)v22, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setShader", "(Landroid/graphics/Shader;)Landroid/graphics/Shader;"), v37, v2, v2, v2);
  v48 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︄︀", "Landroid/graphics/Paint;"));
  /* dbg-move v49 v1 dv=Ljava/lang/Object; sv=Landroid/graphics/Canvas; */
  /* dbg-move v50 v38 dv=F sv=F */
  /* dbg-move v51 v7 dv=F sv=F */
  /* dbg-move v52 v10 dv=F sv=F */
  env->CallVoidMethod((jobject)v49, env->GetMethodID(env->FindClass("android/graphics/Canvas"), "drawRect", "(FFFFLandroid/graphics/Paint;)V"), v41, v50, v51, v52, v48);
goto L_66;

L_66:
  v53 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v54, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︊︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v53 == 0) { goto L_83;
 } else { goto L_6a;
 }

L_6a:
  v55 = env->AllocObject(env->FindClass("android/graphics/LinearGradient"));
  v56 = 0;
  v57 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Shader$TileMode"), env->GetStaticFieldID(env->FindClass("android/graphics/Shader$TileMode"), "CLAMP", "Landroid/graphics/Shader$TileMode;"));
  v58 = 0;
  v59 = 0;
  v60 = 0;
  /* dbg-move v61 v55 dv=Ljava/lang/Object; sv=Landroid/graphics/LinearGradient; */
  /* dbg-move v62 v68 dv=I sv=null */
  /* dbg-move v63 v69 dv=I sv=null */
  env->CallVoidMethod((jobject)v61, env->GetMethodID(env->FindClass("android/graphics/LinearGradient"), "<init>", "(FFFFIILandroid/graphics/Shader$TileMode;)V"), v58, v59, v62, v60, v63, v56, v57);
  v64 = (jobject)env->CallObjectMethod((jobject)v70, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setShader", "(Landroid/graphics/Shader;)Landroid/graphics/Shader;"), v55, v54, v54, v54);
  v65 = (jobject)env->GetObjectField((jobject)(intptr_t)v54, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︄︀", "Landroid/graphics/Paint;"));
  /* dbg-move v66 v71 dv=Ljava/lang/Object; sv=null */
  /* dbg-move v67 v72 dv=I sv=null */
  env->CallVoidMethod((jobject)v66, env->GetMethodID(env->FindClass("android/graphics/Canvas"), "drawRect", "(FFFFLandroid/graphics/Paint;)V"), v58, v59, v62, v67, v65);
goto L_83;

L_83:
  v73 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v74, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︋︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v73 == 0) { goto L_a4;
 } else { goto L_87;
 }

L_87:
  v75 = env->AllocObject(env->FindClass("android/graphics/LinearGradient"));
  /* UNSUPPORTED: sub-float */
  v77 = 0;
  v78 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Shader$TileMode"), env->GetStaticFieldID(env->FindClass("android/graphics/Shader$TileMode"), "CLAMP", "Landroid/graphics/Shader$TileMode;"));
  v79 = 0;
  v80 = 0;
  /* dbg-move v81 v75 dv=Ljava/lang/Object; sv=Landroid/graphics/LinearGradient; */
  /* dbg-move v82 v91 dv=I sv=null */
  /* dbg-move v83 v76 dv=F sv=F */
  /* dbg-move v84 v92 dv=I sv=null */
  env->CallVoidMethod((jobject)v81, env->GetMethodID(env->FindClass("android/graphics/LinearGradient"), "<init>", "(FFFFIILandroid/graphics/Shader$TileMode;)V"), v82, v79, v83, v80, v84, v77, v78);
  v85 = (jobject)env->CallObjectMethod((jobject)v93, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setShader", "(Landroid/graphics/Shader;)Landroid/graphics/Shader;"), v75, v74, v74, v74);
  v86 = (jobject)env->GetObjectField((jobject)(intptr_t)v74, env->GetFieldID(env->FindClass("bin/nt/ui/animation/InnerShadow"), "ᅟ︄︀", "Landroid/graphics/Paint;"));
  /* dbg-move v87 v94 dv=Ljava/lang/Object; sv=null */
  /* dbg-move v88 v76 dv=F sv=F */
  /* dbg-move v89 v91 dv=I sv=null */
  /* dbg-move v90 v95 dv=I sv=null */
  env->CallVoidMethod((jobject)v87, env->GetMethodID(env->FindClass("android/graphics/Canvas"), "drawRect", "(FFFFLandroid/graphics/Paint;)V"), v88, v79, v89, v90, v86);
goto L_a4;

L_a4:
  v96 = 0;
  v97 = (jobject)env->CallObjectMethod((jobject)v98, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setShader", "(Landroid/graphics/Shader;)Landroid/graphics/Shader;"), v96, v99, v99, v99);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for onDraw(Landroid/graphics/Canvas;)V -> Java_bin_nt_ui_animation_InnerShadow_onDraw__Landroid_graphics_Canvas_2 */

/* Lbin/nt/xapk/ApkInstallReceiver;-><init>()V */
void Java_bin_nt_xapk_ApkInstallReceiver__0003cinit_0003e__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/BroadcastReceiver"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>()V -> Java_bin_nt_xapk_ApkInstallReceiver__0003cinit_0003e__ */

/* FAILED Lbin/nt/xapk/ApkInstallReceiver;->onReceive(Landroid/content/Context;Landroid/content/Intent;)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* LI/ᅟ︀︇;-><init>(Lbin/nt/editor/widget/CodeEditor;ILI/ᅟ︂︅;LI/ᅟ︂︅;Ljava/lang/CharSequence;Z)V */
void Java_I__0115f_0fe00_0fe07__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2ILI__0115f_0fe02_0fe05_2LI__0115f_0fe02_0fe05_2Ljava_lang_CharSequence_2Z(JNIEnv* env, jobject thiz, jobject p0, jint p1, jobject p2, jobject p3, jobject p4, jboolean p5) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jboolean v6 = 0;
  jobject v5 = NULL;
  jobject v3 = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jobject v4 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︇"), "ᅟ︂︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︇"), "ᅟ︄︀", "LI/ᅟ︂︅;"), (jobject)(intptr_t)v4);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︇"), "ᅟ︅︀", "Z"), v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;ILI/ᅟ︂︅;LI/ᅟ︂︅;Ljava/lang/CharSequence;Z)V -> Java_I__0115f_0fe00_0fe07__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2ILI__0115f_0fe02_0fe05_2LI__0115f_0fe02_0fe05_2Ljava_lang_CharSequence_2Z */

/* FAILED LI/ᅟ︀︊;-><init>(Lbin/nt/editor/widget/CodeEditor;I)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* LI/ᅟ︀︌;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe00_0fe0c__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v8 = NULL;
  jint v35 = 0;
  jint v54 = 0;
  jobject v61 = NULL;
  jobject v0 = NULL;
  jobject v26 = NULL;
  jobject v59 = NULL;
  jobject v67 = NULL;
  jobject v5 = NULL;
  jobject v57 = NULL;
  jobject v68 = NULL;
  jobject v60 = NULL;
  jobject v11 = NULL;
  jobject v53 = NULL;
  jobject v4 = NULL;
  jobject v73 = NULL;
  jint v3 = 0;
  jint v23 = 0;
  jint v28 = 0;
  jint v16 = 0;
  jint v44 = 0;
  jobject v10 = NULL;
  jint v19 = 0;
  jint v42 = 0;
  jint v13 = 0;
  jint v74 = 0;
  jint v24 = 0;
  jobject v34 = NULL;
  jobject v51 = NULL;
  jobject v75 = NULL;
  jobject v47 = NULL;
  jobject v49 = NULL;
  jobject v15 = NULL;
  jobject v43 = NULL;
  jobject v7 = NULL;
  jint v2 = 0;
  jobject v9 = NULL;
  jint v20 = 0;
  jobject v36 = NULL;
  jobject v18 = NULL;
  jobject v21 = NULL;
  jobject v29 = NULL;
  jobject v30 = NULL;
  jobject v22 = NULL;
  jobject v45 = NULL;
  jobject v48 = NULL;
  jobject v52 = NULL;
  jobject v71 = NULL;
  jobject v76 = NULL;
  jint v31 = 0;
  jint v58 = 0;
  jobject v33 = NULL;
  jobject v1 = NULL;
  jint v70 = 0;
  jobject v6 = NULL;
  jfloat v40 = 0;
  jint v46 = 0;
  jobject v64 = NULL;
  jobject v25 = NULL;
  jint v39 = 0;
  jobject v56 = NULL;
  jobject v69 = NULL;
  jobject v72 = NULL;
  jfloat v37 = 0;
  jint v12 = 0;
  jobject v14 = NULL;
  jfloat v41 = 0;
  jint v62 = 0;
  jobject v55 = NULL;
  jobject v17 = NULL;
  jint v32 = 0;
  jfloat v38 = 0;
  jobject v65 = NULL;
  jint v50 = 0;
  jint v27 = 0;
  jobject v63 = NULL;
  jint v66 = 0;

L_0:
  v2 = 2;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ️︊"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;I)V"), v1, v2, v2, v2);
  v3 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︎︁", "Z"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︂︁", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  v4 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getEventHandler", "()LI/ᅟ︄︌;"), v3, v3, v3, v3);
  v5 = v4;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︉︁", "LI/ᅟ︄︌;"), (jobject)(intptr_t)v5);
  v6 = env->AllocObject(env->FindClass("I/ᅟ︋︌"));
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "<init>", "(LI/ᅟ︋︌;)V"), v7, v6, v6, v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︊︁", "LI/ᅟ︋︌;"), (jobject)(intptr_t)v6);
  v8 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v6, v6, v6, v6);
  v9 = v8;
  v10 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/view/LayoutInflater"), env->GetStaticMethodID(env->FindClass("android/view/LayoutInflater"), "from", "(Landroid/content/Context;)Landroid/view/LayoutInflater;"), v9, v6, v6, v6, v6);
  v11 = v10;
  v12 = 2131558556;
  v13 = 0;
  v14 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/view/LayoutInflater"), "inflate", "(ILandroid/view/ViewGroup;)Landroid/view/View;"), v12, v13, v6, v6);
  v15 = v14;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︈︁", "Landroid/view/View;"), (jobject)(intptr_t)v15);
  v16 = 2131362201;
  v17 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v16, v6, v6, v6);
  v18 = v17;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ImageButton"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︃︁", "Landroid/widget/ImageButton;"), (jobject)(intptr_t)v19);
  v20 = 2131362198;
  v21 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v20, v6, v6, v6);
  v22 = v21;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ImageButton"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︆︁", "Landroid/widget/ImageButton;"), (jobject)(intptr_t)v23);
  v24 = 2131362197;
  v25 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v24, v6, v6, v6);
  v26 = v25;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ImageButton"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︅︁", "Landroid/widget/ImageButton;"), (jobject)(intptr_t)v27);
  v28 = 2131362199;
  v29 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v28, v6, v6, v6);
  v30 = v29;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ImageButton"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︇︁", "Landroid/widget/ImageButton;"), (jobject)(intptr_t)v31);
  v32 = 2131362200;
  v33 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v32, v6, v6, v6);
  v34 = v33;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ImageButton"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︀︌"), "ᅟ︄︁", "Landroid/widget/ImageButton;"), (jobject)(intptr_t)v35);
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v0, v6, v6, v6);
  env->CallVoidMethod((jobject)v23, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v0, v6, v6, v6);
  env->CallVoidMethod((jobject)v27, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v0, v6, v6, v6);
  env->CallVoidMethod((jobject)v35, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v0, v6, v6, v6);
  env->CallVoidMethod((jobject)v31, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v0, v6, v6, v6);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︀︌"), "ᅟ︄︀", "()V"), v6, v6, v6, v6);
  v36 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︄︀", "Landroid/widget/PopupWindow;"));
  env->CallVoidMethod((jobject)v36, env->GetMethodID(env->FindClass("android/widget/PopupWindow"), "setContentView", "(Landroid/view/View;)V"), v15, v6, v6, v6);
  v37 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v1, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getDpUnit", "()F"), v6, v6, v6, v6);
  v38 = v37;
  v39 = 1111490560;
  /* UNSUPPORTED: mul-float */
  v41 = (jint)v41;
  v42 = 0;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︀︁", "I"), v42);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︁︁", "I"), v41);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ️︊"), "ᅟ︀︀", "(Z)V"), v42, v6, v6, v6);
  v43 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︄︀", "Landroid/widget/PopupWindow;"));
  v44 = 2131952802;
  env->CallVoidMethod((jobject)v43, env->GetMethodID(env->FindClass("android/widget/PopupWindow"), "setAnimationStyle", "(I)V"), v44, v6, v6, v6);
  v45 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v46 = 0;
  env->CallVoidMethod((jobject)v45, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v46, v6, v6);
  v47 = env->FindClass("I/ᅠ︊︆");
  v48 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v47, v45, v6, v6);
  v49 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v50 = 1;
  env->CallVoidMethod((jobject)v49, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v50, v6, v6);
  v51 = env->FindClass("I/ᅠ︉︆");
  v52 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v51, v49, v6, v6);
  v53 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v54 = 2;
  env->CallVoidMethod((jobject)v53, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v54, v6, v6);
  v55 = env->FindClass("I/ᅟ︅️");
  v56 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v55, v53, v6, v6);
  v57 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v58 = 3;
  env->CallVoidMethod((jobject)v57, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v58, v6, v6);
  v59 = env->FindClass("I/ᅠ︌︁");
  v60 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v59, v57, v6, v6);
  v61 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v62 = 4;
  env->CallVoidMethod((jobject)v61, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v62, v6, v6);
  v63 = env->FindClass("I/ᅟ︅︊");
  v64 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v63, v61, v6, v6);
  v65 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v66 = 5;
  env->CallVoidMethod((jobject)v65, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v66, v6, v6);
  v67 = env->FindClass("I/ᅟ︁︋");
  v68 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v67, v65, v6, v6);
  v69 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v70 = 6;
  env->CallVoidMethod((jobject)v69, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v70, v6, v6);
  v71 = env->FindClass("I/ᅟ︀︆");
  v72 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v71, v69, v6, v6);
  v73 = env->AllocObject(env->FindClass("I/ᅟ︎︋"));
  v74 = 7;
  env->CallVoidMethod((jobject)v73, env->GetMethodID(env->FindClass("I/ᅟ︎︋"), "<init>", "(LI/ᅟ︀︌;I)V"), v0, v74, v6, v6);
  v75 = env->FindClass("I/ᅟ︊︈");
  v76 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v75, v73, v6, v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe00_0fe0c__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︂︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;I)V */
void Java_I__0115f_0fe02_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jint v2 = 0;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︂︍"), "ᅟ︀︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︂︍"), "ᅟ︁︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;I)V -> Java_I__0115f_0fe02_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2I */

/* LI/ᅟ︄︇;-><init>(Lbin/nt/editor/widget/CodeEditor;Landroid/view/ContextMenu;LI/ᅟ︂︅;)V */
void Java_I__0115f_0fe04_0fe07__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Landroid_view_ContextMenu_2LI__0115f_0fe02_0fe05_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jobject v0 = NULL;

L_0:
  v4 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v4, v0, v0, v0);
  v5 = env->NewStringUTF("menu");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v2, v5, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︇"), "ᅟ︂︀", "Landroid/view/ContextMenu;"), (jobject)(intptr_t)v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;Landroid/view/ContextMenu;LI/ᅟ︂︅;)V -> Java_I__0115f_0fe04_0fe07__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Landroid_view_ContextMenu_2LI__0115f_0fe02_0fe05_2 */

/* LI/ᅟ︄︊;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe04_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v77 = NULL;
  jint v122 = 0;
  jobject v115 = NULL;
  jobject v112 = NULL;
  jobject v24 = NULL;
  jint v65 = 0;
  jint v118 = 0;
  jobject v20 = NULL;
  jint v37 = 0;
  jobject v39 = NULL;
  jobject v2 = NULL;
  jint v60 = 0;
  jint v9 = 0;
  jint v52 = 0;
  jobject v85 = NULL;
  jobject v31 = NULL;
  jobject v117 = NULL;
  jobject v61 = NULL;
  jobject v0 = NULL;
  jint v81 = 0;
  jint v110 = 0;
  jobject v125 = NULL;
  jobject v58 = NULL;
  jobject v76 = NULL;
  jfloat v7 = 0;
  jobject v113 = NULL;
  jlong v87 = 0;
  jint v97 = 0;
  jobject v54 = NULL;
  jint v105 = 0;
  jobject v119 = NULL;
  jobject v32 = NULL;
  jobject v21 = NULL;
  jint v14 = 0;
  jobject v51 = NULL;
  jobject v28 = NULL;
  jobject v17 = NULL;
  jobject v78 = NULL;
  jint v3 = 0;
  jobject v4 = NULL;
  jfloat v11 = 0;
  jobject v126 = NULL;
  jobject v34 = NULL;
  jobject v108 = NULL;
  jobject v80 = NULL;
  jobject v44 = NULL;
  jobject v49 = NULL;
  jobject v35 = NULL;
  jint v62 = 0;
  jlong v88 = 0;
  jint v33 = 0;
  jobject v98 = NULL;
  jobject v116 = NULL;
  jobject v96 = NULL;
  jint v72 = 0;
  jint v16 = 0;
  jlong v93 = 0;
  jobject v121 = NULL;
  jobject v71 = NULL;
  jobject v22 = NULL;
  jobject v90 = NULL;
  jarray v15 = NULL;
  jfloat v10 = 0;
  jint v70 = 0;
  jint v95 = 0;
  jobject v120 = NULL;
  jobject v48 = NULL;
  jobject v104 = NULL;
  jobject v99 = NULL;
  jobject v91 = NULL;
  jobject v68 = NULL;
  jobject v5 = NULL;
  jobject v123 = NULL;
  jobject v43 = NULL;
  jobject v127 = NULL;
  jobject v131 = NULL;
  jobject v94 = NULL;
  jobject v13 = NULL;
  jint v67 = 0;
  jobject v102 = NULL;
  jint v114 = 0;
  jobject v45 = NULL;
  jobject v73 = NULL;
  jobject v100 = NULL;
  jobject v1 = NULL;
  jobject v26 = NULL;
  jobject v38 = NULL;
  jobject v25 = NULL;
  jobject v40 = NULL;
  jobject v109 = NULL;
  jobject v63 = NULL;
  jint v41 = 0;
  jobject v19 = NULL;
  jobject v66 = NULL;
  jobject v29 = NULL;
  jobject v103 = NULL;
  jint v55 = 0;
  jobject v53 = NULL;
  jobject v111 = NULL;
  jint v46 = 0;
  jobject v79 = NULL;
  jobject v64 = NULL;
  jint v101 = 0;
  jlong v92 = 0;
  jobject v27 = NULL;
  jobject v59 = NULL;
  jfloat v8 = 0;
  jobject v18 = NULL;
  jobject v23 = NULL;
  jint v50 = 0;
  jobject v36 = NULL;
  jint v57 = 0;
  jint v86 = 0;
  jobject v56 = NULL;
  jobject v42 = NULL;
  jlong v130 = 0;
  jobject v74 = NULL;
  jobject v30 = NULL;
  jlong v129 = 0;
  jint v83 = 0;
  jint v75 = 0;
  jobject v132 = NULL;
  jobject v106 = NULL;
  jobject v47 = NULL;
  jint v84 = 0;
  jobject v107 = NULL;
  jint v82 = 0;
  jfloat v12 = 0;
  jobject v124 = NULL;
  jobject v128 = NULL;
  jobject v6 = NULL;
  jobject v89 = NULL;
  jobject v69 = NULL;

L_0:
  v2 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v2, v2, v2, v2);
  v3 = 6;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ️︊"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;I)V"), v1, v3, v3, v3);
  v4 = env->AllocObject(env->FindClass("I/ᅟ︋︌"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "<init>", "(LI/ᅟ︋︌;)V"), v5, v4, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︂︁", "LI/ᅟ︋︌;"), (jobject)(intptr_t)v4);
  v6 = env->AllocObject(env->FindClass("I/ᅟ︀︈"));
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v4, v4, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︄︁", "LI/ᅟ︀︈;"), (jobject)(intptr_t)v6);
  v7 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v1, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getDpUnit", "()F"), v4, v4, v4, v4);
  v8 = v7;
  v9 = 175;
  v10 = (jfloat)v10;
  /* UNSUPPORTED: mul-float */
  v12 = (jint)v12;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︆︁", "I"), v12);
  v13 = env->AllocObject(env->FindClass("java/util/ArrayList"));
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/ArrayList"), "<init>", "()V"), v4, v4, v4, v4);
  v14 = 2;
  v15 = env->NewIntArray((jsize)(intptr_t)v15);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︇︁", "[I"), (jobject)(intptr_t)v15);
  v16 = 0;
  v17 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/lang/Float"), env->GetStaticMethodID(env->FindClass("java/lang/Float"), "valueOf", "(F)Ljava/lang/Float;"), v16, v4, v4, v4, v4);
  v18 = (jobject)(intptr_t)v17;
  v19 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/lang/Float"), env->GetStaticMethodID(env->FindClass("java/lang/Float"), "valueOf", "(F)Ljava/lang/Float;"), v16, v4, v4, v4, v4);
  v20 = (jobject)(intptr_t)v19;
  v21 = env->AllocObject(env->FindClass("kotlin/Pair"));
  env->CallVoidMethod((jobject)v21, env->GetMethodID(env->FindClass("kotlin/Pair"), "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V"), v18, v20, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︉︁", "Lkotlin/Pair;"), (jobject)(intptr_t)v21);
  v22 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︄︁", "LI/ᅟ︀︈;"));
  v23 = env->NewStringUTF("value");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v22, v23, v4, v4, v4);
  v24 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︃︁", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v24 == 0) { goto L_50;
 } else { goto L_4a;
 }

L_4a:
  v25 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︄︁", "LI/ᅟ︀︈;"));
  /* UNSUPPORTED: if-ne */
  if (v25 != v22) { goto L_50;
 } else { goto L_4e;
 }

L_4e:
  /* UNSUPPORTED: goto-16 */
v127 = (jobject)v4; v128 = (jobject)v0; goto L_138;

L_50:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︄︁", "LI/ᅟ︀︈;"), (jobject)(intptr_t)v22);
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︀︀", "LI/ᅟ︄︊;"), (jobject)(intptr_t)v0);
  v26 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︅︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v27 = (jobject)env->CallObjectMethod((jobject)v26, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v4, v4, v4, v4);
  v28 = v27;
  v29 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/view/LayoutInflater"), env->GetStaticMethodID(env->FindClass("android/view/LayoutInflater"), "from", "(Landroid/content/Context;)Landroid/view/LayoutInflater;"), v28, v4, v4, v4, v4);
  v30 = v29;
  v31 = env->NewStringUTF("from(...)");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v30, v31, v4, v4, v4);
  v32 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︀︀", "LI/ᅟ︄︊;"));
  v33 = 0;
  /* UNSUPPORTED: if-eqz */
  if (v32 == 0) { goto L_1ce;
 } else { goto L_68;
 }

L_68:
  v34 = (jobject)env->GetObjectField((jobject)(intptr_t)v34, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︅︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v35 = (jobject)env->CallObjectMethod((jobject)v34, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v4, v4, v4, v4);
  v36 = v35;
  v37 = 2131558451;
  v38 = (jobject)env->CallObjectMethod((jobject)v30, env->GetMethodID(env->FindClass("android/view/LayoutInflater"), "inflate", "(ILandroid/view/ViewGroup;)Landroid/view/View;"), v37, v33, v4, v4);
  v39 = v38;
  v40 = env->NewStringUTF("inflate(...)");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v39, v40, v4, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"), (jobject)(intptr_t)v39);
  v41 = 1;
  env->CallVoidMethod((jobject)v39, env->GetMethodID(env->FindClass("android/view/View"), "setClipToOutline", "(Z)V"), v41, v4, v4, v4);
  v42 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  v43 = env->NewStringUTF("root");
  /* UNSUPPORTED: if-eqz */
  if (v42 == 0) { goto L_1ca;
 } else { goto L_86;
 }

L_86:
  v44 = env->AllocObject(env->FindClass("I/ᅟ︎︇"));
  env->CallVoidMethod((jobject)v44, env->GetMethodID(env->FindClass("I/ᅟ︎︇"), "<init>", "(LI/ᅟ︀︈;)V"), v22, v4, v4, v4);
  env->CallVoidMethod((jobject)v42, env->GetMethodID(env->FindClass("android/view/View"), "setOnGenericMotionListener", "(Landroid/view/View$OnGenericMotionListener;)V"), v44, v4, v4, v4);
  v45 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v45 == 0) { goto L_1c6;
 } else { goto L_92;
 }

L_92:
  v46 = 2131361966;
  v47 = (jobject)env->CallObjectMethod((jobject)v45, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v46, v4, v4, v4);
  v48 = (jobject)(intptr_t)v47;
  v49 = env->NewStringUTF("findViewById(...)");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v48, v49, v4, v4, v4);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/TextView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︂︀", "Landroid/widget/TextView;"), (jobject)(intptr_t)v50);
  v51 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v51 == 0) { goto L_1c2;
 } else { goto L_a6;
 }

L_a6:
  v52 = 2131361967;
  v53 = (jobject)env->CallObjectMethod((jobject)v51, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v52, v4, v4, v4);
  v54 = (jobject)(intptr_t)v53;
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v54, v49, v4, v4, v4);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/TextView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︃︀", "Landroid/widget/TextView;"), (jobject)(intptr_t)v55);
  v56 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v56 == 0) { goto L_1be;
 } else { goto L_b8;
 }

L_b8:
  v57 = 2131361969;
  v58 = (jobject)env->CallObjectMethod((jobject)v56, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v57, v4, v4, v4);
  v59 = (jobject)(intptr_t)v58;
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v59, v49, v4, v4, v4);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/TextView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︄︀", "Landroid/widget/TextView;"), (jobject)(intptr_t)v60);
  v61 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v61 == 0) { goto L_1ba;
 } else { goto L_ca;
 }

L_ca:
  v62 = 2131361968;
  v63 = (jobject)env->CallObjectMethod((jobject)v61, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v62, v4, v4, v4);
  v64 = (jobject)(intptr_t)v63;
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v64, v49, v4, v4, v4);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/TextView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︅︀", "Landroid/widget/TextView;"), (jobject)(intptr_t)v65);
  v66 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v66 == 0) { goto L_1b6;
 } else { goto L_dc;
 }

L_dc:
  v67 = 2131361964;
  v68 = (jobject)env->CallObjectMethod((jobject)v66, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v67, v4, v4, v4);
  v69 = (jobject)(intptr_t)v68;
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v69, v49, v4, v4, v4);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/view/ViewGroup"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︆︀", "Landroid/view/ViewGroup;"), (jobject)(intptr_t)v70);
  v71 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v71 == 0) { goto L_1b2;
 } else { goto L_ee;
 }

L_ee:
  v72 = 2131361965;
  v73 = (jobject)env->CallObjectMethod((jobject)v71, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v72, v4, v4, v4);
  v74 = (jobject)(intptr_t)v73;
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︃︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v74, v49, v4, v4, v4);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/view/ViewGroup"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︇︀", "Landroid/view/ViewGroup;"), (jobject)(intptr_t)v75);
  v76 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︄︀", "Landroid/widget/TextView;"));
  /* UNSUPPORTED: if-eqz */
  if (v76 == 0) { goto L_1ac;
 } else { goto L_100;
 }

L_100:
  v77 = env->AllocObject(env->FindClass("I/ᅟ️︇"));
  env->CallVoidMethod((jobject)v77, env->GetMethodID(env->FindClass("I/ᅟ️︇"), "<init>", "(LI/ᅟ︀︈;)V"), v22, v4, v4, v4);
  env->CallVoidMethod((jobject)v76, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v77, v4, v4, v4);
  v78 = (jobject)env->GetObjectField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︅︀", "Landroid/widget/TextView;"));
  v79 = env->NewStringUTF("moreActionText");
  /* UNSUPPORTED: if-eqz */
  if (v78 == 0) { goto L_1a8;
 } else { goto L_10e;
 }

L_10e:
  v80 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︋️"), env->GetStaticFieldID(env->FindClass("I/ᅟ︋️"), "ᅟ︀︀", "Landroid/util/SparseIntArray;"));
  v81 = 2131886324;
  v82 = (jint)(intptr_t)env->CallIntMethod((jobject)v80, env->GetMethodID(env->FindClass("android/util/SparseIntArray"), "get", "(I)I"), v81, v4, v4, v4);
  v83 = v82;
  /* UNSUPPORTED: if-nez */
  if (v83 != 0) { goto L_11a;
 } else { goto L_119;
 }

L_119:
  /* UNSUPPORTED: goto */
v86 = (jint)v81; goto L_11b;

L_11a:
  /* dbg-move v84 v83 dv=I sv=I */
v86 = (jint)v84; goto L_11b;

L_11b:
  env->CallVoidMethod((jobject)v78, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(I)V"), v86, v87, v87, v87);
  v85 = (jobject)env->GetObjectField((jobject)(intptr_t)v88, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︅︀", "Landroid/widget/TextView;"));
  /* UNSUPPORTED: if-eqz */
  if (v85 == 0) { goto L_1a4;
 } else { goto L_122;
 }

L_122:
  v89 = env->AllocObject(env->FindClass("I/ᅟ️︇"));
  env->CallVoidMethod((jobject)v89, env->GetMethodID(env->FindClass("I/ᅟ️︇"), "<init>", "(LI/ᅟ︀︈;Landroid/content/Context;)V"), v88, v36, v87, v87);
  env->CallVoidMethod((jobject)v85, env->GetMethodID(env->FindClass("android/view/View"), "setOnClickListener", "(Landroid/view/View$OnClickListener;)V"), v89, v87, v87, v87);
  v90 = (jobject)env->GetObjectField((jobject)(intptr_t)v90, env->GetFieldID(env->FindClass("I/ᅟ︀︈"), "ᅟ︁︀", "Landroid/view/View;"));
  /* UNSUPPORTED: if-eqz */
  if (v90 == 0) { goto L_1a0;
 } else { goto L_12e;
 }

L_12e:
  env->SetObjectField((jobject)(intptr_t)v92, env->GetFieldID(env->FindClass("I/ᅟ︄︊"), "ᅟ︃︁", "Landroid/view/View;"), (jobject)(intptr_t)v90);
  v91 = (jobject)env->GetObjectField((jobject)(intptr_t)v92, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︄︀", "Landroid/widget/PopupWindow;"));
  env->CallVoidMethod((jobject)v91, env->GetMethodID(env->FindClass("android/widget/PopupWindow"), "setContentView", "(Landroid/view/View;)V"), v90, v93, v93, v93);
  env->CallVoidMethod((jobject)v92, env->GetMethodID(env->FindClass("I/ᅟ︄︊"), "ᅟ︃︀", "()V"), v93, v93, v93, v93);
v127 = (jobject)(intptr_t)v129; v128 = (jobject)(intptr_t)v130; goto L_138;

L_138:
  v94 = (jobject)env->GetObjectField((jobject)(intptr_t)v128, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︄︀", "Landroid/widget/PopupWindow;"));
  v95 = 2131952801;
  env->CallVoidMethod((jobject)v94, env->GetMethodID(env->FindClass("android/widget/PopupWindow"), "setAnimationStyle", "(I)V"), v95, v127, v127, v127);
  v96 = env->AllocObject(env->FindClass("I/ᅟ︂︊"));
  v97 = 0;
  env->CallVoidMethod((jobject)v96, env->GetMethodID(env->FindClass("I/ᅟ︂︊"), "<init>", "(LI/ᅟ︄︊;I)V"), v128, v97, v127, v127);
  v98 = env->FindClass("I/ᅠ︊︆");
  v99 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v98, v96, v127, v127);
  v100 = env->AllocObject(env->FindClass("I/ᅟ︂︊"));
  v101 = 1;
  env->CallVoidMethod((jobject)v100, env->GetMethodID(env->FindClass("I/ᅟ︂︊"), "<init>", "(LI/ᅟ︄︊;I)V"), v128, v101, v127, v127);
  v102 = env->FindClass("I/ᅠ︉︆");
  v103 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v102, v100, v127, v127);
  v104 = env->AllocObject(env->FindClass("I/ᅟ︄︄"));
  v105 = 7;
  env->CallVoidMethod((jobject)v104, env->GetMethodID(env->FindClass("I/ᅟ︄︄"), "<init>", "(ILjava/lang/Object;)V"), v105, v128, v127, v127);
  v106 = env->AllocObject(env->FindClass("I/ᅟ︃︊"));
  env->CallVoidMethod((jobject)v106, env->GetMethodID(env->FindClass("I/ᅟ︃︊"), "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V"), v128, v104, v127, v127);
  v107 = env->FindClass("I/ᅟ︊️");
  v108 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︄︀", "(Ljava/lang/Class;LI/ᅟ︉︌;)LI/ᅠ️︈;"), v107, v106, v127, v127);
  v109 = env->AllocObject(env->FindClass("I/ᅟ︂︊"));
  v110 = 2;
  env->CallVoidMethod((jobject)v109, env->GetMethodID(env->FindClass("I/ᅟ︂︊"), "<init>", "(LI/ᅟ︄︊;I)V"), v128, v110, v127, v127);
  v111 = env->FindClass("I/ᅟ︀︆");
  v112 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v111, v109, v127, v127);
  v113 = env->AllocObject(env->FindClass("I/ᅟ︂︊"));
  v114 = 3;
  env->CallVoidMethod((jobject)v113, env->GetMethodID(env->FindClass("I/ᅟ︂︊"), "<init>", "(LI/ᅟ︄︊;I)V"), v128, v114, v127, v127);
  v115 = env->FindClass("I/ᅠ︎︊");
  v116 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v115, v113, v127, v127);
  v117 = env->AllocObject(env->FindClass("I/ᅟ︂︊"));
  v118 = 4;
  env->CallVoidMethod((jobject)v117, env->GetMethodID(env->FindClass("I/ᅟ︂︊"), "<init>", "(LI/ᅟ︄︊;I)V"), v128, v118, v127, v127);
  v119 = env->FindClass("I/ᅟ︅︊");
  v120 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v119, v117, v127, v127);
  v121 = env->AllocObject(env->FindClass("I/ᅟ︂︊"));
  v122 = 5;
  env->CallVoidMethod((jobject)v121, env->GetMethodID(env->FindClass("I/ᅟ︂︊"), "<init>", "(LI/ᅟ︄︊;I)V"), v128, v122, v127, v127);
  v123 = env->FindClass("I/ᅟ︁︋");
  v124 = (jobject)env->CallObjectMethod((jobject)v127, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v123, v121, v127, v127);
  v125 = (jobject)env->GetObjectField((jobject)(intptr_t)v128, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︄︀", "Landroid/widget/PopupWindow;"));
  v126 = env->AllocObject(env->FindClass("I/ᅟ︁︊"));
  env->CallVoidMethod((jobject)v126, env->GetMethodID(env->FindClass("I/ᅟ︁︊"), "<init>", "(LI/ᅟ︄︊;)V"), v128, v126, v126, v126);
  env->CallVoidMethod((jobject)v125, env->GetMethodID(env->FindClass("android/widget/PopupWindow"), "setOnDismissListener", "(Landroid/widget/PopupWindow$OnDismissListener;)V"), v126, v126, v126, v126);
  env->CallVoidMethod((jobject)v128, env->GetMethodID(env->FindClass("I/ᅟ︄︊"), "ᅟ︃︀", "()V"), v126, v126, v126, v126);
  /* return terminator */
  return;

L_1a0:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v87, v87, v87, v87);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1a4:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v79, v87, v87, v87, v87);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1a8:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v79, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1ac:
  v131 = env->NewStringUTF("quickfixText");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v131, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1b2:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1b6:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1ba:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1be:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1c2:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1c6:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1ca:
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v43, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_1ce:
  v132 = env->NewStringUTF("window");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︊︀", "(Ljava/lang/String;)V"), v132, v4, v4, v4, v4);
  pendingException = (jthrowable)v33; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe04_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︅︊;-><init>(Lbin/nt/editor/widget/CodeEditor;Z)V */
void Java_I__0115f_0fe05_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;
  jboolean v2 = 0;

L_0:
  v3 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v3, v3, v3, v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v3, v3, v3);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︅︊"), "ᅟ︂︀", "Z"), v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;Z)V -> Java_I__0115f_0fe05_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Z */

/* LI/ᅟ︅️;-><init>(Lbin/nt/editor/widget/CodeEditor;IZ)V */
void Java_I__0115f_0fe05_0fe0f__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2IZ(JNIEnv* env, jobject thiz, jobject p0, jint p1, jboolean p2) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jboolean v3 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︅️"), "ᅟ︂︀", "I"), v2);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︅️"), "ᅟ︃︀", "Z"), v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;IZ)V -> Java_I__0115f_0fe05_0fe0f__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2IZ */

/* LI/ᅟ︆︎;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe06_0fe0e__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jobject v2 = NULL;
  jint v4 = 0;

L_0:
  v2 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v2, v2, v2, v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︁︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  v3 = env->AllocObject(env->FindClass("java/util/ArrayList"));
  v4 = 64;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("java/util/ArrayList"), "<init>", "(I)V"), v4, v4, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︂︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  v5 = env->AllocObject(env->FindClass("java/util/Stack"));
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/Stack"), "<init>", "()V"), v4, v4, v4, v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︀︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe06_0fe0e__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︆︎;-><init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/Serializable;Ljava/lang/Object;)V */
void Java_I__0115f_0fe06_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_Serializable_2Ljava_lang_Object_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︀︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︁︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︂︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/Serializable;Ljava/lang/Object;)V -> Java_I__0115f_0fe06_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_Serializable_2Ljava_lang_Object_2 */

/* FAILED LI/ᅟ︇︇;-><init>(Lbin/nt/editor/widget/CodeEditor;I)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ︉︎;-><init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︁︍;LI/ᅟ︁︍;)V */
void Java_I__0115f_0fe09_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe01_0fe0d_2LI__0115f_0fe01_0fe0d_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︎"), "ᅟ︂︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︎"), "ᅟ︀︀", "LI/ᅟ︁︍;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︉︎"), "ᅟ︁︀", "LI/ᅟ︁︍;"), (jobject)(intptr_t)v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView$OnScrollListener"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︁︍;LI/ᅟ︁︍;)V -> Java_I__0115f_0fe09_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe01_0fe0d_2LI__0115f_0fe01_0fe0d_2 */

/* LI/ᅟ︊︍;-><init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Z)V */
void Java_I__0115f_0fe0a_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2Z(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jboolean p2) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jboolean v3 = 0;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︍"), "ᅟ︀︀", "Lbin/nt/fragments/FileBrowserFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︍"), "ᅟ︁︀", "LI/ᅟ︎︎;"), (jobject)(intptr_t)v2);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︍"), "ᅟ︂︀", "Z"), v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Z)V -> Java_I__0115f_0fe0a_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2Z */

/* LI/ᅟ︋︉;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe0b_0fe09__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v23 = NULL;
  jlong v6 = 0;
  jobject v87 = NULL;
  jobject v120 = NULL;
  jint v46 = 0;
  jint v38 = 0;
  jobject v59 = NULL;
  jint v86 = 0;
  jobject v96 = NULL;
  jobject v35 = NULL;
  jobject v66 = NULL;
  jobject v102 = NULL;
  jint v93 = 0;
  jobject v128 = NULL;
  jobject v125 = NULL;
  jint v16 = 0;
  jobject v13 = NULL;
  jobject v103 = NULL;
  jobject v89 = NULL;
  jfloat v30 = 0;
  jobject v76 = NULL;
  jobject v112 = NULL;
  jobject v108 = NULL;
  jint v121 = 0;
  jfloat v55 = 0;
  jobject v26 = NULL;
  jobject v118 = NULL;
  jobject v43 = NULL;
  jobject v65 = NULL;
  jint v97 = 0;
  jobject v104 = NULL;
  jint v77 = 0;
  jint v20 = 0;
  jint v41 = 0;
  jint v126 = 0;
  jint v33 = 0;
  jobject v82 = NULL;
  jobject v127 = NULL;
  jobject v95 = NULL;
  jobject v50 = NULL;
  jobject v34 = NULL;
  jobject v58 = NULL;
  jfloat v62 = 0;
  jint v4 = 0;
  jobject v99 = NULL;
  jobject v122 = NULL;
  jobject v100 = NULL;
  jfloat v29 = 0;
  jint v84 = 0;
  jobject v124 = NULL;
  jobject v21 = NULL;
  jfloat v54 = 0;
  jint v7 = 0;
  jobject v1 = NULL;
  jobject v39 = NULL;
  jfloat v63 = 0;
  jobject v80 = NULL;
  jobject v12 = NULL;
  jint v18 = 0;
  jfloat v78 = 0;
  jobject v68 = NULL;
  jobject v17 = NULL;
  jobject v27 = NULL;
  jint v28 = 0;
  jobject v85 = NULL;
  jobject v107 = NULL;
  jobject v14 = NULL;
  jfloat v48 = 0;
  jobject v110 = NULL;
  jobject v114 = NULL;
  jobject v45 = NULL;
  jobject v32 = NULL;
  jfloat v69 = 0;
  jobject v51 = NULL;
  jobject v116 = NULL;
  jfloat v70 = 0;
  jfloat v56 = 0;
  jobject v90 = NULL;
  jobject v8 = NULL;
  jobject v24 = NULL;
  jobject v19 = NULL;
  jobject v72 = NULL;
  jobject v94 = NULL;
  jobject v10 = NULL;
  jobject v111 = NULL;
  jobject v123 = NULL;
  jobject v67 = NULL;
  jint v88 = 0;
  jfloat v31 = 0;
  jobject v40 = NULL;
  jobject v73 = NULL;
  jint v129 = 0;
  jobject v75 = NULL;
  jint v22 = 0;
  jobject v91 = NULL;
  jfloat v79 = 0;
  jint v3 = 0;
  jfloat v47 = 0;
  jobject v42 = NULL;
  jint v81 = 0;
  jint v2 = 0;
  jint v61 = 0;
  jobject v92 = NULL;
  jobject v9 = NULL;
  jobject v98 = NULL;
  jint v101 = 0;
  jobject v106 = NULL;
  jint v15 = 0;
  jfloat v71 = 0;
  jobject v130 = NULL;
  jobject v44 = NULL;
  jlong v5 = 0;
  jobject v57 = NULL;
  jobject v60 = NULL;
  jint v109 = 0;
  jint v105 = 0;
  jobject v53 = NULL;
  jobject v11 = NULL;
  jobject v37 = NULL;
  jobject v83 = NULL;
  jint v117 = 0;
  jobject v0 = NULL;
  jobject v119 = NULL;
  jobject v25 = NULL;
  jobject v52 = NULL;
  jint v36 = 0;
  jfloat v64 = 0;
  jfloat v49 = 0;
  jobject v74 = NULL;
  jobject v115 = NULL;
  jint v113 = 0;

L_0:
  v2 = 4;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ️︊"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;I)V"), v1, v2, v2, v2);
  v3 = 0;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︃︁", "Z"), v3);
  v4 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︉︁", "I"), v4);
  v5 = 0;
  env->SetLongField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︎︁", "J"), v5);
  v6 = -1;
  env->SetLongField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ️︁", "J"), v6);
  v7 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︀︂", "Z"), v7);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︁︂", "Z"), v3);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︂︂", "Z"), v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︂︁", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  v8 = env->AllocObject(env->FindClass("I/ᅟ︊︇"));
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("android/widget/BaseAdapter"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︊︁", "LI/ᅟ︊︇;"), (jobject)(intptr_t)v8);
  v9 = env->AllocObject(env->FindClass("I/ᅟ︄︀"));
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︋︁", "LI/ᅟ︄︀;"), (jobject)(intptr_t)v9);
  env->SetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︃︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v0);
  v10 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v11 = v10;
  v12 = env->AllocObject(env->FindClass("android/widget/LinearLayout"));
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/widget/LinearLayout"), "<init>", "(Landroid/content/Context;)V"), v11, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︂︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v12);
  v13 = env->AllocObject(env->FindClass("android/widget/ListView"));
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("android/widget/ListView"), "<init>", "(Landroid/content/Context;)V"), v11, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v13);
  v14 = env->AllocObject(env->FindClass("android/widget/ProgressBar"));
  v15 = 0;
  v16 = 16842872;
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V"), v11, v15, v16, v3);
  env->SetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︁︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v14);
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/widget/LinearLayout"), "setOrientation", "(I)V"), v7, v3, v3, v3);
  v17 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︂︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/LinearLayout"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "setLayoutTransition", "(Landroid/animation/LayoutTransition;)V"), v15, v3, v3, v3);
  v19 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ListView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v20, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "setLayoutTransition", "(Landroid/animation/LayoutTransition;)V"), v15, v3, v3, v3);
  v21 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ProgressBar"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v23 = env->AllocObject(env->FindClass("android/widget/LinearLayout$LayoutParams"));
  v24 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v25 = v24;
  v26 = (jobject)env->CallObjectMethod((jobject)v25, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v27 = v26;
  v28 = 1101004800;
  v29 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v7, v28, v27, v3, v3);
  v30 = v29;
  v31 = (jint)v31;
  env->CallVoidMethod((jobject)v23, env->GetMethodID(env->FindClass("android/widget/LinearLayout$LayoutParams"), "<init>", "(II)V"), v4, v31, v3, v3);
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "addView", "(Landroid/view/View;Landroid/view/ViewGroup$LayoutParams;)V"), v22, v23, v3, v3);
  v32 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ListView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v34 = env->AllocObject(env->FindClass("android/widget/LinearLayout$LayoutParams"));
  env->CallVoidMethod((jobject)v34, env->GetMethodID(env->FindClass("android/widget/LinearLayout$LayoutParams"), "<init>", "(II)V"), v4, v4, v3, v3);
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "addView", "(Landroid/view/View;Landroid/view/ViewGroup$LayoutParams;)V"), v33, v34, v3, v3);
  v35 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ProgressBar"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v36, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "setIndeterminate", "(Z)V"), v7, v3, v3, v3);
  v37 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ProgressBar"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v39 = (jobject)env->CallObjectMethod((jobject)v38, env->GetMethodID(env->FindClass("android/view/View"), "getLayoutParams", "()Landroid/view/ViewGroup$LayoutParams;"), v3, v3, v3, v3);
  v40 = (jobject)(intptr_t)v39;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/LinearLayout$LayoutParams"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v42 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v43 = v42;
  v44 = (jobject)env->CallObjectMethod((jobject)v43, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v45 = v44;
  v46 = -1056964608;
  v47 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v7, v46, v45, v3, v3);
  v48 = v47;
  v49 = (jint)v49;
  env->SetIntField((jobject)(intptr_t)v41, env->GetFieldID(env->FindClass("android/widget/LinearLayout$LayoutParams"), "topMargin", "I"), v49);
  v50 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v51 = v50;
  v52 = (jobject)env->CallObjectMethod((jobject)v51, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v53 = v52;
  v54 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v7, v46, v53, v3, v3);
  v55 = v54;
  v56 = (jint)v56;
  env->SetIntField((jobject)(intptr_t)v41, env->GetFieldID(env->FindClass("android/widget/LinearLayout$LayoutParams"), "bottomMargin", "I"), v56);
  v57 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v58 = v57;
  v59 = (jobject)env->CallObjectMethod((jobject)v58, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v60 = v59;
  v61 = 1082130432;
  v62 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v7, v61, v60, v3, v3);
  v63 = v62;
  v64 = (jint)v64;
  env->SetIntField((jobject)(intptr_t)v41, env->GetFieldID(env->FindClass("android/widget/LinearLayout$LayoutParams"), "leftMargin", "I"), v64);
  v65 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v66 = v65;
  v67 = (jobject)env->CallObjectMethod((jobject)v66, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v68 = v67;
  v69 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v7, v61, v68, v3, v3);
  v70 = v69;
  v71 = (jint)v71;
  env->SetIntField((jobject)(intptr_t)v41, env->GetFieldID(env->FindClass("android/widget/LinearLayout$LayoutParams"), "rightMargin", "I"), v71);
  v72 = env->AllocObject(env->FindClass("android/graphics/drawable/GradientDrawable"));
  env->CallVoidMethod((jobject)v72, env->GetMethodID(env->FindClass("android/graphics/drawable/GradientDrawable"), "<init>", "()V"), v3, v3, v3, v3);
  v73 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v74 = v73;
  v75 = (jobject)env->CallObjectMethod((jobject)v74, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v76 = v75;
  v77 = 1090519040;
  v78 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v7, v77, v76, v3, v3);
  v79 = v78;
  env->CallVoidMethod((jobject)v72, env->GetMethodID(env->FindClass("android/graphics/drawable/GradientDrawable"), "setCornerRadius", "(F)V"), v79, v3, v3, v3);
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/view/View"), "setBackground", "(Landroid/graphics/drawable/Drawable;)V"), v72, v3, v3, v3);
  v80 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︂︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/LinearLayout"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v82 = env->AllocObject(env->FindClass("I/ᅟ︍︇"));
  env->CallVoidMethod((jobject)v82, env->GetMethodID(env->FindClass("android/view/ViewOutlineProvider"), "<init>", "()V"), v3, v3, v3, v3);
  env->CallVoidMethod((jobject)v81, env->GetMethodID(env->FindClass("android/view/View"), "setOutlineProvider", "(Landroid/view/ViewOutlineProvider;)V"), v82, v3, v3, v3);
  env->CallVoidMethod((jobject)v81, env->GetMethodID(env->FindClass("android/view/View"), "setClipToOutline", "(Z)V"), v7, v3, v3, v3);
  v83 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ListView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v84, env->GetMethodID(env->FindClass("android/widget/ListView"), "setDividerHeight", "(I)V"), v3, v3, v3, v3);
  v85 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ProgressBar"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v86, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v3, v3, v3, v3);
  v87 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ListView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v89 = env->AllocObject(env->FindClass("I/ᅟ︌︇"));
  env->CallVoidMethod((jobject)v89, env->GetMethodID(env->FindClass("I/ᅟ︌︇"), "<init>", "(LI/ᅟ︄︀;Landroid/content/Context;)V"), v9, v11, v88, v88);
  env->CallVoidMethod((jobject)v88, env->GetMethodID(env->FindClass("android/widget/AdapterView"), "setOnItemClickListener", "(Landroid/widget/AdapterView$OnItemClickListener;)V"), v89, v88, v88, v88);
  v90 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︊"), "ᅟ︄︀", "Landroid/widget/PopupWindow;"));
  env->CallVoidMethod((jobject)v90, env->GetMethodID(env->FindClass("android/widget/PopupWindow"), "setContentView", "(Landroid/view/View;)V"), v12, v90, v90, v90);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︋︉"), "ᅟ︄︀", "()V"), v90, v90, v90, v90);
  v91 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︋︁", "LI/ᅟ︄︀;"));
  v92 = (jobject)env->GetObjectField((jobject)(intptr_t)v92, env->GetFieldID(env->FindClass("I/ᅟ︄︀"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ListView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v93, env->GetMethodID(env->FindClass("android/widget/AdapterView"), "setAdapter", "(Landroid/widget/Adapter;)V"), v8, v93, v93, v93);
  v94 = env->AllocObject(env->FindClass("I/ᅟ︋︌"));
  v95 = (jobject)env->GetObjectField((jobject)(intptr_t)v95, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  env->CallVoidMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "<init>", "(LI/ᅟ︋︌;)V"), v95, v94, v94, v94);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︋︉"), "ᅟ︌︁", "LI/ᅟ︋︌;"), (jobject)(intptr_t)v94);
  v96 = env->AllocObject(env->FindClass("I/ᅟ︈︉"));
  v97 = 0;
  env->CallVoidMethod((jobject)v96, env->GetMethodID(env->FindClass("I/ᅟ︈︉"), "<init>", "(LI/ᅟ︋︉;I)V"), v0, v97, v94, v94);
  v98 = env->FindClass("I/ᅟ︀︆");
  v99 = (jobject)env->CallObjectMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v98, v96, v94, v94);
  v100 = env->AllocObject(env->FindClass("I/ᅟ︈︉"));
  v101 = 1;
  env->CallVoidMethod((jobject)v100, env->GetMethodID(env->FindClass("I/ᅟ︈︉"), "<init>", "(LI/ᅟ︋︉;I)V"), v0, v101, v94, v94);
  v102 = env->FindClass("I/ᅟ︀︇");
  v103 = (jobject)env->CallObjectMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v102, v100, v94, v94);
  v104 = env->AllocObject(env->FindClass("I/ᅟ︈︉"));
  v105 = 2;
  env->CallVoidMethod((jobject)v104, env->GetMethodID(env->FindClass("I/ᅟ︈︉"), "<init>", "(LI/ᅟ︋︉;I)V"), v0, v105, v94, v94);
  v106 = env->FindClass("I/ᅠ︉︆");
  v107 = (jobject)env->CallObjectMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v106, v104, v94, v94);
  v108 = env->AllocObject(env->FindClass("I/ᅟ︈︉"));
  v109 = 3;
  env->CallVoidMethod((jobject)v108, env->GetMethodID(env->FindClass("I/ᅟ︈︉"), "<init>", "(LI/ᅟ︋︉;I)V"), v0, v109, v94, v94);
  v110 = env->FindClass("I/ᅟ︌︊");
  v111 = (jobject)env->CallObjectMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v110, v108, v94, v94);
  v112 = env->AllocObject(env->FindClass("I/ᅟ︈︉"));
  v113 = 4;
  env->CallVoidMethod((jobject)v112, env->GetMethodID(env->FindClass("I/ᅟ︈︉"), "<init>", "(LI/ᅟ︋︉;I)V"), v0, v113, v94, v94);
  v114 = env->FindClass("I/ᅠ︊︆");
  v115 = (jobject)env->CallObjectMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v114, v112, v94, v94);
  v116 = env->AllocObject(env->FindClass("I/ᅟ︈︉"));
  v117 = 5;
  env->CallVoidMethod((jobject)v116, env->GetMethodID(env->FindClass("I/ᅟ︈︉"), "<init>", "(LI/ᅟ︋︉;I)V"), v0, v117, v94, v94);
  v118 = env->FindClass("I/ᅟ︁︋");
  v119 = (jobject)env->CallObjectMethod((jobject)v94, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︅︀", "(Ljava/lang/Class;LI/ᅟ︌︌;)LI/ᅠ️︈;"), v118, v116, v94, v94);
  v120 = env->AllocObject(env->FindClass("I/ᅟ︉︉"));
  v121 = 0;
  env->CallVoidMethod((jobject)v120, env->GetMethodID(env->FindClass("I/ᅟ︉︉"), "<init>", "(I)V"), v121, v121, v121, v121);
  v122 = env->FindClass("I/ᅟ︆︊");
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︋︉"), "ᅟ︊︀", "(Ljava/lang/Class;Lkotlin/jvm/functions/Function1;)V"), v122, v120, v122, v122);
  v123 = env->FindClass("I/ᅟ︅︅");
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︋︉"), "ᅟ︊︀", "(Ljava/lang/Class;Lkotlin/jvm/functions/Function1;)V"), v123, v15, v122, v122);
  v124 = env->FindClass("I/ᅟ︍︊");
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︋︉"), "ᅟ︊︀", "(Ljava/lang/Class;Lkotlin/jvm/functions/Function1;)V"), v124, v15, v122, v122);
  v125 = env->AllocObject(env->FindClass("I/ᅟ︉︉"));
  v126 = 1;
  env->CallVoidMethod((jobject)v125, env->GetMethodID(env->FindClass("I/ᅟ︉︉"), "<init>", "(I)V"), v126, v126, v126, v126);
  v127 = env->FindClass("I/ᅟ︅︊");
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︋︉"), "ᅟ︊︀", "(Ljava/lang/Class;Lkotlin/jvm/functions/Function1;)V"), v127, v125, v127, v127);
  v128 = env->AllocObject(env->FindClass("I/ᅟ︉︉"));
  v129 = 2;
  env->CallVoidMethod((jobject)v128, env->GetMethodID(env->FindClass("I/ᅟ︉︉"), "<init>", "(I)V"), v129, v129, v129, v129);
  v130 = env->FindClass("I/ᅠ︇︈");
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︋︉"), "ᅟ︊︀", "(Ljava/lang/Class;Lkotlin/jvm/functions/Function1;)V"), v130, v128, v130, v130);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe0b_0fe09__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︌︄;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__0115f_0fe0c_0fe04__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v2 = env->NewStringUTF("editor");
  env->CallStaticVoidMethod(env->FindClass("kotlin/jvm/internal/Intrinsics"), env->GetStaticMethodID(env->FindClass("kotlin/jvm/internal/Intrinsics"), "ᅟ︄︀", "(Ljava/lang/Object;Ljava/lang/String;)V"), v1, v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__0115f_0fe0c_0fe04__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅟ︌︊;-><init>(Lbin/nt/editor/widget/CodeEditor;Landroid/view/KeyEvent;LI/ᅟ︋︊;)V */
void Java_I__0115f_0fe0c_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Landroid_view_KeyEvent_2LI__0115f_0fe0b_0fe0a_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jboolean v8 = 0;
  jobject v10 = NULL;
  jobject v1 = NULL;
  jboolean v7 = 0;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v11 = NULL;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jboolean v13 = 0;
  jboolean v12 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︊"), "ᅟ︃︀", "Landroid/view/KeyEvent;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︊"), "ᅟ︄︀", "LI/ᅟ︋︊;"), (jobject)(intptr_t)v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︌"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v5 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getKeyMetaStates", "()LI/ᅠ︌︀;"), v0, v0, v0, v0);
  v6 = v5;
  v7 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅠ︌︀"), "ᅟ︁︀", "()Z"), v0, v0, v0, v0);
  v8 = v7;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︊"), "ᅟ︅︀", "Z"), v8);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︈︌"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v10 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getKeyMetaStates", "()LI/ᅠ︌︀;"), v0, v0, v0, v0);
  v11 = v10;
  v12 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v11, env->GetMethodID(env->FindClass("I/ᅠ︌︀"), "ᅟ︀︀", "()Z"), v0, v0, v0, v0);
  v13 = v12;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︌︊"), "ᅟ︆︀", "Z"), v13);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;Landroid/view/KeyEvent;LI/ᅟ︋︊;)V -> Java_I__0115f_0fe0c_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Landroid_view_KeyEvent_2LI__0115f_0fe0b_0fe0a_2 */

/* LI/ᅟ︍︁;-><init>(Landroidx/drawerlayout/widget/DrawerLayout;Landroid/widget/ImageView;Landroid/widget/LinearLayout;Lcom/google/android/material/bottomnavigation/BottomNavigationView;Landroid/widget/LinearLayout;Landroidx/drawerlayout/widget/DrawerLayout;Landroidx/recyclerview/widget/RecyclerView;Landroidx/appcompat/widget/Toolbar;Landroid/widget/FrameLayout;Landroidx/coordinatorlayout/widget/CoordinatorLayout;Landroid/widget/ImageView;Lbin/nt/ui/HackyViewPager;Landroid/view/View;Lcom/google/android/material/tabs/TabLayout;Landroid/widget/ImageView;Landroidx/appcompat/widget/Toolbar;)V */
void Java_I__0115f_0fe0d_0fe01__0003cinit_0003e__Landroidx_drawerlayout_widget_DrawerLayout_2Landroid_widget_ImageView_2Landroid_widget_LinearLayout_2Lcom_google_android_material_bottomnavigation_BottomNavigationView_2Landroid_widget_LinearLayout_2Landroidx_drawerlayout_widget_DrawerLayout_2Landroidx_recyclerview_widget_RecyclerView_2Landroidx_appcompat_widget_Toolbar_2Landroid_widget_FrameLayout_2Landroidx_coordinatorlayout_widget_CoordinatorLayout_2Landroid_widget_ImageView_2Lbin_nt_ui_HackyViewPager_2Landroid_view_View_2Lcom_google_android_material_tabs_TabLayout_2Landroid_widget_ImageView_2Landroidx_appcompat_widget_Toolbar_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4, jobject p5, jobject p6, jobject p7, jobject p8, jobject p9, jobject p10, jobject p11, jobject p12, jobject p13, jobject p14, jobject p15) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v15 = NULL;
  jobject v2 = NULL;
  jobject v9 = NULL;
  jobject v23 = NULL;
  jobject v32 = NULL;
  jobject v6 = NULL;
  jobject v8 = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jobject v26 = NULL;
  jobject v24 = NULL;
  jobject v13 = NULL;
  jobject v29 = NULL;
  jobject v14 = NULL;
  jobject v10 = NULL;
  jobject v7 = NULL;
  jobject v31 = NULL;
  jobject v19 = NULL;
  jobject v21 = NULL;
  jobject v12 = NULL;
  jobject v22 = NULL;
  jobject v11 = NULL;
  jobject v25 = NULL;
  jobject v18 = NULL;
  jobject v4 = NULL;
  jobject v17 = NULL;
  jobject v28 = NULL;
  jobject v1 = NULL;
  jobject v27 = NULL;
  jobject v20 = NULL;
  jobject v16 = NULL;
  jobject v30 = NULL;

L_0:
  /* dbg-move v17 v0 dv=Ljava/lang/Object; sv=LI/ᅟ︍︁; */
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v17, v17, v17, v17);
  /* dbg-move v18 v2 dv=Ljava/lang/Object; sv=Landroid/widget/ImageView; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︀︀", "Landroid/widget/ImageView;"), (jobject)(intptr_t)v18);
  /* dbg-move v19 v3 dv=Ljava/lang/Object; sv=Landroid/widget/LinearLayout; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︁︀", "Landroid/widget/LinearLayout;"), (jobject)(intptr_t)v19);
  /* dbg-move v20 v4 dv=Ljava/lang/Object; sv=Lcom/google/android/material/bottomnavigation/BottomNavigationView; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︂︀", "Lcom/google/android/material/bottomnavigation/BottomNavigationView;"), (jobject)(intptr_t)v20);
  /* dbg-move v21 v5 dv=Ljava/lang/Object; sv=Landroid/widget/LinearLayout; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︃︀", "Landroid/widget/LinearLayout;"), (jobject)(intptr_t)v21);
  /* dbg-move v22 v6 dv=Ljava/lang/Object; sv=Landroidx/drawerlayout/widget/DrawerLayout; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︄︀", "Landroidx/drawerlayout/widget/DrawerLayout;"), (jobject)(intptr_t)v22);
  /* dbg-move v23 v7 dv=Ljava/lang/Object; sv=Landroidx/recyclerview/widget/RecyclerView; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︅︀", "Landroidx/recyclerview/widget/RecyclerView;"), (jobject)(intptr_t)v23);
  /* dbg-move v24 v8 dv=Ljava/lang/Object; sv=Landroidx/appcompat/widget/Toolbar; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︆︀", "Landroidx/appcompat/widget/Toolbar;"), (jobject)(intptr_t)v24);
  /* dbg-move v25 v9 dv=Ljava/lang/Object; sv=Landroid/widget/FrameLayout; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︇︀", "Landroid/widget/FrameLayout;"), (jobject)(intptr_t)v25);
  /* dbg-move v26 v10 dv=Ljava/lang/Object; sv=Landroidx/coordinatorlayout/widget/CoordinatorLayout; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︈︀", "Landroidx/coordinatorlayout/widget/CoordinatorLayout;"), (jobject)(intptr_t)v26);
  /* dbg-move v27 v11 dv=Ljava/lang/Object; sv=Landroid/widget/ImageView; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︉︀", "Landroid/widget/ImageView;"), (jobject)(intptr_t)v27);
  /* dbg-move v28 v12 dv=Ljava/lang/Object; sv=Lbin/nt/ui/HackyViewPager; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︊︀", "Lbin/nt/ui/HackyViewPager;"), (jobject)(intptr_t)v28);
  /* dbg-move v29 v13 dv=Ljava/lang/Object; sv=Landroid/view/View; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︋︀", "Landroid/view/View;"), (jobject)(intptr_t)v29);
  /* dbg-move v30 v14 dv=Ljava/lang/Object; sv=Lcom/google/android/material/tabs/TabLayout; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︌︀", "Lcom/google/android/material/tabs/TabLayout;"), (jobject)(intptr_t)v30);
  /* dbg-move v31 v15 dv=Ljava/lang/Object; sv=Landroid/widget/ImageView; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︍︀", "Landroid/widget/ImageView;"), (jobject)(intptr_t)v31);
  /* dbg-move v32 v16 dv=Ljava/lang/Object; sv=Landroidx/appcompat/widget/Toolbar; */
  env->SetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︎︀", "Landroidx/appcompat/widget/Toolbar;"), (jobject)(intptr_t)v32);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Landroidx/drawerlayout/widget/DrawerLayout;Landroid/widget/ImageView;Landroid/widget/LinearLayout;Lcom/google/android/material/bottomnavigation/BottomNavigationView;Landroid/widget/LinearLayout;Landroidx/drawerlayout/widget/DrawerLayout;Landroidx/recyclerview/widget/RecyclerView;Landroidx/appcompat/widget/Toolbar;Landroid/widget/FrameLayout;Landroidx/coordinatorlayout/widget/CoordinatorLayout;Landroid/widget/ImageView;Lbin/nt/ui/HackyViewPager;Landroid/view/View;Lcom/google/android/material/tabs/TabLayout;Landroid/widget/ImageView;Landroidx/appcompat/widget/Toolbar;)V -> Java_I__0115f_0fe0d_0fe01__0003cinit_0003e__Landroidx_drawerlayout_widget_DrawerLayout_2Landroid_widget_ImageView_2Landroid_widget_LinearLayout_2Lcom_google_android_material_bottomnavigation_BottomNavigationView_2Landroid_widget_LinearLayout_2Landroidx_drawerlayout_widget_DrawerLayout_2Landroidx_recyclerview_widget_RecyclerView_2Landroidx_appcompat_widget_Toolbar_2Landroid_widget_FrameLayout_2Landroidx_coordinatorlayout_widget_CoordinatorLayout_2Landroid_widget_ImageView_2Lbin_nt_ui_HackyViewPager_2Landroid_view_View_2Lcom_google_android_material_tabs_TabLayout_2Landroid_widget_ImageView_2Landroidx_appcompat_widget_Toolbar_2 */

/* LI/ᅟ︎︁;-><init>(Landroid/widget/FrameLayout;Landroid/widget/LinearLayout;Landroid/widget/FrameLayout;Landroid/widget/TextView;Lbin/nt/ui/HackyViewPager;Landroid/widget/CheckBox;Landroid/widget/ImageButton;Landroidx/appcompat/widget/Toolbar;Landroid/widget/FrameLayout;)V */
void Java_I__0115f_0fe0e_0fe01__0003cinit_0003e__Landroid_widget_FrameLayout_2Landroid_widget_LinearLayout_2Landroid_widget_FrameLayout_2Landroid_widget_TextView_2Lbin_nt_ui_HackyViewPager_2Landroid_widget_CheckBox_2Landroid_widget_ImageButton_2Landroidx_appcompat_widget_Toolbar_2Landroid_widget_FrameLayout_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4, jobject p5, jobject p6, jobject p7, jobject p8) {
  jthrowable pendingException = NULL;
  jobject v8 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v6 = NULL;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jobject v7 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︀︀", "Landroid/widget/FrameLayout;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︁︀", "Landroid/widget/LinearLayout;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︂︀", "Landroid/widget/FrameLayout;"), (jobject)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︃︀", "Landroid/widget/TextView;"), (jobject)(intptr_t)v4);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︄︀", "Lbin/nt/ui/HackyViewPager;"), (jobject)(intptr_t)v5);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︅︀", "Landroid/widget/CheckBox;"), (jobject)(intptr_t)v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︆︀", "Landroid/widget/ImageButton;"), (jobject)(intptr_t)v7);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︇︀", "Landroidx/appcompat/widget/Toolbar;"), (jobject)(intptr_t)v8);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︈︀", "Landroid/widget/FrameLayout;"), (jobject)(intptr_t)v9);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Landroid/widget/FrameLayout;Landroid/widget/LinearLayout;Landroid/widget/FrameLayout;Landroid/widget/TextView;Lbin/nt/ui/HackyViewPager;Landroid/widget/CheckBox;Landroid/widget/ImageButton;Landroidx/appcompat/widget/Toolbar;Landroid/widget/FrameLayout;)V -> Java_I__0115f_0fe0e_0fe01__0003cinit_0003e__Landroid_widget_FrameLayout_2Landroid_widget_LinearLayout_2Landroid_widget_FrameLayout_2Landroid_widget_TextView_2Lbin_nt_ui_HackyViewPager_2Landroid_widget_CheckBox_2Landroid_widget_ImageButton_2Landroidx_appcompat_widget_Toolbar_2Landroid_widget_FrameLayout_2 */

/* LI/ᅟ︎︊;-><init>(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︂︅;Landroid/view/MotionEvent;)V */
void Java_I__0115f_0fe0e_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe02_0fe05_2Landroid_view_MotionEvent_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︊"), "ᅟ︂︀", "LI/ᅟ︂︅;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︊"), "ᅟ︃︀", "Landroid/view/MotionEvent;"), (jobject)(intptr_t)v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︂︅;Landroid/view/MotionEvent;)V -> Java_I__0115f_0fe0e_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe02_0fe05_2Landroid_view_MotionEvent_2 */

/* LI/ᅟ︎︌;-><init>(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V */
void Java_I__0115f_0fe0e_0fe0c__0003cinit_0003e__Lbin_nt_ui_fastscroll_FastScrollerRecyclerView_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︎︌"), "ᅟ︀︀", "Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView$OnScrollListener"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V -> Java_I__0115f_0fe0e_0fe0c__0003cinit_0003e__Lbin_nt_ui_fastscroll_FastScrollerRecyclerView_2 */

/* FAILED LI/ᅟ️︁;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅟ️︁;-><init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅠ︉︌;)V */
void Java_I__0115f_0fe0f_0fe01__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__01160_0fe09_0fe0c_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︁︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︀︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/FileBrowserFragment;LI/ᅠ︉︌;)V -> Java_I__0115f_0fe0f_0fe01__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__01160_0fe09_0fe0c_2 */

/* LI/ᅟ️︁;->ᅟ︂︀(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︅︇;LI/ᅟ︍︆;LI/ᅟ︌︊;LI/ᅠ︋︀;)Z */
jboolean Java_I__0115f_0fe0f_0fe01__0115f_0fe02_0fe00__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe05_0fe07_2LI__0115f_0fe0d_0fe06_2LI__0115f_0fe0c_0fe0a_2LI__01160_0fe0b_0fe00_2(JNIEnv* env, jclass clazz, jobject p0, jobject p1, jobject p2, jobject p3, jobject p4) {
  jthrowable pendingException = NULL;
  jint v22 = 0;
  jint v8 = 0;
  jboolean v20 = 0;
  jobject v1 = NULL;
  jlong v24 = 0;
  jobject v2 = NULL;
  jobject v14 = NULL;
  jobject v10 = NULL;
  jobject v7 = NULL;
  jboolean v18 = 0;
  jint v21 = 0;
  jboolean v17 = 0;
  jobject v3 = NULL;
  jobject v5 = NULL;
  jobject v12 = NULL;
  jobject v15 = NULL;
  jobject v13 = NULL;
  jint v11 = 0;
  jobject v0 = NULL;
  jobject v6 = NULL;
  jint v16 = 0;
  jobject v9 = NULL;
  jlong v23 = 0;
  jobject v4 = NULL;
  jboolean v19 = 0;

L_0:
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v0, v0, v0, v0);
  v7 = (jobject)(intptr_t)v6;
  v8 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I"));
  v9 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ️︀", "(I)LI/ᅟ︁︇;"), v8, v0, v0, v0);
  v10 = v9;
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("I/ᅟ︁︇"), "ᅟ︆︀", "I"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ️︃", "(II)V"), v8, v11, v0, v0);
  v12 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getLineSeparator", "()LI/ᅠ︉︁;"), v0, v0, v0, v0);
  v13 = v12;
  v14 = (jobject)env->CallObjectMethod((jobject)v13, env->GetMethodID(env->FindClass("I/ᅠ︉︁"), "ᅟ︀︀", "()Ljava/lang/String;"), v0, v0, v0, v0);
  v15 = v14;
  v16 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︀", "(Ljava/lang/CharSequence;ZZ)V"), v15, v16, v16, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︂", "()V"), v0, v0, v0, v0);
  v17 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v16, v0, v0, v0);
  v18 = v17;
  /* UNSUPPORTED: if-nez */
  if (v18 != 0) { v22 = (jint)v16; goto L_2e;
 } else { goto L_26;
 }

L_26:
  v19 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v16, v18, v18, v18);
  v20 = v19;
  /* UNSUPPORTED: if-eqz */
  if (v20 == 0) { goto L_2d;
 } else { goto L_2c;
 }

L_2c:
  /* UNSUPPORTED: goto */
v22 = (jint)(intptr_t)v23; goto L_2e;

L_2d:
  v21 = 0;
v22 = (jint)(intptr_t)v24; goto L_2e;

L_2e:
  /* return terminator */
  return (jboolean)(intptr_t)v22;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︂︀(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︅︇;LI/ᅟ︍︆;LI/ᅟ︌︊;LI/ᅠ︋︀;)Z -> Java_I__0115f_0fe0f_0fe01__0115f_0fe02_0fe00__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe05_0fe07_2LI__0115f_0fe0d_0fe06_2LI__0115f_0fe0c_0fe0a_2LI__01160_0fe0b_0fe00_2 */

/* LI/ᅠ︀︄;-><init>(Lbin/nt/main/PhotoViewerActivity;)V */
void Java_I__01160_0fe00_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︀︄"), "ᅟ︀︀", "Lbin/nt/main/PhotoViewerActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/PhotoViewerActivity;)V -> Java_I__01160_0fe00_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2 */

/* LI/ᅠ︁︂;-><init>(Lbin/nt/main/MainActivity;I)V */
void Java_I__01160_0fe01_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︁︂"), "ᅟ︀︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︁︂"), "ᅟ︁︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;I)V -> Java_I__01160_0fe01_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I */

/* FAILED LI/ᅠ︃︃;-><init>(Lbin/nt/editor/widget/CodeEditor;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅠ︇︂;-><init>(Lbin/nt/main/MainActivity;)V */
void Java_I__01160_0fe07_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︇︂"), "ᅟ︀︀", "Lbin/nt/main/MainActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("com/google/android/material/bottomsheet/BottomSheetBehavior$BottomSheetCallback"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;)V -> Java_I__01160_0fe07_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2 */

/* LI/ᅠ︇︈;-><init>(Lbin/nt/editor/widget/CodeEditor;)V */
void Java_I__01160_0fe07_0fe08__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  v2 = 3;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︇︈"), "ᅟ︂︀", "I"), v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;)V -> Java_I__01160_0fe07_0fe08__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2 */

/* LI/ᅠ︈︄;-><init>(Lbin/nt/main/PhotoViewerActivity;)V */
void Java_I__01160_0fe08_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︄"), "ᅟ︂︀", "Lbin/nt/main/PhotoViewerActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/viewpager/widget/PagerAdapter"), "<init>", "()V"), v0, v0, v0, v0);
  v2 = env->AllocObject(env->FindClass("java/util/ArrayList"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("java/util/ArrayList"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︈︄"), "ᅟ︁︀", "Ljava/util/ArrayList;"), (jobject)(intptr_t)v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/PhotoViewerActivity;)V -> Java_I__01160_0fe08_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2 */

/* LI/ᅠ︉︂;-><init>(Lbin/nt/main/MainActivity;Landroid/widget/FrameLayout;Landroid/widget/FrameLayout;)V */
void Java_I__01160_0fe09_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Landroid_widget_FrameLayout_2Landroid_widget_FrameLayout_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v10 = NULL;
  jobject v2 = NULL;
  jobject v9 = NULL;
  jobject v6 = NULL;
  jint v7 = 0;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v8 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︂"), "ᅟ︂︀", "Landroid/view/View;"), (jobject)(intptr_t)v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︂"), "ᅟ︃︀", "Landroid/view/View;"), (jobject)(intptr_t)v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/viewpager/widget/PagerAdapter"), "<init>", "()V"), v0, v0, v0, v0);
  v4 = 2131886312;
  v5 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("android/content/Context"), "getString", "(I)Ljava/lang/String;"), v4, v0, v0, v0);
  v6 = v5;
  v7 = 2131886311;
  v8 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("android/content/Context"), "getString", "(I)Ljava/lang/String;"), v7, v0, v0, v0);
  v9 = v8;
  v10 = env->NewObjectArray((jsize)(intptr_t)5, env->FindClass("java/lang/String"), NULL); env->SetObjectArrayElement((jobjectArray)v10, 0, (jobject)v6); env->SetObjectArrayElement((jobjectArray)v10, 1, (jobject)v9); env->SetObjectArrayElement((jobjectArray)v10, 2, (jobject)v0); env->SetObjectArrayElement((jobjectArray)v10, 3, (jobject)v0); env->SetObjectArrayElement((jobjectArray)v10, 4, (jobject)v0);
  v10 = v8;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︂"), "ᅟ︁︀", "[Ljava/lang/String;"), (jobject)(intptr_t)v10);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/MainActivity;Landroid/widget/FrameLayout;Landroid/widget/FrameLayout;)V -> Java_I__01160_0fe09_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Landroid_widget_FrameLayout_2Landroid_widget_FrameLayout_2 */

/* LI/ᅠ︉︆;-><init>(Lbin/nt/editor/widget/CodeEditor;IIIII)V */
void Java_I__01160_0fe09_0fe06__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2IIIII(JNIEnv* env, jobject thiz, jobject p0, jint p1, jint p2, jint p3, jint p4, jint p5) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jint v3 = 0;
  jint v4 = 0;
  jobject v1 = NULL;
  jint v5 = 0;
  jint v6 = 0;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v1, v0, v0, v0);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︆"), "ᅟ︂︀", "I"), v2);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︆"), "ᅟ︃︀", "I"), v3);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︆"), "ᅟ︄︀", "I"), v4);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︆"), "ᅟ︅︀", "I"), v5);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︆"), "ᅟ︆︀", "I"), v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;IIIII)V -> Java_I__01160_0fe09_0fe06__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2IIIII */

/* LI/ᅠ︉︉;-><init>(Lbin/nt/main/TextEditorActivity;I)V */
void Java_I__01160_0fe09_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I(JNIEnv* env, jobject thiz, jobject p0, jint p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v2 = 0;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︉"), "ᅟ︀︀", "I"), v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︉︉"), "ᅟ︁︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;I)V -> Java_I__01160_0fe09_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I */

/* LI/ᅠ︊︄;-><init>(Lbin/nt/fragments/PreferenceFragment;)V */
void Java_I__01160_0fe0a_0fe04__0003cinit_0003e__Lbin_nt_fragments_PreferenceFragment_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︊︄"), "ᅟ︀︀", "Lbin/nt/fragments/PreferenceFragment;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/PreferenceFragment;)V -> Java_I__01160_0fe0a_0fe04__0003cinit_0003e__Lbin_nt_fragments_PreferenceFragment_2 */

/* FAILED LI/ᅠ︊︆;-><init>(Lbin/nt/editor/widget/CodeEditor;I)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* LI/ᅠ︋︄;-><init>(Lbin/nt/fragments/PreferenceFragment;Landroidx/preference/Preference;I)V */
void Java_I__01160_0fe0b_0fe04__0003cinit_0003e__Lbin_nt_fragments_PreferenceFragment_2Landroidx_preference_Preference_2I(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jint p2) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jint v3 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︋︄"), "ᅟ︀︀", "I"), v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︋︄"), "ᅟ︁︀", "Lbin/nt/fragments/PreferenceFragment;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︋︄"), "ᅟ︂︀", "Landroidx/preference/Preference;"), (jobject)(intptr_t)v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/fragments/PreferenceFragment;Landroidx/preference/Preference;I)V -> Java_I__01160_0fe0b_0fe04__0003cinit_0003e__Lbin_nt_fragments_PreferenceFragment_2Landroidx_preference_Preference_2I */

/* LI/ᅠ︋︉;-><init>(Lbin/nt/main/TextEditorActivity;)V */
void Java_I__01160_0fe0b_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︋︉"), "ᅟ︄︀", "Lbin/nt/main/TextEditorActivity;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/TextEditorActivity;)V -> Java_I__01160_0fe0b_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2 */

/* Lbin/nt/editor/widget/CodeEditor;-><clinit>()V */
void Java_bin_nt_editor_widget_CodeEditor__0003cclinit_0003e__(JNIEnv* env, jclass clazz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v0 = env->NewStringUTF("CodeEditor");
  v1 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅠ︋︁"), env->GetStaticMethodID(env->FindClass("I/ᅠ︋︁"), "ᅟ︀︀", "(Ljava/lang/String;)LI/ᅠ︋︁;"), v0, v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <clinit>()V -> Java_bin_nt_editor_widget_CodeEditor__0003cclinit_0003e__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;-><init>(Landroid/content/Context;Landroid/util/AttributeSet;)V: java.lang.IllegalStateException: unknown phi type v4_6 = phi[v4_5, v4_1] */

/* Lbin/nt/editor/widget/CodeEditor;->computeHorizontalScrollExtent()I */
jint Java_bin_nt_editor_widget_CodeEditor_computeHorizontalScrollExtent__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  v1 = 0;
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for computeHorizontalScrollExtent()I -> Java_bin_nt_editor_widget_CodeEditor_computeHorizontalScrollExtent__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->computeHorizontalScrollOffset()I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->computeHorizontalScrollRange()I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->computeScroll()V: java.lang.IllegalStateException: unknown phi type v6_2 = phi[v6_4 = phi[v6_0, v6_0], v6_4 = phi[v6_0, v6_0], v6_8 = phi[v6_23 = phi[v6_12 = phi[v6_4 = phi[v6_0, v6_0], v6_4 = phi[v6_0, v6_0]], v6_12 = phi[v6_4 = phi[v6_0, v6_0], v6_4 = phi[v6_0, v6_0]]], v6_23 = phi[v6_12 = phi[v6_4 = phi[v6_0, v6_0], v6_4 = phi[v6_0, v6_0]], v6_12 = phi[v6_4 = phi[v6_0, v6_0], v6_4 = phi[v6_0, v6_0]]]]] */

/* Lbin/nt/editor/widget/CodeEditor;->computeVerticalScrollExtent()I */
jint Java_bin_nt_editor_widget_CodeEditor_computeVerticalScrollExtent__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = 0;
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for computeVerticalScrollExtent()I -> Java_bin_nt_editor_widget_CodeEditor_computeVerticalScrollExtent__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->computeVerticalScrollOffset()I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->computeVerticalScrollRange()I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->createAccessibilityNodeInfo()Landroid/view/accessibility/AccessibilityNodeInfo;: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->dispatchTouchEvent(Landroid/view/MotionEvent;)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->getAccessibilityClassName()Ljava/lang/CharSequence; */
jobject Java_bin_nt_editor_widget_CodeEditor_getAccessibilityClassName__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;

L_0:
  v1 = env->FindClass("bin/nt/editor/widget/CodeEditor");
  v2 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("java/lang/Class"), "getName", "()Ljava/lang/String;"), v1, v1, v1, v1);
  v3 = v2;
  /* return terminator */
  return (jobject)(intptr_t)v3;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getAccessibilityClassName()Ljava/lang/CharSequence; -> Java_bin_nt_editor_widget_CodeEditor_getAccessibilityClassName__ */

/* Lbin/nt/editor/widget/CodeEditor;->getBlockIndex()I */
jint Java_bin_nt_editor_widget_CodeEditor_getBlockIndex__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getBlockIndex()I -> Java_bin_nt_editor_widget_CodeEditor_getBlockIndex__ */

/* Lbin/nt/editor/widget/CodeEditor;->getBlockLineWidth()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getBlockLineWidth__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getBlockLineWidth()F -> Java_bin_nt_editor_widget_CodeEditor_getBlockLineWidth__ */

/* Lbin/nt/editor/widget/CodeEditor;->getClipboardManager()Landroid/content/ClipboardManager; */
jobject Java_bin_nt_editor_widget_CodeEditor_getClipboardManager__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︄", "Landroid/content/ClipboardManager;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getClipboardManager()Landroid/content/ClipboardManager; -> Java_bin_nt_editor_widget_CodeEditor_getClipboardManager__ */

/* Lbin/nt/editor/widget/CodeEditor;->getColorScheme()LI/ᅟ︌︉; */
jobject Java_bin_nt_editor_widget_CodeEditor_getColorScheme__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︄", "LI/ᅟ︌︉;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getColorScheme()LI/ᅟ︌︉; -> Java_bin_nt_editor_widget_CodeEditor_getColorScheme__ */

/* Lbin/nt/editor/widget/CodeEditor;->getCurrentCursorBlock()I */
jint Java_bin_nt_editor_widget_CodeEditor_getCurrentCursorBlock__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getCurrentCursorBlock()I -> Java_bin_nt_editor_widget_CodeEditor_getCurrentCursorBlock__ */

/* Lbin/nt/editor/widget/CodeEditor;->getCursor()LI/ᅟ︅︇; */
jobject Java_bin_nt_editor_widget_CodeEditor_getCursor__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getCursor()LI/ᅟ︅︇; -> Java_bin_nt_editor_widget_CodeEditor_getCursor__ */

/* Lbin/nt/editor/widget/CodeEditor;->getCursorAnimator()LI/ᅟ︆︇; */
jobject Java_bin_nt_editor_widget_CodeEditor_getCursorAnimator__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︅", "LI/ᅟ︆︇;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getCursorAnimator()LI/ᅟ︆︇; -> Java_bin_nt_editor_widget_CodeEditor_getCursorAnimator__ */

/* Lbin/nt/editor/widget/CodeEditor;->getCursorBlink()LI/ᅟ︇︇; */
jobject Java_bin_nt_editor_widget_CodeEditor_getCursorBlink__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︅", "LI/ᅟ︇︇;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getCursorBlink()LI/ᅟ︇︇; -> Java_bin_nt_editor_widget_CodeEditor_getCursorBlink__ */

/* Lbin/nt/editor/widget/CodeEditor;->getCursorRange()LI/ᅠ️︉; */
jobject Java_bin_nt_editor_widget_CodeEditor_getCursorRange__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v7 = NULL;
  jobject v3 = NULL;
  jobject v8 = NULL;
  jobject v6 = NULL;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v2 = env->AllocObject(env->FindClass("I/ᅠ️︉"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v1, v1, v1, v1);
  v5 = (jobject)(intptr_t)v4;
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v7 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v6, v6, v6, v6);
  v8 = (jobject)(intptr_t)v7;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅠ️︉"), "<init>", "(LI/ᅟ︂︅;LI/ᅟ︂︅;)V"), v5, v8, v8, v8);
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getCursorRange()LI/ᅠ️︉; -> Java_bin_nt_editor_widget_CodeEditor_getCursorRange__ */

/* Lbin/nt/editor/widget/CodeEditor;->getDiagnosticIndicatorStyle()LI/ᅟ︄︈; */
jobject Java_bin_nt_editor_widget_CodeEditor_getDiagnosticIndicatorStyle__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︄", "LI/ᅟ︄︈;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getDiagnosticIndicatorStyle()LI/ᅟ︄︈; -> Java_bin_nt_editor_widget_CodeEditor_getDiagnosticIndicatorStyle__ */

/* Lbin/nt/editor/widget/CodeEditor;->getDiagnostics()LI/ᅟ︅︈; */
jobject Java_bin_nt_editor_widget_CodeEditor_getDiagnostics__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  v1 = 0;
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getDiagnostics()LI/ᅟ︅︈; -> Java_bin_nt_editor_widget_CodeEditor_getDiagnostics__ */

/* Lbin/nt/editor/widget/CodeEditor;->getDividerMarginLeft()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getDividerMarginLeft__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getDividerMarginLeft()F -> Java_bin_nt_editor_widget_CodeEditor_getDividerMarginLeft__ */

/* Lbin/nt/editor/widget/CodeEditor;->getDividerMarginRight()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getDividerMarginRight__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getDividerMarginRight()F -> Java_bin_nt_editor_widget_CodeEditor_getDividerMarginRight__ */

/* Lbin/nt/editor/widget/CodeEditor;->getDividerWidth()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getDividerWidth__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getDividerWidth()F -> Java_bin_nt_editor_widget_CodeEditor_getDividerWidth__ */

/* Lbin/nt/editor/widget/CodeEditor;->getDpUnit()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getDpUnit__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getDpUnit()F -> Java_bin_nt_editor_widget_CodeEditor_getDpUnit__ */

/* Lbin/nt/editor/widget/CodeEditor;->getEdgeEffectColor()I */
jint Java_bin_nt_editor_widget_CodeEditor_getEdgeEffectColor__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jint v2 = 0;
  jint v3 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︅", "Landroid/widget/EdgeEffect;"));
  v2 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("android/widget/EdgeEffect"), "getColor", "()I"), v1, v1, v1, v1);
  v3 = v2;
  /* return terminator */
  return (jint)(intptr_t)v3;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getEdgeEffectColor()I -> Java_bin_nt_editor_widget_CodeEditor_getEdgeEffectColor__ */

/* Lbin/nt/editor/widget/CodeEditor;->getEditable()Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_getEditable__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︂", "Z"));
  /* return terminator */
  return (jboolean)(intptr_t)v1;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for getEditable()Z -> Java_bin_nt_editor_widget_CodeEditor_getEditable__ */

/* Lbin/nt/editor/widget/CodeEditor;->getEditorLanguage()LI/ᅠ︍︀; */
jobject Java_bin_nt_editor_widget_CodeEditor_getEditorLanguage__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︄", "LI/ᅠ︍︀;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getEditorLanguage()LI/ᅠ︍︀; -> Java_bin_nt_editor_widget_CodeEditor_getEditorLanguage__ */

/* Lbin/nt/editor/widget/CodeEditor;->getEventHandler()LI/ᅟ︄︌; */
jobject Java_bin_nt_editor_widget_CodeEditor_getEventHandler__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getEventHandler()LI/ᅟ︄︌; -> Java_bin_nt_editor_widget_CodeEditor_getEventHandler__ */

/* Lbin/nt/editor/widget/CodeEditor;->getExtraArguments()Landroid/os/Bundle; */
jobject Java_bin_nt_editor_widget_CodeEditor_getExtraArguments__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︅", "Landroid/os/Bundle;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getExtraArguments()Landroid/os/Bundle; -> Java_bin_nt_editor_widget_CodeEditor_getExtraArguments__ */

/* Lbin/nt/editor/widget/CodeEditor;->getFirstVisibleLine()I */
jint Java_bin_nt_editor_widget_CodeEditor_getFirstVisibleLine__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v5 = 0;
  jint v2 = 0;
  jint v4 = 0;
  jobject v1 = NULL;
  jint v3 = 0;
  jobject v0 = NULL;
  jint v6 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v2 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getFirstVisibleRow", "()I"), v1, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v3 = v2;
  v4 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("I/ᅠ︁︁"), "ᅟ︃︁", "(I)I"), v3, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v5 = v4;
goto L_a;

L_b:
  v6 = 0;
  /* return terminator */
  return (jint)(intptr_t)v6;

L_a:
  /* return terminator */
  return (jint)(intptr_t)v5;

EX_LandingPad_0:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/IndexOutOfBoundsException"))) goto L_b;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getFirstVisibleLine()I -> Java_bin_nt_editor_widget_CodeEditor_getFirstVisibleLine__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->getFirstVisibleRow()I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->getFormatTip()Ljava/lang/String; */
jobject Java_bin_nt_editor_widget_CodeEditor_getFormatTip__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︄", "Ljava/lang/String;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getFormatTip()Ljava/lang/String; -> Java_bin_nt_editor_widget_CodeEditor_getFormatTip__ */

/* Lbin/nt/editor/widget/CodeEditor;->getGraphPaint()LI/ᅠ︎︃; */
jobject Java_bin_nt_editor_widget_CodeEditor_getGraphPaint__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︆︀", "LI/ᅠ︎︃;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getGraphPaint()LI/ᅠ︎︃; -> Java_bin_nt_editor_widget_CodeEditor_getGraphPaint__ */

/* Lbin/nt/editor/widget/CodeEditor;->getHandleStyle()LI/ᅠ︌︆; */
jobject Java_bin_nt_editor_widget_CodeEditor_getHandleStyle__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︅", "LI/ᅠ︌︆;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getHandleStyle()LI/ᅠ︌︆; -> Java_bin_nt_editor_widget_CodeEditor_getHandleStyle__ */

/* Lbin/nt/editor/widget/CodeEditor;->getHighlightTexts()LI/ᅟ︉️; */
jobject Java_bin_nt_editor_widget_CodeEditor_getHighlightTexts__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = 0;
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getHighlightTexts()LI/ᅟ︉️; -> Java_bin_nt_editor_widget_CodeEditor_getHighlightTexts__ */

/* Lbin/nt/editor/widget/CodeEditor;->getHorizontalEdgeEffect()Landroid/widget/EdgeEffect; */
jobject Java_bin_nt_editor_widget_CodeEditor_getHorizontalEdgeEffect__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︅", "Landroid/widget/EdgeEffect;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getHorizontalEdgeEffect()Landroid/widget/EdgeEffect; -> Java_bin_nt_editor_widget_CodeEditor_getHorizontalEdgeEffect__ */

/* Lbin/nt/editor/widget/CodeEditor;->getHorizontalScrollbarThumbDrawable()Landroid/graphics/drawable/Drawable; */
jobject Java_bin_nt_editor_widget_CodeEditor_getHorizontalScrollbarThumbDrawable__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︁", "Landroid/graphics/drawable/Drawable;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getHorizontalScrollbarThumbDrawable()Landroid/graphics/drawable/Drawable; -> Java_bin_nt_editor_widget_CodeEditor_getHorizontalScrollbarThumbDrawable__ */

/* Lbin/nt/editor/widget/CodeEditor;->getHorizontalScrollbarTrackDrawable()Landroid/graphics/drawable/Drawable; */
jobject Java_bin_nt_editor_widget_CodeEditor_getHorizontalScrollbarTrackDrawable__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︃︁", "Landroid/graphics/drawable/Drawable;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getHorizontalScrollbarTrackDrawable()Landroid/graphics/drawable/Drawable; -> Java_bin_nt_editor_widget_CodeEditor_getHorizontalScrollbarTrackDrawable__ */

/* Lbin/nt/editor/widget/CodeEditor;->getInlayHintRenderers()Ljava/util/List; */
jobject Java_bin_nt_editor_widget_CodeEditor_getInlayHintRenderers__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v4 = NULL;

L_0:
  v1 = env->AllocObject(env->FindClass("java/util/ArrayList"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︆", "Ljava/util/HashMap;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/util/HashMap"), "values", "()Ljava/util/Collection;"), v1, v1, v1, v1);
  v4 = v3;
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("java/util/ArrayList"), "<init>", "(Ljava/util/Collection;)V"), v4, v1, v1, v1);
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getInlayHintRenderers()Ljava/util/List; -> Java_bin_nt_editor_widget_CodeEditor_getInlayHintRenderers__ */

/* Lbin/nt/editor/widget/CodeEditor;->getInlayHints()LI/ᅟ️️; */
jobject Java_bin_nt_editor_widget_CodeEditor_getInlayHints__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  v1 = 0;
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getInlayHints()LI/ᅟ️️; -> Java_bin_nt_editor_widget_CodeEditor_getInlayHints__ */

/* Lbin/nt/editor/widget/CodeEditor;->getInputMethodManager()Landroid/view/inputmethod/InputMethodManager; */
jobject Java_bin_nt_editor_widget_CodeEditor_getInputMethodManager__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "Landroid/view/inputmethod/InputMethodManager;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getInputMethodManager()Landroid/view/inputmethod/InputMethodManager; -> Java_bin_nt_editor_widget_CodeEditor_getInputMethodManager__ */

/* Lbin/nt/editor/widget/CodeEditor;->getInputType()I */
jint Java_bin_nt_editor_widget_CodeEditor_getInputType__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ️︀", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getInputType()I -> Java_bin_nt_editor_widget_CodeEditor_getInputType__ */

/* Lbin/nt/editor/widget/CodeEditor;->getInsertHandleDescriptor()LI/ᅠ︋︆; */
jobject Java_bin_nt_editor_widget_CodeEditor_getInsertHandleDescriptor__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︄", "LI/ᅠ︋︆;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getInsertHandleDescriptor()LI/ᅠ︋︆; -> Java_bin_nt_editor_widget_CodeEditor_getInsertHandleDescriptor__ */

/* Lbin/nt/editor/widget/CodeEditor;->getInsertSelectionWidth()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getInsertSelectionWidth__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getInsertSelectionWidth()F -> Java_bin_nt_editor_widget_CodeEditor_getInsertSelectionWidth__ */

/* Lbin/nt/editor/widget/CodeEditor;->getKeyMetaStates()LI/ᅠ︌︀; */
jobject Java_bin_nt_editor_widget_CodeEditor_getKeyMetaStates__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v3 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︀", "LI/ᅟ️︁;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︌︀"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  /* return terminator */
  return (jobject)(intptr_t)v3;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getKeyMetaStates()LI/ᅠ︌︀; -> Java_bin_nt_editor_widget_CodeEditor_getKeyMetaStates__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLastVisibleLine()I */
jint Java_bin_nt_editor_widget_CodeEditor_getLastVisibleLine__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v8 = 0;
  jobject v1 = NULL;
  jint v5 = 0;
  jint v7 = 0;
  jint v6 = 0;
  jint v2 = 0;
  jint v3 = 0;
  jobject v0 = NULL;
  jint v4 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v2 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getLastVisibleRow", "()I"), v1, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v3 = v2;
  v4 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("I/ᅠ︁︁"), "ᅟ︃︁", "(I)I"), v3, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v5 = v4;
goto L_a;

L_b:
  v6 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getLineCount", "()I"), v5, v5, v5, v5);
  v7 = v6;
  /* UNSUPPORTED: add-int-lit8 */
  /* return terminator */
  return (jint)(intptr_t)v8;

L_a:
  /* return terminator */
  return (jint)(intptr_t)v5;

EX_LandingPad_0:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/IndexOutOfBoundsException"))) goto L_b;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getLastVisibleLine()I -> Java_bin_nt_editor_widget_CodeEditor_getLastVisibleLine__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLastVisibleRow()I */
jint Java_bin_nt_editor_widget_CodeEditor_getLastVisibleRow__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v14 = 0;
  jint v12 = 0;
  jint v17 = 0;
  jint v4 = 0;
  jint v8 = 0;
  jobject v0 = NULL;
  jint v7 = 0;
  jint v13 = 0;
  jint v3 = 0;
  jint v11 = 0;
  jint v6 = 0;
  jobject v1 = NULL;
  jint v5 = 0;
  jint v10 = 0;
  jint v15 = 0;
  jint v16 = 0;
  jint v2 = 0;
  jint v9 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  v2 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("I/ᅠ︁︁"), "ᅟ︀︀", "()I"), v1, v1, v1, v1);
  v3 = v2;
  /* UNSUPPORTED: add-int-lit8 */
  v5 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getOffsetY", "()I"), v4, v4, v4, v4);
  v6 = v5;
  v7 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getHeight", "()I"), v4, v4, v4, v4);
  v8 = v7;
  /* UNSUPPORTED: add-int-2addr */
  v10 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getRowHeight", "()I"), v4, v4, v4, v4);
  v11 = v10;
  /* UNSUPPORTED: div-int-2addr */
  v13 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "min", "(II)I"), v4, v12, v4, v4, v4);
  v14 = v13;
  v15 = 0;
  v16 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v15, v14, v14, v14, v14);
  v17 = v16;
  /* return terminator */
  return (jint)(intptr_t)v17;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getLastVisibleRow()I -> Java_bin_nt_editor_widget_CodeEditor_getLastVisibleRow__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLayout()LI/ᅠ︁︁; */
jobject Java_bin_nt_editor_widget_CodeEditor_getLayout__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLayout()LI/ᅠ︁︁; -> Java_bin_nt_editor_widget_CodeEditor_getLayout__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLeftHandleDescriptor()LI/ᅠ︋︆; */
jobject Java_bin_nt_editor_widget_CodeEditor_getLeftHandleDescriptor__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︃", "LI/ᅠ︋︆;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLeftHandleDescriptor()LI/ᅠ︋︆; -> Java_bin_nt_editor_widget_CodeEditor_getLeftHandleDescriptor__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineCount()I */
jint Java_bin_nt_editor_widget_CodeEditor_getLineCount__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v4 = 0;
  jint v3 = 0;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︍︆"), "ᅟ︄︀", "Ljava/util/ArrayList;"));
  v3 = (jint)(intptr_t)env->CallIntMethod((jobject)v2, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v2, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jint)(intptr_t)v4;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getLineCount()I -> Java_bin_nt_editor_widget_CodeEditor_getLineCount__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineInfoTextSize()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getLineInfoTextSize__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getLineInfoTextSize()F -> Java_bin_nt_editor_widget_CodeEditor_getLineInfoTextSize__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineNumberAlign()Landroid/graphics/Paint$Align; */
jobject Java_bin_nt_editor_widget_CodeEditor_getLineNumberAlign__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︄", "Landroid/graphics/Paint$Align;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLineNumberAlign()Landroid/graphics/Paint$Align; -> Java_bin_nt_editor_widget_CodeEditor_getLineNumberAlign__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineNumberMarginLeft()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getLineNumberMarginLeft__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getLineNumberMarginLeft()F -> Java_bin_nt_editor_widget_CodeEditor_getLineNumberMarginLeft__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineNumberMetrics()Landroid/graphics/Paint$FontMetricsInt; */
jobject Java_bin_nt_editor_widget_CodeEditor_getLineNumberMetrics__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︊︁", "Landroid/graphics/Paint$FontMetricsInt;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLineNumberMetrics()Landroid/graphics/Paint$FontMetricsInt; -> Java_bin_nt_editor_widget_CodeEditor_getLineNumberMetrics__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineNumberTipTextProvider()LI/ᅠ︈︁; */
jobject Java_bin_nt_editor_widget_CodeEditor_getLineNumberTipTextProvider__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︄", "LI/ᅠ︈︁;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLineNumberTipTextProvider()LI/ᅠ︈︁; -> Java_bin_nt_editor_widget_CodeEditor_getLineNumberTipTextProvider__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineSeparator()LI/ᅠ︉︁; */
jobject Java_bin_nt_editor_widget_CodeEditor_getLineSeparator__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︆", "LI/ᅠ︉︁;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getLineSeparator()LI/ᅠ︉︁; -> Java_bin_nt_editor_widget_CodeEditor_getLineSeparator__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineSpacingExtra()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getLineSpacingExtra__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getLineSpacingExtra()F -> Java_bin_nt_editor_widget_CodeEditor_getLineSpacingExtra__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineSpacingMultiplier()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getLineSpacingMultiplier__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getLineSpacingMultiplier()F -> Java_bin_nt_editor_widget_CodeEditor_getLineSpacingMultiplier__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLineSpacingPixels()I */
jint Java_bin_nt_editor_widget_CodeEditor_getLineSpacingPixels__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v5 = 0;
  jfloat v6 = 0;
  jfloat v10 = 0;
  jfloat v13 = 0;
  jint v8 = 0;
  jfloat v7 = 0;
  jfloat v11 = 0;
  jint v14 = 0;
  jint v4 = 0;
  jobject v0 = NULL;
  jfloat v9 = 0;
  jint v15 = 0;
  jfloat v12 = 0;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jint v3 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︁", "Landroid/graphics/Paint$FontMetricsInt;"));
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("android/graphics/Paint$FontMetricsInt"), "descent", "I"));
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("android/graphics/Paint$FontMetricsInt"), "ascent", "I"));
  /* UNSUPPORTED: sub-int-2addr */
  v6 = (jfloat)v5;
  v7 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︁", "F"));
  v8 = 1065353216;
  /* UNSUPPORTED: sub-float-2addr */
  /* UNSUPPORTED: mul-float */
  v11 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︁", "F"));
  /* UNSUPPORTED: add-float-2addr */
  v13 = (jint)v12;
  /* UNSUPPORTED: div-int-lit8 */
  /* UNSUPPORTED: mul-int-lit8 */
  /* return terminator */
  return (jint)(intptr_t)v15;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getLineSpacingPixels()I -> Java_bin_nt_editor_widget_CodeEditor_getLineSpacingPixels__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLnPanelPosition()I */
jint Java_bin_nt_editor_widget_CodeEditor_getLnPanelPosition__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︂", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getLnPanelPosition()I -> Java_bin_nt_editor_widget_CodeEditor_getLnPanelPosition__ */

/* Lbin/nt/editor/widget/CodeEditor;->getLnPanelPositionMode()I */
jint Java_bin_nt_editor_widget_CodeEditor_getLnPanelPositionMode__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︂", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getLnPanelPositionMode()I -> Java_bin_nt_editor_widget_CodeEditor_getLnPanelPositionMode__ */

/* Lbin/nt/editor/widget/CodeEditor;->getNonPrintablePaintingFlags()I */
jint Java_bin_nt_editor_widget_CodeEditor_getNonPrintablePaintingFlags__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︁", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getNonPrintablePaintingFlags()I -> Java_bin_nt_editor_widget_CodeEditor_getNonPrintablePaintingFlags__ */

/* Lbin/nt/editor/widget/CodeEditor;->getOffsetX()I */
jint Java_bin_nt_editor_widget_CodeEditor_getOffsetX__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jint v5 = 0;
  jobject v2 = NULL;
  jobject v3 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︁︀", "LI/ᅟ︈︋;"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ︈︋"), "ᅟ︁︀", "Landroid/widget/OverScroller;"));
  v4 = (jint)(intptr_t)env->CallIntMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/OverScroller"), "getCurrX", "()I"), v3, v3, v3, v3);
  v5 = v4;
  /* return terminator */
  return (jint)(intptr_t)v5;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getOffsetX()I -> Java_bin_nt_editor_widget_CodeEditor_getOffsetX__ */

/* Lbin/nt/editor/widget/CodeEditor;->getOffsetY()I */
jint Java_bin_nt_editor_widget_CodeEditor_getOffsetY__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v3 = NULL;
  jint v5 = 0;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︁︀", "LI/ᅟ︈︋;"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ︈︋"), "ᅟ︁︀", "Landroid/widget/OverScroller;"));
  v4 = (jint)(intptr_t)env->CallIntMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/OverScroller"), "getCurrY", "()I"), v3, v3, v3, v3);
  v5 = v4;
  /* return terminator */
  return (jint)(intptr_t)v5;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getOffsetY()I -> Java_bin_nt_editor_widget_CodeEditor_getOffsetY__ */

/* Lbin/nt/editor/widget/CodeEditor;->getOtherPaint()LI/ᅠ︎︃; */
jobject Java_bin_nt_editor_widget_CodeEditor_getOtherPaint__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︀", "LI/ᅠ︎︃;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getOtherPaint()LI/ᅠ︎︃; -> Java_bin_nt_editor_widget_CodeEditor_getOtherPaint__ */

/* Lbin/nt/editor/widget/CodeEditor;->getProps()LI/ᅟ︆︈; */
jobject Java_bin_nt_editor_widget_CodeEditor_getProps__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︅", "LI/ᅟ︆︈;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getProps()LI/ᅟ︆︈; -> Java_bin_nt_editor_widget_CodeEditor_getProps__ */

/* Lbin/nt/editor/widget/CodeEditor;->getRenderContext()LI/ᅠ︆︅; */
jobject Java_bin_nt_editor_widget_CodeEditor_getRenderContext__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︅", "LI/ᅠ︆︅;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getRenderContext()LI/ᅠ︆︅; -> Java_bin_nt_editor_widget_CodeEditor_getRenderContext__ */

/* Lbin/nt/editor/widget/CodeEditor;->getRenderer()LI/ᅟ︇︋; */
jobject Java_bin_nt_editor_widget_CodeEditor_getRenderer__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getRenderer()LI/ᅟ︇︋; -> Java_bin_nt_editor_widget_CodeEditor_getRenderer__ */

/* Lbin/nt/editor/widget/CodeEditor;->getRightHandleDescriptor()LI/ᅠ︋︆; */
jobject Java_bin_nt_editor_widget_CodeEditor_getRightHandleDescriptor__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ️︃", "LI/ᅠ︋︆;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getRightHandleDescriptor()LI/ᅠ︋︆; -> Java_bin_nt_editor_widget_CodeEditor_getRightHandleDescriptor__ */

/* Lbin/nt/editor/widget/CodeEditor;->getRowHeight()I */
jint Java_bin_nt_editor_widget_CodeEditor_getRowHeight__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v7 = 0;
  jint v8 = 0;
  jint v9 = 0;
  jint v4 = 0;
  jobject v1 = NULL;
  jint v10 = 0;
  jint v6 = 0;
  jint v3 = 0;
  jint v11 = 0;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jint v5 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︁", "Landroid/graphics/Paint$FontMetricsInt;"));
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("android/graphics/Paint$FontMetricsInt"), "descent", "I"));
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("android/graphics/Paint$FontMetricsInt"), "ascent", "I"));
  /* UNSUPPORTED: sub-int-2addr */
  v6 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getLineSpacingPixels", "()I"), v4, v4, v4, v4);
  v7 = v6;
  /* UNSUPPORTED: add-int-2addr */
  v9 = 1;
  v10 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v9, v8, v8, v8, v8);
  v11 = v10;
  /* return terminator */
  return (jint)(intptr_t)v11;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getRowHeight()I -> Java_bin_nt_editor_widget_CodeEditor_getRowHeight__ */

/* Lbin/nt/editor/widget/CodeEditor;->getRowHeightOfText()I */
jint Java_bin_nt_editor_widget_CodeEditor_getRowHeightOfText__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v4 = 0;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jint v3 = 0;
  jint v5 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︁", "Landroid/graphics/Paint$FontMetricsInt;"));
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("android/graphics/Paint$FontMetricsInt"), "descent", "I"));
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("android/graphics/Paint$FontMetricsInt"), "ascent", "I"));
  /* UNSUPPORTED: sub-int-2addr */
  /* return terminator */
  return (jint)(intptr_t)v5;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getRowHeightOfText()I -> Java_bin_nt_editor_widget_CodeEditor_getRowHeightOfText__ */

/* Lbin/nt/editor/widget/CodeEditor;->getScrollMaxX()I */
jint Java_bin_nt_editor_widget_CodeEditor_getScrollMaxX__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v16 = 0;
  jfloat v17 = 0;
  jfloat v13 = 0;
  jobject v0 = NULL;
  jfloat v15 = 0;
  jfloat v4 = 0;
  jobject v1 = NULL;
  jint v8 = 0;
  jfloat v10 = 0;
  jint v11 = 0;
  jint v9 = 0;
  jfloat v5 = 0;
  jfloat v7 = 0;
  jfloat v12 = 0;
  jfloat v6 = 0;
  jint v2 = 0;
  jint v3 = 0;
  jint v14 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  v2 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("I/ᅠ︁︁"), "ᅟ︋︁", "()I"), v1, v1, v1, v1);
  v3 = v2;
  v4 = (jfloat)v4;
  v5 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︂", "()F"), v4, v4, v4, v4);
  v6 = v5;
  /* UNSUPPORTED: add-float-2addr */
  v8 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v4, v4, v4, v4);
  v9 = v8;
  v10 = (jfloat)v10;
  v11 = 1073741824;
  /* UNSUPPORTED: div-float-2addr */
  /* UNSUPPORTED: sub-float-2addr */
  v14 = 0;
  v15 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(FF)F"), v14, v13, v14, v14, v14);
  v16 = v15;
  v17 = (jint)v17;
  /* return terminator */
  return (jint)(intptr_t)v17;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getScrollMaxX()I -> Java_bin_nt_editor_widget_CodeEditor_getScrollMaxX__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->getScrollMaxY()I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->getScroller()LI/ᅟ︈︋; */
jobject Java_bin_nt_editor_widget_CodeEditor_getScroller__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︁︀", "LI/ᅟ︈︋;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getScroller()LI/ᅟ︈︋; -> Java_bin_nt_editor_widget_CodeEditor_getScroller__ */

/* Lbin/nt/editor/widget/CodeEditor;->getSearcher()LI/ᅟ︍︋; */
jobject Java_bin_nt_editor_widget_CodeEditor_getSearcher__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︅", "LI/ᅟ︍︋;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getSearcher()LI/ᅟ︍︋; -> Java_bin_nt_editor_widget_CodeEditor_getSearcher__ */

/* Lbin/nt/editor/widget/CodeEditor;->getSelectingTarget()LI/ᅟ︂︅; */
jobject Java_bin_nt_editor_widget_CodeEditor_getSelectingTarget__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v15 = NULL;
  jboolean v6 = 0;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jobject v11 = NULL;
  jobject v2 = NULL;
  jobject v8 = NULL;
  jobject v9 = NULL;
  jobject v5 = NULL;
  jboolean v7 = 0;
  jobject v12 = NULL;
  jobject v10 = NULL;
  jobject v13 = NULL;
  jobject v14 = NULL;
  jobject v3 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v2, v2, v2, v2);
  v4 = (jobject)(intptr_t)v3;
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︀", "LI/ᅟ︂︅;"));
  v6 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "equals", "(Ljava/lang/Object;)Z"), v5, v4, v4, v4);
  v7 = v6;
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_19;
 } else { goto L_10;
 }

L_10:
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v10 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v9, v9, v9, v9);
  v11 = (jobject)(intptr_t)v10;
  /* return terminator */
  return (jobject)(intptr_t)v11;

L_19:
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v13 = (jobject)env->GetObjectField((jobject)(intptr_t)v13, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v14 = (jobject)env->CallObjectMethod((jobject)v13, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v13, v13, v13, v13);
  v15 = (jobject)(intptr_t)v14;
  /* return terminator */
  return (jobject)(intptr_t)v15;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getSelectingTarget()LI/ᅟ︂︅; -> Java_bin_nt_editor_widget_CodeEditor_getSelectingTarget__ */

/* Lbin/nt/editor/widget/CodeEditor;->getSnippetController()LI/ᅠ︆︈; */
jobject Java_bin_nt_editor_widget_CodeEditor_getSnippetController__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︆", "LI/ᅠ︆︈;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getSnippetController()LI/ᅠ︆︈; -> Java_bin_nt_editor_widget_CodeEditor_getSnippetController__ */

/* Lbin/nt/editor/widget/CodeEditor;->getStyles()LI/ᅠ︎︈; */
jobject Java_bin_nt_editor_widget_CodeEditor_getStyles__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = 0;
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getStyles()LI/ᅠ︎︈; -> Java_bin_nt_editor_widget_CodeEditor_getStyles__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTabWidth()I */
jint Java_bin_nt_editor_widget_CodeEditor_getTabWidth__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︀", "I"));
  /* return terminator */
  return (jint)(intptr_t)v1;
EX_Return: return (jint)0;
EX_UnwindBlock: return (jint)0;
}

/* RegisterNatives entry for getTabWidth()I -> Java_bin_nt_editor_widget_CodeEditor_getTabWidth__ */

/* Lbin/nt/editor/widget/CodeEditor;->getText()LI/ᅟ︍︆; */
jobject Java_bin_nt_editor_widget_CodeEditor_getText__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getText()LI/ᅟ︍︆; -> Java_bin_nt_editor_widget_CodeEditor_getText__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTextBorderWidth()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getTextBorderWidth__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getTextBorderWidth()F -> Java_bin_nt_editor_widget_CodeEditor_getTextBorderWidth__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTextLetterSpacing()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getTextLetterSpacing__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v3 = 0;
  jfloat v4 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  v3 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v2, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getLetterSpacing", "()F"), v2, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jfloat)(intptr_t)v4;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getTextLetterSpacing()F -> Java_bin_nt_editor_widget_CodeEditor_getTextLetterSpacing__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTextPaint()LI/ᅠ︎︃; */
jobject Java_bin_nt_editor_widget_CodeEditor_getTextPaint__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getTextPaint()LI/ᅠ︎︃; -> Java_bin_nt_editor_widget_CodeEditor_getTextPaint__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTextScaleX()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getTextScaleX__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v3 = 0;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jfloat v4 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  v3 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v2, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getTextScaleX", "()F"), v2, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jfloat)(intptr_t)v4;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getTextScaleX()F -> Java_bin_nt_editor_widget_CodeEditor_getTextScaleX__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTextSizePx()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getTextSizePx__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jfloat v3 = 0;
  jfloat v4 = 0;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  v3 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v2, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getTextSize", "()F"), v2, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jfloat)(intptr_t)v4;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getTextSizePx()F -> Java_bin_nt_editor_widget_CodeEditor_getTextSizePx__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTypefaceLineNumber()Landroid/graphics/Typeface; */
jobject Java_bin_nt_editor_widget_CodeEditor_getTypefaceLineNumber__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︀", "LI/ᅠ︎︃;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getTypeface", "()Landroid/graphics/Typeface;"), v2, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jobject)(intptr_t)v4;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getTypefaceLineNumber()Landroid/graphics/Typeface; -> Java_bin_nt_editor_widget_CodeEditor_getTypefaceLineNumber__ */

/* Lbin/nt/editor/widget/CodeEditor;->getTypefaceText()Landroid/graphics/Typeface; */
jobject Java_bin_nt_editor_widget_CodeEditor_getTypefaceText__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getTypeface", "()Landroid/graphics/Typeface;"), v2, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jobject)(intptr_t)v4;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getTypefaceText()Landroid/graphics/Typeface; -> Java_bin_nt_editor_widget_CodeEditor_getTypefaceText__ */

/* Lbin/nt/editor/widget/CodeEditor;->getVerticalEdgeEffect()Landroid/widget/EdgeEffect; */
jobject Java_bin_nt_editor_widget_CodeEditor_getVerticalEdgeEffect__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︅", "Landroid/widget/EdgeEffect;"));
  /* return terminator */
  return (jobject)(intptr_t)v1;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getVerticalEdgeEffect()Landroid/widget/EdgeEffect; -> Java_bin_nt_editor_widget_CodeEditor_getVerticalEdgeEffect__ */

/* Lbin/nt/editor/widget/CodeEditor;->getVerticalExtraSpaceFactor()F */
jfloat Java_bin_nt_editor_widget_CodeEditor_getVerticalExtraSpaceFactor__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︁", "F"));
  /* return terminator */
  return (jfloat)(intptr_t)v1;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for getVerticalExtraSpaceFactor()F -> Java_bin_nt_editor_widget_CodeEditor_getVerticalExtraSpaceFactor__ */

/* Lbin/nt/editor/widget/CodeEditor;->getVerticalScrollbarThumbDrawable()Landroid/graphics/drawable/Drawable; */
jobject Java_bin_nt_editor_widget_CodeEditor_getVerticalScrollbarThumbDrawable__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︄︁", "Landroid/graphics/drawable/Drawable;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getVerticalScrollbarThumbDrawable()Landroid/graphics/drawable/Drawable; -> Java_bin_nt_editor_widget_CodeEditor_getVerticalScrollbarThumbDrawable__ */

/* Lbin/nt/editor/widget/CodeEditor;->getVerticalScrollbarTrackDrawable()Landroid/graphics/drawable/Drawable; */
jobject Java_bin_nt_editor_widget_CodeEditor_getVerticalScrollbarTrackDrawable__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︅︁", "Landroid/graphics/drawable/Drawable;"));
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for getVerticalScrollbarTrackDrawable()Landroid/graphics/drawable/Drawable; -> Java_bin_nt_editor_widget_CodeEditor_getVerticalScrollbarTrackDrawable__ */

/* Lbin/nt/editor/widget/CodeEditor;->isHorizontalScrollBarEnabled()Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_isHorizontalScrollBarEnabled__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "Z"));
  /* return terminator */
  return (jboolean)(intptr_t)v1;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for isHorizontalScrollBarEnabled()Z -> Java_bin_nt_editor_widget_CodeEditor_isHorizontalScrollBarEnabled__ */

/* Lbin/nt/editor/widget/CodeEditor;->isVerticalScrollBarEnabled()Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_isVerticalScrollBarEnabled__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "Z"));
  /* return terminator */
  return (jboolean)(intptr_t)v1;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for isVerticalScrollBarEnabled()Z -> Java_bin_nt_editor_widget_CodeEditor_isVerticalScrollBarEnabled__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onAttachedToWindow()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onCheckIsTextEditor()Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->onConfigurationChanged(Landroid/content/res/Configuration;)V */
void Java_bin_nt_editor_widget_CodeEditor_onConfigurationChanged__Landroid_content_res_Configuration_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jint v3 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "onConfigurationChanged", "(Landroid/content/res/Configuration;)V"), v1, v0, v0, v0);
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︄︌"), "ᅟ︉︀", "()V"), v0, v0, v0, v0);
  v3 = 0;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︂", "Z"), v3);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︂", "Z"), v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for onConfigurationChanged(Landroid/content/res/Configuration;)V -> Java_bin_nt_editor_widget_CodeEditor_onConfigurationChanged__Landroid_content_res_Configuration_2 */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onCreateContextMenu(Landroid/view/ContextMenu;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onCreateInputConnection(Landroid/view/inputmethod/EditorInfo;)Landroid/view/inputmethod/InputConnection;: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onDetachedFromWindow()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onDragEvent(Landroid/view/DragEvent;)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onDraw(Landroid/graphics/Canvas;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onFocusChanged(ZILandroid/graphics/Rect;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onGenericMotionEvent(Landroid/view/MotionEvent;)Z: java.lang.IllegalStateException: unknown phi type v1_20 = phi[v1_22 = phi[v1_0, v1_0, v1_0], v1_25 = phi[v1_26 = phi[v1_22 = phi[v1_0, v1_0, v1_0], v1_22 = phi[v1_0, v1_0, v1_0]], v1_26 = phi[v1_22 = phi[v1_0, v1_0, v1_0], v1_22 = phi[v1_0, v1_0, v1_0]]]] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onInitializeAccessibilityEvent(Landroid/view/accessibility/AccessibilityEvent;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onKeyDown(ILandroid/view/KeyEvent;)Z: java.lang.IllegalStateException: unknown phi type v26_16 = phi[v26_20 = phi[v26_0, v26_0], v26_22 = phi[v26_20 = phi[v26_0, v26_0], v26_20 = phi[v26_0, v26_0]]] */

/* Lbin/nt/editor/widget/CodeEditor;->onKeyMultiple(IILandroid/view/KeyEvent;)Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_onKeyMultiple__IILandroid_view_KeyEvent_2(JNIEnv* env, jobject thiz, jint p0, jint p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v9 = NULL;
  jint v10 = 0;
  jboolean v17 = 0;
  jobject v0 = NULL;
  jint v18 = 0;
  jint v11 = 0;
  jboolean v16 = 0;
  jobject v3 = NULL;
  jboolean v14 = 0;
  jboolean v15 = 0;
  jint v1 = 0;
  jint v2 = 0;
  jint v8 = 0;
  jint v13 = 0;
  jint v12 = 0;
  jobject v7 = NULL;
  jobject v4 = NULL;

L_0:
  v4 = env->AllocObject(env->FindClass("I/ᅟ︌︊"));
  v5 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︋︊"), env->GetStaticFieldID(env->FindClass("I/ᅟ︋︊"), "MULTIPLE", "LI/ᅟ︋︊;"));
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︀", "LI/ᅟ️︁;"));
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("bin/nt/editor/widget/CodeEditor"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;Landroid/view/KeyEvent;LI/ᅟ︋︊;)V"), v8, v3, v5, v4);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v10 = (jint)(intptr_t)env->CallIntMethod((jobject)v9, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v4, v4, v4, v4);
  v11 = v10;
  /* UNSUPPORTED: and-int-lit8 */
  /* UNSUPPORTED: if-eqz */
  if (v12 == 0) { goto L_1d;
 } else { goto L_17;
 }

L_17:
  v13 = 0;
v18 = (jint)v13; goto L_18;

L_1d:
  v14 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v8, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︃", "(IILandroid/view/KeyEvent;)Z"), v1, v2, v3, v4);
  v15 = v14;
  /* UNSUPPORTED: goto */
v18 = (jint)(intptr_t)v15; goto L_18;

L_18:
  v16 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v18, v4, v4, v4);
  v17 = v16;
  /* UNSUPPORTED: goto */
goto L_22;

L_22:
  /* return terminator */
  return (jboolean)(intptr_t)v17;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for onKeyMultiple(IILandroid/view/KeyEvent;)Z -> Java_bin_nt_editor_widget_CodeEditor_onKeyMultiple__IILandroid_view_KeyEvent_2 */

/* Lbin/nt/editor/widget/CodeEditor;->onKeyUp(ILandroid/view/KeyEvent;)Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_onKeyUp__ILandroid_view_KeyEvent_2(JNIEnv* env, jobject thiz, jint p0, jobject p1) {
  jthrowable pendingException = NULL;
  jboolean v35 = 0;
  jint v40 = 0;
  jint v39 = 0;
  jboolean v24 = 0;
  jobject v2 = NULL;
  jint v23 = 0;
  jobject v18 = NULL;
  jboolean v48 = 0;
  jint v34 = 0;
  jobject v19 = NULL;
  jint v33 = 0;
  jobject v17 = NULL;
  jint v1 = 0;
  jint v32 = 0;
  jint v42 = 0;
  jboolean v12 = 0;
  jboolean v29 = 0;
  jint v21 = 0;
  jboolean v41 = 0;
  jboolean v45 = 0;
  jobject v4 = NULL;
  jobject v14 = NULL;
  jboolean v30 = 0;
  jobject v0 = NULL;
  jint v8 = 0;
  jboolean v26 = 0;
  jboolean v13 = 0;
  jboolean v36 = 0;
  jobject v28 = NULL;
  jboolean v25 = 0;
  jlong v43 = 0;
  jboolean v44 = 0;
  jboolean v47 = 0;
  jint v22 = 0;
  jobject v3 = NULL;
  jobject v16 = NULL;
  jboolean v31 = 0;
  jboolean v38 = 0;
  jobject v6 = NULL;
  jboolean v27 = 0;
  jboolean v46 = 0;
  jint v20 = 0;
  jint v7 = 0;
  jint v5 = 0;
  jboolean v37 = 0;
  jobject v10 = NULL;
  jboolean v11 = 0;
  jint v15 = 0;
  jobject v9 = NULL;

L_0:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︀", "LI/ᅟ️︁;"));
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︌︀"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v3, v3, v3, v3);
  v7 = (jint)(intptr_t)env->CallIntMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/KeyEvent"), "getKeyCode", "()I"), v3, v3, v3, v3);
  v8 = v7;
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅠ︌︀"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅠ︌︀"), "ᅟ︁︀", "Landroid/text/Editable;"));
  v11 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v5, env->GetMethodID(env->FindClass("android/text/method/MetaKeyKeyListener"), "onKeyUp", "(Landroid/view/View;Landroid/text/Editable;ILandroid/view/KeyEvent;)Z"), v9, v10, v8, v2);
  v12 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/KeyEvent"), "isCtrlPressed", "()Z"), v3, v3, v3, v3);
  v13 = v12;
  env->SetBooleanField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅠ︌︀"), "ᅟ︂︀", "Z"), v13);
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("bin/nt/editor/widget/CodeEditor"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v15, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v17 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getCursor", "()LI/ᅟ︅︇;"), v3, v3, v3, v3);
  v18 = env->AllocObject(env->FindClass("I/ᅟ︌︊"));
  v19 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︋︊"), env->GetStaticFieldID(env->FindClass("I/ᅟ︋︊"), "UP", "LI/ᅟ︋︊;"));
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;Landroid/view/KeyEvent;LI/ᅟ︋︊;)V"), v15, v2, v19, v3);
  v20 = (jint)(intptr_t)env->CallIntMethod((jobject)v16, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v18, v3, v3, v3);
  v21 = v20;
  /* UNSUPPORTED: and-int-lit8 */
  v23 = 0;
  /* UNSUPPORTED: if-eqz */
  if (v22 == 0) { goto L_38;
 } else { goto L_33;
 }

L_33:
  v24 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v18, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v23, v3, v3, v3);
  v25 = v24;
  /* UNSUPPORTED: goto */
v48 = (jboolean)v25; goto L_6b;

L_38:
  v26 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ️︁"), "ᅟ︁︀", "(ILandroid/view/KeyEvent;)Z"), v1, v2, v3, v3);
  v27 = v26;
  /* UNSUPPORTED: if-eqz */
  if (v27 == 0) { goto L_63;
 } else { goto L_3e;
 }

L_3e:
  v28 = env->AllocObject(env->FindClass("I/ᅠ︋︀"));
  v29 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/KeyEvent"), "isCtrlPressed", "()Z"), v28, v28, v28, v28);
  v30 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅠ︌︀"), "ᅟ︁︀", "()Z"), v28, v28, v28, v28);
  v31 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅠ︌︀"), "ᅟ︀︀", "()Z"), v28, v28, v28, v28);
  env->CallVoidMethod((jobject)v28, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;Landroid/view/KeyEvent;LI/ᅟ︋︊;)V"), v15, v2, v19, v28);
  v32 = (jint)(intptr_t)env->CallIntMethod((jobject)v16, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v28, v28, v28, v28);
  v33 = v32;
  /* UNSUPPORTED: and-int-lit8 */
  /* UNSUPPORTED: if-eqz */
  if (v34 == 0) { goto L_63;
 } else { goto L_54;
 }

L_54:
  v35 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v28, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v23, v28, v28, v28);
  v36 = v35;
  /* UNSUPPORTED: if-nez */
  if (v36 != 0) { goto L_60;
 } else { goto L_5a;
 }

L_5a:
  v37 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v18, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v23, v28, v28, v28);
  v38 = v37;
  /* UNSUPPORTED: if-eqz */
  if (v38 == 0) { v41 = (jboolean)v36; v42 = (jint)v23; goto L_61;
 } else { goto L_60;
 }

L_60:
  v39 = 1;
v41 = (jboolean)(intptr_t)v43; v42 = (jint)v39; goto L_61;

L_61:
  /* dbg-move v40 v42 dv=I sv=I */
  /* UNSUPPORTED: goto */
v48 = (jboolean)v41; goto L_6b;

L_63:
  v44 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v15, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︃", "(ILandroid/view/KeyEvent;)Z"), v1, v2, v27, v27);
  v45 = v44;
  v46 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v18, env->GetMethodID(env->FindClass("I/ᅟ︌︊"), "ᅟ︀︀", "(Z)Z"), v45, v27, v27, v27);
  v47 = v46;
v48 = (jboolean)v47; goto L_6b;

L_6b:
  /* return terminator */
  return (jboolean)(intptr_t)v48;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for onKeyUp(ILandroid/view/KeyEvent;)Z -> Java_bin_nt_editor_widget_CodeEditor_onKeyUp__ILandroid_view_KeyEvent_2 */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onMeasure(II)V: java.lang.IllegalStateException: unknown phi type v16_25 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onResolvePointerIcon(Landroid/view/MotionEvent;I)Landroid/view/PointerIcon;: java.lang.IllegalStateException: unknown phi type v6_13 = phi[v6_14 = phi[v6_15 = phi[v6_0, v6_0], v6_15 = phi[v6_0, v6_0]], v6_19 = phi[v6_14 = phi[v6_15 = phi[v6_0, v6_0], v6_15 = phi[v6_0, v6_0]]]] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onSizeChanged(IIII)V: java.lang.IllegalStateException: unknown phi type v7_9 = phi[v7_7, v7_4] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->onTouchEvent(Landroid/view/MotionEvent;)Z: java.lang.IllegalStateException: unknown phi type v21_54 = phi[v21_47 = phi[v21_34 = phi[v21_0, v21_0], v21_34 = phi[v21_0, v21_0]], v21_39 = phi[v21_47 = phi[v21_34 = phi[v21_0, v21_0], v21_34 = phi[v21_0, v21_0]]]] */

/* Lbin/nt/editor/widget/CodeEditor;->performAccessibilityAction(ILandroid/os/Bundle;)Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_performAccessibilityAction__ILandroid_os_Bundle_2(JNIEnv* env, jobject thiz, jint p0, jobject p1) {
  jthrowable pendingException = NULL;
  jlong v25 = 0;
  jint v6 = 0;
  jobject v18 = NULL;
  jboolean v17 = 0;
  jint v4 = 0;
  jint v20 = 0;
  jobject v15 = NULL;
  jobject v29 = NULL;
  jint v5 = 0;
  jint v3 = 0;
  jobject v14 = NULL;
  jobject v26 = NULL;
  jlong v23 = 0;
  jobject v0 = NULL;
  jobject v27 = NULL;
  jint v7 = 0;
  jint v1 = 0;
  jobject v2 = NULL;
  jint v10 = 0;
  jobject v28 = NULL;
  jboolean v16 = 0;
  jobject v19 = NULL;
  jint v11 = 0;
  jint v9 = 0;
  jint v21 = 0;
  jlong v24 = 0;
  jlong v22 = 0;
  jint v12 = 0;
  jobject v30 = NULL;
  jint v8 = 0;
  jint v13 = 0;

L_0:
  v3 = 4096;
  v4 = 1;
  /* UNSUPPORTED: if-eq */
  if (v1 == v3) { goto L_58;
 } else { goto L_5;
 }

L_5:
  v5 = 8192;
  /* UNSUPPORTED: if-eq */
  if (v1 == v5) { goto L_52;
 } else { goto L_9;
 }

L_9:
  v6 = 16384;
  /* UNSUPPORTED: if-eq */
  if (v1 == v6) { goto L_4e;
 } else { goto L_d;
 }

L_d:
  v7 = 32768;
  /* UNSUPPORTED: if-eq */
  if (v1 == v7) { goto L_4a;
 } else { goto L_12;
 }

L_12:
  v8 = 65536;
  /* UNSUPPORTED: if-eq */
  if (v1 == v8) { goto L_46;
 } else { goto L_16;
 }

L_16:
  v9 = 2097152;
  /* UNSUPPORTED: if-eq */
  if (v1 == v9) { goto L_3c;
 } else { goto L_1a;
 }

L_1a:
  v10 = (jint)(intptr_t)env->GetStaticIntField(env->FindClass("android/os/Build$VERSION"), env->GetStaticFieldID(env->FindClass("android/os/Build$VERSION"), "SDK_INT", "I"));
  v11 = 23;
  /* UNSUPPORTED: if-lt */
  if (v10 < v11) { v18 = (jobject)v2; v19 = (jobject)v0; v20 = (jint)v10; v21 = (jint)v1; goto L_37;
 } else { goto L_20;
 }

L_20:
  v12 = 16908344;
  /* UNSUPPORTED: if-eq */
  if (v1 == v12) { goto L_31;
 } else { goto L_25;
 }

L_25:
  v13 = 16908346;
  /* UNSUPPORTED: if-eq */
  if (v1 == v13) { goto L_2b;
 } else { goto L_2a;
 }

L_2a:
  /* UNSUPPORTED: goto */
v18 = (jobject)(intptr_t)v22; v19 = (jobject)(intptr_t)v23; v20 = (jint)(intptr_t)v24; v21 = (jint)(intptr_t)v25; goto L_37;

L_2b:
  v14 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︎︆"), env->GetStaticFieldID(env->FindClass("I/ᅠ︎︆"), "PAGE_UP", "LI/ᅠ︎︆;"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "(LI/ᅠ︎︆;)V"), v14, v13, v13, v13);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_31:
  v15 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︎︆"), env->GetStaticFieldID(env->FindClass("I/ᅠ︎︆"), "PAGE_DOWN", "LI/ᅠ︎︆;"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "(LI/ᅠ︎︆;)V"), v15, v12, v12, v12);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_37:
  v16 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v19, env->GetMethodID(env->FindClass("android/view/View"), "performAccessibilityAction", "(ILandroid/os/Bundle;)Z"), v21, v18, v20, v20);
  v17 = v16;
  /* return terminator */
  return (jboolean)(intptr_t)v17;

L_3c:
  v26 = env->NewStringUTF("ACTION_ARGUMENT_SET_TEXT_CHARSEQUENCE");
  v27 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("android/os/Bundle"), "getCharSequence", "(Ljava/lang/String;)Ljava/lang/CharSequence;"), v26, v9, v9, v9);
  v28 = v27;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "setText", "(Ljava/lang/CharSequence;)V"), v28, v9, v9, v9);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_46:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︁", "()V"), v8, v8, v8, v8);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_4a:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︃", "()V"), v7, v7, v7, v7);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_4e:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︀", "(Z)V"), v4, v6, v6, v6);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_52:
  v29 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︎︆"), env->GetStaticFieldID(env->FindClass("I/ᅠ︎︆"), "PAGE_DOWN", "LI/ᅠ︎︆;"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "(LI/ᅠ︎︆;)V"), v29, v5, v5, v5);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_58:
  v30 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︎︆"), env->GetStaticFieldID(env->FindClass("I/ᅠ︎︆"), "PAGE_UP", "LI/ᅠ︎︆;"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "(LI/ᅠ︎︆;)V"), v30, v3, v3, v3);
  /* return terminator */
  return (jboolean)(intptr_t)v4;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for performAccessibilityAction(ILandroid/os/Bundle;)Z -> Java_bin_nt_editor_widget_CodeEditor_performAccessibilityAction__ILandroid_os_Bundle_2 */

/* Lbin/nt/editor/widget/CodeEditor;->removeCallbacks(Ljava/lang/Runnable;)Z */
jboolean Java_bin_nt_editor_widget_CodeEditor_removeCallbacks__Ljava_lang_Runnable_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jboolean v4 = 0;
  jobject v0 = NULL;
  jboolean v3 = 0;

L_0:
  v2 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︇︊"), env->GetStaticFieldID(env->FindClass("I/ᅟ︇︊"), "ᅟ︀︀", "LI/ᅟ︇︊;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/os/Handler"), "removeCallbacks", "(Ljava/lang/Runnable;)V"), v1, v2, v2, v2);
  v3 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "removeCallbacks", "(Ljava/lang/Runnable;)Z"), v1, v2, v2, v2);
  v4 = v3;
  /* return terminator */
  return (jboolean)(intptr_t)v4;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for removeCallbacks(Ljava/lang/Runnable;)Z -> Java_bin_nt_editor_widget_CodeEditor_removeCallbacks__Ljava_lang_Runnable_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setBlockLineEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setBlockLineEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︂", "Z"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setBlockLineEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setBlockLineEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setBlockLineWidth(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setBlockLineWidth__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setBlockLineWidth(F)V -> Java_bin_nt_editor_widget_CodeEditor_setBlockLineWidth__F */

/* Lbin/nt/editor/widget/CodeEditor;->setColorScheme(LI/ᅟ︌︉;)V */
void Java_bin_nt_editor_widget_CodeEditor_setColorScheme__LI__0115f_0fe0c_0fe09_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jlong v24 = 0;
  jobject v5 = NULL;
  jlong v22 = 0;
  jobject v20 = NULL;
  jobject v18 = NULL;
  jboolean v6 = 0;
  jobject v8 = NULL;
  jobject v9 = NULL;
  jlong v13 = 0;
  jobject v15 = NULL;
  jobject v1 = NULL;
  jboolean v7 = 0;
  jobject v2 = NULL;
  jlong v12 = 0;
  jobject v4 = NULL;
  jobject v21 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v19 = NULL;
  jlong v23 = 0;
  jobject v14 = NULL;
  jlong v11 = 0;
  jobject v17 = NULL;
  jobject v10 = NULL;
  jint v16 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︄", "LI/ᅟ︌︉;"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { v19 = (jobject)(intptr_t)v2; v20 = (jobject)v0; v21 = (jobject)v1; goto L_1f;
 } else { goto L_4;
 }

L_4:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ︌︉"), "ᅟ︁︀", "Ljava/util/ArrayList;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/util/ArrayList"), "iterator", "()Ljava/util/Iterator;"), v3, v3, v3, v3);
  v5 = v4;
v8 = (jobject)v5; v9 = (jobject)v0; v10 = (jobject)v1; goto L_a;

L_a:
  v6 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v8, env->GetMethodID(env->FindClass("java/util/Iterator"), "hasNext", "()Z"), v8, v8, v8, v8);
  v7 = v6;
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { v19 = (jobject)v8; v20 = (jobject)v9; v21 = (jobject)v10; goto L_1f;
 } else { goto L_10;
 }

L_10:
  v14 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("java/util/Iterator"), "next", "()Ljava/lang/Object;"), v8, v8, v8, v8);
  v15 = v14;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/ref/WeakReference"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v17 = (jobject)env->CallObjectMethod((jobject)v16, env->GetMethodID(env->FindClass("java/lang/ref/Reference"), "get", "()Ljava/lang/Object;"), v8, v8, v8, v8);
  v18 = v17;
  /* UNSUPPORTED: if-ne */
  if (v18 != v9) { v8 = (jobject)(intptr_t)v11; v9 = (jobject)(intptr_t)v12; v10 = (jobject)(intptr_t)v13; goto L_a;
 } else { goto L_1c;
 }

L_1c:
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("java/util/Iterator"), "remove", "()V"), v11, v11, v11, v11);
v19 = (jobject)(intptr_t)v22; v20 = (jobject)(intptr_t)v23; v21 = (jobject)(intptr_t)v24; goto L_1f;

L_1f:
  env->SetObjectField((jobject)(intptr_t)v20, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︄", "LI/ᅟ︌︉;"), (jobject)(intptr_t)v21);
  env->CallVoidMethod((jobject)v21, env->GetMethodID(env->FindClass("I/ᅟ︌︉"), "ᅟ︀︀", "(Lbin/nt/editor/widget/CodeEditor;)V"), v20, v19, v19, v19);
  env->CallVoidMethod((jobject)v20, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v19, v19, v19, v19);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setColorScheme(LI/ᅟ︌︉;)V -> Java_bin_nt_editor_widget_CodeEditor_setColorScheme__LI__0115f_0fe0c_0fe09_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setCursorAnimationEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setCursorAnimationEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v3 = 0;
  jboolean v1 = 0;

L_0:
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_9;
 } else { goto L_2;
 }

L_2:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︅", "LI/ᅟ︆︇;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︃︃"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅠ︃︃"), "ᅟ︀︀", "()V"), v3, v3, v3, v3);
goto L_9;

L_9:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︃", "Z"), v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setCursorAnimationEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setCursorAnimationEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setCursorAnimator(LI/ᅟ︆︇;)V */
void Java_bin_nt_editor_widget_CodeEditor_setCursorAnimator__LI__0115f_0fe06_0fe07_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︅", "LI/ᅟ︆︇;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setCursorAnimator(LI/ᅟ︆︇;)V -> Java_bin_nt_editor_widget_CodeEditor_setCursorAnimator__LI__0115f_0fe06_0fe07_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setCursorBlinkPeriod(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setCursorBlinkPeriod__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v10 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jint v5 = 0;
  jboolean v8 = 0;
  jobject v0 = NULL;
  jboolean v7 = 0;
  jboolean v9 = 0;
  jint v4 = 0;
  jint v6 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︅", "LI/ᅟ︇︇;"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_c;
 } else { goto L_4;
 }

L_4:
  v3 = env->AllocObject(env->FindClass("I/ᅟ︇︇"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︇︇"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;I)V"), v0, v1, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︅", "LI/ᅟ︇︇;"), (jobject)(intptr_t)v3);
  /* UNSUPPORTED: goto */
goto L_2c;

L_c:
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︇"), "ᅟ︈︀", "I"));
  env->SetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︇"), "ᅟ︈︀", "I"), v1);
  v5 = 1;
  /* UNSUPPORTED: if-gtz */
  if (v1 > 0) { goto L_19;
 } else { goto L_13;
 }

L_13:
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︇"), "ᅟ︅︀", "Z"), v5);
  v6 = 0;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︇"), "ᅟ︆︀", "Z"), v6);
  /* UNSUPPORTED: goto */
goto L_1b;

L_19:
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︇"), "ᅟ︆︀", "Z"), v5);
goto L_1b;

L_1b:
  /* UNSUPPORTED: if-gtz */
  if (v4 > 0) { goto L_2c;
 } else { goto L_1d;
 }

L_1d:
  v7 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︇"), "ᅟ︆︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_2c;
 } else { goto L_21;
 }

L_21:
  v8 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "isAttachedToWindow", "()Z"), v2, v2, v2, v2);
  v9 = v8;
  /* UNSUPPORTED: if-eqz */
  if (v9 == 0) { goto L_2c;
 } else { goto L_27;
 }

L_27:
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︅", "LI/ᅟ︇︇;"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︃", "(Ljava/lang/Runnable;)V"), v10, v2, v2, v2);
goto L_2c;

L_2c:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setCursorBlinkPeriod(I)V -> Java_bin_nt_editor_widget_CodeEditor_setCursorBlinkPeriod__I */

/* Lbin/nt/editor/widget/CodeEditor;->setCursorWidth(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setCursorWidth__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jint v3 = 0;
  jobject v0 = NULL;
  jfloat v1 = 0;
  jobject v4 = NULL;
  jint v2 = 0;
  jobject v5 = NULL;

L_0:
  v2 = 0;
  v3 = (v1 > v3 ? 1 : (v1 < v3 ? -1 : 0));
  /* UNSUPPORTED: if-ltz */
  if (v3 < 0) { goto L_b;
 } else { goto L_5;
 }

L_5:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v3, v3, v3, v3);
  /* return terminator */
  return;

L_b:
  v4 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  v5 = env->NewStringUTF("width can not be under zero");
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v5, v5, v5, v5);
  pendingException = (jthrowable)v4; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setCursorWidth(F)V -> Java_bin_nt_editor_widget_CodeEditor_setCursorWidth__F */

/* Lbin/nt/editor/widget/CodeEditor;->setDiagnosticIndicatorStyle(LI/ᅟ︄︈;)V */
void Java_bin_nt_editor_widget_CodeEditor_setDiagnosticIndicatorStyle__LI__0115f_0fe04_0fe08_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︄", "LI/ᅟ︄︈;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setDiagnosticIndicatorStyle(LI/ᅟ︄︈;)V -> Java_bin_nt_editor_widget_CodeEditor_setDiagnosticIndicatorStyle__LI__0115f_0fe04_0fe08_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setDiagnostics(LI/ᅟ︅︈;)V */
void Java_bin_nt_editor_widget_CodeEditor_setDiagnostics__LI__0115f_0fe05_0fe08_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setDiagnostics(LI/ᅟ︅︈;)V -> Java_bin_nt_editor_widget_CodeEditor_setDiagnostics__LI__0115f_0fe05_0fe08_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setDisableSoftKbdIfHardKbdAvailable(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setDisableSoftKbdIfHardKbdAvailable__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v7 = 0;
  jboolean v2 = 0;
  jobject v3 = NULL;
  jint v6 = 0;
  jobject v5 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jboolean v1 = 0;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︃", "Z"));
  /* UNSUPPORTED: if-ne */
  if (v2 != v1) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︃", "Z"), v1);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "Landroid/view/inputmethod/InputMethodManager;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getWindowToken", "()Landroid/os/IBinder;"), v2, v2, v2, v2);
  v5 = v4;
  v6 = 0;
  v7 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v3, env->GetMethodID(env->FindClass("android/view/inputmethod/InputMethodManager"), "hideSoftInputFromWindow", "(Landroid/os/IBinder;I)Z"), v5, v6, v5, v5);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "()V"), v5, v5, v5, v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setDisableSoftKbdIfHardKbdAvailable(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setDisableSoftKbdIfHardKbdAvailable__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setDisplayLnPanel(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setDisplayLnPanel__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︂", "Z"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setDisplayLnPanel(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setDisplayLnPanel__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setDividerMargin(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setDividerMargin__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︃", "(FF)V"), v1, v1, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setDividerMargin(F)V -> Java_bin_nt_editor_widget_CodeEditor_setDividerMargin__F */

/* Lbin/nt/editor/widget/CodeEditor;->setDividerWidth(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setDividerWidth__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jfloat v1 = 0;
  jobject v5 = NULL;
  jint v3 = 0;
  jobject v4 = NULL;

L_0:
  v2 = 0;
  v3 = (v1 > v3 ? 1 : (v1 < v3 ? -1 : 0));
  /* UNSUPPORTED: if-ltz */
  if (v3 < 0) { goto L_e;
 } else { goto L_5;
 }

L_5:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v3, v3, v3, v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v3, v3, v3, v3);
  /* return terminator */
  return;

L_e:
  v4 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  v5 = env->NewStringUTF("width can not be under zero");
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v5, v5, v5, v5);
  pendingException = (jthrowable)v4; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setDividerWidth(F)V -> Java_bin_nt_editor_widget_CodeEditor_setDividerWidth__F */

/* Lbin/nt/editor/widget/CodeEditor;->setEdgeEffectColor(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setEdgeEffectColor__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︅", "Landroid/widget/EdgeEffect;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/EdgeEffect"), "setColor", "(I)V"), v1, v2, v2, v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︅", "Landroid/widget/EdgeEffect;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/EdgeEffect"), "setColor", "(I)V"), v1, v3, v3, v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setEdgeEffectColor(I)V -> Java_bin_nt_editor_widget_CodeEditor_setEdgeEffectColor__I */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setEditable(Z)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setEditorLanguage(LI/ᅠ︍︀;)V: java.lang.IllegalStateException: unknown phi type v0_2 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setExtracting(Landroid/view/inputmethod/ExtractedTextRequest;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->setFirstLineNumberAlwaysVisible(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setFirstLineNumberAlwaysVisible__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v2 = 0;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︃", "Z"), v1);
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_9;
 } else { goto L_6;
 }

L_6:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
goto L_9;

L_9:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setFirstLineNumberAlwaysVisible(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setFirstLineNumberAlwaysVisible__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setFontFeatureSettings(Ljava/lang/String;)V */
void Java_bin_nt_editor_widget_CodeEditor_setFontFeatureSettings__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;
  jobject v8 = NULL;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v7 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setFontFeatureSettings", "(Ljava/lang/String;)V"), v1, v3, v3, v3);
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅠ︎︃"), "ᅟ︂︀", "()V"), v3, v3, v3, v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setFontFeatureSettings", "(Ljava/lang/String;)V"), v1, v5, v5, v5);
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︆︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setFontFeatureSettings", "(Ljava/lang/String;)V"), v1, v7, v7, v7);
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ︀︂", "()V"), v7, v7, v7, v7);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v7, v7, v7, v7);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setFontFeatureSettings(Ljava/lang/String;)V -> Java_bin_nt_editor_widget_CodeEditor_setFontFeatureSettings__Ljava_lang_String_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setFormatTip(Ljava/lang/String;)V */
void Java_bin_nt_editor_widget_CodeEditor_setFormatTip__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v2 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/util/Objects"), env->GetStaticMethodID(env->FindClass("java/util/Objects"), "requireNonNull", "(Ljava/lang/Object;)Ljava/lang/Object;"), v1, v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︄", "Ljava/lang/String;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setFormatTip(Ljava/lang/String;)V -> Java_bin_nt_editor_widget_CodeEditor_setFormatTip__Ljava_lang_String_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setHardwareAcceleratedDrawAllowed(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setHardwareAcceleratedDrawAllowed__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;
  jboolean v2 = 0;
  jobject v3 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︅", "Z"), v1);
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_d;
 } else { goto L_4;
 }

L_4:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_d;
 } else { goto L_8;
 }

L_8:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︅", "LI/ᅠ︆︅;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅠ︆︅"), "ᅟ︀︀", "()V"), v0, v0, v0, v0);
goto L_d;

L_d:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHardwareAcceleratedDrawAllowed(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setHardwareAcceleratedDrawAllowed__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setHighlightBracketPair(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setHighlightBracketPair__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v4 = NULL;
  jboolean v1 = 0;

L_0:
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_8;
 } else { goto L_2;
 }

L_2:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︀", "LI/ᅟ︀︊;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v0, v0, v0, v0);
  /* UNSUPPORTED: goto */
goto L_d;

L_8:
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︀", "LI/ᅟ︀︊;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︀︊"), "ᅟ︄︀", "()V"), v0, v0, v0, v0);
goto L_d;

L_d:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHighlightBracketPair(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setHighlightBracketPair__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setHighlightCurrentBlock(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setHighlightCurrentBlock__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v2 = 0;
  jboolean v1 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︂", "Z"), v1);
  v2 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "I"), v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHighlightCurrentBlock(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setHighlightCurrentBlock__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setHighlightCurrentLine(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setHighlightCurrentLine__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ️︂", "Z"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHighlightCurrentLine(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setHighlightCurrentLine__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setHighlightTexts(LI/ᅟ︉️;)V */
void Java_bin_nt_editor_widget_CodeEditor_setHighlightTexts__LI__0115f_0fe09_0fe0f_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v2 = env->AllocObject(env->FindClass("androidx/collection/MutableIntSet"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/collection/MutableIntSet"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHighlightTexts(LI/ᅟ︉️;)V -> Java_bin_nt_editor_widget_CodeEditor_setHighlightTexts__LI__0115f_0fe09_0fe0f_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setHorizontalScrollBarEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollBarEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "Z"), v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHorizontalScrollBarEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollBarEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setHorizontalScrollbarThumbDrawable(Landroid/graphics/drawable/Drawable;)V */
void Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollbarThumbDrawable__Landroid_graphics_drawable_Drawable_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->SetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︁", "Landroid/graphics/drawable/Drawable;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHorizontalScrollbarThumbDrawable(Landroid/graphics/drawable/Drawable;)V -> Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollbarThumbDrawable__Landroid_graphics_drawable_Drawable_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setHorizontalScrollbarTrackDrawable(Landroid/graphics/drawable/Drawable;)V */
void Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollbarTrackDrawable__Landroid_graphics_drawable_Drawable_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->SetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︃︁", "Landroid/graphics/drawable/Drawable;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setHorizontalScrollbarTrackDrawable(Landroid/graphics/drawable/Drawable;)V -> Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollbarTrackDrawable__Landroid_graphics_drawable_Drawable_2 */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setInlayHints(LI/ᅟ️️;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->setInputType(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setInputType__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ️︀", "I"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setInputType(I)V -> Java_bin_nt_editor_widget_CodeEditor_setInputType__I */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setInterceptParentHorizontalScrollIfNeeded(Z)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->setLayoutBusy(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setLayoutBusy__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jlong v11 = 0;
  jint v35 = 0;
  jfloat v24 = 0;
  jobject v26 = NULL;
  jint v41 = 0;
  jint v42 = 0;
  jboolean v6 = 0;
  jobject v47 = NULL;
  jobject v57 = NULL;
  jlong v13 = 0;
  jfloat v23 = 0;
  jint v4 = 0;
  jboolean v2 = 0;
  jobject v36 = NULL;
  jfloat v38 = 0;
  jobject v51 = NULL;
  jlong v10 = 0;
  jint v31 = 0;
  jint v52 = 0;
  jobject v56 = NULL;
  jint v19 = 0;
  jobject v0 = NULL;
  jobject v49 = NULL;
  jboolean v1 = 0;
  jint v29 = 0;
  jlong v54 = 0;
  jint v50 = 0;
  jfloat v21 = 0;
  jint v20 = 0;
  jobject v22 = NULL;
  jobject v37 = NULL;
  jint v18 = 0;
  jlong v53 = 0;
  jint v8 = 0;
  jlong v12 = 0;
  jobject v27 = NULL;
  jint v32 = 0;
  jint v58 = 0;
  jfloat v33 = 0;
  jint v16 = 0;
  jobject v25 = NULL;
  jlong v7 = 0;
  jobject v5 = NULL;
  jfloat v46 = 0;
  jobject v30 = NULL;
  jobject v48 = NULL;
  jint v43 = 0;
  jobject v39 = NULL;
  jboolean v55 = 0;
  jobject v14 = NULL;
  jint v28 = 0;
  jint v34 = 0;
  jobject v45 = NULL;
  jlong v9 = 0;
  jint v15 = 0;
  jboolean v3 = 0;
  jint v44 = 0;
  jint v40 = 0;
  jint v17 = 0;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_77;
 } else { goto L_4;
 }

L_4:
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_77;
 } else { goto L_6;
 }

L_6:
  v3 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "Z"));
  v4 = 0;
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { v51 = (jobject)v0; v52 = (jint)v4; goto L_64;
 } else { goto L_b;
 }

L_b:
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  v6 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︊︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v6 == 0) { v51 = (jobject)v0; v52 = (jint)v4; goto L_64;
 } else { goto L_11;
 }

L_11:
  env->SetBooleanField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︊︂", "Z"), v4);
  v7 = (jlong)(intptr_t)env->GetLongField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︉︂", "J"));
  v8 = 32;
  /* UNSUPPORTED: shr-long */
  v10 = (jint)v9;
  v11 = 4294967295;
  /* UNSUPPORTED: and-long-2addr */
  v13 = (jint)v12;
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︇︌"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v16 = (jint)(intptr_t)env->CallIntMethod((jobject)v15, env->GetMethodID(env->FindClass("I/ᅠ︇︌"), "ᅟ︈︀", "(II)I"), v10, v13, v4, v4);
  v17 = v16;
  v18 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getRowHeight", "()I"), v4, v4, v4, v4);
  v19 = v18;
  /* UNSUPPORTED: mul-int */
  v21 = (jfloat)v20;
  v22 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  v23 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︋︂", "F"));
  /* UNSUPPORTED: sub-float-2addr */
  v25 = (jobject)env->GetObjectField((jobject)(intptr_t)v25, env->GetFieldID(env->FindClass("I/ᅟ︄︌"), "ᅟ︁︀", "LI/ᅟ︈︋;"));
  v26 = env->AllocObject(env->FindClass("I/ᅠ︉︆"));
  v27 = (jobject)env->GetObjectField((jobject)(intptr_t)v25, env->GetFieldID(env->FindClass("I/ᅟ︈︋"), "ᅟ︁︀", "Landroid/widget/OverScroller;"));
  v28 = (jint)(intptr_t)env->CallIntMethod((jobject)v27, env->GetMethodID(env->FindClass("android/widget/OverScroller"), "getCurrX", "()I"), v4, v4, v4, v4);
  v29 = v28;
  v30 = (jobject)env->GetObjectField((jobject)(intptr_t)v25, env->GetFieldID(env->FindClass("I/ᅟ︈︋"), "ᅟ︁︀", "Landroid/widget/OverScroller;"));
  v31 = (jint)(intptr_t)env->CallIntMethod((jobject)v30, env->GetMethodID(env->FindClass("android/widget/OverScroller"), "getCurrY", "()I"), v4, v4, v4, v4);
  v32 = v31;
  v33 = (jint)v33;
  v34 = 5;
  v35 = 0;
  /* dbg-move v36 v26 dv=Ljava/lang/Object; sv=LI/ᅠ︉︆; */
  /* dbg-move v37 v0 dv=Ljava/lang/Object; sv=Lbin/nt/editor/widget/CodeEditor; */
  /* dbg-move v38 v33 dv=F sv=F */
  env->CallVoidMethod((jobject)v36, env->GetMethodID(env->FindClass("I/ᅠ︉︆"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;IIIII)V"), v37, v29, v32, v35, v38, v34);
  v39 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v40 = (jint)(intptr_t)env->CallIntMethod((jobject)v39, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v26, v4, v4, v4);
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  /* dbg-move v45 v25 dv=Ljava/lang/Object; sv=LI/ᅟ︈︋; */
  /* dbg-move v46 v33 dv=F sv=F */
  env->CallVoidMethod((jobject)v45, env->GetMethodID(env->FindClass("I/ᅟ︈︋"), "ᅟ︁︀", "(IIIII)V"), v41, v46, v42, v43, v44);
  v47 = (jobject)env->GetObjectField((jobject)(intptr_t)v25, env->GetFieldID(env->FindClass("I/ᅟ︈︋"), "ᅟ︁︀", "Landroid/widget/OverScroller;"));
  env->CallVoidMethod((jobject)v47, env->GetMethodID(env->FindClass("android/widget/OverScroller"), "abortAnimation", "()V"), v4, v4, v4, v4);
  env->CallVoidMethod((jobject)v25, env->GetMethodID(env->FindClass("I/ᅟ︈︋"), "ᅟ︀︀", "()V"), v4, v4, v4, v4);
v51 = (jobject)(intptr_t)v53; v52 = (jint)(intptr_t)v54; goto L_64;

L_64:
  env->SetBooleanField((jobject)(intptr_t)v51, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︂", "Z"), v52);
  env->CallVoidMethod((jobject)v51, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "()V"), v52, v52, v52, v52);
  env->CallVoidMethod((jobject)v51, env->GetMethodID(env->FindClass("android/view/View"), "postInvalidate", "()V"), v52, v52, v52, v52);
  v48 = env->AllocObject(env->FindClass("I/ᅟ︌︄"));
  env->CallVoidMethod((jobject)v48, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v51, v52, v52, v52);
  v49 = (jobject)env->GetObjectField((jobject)(intptr_t)v51, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v50 = (jint)(intptr_t)env->CallIntMethod((jobject)v49, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v48, v49, v49, v49);
  /* return terminator */
  return;

L_77:
  v55 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︂", "Z"));
  /* UNSUPPORTED: if-ne */
  if (v55 != v1) { goto L_7c;
 } else { goto L_7b;
 }

L_7b:
  /* return terminator */
  return;

L_7c:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︂", "Z"), v1);
  v56 = env->AllocObject(env->FindClass("I/ᅟ︌︄"));
  env->CallVoidMethod((jobject)v56, env->GetMethodID(env->FindClass("I/ᅟ︈︌"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;)V"), v0, v55, v55, v55);
  v57 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v58 = (jint)(intptr_t)env->CallIntMethod((jobject)v57, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v56, v57, v57, v57);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLayoutBusy(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setLayoutBusy__Z */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setLigatureEnabled(Z)V: java.lang.IllegalStateException: unknown phi type v1_3 = phi[v1_2, v1_1] */

/* Lbin/nt/editor/widget/CodeEditor;->setLineInfoTextSize(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineInfoTextSize__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jint v2 = 0;
  jint v3 = 0;

L_0:
  v2 = 0;
  v3 = (v1 > v3 ? 1 : (v1 < v3 ? -1 : 0));
  /* UNSUPPORTED: if-lez */
  if (v3 <= 0) { goto L_8;
 } else { goto L_5;
 }

L_5:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︁", "F"), v1);
  /* return terminator */
  return;

L_8:
  v4 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "()V"), v3, v3, v3, v3);
  pendingException = (jthrowable)v4; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineInfoTextSize(F)V -> Java_bin_nt_editor_widget_CodeEditor_setLineInfoTextSize__F */

/* Lbin/nt/editor/widget/CodeEditor;->setLineNumberAlign(Landroid/graphics/Paint$Align;)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineNumberAlign__Landroid_graphics_Paint_00024Align_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v1 = NULL;

L_0:
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_4;
 } else { goto L_2;
 }

L_2:
  v2 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Paint$Align"), env->GetStaticFieldID(env->FindClass("android/graphics/Paint$Align"), "LEFT", "Landroid/graphics/Paint$Align;"));
goto L_4;

L_4:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︄", "Landroid/graphics/Paint$Align;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineNumberAlign(Landroid/graphics/Paint$Align;)V -> Java_bin_nt_editor_widget_CodeEditor_setLineNumberAlign__Landroid_graphics_Paint_00024Align_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setLineNumberEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineNumberEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jlong v8 = 0;
  jboolean v2 = 0;
  jobject v5 = NULL;
  jint v4 = 0;
  jboolean v6 = 0;
  jlong v9 = 0;
  jobject v0 = NULL;
  jboolean v3 = 0;
  jboolean v7 = 0;
  jboolean v1 = 0;
  jlong v10 = 0;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︂", "Z"));
  /* UNSUPPORTED: if-eq */
  if (v1 == v2) { v5 = (jobject)v0; v6 = (jboolean)v2; v7 = (jboolean)v1; goto L_c;
 } else { goto L_4;
 }

L_4:
  v3 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { v5 = (jobject)v0; v6 = (jboolean)v2; v7 = (jboolean)v1; goto L_c;
 } else { goto L_8;
 }

L_8:
  v4 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "(Z)V"), v4, v4, v4, v4);
v5 = (jobject)(intptr_t)v8; v6 = (jboolean)(intptr_t)v9; v7 = (jboolean)(intptr_t)v10; goto L_c;

L_c:
  env->SetBooleanField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︂", "Z"), v7);
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v6, v6, v6, v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineNumberEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setLineNumberEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setLineNumberMarginLeft(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineNumberMarginLeft__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v0, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineNumberMarginLeft(F)V -> Java_bin_nt_editor_widget_CodeEditor_setLineNumberMarginLeft__F */

/* Lbin/nt/editor/widget/CodeEditor;->setLineNumberTipTextProvider(LI/ᅠ︈︁;)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineNumberTipTextProvider__LI__01160_0fe08_0fe01_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jobject v1 = NULL;

L_0:
  v2 = env->NewStringUTF("Provider can not be null");
  v3 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/util/Objects"), env->GetStaticMethodID(env->FindClass("java/util/Objects"), "requireNonNull", "(Ljava/lang/Object;Ljava/lang/String;)Ljava/lang/Object;"), v1, v2, v2, v2, v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︄", "LI/ᅠ︈︁;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineNumberTipTextProvider(LI/ᅠ︈︁;)V -> Java_bin_nt_editor_widget_CodeEditor_setLineNumberTipTextProvider__LI__01160_0fe08_0fe01_2 */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setLineSeparator(LI/ᅠ︉︁;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->setLineSpacingExtra(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineSpacingExtra__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineSpacingExtra(F)V -> Java_bin_nt_editor_widget_CodeEditor_setLineSpacingExtra__F */

/* Lbin/nt/editor/widget/CodeEditor;->setLineSpacingMultiplier(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setLineSpacingMultiplier__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v1 = 0;

L_0:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLineSpacingMultiplier(F)V -> Java_bin_nt_editor_widget_CodeEditor_setLineSpacingMultiplier__F */

/* Lbin/nt/editor/widget/CodeEditor;->setLnPanelPosition(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setLnPanelPosition__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︂", "I"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLnPanelPosition(I)V -> Java_bin_nt_editor_widget_CodeEditor_setLnPanelPosition__I */

/* Lbin/nt/editor/widget/CodeEditor;->setLnPanelPositionMode(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setLnPanelPositionMode__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︂", "I"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLnPanelPositionMode(I)V -> Java_bin_nt_editor_widget_CodeEditor_setLnPanelPositionMode__I */

/* Lbin/nt/editor/widget/CodeEditor;->setNonPrintablePaintingFlags(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setNonPrintablePaintingFlags__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v5 = 0;
  jint v2 = 0;
  jint v4 = 0;
  jint v1 = 0;
  jobject v0 = NULL;
  jint v3 = 0;

L_0:
  v2 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︁", "I"));
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︁", "I"), v1);
  /* UNSUPPORTED: and-int-lit16 */
  /* UNSUPPORTED: and-int-lit16 */
  /* UNSUPPORTED: if-eq */
  if (v3 == v4) { goto L_e;
 } else { goto L_a;
 }

L_a:
  v5 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "(Z)V"), v5, v3, v3, v3);
goto L_e;

L_e:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v3, v3, v3, v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setNonPrintablePaintingFlags(I)V -> Java_bin_nt_editor_widget_CodeEditor_setNonPrintablePaintingFlags__I */

/* Lbin/nt/editor/widget/CodeEditor;->setPinLineNumber(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setPinLineNumber__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;
  jboolean v2 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︃", "Z"), v1);
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_9;
 } else { goto L_6;
 }

L_6:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
goto L_9;

L_9:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setPinLineNumber(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setPinLineNumber__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setRenderFunctionCharacters(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setRenderFunctionCharacters__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jboolean v1 = 0;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jboolean v2 = 0;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "Z"));
  /* UNSUPPORTED: if-eq */
  if (v2 == v1) { goto L_15;
 } else { goto L_4;
 }

L_4:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "Z"), v1);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ️︁", "()V"), v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v2, v2, v2, v2);
  v4 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "(Z)V"), v4, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v2, v2, v2, v2);
goto L_15;

L_15:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setRenderFunctionCharacters(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setRenderFunctionCharacters__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setScalable(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setScalable__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ️︁", "Z"), v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setScalable(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setScalable__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setScrollBarEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setScrollBarEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "Z"), v1);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "Z"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setScrollBarEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setScrollBarEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setSelectionHandleStyle(LI/ᅠ︌︆;)V */
void Java_bin_nt_editor_widget_CodeEditor_setSelectionHandleStyle__LI__01160_0fe0c_0fe06_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jint v3 = 0;

L_0:
  v2 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/util/Objects"), env->GetStaticMethodID(env->FindClass("java/util/Objects"), "requireNonNull", "(Ljava/lang/Object;)Ljava/lang/Object;"), v1, v0, v0, v0, v0);
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︌︆"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︅", "LI/ᅠ︌︆;"), (jobject)(intptr_t)v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setSelectionHandleStyle(LI/ᅠ︌︆;)V -> Java_bin_nt_editor_widget_CodeEditor_setSelectionHandleStyle__LI__01160_0fe0c_0fe06_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setSoftKeyboardEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setSoftKeyboardEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jboolean v2 = 0;
  jobject v3 = NULL;
  jboolean v7 = 0;
  jboolean v1 = 0;
  jint v6 = 0;
  jobject v4 = NULL;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︃", "Z"));
  /* UNSUPPORTED: if-ne */
  if (v2 != v1) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︃", "Z"), v1);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "Landroid/view/inputmethod/InputMethodManager;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getWindowToken", "()Landroid/os/IBinder;"), v2, v2, v2, v2);
  v5 = v4;
  v6 = 0;
  v7 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v3, env->GetMethodID(env->FindClass("android/view/inputmethod/InputMethodManager"), "hideSoftInputFromWindow", "(Landroid/os/IBinder;I)Z"), v5, v6, v5, v5);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "()V"), v5, v5, v5, v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setSoftKeyboardEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setSoftKeyboardEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setStickyTextSelection(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setStickyTextSelection__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︃", "Z"), v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setStickyTextSelection(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setStickyTextSelection__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setStyles(LI/ᅠ︎︈;)V */
void Java_bin_nt_editor_widget_CodeEditor_setStyles__LI__01160_0fe0e_0fe08_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v3 = 0;
  jobject v4 = NULL;
  jboolean v2 = 0;
  jobject v1 = NULL;
  jobject v5 = NULL;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_7;
 } else { goto L_4;
 }

L_4:
  v3 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "I"), v3);
goto L_7;

L_7:
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︅", "LI/ᅠ︆︅;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅠ︆︅"), "ᅟ︀︀", "()V"), v0, v0, v0, v0);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ︀︂", "()V"), v0, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setStyles(LI/ᅠ︎︈;)V -> Java_bin_nt_editor_widget_CodeEditor_setStyles__LI__01160_0fe0e_0fe08_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setTabWidth(I)V */
void Java_bin_nt_editor_widget_CodeEditor_setTabWidth__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jint v2 = 0;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v4 = NULL;
  jobject v0 = NULL;
  jint v1 = 0;

L_0:
  v2 = 1;
  /* UNSUPPORTED: if-lt */
  if (v1 < v2) { goto L_16;
 } else { goto L_3;
 }

L_3:
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︀", "I"), v1);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︅", "LI/ᅠ︆︅;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅠ︆︅"), "ᅟ︀︀", "()V"), v2, v2, v2, v2);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ︀︂", "()V"), v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;

L_16:
  v5 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  v6 = env->NewStringUTF("width can not be under 1");
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v6, v6, v6, v6);
  pendingException = (jthrowable)v5; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTabWidth(I)V -> Java_bin_nt_editor_widget_CodeEditor_setTabWidth__I */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setText(Ljava/lang/CharSequence;)V: java.lang.IllegalStateException: unknown phi type v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_4 = phi[v10_1 = phi[v10_0, v10_0]]] */

/* Lbin/nt/editor/widget/CodeEditor;->setTextBorderWidth(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setTextBorderWidth__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jint v3 = 0;
  jint v2 = 0;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jobject v0 = NULL;

L_0:
  v2 = 0;
  v3 = (v1 > v3 ? 1 : (v1 < v3 ? -1 : 0));
  /* UNSUPPORTED: if-ltz */
  if (v3 < 0) { goto L_b;
 } else { goto L_5;
 }

L_5:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︁", "F"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v3, v3, v3, v3);
  /* return terminator */
  return;

L_b:
  v4 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  v5 = env->NewStringUTF("width can not be under zero");
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v5, v5, v5, v5);
  pendingException = (jthrowable)v4; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTextBorderWidth(F)V -> Java_bin_nt_editor_widget_CodeEditor_setTextBorderWidth__F */

/* Lbin/nt/editor/widget/CodeEditor;->setTextLetterSpacing(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setTextLetterSpacing__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v3 = NULL;
  jfloat v1 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅠ︎︃"), "setLetterSpacing", "(F)V"), v1, v2, v2, v2);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅠ︎︃"), "setLetterSpacing", "(F)V"), v1, v2, v2, v2);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ️︁", "()V"), v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTextLetterSpacing(F)V -> Java_bin_nt_editor_widget_CodeEditor_setTextLetterSpacing__F */

/* Lbin/nt/editor/widget/CodeEditor;->setTextScaleX(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setTextScaleX__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v4 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setTextScaleX", "(F)V"), v1, v2, v2, v2);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︀", "LI/ᅠ︎︃;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setTextScaleX", "(F)V"), v1, v2, v2, v2);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ️︁", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTextScaleX(F)V -> Java_bin_nt_editor_widget_CodeEditor_setTextScaleX__F */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setTextSize(F)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->setTextSizePx(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setTextSizePx__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jfloat v1 = 0;
  jobject v0 = NULL;
  jint v2 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "setTextSizePxDirect", "(F)V"), v1, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v0, v0, v0, v0);
  v2 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "(Z)V"), v2, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTextSizePx(F)V -> Java_bin_nt_editor_widget_CodeEditor_setTextSizePx__F */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->setTextSizePxDirect(F)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->setTypefaceLineNumber(Landroid/graphics/Typeface;)V */
void Java_bin_nt_editor_widget_CodeEditor_setTypefaceLineNumber__Landroid_graphics_Typeface_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v4 = NULL;
  jobject v5 = NULL;
  jobject v8 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jobject v6 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v7 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_9;
 } else { goto L_4;
 }

L_4:
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v2, v2, v2, v2);
  v4 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Typeface"), env->GetStaticFieldID(env->FindClass("android/graphics/Typeface"), "MONOSPACE", "Landroid/graphics/Typeface;"));
goto L_9;

L_9:
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︂︀", "LI/ᅠ︎︃;"));
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setTypeface", "(Landroid/graphics/Typeface;)Landroid/graphics/Typeface;"), v1, v2, v2, v2);
  v7 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getFontMetricsInt", "()Landroid/graphics/Paint$FontMetricsInt;"), v2, v2, v2, v2);
  v8 = v7;
  env->SetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︊︁", "Landroid/graphics/Paint$FontMetricsInt;"), (jobject)(intptr_t)v8);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ️︀", "Lbin/nt/editor/widget/CodeEditor;"));
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTypefaceLineNumber(Landroid/graphics/Typeface;)V -> Java_bin_nt_editor_widget_CodeEditor_setTypefaceLineNumber__Landroid_graphics_Typeface_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setTypefaceText(Landroid/graphics/Typeface;)V */
void Java_bin_nt_editor_widget_CodeEditor_setTypefaceText__Landroid_graphics_Typeface_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jobject v2 = NULL;
  jobject v8 = NULL;
  jobject v11 = NULL;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jobject v7 = NULL;
  jint v12 = 0;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v10 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_9;
 } else { goto L_4;
 }

L_4:
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v2, v2, v2, v2);
  v4 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Typeface"), env->GetStaticFieldID(env->FindClass("android/graphics/Typeface"), "DEFAULT", "Landroid/graphics/Typeface;"));
goto L_9;

L_9:
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︀", "LI/ᅠ︎︃;"));
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setTypeface", "(Landroid/graphics/Typeface;)Landroid/graphics/Typeface;"), v1, v2, v2, v2);
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅠ︎︃"), "ᅟ︂︀", "()V"), v2, v2, v2, v2);
  v7 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/Paint"), "getFontMetricsInt", "()Landroid/graphics/Paint$FontMetricsInt;"), v2, v2, v2, v2);
  v8 = v7;
  env->SetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︁︁", "Landroid/graphics/Paint$FontMetricsInt;"), (jobject)(intptr_t)v8);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ️︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v10 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getRenderContext", "()LI/ᅠ︆︅;"), v2, v2, v2, v2);
  v11 = v10;
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("I/ᅠ︆︅"), "ᅟ︀︀", "()V"), v2, v2, v2, v2);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ︀︂", "()V"), v2, v2, v2, v2);
  v12 = 1;
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "(Z)V"), v12, v12, v12, v12);
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v12, v12, v12, v12);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v12, v12, v12, v12);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTypefaceText(Landroid/graphics/Typeface;)V -> Java_bin_nt_editor_widget_CodeEditor_setTypefaceText__Landroid_graphics_Typeface_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setUndoEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setUndoEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︂", "Z"), v1);
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_9;
 } else { goto L_6;
 }

L_6:
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︌︁", "(Z)V"), v1, v2, v2, v2);
goto L_9;

L_9:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setUndoEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setUndoEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setVerticalExtraSpaceFactor(F)V */
void Java_bin_nt_editor_widget_CodeEditor_setVerticalExtraSpaceFactor__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jint v5 = 0;
  jobject v0 = NULL;
  jobject v9 = NULL;
  jint v3 = 0;
  jfloat v1 = 0;
  jint v4 = 0;
  jint v2 = 0;
  jobject v6 = NULL;
  jint v7 = 0;
  jobject v8 = NULL;

L_0:
  v2 = 0;
  v3 = (v1 > v2 ? 1 : (v1 < v2 ? -1 : 0));
  /* UNSUPPORTED: if-ltz */
  if (v3 < 0) { goto L_14;
 } else { goto L_5;
 }

L_5:
  v4 = 1065353216;
  v5 = (v1 > v5 ? 1 : (v1 < v5 ? -1 : 0));
  /* UNSUPPORTED: if-gtz */
  if (v5 > 0) { goto L_14;
 } else { goto L_b;
 }

L_b:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︁", "F"), v1);
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︄", "LI/ᅟ︄︌;"));
  v7 = 0;
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅟ︄︌"), "ᅟ︊︀", "(FFZ)V"), v2, v2, v7, v2);
  /* return terminator */
  return;

L_14:
  v8 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  v9 = env->NewStringUTF("the factor should be in range [0.0, 1.0]");
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v9, v9, v9, v9);
  pendingException = (jthrowable)v8; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setVerticalExtraSpaceFactor(F)V -> Java_bin_nt_editor_widget_CodeEditor_setVerticalExtraSpaceFactor__F */

/* Lbin/nt/editor/widget/CodeEditor;->setVerticalScrollBarEnabled(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollBarEnabled__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v1 = 0;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "Z"), v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setVerticalScrollBarEnabled(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollBarEnabled__Z */

/* Lbin/nt/editor/widget/CodeEditor;->setVerticalScrollbarThumbDrawable(Landroid/graphics/drawable/Drawable;)V */
void Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollbarThumbDrawable__Landroid_graphics_drawable_Drawable_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->SetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︄︁", "Landroid/graphics/drawable/Drawable;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setVerticalScrollbarThumbDrawable(Landroid/graphics/drawable/Drawable;)V -> Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollbarThumbDrawable__Landroid_graphics_drawable_Drawable_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setVerticalScrollbarTrackDrawable(Landroid/graphics/drawable/Drawable;)V */
void Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollbarTrackDrawable__Landroid_graphics_drawable_Drawable_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->SetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︇︋"), "ᅟ︅︁", "Landroid/graphics/drawable/Drawable;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setVerticalScrollbarTrackDrawable(Landroid/graphics/drawable/Drawable;)V -> Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollbarTrackDrawable__Landroid_graphics_drawable_Drawable_2 */

/* Lbin/nt/editor/widget/CodeEditor;->setWordwrap(Z)V */
void Java_bin_nt_editor_widget_CodeEditor_setWordwrap__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jint v2 = 0;
  jobject v0 = NULL;

L_0:
  v2 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "(ZZ)V"), v1, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setWordwrap(Z)V -> Java_bin_nt_editor_widget_CodeEditor_setWordwrap__Z */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︀︁()Ljava/lang/String;: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︀︂()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︀︃(LI/ᅠ︎︆;)V: java.lang.IllegalStateException: unknown phi type v5_12 = phi[v5_13 = phi[v5_6 = phi[v5_2 = phi[v5_0, v5_0], v5_2 = phi[v5_0, v5_0], v5_2 = phi[v5_0, v5_0]], v5_6 = phi[v5_2 = phi[v5_0, v5_0], v5_2 = phi[v5_0, v5_0], v5_2 = phi[v5_0, v5_0]]], v5_6 = phi[v5_2 = phi[v5_0, v5_0], v5_2 = phi[v5_0, v5_0], v5_2 = phi[v5_0, v5_0]]] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︀︄(IIIZ)V: java.lang.IllegalStateException: unknown phi type v6_1 = phi[v6_2 = phi[v6_3 = phi[v6_0, v6_0, v6_0, v6_0], v6_3 = phi[v6_0, v6_0, v6_0, v6_0]], v6_2 = phi[v6_3 = phi[v6_0, v6_0, v6_0, v6_0], v6_3 = phi[v6_0, v6_0, v6_0, v6_0]], v6_10 = phi[v6_2 = phi[v6_3 = phi[v6_0, v6_0, v6_0, v6_0], v6_3 = phi[v6_0, v6_0, v6_0, v6_0]]], v6_11 = phi[v6_10 = phi[v6_2 = phi[v6_3 = phi[v6_0, v6_0, v6_0, v6_0], v6_3 = phi[v6_0, v6_0, v6_0, v6_0]]]]] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︁︀()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe00__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v10 = 0;
  jint v5 = 0;
  jlong v15 = 0;
  jobject v0 = NULL;
  jobject v12 = NULL;
  jboolean v1 = 0;
  jobject v2 = NULL;
  jobject v13 = NULL;
  jint v8 = 0;
  jint v4 = 0;
  jint v7 = 0;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jint v6 = 0;
  jint v11 = 0;
  jlong v14 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_24;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getLayoutParams", "()Landroid/view/ViewGroup$LayoutParams;"), v1, v1, v1, v1);
  v3 = v2;
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_24;
 } else { goto L_a;
 }

L_a:
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("android/view/ViewGroup$LayoutParams"), "width", "I"));
  v5 = -2;
  /* UNSUPPORTED: if-ne */
  if (v4 != v5) { goto L_13;
 } else { v12 = (jobject)v0; v13 = (jobject)v3; goto L_f;
 }

L_13:
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("android/view/ViewGroup$LayoutParams"), "height", "I"));
  /* UNSUPPORTED: if-ne */
  if (v6 != v5) { goto L_24;
 } else { goto L_17;
 }

L_17:
  v7 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getHeight", "()I"), v6, v6, v6, v6);
  v8 = v7;
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  v10 = (jint)(intptr_t)env->CallIntMethod((jobject)v9, env->GetMethodID(env->FindClass("I/ᅠ︁︁"), "ᅟ︊︀", "()I"), v8, v8, v8, v8);
  v11 = v10;
  /* UNSUPPORTED: if-eq */
  if (v8 == v11) { goto L_24;
 } else { goto L_23;
 }

L_23:
  /* UNSUPPORTED: goto */
v12 = (jobject)(intptr_t)v14; v13 = (jobject)(intptr_t)v15; goto L_f;

L_f:
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/view/View"), "requestLayout", "()V"), v13, v13, v13, v13);
  /* UNSUPPORTED: goto */
goto L_24;

L_24:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︀()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe00__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︁︂(LI/ᅠ︎︆;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︁︃()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v6 = 0;
  jobject v2 = NULL;
  jfloat v7 = 0;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jobject v9 = NULL;
  jobject v0 = NULL;
  jboolean v10 = 0;
  jobject v5 = NULL;
  jboolean v11 = 0;
  jobject v3 = NULL;
  jobject v8 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︅", "Landroid/view/inputmethod/ExtractedTextRequest;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_11;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︂", "(Landroid/view/inputmethod/ExtractedTextRequest;)Landroid/view/inputmethod/ExtractedText;"), v1, v1, v1, v1);
  v3 = v2;
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "Landroid/view/inputmethod/InputMethodManager;"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︅", "Landroid/view/inputmethod/ExtractedTextRequest;"));
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("android/view/inputmethod/ExtractedTextRequest"), "token", "I"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/view/inputmethod/InputMethodManager"), "updateExtractedText", "(Landroid/view/View;ILandroid/view/inputmethod/ExtractedText;)V"), v0, v6, v3, v3);
goto L_11;

L_11:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︇︄", "()V"), v1, v1, v1, v1);
  v7 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︄", "()F"), v1, v1, v1, v1);
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︀", "LI/ᅟ︊︊;"));
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︁︀", "LI/ᅟ︇︆;"));
  v10 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v9, env->GetMethodID(env->FindClass("I/ᅟ︇︆"), "ᅟ︀︀", "()Z"), v9, v9, v9, v9);
  v11 = v10;
  /* UNSUPPORTED: if-eqz */
  if (v11 == 0) { goto L_24;
 } else { goto L_21;
 }

L_21:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︃", "()V"), v11, v11, v11, v11);
goto L_24;

L_24:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︃()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe03__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︁︄(IIII)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe04__IIII(JNIEnv* env, jobject thiz, jint p0, jint p1, jint p2, jint p3) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v2 = 0;
  jint v10 = 0;
  jint v11 = 0;
  jint v8 = 0;
  jint v1 = 0;
  jint v9 = 0;
  jint v5 = 0;
  jint v3 = 0;
  jobject v7 = NULL;
  jint v4 = 0;
  jint v6 = 0;

L_0:
  v5 = 1;
  v6 = 0;
  /* dbg-move v7 v0 dv=Ljava/lang/Object; sv=Lbin/nt/editor/widget/CodeEditor; */
  /* dbg-move v8 v1 dv=I sv=I */
  /* dbg-move v9 v2 dv=I sv=I */
  /* dbg-move v10 v3 dv=I sv=I */
  /* dbg-move v11 v4 dv=I sv=I */
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "(IIIIIZ)V"), v8, v9, v10, v11, v6, v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︄(IIII)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe04__IIII */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︂︁(LI/ᅟ︍︆;)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe02_0fe01__LI__0115f_0fe0d_0fe06_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jint v2 = 0;

L_0:
  v2 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︁", "Z"), v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︂︇"), "ᅟ︂︁", "(LI/ᅟ︍︆;)V"), v1, v3, v3, v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︂︁(LI/ᅟ︍︆;)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe02_0fe01__LI__0115f_0fe0d_0fe06_2 */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︂︂(Landroid/view/inputmethod/ExtractedTextRequest;)Landroid/view/inputmethod/ExtractedText;: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︂︃(I)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe02_0fe03__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v5 = NULL;
  jint v1 = 0;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jobject v3 = NULL;

L_0:
  v2 = env->AllocObject(env->FindClass("I/ᅠ︊︆"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅠ︊︆"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;I)V"), v0, v1, v2, v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︀", "LI/ᅟ︋︌;"));
  v4 = (jint)(intptr_t)env->CallIntMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︋︌"), "ᅟ︀︀", "(LI/ᅟ︈︌;)I"), v2, v2, v2, v2);
  v5 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getCursorRange", "()LI/ᅠ️︉;"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︂︃(I)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe02_0fe03__I */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︂︄(IIIIIZ)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︃︀()Z */
jboolean Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe00__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v9 = 0;
  jobject v0 = NULL;
  jobject v8 = NULL;
  jint v15 = 0;
  jlong v18 = 0;
  jboolean v19 = 0;
  jint v4 = 0;
  jobject v3 = NULL;
  jobject v6 = NULL;
  jint v12 = 0;
  jboolean v1 = 0;
  jobject v7 = NULL;
  jint v10 = 0;
  jobject v2 = NULL;
  jobject v13 = NULL;
  jobject v16 = NULL;
  jint v11 = 0;
  jlong v14 = 0;
  jobject v20 = NULL;
  jint v17 = 0;
  jobject v5 = NULL;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︃", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { v20 = (jobject)v0; goto L_21;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v1, v1, v1, v1);
  v3 = v2;
  v4 = 0;
  /* UNSUPPORTED: if-nez */
  if (v3 != 0) { goto L_d;
 } else { v13 = (jobject)v0; goto L_b;
 }

L_d:
  v5 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v6 = v5;
  v7 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getConfiguration", "()Landroid/content/res/Configuration;"), v6, v6, v6, v6);
  v8 = v7;
  v9 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("android/content/res/Configuration"), "keyboard", "I"));
  v10 = 1;
  /* UNSUPPORTED: if-ne */
  if (v9 != v10) { v15 = (jint)v4; v16 = (jobject)v0; v17 = (jint)v10; goto L_1e;
 } else { goto L_1a;
 }

L_1a:
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("android/content/res/Configuration"), "hardKeyboardHidden", "I"));
  /* UNSUPPORTED: if-ne */
  if (v11 != v10) { v13 = (jobject)(intptr_t)v14; goto L_b;
 } else { v15 = (jint)v4; v16 = (jobject)(intptr_t)v14; v17 = (jint)v10; goto L_1e;
 }

L_b:
  v12 = 0;
  /* UNSUPPORTED: goto */
v15 = (jint)(intptr_t)v18; v16 = (jobject)v13; v17 = (jint)v12; goto L_1e;

L_1e:
  /* UNSUPPORTED: if-eqz */
  if (v17 == 0) { v20 = (jobject)v16; goto L_21;
 } else { goto L_20;
 }

L_20:
  /* return terminator */
  return (jboolean)(intptr_t)v15;

L_21:
  v19 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v20, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︃", "Z"));
  /* return terminator */
  return (jboolean)(intptr_t)v19;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︃︀()Z -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe00__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︃︂(FF)J */
jlong Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe02__FF(JNIEnv* env, jobject thiz, jfloat p0, jfloat p1) {
  jthrowable pendingException = NULL;
  jlong v11 = 0;
  jfloat v4 = 0;
  jfloat v6 = 0;
  jobject v3 = NULL;
  jfloat v5 = 0;
  jobject v0 = NULL;
  jfloat v1 = 0;
  jfloat v2 = 0;
  jlong v12 = 0;
  jint v10 = 0;
  jobject v8 = NULL;
  jobject v7 = NULL;
  jint v9 = 0;

L_0:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  v4 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︂", "()F"), v3, v3, v3, v3);
  v5 = v4;
  /* UNSUPPORTED: sub-float-2addr */
  v7 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅠ︁︁"), "ᅟ︌︀", "(FF)LI/ᅠ︀︁;"), v6, v2, v3, v3);
  v8 = v7;
  v9 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅠ︀︁"), "ᅟ︀︀", "I"));
  v10 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("I/ᅠ︀︁"), "ᅟ︁︀", "I"));
  v11 = (jlong)(intptr_t)env->CallStaticLongMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︅︁", "(II)J"), v9, v10, v3, v3, v3);
  v12 = v11;
  /* return terminator */
  return (jlong)(intptr_t)v12;
EX_Return: return (jlong)0;
EX_UnwindBlock: return (jlong)0;
}

/* RegisterNatives entry for ᅟ︃︂(FF)J -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe02__FF */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︃︃(IILandroid/view/KeyEvent;)Z */
jboolean Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe03__IILandroid_view_KeyEvent_2(JNIEnv* env, jobject thiz, jint p0, jint p1, jobject p2) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jboolean v4 = 0;
  jint v1 = 0;
  jobject v3 = NULL;
  jboolean v5 = 0;

L_0:
  v4 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "onKeyMultiple", "(IILandroid/view/KeyEvent;)Z"), v1, v2, v3, v0);
  v5 = v4;
  /* return terminator */
  return (jboolean)(intptr_t)v5;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︃︃(IILandroid/view/KeyEvent;)Z -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe03__IILandroid_view_KeyEvent_2 */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︃︄(ZZ)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe04__ZZ(JNIEnv* env, jobject thiz, jboolean p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jobject v16 = NULL;
  jobject v0 = NULL;
  jint v6 = 0;
  jint v7 = 0;
  jlong v15 = 0;
  jboolean v8 = 0;
  jboolean v9 = 0;
  jobject v10 = NULL;
  jboolean v1 = 0;
  jboolean v5 = 0;
  jboolean v2 = 0;
  jboolean v11 = 0;
  jlong v13 = 0;
  jboolean v3 = 0;
  jboolean v4 = 0;
  jlong v14 = 0;
  jlong v12 = 0;

L_0:
  v3 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "Z"));
  /* UNSUPPORTED: if-ne */
  if (v3 != v1) { v8 = (jboolean)v1; v9 = (jboolean)v2; v10 = (jobject)v0; v11 = (jboolean)v3; goto L_c;
 } else { goto L_4;
 }

L_4:
  v4 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︃", "Z"));
  /* UNSUPPORTED: if-ne */
  if (v4 != v2) { v8 = (jboolean)v1; v9 = (jboolean)v2; v10 = (jobject)v0; v11 = (jboolean)v3; goto L_c;
 } else { goto L_8;
 }

L_8:
  v5 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︃", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v5 == 0) { goto L_24;
 } else { v8 = (jboolean)(intptr_t)v12; v9 = (jboolean)(intptr_t)v13; v10 = (jobject)(intptr_t)v14; v11 = (jboolean)(intptr_t)v15; goto L_c;
 }

L_c:
  env->SetBooleanField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "Z"), v8);
  env->SetBooleanField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︃", "Z"), v9);
  v6 = 0;
  env->SetBooleanField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︃", "Z"), v6);
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v11, v11, v11, v11);
  v7 = 1;
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︀", "(Z)V"), v7, v11, v11, v11);
  /* UNSUPPORTED: if-nez */
  if (v8 != 0) { goto L_21;
 } else { goto L_1c;
 }

L_1c:
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︅", "LI/ᅠ︆︅;"));
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("I/ᅠ︆︅"), "ᅟ︀︀", "()V"), v11, v11, v11, v11);
goto L_21;

L_21:
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v11, v11, v11, v11);
goto L_24;

L_24:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︄(ZZ)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe04__ZZ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︄︀(Ljava/lang/CharSequence;ZZ)V: java.lang.StackOverflowError */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︄︂(FF)J */
jlong Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe02__FF(JNIEnv* env, jobject thiz, jfloat p0, jfloat p1) {
  jthrowable pendingException = NULL;
  jlong v17 = 0;
  jint v3 = 0;
  jfloat v10 = 0;
  jfloat v4 = 0;
  jint v8 = 0;
  jobject v0 = NULL;
  jlong v16 = 0;
  jfloat v15 = 0;
  jfloat v2 = 0;
  jobject v6 = NULL;
  jint v13 = 0;
  jint v9 = 0;
  jfloat v1 = 0;
  jobject v7 = NULL;
  jfloat v11 = 0;
  jfloat v14 = 0;
  jfloat v5 = 0;
  jint v12 = 0;

L_0:
  v3 = 0;
  v4 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(FF)F"), v3, v2, v3, v3, v3);
  v5 = v4;
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  v7 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v6, v6, v6, v6);
  v8 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getOffsetX", "()I"), v6, v6, v6, v6);
  v9 = v8;
  v10 = (jfloat)v10;
  /* UNSUPPORTED: add-float-2addr */
  v12 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getOffsetY", "()I"), v10, v10, v10, v10);
  v13 = v12;
  v14 = (jfloat)v14;
  /* UNSUPPORTED: add-float-2addr */
  v16 = (jlong)(intptr_t)env->CallLongMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︂", "(FF)J"), v11, v15, v14, v14);
  v17 = v16;
  /* return terminator */
  return (jlong)(intptr_t)v17;
EX_Return: return (jlong)0;
EX_UnwindBlock: return (jlong)0;
}

/* RegisterNatives entry for ᅟ︄︂(FF)J -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe02__FF */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︄︃(ILandroid/view/KeyEvent;)Z */
jboolean Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe03__ILandroid_view_KeyEvent_2(JNIEnv* env, jobject thiz, jint p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v3 = 0;
  jboolean v4 = 0;
  jobject v2 = NULL;
  jint v1 = 0;

L_0:
  v3 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "onKeyUp", "(ILandroid/view/KeyEvent;)Z"), v1, v2, v0, v0);
  v4 = v3;
  /* return terminator */
  return (jboolean)(intptr_t)v4;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︄︃(ILandroid/view/KeyEvent;)Z -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe03__ILandroid_view_KeyEvent_2 */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︄︄()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe04__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jboolean v3 = 0;
  jint v22 = 0;
  jint v28 = 0;
  jint v4 = 0;
  jint v23 = 0;
  jobject v0 = NULL;
  jobject v21 = NULL;
  jint v11 = 0;
  jint v14 = 0;
  jboolean v5 = 0;
  jobject v24 = NULL;
  jint v25 = 0;
  jobject v18 = NULL;
  jint v6 = 0;
  jobject v7 = NULL;
  jint v17 = 0;
  jobject v9 = NULL;
  jint v16 = 0;
  jobject v29 = NULL;
  jint v8 = 0;
  jint v26 = 0;
  jlong v19 = 0;
  jint v27 = 0;
  jobject v1 = NULL;
  jint v13 = 0;
  jobject v15 = NULL;
  jlong v20 = 0;
  jint v12 = 0;
  jobject v10 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︍︆"), "ᅟ︌︀", "LI/ᅠ︇︋;"));
  v3 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︅︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_2a;
 } else { goto L_8;
 }

L_8:
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"));
  /* UNSUPPORTED: if-lez */
  if (v4 <= 0) { goto L_2a;
 } else { goto L_c;
 }

L_c:
  v5 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︊︀", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v5 != 0) { goto L_2a;
 } else { goto L_10;
 }

L_10:
  v6 = 1;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︊︀", "Z"), v6);
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︄︀", "Ljava/util/ArrayList;"));
  /* UNSUPPORTED: sub-int-2addr */
  v9 = (jobject)env->CallObjectMethod((jobject)v7, env->GetMethodID(env->FindClass("java/util/ArrayList"), "get", "(I)Ljava/lang/Object;"), v8, v1, v1, v1);
  v10 = v9;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︂︋"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("I/ᅠ︂︋"), "ᅟ︉︀", "(LI/ᅟ︍︆;)V"), v1, v1, v1, v1);
  v12 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"));
  /* UNSUPPORTED: sub-int-2addr */
  env->SetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"), v13);
  v14 = 0;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︊︀", "Z"), v14);
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("I/ᅠ︂︋"), "ᅟ︄︀", "LI/ᅠ️︉;"));
  /* UNSUPPORTED: goto */
v17 = (jint)(intptr_t)v19; v18 = (jobject)v0; goto L_2b;

L_2a:
  v16 = 0;
v17 = (jint)v16; v18 = (jobject)(intptr_t)v20; goto L_2b;

L_2b:
  /* UNSUPPORTED: if-eqz */
  if (v17 == 0) { goto L_3f;
 } else { goto L_2d;
 }

L_2d:
  v21 = (jobject)env->GetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅠ️︉"), "ᅟ︀︀", "LI/ᅟ︂︅;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
  v22 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v21, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
  v23 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v21, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
  v24 = (jobject)env->GetObjectField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅠ️︉"), "ᅟ︁︀", "LI/ᅟ︂︅;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
  v25 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
  v26 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
  v27 = 1;
  v28 = 1;
  /* dbg-move v29 v18 dv=Ljava/lang/Object; sv=Lbin/nt/editor/widget/CodeEditor; */
  env->CallVoidMethod((jobject)v29, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "(IIIIIZ)V"), v22, v23, v25, v26, v28, v27); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_6; }
goto L_3f;

L_3f:
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "()V"), v17, v17, v17, v17);
  /* return terminator */
  return;

EX_LandingPad_6:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/IndexOutOfBoundsException"))) goto L_3f;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︄︄()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe04__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︅︀()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︅︂(I)I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︅︃()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe05_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v15 = NULL;
  jobject v19 = NULL;
  jobject v14 = NULL;
  jobject v8 = NULL;
  jboolean v2 = 0;
  jobject v5 = NULL;
  jint v17 = 0;
  jobject v6 = NULL;
  jobject v0 = NULL;
  jobject v7 = NULL;
  jboolean v3 = 0;
  jobject v9 = NULL;
  jobject v18 = NULL;
  jobject v4 = NULL;
  jobject v13 = NULL;
  jobject v16 = NULL;
  jint v12 = 0;
  jobject v10 = NULL;
  jobject v1 = NULL;
  jobject v11 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︄", "Landroid/content/ClipboardManager;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v2 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v1, env->GetMethodID(env->FindClass("android/content/ClipboardManager"), "hasPrimaryClip", "()Z"), v1, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v3 = v2;
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_1b;
 } else { goto L_8;
 }

L_8:
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︄", "Landroid/content/ClipboardManager;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v5 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/ClipboardManager"), "getPrimaryClip", "()Landroid/content/ClipData;"), v4, v4, v4, v4); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v6 = v5;
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { goto L_11;
 } else { goto L_10;
 }

L_10:
  /* UNSUPPORTED: goto */
goto L_1b;

L_11:
  v7 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︀", "(Landroid/content/ClipData;)Ljava/lang/String;"), v6, v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v8 = v7;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︃", "(Ljava/lang/String;)V"), v8, v8, v8, v8); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
goto L_18;

L_19:
  v9 = pendingException;
  /* UNSUPPORTED: goto */
goto L_1c;

L_1c:
  v10 = env->NewStringUTF("CodeEditor");
  v11 = env->NewStringUTF("Error pasting text to editor");
  v12 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/util/Log"), env->GetStaticMethodID(env->FindClass("android/util/Log"), "w", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)I"), v10, v11, v9, v9, v9);
  v13 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v9, v9, v9, v9);
  v14 = v13;
  v15 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("java/lang/Object"), "toString", "()Ljava/lang/String;"), v9, v9, v9, v9);
  v16 = v15;
  v17 = 0;
  v18 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"), v14, v16, v17, v16, v16);
  v19 = v18;
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v19, v19, v19, v19);
goto L_33;

L_18:
  /* UNSUPPORTED: goto */
goto L_33;

L_33:
  /* return terminator */
  return;

L_1b:
  /* return terminator */
  return;

EX_LandingPad_0:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_19;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︃()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe05_0fe03__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︅︄()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︆︀(Z)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe00__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v8 = NULL;
  jobject v13 = NULL;
  jobject v2 = NULL;
  jboolean v1 = 0;
  jobject v12 = NULL;
  jobject v15 = NULL;
  jobject v20 = NULL;
  jobject v7 = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jint v16 = 0;
  jobject v14 = NULL;
  jobject v10 = NULL;
  jint v19 = 0;
  jboolean v4 = 0;
  jint v18 = 0;
  jint v11 = 0;
  jint v21 = 0;
  jint v17 = 0;
  jobject v6 = NULL;
  jint v9 = 0;
  jboolean v3 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v3 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︅︇"), "ᅟ︀︀", "()Z"), v2, v2, v2, v2);
  v4 = v3;
  /* UNSUPPORTED: if-eqz */
  if (v4 == 0) { goto L_1a;
 } else { goto L_8;
 }

L_8:
  v5 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getText", "()LI/ᅟ︍︆;"), v4, v4, v4, v4);
  v6 = v5;
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v9 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I"));
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I"));
v19 = (jint)v9; v20 = (jobject)v6; v21 = (jint)v11; goto L_16;

L_1a:
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_20;
 } else { goto L_1c;
 }

L_1c:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︀", "()V"), v4, v4, v4, v4);
  /* UNSUPPORTED: goto */
goto L_2e;

L_20:
  v12 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getLineSeparator", "()LI/ᅠ︉︁;"), v4, v4, v4, v4);
  v13 = v12;
  v14 = (jobject)env->CallObjectMethod((jobject)v13, env->GetMethodID(env->FindClass("I/ᅠ︉︁"), "ᅟ︀︀", "()Ljava/lang/String;"), v4, v4, v4, v4);
  v15 = v14;
  v16 = (jint)(intptr_t)env->CallIntMethod((jobject)v15, env->GetMethodID(env->FindClass("java/lang/String"), "length", "()I"), v4, v4, v4, v4);
  v17 = v16;
  v18 = 0;
  /* UNSUPPORTED: goto */
v19 = (jint)v18; v20 = (jobject)v15; v21 = (jint)v17; goto L_16;

L_16:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︀", "(IILjava/lang/CharSequence;)V"), v19, v21, v20, v21);
  /* UNSUPPORTED: goto */
goto L_2e;

L_2e:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︆︀(Z)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe00__Z */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︆︂(I)I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︆︃(Ljava/lang/String;)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe03__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v10 = 0;
  jint v17 = 0;
  jobject v2 = NULL;
  jlong v24 = 0;
  jobject v20 = NULL;
  jint v3 = 0;
  jboolean v6 = 0;
  jint v11 = 0;
  jobject v7 = NULL;
  jboolean v4 = 0;
  jobject v19 = NULL;
  jobject v0 = NULL;
  jobject v15 = NULL;
  jobject v8 = NULL;
  jobject v22 = NULL;
  jobject v1 = NULL;
  jobject v12 = NULL;
  jobject v23 = NULL;
  jobject v5 = NULL;
  jobject v13 = NULL;
  jobject v18 = NULL;
  jlong v25 = 0;
  jobject v16 = NULL;
  jobject v14 = NULL;
  jobject v21 = NULL;
  jobject v9 = NULL;

L_0:
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_46;
 } else { goto L_2;
 }

L_2:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︀", "LI/ᅟ︊︊;"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_46;
 } else { goto L_6;
 }

L_6:
  v3 = 1;
  v4 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︊︊"), "commitText", "(Ljava/lang/CharSequence;I)Z"), v1, v3, v2, v2);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︅", "LI/ᅟ︆︈;"));
  v6 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︆︈"), "formatPastedText", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v6 == 0) { v22 = (jobject)v2; v23 = (jobject)v0; goto L_43;
 } else { goto L_10;
 }

L_10:
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︆", "LI/ᅠ️︉;"));
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅠ️︉"), "ᅟ︀︀", "LI/ᅟ︂︅;"));
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅠ️︉"), "ᅟ︁︀", "LI/ᅟ︂︅;"));
  env->MonitorEnter((jobject)v0);
goto L_17;

L_17:
  v10 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  /* UNSUPPORTED: if-gt */
  if (v10 > v11) { goto L_39;
 } else { goto L_1d;
 }

L_1d:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︂", "()V"), v10, v10, v10, v10); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︄", "LI/ᅠ︍︀;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v13 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v10, v10, v10, v10); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v15 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︆︀", "()LI/ᅟ︍︆;"), v10, v10, v10, v10); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v16 = (jobject)(intptr_t)v15;
  v17 = 0;
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︌︁", "(Z)V"), v17, v17, v17, v17); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  v18 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getCursorRange", "()LI/ᅠ️︉;"), v17, v17, v17, v17); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "postInvalidate", "()V"), v17, v17, v17, v17); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_4; }
goto L_35;

L_35:
  env->MonitorExit((jobject)v0);
  /* UNSUPPORTED: goto */
v22 = (jobject)(intptr_t)v24; v23 = (jobject)(intptr_t)v25; goto L_43;

L_39:
  v19 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v20 = env->NewStringUTF("start > end");
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v20, v20, v20, v20); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  pendingException = (jthrowable)v19; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_37:
  v21 = pendingException;
  /* UNSUPPORTED: goto */
goto L_41;

L_41:
  env->MonitorExit((jobject)v0);
  pendingException = (jthrowable)v21; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_43:
  env->CallVoidMethod((jobject)v23, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "()V"), v22, v22, v22, v22);
goto L_46;

L_46:
  /* return terminator */
  return;

EX_LandingPad_4:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_37;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_7:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_37;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︆︃(Ljava/lang/String;)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe03__Ljava_lang_String_2 */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︆︄()F */
jfloat Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe04__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v30 = 0;
  jint v87 = 0;
  jobject v91 = NULL;
  jint v80 = 0;
  jobject v54 = NULL;
  jobject v83 = NULL;
  jint v19 = 0;
  jint v65 = 0;
  jint v23 = 0;
  jint v32 = 0;
  jfloat v46 = 0;
  jint v39 = 0;
  jobject v70 = NULL;
  jboolean v77 = 0;
  jobject v1 = NULL;
  jint v36 = 0;
  jint v40 = 0;
  jint v43 = 0;
  jint v45 = 0;
  jobject v71 = NULL;
  jint v44 = 0;
  jint v41 = 0;
  jfloat v8 = 0;
  jlong v94 = 0;
  jint v3 = 0;
  jobject v73 = NULL;
  jint v37 = 0;
  jobject v0 = NULL;
  jfloat v22 = 0;
  jfloat v29 = 0;
  jfloat v12 = 0;
  jlong v97 = 0;
  jobject v79 = NULL;
  jint v34 = 0;
  jint v10 = 0;
  jfloat v16 = 0;
  jobject v75 = NULL;
  jobject v6 = NULL;
  jobject v58 = NULL;
  jint v85 = 0;
  jint v17 = 0;
  jfloat v52 = 0;
  jboolean v51 = 0;
  jobject v88 = NULL;
  jobject v59 = NULL;
  jint v14 = 0;
  jobject v50 = NULL;
  jlong v96 = 0;
  jint v27 = 0;
  jint v20 = 0;
  jobject v89 = NULL;
  jobject v2 = NULL;
  jobject v69 = NULL;
  jobject v82 = NULL;
  jint v4 = 0;
  jobject v7 = NULL;
  jint v63 = 0;
  jfloat v15 = 0;
  jint v74 = 0;
  jobject v11 = NULL;
  jlong v98 = 0;
  jobject v5 = NULL;
  jfloat v64 = 0;
  jobject v68 = NULL;
  jlong v93 = 0;
  jint v31 = 0;
  jobject v56 = NULL;
  jobject v81 = NULL;
  jfloat v99 = 0;
  jint v38 = 0;
  jint v72 = 0;
  jint v84 = 0;
  jlong v95 = 0;
  jint v13 = 0;
  jfloat v42 = 0;
  jarray v61 = NULL;
  jfloat v21 = 0;
  jint v92 = 0;
  jobject v62 = NULL;
  jint v48 = 0;
  jfloat v9 = 0;
  jobject v86 = NULL;
  jboolean v55 = 0;
  jint v60 = 0;
  jobject v49 = NULL;
  jint v24 = 0;
  jint v18 = 0;
  jboolean v67 = 0;
  jobject v57 = NULL;
  jlong v100 = 0;
  jint v33 = 0;
  jfloat v25 = 0;
  jboolean v76 = 0;
  jint v78 = 0;
  jfloat v35 = 0;
  jint v47 = 0;
  jobject v90 = NULL;
  jint v28 = 0;
  jfloat v66 = 0;
  jint v53 = 0;
  jfloat v26 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I"));
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︀", "LI/ᅟ︊︀;"));
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("I/ᅟ︊︀"), "ᅟ︁︀", "(II)[F"), v3, v4, v4, v4);
  v7 = v6;
  v8 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︎︂", "()F"), v7, v7, v7, v7);
  v9 = v8;
  v10 = 1;
  env->GetIntArrayRegion((jintArray)v7, (jsize)(intptr_t)v10, 1, (jint*)&v11);
  /* UNSUPPORTED: add-float-2addr */
  v13 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getOffsetX", "()I"), v7, v7, v7, v7);
  v14 = v13;
  v15 = (jfloat)v15;
  /* UNSUPPORTED: sub-float-2addr */
  v17 = 0;
  env->GetIntArrayRegion((jintArray)v18, (jsize)(intptr_t)v17, 1, (jint*)&v18);
  v19 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getOffsetY", "()I"), v18, v18, v18, v18);
  v20 = v19;
  v21 = (jfloat)v21;
  /* UNSUPPORTED: sub-float */
  v23 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getRowHeight", "()I"), v18, v18, v18, v18);
  v24 = v23;
  v25 = (jfloat)v25;
  /* UNSUPPORTED: sub-float */
  v27 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getRowHeight", "()I"), v25, v25, v25, v25);
  v28 = v27;
  v29 = (jfloat)v29;
  /* UNSUPPORTED: div-float */
  v31 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "round", "(F)I"), v30, v30, v30, v30, v30);
  v32 = v31;
  v33 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︂", "(I)I"), v32, v32, v32, v32);
  v34 = v33;
  v35 = (jfloat)v34;
  v36 = 0;
  v37 = (v16 > v36 ? 1 : (v16 < v36 ? -1 : 0));
  /* UNSUPPORTED: if-gez */
  if (v37 >= 0) { goto L_45;
 } else { goto L_42;
 }

L_42:
  v38 = 0;
  v39 = 0;
  /* UNSUPPORTED: goto */
v52 = (jfloat)(intptr_t)v39; v53 = (jint)v38; goto L_56;

L_45:
  v40 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v36, v36, v36, v36);
  v41 = v40;
  v42 = (jfloat)v42;
  v43 = (v16 > v43 ? 1 : (v16 < v43 ? -1 : 0));
  /* UNSUPPORTED: if-lez */
  if (v43 <= 0) { goto L_55;
 } else { goto L_4e;
 }

L_4e:
  v44 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v43, v43, v43, v43);
  v45 = v44;
  v46 = (jfloat)v45;
  v47 = 0;
  /* UNSUPPORTED: goto */
v52 = (jfloat)v46; v53 = (jint)v47; goto L_56;

L_55:
  v48 = 1;
v52 = (jfloat)v16; v53 = (jint)v48; goto L_56;

L_56:
  v49 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︀", "LI/ᅟ︊︊;"));
  v50 = (jobject)env->GetObjectField((jobject)(intptr_t)v50, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︁︀", "LI/ᅟ︇︆;"));
  v51 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v50, env->GetFieldID(env->FindClass("I/ᅟ︇︆"), "ᅟ︂︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v51 == 0) { goto L_5f;
 } else { goto L_5e;
 }

L_5e:
  /* return terminator */
  return (jfloat)(intptr_t)v52;

L_5f:
  v54 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︅", "LI/ᅟ︆︈;"));
  v55 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v55, env->GetFieldID(env->FindClass("I/ᅟ︆︈"), "reportCursorAnchor", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v55 == 0) { v99 = (jfloat)v52; goto L_bc;
 } else { goto L_65;
 }

L_65:
  v56 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︅", "Landroid/view/inputmethod/CursorAnchorInfo$Builder;"));
  env->CallVoidMethod((jobject)v56, env->GetMethodID(env->FindClass("android/view/inputmethod/CursorAnchorInfo$Builder"), "reset", "()V"), v53, v53, v53, v53);
  v57 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︄", "Landroid/graphics/Matrix;"));
  v58 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getMatrix", "()Landroid/graphics/Matrix;"), v53, v53, v53, v53);
  v59 = v58;
  env->CallVoidMethod((jobject)v57, env->GetMethodID(env->FindClass("android/graphics/Matrix"), "set", "(Landroid/graphics/Matrix;)V"), v59, v53, v53, v53);
  v60 = 2;
  v61 = env->NewIntArray((jsize)(intptr_t)v60);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getLocationOnScreen", "([I)V"), v61, v53, v53, v53);
  v62 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︄", "Landroid/graphics/Matrix;"));
  env->GetIntArrayRegion((jintArray)v61, (jsize)(intptr_t)v63, 1, (jint*)&v63);
  v64 = (jfloat)v64;
  env->GetIntArrayRegion((jintArray)v65, (jsize)(intptr_t)v10, 1, (jint*)&v65);
  v66 = (jfloat)v66;
  v67 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v62, env->GetMethodID(env->FindClass("android/graphics/Matrix"), "postTranslate", "(FF)Z"), v64, v66, v53, v53);
  v68 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︅︄", "Landroid/graphics/Matrix;"));
  v69 = (jobject)env->CallObjectMethod((jobject)v56, env->GetMethodID(env->FindClass("android/view/inputmethod/CursorAnchorInfo$Builder"), "setMatrix", "(Landroid/graphics/Matrix;)Landroid/view/inputmethod/CursorAnchorInfo$Builder;"), v68, v53, v53, v53);
  v70 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v71 = (jobject)env->GetObjectField((jobject)(intptr_t)v70, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v72 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v72, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I"));
  v73 = (jobject)env->GetObjectField((jobject)(intptr_t)v73, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v74 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v74, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I"));
  v75 = (jobject)env->CallObjectMethod((jobject)v56, env->GetMethodID(env->FindClass("android/view/inputmethod/CursorAnchorInfo$Builder"), "setSelectionRange", "(II)Landroid/view/inputmethod/CursorAnchorInfo$Builder;"), v72, v74, v53, v53);
  v76 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v50, env->GetMethodID(env->FindClass("I/ᅟ︇︆"), "ᅟ︀︀", "()Z"), v53, v53, v53, v53);
  v77 = v76;
  /* UNSUPPORTED: if-eqz */
  if (v77 == 0) { goto L_a9;
 } else { goto L_9c;
 }

L_9c:
  v78 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v50, env->GetFieldID(env->FindClass("I/ᅟ︇︆"), "ᅟ︀︀", "I"));
  v79 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  v80 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v80, env->GetFieldID(env->FindClass("I/ᅟ︇︆"), "ᅟ︁︀", "I"));
  v81 = (jobject)env->CallObjectMethod((jobject)v79, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ️︁", "(II)Ljava/lang/String;"), v78, v80, v53, v53);
  v82 = v81;
  v83 = (jobject)env->CallObjectMethod((jobject)v56, env->GetMethodID(env->FindClass("android/view/inputmethod/CursorAnchorInfo$Builder"), "setComposingText", "(ILjava/lang/CharSequence;)Landroid/view/inputmethod/CursorAnchorInfo$Builder;"), v78, v82, v53, v53);
goto L_a9;

L_a9:
  /* UNSUPPORTED: if-eqz */
  if (v53 == 0) { goto L_ad;
 } else { goto L_ab;
 }

L_ab:
  v84 = 1;
  /* UNSUPPORTED: goto */
v92 = (jint)v84; goto L_ae;

L_ad:
  v85 = 2;
v92 = (jint)v85; goto L_ae;

L_ae:
  /* dbg-move v86 v93 dv=Ljava/lang/Object; sv=null */
  /* dbg-move v87 v94 dv=I sv=null */
  v88 = (jobject)env->CallObjectMethod((jobject)v86, env->GetMethodID(env->FindClass("android/view/inputmethod/CursorAnchorInfo$Builder"), "setInsertionMarkerLocation", "(FFFFI)Landroid/view/inputmethod/CursorAnchorInfo$Builder;"), v87, v95, v96, v97, v92);
  v89 = (jobject)env->GetObjectField((jobject)(intptr_t)v98, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "Landroid/view/inputmethod/InputMethodManager;"));
  v90 = (jobject)env->CallObjectMethod((jobject)v93, env->GetMethodID(env->FindClass("android/view/inputmethod/CursorAnchorInfo$Builder"), "build", "()Landroid/view/inputmethod/CursorAnchorInfo;"), v89, v89, v89, v89);
  v91 = (jobject)(intptr_t)v90;
  env->CallVoidMethod((jobject)v89, env->GetMethodID(env->FindClass("android/view/inputmethod/InputMethodManager"), "updateCursorAnchorInfo", "(Landroid/view/View;Landroid/view/inputmethod/CursorAnchorInfo;)V"), v98, v91, v89, v89);
v99 = (jfloat)(intptr_t)v100; goto L_bc;

L_bc:
  /* return terminator */
  return (jfloat)(intptr_t)v99;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for ᅟ︆︄()F -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe04__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︇︀(LI/ᅟ︍︆;)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︇︂(I)I: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︇︃(Ljava/lang/Runnable;J)V: java.lang.IllegalStateException: unknown phi type v6_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︇︄()V: java.lang.IllegalStateException: unknown phi type v7_7 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︈︀(IILjava/lang/CharSequence;)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe08_0fe00__IILjava_lang_CharSequence_2(JNIEnv* env, jobject thiz, jint p0, jint p1, jobject p2) {
  jthrowable pendingException = NULL;
  jint v52 = 0;
  jobject v42 = NULL;
  jobject v26 = NULL;
  jobject v40 = NULL;
  jobject v43 = NULL;
  jlong v64 = 0;
  jobject v0 = NULL;
  jobject v3 = NULL;
  jobject v20 = NULL;
  jobject v39 = NULL;
  jint v12 = 0;
  jobject v30 = NULL;
  jobject v62 = NULL;
  jobject v5 = NULL;
  jlong v37 = 0;
  jobject v34 = NULL;
  jint v45 = 0;
  jint v46 = 0;
  jint v47 = 0;
  jobject v29 = NULL;
  jlong v63 = 0;
  jobject v60 = NULL;
  jint v4 = 0;
  jint v1 = 0;
  jint v32 = 0;
  jlong v35 = 0;
  jint v13 = 0;
  jint v19 = 0;
  jobject v57 = NULL;
  jint v17 = 0;
  jobject v53 = NULL;
  jobject v61 = NULL;
  jint v6 = 0;
  jobject v44 = NULL;
  jobject v58 = NULL;
  jobject v59 = NULL;
  jobject v48 = NULL;
  jobject v10 = NULL;
  jint v31 = 0;
  jobject v25 = NULL;
  jint v2 = 0;
  jobject v22 = NULL;
  jint v50 = 0;
  jobject v16 = NULL;
  jobject v18 = NULL;
  jobject v49 = NULL;
  jobject v55 = NULL;
  jint v41 = 0;
  jint v7 = 0;
  jobject v21 = NULL;
  jobject v56 = NULL;
  jobject v33 = NULL;
  jobject v9 = NULL;
  jobject v28 = NULL;
  jobject v24 = NULL;
  jobject v11 = NULL;
  jint v14 = 0;
  jobject v23 = NULL;
  jlong v38 = 0;
  jlong v36 = 0;
  jobject v15 = NULL;
  jobject v54 = NULL;
  jint v8 = 0;
  jobject v27 = NULL;
  jobject v51 = NULL;

L_0:
  /* UNSUPPORTED: if-ge */
  if (v2 >= v1) { goto L_3;
 } else { goto L_2;
 }

L_2:
  /* return terminator */
  return;

L_3:
  /* UNSUPPORTED: sub-int */
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︅", "LI/ᅟ︆︈;"));
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︆︈"), "clipboardTextLengthLimit", "I"));
  v7 = 2131886323;
  v8 = 0;
  /* UNSUPPORTED: if-le */
  if (v4 <= v6) { goto L_25;
 } else { goto L_f;
 }

L_f:
  v9 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v4, v4, v4, v4);
  v10 = v9;
  v11 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︋️"), env->GetStaticFieldID(env->FindClass("I/ᅟ︋️"), "ᅟ︀︀", "Landroid/util/SparseIntArray;"));
  v12 = (jint)(intptr_t)env->CallIntMethod((jobject)v11, env->GetMethodID(env->FindClass("android/util/SparseIntArray"), "get", "(I)I"), v7, v4, v4, v4);
  v13 = v12;
  /* UNSUPPORTED: if-nez */
  if (v13 != 0) { goto L_1c;
 } else { goto L_1b;
 }

L_1b:
  /* UNSUPPORTED: goto */
v17 = (jint)v7; goto L_1d;

L_1c:
  /* dbg-move v14 v13 dv=I sv=I */
v17 = (jint)v14; goto L_1d;

L_1d:
  v15 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;II)Landroid/widget/Toast;"), v10, v17, v8, v4, v4);
  v16 = v15;
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v4, v4, v4, v4);
  /* return terminator */
  return;

L_25:
  v18 = (jobject)(v0 && env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅟ︍︆")) ? 1 : 0);
  /* UNSUPPORTED: if-eqz */
  if (v18 == 0) { goto L_32;
 } else { goto L_29;
 }

L_29:
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅟ︍︆"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v20 = (jobject)env->CallObjectMethod((jobject)v19, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ️︁", "(II)Ljava/lang/String;"), v1, v2, v18, v18); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v21 = (jobject)(intptr_t)v20;
  /* UNSUPPORTED: goto */
v29 = (jobject)v21; goto L_3a;

L_32:
  v22 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/CharSequence"), "subSequence", "(II)Ljava/lang/CharSequence;"), v1, v2, v18, v18); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v23 = (jobject)(intptr_t)v22;
  v24 = (jobject)env->CallObjectMethod((jobject)v23, env->GetMethodID(env->FindClass("java/lang/CharSequence"), "toString", "()Ljava/lang/String;"), v18, v18, v18, v18); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v25 = v24;
v29 = (jobject)v25; goto L_3a;

L_3a:
  v26 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︄", "Landroid/content/ClipboardManager;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v27 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/content/ClipData"), env->GetStaticMethodID(env->FindClass("android/content/ClipData"), "newPlainText", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Landroid/content/ClipData;"), v29, v29, v18, v18, v18); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v28 = v27;
  env->CallVoidMethod((jobject)v26, env->GetMethodID(env->FindClass("android/content/ClipboardManager"), "setPrimaryClip", "(Landroid/content/ClipData;)V"), v28, v18, v18, v18); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
goto L_43;

L_30:
  v30 = pendingException;
  /* UNSUPPORTED: goto */
goto L_44;

L_44:
  v39 = (jobject)env->CallObjectMethod((jobject)v30, env->GetMethodID(env->FindClass("java/lang/Throwable"), "getCause", "()Ljava/lang/Throwable;"), v33, v33, v33, v33);
  v40 = v39;
  v41 = (jint)(intptr_t)(v41 && env->IsInstanceOf((jobject)v41, env->FindClass("android/os/TransactionTooLargeException")) ? 1 : 0);
  /* UNSUPPORTED: if-eqz */
  if (v41 == 0) { goto L_62;
 } else { goto L_4c;
 }

L_4c:
  v42 = (jobject)env->CallObjectMethod((jobject)v34, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v33, v33, v33, v33);
  v43 = v42;
  v44 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︋️"), env->GetStaticFieldID(env->FindClass("I/ᅟ︋️"), "ᅟ︀︀", "Landroid/util/SparseIntArray;"));
  v45 = (jint)(intptr_t)env->CallIntMethod((jobject)v44, env->GetMethodID(env->FindClass("android/util/SparseIntArray"), "get", "(I)I"), v31, v33, v33, v33);
  v46 = v45;
  /* UNSUPPORTED: if-nez */
  if (v46 != 0) { goto L_59;
 } else { goto L_58;
 }

L_58:
  /* UNSUPPORTED: goto */
v50 = (jint)v31; goto L_5a;

L_59:
  /* dbg-move v47 v46 dv=I sv=I */
v50 = (jint)v47; goto L_5a;

L_5a:
  v48 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;II)Landroid/widget/Toast;"), v43, v50, v32, v33, v33);
  v49 = v48;
v61 = (jobject)(intptr_t)v63; v62 = (jobject)(intptr_t)v64; goto L_5e;

L_62:
  v51 = env->NewStringUTF("CodeEditor");
  v52 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("android/util/Log"), env->GetStaticMethodID(env->FindClass("android/util/Log"), "w", "(Ljava/lang/String;Ljava/lang/Throwable;)I"), v51, v30, v33, v33, v33);
  v53 = (jobject)env->CallObjectMethod((jobject)v34, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v33, v33, v33, v33);
  v54 = v53;
  v55 = (jobject)env->CallObjectMethod((jobject)v30, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v33, v33, v33, v33);
  v56 = v55;
  v57 = (jobject)env->CallObjectMethod((jobject)v56, env->GetMethodID(env->FindClass("java/lang/Class"), "toString", "()Ljava/lang/String;"), v33, v33, v33, v33);
  v58 = v57;
  v59 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"), v54, v58, v32, v33, v33);
  v60 = v59;
  /* UNSUPPORTED: goto */
v61 = (jobject)v60; v62 = (jobject)v33; goto L_5e;

L_5e:
  env->CallVoidMethod((jobject)v61, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v62, v62, v62, v62);
  /* UNSUPPORTED: goto */
goto L_78;

L_43:
  /* UNSUPPORTED: goto */
goto L_78;

L_78:
  /* return terminator */
  return;

EX_LandingPad_7:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/RuntimeException"))) goto L_30;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︈︀(IILjava/lang/CharSequence;)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe08_0fe00__IILjava_lang_CharSequence_2 */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︈︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︈︂(Z)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︈︃(Ljava/lang/Runnable;)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe08_0fe03__Ljava_lang_Runnable_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jint v4 = 0;
  jobject v0 = NULL;
  jboolean v5 = 0;
  jobject v2 = NULL;
  jobject v3 = NULL;

L_0:
  v2 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︇︊"), env->GetStaticFieldID(env->FindClass("I/ᅟ︇︊"), "ᅟ︀︀", "LI/ᅟ︇︊;"));
  v3 = env->AllocObject(env->FindClass("I/ᅟ︉︅"));
  v4 = 1;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("I/ᅟ︉︅"), "<init>", "(Lbin/nt/editor/widget/CodeEditor;Ljava/lang/Runnable;I)V"), v0, v1, v4, v2);
  v5 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v2, env->GetMethodID(env->FindClass("android/os/Handler"), "post", "(Ljava/lang/Runnable;)Z"), v3, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︈︃(Ljava/lang/Runnable;)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe08_0fe03__Ljava_lang_Runnable_2 */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︉︁()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jboolean v2 = 0;
  jboolean v3 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v2 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v1, env->GetMethodID(env->FindClass("I/ᅟ︅︇"), "ᅟ︀︀", "()Z"), v1, v1, v1, v1);
  v3 = v2;
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_13;
 } else { goto L_8;
 }

L_8:
  v4 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︀", "(Z)V"), v4, v4, v4, v4);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︁", "()V"), v4, v4, v4, v4);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "()V"), v4, v4, v4, v4);
  /* UNSUPPORTED: goto */
goto L_16;

L_13:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︁", "()V"), v3, v3, v3, v3);
goto L_16;

L_16:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︉︁()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe01__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︉︂()Z */
jboolean Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jboolean v2 = 0;
  jint v4 = 0;
  jobject v0 = NULL;
  jint v5 = 0;
  jboolean v1 = 0;
  jint v3 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_d;
 } else { goto L_4;
 }

L_4:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︆︂", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_d;
 } else { goto L_8;
 }

L_8:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︂", "()V"), v2, v2, v2, v2);
  v3 = 1;
  /* UNSUPPORTED: goto */
v5 = (jint)(intptr_t)v2; goto L_e;

L_d:
  v4 = 0;
v5 = (jint)v4; goto L_e;

L_e:
  /* return terminator */
  return (jboolean)(intptr_t)v5;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︉︂()Z -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe02__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︉︃()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v12 = NULL;
  jint v10 = 0;
  jobject v2 = NULL;
  jint v14 = 0;
  jlong v17 = 0;
  jobject v11 = NULL;
  jboolean v8 = 0;
  jint v15 = 0;
  jint v4 = 0;
  jint v9 = 0;
  jint v16 = 0;
  jlong v21 = 0;
  jobject v18 = NULL;
  jint v7 = 0;
  jint v13 = 0;
  jobject v19 = NULL;
  jlong v22 = 0;
  jint v6 = 0;
  jlong v20 = 0;
  jboolean v3 = 0;
  jobject v5 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︍︆"), "ᅟ︌︀", "LI/ᅠ︇︋;"));
  v3 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︅︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { v18 = (jobject)v0; v19 = (jobject)v1; goto L_2c;
 } else { goto L_8;
 }

L_8:
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︄︀", "Ljava/util/ArrayList;"));
  v6 = (jint)(intptr_t)env->CallIntMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v1, v1, v1, v1);
  v7 = v6;
  /* UNSUPPORTED: if-ge */
  if (v4 >= v7) { v18 = (jobject)v0; v19 = (jobject)v1; goto L_2c;
 } else { goto L_12;
 }

L_12:
  v8 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︊︀", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v8 != 0) { v18 = (jobject)(intptr_t)v20; v19 = (jobject)(intptr_t)v17; goto L_2c;
 } else { goto L_16;
 }

L_16:
  v9 = 1;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︊︀", "Z"), v9);
  v10 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"));
  v11 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/ArrayList"), "get", "(I)Ljava/lang/Object;"), v10, v17, v17, v17);
  v12 = v11;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︂︋"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("I/ᅠ︂︋"), "ᅟ︇︀", "(LI/ᅟ︍︆;)V"), v17, v17, v17, v17);
  v14 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"));
  /* UNSUPPORTED: add-int-2addr */
  env->SetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︉︀", "I"), v15);
  v16 = 0;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︇︋"), "ᅟ︊︀", "Z"), v16);
v18 = (jobject)(intptr_t)v21; v19 = (jobject)(intptr_t)v22; goto L_2c;

L_2c:
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︃", "()V"), v19, v19, v19, v19);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︉︃()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe03__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︊︂()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0a_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︄", "LI/ᅠ︍︀;"));
  v2 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v1, v1, v1, v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︊︂()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0a_0fe02__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︊︃()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0a_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_7;
 } else { goto L_4;
 }

L_4:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "requestLayout", "()V"), v1, v1, v1, v1);
goto L_7;

L_7:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︊︃()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0a_0fe03__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︋︀(LI/ᅟ︍︆;IIIILjava/lang/CharSequence;)V: java.lang.StackOverflowError */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︋︂()Z */
jboolean Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0b_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jboolean v6 = 0;
  jint v5 = 0;
  jint v2 = 0;
  jobject v0 = NULL;
  jint v8 = 0;
  jint v9 = 0;
  jlong v10 = 0;
  jint v4 = 0;
  jboolean v7 = 0;
  jlong v11 = 0;
  jobject v1 = NULL;
  jint v3 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︅", "LI/ᅟ︆︈;"));
  v2 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︆︈"), "mouseMode", "I"));
  v3 = 1;
  /* UNSUPPORTED: if-eq */
  if (v2 == v3) { goto L_17;
 } else { goto L_7;
 }

L_7:
  v4 = 2;
  v5 = 0;
  /* UNSUPPORTED: if-eq */
  if (v2 == v4) { goto L_16;
 } else { goto L_b;
 }

L_b:
  v6 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︂", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { v9 = (jint)v3; goto L_15;
 } else { goto L_f;
 }

L_f:
  v7 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_14;
 } else { goto L_13;
 }

L_13:
  /* UNSUPPORTED: goto */
v9 = (jint)(intptr_t)v10; goto L_15;

L_14:
  v8 = 0;
v9 = (jint)(intptr_t)v11; goto L_15;

L_15:
  /* return terminator */
  return (jboolean)(intptr_t)v9;

L_16:
  /* return terminator */
  return (jboolean)(intptr_t)v5;

L_17:
  /* return terminator */
  return (jboolean)(intptr_t)v3;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︋︂()Z -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0b_0fe02__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︋︃()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0b_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v9 = NULL;
  jobject v7 = NULL;
  jlong v10 = 0;
  jboolean v5 = 0;
  jlong v11 = 0;
  jboolean v13 = 0;
  jobject v4 = NULL;
  jobject v16 = NULL;
  jobject v17 = NULL;
  jint v15 = 0;
  jlong v18 = 0;
  jobject v3 = NULL;
  jobject v14 = NULL;
  jobject v8 = NULL;
  jlong v12 = 0;
  jobject v0 = NULL;
  jboolean v6 = 0;
  jobject v2 = NULL;
  jobject v1 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︀", "LI/ᅟ︊︊;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { v17 = (jobject)v0; goto L_1c;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︀︀", "Lbin/nt/editor/widget/CodeEditor;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getText", "()LI/ᅟ︍︆;"), v1, v1, v1, v1);
  v4 = v3;
v7 = (jobject)v4; v8 = (jobject)v1; v9 = (jobject)v0; goto L_a;

L_a:
  v5 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v7, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︄︁", "()Z"), v8, v8, v8, v8);
  v6 = v5;
  /* UNSUPPORTED: if-eqz */
  if (v6 == 0) { goto L_14;
 } else { goto L_10;
 }

L_10:
  v13 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v7, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︋︀", "()Z"), v8, v8, v8, v8);
  /* UNSUPPORTED: goto */
v7 = (jobject)(intptr_t)v10; v8 = (jobject)(intptr_t)v11; v9 = (jobject)(intptr_t)v12; goto L_a;

L_14:
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︁︀", "LI/ᅟ︇︆;"));
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("I/ᅟ︇︆"), "ᅟ︁︀", "()V"), v8, v8, v8, v8);
  v15 = 0;
  env->SetBooleanField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅟ︊︊"), "ᅟ︂︀", "Z"), v15);
v17 = (jobject)(intptr_t)v18; goto L_1c;

L_1c:
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "Landroid/view/inputmethod/InputMethodManager;"));
  /* UNSUPPORTED: if-eqz */
  if (v16 == 0) { goto L_23;
 } else { goto L_20;
 }

L_20:
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("android/view/inputmethod/InputMethodManager"), "restartInput", "(Landroid/view/View;)V"), v17, v16, v16, v16);
goto L_23;

L_23:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︋︃()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0b_0fe03__ */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︌︁()V: java.lang.StackOverflowError */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︌︂(FF)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︌︃()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︍︀(Z)V: java.lang.IllegalStateException: unknown phi type v4_6 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︍︁(Ljava/lang/String;Z)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︍︂()F: java.lang.StackOverflowError */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︍︃(II)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0d_0fe03__II(JNIEnv* env, jobject thiz, jint p0, jint p1) {
  jthrowable pendingException = NULL;
  jboolean v4 = 0;
  jobject v7 = NULL;
  jobject v12 = NULL;
  jint v11 = 0;
  jint v13 = 0;
  jobject v0 = NULL;
  jobject v6 = NULL;
  jint v15 = 0;
  jint v10 = 0;
  jint v14 = 0;
  jobject v17 = NULL;
  jint v1 = 0;
  jint v2 = 0;
  jobject v9 = NULL;
  jobject v8 = NULL;
  jint v16 = 0;
  jobject v5 = NULL;
  jobject v3 = NULL;

L_0:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︅", "LI/ᅟ︆︈;"));
  v4 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ︆︈"), "useICULibToSelectWords", "Z"));
  v5 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getText", "()LI/ᅟ︍︆;"), v4, v4, v4, v4);
  v6 = v5;
  v7 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︁︁", "(LI/ᅟ︍︆;IIZ)LI/ᅠ️︉;"), v6, v1, v2, v4, v4);
  v8 = v7;
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅠ️︉"), "ᅟ︀︀", "LI/ᅟ︂︅;"));
  v10 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I"));
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I"));
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅠ️︉"), "ᅟ︁︀", "LI/ᅟ︂︅;"));
  v13 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I"));
  v14 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I"));
  v15 = 1;
  v16 = 5;
  /* dbg-move v17 v0 dv=Ljava/lang/Object; sv=Lbin/nt/editor/widget/CodeEditor; */
  env->CallVoidMethod((jobject)v17, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︄", "(IIIIIZ)V"), v10, v11, v13, v14, v16, v15);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︍︃(II)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0d_0fe03__II */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ︎︁(II)V: java.lang.IllegalStateException: unknown phi type v0_22 = phi[v0_20, v0_19] */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︎︂()F */
jfloat Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0e_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jfloat v13 = 0;
  jfloat v4 = 0;
  jobject v10 = NULL;
  jint v11 = 0;
  jfloat v9 = 0;
  jfloat v6 = 0;
  jfloat v5 = 0;
  jboolean v1 = 0;
  jfloat v2 = 0;
  jfloat v7 = 0;
  jfloat v16 = 0;
  jfloat v17 = 0;
  jfloat v3 = 0;
  jint v15 = 0;
  jobject v0 = NULL;
  jfloat v12 = 0;
  jfloat v14 = 0;
  jfloat v8 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︋︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_1a;
 } else { goto L_4;
 }

L_4:
  v2 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︍︂", "()F"), v1, v1, v1, v1);
  v3 = v2;
  v4 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︁", "F"));
  /* UNSUPPORTED: add-float-2addr */
  v6 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︁", "F"));
  /* UNSUPPORTED: add-float-2addr */
  v8 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︂︁", "F"));
  /* UNSUPPORTED: add-float-2addr */
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︌︅", "LI/ᅟ︇︋;"));
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("I/ᅟ︇︋"), "ᅟ︍︁", "()V"), v9, v9, v9, v9);
  v11 = 0;
  v12 = (jfloat)v12;
  /* UNSUPPORTED: add-float-2addr */
  /* UNSUPPORTED: goto */
v17 = (jfloat)v13; goto L_20;

L_1a:
  v14 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︁", "F"));
  v15 = 1084227584;
  /* UNSUPPORTED: mul-float */
v17 = (jfloat)v16; goto L_20;

L_20:
  /* return terminator */
  return (jfloat)(intptr_t)v17;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for ᅟ︎︂()F -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0e_0fe02__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ︎︃(FF)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0e_0fe03__FF(JNIEnv* env, jobject thiz, jfloat p0, jfloat p1) {
  jthrowable pendingException = NULL;
  jint v3 = 0;
  jint v5 = 0;
  jobject v6 = NULL;
  jfloat v2 = 0;
  jint v4 = 0;
  jobject v0 = NULL;
  jfloat v1 = 0;
  jobject v7 = NULL;

L_0:
  v3 = 0;
  v4 = (v1 > v3 ? 1 : (v1 < v3 ? -1 : 0));
  /* UNSUPPORTED: if-ltz */
  if (v4 < 0) { goto L_14;
 } else { goto L_5;
 }

L_5:
  v5 = (v2 > v5 ? 1 : (v2 < v5 ? -1 : 0));
  /* UNSUPPORTED: if-ltz */
  if (v5 < 0) { goto L_14;
 } else { goto L_9;
 }

L_9:
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︁", "F"), v1);
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︁", "F"), v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︊︃", "()V"), v5, v5, v5, v5);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v5, v5, v5, v5);
  /* return terminator */
  return;

L_14:
  v6 = env->AllocObject(env->FindClass("java/lang/IllegalArgumentException"));
  v7 = env->NewStringUTF("margin can not be under zero");
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("java/lang/IllegalArgumentException"), "<init>", "(Ljava/lang/String;)V"), v7, v3, v3, v3);
  pendingException = (jthrowable)v6; env->Throw(pendingException);
  goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︎︃(FF)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0e_0fe03__FF */

/* FAILED Lbin/nt/editor/widget/CodeEditor;->ᅟ️︀(LI/ᅟ︍︆;IIIILjava/lang/StringBuilder;)V: java.lang.StackOverflowError */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ️︁()V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v52 = NULL;
  jobject v51 = NULL;
  jint v16 = 0;
  jint v4 = 0;
  jobject v53 = NULL;
  jlong v28 = 0;
  jobject v20 = NULL;
  jobject v1 = NULL;
  jint v10 = 0;
  jint v7 = 0;
  jint v36 = 0;
  jobject v26 = NULL;
  jint v34 = 0;
  jlong v50 = 0;
  jlong v31 = 0;
  jint v6 = 0;
  jint v23 = 0;
  jint v40 = 0;
  jlong v30 = 0;
  jobject v19 = NULL;
  jobject v22 = NULL;
  jlong v43 = 0;
  jlong v49 = 0;
  jint v9 = 0;
  jint v25 = 0;
  jint v33 = 0;
  jobject v21 = NULL;
  jlong v42 = 0;
  jobject v8 = NULL;
  jint v47 = 0;
  jint v39 = 0;
  jobject v15 = NULL;
  jint v13 = 0;
  jlong v45 = 0;
  jobject v14 = NULL;
  jobject v24 = NULL;
  jobject v54 = NULL;
  jint v17 = 0;
  jlong v27 = 0;
  jlong v46 = 0;
  jobject v12 = NULL;
  jlong v32 = 0;
  jint v18 = 0;
  jobject v55 = NULL;
  jint v35 = 0;
  jobject v2 = NULL;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jint v5 = 0;
  jlong v29 = 0;
  jobject v37 = NULL;
  jlong v41 = 0;
  jlong v44 = 0;
  jobject v38 = NULL;
  jobject v11 = NULL;
  jobject v48 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︀", "LI/ᅟ︂︅;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { v55 = (jobject)v0; goto L_52;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︄︄", "LI/ᅟ︍︆;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v1, v1, v1, v1);
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I"));
  v5 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I"));
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I"));
  v7 = 0;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︆︁", "(Z)V"), v7, v6, v6, v6);
  /* UNSUPPORTED: if-ltz */
  if (v4 < 0) { v37 = (jobject)v0; v38 = (jobject)v2; v39 = (jint)v6; v40 = (jint)v7; goto L_48;
 } else { goto L_15;
 }

L_15:
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︍︆"), "ᅟ︄︀", "Ljava/util/ArrayList;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v9 = (jint)(intptr_t)env->CallIntMethod((jobject)v8, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v10 = v9;
  /* UNSUPPORTED: if-lt */
  if (v4 < v10) { goto L_1e;
 } else { goto L_1d;
 }

L_1d:
  /* UNSUPPORTED: goto */
v37 = (jobject)(intptr_t)v41; v38 = (jobject)(intptr_t)v30; v39 = (jint)(intptr_t)v44; v40 = (jint)(intptr_t)v27; goto L_48;

L_1e:
  v11 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ️︀", "(I)LI/ᅟ︁︇;"), v4, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v12 = v11;
  v13 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅟ︁︇"), "ᅟ︆︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v14 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("I/ᅟ︁︇"), "ᅟ︃︀", "()LI/ᅠ︉︁;"), v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v15 = v14;
  v16 = (jint)(intptr_t)env->CallIntMethod((jobject)v15, env->GetMethodID(env->FindClass("I/ᅠ︉︁"), "ᅟ︁︀", "()I"), v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v17 = v16;
  /* UNSUPPORTED: add-int-2addr */
  /* UNSUPPORTED: if-gt */
  if (v5 > v18) { v37 = (jobject)(intptr_t)v42; v38 = (jobject)(intptr_t)v31; v39 = (jint)(intptr_t)v45; v40 = (jint)(intptr_t)v28; goto L_48;
 } else { goto L_2f;
 }

L_2f:
  /* UNSUPPORTED: if-gez */
  if (v5 >= 0) { goto L_32;
 } else { goto L_31;
 }

L_31:
  /* UNSUPPORTED: goto */
v37 = (jobject)(intptr_t)v43; v38 = (jobject)(intptr_t)v32; v39 = (jint)(intptr_t)v46; v40 = (jint)(intptr_t)v29; goto L_48;

L_32:
  v19 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︎︀", "()LI/ᅟ️︄;"), v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v20 = v19;
  v21 = (jobject)env->CallObjectMethod((jobject)v20, env->GetMethodID(env->FindClass("I/ᅟ️︄"), "ᅟ︈︁", "(II)LI/ᅟ︂︅;"), v4, v5, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
  v22 = v21;
  v23 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v23, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "I")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_2; }
goto L_3c;

L_46:
  v24 = pendingException;
  /* UNSUPPORTED: goto */
goto L_4c;

L_4c:
  env->CallVoidMethod((jobject)v26, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︁︂", "(Z)V"), v25, v24, v24, v24);
  pendingException = (jthrowable)v24; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_3c:
  /* UNSUPPORTED: if-ne */
  if (v23 != v6) { goto L_40;
 } else { goto L_3e;
 }

L_3e:
  v33 = 1;
  /* UNSUPPORTED: goto */
v36 = (jint)v33; goto L_41;

L_40:
  v34 = 0;
v36 = (jint)v34; goto L_41;

L_41:
  env->CallVoidMethod((jobject)v31, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︁︂", "(Z)V"), v28, v36, v36, v36);
  /* dbg-move v35 v36 dv=I sv=I */
  /* UNSUPPORTED: goto */
v47 = (jint)(intptr_t)v49; v48 = (jobject)(intptr_t)v50; goto L_50;

L_48:
  env->CallVoidMethod((jobject)v38, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "ᅟ︁︂", "(Z)V"), v40, v39, v39, v39);
  /* UNSUPPORTED: goto */
v47 = (jint)v40; v48 = (jobject)v37; goto L_50;

L_50:
  /* UNSUPPORTED: if-nez */
  if (v47 != 0) { goto L_5c;
 } else { v55 = (jobject)v48; goto L_52;
 }

L_52:
  v51 = (jobject)env->GetObjectField((jobject)(intptr_t)v55, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︃︄", "LI/ᅟ︅︇;"));
  v52 = (jobject)env->GetObjectField((jobject)(intptr_t)v52, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︃︀", "LI/ᅟ︂︅;"));
  v53 = (jobject)env->CallObjectMethod((jobject)v52, env->GetMethodID(env->FindClass("I/ᅟ︂︅"), "ᅟ︀︀", "()LI/ᅟ︂︅;"), v52, v52, v52, v52);
  v54 = (jobject)(intptr_t)v53;
  env->SetObjectField((jobject)(intptr_t)v55, env->GetFieldID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︈︀", "LI/ᅟ︂︅;"), (jobject)(intptr_t)v54);
goto L_5c;

L_5c:
  /* return terminator */
  return;

EX_LandingPad_2:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_46;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ️︁()V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe01__ */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ️︂(LI/ᅠ︎︆;Z)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe02__LI__01160_0fe0e_0fe06_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jboolean v2 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;

L_0:
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_6;
 } else { goto L_2;
 }

L_2:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︁︂", "(LI/ᅠ︎︆;)V"), v1, v0, v0, v0);
  /* UNSUPPORTED: goto */
goto L_9;

L_6:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︃", "(LI/ᅠ︎︆;)V"), v1, v0, v0, v0);
goto L_9;

L_9:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ️︂(LI/ᅠ︎︆;Z)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe02__LI__01160_0fe0e_0fe06_2Z */

/* Lbin/nt/editor/widget/CodeEditor;->ᅟ️︃(II)V */
void Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe03__II(JNIEnv* env, jobject thiz, jint p0, jint p1) {
  jthrowable pendingException = NULL;
  jint v2 = 0;
  jint v1 = 0;
  jint v3 = 0;
  jobject v0 = NULL;
  jint v4 = 0;

L_0:
  v3 = 1;
  v4 = 0;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︀︄", "(IIIZ)V"), v1, v2, v4, v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ️︃(II)V -> Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe03__II */

/* Lbin/nt/ui/HackyViewPager;-><init>(Landroid/content/Context;Landroid/util/AttributeSet;)V */
void Java_bin_nt_ui_HackyViewPager__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/viewpager/widget/ViewPager"), "<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;)V"), v1, v2, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Landroid/content/Context;Landroid/util/AttributeSet;)V -> Java_bin_nt_ui_HackyViewPager__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2 */

/* Lbin/nt/ui/HackyViewPager;->onInterceptTouchEvent(Landroid/view/MotionEvent;)Z */
jboolean Java_bin_nt_ui_HackyViewPager_onInterceptTouchEvent__Landroid_view_MotionEvent_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jboolean v2 = 0;
  jobject v0 = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jboolean v3 = 0;

L_0:
  v2 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/viewpager/widget/ViewPager"), "onInterceptTouchEvent", "(Landroid/view/MotionEvent;)Z"), v1, v0, v0, v0); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_0; }
  v3 = v2;
goto L_4;

L_5:
  v4 = 0;
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_4:
  /* return terminator */
  return (jboolean)(intptr_t)v3;

EX_LandingPad_0:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_5;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for onInterceptTouchEvent(Landroid/view/MotionEvent;)Z -> Java_bin_nt_ui_HackyViewPager_onInterceptTouchEvent__Landroid_view_MotionEvent_2 */

/* Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;-><init>(Landroid/content/Context;Landroid/util/AttributeSet;)V */
void Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v20 = NULL;
  jboolean v29 = 0;
  jobject v39 = NULL;
  jfloat v53 = 0;
  jobject v19 = NULL;
  jint v55 = 0;
  jint v35 = 0;
  jint v7 = 0;
  jobject v9 = NULL;
  jobject v11 = NULL;
  jint v8 = 0;
  jint v48 = 0;
  jobject v64 = NULL;
  jint v6 = 0;
  jint v34 = 0;
  jfloat v26 = 0;
  jobject v32 = NULL;
  jint v33 = 0;
  jfloat v60 = 0;
  jfloat v17 = 0;
  jobject v18 = NULL;
  jobject v46 = NULL;
  jobject v65 = NULL;
  jobject v13 = NULL;
  jfloat v40 = 0;
  jobject v12 = NULL;
  jint v28 = 0;
  jobject v47 = NULL;
  jobject v0 = NULL;
  jfloat v56 = 0;
  jarray v45 = NULL;
  jfloat v54 = 0;
  jobject v63 = NULL;
  jobject v1 = NULL;
  jobject v44 = NULL;
  jobject v27 = NULL;
  jfloat v51 = 0;
  jobject v30 = NULL;
  jboolean v5 = 0;
  jobject v37 = NULL;
  jint v50 = 0;
  jfloat v52 = 0;
  jfloat v57 = 0;
  jboolean v4 = 0;
  jobject v10 = NULL;
  jobject v23 = NULL;
  jfloat v41 = 0;
  jobject v21 = NULL;
  jfloat v16 = 0;
  jfloat v25 = 0;
  jint v3 = 0;
  jobject v42 = NULL;
  jobject v38 = NULL;
  jobject v14 = NULL;
  jint v59 = 0;
  jfloat v61 = 0;
  jobject v62 = NULL;
  jobject v2 = NULL;
  jint v15 = 0;
  jint v49 = 0;
  jint v24 = 0;
  jobject v36 = NULL;
  jfloat v58 = 0;
  jobject v31 = NULL;
  jobject v22 = NULL;
  jobject v43 = NULL;

L_0:
  v3 = 0;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/widget/FrameLayout"), "<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V"), v1, v2, v3, v3);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︊︀", "I"), v3);
  v4 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "isInEditMode", "()Z"), v3, v3, v3, v3);
  v5 = v4;
  v6 = 1;
  /* UNSUPPORTED: if-eqz */
  if (v5 == 0) { goto L_e;
 } else { goto L_d;
 }

L_d:
  /* UNSUPPORTED: goto */
goto L_48;

L_e:
  v7 = (jint)(intptr_t)env->CallIntMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "getChildCount", "()I"), v3, v3, v3, v3);
  v8 = v7;
  /* UNSUPPORTED: if-gt */
  if (v8 > v6) { goto L_c5;
 } else { goto L_14;
 }

L_14:
  v9 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v10 = v9;
  v11 = (jobject)env->CallObjectMethod((jobject)v10, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v12 = v11;
  v13 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v14 = v13;
  v15 = 1125515264;
  v16 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v6, v15, v14, v3, v3);
  v17 = v16;
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︇︀", "F"), v17);
  v18 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v19 = v18;
  v20 = (jobject)env->CallObjectMethod((jobject)v19, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v21 = v20;
  v22 = (jobject)env->CallObjectMethod((jobject)v21, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v23 = v22;
  v24 = 1113587712;
  v25 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("android/util/TypedValue"), env->GetStaticMethodID(env->FindClass("android/util/TypedValue"), "applyDimension", "(IFLandroid/util/DisplayMetrics;)F"), v6, v24, v23, v3, v3);
  v26 = v25;
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︈︀", "F"), v26);
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︉︀", "F"), v26);
  v27 = env->AllocObject(env->FindClass("I/ᅟ︄︄"));
  v28 = 14;
  env->CallVoidMethod((jobject)v27, env->GetMethodID(env->FindClass("I/ᅟ︄︄"), "<init>", "(ILjava/lang/Object;)V"), v28, v0, v3, v3);
  v29 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "post", "(Ljava/lang/Runnable;)Z"), v27, v3, v3, v3);
goto L_48;

L_48:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ︁︁", "Z"), v6);
  v30 = env->AllocObject(env->FindClass("I/ᅠ︊︀"));
  v31 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v32 = v31;
  v33 = 0;
  env->CallVoidMethod((jobject)v30, env->GetMethodID(env->FindClass("android/widget/FrameLayout"), "<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V"), v32, v33, v3, v3);
  v34 = -7829368;
  env->SetIntField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︆︀", "I"), v34);
  v35 = 0;
  env->SetFloatField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︊︀", "F"), v35);
  env->SetFloatField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︋︀", "F"), v35);
  env->CallVoidMethod((jobject)v30, env->GetMethodID(env->FindClass("android/view/View"), "setWillNotDraw", "(Z)V"), v3, v3, v3, v3);
  v36 = env->AllocObject(env->FindClass("android/graphics/Paint"));
  env->CallVoidMethod((jobject)v36, env->GetMethodID(env->FindClass("android/graphics/Paint"), "<init>", "(I)V"), v6, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︄︀", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v36);
  v37 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Paint$Style"), env->GetStaticFieldID(env->FindClass("android/graphics/Paint$Style"), "FILL", "Landroid/graphics/Paint$Style;"));
  env->CallVoidMethod((jobject)v36, env->GetMethodID(env->FindClass("android/graphics/Paint"), "setStyle", "(Landroid/graphics/Paint$Style;)V"), v37, v3, v3, v3);
  v38 = env->AllocObject(env->FindClass("android/graphics/Path"));
  env->CallVoidMethod((jobject)v38, env->GetMethodID(env->FindClass("android/graphics/Path"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︅︀", "Landroid/graphics/Path;"), (jobject)(intptr_t)v38);
  v39 = env->AllocObject(env->FindClass("I/ᅠ︉︀"));
  env->CallVoidMethod((jobject)v39, env->GetMethodID(env->FindClass("I/ᅠ︉︀"), "<init>", "(LI/ᅠ︊︀;)V"), v30, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︇︀", "LI/ᅠ︉︀;"), (jobject)(intptr_t)v39);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"), (jobject)(intptr_t)v30);
  v40 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getElevation", "()F"), v3, v3, v3, v3);
  v41 = v40;
  env->CallVoidMethod((jobject)v30, env->GetMethodID(env->FindClass("android/view/View"), "setElevation", "(F)V"), v41, v3, v3, v3);
  v42 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅠ︃︅"), "setHeaderView", "(Landroid/view/View;)V"), v42, v3, v3, v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("I/ᅠ︃︅"), "setPullingListener", "(LI/ᅠ︂︅;)V"), v0, v3, v3, v3);
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_8f;
 } else { goto L_8e;
 }

L_8e:
  /* UNSUPPORTED: goto */
goto L_bf;

L_8f:
  v43 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v44 = v43;
  v45 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅠ︄︅"), env->GetStaticFieldID(env->FindClass("I/ᅠ︄︅"), "ᅟ︁︀", "[I"));
  v46 = (jobject)env->CallObjectMethod((jobject)v44, env->GetMethodID(env->FindClass("android/content/Context"), "obtainStyledAttributes", "(Landroid/util/AttributeSet;[I)Landroid/content/res/TypedArray;"), v2, v45, v3, v3);
  v47 = v46;
  v48 = -1;
goto L_9a;

L_9a:
  v49 = (jint)(intptr_t)env->CallIntMethod((jobject)v47, env->GetMethodID(env->FindClass("android/content/res/TypedArray"), "getColor", "(II)I"), v6, v48, v3, v3); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v50 = v49;
  v51 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︈︀", "F")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v52 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v47, env->GetMethodID(env->FindClass("android/content/res/TypedArray"), "getDimension", "(IF)F"), v3, v51, v3, v3); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v53 = v52;
  v54 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︇︀", "F")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v55 = 2;
  v56 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v47, env->GetMethodID(env->FindClass("android/content/res/TypedArray"), "getDimension", "(IF)F"), v55, v54, v53, v53); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v57 = v56;
  v58 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︉︀", "F")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v59 = 3;
  v60 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v47, env->GetMethodID(env->FindClass("android/content/res/TypedArray"), "getDimension", "(IF)F"), v59, v58, v53, v53); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  v61 = v60;
  v62 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  env->SetIntField((jobject)(intptr_t)v62, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︆︀", "I"), v50); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︈︀", "F"), v53); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︇︀", "F"), v57); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︉︀", "F"), v61); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
goto L_bc;

L_c0:
  v63 = pendingException;
  env->CallVoidMethod((jobject)v47, env->GetMethodID(env->FindClass("android/content/res/TypedArray"), "recycle", "()V"), v53, v53, v53, v53);
  pendingException = (jthrowable)v63; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_bc:
  env->CallVoidMethod((jobject)v47, env->GetMethodID(env->FindClass("android/content/res/TypedArray"), "recycle", "()V"), v53, v53, v53, v53);
goto L_bf;

L_bf:
  /* return terminator */
  return;

L_c5:
  v64 = env->AllocObject(env->FindClass("java/lang/RuntimeException"));
  v65 = env->NewStringUTF("You can only attach one child");
  env->CallVoidMethod((jobject)v64, env->GetMethodID(env->FindClass("java/lang/RuntimeException"), "<init>", "(Ljava/lang/String;)V"), v65, v3, v3, v3);
  pendingException = (jthrowable)v64; env->Throw(pendingException);
  goto EX_UnwindBlock;

EX_LandingPad_7:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_c0;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Landroid/content/Context;Landroid/util/AttributeSet;)V -> Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2 */

/* Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->setJellyColor(I)V */
void Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setJellyColor__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v1 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"));
  env->SetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︆︀", "I"), v1);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v2, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setJellyColor(I)V -> Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setJellyColor__I */

/* Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->setLoadingView(Landroid/view/View;)V */
void Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setLoadingView__Landroid_view_View_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jint v6 = 0;
  jint v4 = 0;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jint v3 = 0;
  jobject v0 = NULL;

L_0:
  v2 = env->AllocObject(env->FindClass("android/widget/FrameLayout$LayoutParams"));
  v3 = -2;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/FrameLayout$LayoutParams"), "<init>", "(II)V"), v3, v3, v2, v2);
  v4 = 49;
  env->SetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("android/widget/FrameLayout$LayoutParams"), "gravity", "I"), v4);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"));
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/view/ViewGroup"), "addView", "(Landroid/view/View;Landroid/view/ViewGroup$LayoutParams;)V"), v1, v2, v2, v2);
  v6 = 4;
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v6, v6, v6, v6);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ︀︁", "Landroid/view/View;"), (jobject)(intptr_t)v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLoadingView(Landroid/view/View;)V -> Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setLoadingView__Landroid_view_View_2 */

/* FAILED Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->setRefreshing(Z)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->setSweepDirection(Z)V */
void Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setSweepDirection__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jint v3 = 0;
  jobject v0 = NULL;
  jboolean v1 = 0;
  jobject v2 = NULL;
  jobject v4 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ︁︁", "Z"), v1);
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"));
  v3 = 1;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︉︀", "Z"), v3);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v3, v3, v3, v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v3, v3, v3, v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setSweepDirection(Z)V -> Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setSweepDirection__Z */

/* FAILED Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->ᅟ︂︀(F)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->ᅟ︃︀(LI/ᅠ︊︀;F)V */
void Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0115f_0fe03_0fe00__LI__01160_0fe0a_0fe00_2F(JNIEnv* env, jobject thiz, jobject p0, jfloat p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jfloat v9 = 0;
  jobject v1 = NULL;
  jfloat v4 = 0;
  jfloat v7 = 0;
  jfloat v12 = 0;
  jfloat v8 = 0;
  jfloat v3 = 0;
  jfloat v11 = 0;
  jfloat v10 = 0;
  jfloat v6 = 0;
  jint v5 = 0;
  jfloat v13 = 0;
  jfloat v2 = 0;

L_0:
  v3 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︉︀", "F"));
  /* UNSUPPORTED: div-float-2addr */
  v5 = 1065353216;
  v6 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︃︀", "(FF)F"), v5, v4, v5, v5, v5);
  v7 = v6;
  /* UNSUPPORTED: mul-float */
  /* UNSUPPORTED: sub-float-2addr */
  v10 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︊︀", "F"));
  /* UNSUPPORTED: mul-float */
  env->SetFloatField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︊︀", "F"), v11);
  v12 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︋︀", "F"));
  /* UNSUPPORTED: mul-float */
  env->SetFloatField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅠ︊︀"), "ᅟ︋︀", "F"), v13);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︀(LI/ᅠ︊︀;F)V -> Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0115f_0fe03_0fe00__LI__01160_0fe0a_0fe00_2F */

/* Lbin/nt/ui/jellyrefresh/JellyRefreshLayout;->ᅟ︄︀(F)F */
jfloat Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0115f_0fe04_0fe00__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jfloat v2 = 0;
  jint v8 = 0;
  jint v12 = 0;
  jint v10 = 0;
  jfloat v1 = 0;
  jint v9 = 0;
  jfloat v5 = 0;
  jfloat v13 = 0;
  jfloat v15 = 0;
  jfloat v3 = 0;
  jint v4 = 0;
  jboolean v14 = 0;
  jobject v7 = NULL;
  jfloat v18 = 0;
  jobject v0 = NULL;
  jfloat v16 = 0;
  jint v11 = 0;
  jfloat v6 = 0;
  jfloat v17 = 0;

L_0:
  v2 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︃︅"), "ᅟ︉︀", "F"));
  /* UNSUPPORTED: div-float-2addr */
  v4 = 1065353216;
  v5 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︃︀", "(FF)F"), v4, v3, v4, v4, v4);
  v6 = v5;
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ️︀", "LI/ᅠ︊︀;"));
  v8 = (jint)(intptr_t)env->CallIntMethod((jobject)v7, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v4, v4, v4, v4);
  v9 = v8;
  v10 = 1;
  v11 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v9, v10, v4, v4, v4);
  v12 = v11;
  v13 = (jfloat)v13;
  v14 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout"), "ᅟ︁︁", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v14 == 0) { goto L_1c;
 } else { goto L_19;
 }

L_19:
  /* UNSUPPORTED: mul-float */
  /* UNSUPPORTED: goto */
v18 = (jfloat)v15; goto L_1f;

L_1c:
  /* UNSUPPORTED: sub-float-2addr */
  /* UNSUPPORTED: mul-float */
v18 = (jfloat)v17; goto L_1f;

L_1f:
  /* return terminator */
  return (jfloat)(intptr_t)v18;
EX_Return: return (jfloat)0;
EX_UnwindBlock: return (jfloat)0;
}

/* RegisterNatives entry for ᅟ︄︀(F)F -> Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0115f_0fe04_0fe00__F */

/* LI/ᅟ︊︀;-><init>(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︍︆;)V */
void Java_I__0115f_0fe0a_0fe00__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe0d_0fe06_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("java/lang/Object"), "<init>", "()V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︀"), "ᅟ︄︀", "Lbin/nt/editor/widget/CodeEditor;"), (jobject)(intptr_t)v1);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅟ︊︀"), "ᅟ︅︀", "LI/ᅟ︍︆;"), (jobject)(intptr_t)v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︍︆;)V -> Java_I__0115f_0fe0a_0fe00__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe0d_0fe06_2 */

/* LI/ᅠ︂︄;-><init>(Lbin/nt/main/PhotoViewerActivity;)V */
void Java_I__01160_0fe02_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;

L_0:
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("I/ᅠ︂︄"), "ᅟ︀︀", "Lbin/nt/main/PhotoViewerActivity;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/viewpager/widget/ViewPager$SimpleOnPageChangeListener"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Lbin/nt/main/PhotoViewerActivity;)V -> Java_I__01160_0fe02_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2 */

/* FAILED LI/ᅠ︇︁;-><init>(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︍︆;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED LI/ᅠ︇︌;-><init>(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︍︆;ZZLI/ᅠ︇︌;Z)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;-><init>()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︇︅(Ljava/lang/String;)Ljava/io/File; */
jobject Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe07_0fe05__Ljava_lang_String_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v32 = NULL;
  jobject v21 = NULL;
  jint v38 = 0;
  jobject v16 = NULL;
  jboolean v18 = 0;
  jobject v33 = NULL;
  jlong v44 = 0;
  jobject v53 = NULL;
  jobject v22 = NULL;
  jint v56 = 0;
  jobject v49 = NULL;
  jint v45 = 0;
  jint v34 = 0;
  jint v36 = 0;
  jlong v51 = 0;
  jobject v55 = NULL;
  jobject v23 = NULL;
  jobject v2 = NULL;
  jobject v46 = NULL;
  jobject v20 = NULL;
  jobject v52 = NULL;
  jobject v3 = NULL;
  jobject v12 = NULL;
  jobject v14 = NULL;
  jobject v25 = NULL;
  jlong v42 = 0;
  jobject v4 = NULL;
  jobject v40 = NULL;
  jobject v27 = NULL;
  jobject v19 = NULL;
  jlong v43 = 0;
  jobject v9 = NULL;
  jlong v54 = 0;
  jlong v57 = 0;
  jobject v1 = NULL;
  jobject v10 = NULL;
  jobject v28 = NULL;
  jlong v30 = 0;
  jobject v24 = NULL;
  jobject v47 = NULL;
  jobject v48 = NULL;
  jobject v0 = NULL;
  jobject v50 = NULL;
  jobject v29 = NULL;
  jobject v5 = NULL;
  jobject v13 = NULL;
  jarray v35 = NULL;
  jobject v6 = NULL;
  jobject v7 = NULL;
  jint v37 = 0;
  jobject v26 = NULL;
  jboolean v17 = 0;
  jarray v39 = NULL;
  jobject v15 = NULL;
  jobject v8 = NULL;
  jobject v11 = NULL;
  jlong v31 = 0;
  jobject v41 = NULL;

L_0:
  v1 = env->AllocObject(env->FindClass("java/io/File"));
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/lang/String;)V"), v0, v1, v1, v1);
  v2 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("java/io/File"), "getParentFile", "()Ljava/io/File;"), v1, v1, v1, v1);
  v3 = (jobject)(intptr_t)v2;
  v4 = env->NewStringUTF("");
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_12;
 } else { goto L_d;
 }

L_d:
  v5 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/io/File"), "getName", "()Ljava/lang/String;"), v1, v1, v1, v1);
  v6 = v5;
  /* UNSUPPORTED: goto */
v19 = (jobject)v6; goto L_13;

L_12:
  /* dbg-move v7 v4 dv=Ljava/lang/Object; sv=Ljava/lang/String; */
v19 = (jobject)v7; goto L_13;

L_13:
  v8 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  v9 = env->NewStringUTF("task:");
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "(Ljava/lang/String;)V"), v9, v1, v1, v1);
  v10 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v0, v1, v1, v1);
  v11 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v1, v1, v1, v1);
  v12 = v11;
  v13 = (jobject)env->CallStaticObjectMethod(env->FindClass("bin/nt/main/App"), env->GetStaticMethodID(env->FindClass("bin/nt/main/App"), "ᅟ︅︀", "(Ljava/lang/String;)Ljava/io/File;"), v12, v1, v1, v1, v1);
  v14 = v13;
  v15 = env->AllocObject(env->FindClass("java/io/File"));
  v16 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "()V"), v1, v1, v1, v1);
  v17 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v19, env->GetMethodID(env->FindClass("java/lang/String"), "isEmpty", "()Z"), v1, v1, v1, v1);
  v18 = v17;
  /* UNSUPPORTED: if-eqz */
  if (v18 == 0) { goto L_33;
 } else { goto L_32;
 }

L_32:
  /* UNSUPPORTED: goto */
v29 = (jobject)(intptr_t)v30; goto L_39;

L_33:
  v20 = env->NewStringUTF("_");
  v21 = (jobject)env->CallObjectMethod((jobject)v19, env->GetMethodID(env->FindClass("java/lang/String"), "concat", "(Ljava/lang/String;)Ljava/lang/String;"), v20, v1, v1, v1);
  v22 = v21;
v29 = (jobject)v22; goto L_39;

L_39:
  v23 = (jobject)env->CallObjectMethod((jobject)v16, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v29, v31, v31, v31);
  v24 = (jobject)env->CallObjectMethod((jobject)v31, env->GetMethodID(env->FindClass("java/io/File"), "getName", "()Ljava/lang/String;"), v31, v31, v31, v31);
  v25 = (jobject)(intptr_t)v24;
  v26 = (jobject)env->CallObjectMethod((jobject)v16, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v25, v31, v31, v31);
  v27 = (jobject)env->CallObjectMethod((jobject)v16, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v31, v31, v31, v31);
  v28 = v27;
  env->CallVoidMethod((jobject)v15, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/io/File;Ljava/lang/String;)V"), v14, v28, v31, v31);
goto L_4a;

L_4a:
  v32 = env->AllocObject(env->FindClass("java/io/FileInputStream")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  env->CallVoidMethod((jobject)v32, env->GetMethodID(env->FindClass("java/io/FileInputStream"), "<init>", "(Ljava/io/File;)V"), v31, v31, v31, v31); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
goto L_4f;

L_4f:
  v33 = env->AllocObject(env->FindClass("java/io/FileOutputStream")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_8; }
  env->CallVoidMethod((jobject)v33, env->GetMethodID(env->FindClass("java/io/FileOutputStream"), "<init>", "(Ljava/io/File;)V"), v15, v33, v33, v33); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_8; }
goto L_54;

L_54:
  v34 = 32768;
goto L_57;

L_57:
  v35 = env->NewByteArray((jsize)(intptr_t)v35); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_10; }
v39 = (jarray)v35; v40 = (jobject)v33; v41 = (jobject)v32; goto L_59;

L_59:
  v36 = (jint)(intptr_t)env->CallIntMethod((jobject)v41, env->GetMethodID(env->FindClass("java/io/InputStream"), "read", "([B)I"), v39, v40, v40, v40); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_10; }
  v37 = v36;
  v38 = -1;
  /* UNSUPPORTED: if-eq */
  if (v37 == v38) { goto L_67;
 } else { goto L_60;
 }

L_60:
  v45 = 0;
  env->CallVoidMethod((jobject)v40, env->GetMethodID(env->FindClass("java/io/FileOutputStream"), "write", "([BII)V"), v39, v45, v37, v40); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_10; }
goto L_64;

L_65:
  v46 = pendingException;
  /* UNSUPPORTED: goto */
goto L_70;

L_70:
  env->CallVoidMethod((jobject)v48, env->GetMethodID(env->FindClass("java/io/FileOutputStream"), "close", "()V"), v48, v48, v48, v48); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_14; }
goto L_73;

L_74:
  v49 = pendingException;
goto L_75;

L_75:
  env->CallVoidMethod((jobject)v46, env->GetMethodID(env->FindClass("java/lang/Throwable"), "addSuppressed", "(Ljava/lang/Throwable;)V"), v49, v49, v49, v49); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_16; }
v50 = (jobject)(intptr_t)v51; goto L_78;

L_73:
  /* UNSUPPORTED: goto */
v50 = (jobject)v47; goto L_78;

L_78:
  pendingException = (jthrowable)v46; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_64:
  /* UNSUPPORTED: goto */
v39 = (jarray)(intptr_t)v42; v40 = (jobject)(intptr_t)v43; v41 = (jobject)(intptr_t)v44; goto L_59;

L_67:
  env->CallVoidMethod((jobject)v40, env->GetMethodID(env->FindClass("java/io/FileOutputStream"), "close", "()V"), v40, v40, v40, v40); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_20; }
goto L_6a;

L_6e:
  v52 = pendingException;
  /* UNSUPPORTED: goto */
goto L_79;

L_79:
  env->CallVoidMethod((jobject)v53, env->GetMethodID(env->FindClass("java/io/InputStream"), "close", "()V"), v52, v52, v52, v52); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_22; }
goto L_7c;

L_7d:
  v55 = pendingException;
goto L_7e;

L_7e:
  env->CallVoidMethod((jobject)v52, env->GetMethodID(env->FindClass("java/lang/Throwable"), "addSuppressed", "(Ljava/lang/Throwable;)V"), v55, v52, v52, v52); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_24; }
goto L_81;

L_7c:
  /* UNSUPPORTED: goto */
goto L_81;

L_81:
  pendingException = (jthrowable)v52; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_6a:
  env->CallVoidMethod((jobject)v41, env->GetMethodID(env->FindClass("java/io/InputStream"), "close", "()V"), v40, v40, v40, v40); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_27; }
goto L_6d;

L_82:
  v56 = 0;
  /* return terminator */
  return (jobject)(intptr_t)v56;

L_6d:
  /* return terminator */
  return (jobject)(intptr_t)v57;

EX_LandingPad_7:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/io/IOException"))) goto L_82;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_8:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_6e;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_10:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_65;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_20:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_6e;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_27:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/io/IOException"))) goto L_82;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_14:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_74;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_16:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_6e;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_22:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Throwable"))) goto L_7d;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_24:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/io/IOException"))) goto L_82;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︇︅(Ljava/lang/String;)Ljava/io/File; -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe07_0fe05__Ljava_lang_String_2 */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︉︄(LI/ᅟ︎︎;)Ljava/io/InputStream; */
jobject Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe09_0fe04__LI__0115f_0fe0e_0fe0e_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v7 = 0;
  jobject v26 = NULL;
  jobject v28 = NULL;
  jobject v17 = NULL;
  jobject v8 = NULL;
  jobject v19 = NULL;
  jobject v1 = NULL;
  jobject v24 = NULL;
  jobject v16 = NULL;
  jobject v5 = NULL;
  jobject v4 = NULL;
  jobject v23 = NULL;
  jobject v6 = NULL;
  jobject v15 = NULL;
  jobject v25 = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jboolean v12 = 0;
  jobject v20 = NULL;
  jobject v18 = NULL;
  jobject v21 = NULL;
  jobject v11 = NULL;
  jboolean v13 = 0;
  jobject v27 = NULL;
  jobject v3 = NULL;
  jobject v22 = NULL;
  jobject v10 = NULL;
  jobject v14 = NULL;
  jint v9 = 0;

L_0:
  v1 = env->AllocObject(env->FindClass("java/io/File"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︁︀", "Ljava/lang/String;"));
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/lang/String;)V"), v2, v1, v1, v1);
  v3 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︂️"), env->GetStaticMethodID(env->FindClass("I/ᅟ︂️"), "ᅟ︂︀", "(Ljava/io/File;)LI/ᅟ️︁;"), v1, v1, v1, v1, v1);
  v4 = v3;
  /* UNSUPPORTED: if-eqz */
  if (v4 == 0) { goto L_3f;
 } else { goto L_d;
 }

L_d:
  v5 = env->AllocObject(env->FindClass("java/util/zip/ZipFile"));
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/io/File"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/zip/ZipFile"), "<init>", "(Ljava/io/File;)V"), v7, v4, v4, v4);
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/String"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v10 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/zip/ZipFile"), "getEntry", "(Ljava/lang/String;)Ljava/util/zip/ZipEntry;"), v9, v9, v9, v9);
  v11 = v10;
  /* UNSUPPORTED: if-eqz */
  if (v11 == 0) { goto L_30;
 } else { goto L_20;
 }

L_20:
  v12 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v11, env->GetMethodID(env->FindClass("java/util/zip/ZipEntry"), "isDirectory", "()Z"), v9, v9, v9, v9);
  v13 = v12;
  /* UNSUPPORTED: if-nez */
  if (v13 != 0) { goto L_30;
 } else { goto L_26;
 }

L_26:
  v14 = env->AllocObject(env->FindClass("I/ᅠ︂︆"));
  v15 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/zip/ZipFile"), "getInputStream", "(Ljava/util/zip/ZipEntry;)Ljava/io/InputStream;"), v11, v14, v14, v14);
  v16 = v15;
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("I/ᅠ︂︆"), "<init>", "(Ljava/io/InputStream;Ljava/util/zip/ZipFile;)V"), v16, v5, v14, v14);
  /* return terminator */
  return (jobject)(intptr_t)v14;

L_30:
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("java/util/zip/ZipFile"), "close", "()V"), v9, v9, v9, v9);
  v17 = env->AllocObject(env->FindClass("java/io/IOException"));
  v18 = env->NewStringUTF("Entry not found in archive: ");
  v19 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︍︀"), env->GetStaticMethodID(env->FindClass("I/ᅟ︍︀"), "ᅟ︅︁", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"), v18, v9, v9, v9, v9);
  v20 = (jobject)(intptr_t)v19;
  env->CallVoidMethod((jobject)v17, env->GetMethodID(env->FindClass("java/io/IOException"), "<init>", "(Ljava/lang/String;)V"), v20, v20, v20, v20);
  pendingException = (jthrowable)v17; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_3f:
  v21 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︀️"), env->GetStaticMethodID(env->FindClass("I/ᅟ︀️"), "ᅟ︁︀", "(Ljava/lang/String;)LI/ᅟ️︎;"), v2, v4, v4, v4, v4); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_5; }
  v22 = v21;
  v23 = (jobject)env->CallObjectMethod((jobject)v22, env->GetMethodID(env->FindClass("I/ᅟ️︎"), "ᅟ︀︀", "(Ljava/lang/String;)Ljava/io/InputStream;"), v2, v22, v22, v22); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_5; }
  v24 = v23;
goto L_47;

L_48:
  v25 = pendingException;
  v26 = env->AllocObject(env->FindClass("java/io/IOException"));
  v27 = (jobject)env->CallObjectMethod((jobject)v25, env->GetMethodID(env->FindClass("java/lang/Throwable"), "getMessage", "()Ljava/lang/String;"), v26, v26, v26, v26);
  v28 = v27;
  env->CallVoidMethod((jobject)v26, env->GetMethodID(env->FindClass("java/io/IOException"), "<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V"), v28, v25, v26, v26);
  pendingException = (jthrowable)v26; env->Throw(pendingException);
  goto EX_UnwindBlock;

L_47:
  /* return terminator */
  return (jobject)(intptr_t)v24;

EX_LandingPad_5:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("I/ᅟ︄️"))) goto L_48;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︉︄(LI/ᅟ︎︎;)Ljava/io/InputStream; -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe09_0fe04__LI__0115f_0fe0e_0fe0e_2 */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︊︃(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Ljava/lang/String;Ljava/lang/String;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︎︃(Ljava/io/File;)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︎︄(Ljava/io/File;Ljava/lang/String;)Ljava/lang/String;: java.lang.IllegalStateException: unknown phi type vResult_3 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ️︄(Landroid/content/SharedPreferences;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String; */
jobject Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0f_0fe04__Landroid_content_SharedPreferences_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2(JNIEnv* env, jclass clazz, jobject p0, jobject p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v7 = NULL;
  jboolean v15 = 0;
  jobject v6 = NULL;
  jboolean v8 = 0;
  jobject v5 = NULL;
  jint v10 = 0;
  jobject v12 = NULL;
  jboolean v14 = 0;
  jlong v17 = 0;
  jobject v3 = NULL;
  jobject v1 = NULL;
  jobject v13 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jobject v2 = NULL;
  jobject v11 = NULL;
  jobject v16 = NULL;
  jboolean v9 = 0;

L_0:
  v4 = env->NewStringUTF("home");
  v5 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"), v1, v4, v4, v4);
  v6 = v5;
  v7 = env->NewStringUTF("last");
  v8 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v7, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v6, v7, v7, v7);
  v9 = v8;
  /* UNSUPPORTED: if-eqz */
  if (v9 == 0) { v16 = (jobject)v3; goto L_21;
 } else { goto L_e;
 }

L_e:
  v10 = 0;
  v11 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"), v2, v10, v7, v7);
  v12 = v11;
  /* UNSUPPORTED: if-eqz */
  if (v12 == 0) { v16 = (jobject)v3; goto L_21;
 } else { goto L_15;
 }

L_15:
  v13 = env->AllocObject(env->FindClass("java/io/File"));
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/lang/String;)V"), v12, v7, v7, v7);
  v14 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/io/File"), "isDirectory", "()Z"), v7, v7, v7, v7);
  v15 = v14;
  /* UNSUPPORTED: if-eqz */
  if (v15 == 0) { v16 = (jobject)(intptr_t)v17; goto L_21;
 } else { goto L_20;
 }

L_20:
  /* return terminator */
  return (jobject)(intptr_t)v12;

L_21:
  /* return terminator */
  return (jobject)(intptr_t)v16;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ️︄(Landroid/content/SharedPreferences;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String; -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0f_0fe04__Landroid_content_SharedPreferences_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2 */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︀︂()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe00_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v4 = NULL;
  jobject v3 = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jint v5 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︅︅", "LI/ᅟ︈︎;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_9;
 } else { goto L_4;
 }

L_4:
  v2 = 0;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︅︅", "LI/ᅟ︈︎;"), (jobject)(intptr_t)v2);
  env->SetStaticObjectField(env->FindClass("bin/nt/xapk/ApkInstallReceiver"), env->GetStaticFieldID(env->FindClass("bin/nt/xapk/ApkInstallReceiver"), "ᅟ︀︀", "LI/ᅟ︈︎;"), (jobject)(intptr_t)v2);
goto L_9;

L_9:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︃", "Ljava/util/concurrent/ExecutorService;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("java/util/concurrent/ExecutorService"), "shutdown", "()V"), v3, v3, v3, v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ️︃", "Ljava/util/concurrent/ExecutorService;"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/util/concurrent/ExecutorService"), "shutdown", "()V"), v4, v4, v4, v4);
  v5 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︁︂", "Z"), v5);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︀︂()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe00_0fe02__ */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︀︄()V: java.lang.IllegalStateException: unknown phi type v1_2 = phi[v1_3 = phi[v1_5 = phi[v1_0, v1_0], v1_5 = phi[v1_0, v1_0]], v1_3 = phi[v1_5 = phi[v1_0, v1_0], v1_5 = phi[v1_0, v1_0]], v1_8 = phi[v1_3 = phi[v1_5 = phi[v1_0, v1_0], v1_5 = phi[v1_0, v1_0]]]] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︀︅()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe00_0fe05__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v7 = 0;
  jobject v3 = NULL;
  jint v8 = 0;
  jint v9 = 0;
  jobject v11 = NULL;
  jint v14 = 0;
  jint v16 = 0;
  jint v10 = 0;
  jint v18 = 0;
  jint v2 = 0;
  jint v15 = 0;
  jint v12 = 0;
  jobject v1 = NULL;
  jint v17 = 0;
  jint v13 = 0;
  jint v4 = 0;
  jint v5 = 0;
  jobject v0 = NULL;
  jint v6 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_2f;
 } else { goto L_4;
 }

L_4:
  v2 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︄", "I"));
  /* UNSUPPORTED: if-ltz */
  if (v2 < 0) { goto L_2f;
 } else { goto L_8;
 }

L_8:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︀︅", "Ljava/lang/String;"));
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ️︄", "I"));
  v5 = 100;
  v6 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v4, v5, v1, v1, v1);
  v7 = v6;
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("I/ᅠ︋︃"), "ᅟ︍︀", "(Ljava/lang/String;)V"), v3, v1, v1, v1);
  v8 = 1;
  v9 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v7, v8, v1, v1, v1);
  v10 = v9;
  v11 = (jobject)env->GetObjectField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("I/ᅠ︋︃"), "ᅟ︍︀", "Landroid/widget/ProgressBar;"));
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "setMax", "(I)V"), v10, v11, v11, v11);
  v12 = (jint)(intptr_t)env->CallIntMethod((jobject)v11, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "getMax", "()I"), v11, v11, v11, v11);
  v13 = v12;
  v14 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "min", "(II)I"), v2, v13, v11, v11, v11);
  v15 = v14;
  v16 = 0;
  v17 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v16, v15, v11, v11, v11);
  v18 = v17;
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "setProgress", "(I)V"), v18, v11, v11, v11);
goto L_2f;

L_2f:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︀︅()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe00_0fe05__ */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︁︄()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe01_0fe04__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v5 = NULL;
  jint v15 = 0;
  jint v1 = 0;
  jobject v3 = NULL;
  jint v6 = 0;
  jobject v11 = NULL;
  jobject v10 = NULL;
  jobject v0 = NULL;
  jint v4 = 0;
  jint v13 = 0;
  jarray v2 = NULL;
  jint v7 = 0;
  jint v14 = 0;
  jint v8 = 0;
  jint v12 = 0;
  jobject v9 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︃", "I"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v3 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v1);
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  /* UNSUPPORTED: if-gtz */
  if (v4 > 0) { goto L_b;
 } else { goto L_a;
 }

L_a:
  /* return terminator */
  return;

L_b:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︅", "(I)V"), v1, v1, v1, v1);
  v5 = (jobject)env->GetObjectArrayElement((jobjectArray)v5, (jsize)(intptr_t)v1);
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  v7 = 1;
  /* UNSUPPORTED: sub-int-2addr */
  env->SetIntField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"), v8);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︂︀", "Ljava/util/ArrayList;"));
  v10 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("java/util/ArrayList"), "get", "(I)Ljava/lang/Object;"), v8, v1, v1, v1);
  v11 = v10;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/String"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  env->SetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"), (jobject)(intptr_t)v12);
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_24;
 } else { goto L_22;
 }

L_22:
  v13 = 1;
  /* UNSUPPORTED: goto */
v15 = (jint)v13; goto L_25;

L_24:
  v14 = 0;
v15 = (jint)v14; goto L_25;

L_25:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︄", "(ZZ)V"), v15, v7, v15, v15);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︄", "()V"), v15, v15, v15, v15);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︄()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe01_0fe04__ */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︁︅(LI/ᅟ︎︎;Ljava/lang/String;Landroid/content/Context;Ljava/lang/String;)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe01_0fe05__LI__0115f_0fe0e_0fe0e_2Ljava_lang_String_2Landroid_content_Context_2Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2, jobject p3) {
  jthrowable pendingException = NULL;
  jobject v19 = NULL;
  jobject v11 = NULL;
  jobject v3 = NULL;
  jobject v5 = NULL;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jboolean v6 = 0;
  jboolean v7 = 0;
  jboolean v12 = 0;
  jobject v26 = NULL;
  jint v20 = 0;
  jobject v21 = NULL;
  jobject v16 = NULL;
  jobject v1 = NULL;
  jobject v23 = NULL;
  jboolean v18 = 0;
  jobject v14 = NULL;
  jboolean v17 = 0;
  jobject v10 = NULL;
  jboolean v13 = 0;
  jint v15 = 0;
  jboolean v24 = 0;
  jint v9 = 0;
  jobject v8 = NULL;
  jboolean v25 = 0;
  jboolean v22 = 0;
  jobject v2 = NULL;

L_0:
  v5 = env->NewStringUTF("manifest");
  v6 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v5, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v2, v5, v5, v5);
  v7 = v6;
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_14;
 } else { goto L_8;
 }

L_8:
  v8 = env->AllocObject(env->FindClass("I/ᅟ︋︍"));
  v9 = 1;
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("I/ᅟ︋︍"), "<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;I)V"), v0, v1, v9, v7);
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︃", "Ljava/util/concurrent/ExecutorService;"));
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("java/util/concurrent/Executor"), "execute", "(Ljava/lang/Runnable;)V"), v8, v7, v7, v7);
  /* UNSUPPORTED: goto */
goto L_45;

L_14:
  v11 = env->NewStringUTF("optimize");
  v12 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v11, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v2, v11, v11, v11);
  v13 = v12;
  /* UNSUPPORTED: if-eqz */
  if (v13 == 0) { goto L_26;
 } else { goto L_1c;
 }

L_1c:
  v14 = env->AllocObject(env->FindClass("I/ᅟ︂︍"));
  v15 = 4;
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("I/ᅟ︂︍"), "<init>", "(Lbin/nt/fragments/FileBrowserFragment;I)V"), v0, v15, v13, v13);
v21 = (jobject)v14; v22 = (jboolean)v13; goto L_22;

L_26:
  v16 = env->NewStringUTF("sign");
  v17 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v16, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v2, v16, v16, v16);
  v18 = v17;
  /* UNSUPPORTED: if-eqz */
  if (v18 == 0) { goto L_35;
 } else { goto L_2e;
 }

L_2e:
  v19 = env->AllocObject(env->FindClass("I/ᅟ︂︍"));
  v20 = 5;
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("I/ᅟ︂︍"), "<init>", "(Lbin/nt/fragments/FileBrowserFragment;I)V"), v0, v20, v18, v18);
  /* UNSUPPORTED: goto */
v21 = (jobject)v19; v22 = (jboolean)v18; goto L_22;

L_22:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︈︅", "(Landroid/content/Context;Ljava/lang/String;LI/ᅟ︌︎;)V"), v3, v4, v21, v22);
  /* UNSUPPORTED: goto */
goto L_45;

L_35:
  v23 = env->NewStringUTF("clone");
  v24 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v23, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v2, v23, v23, v23);
  v25 = v24;
  /* UNSUPPORTED: if-eqz */
  if (v25 == 0) { goto L_45;
 } else { goto L_3d;
 }

L_3d:
  v26 = env->AllocObject(env->FindClass("I/ᅟ︃︊"));
  env->CallVoidMethod((jobject)v26, env->GetMethodID(env->FindClass("I/ᅟ︃︊"), "<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V"), v0, v1, v23, v23);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︈︅", "(Landroid/content/Context;Ljava/lang/String;LI/ᅟ︌︎;)V"), v3, v4, v26, v23);
goto L_45;

L_45:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︅(LI/ᅟ︎︎;Ljava/lang/String;Landroid/content/Context;Ljava/lang/String;)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe01_0fe05__LI__0115f_0fe0e_0fe0e_2Ljava_lang_String_2Landroid_content_Context_2Ljava_lang_String_2 */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︂︄()Z */
jboolean Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe02_0fe04__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v8 = 0;
  jint v18 = 0;
  jint v2 = 0;
  jlong v19 = 0;
  jint v9 = 0;
  jint v14 = 0;
  jint v15 = 0;
  jobject v12 = NULL;
  jarray v1 = NULL;
  jint v13 = 0;
  jobject v6 = NULL;
  jobject v3 = NULL;
  jobject v7 = NULL;
  jobject v11 = NULL;
  jobject v10 = NULL;
  jlong v17 = 0;
  jint v4 = 0;
  jobject v5 = NULL;
  jint v16 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v2 = 0;
  v3 = (jobject)env->GetObjectArrayElement((jobjectArray)v1, (jsize)(intptr_t)v2);
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { v18 = (jint)v2; goto L_24;
 } else { goto L_7;
 }

L_7:
  v4 = 1;
  v5 = (jobject)env->GetObjectArrayElement((jobjectArray)v1, (jsize)(intptr_t)v4);
  /* UNSUPPORTED: if-nez */
  if (v5 != 0) { goto L_d;
 } else { goto L_c;
 }

L_c:
  /* UNSUPPORTED: goto */
v18 = (jint)(intptr_t)v19; goto L_24;

L_d:
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︁︀", "LI/ᅟ︁︍;"));
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅟ︁︍"), "ᅟ︅︀", "Ljava/util/HashSet;"));
  v8 = (jint)(intptr_t)env->CallIntMethod((jobject)v7, env->GetMethodID(env->FindClass("java/util/HashSet"), "size", "()I"), v1, v1, v1, v1);
  v9 = v8;
  /* UNSUPPORTED: if-gtz */
  if (v9 > 0) { v16 = (jint)v2; goto L_23;
 } else { goto L_17;
 }

L_17:
  v10 = (jobject)env->GetObjectArrayElement((jobjectArray)v10, (jsize)(intptr_t)v4);
  v11 = (jobject)env->GetObjectField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︁︀", "LI/ᅟ︁︍;"));
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅟ︁︍"), "ᅟ︅︀", "Ljava/util/HashSet;"));
  v13 = (jint)(intptr_t)env->CallIntMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/HashSet"), "size", "()I"), v12, v12, v12, v12);
  v14 = v13;
  /* UNSUPPORTED: if-lez */
  if (v14 <= 0) { v18 = (jint)(intptr_t)v17; goto L_24;
 } else { v16 = (jint)(intptr_t)v17; goto L_23;
 }

L_23:
  v15 = 1;
v18 = (jint)v16; goto L_24;

L_24:
  /* return terminator */
  return (jboolean)(intptr_t)v18;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︂︄()Z -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe02_0fe04__ */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︂︅(LI/ᅠ︉︌;)V: java.lang.IllegalStateException: unknown phi type v0_4 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︃︄(ZZ)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe03_0fe04__ZZ(JNIEnv* env, jobject thiz, jboolean p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jint v12 = 0;
  jobject v0 = NULL;
  jobject v19 = NULL;
  jboolean v2 = 0;
  jobject v5 = NULL;
  jobject v14 = NULL;
  jobject v25 = NULL;
  jobject v21 = NULL;
  jobject v16 = NULL;
  jint v7 = 0;
  jobject v8 = NULL;
  jarray v4 = NULL;
  jobject v9 = NULL;
  jobject v20 = NULL;
  jobject v18 = NULL;
  jboolean v23 = 0;
  jboolean v1 = 0;
  jint v6 = 0;
  jobject v17 = NULL;
  jobject v11 = NULL;
  jobject v15 = NULL;
  jobject v10 = NULL;
  jobject v22 = NULL;
  jint v3 = 0;
  jobject v13 = NULL;
  jboolean v24 = 0;

L_0:
  /* UNSUPPORTED: xor-int-lit8 */
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v5 = (jobject)env->GetObjectArrayElement((jobjectArray)v4, (jsize)(intptr_t)v3);
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︇︀", "I"));
  /* UNSUPPORTED: add-int-lit8 */
  env->SetIntField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︇︀", "I"), v7);
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︉︃", "Ljava/util/HashMap;"));
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v10 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("java/util/HashMap"), "get", "(Ljava/lang/Object;)Ljava/lang/Object;"), v9, v4, v4, v4);
  v11 = v10;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/String"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  /* UNSUPPORTED: if-eqz */
  if (v12 == 0) { goto L_1c;
 } else { goto L_18;
 }

L_18:
  v13 = (jobject)env->GetObjectArrayElement((jobjectArray)v4, (jsize)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v13, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"), (jobject)(intptr_t)v12);
goto L_1c;

L_1c:
  v14 = (jobject)env->GetObjectArrayElement((jobjectArray)v14, (jsize)(intptr_t)v3);
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v14, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v16 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v14, v14, v14, v14);
  v17 = v16;
  v18 = (jobject)env->CallObjectMethod((jobject)v17, env->GetMethodID(env->FindClass("android/content/Context"), "getApplicationContext", "()Landroid/content/Context;"), v17, v17, v17, v17);
  v19 = v18;
  v20 = env->AllocObject(env->FindClass("I/ᅟ︈︍"));
  /* dbg-move v21 v20 dv=Ljava/lang/Object; sv=LI/ᅟ︈︍; */
  /* dbg-move v22 v0 dv=Ljava/lang/Object; sv=Lbin/nt/fragments/FileBrowserFragment; */
  /* dbg-move v23 v2 dv=Z sv=Z */
  /* dbg-move v24 v1 dv=Z sv=Z */
  env->CallVoidMethod((jobject)v21, env->GetMethodID(env->FindClass("I/ᅟ︈︍"), "<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;ZLandroid/content/Context;IIZ)V"), v22, v15, v23, v19, v7, v3, v24);
  v25 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︃", "Ljava/util/concurrent/ExecutorService;"));
  env->CallVoidMethod((jobject)v25, env->GetMethodID(env->FindClass("java/util/concurrent/Executor"), "execute", "(Ljava/lang/Runnable;)V"), v20, v21, v21, v21);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︄(ZZ)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe03_0fe04__ZZ */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︃︅(I)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe03_0fe05__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v14 = 0;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jobject v15 = NULL;
  jobject v16 = NULL;
  jobject v7 = NULL;
  jobject v11 = NULL;
  jobject v12 = NULL;
  jobject v0 = NULL;
  jint v13 = 0;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v17 = NULL;
  jint v1 = 0;
  jarray v2 = NULL;
  jobject v4 = NULL;
  jint v8 = 0;
  jobject v10 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v3 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v1);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  /* UNSUPPORTED: if-eqz */
  if (v4 == 0) { goto L_2c;
 } else { goto L_8;
 }

L_8:
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︅︃", "LI/ᅟ︆︎;"));
  /* UNSUPPORTED: if-nez */
  if (v5 != 0) { goto L_d;
 } else { goto L_c;
 }

L_c:
  /* UNSUPPORTED: goto */
goto L_2c;

L_d:
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_14;
 } else { goto L_f;
 }

L_f:
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︂︀", "Ljava/lang/Object;"));
goto L_11;

L_14:
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅟ︆︎"), "ᅟ︀︀", "Ljava/lang/Object;"));
  /* UNSUPPORTED: goto */
goto L_11;

L_11:
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("bin/nt/ui/PanelView"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  /* UNSUPPORTED: goto */
goto L_17;

L_17:
  v9 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("bin/nt/ui/PanelView"), "getLinearLayoutManager", "()Landroidx/recyclerview/widget/LinearLayoutManager;"), v2, v2, v2, v2);
  v10 = (jobject)(intptr_t)v9;
  /* UNSUPPORTED: if-eqz */
  if (v10 == 0) { goto L_2c;
 } else { goto L_1d;
 }

L_1d:
  v11 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v11);
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︅︀", "Ljava/util/HashMap;"));
  v13 = (jint)(intptr_t)env->CallIntMethod((jobject)v10, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"), "ᅟ︀︆", "()I"), v2, v2, v2, v2);
  v14 = v13;
  v15 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/lang/Integer"), env->GetStaticMethodID(env->FindClass("java/lang/Integer"), "valueOf", "(I)Ljava/lang/Integer;"), v14, v14, v14, v14, v14);
  v16 = (jobject)(intptr_t)v15;
  v17 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/HashMap"), "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;"), v4, v16, v16, v16);
goto L_2c;

L_2c:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︅(I)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe03_0fe05__I */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︄︂()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe04_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v59 = NULL;
  jobject v7 = NULL;
  jint v51 = 0;
  jarray v16 = NULL;
  jobject v19 = NULL;
  jobject v22 = NULL;
  jint v8 = 0;
  jint v14 = 0;
  jlong v35 = 0;
  jlong v48 = 0;
  jobject v4 = NULL;
  jint v31 = 0;
  jint v32 = 0;
  jlong v37 = 0;
  jint v6 = 0;
  jlong v34 = 0;
  jlong v42 = 0;
  jlong v43 = 0;
  jboolean v53 = 0;
  jlong v62 = 0;
  jint v3 = 0;
  jlong v63 = 0;
  jlong v65 = 0;
  jint v2 = 0;
  jboolean v20 = 0;
  jlong v56 = 0;
  jboolean v25 = 0;
  jlong v55 = 0;
  jobject v29 = NULL;
  jlong v40 = 0;
  jboolean v52 = 0;
  jarray v60 = NULL;
  jlong v36 = 0;
  jboolean v26 = 0;
  jobject v58 = NULL;
  jlong v47 = 0;
  jint v13 = 0;
  jobject v27 = NULL;
  jlong v33 = 0;
  jlong v46 = 0;
  jobject v49 = NULL;
  jint v28 = 0;
  jint v1 = 0;
  jobject v30 = NULL;
  jlong v44 = 0;
  jobject v17 = NULL;
  jobject v24 = NULL;
  jint v11 = 0;
  jobject v18 = NULL;
  jlong v38 = 0;
  jboolean v21 = 0;
  jlong v41 = 0;
  jint v5 = 0;
  jarray v57 = NULL;
  jlong v64 = 0;
  jint v15 = 0;
  jobject v23 = NULL;
  jboolean v54 = 0;
  jobject v50 = NULL;
  jint v61 = 0;
  jobject v0 = NULL;
  jlong v45 = 0;
  jlong v39 = 0;
  jint v9 = 0;
  jobject v12 = NULL;
  jint v10 = 0;

L_0:
  v1 = 2;
  v2 = 0;
  v3 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︁︂", "Z"), v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︅︃", "LI/ᅟ︆︎;"));
  /* UNSUPPORTED: if-nez */
  if (v4 != 0) { goto L_a;
 } else { goto L_9;
 }

L_9:
  /* UNSUPPORTED: goto */
goto L_52;

L_a:
  v5 = 0;
v6 = (jint)v1; v7 = (jobject)v0; v8 = (jint)v2; v9 = (jint)v5; v10 = (jint)v3; goto L_b;

L_b:
  /* UNSUPPORTED: if-ge */
  if (v9 >= v6) { goto L_52;
 } else { goto L_d;
 }

L_d:
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v17 = (jobject)env->GetObjectArrayElement((jobjectArray)v17, (jsize)(intptr_t)v9);
  v18 = (jobject)env->GetObjectField((jobject)(intptr_t)v18, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︁︀", "LI/ᅟ︁︍;"));
  v19 = (jobject)env->GetObjectField((jobject)(intptr_t)v19, env->GetFieldID(env->FindClass("I/ᅟ︁︍"), "ᅟ︄︀", "Ljava/util/ArrayList;"));
  v20 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v19, env->GetMethodID(env->FindClass("java/util/ArrayList"), "isEmpty", "()Z"), v6, v6, v6, v6);
  v21 = v20;
  /* UNSUPPORTED: if-eqz */
  if (v21 == 0) { goto L_1c;
 } else { goto L_1b;
 }

L_1b:
  /* UNSUPPORTED: goto */
v13 = (jint)v8; v15 = (jint)v10; v14 = (jint)v9; v12 = (jobject)v7; v11 = (jint)v6; goto L_50;

L_1c:
  v22 = env->AllocObject(env->FindClass("java/util/HashMap"));
  env->CallVoidMethod((jobject)v22, env->GetMethodID(env->FindClass("java/util/HashMap"), "<init>", "()V"), v6, v6, v6, v6);
  v23 = (jobject)env->CallObjectMethod((jobject)v19, env->GetMethodID(env->FindClass("java/util/ArrayList"), "iterator", "()Ljava/util/Iterator;"), v6, v6, v6, v6);
  v24 = v23;
v27 = (jobject)v24; v28 = (jint)v9; v29 = (jobject)v7; v30 = (jobject)v22; v31 = (jint)v6; v32 = (jint)v10; goto L_25;

L_25:
  v25 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v27, env->GetMethodID(env->FindClass("java/util/Iterator"), "hasNext", "()Z"), v31, v31, v31, v31);
  v26 = v25;
  /* UNSUPPORTED: if-eqz */
  if (v26 == 0) { goto L_4c;
 } else { goto L_2b;
 }

L_2b:
  v49 = (jobject)env->CallObjectMethod((jobject)v27, env->GetMethodID(env->FindClass("java/util/Iterator"), "next", "()Ljava/lang/Object;"), v31, v31, v31, v31);
  v50 = v49;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅟ︎︎"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v52 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v51, env->GetMethodID(env->FindClass("I/ᅟ︎︎"), "ᅟ︀︀", "()Z"), v31, v31, v31, v31);
  v53 = v52;
  /* UNSUPPORTED: if-nez */
  if (v53 != 0) { v27 = (jobject)(intptr_t)v33; v28 = (jint)(intptr_t)v36; v29 = (jobject)(intptr_t)v39; v30 = (jobject)v30; v31 = (jint)(intptr_t)v44; v32 = (jint)v32; goto L_25;
 } else { goto L_37;
 }

L_37:
  v54 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v51, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︃︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v54 == 0) { goto L_3c;
 } else { goto L_3b;
 }

L_3b:
  /* UNSUPPORTED: goto */
v27 = (jobject)(intptr_t)v34; v28 = (jint)(intptr_t)v37; v29 = (jobject)(intptr_t)v40; v30 = (jobject)(intptr_t)v42; v31 = (jint)(intptr_t)v45; v32 = (jint)(intptr_t)v47; goto L_25;

L_3c:
  v55 = (jlong)(intptr_t)env->GetLongField((jobject)(intptr_t)v51, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︂︀", "J"));
  v56 = (jlong)(intptr_t)env->GetLongField((jobject)(intptr_t)v51, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︄︀", "J"));
  v57 = env->NewLongArray((jsize)(intptr_t)v44);
  env->SetLongArrayRegion((jlongArray)v57, (jsize)(intptr_t)v8, 1, (jlong*)&v55);
  env->SetLongArrayRegion((jlongArray)v57, (jsize)(intptr_t)v32, 1, (jlong*)&v56);
  v58 = (jobject)env->GetObjectField((jobject)(intptr_t)v58, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v59 = (jobject)env->CallObjectMethod((jobject)v30, env->GetMethodID(env->FindClass("java/util/HashMap"), "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;"), v58, v57, v44, v44);
  /* UNSUPPORTED: goto */
v27 = (jobject)(intptr_t)v35; v28 = (jint)(intptr_t)v38; v29 = (jobject)(intptr_t)v41; v30 = (jobject)(intptr_t)v43; v31 = (jint)(intptr_t)v46; v32 = (jint)(intptr_t)v48; goto L_25;

L_4c:
  v60 = (jobject)env->GetObjectField((jobject)(intptr_t)v29, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︊︃", "[Ljava/util/Map;"));
  env->SetObjectArrayElement((jobjectArray)v60, (jsize)v28, (jobject)(intptr_t)v30);
v13 = (jint)(intptr_t)v62; v15 = (jint)v32; v14 = (jint)(intptr_t)v63; v12 = (jobject)(intptr_t)v64; v11 = (jint)(intptr_t)v65; goto L_50;

L_50:
  /* UNSUPPORTED: add-int-2addr */
  /* UNSUPPORTED: goto */
v6 = (jint)v11; v7 = (jobject)v12; v8 = (jint)v13; v9 = (jint)v14; v10 = (jint)v15; goto L_b;

L_52:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︄︂()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe04_0fe02__ */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︄︄(Ljava/lang/String;)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe04_0fe04__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v8 = 0;
  jint v7 = 0;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jarray v4 = NULL;
  jint v3 = 0;
  jint v6 = 0;
  jint v9 = 0;
  jobject v1 = NULL;

L_0:
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_21;
 } else { goto L_2;
 }

L_2:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︅︃", "LI/ᅟ︆︎;"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_7;
 } else { goto L_6;
 }

L_6:
  /* UNSUPPORTED: goto */
goto L_21;

L_7:
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︃", "I"));
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︅", "(I)V"), v3, v3, v3, v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v5 = (jobject)env->GetObjectArrayElement((jobjectArray)v5, (jsize)(intptr_t)v3);
  env->SetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"), (jobject)(intptr_t)v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︌︄", "(ILjava/lang/String;)V"), v3, v1, v3, v3);
  v6 = 0;
  /* UNSUPPORTED: if-nez */
  if (v3 != 0) { goto L_1a;
 } else { goto L_18;
 }

L_18:
  v7 = 1;
  /* UNSUPPORTED: goto */
v9 = (jint)v7; goto L_1b;

L_1a:
  v8 = 0;
v9 = (jint)v8; goto L_1b;

L_1b:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︄", "(ZZ)V"), v9, v6, v9, v9);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︄", "()V"), v9, v9, v9, v9);
goto L_21;

L_21:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︄︄(Ljava/lang/String;)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe04_0fe04__Ljava_lang_String_2 */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︄︅(IIZ)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︅︂()V: java.lang.IllegalStateException: unknown phi type v0_15 = phi[v0_16 = phi[v0_4 = phi[v0_0, v0_0], v0_4 = phi[v0_0, v0_0]], v0_16 = phi[v0_4 = phi[v0_0, v0_0], v0_4 = phi[v0_0, v0_0]], v0_19 = phi[v0_16 = phi[v0_4 = phi[v0_0, v0_0], v0_4 = phi[v0_0, v0_0]]]] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︅︄(LI/ᅟ︎︎;Z)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe05_0fe04__LI__0115f_0fe0e_0fe0e_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jboolean v2 = 0;
  jint v7 = 0;
  jint v3 = 0;
  jobject v0 = NULL;
  jobject v6 = NULL;
  jarray v4 = NULL;
  jobject v5 = NULL;
  jobject v1 = NULL;

L_0:
  /* UNSUPPORTED: xor-int-lit8 */
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︅", "(I)V"), v3, v3, v3, v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v5 = (jobject)env->GetObjectArrayElement((jobjectArray)v5, (jsize)(intptr_t)v3);
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︁︀", "Ljava/lang/String;"));
  env->SetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"), (jobject)(intptr_t)v6);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︌︄", "(ILjava/lang/String;)V"), v3, v6, v3, v3);
  v7 = 1;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︄", "(ZZ)V"), v2, v7, v3, v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︄", "()V"), v3, v3, v3, v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︄(LI/ᅟ︎︎;Z)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe05_0fe04__LI__0115f_0fe0e_0fe0e_2Z */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︅︅(Ljava/lang/String;Z)Landroid/widget/EditText; */
jobject Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe05_0fe05__Ljava_lang_String_2Z(JNIEnv* env, jobject thiz, jobject p0, jboolean p1) {
  jthrowable pendingException = NULL;
  jint v6 = 0;
  jobject v3 = NULL;
  jint v7 = 0;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jboolean v2 = 0;
  jobject v5 = NULL;

L_0:
  v3 = env->AllocObject(env->FindClass("android/widget/EditText"));
  v4 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v3, v3, v3, v3);
  v5 = v4;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/EditText"), "<init>", "(Landroid/content/Context;)V"), v5, v3, v3, v3);
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/TextView"), "setHint", "(Ljava/lang/CharSequence;)V"), v1, v3, v3, v3);
  v6 = 1;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/TextView"), "setSingleLine", "(Z)V"), v6, v3, v3, v3);
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_17;
 } else { goto L_12;
 }

L_12:
  v7 = 129;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/TextView"), "setInputType", "(I)V"), v7, v3, v3, v3);
goto L_17;

L_17:
  /* return terminator */
  return (jobject)(intptr_t)v3;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︅︅(Ljava/lang/String;Z)Landroid/widget/EditText; -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe05_0fe05__Ljava_lang_String_2Z */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︆︂(Landroid/os/Bundle;)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe06_0fe02__Landroid_os_Bundle_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jint v12 = 0;
  jint v33 = 0;
  jobject v8 = NULL;
  jobject v28 = NULL;
  jobject v29 = NULL;
  jobject v18 = NULL;
  jobject v30 = NULL;
  jobject v10 = NULL;
  jobject v0 = NULL;
  jobject v26 = NULL;
  jobject v23 = NULL;
  jobject v19 = NULL;
  jint v22 = 0;
  jobject v20 = NULL;
  jobject v15 = NULL;
  jarray v2 = NULL;
  jint v11 = 0;
  jint v7 = 0;
  jint v13 = 0;
  jobject v17 = NULL;
  jint v25 = 0;
  jobject v14 = NULL;
  jobject v16 = NULL;
  jint v3 = 0;
  jobject v6 = NULL;
  jobject v5 = NULL;
  jobject v27 = NULL;
  jobject v9 = NULL;
  jobject v21 = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jobject v24 = NULL;
  jobject v31 = NULL;
  jobject v32 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v3 = 0;
  v4 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v3);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v6 = env->NewStringUTF("path_left");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/BaseBundle"), "putString", "(Ljava/lang/String;Ljava/lang/String;)V"), v6, v5, v2, v2);
  v7 = 1;
  v8 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v7);
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v10 = env->NewStringUTF("path_right");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/BaseBundle"), "putString", "(Ljava/lang/String;Ljava/lang/String;)V"), v10, v9, v2, v2);
  v11 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︃", "I"));
  /* UNSUPPORTED: if-nez */
  if (v11 != 0) { goto L_1c;
 } else { goto L_1a;
 }

L_1a:
  v12 = 1;
  /* UNSUPPORTED: goto */
v33 = (jint)v12; goto L_1d;

L_1c:
  v13 = 0;
v33 = (jint)v13; goto L_1d;

L_1d:
  v14 = env->NewStringUTF("left_active");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/Bundle"), "putBoolean", "(Ljava/lang/String;Z)V"), v14, v33, v2, v2);
  v15 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v3);
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v16, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︂︀", "Ljava/util/ArrayList;"));
  v17 = env->NewStringUTF("history_left");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/Bundle"), "putStringArrayList", "(Ljava/lang/String;Ljava/util/ArrayList;)V"), v17, v16, v2, v2);
  v18 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v7);
  v19 = (jobject)env->GetObjectField((jobject)(intptr_t)v19, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︂︀", "Ljava/util/ArrayList;"));
  v20 = env->NewStringUTF("history_right");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/Bundle"), "putStringArrayList", "(Ljava/lang/String;Ljava/util/ArrayList;)V"), v20, v19, v2, v2);
  v21 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v3);
  v22 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v22, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  v23 = env->NewStringUTF("history_index_left");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/BaseBundle"), "putInt", "(Ljava/lang/String;I)V"), v23, v22, v2, v2);
  v24 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v7);
  v25 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v25, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  v26 = env->NewStringUTF("history_index_right");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/BaseBundle"), "putInt", "(Ljava/lang/String;I)V"), v26, v25, v2, v2);
  v27 = env->AllocObject(env->FindClass("java/util/HashMap"));
  env->CallVoidMethod((jobject)v27, env->GetMethodID(env->FindClass("java/util/HashMap"), "<init>", "()V"), v2, v2, v2, v2);
  v28 = (jobject)env->GetObjectArrayElement((jobjectArray)v2, (jsize)(intptr_t)v28);
  v29 = (jobject)env->GetObjectField((jobject)(intptr_t)v29, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︅︀", "Ljava/util/HashMap;"));
  env->CallVoidMethod((jobject)v27, env->GetMethodID(env->FindClass("java/util/HashMap"), "putAll", "(Ljava/util/Map;)V"), v29, v2, v2, v2);
  v30 = (jobject)env->GetObjectArrayElement((jobjectArray)v30, (jsize)(intptr_t)v7);
  v31 = (jobject)env->GetObjectField((jobject)(intptr_t)v31, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︅︀", "Ljava/util/HashMap;"));
  env->CallVoidMethod((jobject)v27, env->GetMethodID(env->FindClass("java/util/HashMap"), "putAll", "(Ljava/util/Map;)V"), v31, v31, v31, v31);
  v32 = env->NewStringUTF("scroll_positions");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/os/Bundle"), "putSerializable", "(Ljava/lang/String;Ljava/io/Serializable;)V"), v32, v27, v32, v32);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︆︂(Landroid/os/Bundle;)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe06_0fe02__Landroid_os_Bundle_2 */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︆︄()V: java.lang.IllegalStateException: unknown phi type v1_14 = phi[v1_9, v1_10] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︆︅(Ljava/lang/String;Ljava/util/List;LI/ᅟ︋︋;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︇︂()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe07_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jobject v6 = NULL;
  jobject v7 = NULL;
  jobject v11 = NULL;
  jobject v0 = NULL;
  jobject v8 = NULL;
  jint v1 = 0;
  jobject v5 = NULL;
  jboolean v2 = 0;
  jobject v9 = NULL;
  jobject v4 = NULL;
  jobject v10 = NULL;

L_0:
  v1 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︁︂", "Z"), v1);
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︅", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_30;
 } else { goto L_7;
 }

L_7:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︄︅", "Lbin/nt/xapk/ApkInstallReceiver;"));
  /* UNSUPPORTED: if-nez */
  if (v3 != 0) { goto L_c;
 } else { goto L_b;
 }

L_b:
  /* UNSUPPORTED: goto */
goto L_30;

L_c:
  v4 = env->AllocObject(env->FindClass("android/content/IntentFilter")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/IntentFilter"), "<init>", "()V"), v1, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v5 = env->NewStringUTF("android.intent.action.PACKAGE_ADDED");
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/IntentFilter"), "addAction", "(Ljava/lang/String;)V"), v5, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v6 = env->NewStringUTF("android.intent.action.PACKAGE_REMOVED");
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/IntentFilter"), "addAction", "(Ljava/lang/String;)V"), v6, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v7 = env->NewStringUTF("package");
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/IntentFilter"), "addDataScheme", "(Ljava/lang/String;)V"), v7, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v8 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v1, v1, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v9 = v8;
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︄︅", "Lbin/nt/xapk/ApkInstallReceiver;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallStaticVoidMethod(env->FindClass("androidx/core/content/ContextCompat"), env->GetStaticMethodID(env->FindClass("androidx/core/content/ContextCompat"), "ᅟ︇︀", "(Landroid/content/Context;Lbin/nt/xapk/ApkInstallReceiver;Landroid/content/IntentFilter;)V"), v9, v10, v4, v1, v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︅", "Z"), v1); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
goto L_2b;

L_2c:
  v11 = pendingException;
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("java/lang/Throwable"), "printStackTrace", "()V"), v11, v11, v11, v11);
goto L_30;

L_2b:
  /* UNSUPPORTED: goto */
goto L_30;

L_30:
  /* return terminator */
  return;

EX_LandingPad_3:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_2c;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︇︂()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe07_0fe02__ */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︇︄()V: java.lang.IllegalStateException: unknown phi type v11_11 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︈︂()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe08_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v1 = 0;
  jlong v11 = 0;
  jobject v21 = NULL;
  jint v18 = 0;
  jobject v15 = NULL;
  jobject v5 = NULL;
  jobject v6 = NULL;
  jobject v3 = NULL;
  jint v7 = 0;
  jlong v23 = 0;
  jobject v9 = NULL;
  jobject v22 = NULL;
  jobject v16 = NULL;
  jint v17 = 0;
  jlong v24 = 0;
  jlong v10 = 0;
  jobject v8 = NULL;
  jobject v4 = NULL;
  jobject v19 = NULL;
  jobject v12 = NULL;
  jint v14 = 0;
  jint v13 = 0;
  jobject v0 = NULL;
  jint v20 = 0;
  jboolean v2 = 0;

L_0:
  v1 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︁︂", "Z"), v1);
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︅", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { v9 = (jobject)v0; goto L_18;
 } else { goto L_7;
 }

L_7:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︄︅", "Lbin/nt/xapk/ApkInstallReceiver;"));
  /* UNSUPPORTED: if-nez */
  if (v3 != 0) { goto L_c;
 } else { goto L_b;
 }

L_b:
  /* UNSUPPORTED: goto */
v9 = (jobject)(intptr_t)v10; goto L_18;

L_c:
  v4 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v3, v3, v3, v3); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v5 = v4;
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︄︅", "Lbin/nt/xapk/ApkInstallReceiver;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/content/Context"), "unregisterReceiver", "(Landroid/content/BroadcastReceiver;)V"), v6, v5, v5, v5); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
goto L_15;

L_15:
  v7 = 0;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︅", "Z"), v7);
v9 = (jobject)(intptr_t)v11; goto L_18;

L_18:
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;"));
  /* UNSUPPORTED: if-eqz */
  if (v8 == 0) { v21 = (jobject)v8; v22 = (jobject)v9; goto L_36;
 } else { goto L_1c;
 }

L_1c:
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅠ︋︃"), "ᅟ︍︀", "Landroid/widget/ProgressBar;"));
  v13 = (jint)(intptr_t)env->CallIntMethod((jobject)v12, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "getProgress", "()I"), v12, v12, v12, v12);
  v14 = v13;
  env->SetIntField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︄", "I"), v14);
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;"));
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v16, env->GetFieldID(env->FindClass("I/ᅠ︋︃"), "ᅟ︍︀", "Landroid/widget/ProgressBar;"));
  v17 = (jint)(intptr_t)env->CallIntMethod((jobject)v16, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "getMax", "()I"), v16, v16, v16, v16);
  v18 = v17;
  env->SetIntField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ️︄", "I"), v18);
goto L_2e;

L_2e:
  v19 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatDialog"), "dismiss", "()V"), v19, v19, v19, v19); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_7; }
goto L_33;

L_33:
  v20 = 0;
  env->SetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;"), (jobject)(intptr_t)v20);
v21 = (jobject)(intptr_t)v23; v22 = (jobject)(intptr_t)v24; goto L_36;

L_36:
  env->CallVoidMethod((jobject)v22, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︄", "()V"), v21, v21, v21, v21);
  /* return terminator */
  return;

EX_LandingPad_3:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_15;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_7:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_33;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︈︂()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe08_0fe02__ */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︈︄(LI/ᅟ︎︎;)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe08_0fe04__LI__0115f_0fe0e_0fe0e_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v35 = NULL;
  jlong v39 = 0;
  jlong v51 = 0;
  jlong v43 = 0;
  jobject v58 = NULL;
  jobject v29 = NULL;
  jlong v33 = 0;
  jboolean v31 = 0;
  jboolean v14 = 0;
  jlong v48 = 0;
  jint v62 = 0;
  jobject v64 = NULL;
  jlong v61 = 0;
  jobject v65 = NULL;
  jobject v68 = NULL;
  jint v12 = 0;
  jobject v7 = NULL;
  jobject v36 = NULL;
  jobject v6 = NULL;
  jlong v41 = 0;
  jint v18 = 0;
  jobject v26 = NULL;
  jboolean v30 = 0;
  jobject v54 = NULL;
  jlong v50 = 0;
  jlong v22 = 0;
  jlong v52 = 0;
  jobject v37 = NULL;
  jobject v66 = NULL;
  jint v63 = 0;
  jboolean v11 = 0;
  jobject v13 = NULL;
  jlong v32 = 0;
  jlong v40 = 0;
  jobject v69 = NULL;
  jobject v71 = NULL;
  jobject v9 = NULL;
  jobject v59 = NULL;
  jint v2 = 0;
  jint v20 = 0;
  jint v16 = 0;
  jint v34 = 0;
  jboolean v10 = 0;
  jlong v44 = 0;
  jint v55 = 0;
  jobject v72 = NULL;
  jlong v42 = 0;
  jint v21 = 0;
  jlong v49 = 0;
  jobject v56 = NULL;
  jobject v4 = NULL;
  jobject v53 = NULL;
  jobject v5 = NULL;
  jobject v28 = NULL;
  jint v17 = 0;
  jobject v25 = NULL;
  jobject v0 = NULL;
  jlong v46 = 0;
  jobject v27 = NULL;
  jobject v70 = NULL;
  jlong v45 = 0;
  jint v24 = 0;
  jobject v57 = NULL;
  jobject v8 = NULL;
  jobject v1 = NULL;
  jint v19 = 0;
  jlong v60 = 0;
  jobject v67 = NULL;
  jboolean v15 = 0;
  jlong v47 = 0;
  jlong v23 = 0;
  jint v38 = 0;
  jobject v3 = NULL;

L_0:
  v2 = 0;
  v3 = env->AllocObject(env->FindClass("java/io/File"));
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︁︀", "Ljava/lang/String;"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/lang/String;)V"), v4, v2, v2, v2);
  v5 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︂️"), env->GetStaticMethodID(env->FindClass("I/ᅟ︂️"), "ᅟ︂︀", "(Ljava/io/File;)LI/ᅟ️︁;"), v3, v2, v2, v2, v2);
  v6 = v5;
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { v63 = (jint)v2; v64 = (jobject)v0; v65 = (jobject)v1; goto L_5a;
 } else { goto L_e;
 }

L_e:
  v7 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︁️"), env->GetStaticFieldID(env->FindClass("I/ᅟ︁️"), "ᅟ︀︀", "Ljava/util/HashMap;"));
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v9 = env->NewStringUTF("Makefile");
  v10 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v9, v2, v2, v2);
  v11 = v10;
  v12 = 1;
  /* UNSUPPORTED: if-nez */
  if (v11 != 0) { v34 = (jint)v2; v35 = (jobject)v0; v36 = (jobject)v4; v37 = (jobject)v1; v38 = (jint)v12; goto L_42;
 } else { goto L_1b;
 }

L_1b:
  v13 = env->NewStringUTF("Dockerfile");
  v14 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v13, v2, v2, v2);
  v15 = v14;
  /* UNSUPPORTED: if-eqz */
  if (v15 == 0) { goto L_24;
 } else { goto L_23;
 }

L_23:
  /* UNSUPPORTED: goto */
v34 = (jint)(intptr_t)v39; v35 = (jobject)(intptr_t)v41; v36 = (jobject)v4; v37 = (jobject)(intptr_t)v47; v38 = (jint)(intptr_t)v51; goto L_42;

L_24:
  v16 = 46;
  v17 = (jint)(intptr_t)env->CallIntMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/String"), "lastIndexOf", "(I)I"), v16, v2, v2, v2);
  v18 = v17;
  /* UNSUPPORTED: if-lez */
  if (v18 <= 0) { v34 = (jint)(intptr_t)v22; v35 = (jobject)(intptr_t)v42; v36 = (jobject)v4; v37 = (jobject)(intptr_t)v48; v38 = (jint)(intptr_t)v23; goto L_42;
 } else { goto L_2c;
 }

L_2c:
  v19 = (jint)(intptr_t)env->CallIntMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/String"), "length", "()I"), v22, v22, v22, v22);
  v20 = v19;
  /* UNSUPPORTED: sub-int-2addr */
  /* UNSUPPORTED: if-ge */
  if (v18 >= v21) { v34 = (jint)(intptr_t)v33; v35 = (jobject)(intptr_t)v43; v36 = (jobject)(intptr_t)v45; v37 = (jobject)(intptr_t)v49; v38 = (jint)(intptr_t)v32; goto L_42;
 } else { goto L_33;
 }

L_33:
  /* UNSUPPORTED: add-int-2addr */
  v25 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/String"), "substring", "(I)Ljava/lang/String;"), v24, v33, v33, v33);
  v26 = (jobject)(intptr_t)v25;
  v27 = (jobject)env->CallObjectMethod((jobject)v26, env->GetMethodID(env->FindClass("java/lang/String"), "toLowerCase", "()Ljava/lang/String;"), v33, v33, v33, v33);
  v28 = v27;
  v29 = (jobject)env->GetStaticObjectField(env->FindClass("I/ᅟ︁️"), env->GetStaticFieldID(env->FindClass("I/ᅟ︁️"), "ᅟ︀︀", "Ljava/util/HashMap;"));
  v30 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v29, env->GetMethodID(env->FindClass("java/util/HashMap"), "containsKey", "(Ljava/lang/Object;)Z"), v28, v33, v33, v33);
  v31 = v30;
v34 = (jint)(intptr_t)v40; v35 = (jobject)(intptr_t)v44; v36 = (jobject)(intptr_t)v46; v37 = (jobject)(intptr_t)v50; v38 = (jint)(intptr_t)v52; goto L_42;

L_42:
  /* UNSUPPORTED: if-eqz */
  if (v38 == 0) { v63 = (jint)v34; v64 = (jobject)v35; v65 = (jobject)v37; goto L_5a;
 } else { goto L_44;
 }

L_44:
  v53 = (jobject)env->CallObjectMethod((jobject)v35, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v34, v34, v34, v34);
  v54 = v53;
  v55 = (jint)(intptr_t)env->GetStaticIntField(env->FindClass("bin/nt/main/TextEditorActivity"), env->GetStaticFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︍︃", "I"));
  v56 = env->AllocObject(env->FindClass("android/content/Intent"));
  v57 = env->FindClass("bin/nt/main/TextEditorActivity");
  env->CallVoidMethod((jobject)v56, env->GetMethodID(env->FindClass("android/content/Intent"), "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V"), v54, v57, v56, v56);
  v58 = env->NewStringUTF("file_path");
  v59 = (jobject)env->CallObjectMethod((jobject)v56, env->GetMethodID(env->FindClass("android/content/Intent"), "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;"), v58, v36, v56, v56);
  env->CallVoidMethod((jobject)v54, env->GetMethodID(env->FindClass("android/content/Context"), "startActivity", "(Landroid/content/Intent;)V"), v56, v56, v56, v56);
  /* return terminator */
  return;

L_5a:
  v60 = (jlong)(intptr_t)env->GetLongField((jobject)(intptr_t)v65, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︂︀", "J"));
  v61 = 524288;
  v62 = (v60 > v61 ? 1 : (v60 < v61 ? -1 : 0));
  /* UNSUPPORTED: if-lez */
  if (v62 <= 0) { goto L_71;
 } else { goto L_63;
 }

L_63:
  v66 = (jobject)env->CallObjectMethod((jobject)v64, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v63, v63, v63, v63);
  v67 = v66;
  v68 = env->NewStringUTF("File too large to preview");
  v69 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"), v67, v68, v63, v63, v63);
  v70 = v69;
  env->CallVoidMethod((jobject)v70, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v63, v63, v63, v63);
  /* return terminator */
  return;

L_71:
  v71 = env->AllocObject(env->FindClass("I/ᅟ︋︍"));
  env->CallVoidMethod((jobject)v71, env->GetMethodID(env->FindClass("I/ᅟ︋︍"), "<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;I)V"), v64, v65, v63, v63);
  v72 = (jobject)env->GetObjectField((jobject)(intptr_t)v64, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︃", "Ljava/util/concurrent/ExecutorService;"));
  env->CallVoidMethod((jobject)v72, env->GetMethodID(env->FindClass("java/util/concurrent/Executor"), "execute", "(Ljava/lang/Runnable;)V"), v71, v63, v63, v63);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︈︄(LI/ᅟ︎︎;)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe08_0fe04__LI__0115f_0fe0e_0fe0e_2 */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︈︅(Landroid/content/Context;Ljava/lang/String;LI/ᅟ︌︎;)V: java.lang.IllegalStateException: unknown phi type v0_2 = phi[] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︊︄(Ljava/io/File;LI/ᅟ︍︎;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︋︃()Z */
jboolean Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0b_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v3 = 0;
  jint v4 = 0;
  jint v1 = 0;
  jobject v0 = NULL;
  jint v2 = 0;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︃", "I"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_6;
 } else { goto L_4;
 }

L_4:
  v2 = 1;
  /* UNSUPPORTED: goto */
v4 = (jint)v2; goto L_7;

L_6:
  v3 = 0;
v4 = (jint)v3; goto L_7;

L_7:
  /* return terminator */
  return (jboolean)(intptr_t)v4;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︋︃()Z -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0b_0fe03__ */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︋︄()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︌︃()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0c_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v8 = 0;
  jboolean v2 = 0;
  jint v9 = 0;
  jint v10 = 0;
  jint v7 = 0;
  jobject v0 = NULL;
  jint v4 = 0;
  jobject v11 = NULL;
  jint v12 = 0;
  jlong v16 = 0;
  jboolean v3 = 0;
  jint v6 = 0;
  jlong v17 = 0;
  jobject v13 = NULL;
  jobject v1 = NULL;
  jlong v15 = 0;
  jobject v5 = NULL;
  jint v18 = 0;
  jint v14 = 0;
  jint v19 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︅︃", "LI/ᅟ︆︎;"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  v2 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︃", "()Z"), v1, v1, v1, v1);
  v3 = v2;
  /* UNSUPPORTED: xor-int-lit8 */
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︇︃", "Lbin/nt/ui/animation/InnerShadow;"));
  v6 = 4;
  v7 = 0;
  /* UNSUPPORTED: if-eqz */
  if (v5 == 0) { v12 = (jint)v6; v13 = (jobject)v0; v14 = (jint)v4; goto L_19;
 } else { goto L_11;
 }

L_11:
  /* UNSUPPORTED: if-eqz */
  if (v4 == 0) { goto L_15;
 } else { goto L_13;
 }

L_13:
  v8 = 0;
  /* UNSUPPORTED: goto */
v10 = (jint)v8; goto L_16;

L_15:
  v9 = 4;
v10 = (jint)v9; goto L_16;

L_16:
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v10, v4, v4, v4);
v12 = (jint)(intptr_t)v15; v13 = (jobject)(intptr_t)v16; v14 = (jint)(intptr_t)v17; goto L_19;

L_19:
  v11 = (jobject)env->GetObjectField((jobject)(intptr_t)v13, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︈︃", "Lbin/nt/ui/animation/InnerShadow;"));
  /* UNSUPPORTED: if-eqz */
  if (v11 == 0) { goto L_24;
 } else { goto L_1d;
 }

L_1d:
  /* UNSUPPORTED: if-eqz */
  if (v14 == 0) { goto L_20;
 } else { goto L_1f;
 }

L_1f:
  /* UNSUPPORTED: goto */
v19 = (jint)v12; goto L_21;

L_20:
  v18 = 0;
v19 = (jint)v18; goto L_21;

L_21:
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v19, v14, v14, v14);
goto L_24;

L_24:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︌︃()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0c_0fe03__ */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︌︄(ILjava/lang/String;)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0c_0fe04__ILjava_lang_String_2(JNIEnv* env, jobject thiz, jint p0, jobject p1) {
  jthrowable pendingException = NULL;
  jint v6 = 0;
  jobject v8 = NULL;
  jint v18 = 0;
  jobject v0 = NULL;
  jint v11 = 0;
  jboolean v25 = 0;
  jobject v2 = NULL;
  jobject v21 = NULL;
  jboolean v26 = 0;
  jint v10 = 0;
  jint v28 = 0;
  jobject v4 = NULL;
  jobject v12 = NULL;
  jarray v13 = NULL;
  jint v29 = 0;
  jlong v15 = 0;
  jlong v14 = 0;
  jobject v20 = NULL;
  jarray v3 = NULL;
  jint v17 = 0;
  jboolean v24 = 0;
  jlong v30 = 0;
  jlong v16 = 0;
  jint v9 = 0;
  jobject v27 = NULL;
  jobject v5 = NULL;
  jint v7 = 0;
  jint v19 = 0;
  jobject v22 = NULL;
  jint v1 = 0;
  jint v23 = 0;

L_0:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v4 = (jobject)env->GetObjectArrayElement((jobjectArray)v3, (jsize)(intptr_t)v1);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︂︀", "Ljava/util/ArrayList;"));
v11 = (jint)v1; v12 = (jobject)v5; v13 = (jarray)v3; goto L_6;

L_6:
  v6 = (jint)(intptr_t)env->CallIntMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v13, v13, v13, v13);
  v7 = v6;
  v8 = (jobject)env->GetObjectArrayElement((jobjectArray)v13, (jsize)(intptr_t)v11);
  v9 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  /* UNSUPPORTED: add-int-lit8 */
  /* UNSUPPORTED: if-le */
  if (v7 <= v10) { goto L_1c;
 } else { goto L_12;
 }

L_12:
  v17 = (jint)(intptr_t)env->CallIntMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v13, v13, v13, v13);
  v18 = v17;
  /* UNSUPPORTED: add-int-lit8 */
  v20 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "remove", "(I)Ljava/lang/Object;"), v19, v13, v13, v13);
  /* UNSUPPORTED: goto */
v11 = (jint)(intptr_t)v14; v12 = (jobject)(intptr_t)v15; v13 = (jarray)(intptr_t)v16; goto L_6;

L_1c:
  /* UNSUPPORTED: if-ltz */
  if (v9 < 0) { goto L_2b;
 } else { goto L_1e;
 }

L_1e:
  v21 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "get", "(I)Ljava/lang/Object;"), v9, v13, v13, v13);
  v22 = v21;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/String"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v24 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v23, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v2, v13, v13, v13);
  v25 = v24;
  /* UNSUPPORTED: if-eqz */
  if (v25 == 0) { goto L_2b;
 } else { goto L_2a;
 }

L_2a:
  /* return terminator */
  return;

L_2b:
  v26 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "add", "(Ljava/lang/Object;)Z"), v30, v13, v13, v13);
  v27 = (jobject)env->GetObjectArrayElement((jobjectArray)v13, (jsize)(intptr_t)v27);
  v28 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v27, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  /* UNSUPPORTED: add-int-lit8 */
  env->SetIntField((jobject)(intptr_t)v27, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"), v29);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︌︄(ILjava/lang/String;)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0c_0fe04__ILjava_lang_String_2 */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︍︃(ILjava/util/List;)V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0d_0fe03__ILjava_util_List_2(JNIEnv* env, jobject thiz, jint p0, jobject p1) {
  jthrowable pendingException = NULL;
  jboolean v27 = 0;
  jlong v21 = 0;
  jlong v18 = 0;
  jlong v13 = 0;
  jlong v16 = 0;
  jarray v37 = NULL;
  jlong v28 = 0;
  jboolean v6 = 0;
  jlong v12 = 0;
  jboolean v7 = 0;
  jlong v29 = 0;
  jobject v3 = NULL;
  jlong v19 = 0;
  jobject v22 = NULL;
  jobject v43 = NULL;
  jobject v0 = NULL;
  jobject v34 = NULL;
  jobject v5 = NULL;
  jobject v8 = NULL;
  jobject v2 = NULL;
  jobject v23 = NULL;
  jarray v41 = NULL;
  jobject v11 = NULL;
  jobject v39 = NULL;
  jobject v4 = NULL;
  jobject v38 = NULL;
  jobject v40 = NULL;
  jlong v14 = 0;
  jobject v9 = NULL;
  jint v10 = 0;
  jlong v17 = 0;
  jint v32 = 0;
  jint v24 = 0;
  jboolean v26 = 0;
  jobject v42 = NULL;
  jobject v35 = NULL;
  jint v33 = 0;
  jobject v44 = NULL;
  jarray v36 = NULL;
  jint v1 = 0;
  jboolean v25 = 0;
  jarray v31 = NULL;
  jlong v15 = 0;
  jlong v20 = 0;
  jint v30 = 0;

L_0:
  v3 = env->AllocObject(env->FindClass("java/util/HashMap"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("java/util/HashMap"), "<init>", "()V"), v3, v3, v3, v3);
  v4 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/util/List"), "iterator", "()Ljava/util/Iterator;"), v3, v3, v3, v3);
  v5 = v4;
v8 = (jobject)v0; v9 = (jobject)v5; v10 = (jint)v1; v11 = (jobject)v3; goto L_9;

L_9:
  v6 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v9, env->GetMethodID(env->FindClass("java/util/Iterator"), "hasNext", "()Z"), v11, v11, v11, v11);
  v7 = v6;
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_33;
 } else { goto L_f;
 }

L_f:
  v22 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("java/util/Iterator"), "next", "()Ljava/lang/Object;"), v11, v11, v11, v11);
  v23 = v22;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅟ︎︎"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v25 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v24, env->GetMethodID(env->FindClass("I/ᅟ︎︎"), "ᅟ︀︀", "()Z"), v11, v11, v11, v11);
  v26 = v25;
  /* UNSUPPORTED: if-nez */
  if (v26 != 0) { v8 = (jobject)v8; v9 = (jobject)(intptr_t)v14; v10 = (jint)v10; v11 = (jobject)(intptr_t)v19; goto L_9;
 } else { goto L_1b;
 }

L_1b:
  v27 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︃︀", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v27 == 0) { goto L_20;
 } else { goto L_1f;
 }

L_1f:
  /* UNSUPPORTED: goto */
v8 = (jobject)(intptr_t)v12; v9 = (jobject)(intptr_t)v15; v10 = (jint)(intptr_t)v17; v11 = (jobject)(intptr_t)v20; goto L_9;

L_20:
  v28 = (jlong)(intptr_t)env->GetLongField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︂︀", "J"));
  v29 = (jlong)(intptr_t)env->GetLongField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︄︀", "J"));
  v30 = 2;
  v31 = env->NewLongArray((jsize)(intptr_t)v31);
  v32 = 0;
  env->SetLongArrayRegion((jlongArray)v31, (jsize)(intptr_t)v32, 1, (jlong*)&v28);
  v33 = 1;
  env->SetLongArrayRegion((jlongArray)v31, (jsize)(intptr_t)v33, 1, (jlong*)&v29);
  v34 = (jobject)env->GetObjectField((jobject)(intptr_t)v34, env->GetFieldID(env->FindClass("I/ᅟ︎︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v35 = (jobject)env->CallObjectMethod((jobject)v19, env->GetMethodID(env->FindClass("java/util/HashMap"), "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;"), v34, v31, v19, v19);
  /* UNSUPPORTED: goto */
v8 = (jobject)(intptr_t)v13; v9 = (jobject)(intptr_t)v16; v10 = (jint)(intptr_t)v18; v11 = (jobject)(intptr_t)v21; goto L_9;

L_33:
  v36 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︊︃", "[Ljava/util/Map;"));
  env->SetObjectArrayElement((jobjectArray)v36, (jsize)v10, (jobject)(intptr_t)v11);
  v37 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︃", "[Ljava/util/Set;"));
  v38 = (jobject)env->GetObjectArrayElement((jobjectArray)v37, (jsize)(intptr_t)v10);
  /* UNSUPPORTED: if-nez */
  if (v38 != 0) { goto L_44;
 } else { goto L_3d;
 }

L_3d:
  v39 = env->AllocObject(env->FindClass("java/util/HashSet"));
  env->CallVoidMethod((jobject)v39, env->GetMethodID(env->FindClass("java/util/HashSet"), "<init>", "()V"), v39, v39, v39, v39);
  env->SetObjectArrayElement((jobjectArray)v37, (jsize)v10, (jobject)(intptr_t)v39);
goto L_44;

L_44:
  v40 = (jobject)env->GetObjectArrayElement((jobjectArray)v37, (jsize)(intptr_t)v10);
  env->CallVoidMethod((jobject)v40, env->GetMethodID(env->FindClass("java/util/Set"), "clear", "()V"), v40, v40, v40, v40);
  v41 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v42 = (jobject)env->GetObjectArrayElement((jobjectArray)v42, (jsize)(intptr_t)v10);
  v43 = (jobject)env->GetObjectField((jobject)(intptr_t)v43, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︁︀", "LI/ᅟ︁︍;"));
  v44 = (jobject)env->GetObjectArrayElement((jobjectArray)v37, (jsize)(intptr_t)v44);
  env->CallVoidMethod((jobject)v43, env->GetMethodID(env->FindClass("I/ᅟ︁︍"), "ᅟ︇︁", "(Ljava/util/Set;)V"), v44, v43, v43, v43);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︍︃(ILjava/util/List;)V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0d_0fe03__ILjava_util_List_2 */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ︍︄()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0d_0fe04__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v1 = 0;
  jint v2 = 0;
  jint v3 = 0;

L_0:
  v1 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︎︄", "I"), v1);
  v2 = 100;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ️︄", "I"), v2);
  v3 = 0;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︀︅", "Ljava/lang/String;"), (jobject)(intptr_t)v3);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︍︄()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0d_0fe04__ */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ︎︁(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/fragments/FileBrowserFragment;->ᅟ️︁(Landroid/view/LayoutInflater;Landroid/view/ViewGroup;Landroid/os/Bundle;)Landroid/view/View;: java.lang.IllegalStateException: unknown phi type v3_4 = phi[v3_7 = phi[v3_0, v3_0], v3_9 = phi[v3_7 = phi[v3_0, v3_0]]] */

/* Lbin/nt/fragments/FileBrowserFragment;->ᅟ️︃()V */
void Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0f_0fe03__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v5 = 0;
  jint v6 = 0;
  jobject v1 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jobject v4 = NULL;
  jobject v7 = NULL;
  jobject v0 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_18;
 } else { goto L_4;
 }

L_4:
  v2 = env->AllocObject(env->FindClass("I/ᅠ︋︃"));
  v3 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v2, v2, v2, v2);
  v4 = v3;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅠ︋︃"), "<init>", "(Landroid/content/Context;)V"), v4, v2, v2, v2);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︄", "LI/ᅠ︋︃;"), (jobject)(intptr_t)v2);
  v5 = 1;
  env->SetBooleanField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︋︃"), "ᅟ︎︀", "Z"), v5);
  v6 = 0;
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅠ︋︃"), "ᅟ︌︀", "Landroid/widget/TextView;"));
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v6, v7, v7, v7);
goto L_18;

L_18:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ️︃()V -> Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0f_0fe03__ */

/* FAILED Lbin/nt/fragments/PreferenceFragment;-><clinit>()V: java.lang.IllegalStateException: unknown phi type vResult_0 = phi[] */

/* FAILED Lbin/nt/fragments/PreferenceFragment;-><init>()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/fragments/PreferenceFragment;->ᅟ︀︂()V */
void Java_bin_nt_fragments_PreferenceFragment__0115f_0fe00_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v2 = NULL;
  jint v3 = 0;
  jint v1 = 0;

L_0:
  v1 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︁︂", "Z"), v1);
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/PreferenceFragment"), "ᅟ︎︃", "LI/ᅠ︍︄;"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_b;
 } else { goto L_7;
 }

L_7:
  v3 = 0;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/os/Handler"), "removeCallbacksAndMessages", "(Ljava/lang/Object;)V"), v3, v2, v2, v2);
goto L_b;

L_b:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︀︂()V -> Java_bin_nt_fragments_PreferenceFragment__0115f_0fe00_0fe02__ */

/* FAILED Lbin/nt/fragments/PreferenceFragment;->ᅟ︊︃(Ljava/lang/String;)V: java.lang.IllegalStateException: unknown phi type v4_5 = phi[v4_1 = phi[v4_0, v4_0], v4_7 = phi[v4_11 = phi[v4_1 = phi[v4_0, v4_0], v4_1 = phi[v4_0, v4_0]]]] */

/* Lbin/nt/fragments/PreferenceFragment;->ᅟ︌︃(Landroidx/preference/Preference;)V */
void Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0c_0fe03__Landroidx_preference_Preference_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v17 = NULL;
  jobject v19 = NULL;
  jobject v16 = NULL;
  jobject v5 = NULL;
  jobject v2 = NULL;
  jobject v4 = NULL;
  jobject v6 = NULL;
  jobject v1 = NULL;
  jobject v9 = NULL;
  jint v18 = 0;
  jobject v7 = NULL;
  jobject v0 = NULL;
  jarray v12 = NULL;
  jint v13 = 0;
  jobject v8 = NULL;
  jboolean v10 = 0;
  jobject v14 = NULL;
  jint v15 = 0;
  jobject v3 = NULL;
  jboolean v11 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/PreferenceFragment"), "ᅟ︍︃", "Landroid/content/Context;"));
  v3 = (jobject)env->CallStaticObjectMethod(env->FindClass("androidx/preference/PreferenceManager"), env->GetStaticMethodID(env->FindClass("androidx/preference/PreferenceManager"), "ᅟ︀︀", "(Landroid/content/Context;)Landroid/content/SharedPreferences;"), v2, v2, v2, v2, v2);
  v4 = v3;
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("androidx/preference/Preference"), "ᅟ︎︀", "Ljava/lang/String;"));
  v6 = env->NewStringUTF("home");
  v7 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"), v5, v6, v4, v4);
  v8 = v7;
  v9 = env->NewStringUTF("last");
  v10 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v9, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v8, v8, v8, v8);
  v11 = v10;
  v12 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/fragments/PreferenceFragment"), env->GetStaticFieldID(env->FindClass("bin/nt/fragments/PreferenceFragment"), "ᅟ︀︄", "[Ljava/lang/String;"));
  /* UNSUPPORTED: if-eqz */
  if (v11 == 0) { goto L_1c;
 } else { goto L_18;
 }

L_18:
  v13 = 1;
  v14 = (jobject)env->GetObjectArrayElement((jobjectArray)v12, (jsize)(intptr_t)v14);
  /* UNSUPPORTED: goto */
v19 = (jobject)v14; goto L_1f;

L_1c:
  v15 = 0;
  v16 = (jobject)env->GetObjectArrayElement((jobjectArray)v12, (jsize)(intptr_t)v16);
v19 = (jobject)v16; goto L_1f;

L_1f:
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("androidx/preference/Preference"), "ᅟ︈︁", "(Ljava/lang/CharSequence;)V"), v19, v19, v19, v19);
  v17 = env->AllocObject(env->FindClass("I/ᅠ︋︄"));
  v18 = 1;
  env->CallVoidMethod((jobject)v17, env->GetMethodID(env->FindClass("I/ᅠ︋︄"), "<init>", "(Lbin/nt/fragments/PreferenceFragment;Landroidx/preference/Preference;I)V"), v0, v1, v18, v17);
  env->SetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("androidx/preference/Preference"), "ᅟ︈︀", "Landroidx/preference/Preference$OnPreferenceClickListener;"), (jobject)(intptr_t)v17);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︌︃(Landroidx/preference/Preference;)V -> Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0c_0fe03__Landroidx_preference_Preference_2 */

/* Lbin/nt/fragments/PreferenceFragment;->ᅟ︎︁(Landroid/os/Bundle;)V */
void Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0e_0fe01__Landroid_os_Bundle_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v4 = NULL;
  jint v6 = 0;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v2 = NULL;
  jint v5 = 0;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/preference/PreferenceFragmentCompat"), "ᅟ︎︁", "(Landroid/os/Bundle;)V"), v1, v0, v0, v0);
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︄︃", "()Landroid/content/Context;"), v0, v0, v0, v0);
  v3 = v2;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/PreferenceFragment"), "ᅟ︍︃", "Landroid/content/Context;"), (jobject)(intptr_t)v3);
  v4 = env->AllocObject(env->FindClass("I/ᅠ︍︄"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅠ︍︄"), "<init>", "(Lbin/nt/fragments/PreferenceFragment;)V"), v0, v0, v0, v0);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/PreferenceFragment"), "ᅟ︎︃", "LI/ᅠ︍︄;"), (jobject)(intptr_t)v4);
  v5 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︋︀", "()I"), v0, v0, v0, v0, v0);
  v6 = v5;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/fragments/PreferenceFragment"), "ᅟ️︃", "I"), v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︎︁(Landroid/os/Bundle;)V -> Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0e_0fe01__Landroid_os_Bundle_2 */

/* Lbin/nt/fragments/PreferenceFragment;->ᅟ️︁(Landroid/view/LayoutInflater;Landroid/view/ViewGroup;Landroid/os/Bundle;)Landroid/view/View; */
jobject Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0f_0fe01__Landroid_view_LayoutInflater_2Landroid_view_ViewGroup_2Landroid_os_Bundle_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1, jobject p2) {
  jthrowable pendingException = NULL;
  jobject v6 = NULL;
  jobject v9 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v5 = NULL;
  jobject v8 = NULL;
  jobject v7 = NULL;
  jobject v1 = NULL;
  jobject v12 = NULL;
  jobject v10 = NULL;
  jobject v11 = NULL;
  jobject v4 = NULL;

L_0:
  v4 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/preference/PreferenceFragmentCompat"), "ᅟ️︁", "(Landroid/view/LayoutInflater;Landroid/view/ViewGroup;Landroid/os/Bundle;)Landroid/view/View;"), v1, v2, v3, v0);
  v5 = v4;
goto L_4;

L_4:
  v6 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/Fragment"), "ᅟ︃︃", "()Landroidx/fragment/app/FragmentActivity;"), v0, v0, v0, v0); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_1; }
  v7 = v6;
  v8 = (jobject)env->CallObjectMethod((jobject)v7, env->GetMethodID(env->FindClass("android/content/Context"), "getAssets", "()Landroid/content/res/AssetManager;"), v0, v0, v0, v0); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_1; }
  v9 = v8;
  v10 = env->NewStringUTF("MaterialIcons-Regular.ttf");
  v11 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/graphics/Typeface"), env->GetStaticMethodID(env->FindClass("android/graphics/Typeface"), "createFromAsset", "(Landroid/content/res/AssetManager;Ljava/lang/String;)Landroid/graphics/Typeface;"), v9, v10, v0, v0, v0); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_1; }
goto L_11;

L_12:
  v12 = (jobject)env->GetStaticObjectField(env->FindClass("android/graphics/Typeface"), env->GetStaticFieldID(env->FindClass("android/graphics/Typeface"), "DEFAULT", "Landroid/graphics/Typeface;"));
goto L_14;

L_11:
  /* UNSUPPORTED: goto */
goto L_14;

L_14:
  /* return terminator */
  return (jobject)(intptr_t)v5;

EX_LandingPad_1:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_12;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ️︁(Landroid/view/LayoutInflater;Landroid/view/ViewGroup;Landroid/os/Bundle;)Landroid/view/View; -> Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0f_0fe01__Landroid_view_LayoutInflater_2Landroid_view_ViewGroup_2Landroid_os_Bundle_2 */

/* Lbin/nt/main/EditorPreferencesActivity$EditorPreferenceFragment;-><init>()V */
void Java_bin_nt_main_EditorPreferencesActivity_00024EditorPreferenceFragment__0003cinit_0003e__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/preference/PreferenceFragmentCompat"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>()V -> Java_bin_nt_main_EditorPreferencesActivity_00024EditorPreferenceFragment__0003cinit_0003e__ */

/* Lbin/nt/main/EditorPreferencesActivity$EditorPreferenceFragment;->ᅟ︊︃(Ljava/lang/String;)V */
void Java_bin_nt_main_EditorPreferencesActivity_00024EditorPreferenceFragment__0115f_0fe0a_0fe03__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jint v2 = 0;

L_0:
  v2 = 2132082690;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/preference/PreferenceFragmentCompat"), "ᅟ︋︃", "(ILjava/lang/String;)V"), v2, v1, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︊︃(Ljava/lang/String;)V -> Java_bin_nt_main_EditorPreferencesActivity_00024EditorPreferenceFragment__0115f_0fe0a_0fe03__Ljava_lang_String_2 */

/* Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;-><init>(Landroid/content/Context;Landroid/util/AttributeSet;)V */
void Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2(JNIEnv* env, jobject thiz, jobject p0, jobject p1) {
  jthrowable pendingException = NULL;
  jobject v11 = NULL;
  jfloat v17 = 0;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jint v3 = 0;
  jobject v10 = NULL;
  jint v6 = 0;
  jobject v1 = NULL;
  jlong v27 = 0;
  jobject v16 = NULL;
  jint v21 = 0;
  jobject v13 = NULL;
  jlong v28 = 0;
  jobject v14 = NULL;
  jobject v26 = NULL;
  jfloat v20 = 0;
  jobject v2 = NULL;
  jint v5 = 0;
  jint v9 = 0;
  jlong v7 = 0;
  jint v19 = 0;
  jobject v15 = NULL;
  jint v8 = 0;
  jint v18 = 0;
  jfloat v22 = 0;
  jobject v12 = NULL;
  jobject v24 = NULL;
  jobject v25 = NULL;
  jobject v23 = NULL;

L_0:
  v3 = 0;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V"), v1, v2, v3, v3);
  v4 = env->AllocObject(env->FindClass("I/ᅟ︊︂"));
  v5 = 1;
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("I/ᅟ︊︂"), "<init>", "(ILjava/lang/Object;)V"), v5, v0, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ️︅", "LI/ᅟ︊︂;"), (jobject)(intptr_t)v4);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︀︆", "Z"), v3);
  v6 = -1;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︁︆", "I"), v6);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︂︆", "Z"), v3);
  v7 = 0;
  env->SetLongField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︃︆", "J"), v7);
  v8 = 0;
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︅︆", "F"), v8);
  v9 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︆︆", "Z"), v9);
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︇︆", "Z"), v9);
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︉︆", "I"), v6);
  v10 = env->AllocObject(env->FindClass("I/ᅟ︍︌"));
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("I/ᅟ︍︌"), "<init>", "(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V"), v0, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︊︆", "LI/ᅟ︍︌;"), (jobject)(intptr_t)v10);
  v11 = env->AllocObject(env->FindClass("android/graphics/RectF"));
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("android/graphics/RectF"), "<init>", "()V"), v3, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︍︅", "Landroid/graphics/RectF;"), (jobject)(intptr_t)v11);
  v12 = env->AllocObject(env->FindClass("android/graphics/Paint"));
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/graphics/Paint"), "<init>", "(I)V"), v9, v3, v3, v3);
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︌︅", "Landroid/graphics/Paint;"), (jobject)(intptr_t)v12);
  v13 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v3, v3, v3, v3);
  v14 = v13;
  v15 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v3, v3, v3, v3);
  v16 = v15;
  v17 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("android/util/DisplayMetrics"), "density", "F"));
  v18 = -580491674;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︋︅", "I"), v18);
  v19 = 1090519040;
  /* UNSUPPORTED: mul-float */
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︊︅", "F"), v20);
  v21 = 1112539136;
  /* UNSUPPORTED: mul-float */
  env->SetFloatField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︎︅", "F"), v22);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "setWillNotDraw", "(Z)V"), v3, v3, v3, v3);
  v23 = env->AllocObject(env->FindClass("I/ᅟ︎︌"));
  env->CallVoidMethod((jobject)v23, env->GetMethodID(env->FindClass("I/ᅟ︎︌"), "<init>", "(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V"), v0, v3, v3, v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "ᅟ︉︀", "(Landroidx/recyclerview/widget/RecyclerView$OnScrollListener;)V"), v23, v3, v3, v3);
  v24 = env->AllocObject(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"));
  env->CallVoidMethod((jobject)v24, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"), "<init>", "(I)V"), v9, v3, v3, v3);
  env->SetBooleanField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"), "ᅟ︆︁", "Z"), v3);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "setLayoutManager", "(Landroidx/recyclerview/widget/RecyclerView$LayoutManager;)V"), v24, v3, v3, v3);
  v25 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "getItemAnimator", "()Landroidx/recyclerview/widget/RecyclerView$ItemAnimator;"), v3, v3, v3, v3);
  v26 = v25;
  /* UNSUPPORTED: if-eqz */
  if (v26 == 0) { goto L_78;
 } else { goto L_6c;
 }

L_6c:
  v27 = 100;
  env->SetLongField((jobject)(intptr_t)v26, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/RecyclerView$ItemAnimator"), "ᅟ︂︀", "J"), v27);
  env->SetLongField((jobject)(intptr_t)v26, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/RecyclerView$ItemAnimator"), "ᅟ︃︀", "J"), v27);
  v28 = 200;
  env->SetLongField((jobject)(intptr_t)v26, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/RecyclerView$ItemAnimator"), "ᅟ︄︀", "J"), v28);
  env->SetLongField((jobject)(intptr_t)v26, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/RecyclerView$ItemAnimator"), "ᅟ︅︀", "J"), v27);
goto L_78;

L_78:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>(Landroid/content/Context;Landroid/util/AttributeSet;)V -> Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2 */

/* FAILED Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;->dispatchDraw(Landroid/graphics/Canvas;)V: java.lang.IllegalStateException: unknown phi type v4_10 = phi[v4_13 = phi[v4_0, v4_0], v4_15 = phi[v4_13 = phi[v4_0, v4_0], v4_13 = phi[v4_0, v4_0]]] */

/* Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;->onInterceptTouchEvent(Landroid/view/MotionEvent;)Z */
jboolean Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_onInterceptTouchEvent__Landroid_view_MotionEvent_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jboolean v45 = 0;
  jobject v1 = NULL;
  jobject v17 = NULL;
  jint v20 = 0;
  jobject v25 = NULL;
  jobject v16 = NULL;
  jboolean v2 = 0;
  jfloat v8 = 0;
  jint v12 = 0;
  jobject v13 = NULL;
  jobject v38 = NULL;
  jboolean v47 = 0;
  jobject v18 = NULL;
  jfloat v32 = 0;
  jboolean v10 = 0;
  jfloat v28 = 0;
  jlong v44 = 0;
  jobject v5 = NULL;
  jobject v14 = NULL;
  jboolean v37 = 0;
  jfloat v35 = 0;
  jint v4 = 0;
  jint v19 = 0;
  jfloat v33 = 0;
  jint v15 = 0;
  jobject v24 = NULL;
  jint v21 = 0;
  jobject v22 = NULL;
  jlong v41 = 0;
  jlong v50 = 0;
  jobject v0 = NULL;
  jobject v27 = NULL;
  jobject v48 = NULL;
  jfloat v34 = 0;
  jfloat v7 = 0;
  jobject v26 = NULL;
  jint v30 = 0;
  jobject v23 = NULL;
  jboolean v46 = 0;
  jboolean v11 = 0;
  jfloat v29 = 0;
  jobject v43 = NULL;
  jfloat v9 = 0;
  jfloat v31 = 0;
  jobject v39 = NULL;
  jobject v36 = NULL;
  jlong v40 = 0;
  jobject v49 = NULL;
  jint v3 = 0;
  jfloat v6 = 0;
  jobject v42 = NULL;

L_0:
  v2 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︂︆", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { v47 = (jboolean)v2; v48 = (jobject)v1; v49 = (jobject)v0; goto L_69;
 } else { goto L_4;
 }

L_4:
  v3 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("android/view/MotionEvent"), "getAction", "()I"), v2, v2, v2, v2);
  v4 = v3;
  /* UNSUPPORTED: if-nez */
  if (v4 != 0) { v47 = (jboolean)v2; v48 = (jobject)v1; v49 = (jobject)v0; goto L_69;
 } else { goto L_a;
 }

L_a:
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︍︅", "Landroid/graphics/RectF;"));
  v6 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v1, env->GetMethodID(env->FindClass("android/view/MotionEvent"), "getX", "()F"), v5, v5, v5, v5);
  v7 = v6;
  v8 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v1, env->GetMethodID(env->FindClass("android/view/MotionEvent"), "getY", "()F"), v5, v5, v5, v5);
  v9 = v8;
  v10 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v5, env->GetMethodID(env->FindClass("android/graphics/RectF"), "contains", "(FF)Z"), v7, v9, v5, v5);
  v11 = v10;
  /* UNSUPPORTED: if-eqz */
  if (v11 == 0) { v47 = (jboolean)(intptr_t)v50; v48 = (jobject)(intptr_t)v41; v49 = (jobject)(intptr_t)v40; goto L_69;
 } else { goto L_1a;
 }

L_1a:
  v12 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︀︆", "Z"), v12);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "ᅟ︁︄", "()V"), v5, v5, v5, v5);
  v13 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "getItemAnimator", "()Landroidx/recyclerview/widget/RecyclerView$ItemAnimator;"), v5, v5, v5, v5);
  v14 = v13;
  env->SetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︈︆", "Landroidx/recyclerview/widget/RecyclerView$ItemAnimator;"), (jobject)(intptr_t)v14);
  v15 = 0;
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "setItemAnimator", "(Landroidx/recyclerview/widget/RecyclerView$ItemAnimator;)V"), v15, v5, v5, v5);
  v16 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "getLayoutManager", "()Landroidx/recyclerview/widget/RecyclerView$LayoutManager;"), v5, v5, v5, v5);
  v17 = v16;
  v18 = (jobject)(v0 && env->IsInstanceOf((jobject)v0, env->FindClass("androidx/recyclerview/widget/LinearLayoutManager")) ? 1 : 0);
  /* UNSUPPORTED: if-eqz */
  if (v18 == 0) { goto L_3a;
 } else { goto L_32;
 }

L_32:
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v20 = (jint)(intptr_t)env->CallIntMethod((jobject)v19, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"), "ᅟ︀︆", "()I"), v5, v5, v5, v5);
  v21 = v20;
  env->SetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︁︆", "I"), v21);
goto L_3a;

L_3a:
  v22 = (jobject)env->CallObjectMethod((jobject)v40, env->GetMethodID(env->FindClass("android/view/View"), "getContext", "()Landroid/content/Context;"), v5, v5, v5, v5);
  v23 = (jobject)(intptr_t)v22;
  v24 = (jobject)env->CallObjectMethod((jobject)v23, env->GetMethodID(env->FindClass("android/content/Context"), "getResources", "()Landroid/content/res/Resources;"), v5, v5, v5, v5);
  v25 = v24;
  v26 = (jobject)env->CallObjectMethod((jobject)v25, env->GetMethodID(env->FindClass("android/content/res/Resources"), "getDisplayMetrics", "()Landroid/util/DisplayMetrics;"), v5, v5, v5, v5);
  v27 = v26;
  v28 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v28, env->GetFieldID(env->FindClass("android/util/DisplayMetrics"), "density", "F"));
  v29 = (jfloat)(intptr_t)env->GetFloatField((jobject)(intptr_t)v29, env->GetFieldID(env->FindClass("android/graphics/RectF"), "top", "F"));
  v30 = 1094713344;
  /* UNSUPPORTED: mul-float */
  /* UNSUPPORTED: add-float-2addr */
  v33 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v41, env->GetMethodID(env->FindClass("android/view/MotionEvent"), "getY", "()F"), v29, v29, v29, v29);
  v34 = v33;
  /* UNSUPPORTED: sub-float-2addr */
  env->SetFloatField((jobject)(intptr_t)v40, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︄︆", "F"), v35);
  v36 = (jobject)env->GetObjectField((jobject)(intptr_t)v40, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ️︅", "LI/ᅟ︊︂;"));
  v37 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v40, env->GetMethodID(env->FindClass("android/view/View"), "removeCallbacks", "(Ljava/lang/Runnable;)Z"), v36, v29, v29, v29);
  v38 = (jobject)env->CallObjectMethod((jobject)v40, env->GetMethodID(env->FindClass("android/view/View"), "getParent", "()Landroid/view/ViewParent;"), v29, v29, v29, v29);
  v39 = (jobject)(intptr_t)v38;
  /* UNSUPPORTED: if-eqz */
  if (v39 == 0) { goto L_68;
 } else { goto L_61;
 }

L_61:
  v42 = (jobject)env->CallObjectMethod((jobject)v40, env->GetMethodID(env->FindClass("android/view/View"), "getParent", "()Landroid/view/ViewParent;"), v29, v29, v29, v29);
  v43 = (jobject)(intptr_t)v42;
  env->CallVoidMethod((jobject)v43, env->GetMethodID(env->FindClass("android/view/ViewParent"), "requestDisallowInterceptTouchEvent", "(Z)V"), v12, v29, v29, v29);
goto L_68;

L_68:
  /* return terminator */
  return (jboolean)(intptr_t)v44;

L_69:
  v45 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v49, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "onInterceptTouchEvent", "(Landroid/view/MotionEvent;)Z"), v48, v47, v47, v47);
  v46 = v45;
  /* return terminator */
  return (jboolean)(intptr_t)v46;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for onInterceptTouchEvent(Landroid/view/MotionEvent;)Z -> Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_onInterceptTouchEvent__Landroid_view_MotionEvent_2 */

/* FAILED Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;->onTouchEvent(Landroid/view/MotionEvent;)Z: java.lang.IllegalStateException: unknown phi type v2_1 = phi[v2_2 = phi[v2_0, v2_0], v2_2 = phi[v2_0, v2_0], v2_6 = phi[v2_2 = phi[v2_0, v2_0]]] */

/* Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;->setLayoutManager(Landroidx/recyclerview/widget/RecyclerView$LayoutManager;)V */
void Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_setLayoutManager__Landroidx_recyclerview_widget_RecyclerView_00024LayoutManager_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v3 = NULL;
  jobject v2 = NULL;
  jint v5 = 0;
  jint v4 = 0;

L_0:
  v2 = (jobject)(v0 && env->IsInstanceOf((jobject)v0, env->FindClass("androidx/recyclerview/widget/LinearLayoutManager")) ? 1 : 0);
  /* UNSUPPORTED: if-eqz */
  if (v2 == 0) { goto L_a;
 } else { goto L_4;
 }

L_4:
  /* dbg-move v3 v1 dv=Ljava/lang/Object; sv=Landroidx/recyclerview/widget/RecyclerView$LayoutManager; */
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v5 = 0;
  env->SetBooleanField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("androidx/recyclerview/widget/LinearLayoutManager"), "ᅟ︆︁", "Z"), v5);
goto L_a;

L_a:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView"), "setLayoutManager", "(Landroidx/recyclerview/widget/RecyclerView$LayoutManager;)V"), v1, v2, v2, v2);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setLayoutManager(Landroidx/recyclerview/widget/RecyclerView$LayoutManager;)V -> Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_setLayoutManager__Landroidx_recyclerview_widget_RecyclerView_00024LayoutManager_2 */

/* Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;->setTrackVisible(Z)V */
void Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_setTrackVisible__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jboolean v1 = 0;
  jobject v0 = NULL;

L_0:
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView"), "ᅟ︇︆", "Z"), v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/view/View"), "invalidate", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for setTrackVisible(Z)V -> Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_setTrackVisible__Z */

/* FAILED Lbin/nt/main/BaseActivity;-><init>()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/BaseActivity;->onCreate(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/BaseActivity;->ᅟ︅︁()V */
void Java_bin_nt_main_BaseActivity__0115f_0fe05_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︁()V -> Java_bin_nt_main_BaseActivity__0115f_0fe05_0fe01__ */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︆︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︇︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︈︁()[Landroid/graphics/Rect;: java.lang.StackOverflowError */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︉︁(Landroid/view/View;)V: java.lang.IllegalStateException: unknown phi type v10_7 = phi[v10_5 = phi[v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_1 = phi[v10_0, v10_0]], v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_1 = phi[v10_0, v10_0]]], v10_5 = phi[v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_1 = phi[v10_0, v10_0]], v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_1 = phi[v10_0, v10_0]]], v10_9 = phi[v10_5 = phi[v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_1 = phi[v10_0, v10_0]], v10_3 = phi[v10_1 = phi[v10_0, v10_0], v10_1 = phi[v10_0, v10_0]]]]] */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︊︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︋︁(Landroidx/appcompat/widget/Toolbar;)V: java.lang.IllegalStateException: unknown phi type v0_1 = phi[] */

/* FAILED Lbin/nt/main/BaseActivity;->ᅟ︌︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/CrashActivity;-><clinit>()V */
void Java_bin_nt_main_CrashActivity__0003cclinit_0003e__(JNIEnv* env, jclass clazz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  v0 = env->NewStringUTF("Bin");
  env->CallStaticVoidMethod(env->FindClass("java/lang/System"), env->GetStaticMethodID(env->FindClass("java/lang/System"), "loadLibrary", "(Ljava/lang/String;)V"), v0, v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <clinit>()V -> Java_bin_nt_main_CrashActivity__0003cclinit_0003e__ */

/* Lbin/nt/main/CrashActivity;-><init>()V */
void Java_bin_nt_main_CrashActivity__0003cinit_0003e__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/BaseActivity"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>()V -> Java_bin_nt_main_CrashActivity__0003cinit_0003e__ */

/* FAILED Lbin/nt/main/CrashActivity;->onBackPressed()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/CrashActivity;->onCreate(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/CrashActivity;->onDestroy()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/CrashActivity;->ᅟ︅︁()V */
void Java_bin_nt_main_CrashActivity__0115f_0fe05_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v5 = NULL;
  jint v11 = 0;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jint v8 = 0;
  jobject v2 = NULL;
  jint v6 = 0;
  jint v10 = 0;
  jint v13 = 0;
  jobject v0 = NULL;
  jint v12 = 0;
  jint v9 = 0;
  jint v7 = 0;
  jint v3 = 0;
  jobject v14 = NULL;
  jobject v15 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/CrashActivity"), "ᅟ︃︂", "LI/ᅟ︌︁;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_28;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︌︁"), "ᅟ︃︀", "Landroid/widget/LinearLayout;"));
  v3 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v3, v2, v2, v2);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/CrashActivity"), "ᅟ︃︂", "LI/ᅟ︌︁;"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("I/ᅟ︌︁"), "ᅟ︆︀", "Landroid/widget/TextView;"));
  v6 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︁︁", "(Landroid/content/Context;)I"), v0, v5, v5, v5, v5);
  v7 = v6;
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextColor", "(I)V"), v7, v5, v5, v5);
  v8 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︁︁", "(Landroid/content/Context;)I"), v0, v5, v5, v5, v5);
  v9 = v8;
  v10 = 16777215;
  /* UNSUPPORTED: and-int-2addr */
  v12 = -1291845632;
  /* UNSUPPORTED: or-int-2addr */
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/CrashActivity"), "ᅟ︃︂", "LI/ᅟ︌︁;"));
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v15, env->GetFieldID(env->FindClass("I/ᅟ︌︁"), "ᅟ︅︀", "Landroid/widget/TextView;"));
  env->CallVoidMethod((jobject)v15, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextColor", "(I)V"), v13, v13, v13, v13);
goto L_28;

L_28:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︁()V -> Java_bin_nt_main_CrashActivity__0115f_0fe05_0fe01__ */

/* Lbin/nt/main/CrashActivity;->ᅟ︍︁()V */
void Java_bin_nt_main_CrashActivity__0115f_0fe0d_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jint v3 = 0;
  jobject v2 = NULL;

L_0:
  v1 = env->AllocObject(env->FindClass("android/content/Intent"));
  v2 = env->FindClass("bin/nt/main/MainActivity");
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("android/content/Intent"), "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V"), v0, v2, v1, v1);
  v3 = 268468224;
  v4 = (jobject)env->CallObjectMethod((jobject)v1, env->GetMethodID(env->FindClass("android/content/Intent"), "addFlags", "(I)Landroid/content/Intent;"), v3, v1, v1, v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "startActivity", "(Landroid/content/Intent;)V"), v1, v1, v1, v1);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Activity"), "finish", "()V"), v1, v1, v1, v1);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︍︁()V -> Java_bin_nt_main_CrashActivity__0115f_0fe0d_0fe01__ */

/* Lbin/nt/main/EditorPreferencesActivity;-><init>()V */
void Java_bin_nt_main_EditorPreferencesActivity__0003cinit_0003e__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/BaseActivity"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>()V -> Java_bin_nt_main_EditorPreferencesActivity__0003cinit_0003e__ */

/* FAILED Lbin/nt/main/EditorPreferencesActivity;->onCreate(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/MainActivity;-><init>()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/MainActivity;->ᅟ︁︂(Landroid/content/Intent;)Z */
jboolean Java_bin_nt_main_MainActivity__0115f_0fe01_0fe02__Landroid_content_Intent_2(JNIEnv* env, jclass clazz, jobject p0) {
  jthrowable pendingException = NULL;
  jboolean v8 = 0;
  jint v1 = 0;
  jobject v2 = NULL;
  jboolean v15 = 0;
  jobject v13 = NULL;
  jobject v3 = NULL;
  jint v18 = 0;
  jint v17 = 0;
  jboolean v5 = 0;
  jobject v12 = NULL;
  jobject v10 = NULL;
  jlong v19 = 0;
  jboolean v9 = 0;
  jobject v0 = NULL;
  jobject v4 = NULL;
  jboolean v16 = 0;
  jboolean v6 = 0;
  jobject v14 = NULL;
  jobject v7 = NULL;
  jobject v11 = NULL;

L_0:
  v1 = 0;
  /* UNSUPPORTED: if-nez */
  if (v0 != 0) { goto L_4;
 } else { goto L_3;
 }

L_3:
  /* return terminator */
  return (jboolean)(intptr_t)v1;

L_4:
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Intent"), "getAction", "()Ljava/lang/String;"), v1, v1, v1, v1);
  v3 = v2;
  v4 = env->NewStringUTF("android.intent.action.VIEW");
  v5 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v3, v1, v1, v1);
  v6 = v5;
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { goto L_19;
 } else { goto L_10;
 }

L_10:
  v7 = env->NewStringUTF("android.intent.action.EDIT");
  v8 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v7, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v3, v1, v1, v1);
  v9 = v8;
  /* UNSUPPORTED: if-nez */
  if (v9 != 0) { goto L_19;
 } else { goto L_18;
 }

L_18:
  /* return terminator */
  return (jboolean)(intptr_t)v1;

L_19:
  v10 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Intent"), "getData", "()Landroid/net/Uri;"), v1, v1, v1, v1);
  v11 = v10;
  /* UNSUPPORTED: if-nez */
  if (v11 != 0) { goto L_20;
 } else { goto L_1f;
 }

L_1f:
  /* return terminator */
  return (jboolean)(intptr_t)v1;

L_20:
  v12 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Intent"), "getType", "()Ljava/lang/String;"), v1, v1, v1, v1);
  v13 = v12;
  /* UNSUPPORTED: if-eqz */
  if (v13 == 0) { goto L_2e;
 } else { goto L_26;
 }

L_26:
  v14 = env->NewStringUTF("image/");
  v15 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/lang/String"), "startsWith", "(Ljava/lang/String;)Z"), v14, v1, v1, v1);
  v16 = v15;
  /* UNSUPPORTED: if-eqz */
  if (v16 == 0) { v18 = (jint)(intptr_t)v19; goto L_2f;
 } else { goto L_2e;
 }

L_2e:
  v17 = 1;
v18 = (jint)v17; goto L_2f;

L_2f:
  /* return terminator */
  return (jboolean)(intptr_t)v18;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for ᅟ︁︂(Landroid/content/Intent;)Z -> Java_bin_nt_main_MainActivity__0115f_0fe01_0fe02__Landroid_content_Intent_2 */

/* FAILED Lbin/nt/main/MainActivity;->ᅟ️︁(J)Ljava/lang/String;: java.lang.IllegalStateException: unknown phi type v6_2 = phi[] */

/* Lbin/nt/main/MainActivity;->onBackPressed()V */
void Java_bin_nt_main_MainActivity_onBackPressed__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v17 = NULL;
  jboolean v12 = 0;
  jboolean v10 = 0;
  jint v5 = 0;
  jarray v3 = NULL;
  jobject v4 = NULL;
  jlong v19 = 0;
  jlong v20 = 0;
  jlong v21 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jint v14 = 0;
  jobject v8 = NULL;
  jint v16 = 0;
  jlong v11 = 0;
  jboolean v9 = 0;
  jint v2 = 0;
  jobject v7 = NULL;
  jobject v15 = NULL;
  jobject v18 = NULL;
  jobject v6 = NULL;
  jboolean v13 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︆︂", "Lbin/nt/fragments/FileBrowserFragment;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { v17 = (jobject)v0; v18 = (jobject)v1; goto L_38;
 } else { goto L_4;
 }

L_4:
  v2 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︍︃", "I"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v1, env->GetFieldID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︆︃", "[LI/ᅟ︋︎;"));
  v4 = (jobject)env->GetObjectArrayElement((jobjectArray)v3, (jsize)(intptr_t)v4);
  v5 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︃︀", "I"));
  /* UNSUPPORTED: if-lez */
  if (v5 <= 0) { goto L_12;
 } else { goto L_e;
 }

L_e:
  env->CallVoidMethod((jobject)v1, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︁︄", "()V"), v1, v1, v1, v1);
  /* UNSUPPORTED: goto */
goto L_37;

L_12:
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"));
  v7 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︂️"), env->GetStaticMethodID(env->FindClass("I/ᅟ︂️"), "ᅟ︁︀", "(Ljava/lang/String;)Ljava/lang/String;"), v6, v1, v1, v1, v1);
  v8 = (jobject)(intptr_t)v7;
  /* UNSUPPORTED: if-eqz */
  if (v8 == 0) { v17 = (jobject)(intptr_t)v19; v18 = (jobject)(intptr_t)v11; goto L_38;
 } else { goto L_1a;
 }

L_1a:
  v9 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v8, env->GetMethodID(env->FindClass("java/lang/String"), "equals", "(Ljava/lang/Object;)Z"), v6, v11, v11, v11);
  v10 = v9;
  /* UNSUPPORTED: if-nez */
  if (v10 != 0) { v17 = (jobject)(intptr_t)v20; v18 = (jobject)(intptr_t)v21; goto L_38;
 } else { goto L_20;
 }

L_20:
  v12 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v11, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︃", "()Z"), v11, v11, v11, v11);
  v13 = v12;
  /* UNSUPPORTED: xor-int-lit8 */
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︅", "(I)V"), v14, v11, v11, v11);
  v15 = (jobject)env->GetObjectArrayElement((jobjectArray)v15, (jsize)(intptr_t)v14);
  env->SetObjectField((jobject)(intptr_t)v15, env->GetFieldID(env->FindClass("I/ᅟ︋︎"), "ᅟ︀︀", "Ljava/lang/String;"), (jobject)(intptr_t)v8);
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︌︄", "(ILjava/lang/String;)V"), v14, v8, v11, v11);
  v16 = 1;
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︃︄", "(ZZ)V"), v13, v16, v11, v11);
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︋︄", "()V"), v11, v11, v11, v11);
goto L_37;

L_37:
  /* return terminator */
  return;

L_38:
  env->CallVoidMethod((jobject)v17, env->GetMethodID(env->FindClass("androidx/activity/ComponentActivity"), "onBackPressed", "()V"), v18, v18, v18, v18);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for onBackPressed()V -> Java_bin_nt_main_MainActivity_onBackPressed__ */

/* FAILED Lbin/nt/main/MainActivity;->onConfigurationChanged(Landroid/content/res/Configuration;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/MainActivity;->onCreate(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_28 = phi[v0_4 = phi[v0_3 = phi[v0_0]], v0_30 = phi[v0_4 = phi[v0_3 = phi[v0_0]], v0_4 = phi[v0_3 = phi[v0_0]]]] */

/* FAILED Lbin/nt/main/MainActivity;->onDestroy()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/MainActivity;->onNewIntent(Landroid/content/Intent;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/MainActivity;->onResume()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/MainActivity;->ᅟ︀︂(Landroid/view/MenuItem;)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/MainActivity;->ᅟ︂︂()V */
void Java_bin_nt_main_MainActivity__0115f_0fe02_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v4 = 0;
  jobject v1 = NULL;
  jobject v8 = NULL;
  jobject v12 = NULL;
  jobject v10 = NULL;
  jobject v14 = NULL;
  jobject v3 = NULL;
  jobject v13 = NULL;
  jobject v9 = NULL;
  jboolean v17 = 0;
  jobject v7 = NULL;
  jobject v11 = NULL;
  jboolean v18 = 0;
  jobject v5 = NULL;
  jint v20 = 0;
  jobject v6 = NULL;
  jboolean v15 = 0;
  jobject v16 = NULL;
  jint v19 = 0;
  jobject v0 = NULL;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︊︂", "LI/ᅠ︀︇;"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  v2 = (jobject)env->CallStaticObjectMethod(env->FindClass("androidx/preference/PreferenceManager"), env->GetStaticMethodID(env->FindClass("androidx/preference/PreferenceManager"), "ᅟ︁︀", "(Landroid/content/Context;)Ljava/lang/String;"), v0, v1, v1, v1, v1);
  v3 = v2;
  v4 = 0;
  v5 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "getSharedPreferences", "(Ljava/lang/String;I)Landroid/content/SharedPreferences;"), v3, v4, v3, v3);
  v6 = v5;
  v7 = env->NewStringUTF("bookmark_paths");
  v8 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/util/Collections"), env->GetStaticMethodID(env->FindClass("java/util/Collections"), "emptySet", "()Ljava/util/Set;"), v6, v6, v6, v6, v6);
  v9 = v8;
  v10 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getStringSet", "(Ljava/lang/String;Ljava/util/Set;)Ljava/util/Set;"), v7, v9, v6, v6);
  v11 = v10;
  v12 = env->AllocObject(env->FindClass("java/util/ArrayList"));
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "<init>", "(Ljava/util/Collection;)V"), v11, v11, v11, v11);
  env->CallStaticVoidMethod(env->FindClass("java/util/Collections"), env->GetStaticMethodID(env->FindClass("java/util/Collections"), "sort", "(Ljava/util/List;)V"), v12, v11, v11, v11, v11);
  v13 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︊︂", "LI/ᅠ︀︇;"));
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v13, env->GetFieldID(env->FindClass("I/ᅠ︀︇"), "ᅟ︅︀", "Ljava/util/ArrayList;"));
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("java/util/ArrayList"), "clear", "()V"), v13, v13, v13, v13);
  v15 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v14, env->GetMethodID(env->FindClass("java/util/ArrayList"), "addAll", "(Ljava/util/Collection;)Z"), v12, v13, v13, v13);
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView$Adapter"), "ᅟ︇︀", "()V"), v13, v13, v13, v13);
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︌︂", "Landroid/widget/TextView;"));
  v17 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v12, env->GetMethodID(env->FindClass("java/util/ArrayList"), "isEmpty", "()Z"), v16, v16, v16, v16);
  v18 = v17;
  /* UNSUPPORTED: if-eqz */
  if (v18 == 0) { goto L_36;
 } else { goto L_35;
 }

L_35:
  /* UNSUPPORTED: goto */
v20 = (jint)v4; goto L_38;

L_36:
  v19 = 8;
v20 = (jint)v19; goto L_38;

L_38:
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v20, v16, v16, v16);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︂︂()V -> Java_bin_nt_main_MainActivity__0115f_0fe02_0fe02__ */

/* FAILED Lbin/nt/main/MainActivity;->ᅟ︃︂()V: java.lang.StackOverflowError */

/* Lbin/nt/main/MainActivity;->ᅟ︄︂()V */
void Java_bin_nt_main_MainActivity__0115f_0fe04_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v53 = 0;
  jarray v9 = NULL;
  jobject v22 = NULL;
  jlong v57 = 0;
  jobject v41 = NULL;
  jint v14 = 0;
  jobject v44 = NULL;
  jobject v31 = NULL;
  jboolean v52 = 0;
  jobject v0 = NULL;
  jint v37 = 0;
  jlong v61 = 0;
  jint v27 = 0;
  jint v36 = 0;
  jint v46 = 0;
  jobject v24 = NULL;
  jint v12 = 0;
  jint v49 = 0;
  jint v25 = 0;
  jobject v21 = NULL;
  jobject v7 = NULL;
  jint v20 = 0;
  jobject v43 = NULL;
  jobject v23 = NULL;
  jobject v40 = NULL;
  jlong v56 = 0;
  jobject v39 = NULL;
  jint v48 = 0;
  jint v16 = 0;
  jobject v6 = NULL;
  jint v15 = 0;
  jint v8 = 0;
  jboolean v32 = 0;
  jint v29 = 0;
  jlong v58 = 0;
  jint v5 = 0;
  jboolean v1 = 0;
  jobject v4 = NULL;
  jint v10 = 0;
  jint v2 = 0;
  jobject v38 = NULL;
  jobject v45 = NULL;
  jint v54 = 0;
  jint v11 = 0;
  jobject v42 = NULL;
  jint v18 = 0;
  jint v28 = 0;
  jint v35 = 0;
  jint v13 = 0;
  jint v17 = 0;
  jlong v59 = 0;
  jlong v60 = 0;
  jobject v3 = NULL;
  jint v30 = 0;
  jboolean v33 = 0;
  jint v50 = 0;
  jlong v55 = 0;
  jint v26 = 0;
  jboolean v51 = 0;
  jint v47 = 0;
  jint v34 = 0;
  jint v19 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︅︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  v2 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︅︂", "Z"), v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︆︀", "Landroidx/appcompat/widget/Toolbar;"));
  v5 = 2131361867;
  v6 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v5, v2, v2, v2);
  v7 = v6;
  v8 = 2;
  v9 = env->NewIntArray((jsize)(intptr_t)v8);
  v10 = 0;
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_2d;
 } else { goto L_19;
 }

L_19:
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("android/view/View"), "getLocationInWindow", "([I)V"), v9, v2, v2, v2);
  env->GetIntArrayRegion((jintArray)v9, (jsize)(intptr_t)v10, 1, (jint*)&v11);
  v12 = (jint)(intptr_t)env->CallIntMethod((jobject)v7, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v2, v2, v2, v2);
  v13 = v12;
  /* UNSUPPORTED: div-int-2addr */
  /* UNSUPPORTED: add-int-2addr */
  env->GetIntArrayRegion((jintArray)v16, (jsize)(intptr_t)v2, 1, (jint*)&v16);
  v17 = (jint)(intptr_t)env->CallIntMethod((jobject)v7, env->GetMethodID(env->FindClass("android/view/View"), "getHeight", "()I"), v2, v2, v2, v2);
  v18 = v17;
  /* UNSUPPORTED: div-int-2addr */
  /* UNSUPPORTED: add-int-2addr */
  /* UNSUPPORTED: goto */
v46 = (jint)v15; v47 = (jint)v20; goto L_40;

L_2d:
  v21 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Activity"), "getWindow", "()Landroid/view/Window;"), v2, v2, v2, v2);
  v22 = v21;
  v23 = (jobject)env->CallObjectMethod((jobject)v22, env->GetMethodID(env->FindClass("android/view/Window"), "getDecorView", "()Landroid/view/View;"), v2, v2, v2, v2);
  v24 = v23;
  v25 = (jint)(intptr_t)env->CallIntMethod((jobject)v24, env->GetMethodID(env->FindClass("android/view/View"), "getWidth", "()I"), v2, v2, v2, v2);
  v26 = v25;
  /* UNSUPPORTED: div-int-lit8 */
  v28 = (jint)(intptr_t)env->CallIntMethod((jobject)v24, env->GetMethodID(env->FindClass("android/view/View"), "getHeight", "()I"), v2, v2, v2, v2);
  v29 = v28;
  /* UNSUPPORTED: div-int-2addr */
v46 = (jint)v27; v47 = (jint)v30; goto L_40;

L_40:
  env->CallStaticVoidMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︍︁", "(Landroid/app/Activity;IIZ)V"), v0, v46, v47, v2, v2);
  v31 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  v32 = (jboolean)(intptr_t)env->CallStaticBooleanMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︅︁", "(Landroid/content/Context;)Z"), v31, v2, v2, v2, v2);
  v33 = v32;
  /* UNSUPPORTED: xor-int-2addr */
  /* UNSUPPORTED: rem-int-lit8 */
  /* UNSUPPORTED: add-int-2addr */
  /* UNSUPPORTED: rem-int-2addr */
  v38 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  v39 = (jobject)env->GetObjectField((jobject)(intptr_t)v39, env->GetFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︄︀", "Landroid/content/SharedPreferences;"));
  v40 = (jobject)env->CallObjectMethod((jobject)v39, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "edit", "()Landroid/content/SharedPreferences$Editor;"), v2, v2, v2, v2);
  v41 = v40;
  v42 = env->NewStringUTF("surface_mode");
  v43 = (jobject)env->CallObjectMethod((jobject)v41, env->GetMethodID(env->FindClass("android/content/SharedPreferences$Editor"), "putInt", "(Ljava/lang/String;I)Landroid/content/SharedPreferences$Editor;"), v42, v37, v2, v2);
  v44 = v43;
  env->CallVoidMethod((jobject)v44, env->GetMethodID(env->FindClass("android/content/SharedPreferences$Editor"), "apply", "()V"), v2, v2, v2, v2);
  v45 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  /* UNSUPPORTED: if-ne */
  if (v34 != v2) { goto L_67;
 } else { goto L_63;
 }

L_63:
  v48 = 2131100477;
  /* UNSUPPORTED: goto */
v54 = (jint)v48; goto L_6a;

L_67:
  v49 = 2131100478;
v54 = (jint)v49; goto L_6a;

L_6a:
  v50 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("androidx/core/content/ContextCompat"), env->GetStaticMethodID(env->FindClass("androidx/core/content/ContextCompat"), "ᅟ︁︀", "(Landroid/content/Context;I)I"), v45, v54, v55, v55, v55);
  env->CallStaticVoidMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︄︀", "()V"), v55, v55, v55, v55, v55);
  env->CallVoidMethod((jobject)v56, env->GetMethodID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ︊︁", "()V"), v55, v55, v55, v55);
  v51 = (jboolean)(intptr_t)env->CallStaticBooleanMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︈︁", "()Z"), v55, v55, v55, v55, v55);
  v52 = v51;
  v53 = -1;
  /* UNSUPPORTED: if-eqz */
  if (v52 == 0) { goto L_83;
 } else { goto L_7a;
 }

L_7a:
  env->CallStaticVoidMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︍︁", "(Landroid/app/Activity;IIZ)V"), v56, v53, v53, v55, v55);
  v57 = 150;
v60 = (jlong)v57; goto L_7f;

L_83:
  env->CallStaticVoidMethod(env->FindClass("I/ᅠ︃︆"), env->GetStaticMethodID(env->FindClass("I/ᅠ︃︆"), "ᅟ︍︁", "(Landroid/app/Activity;IIZ)V"), v56, v53, v53, v59, v55);
  v58 = 350;
  /* UNSUPPORTED: goto */
v60 = (jlong)v58; goto L_7f;

L_7f:
  env->CallVoidMethod((jobject)v61, env->GetMethodID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︍︁", "(J)V"), v60, v52, v60, v60);
  /* UNSUPPORTED: goto */
goto L_89;

L_89:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︄︂()V -> Java_bin_nt_main_MainActivity__0115f_0fe04_0fe02__ */

/* Lbin/nt/main/MainActivity;->ᅟ︅︁()V */
void Java_bin_nt_main_MainActivity__0115f_0fe05_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v29 = NULL;
  jint v25 = 0;
  jobject v15 = NULL;
  jobject v35 = NULL;
  jobject v12 = NULL;
  jobject v6 = NULL;
  jint v36 = 0;
  jint v7 = 0;
  jlong v39 = 0;
  jobject v16 = NULL;
  jint v18 = 0;
  jint v13 = 0;
  jint v31 = 0;
  jint v3 = 0;
  jobject v26 = NULL;
  jobject v20 = NULL;
  jobject v23 = NULL;
  jobject v27 = NULL;
  jobject v14 = NULL;
  jobject v19 = NULL;
  jobject v24 = NULL;
  jboolean v34 = 0;
  jobject v0 = NULL;
  jint v10 = 0;
  jint v4 = 0;
  jobject v32 = NULL;
  jint v33 = 0;
  jboolean v38 = 0;
  jobject v21 = NULL;
  jint v37 = 0;
  jobject v30 = NULL;
  jobject v2 = NULL;
  jobject v11 = NULL;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jobject v8 = NULL;
  jobject v17 = NULL;
  jint v28 = 0;
  jobject v9 = NULL;
  jobject v22 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︉︀", "Landroid/widget/ImageView;"));
  v3 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︁︁", "(Landroid/content/Context;)I"), v0, v2, v2, v2, v2);
  v4 = v3;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/ImageView"), "setColorFilter", "(I)V"), v4, v2, v2, v2);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︈︀", "Landroidx/coordinatorlayout/widget/CoordinatorLayout;"));
  v7 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v7, v6, v6, v6);
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︃︀", "Landroid/widget/LinearLayout;"));
  v10 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v10, v9, v9, v9);
  v11 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︂︀", "Lcom/google/android/material/bottomnavigation/BottomNavigationView;"));
  v13 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v12, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v13, v12, v12, v12);
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v15, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︂︀", "Lcom/google/android/material/bottomnavigation/BottomNavigationView;"));
  v16 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "getResources", "()Landroid/content/res/Resources;"), v15, v15, v15, v15);
  v17 = v16;
  v18 = 2131099686;
  v19 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "getTheme", "()Landroid/content/res/Resources$Theme;"), v15, v15, v15, v15);
  v20 = v19;
  v21 = (jobject)env->CallStaticObjectMethod(env->FindClass("androidx/core/content/res/ResourcesCompat"), env->GetStaticMethodID(env->FindClass("androidx/core/content/res/ResourcesCompat"), "ᅟ︁︀", "(Landroid/content/res/Resources;ILandroid/content/res/Resources$Theme;)Landroid/content/res/ColorStateList;"), v17, v18, v20, v15, v15);
  v22 = v21;
  env->CallVoidMethod((jobject)v15, env->GetMethodID(env->FindClass("com/google/android/material/navigation/NavigationBarView"), "setItemIconTintList", "(Landroid/content/res/ColorStateList;)V"), v22, v15, v15, v15);
  v23 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v24 = (jobject)env->GetObjectField((jobject)(intptr_t)v24, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︇︀", "Landroid/widget/FrameLayout;"));
  v25 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v24, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v25, v24, v24, v24);
  v26 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v27 = (jobject)env->GetObjectField((jobject)(intptr_t)v27, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︅︀", "Landroidx/recyclerview/widget/RecyclerView;"));
  v28 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v27, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v28, v27, v27, v27);
  v29 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v30 = (jobject)env->GetObjectField((jobject)(intptr_t)v30, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︄︀", "Landroidx/drawerlayout/widget/DrawerLayout;"));
  v31 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  env->CallVoidMethod((jobject)v30, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v31, v30, v30, v30);
  v32 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︎︂", "LI/ᅟ︁︉;"));
  /* UNSUPPORTED: if-eqz */
  if (v32 == 0) { goto L_66;
 } else { goto L_5b;
 }

L_5b:
  v33 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ︎︁", "I"));
  v34 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ︀︂", "Z"));
  env->SetIntField((jobject)(intptr_t)v32, env->GetFieldID(env->FindClass("I/ᅟ︁︉"), "ᅟ︇︀", "I"), v33);
  env->SetBooleanField((jobject)(intptr_t)v32, env->GetFieldID(env->FindClass("I/ᅟ︁︉"), "ᅟ︈︀", "Z"), v34);
  env->CallVoidMethod((jobject)v32, env->GetMethodID(env->FindClass("androidx/recyclerview/widget/RecyclerView$Adapter"), "ᅟ︇︀", "()V"), v32, v32, v32, v32);
goto L_66;

L_66:
  v35 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︆︂", "Lbin/nt/fragments/FileBrowserFragment;"));
  /* UNSUPPORTED: if-eqz */
  if (v35 == 0) { goto L_73;
 } else { goto L_6a;
 }

L_6a:
  v36 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ︎︁", "I"));
  v37 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ️︁", "I"));
  v38 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ︀︂", "Z"));
  env->CallVoidMethod((jobject)v35, env->GetMethodID(env->FindClass("bin/nt/fragments/FileBrowserFragment"), "ᅟ︄︅", "(IIZ)V"), v36, v37, v38, v35);
goto L_73;

L_73:
  env->CallVoidMethod((jobject)v39, env->GetMethodID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︅︂", "()V"), v35, v35, v35, v35);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︁()V -> Java_bin_nt_main_MainActivity__0115f_0fe05_0fe01__ */

/* Lbin/nt/main/MainActivity;->ᅟ︅︂()V */
void Java_bin_nt_main_MainActivity__0115f_0fe05_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jobject v14 = NULL;
  jobject v8 = NULL;
  jobject v4 = NULL;
  jobject v1 = NULL;
  jobject v16 = NULL;
  jint v5 = 0;
  jobject v18 = NULL;
  jobject v19 = NULL;
  jint v10 = 0;
  jint v23 = 0;
  jobject v2 = NULL;
  jint v21 = 0;
  jint v7 = 0;
  jint v6 = 0;
  jobject v22 = NULL;
  jobject v15 = NULL;
  jobject v12 = NULL;
  jobject v3 = NULL;
  jobject v9 = NULL;
  jint v20 = 0;
  jlong v25 = 0;
  jint v13 = 0;
  jobject v17 = NULL;
  jlong v11 = 0;
  jlong v24 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︆︀", "Landroidx/appcompat/widget/Toolbar;"));
  v3 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/widget/Toolbar"), "getMenu", "()Landroid/view/Menu;"), v2, v2, v2, v2);
  v4 = v3;
  v5 = 0;
v8 = (jobject)v0; v9 = (jobject)v4; v10 = (jint)v5; goto L_9;

L_9:
  v6 = (jint)(intptr_t)env->CallIntMethod((jobject)v9, env->GetMethodID(env->FindClass("android/view/Menu"), "size", "()I"), v9, v9, v9, v9);
  v7 = v6;
  /* UNSUPPORTED: if-ge */
  if (v10 >= v7) { goto L_2a;
 } else { goto L_f;
 }

L_f:
  v14 = (jobject)env->CallObjectMethod((jobject)v9, env->GetMethodID(env->FindClass("android/view/Menu"), "getItem", "(I)Landroid/view/MenuItem;"), v10, v9, v9, v9);
  v15 = v14;
  v16 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/MenuItem"), "getIcon", "()Landroid/graphics/drawable/Drawable;"), v9, v9, v9, v9);
  v17 = v16;
  /* UNSUPPORTED: if-eqz */
  if (v17 == 0) { v12 = (jobject)v9; v13 = (jint)v10; goto L_27;
 } else { goto L_19;
 }

L_19:
  v18 = (jobject)env->CallObjectMethod((jobject)v17, env->GetMethodID(env->FindClass("android/graphics/drawable/Drawable"), "mutate", "()Landroid/graphics/drawable/Drawable;"), v9, v9, v9, v9);
  v19 = v18;
  v20 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︁︁", "(Landroid/content/Context;)I"), v8, v9, v9, v9, v9);
  v21 = v20;
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("android/graphics/drawable/Drawable"), "setTint", "(I)V"), v21, v9, v9, v9);
  v22 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/MenuItem"), "setIcon", "(Landroid/graphics/drawable/Drawable;)Landroid/view/MenuItem;"), v19, v9, v9, v9);
v12 = (jobject)(intptr_t)v24; v13 = (jint)(intptr_t)v25; goto L_27;

L_27:
  /* UNSUPPORTED: add-int-lit8 */
  /* UNSUPPORTED: goto */
v8 = (jobject)(intptr_t)v11; v9 = (jobject)v12; v10 = (jint)v13; goto L_9;

L_2a:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︂()V -> Java_bin_nt_main_MainActivity__0115f_0fe05_0fe02__ */

/* FAILED Lbin/nt/main/MainActivity;->ᅟ︆︂()V: java.lang.IllegalStateException: unknown phi type v0_7 = phi[v0_8 = phi[v0_10 = phi[v0_3, v0_14 = phi[v0_3, v0_3]]], v0_9 = phi[v0_10 = phi[v0_3, v0_14 = phi[v0_3, v0_3]], v0_10 = phi[v0_3, v0_14 = phi[v0_3, v0_3]], v0_10 = phi[v0_3, v0_14 = phi[v0_3, v0_3]]]] */

/* Lbin/nt/main/MainActivity;->ᅟ︇︂(Z)V */
void Java_bin_nt_main_MainActivity__0115f_0fe07_0fe02__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v14 = NULL;
  jobject v15 = NULL;
  jobject v8 = NULL;
  jobject v19 = NULL;
  jobject v7 = NULL;
  jint v6 = 0;
  jint v10 = 0;
  jint v20 = 0;
  jobject v4 = NULL;
  jobject v2 = NULL;
  jobject v21 = NULL;
  jobject v22 = NULL;
  jobject v5 = NULL;
  jobject v13 = NULL;
  jobject v12 = NULL;
  jobject v18 = NULL;
  jboolean v1 = 0;
  jobject v25 = NULL;
  jlong v23 = 0;
  jint v16 = 0;
  jobject v24 = NULL;
  jobject v11 = NULL;
  jobject v0 = NULL;
  jint v17 = 0;
  jobject v3 = NULL;
  jint v9 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︂︀", "Lcom/google/android/material/bottomnavigation/BottomNavigationView;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("com/google/android/material/navigation/NavigationBarView"), "getMenu", "()Landroid/view/Menu;"), v3, v3, v3, v3);
  v5 = v4;
  v6 = 2131362352;
  v7 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("android/view/Menu"), "findItem", "(I)Landroid/view/MenuItem;"), v6, v5, v5, v5);
  v8 = v7;
  /* UNSUPPORTED: if-nez */
  if (v8 != 0) { goto L_15;
 } else { goto L_14;
 }

L_14:
  /* return terminator */
  return;

L_15:
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_1b;
 } else { goto L_17;
 }

L_17:
  v9 = 2131230952;
  /* UNSUPPORTED: goto */
v16 = (jint)v9; goto L_1e;

L_1b:
  v10 = 2131230953;
v16 = (jint)v10; goto L_1e;

L_1e:
  v11 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("android/view/MenuItem"), "setIcon", "(I)Landroid/view/MenuItem;"), v16, v8, v8, v8);
  v12 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/MainActivity"), "ᅟ︃︂", "LI/ᅟ︍︁;"));
  v13 = (jobject)env->GetObjectField((jobject)(intptr_t)v13, env->GetFieldID(env->FindClass("I/ᅟ︍︁"), "ᅟ︂︀", "Lcom/google/android/material/bottomnavigation/BottomNavigationView;"));
  v14 = (jobject)env->CallObjectMethod((jobject)v13, env->GetMethodID(env->FindClass("android/view/View"), "findViewById", "(I)Landroid/view/View;"), v6, v8, v8, v8);
  v15 = v14;
  /* UNSUPPORTED: if-eqz */
  if (v15 == 0) { goto L_42;
 } else { goto L_2b;
 }

L_2b:
  v17 = 0;
  env->CallVoidMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "setAlpha", "(F)V"), v17, v17, v17, v17);
  v18 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/View"), "animate", "()Landroid/view/ViewPropertyAnimator;"), v17, v17, v17, v17);
  v19 = v18;
  v20 = 1065353216;
  v21 = (jobject)env->CallObjectMethod((jobject)v19, env->GetMethodID(env->FindClass("android/view/ViewPropertyAnimator"), "alpha", "(F)Landroid/view/ViewPropertyAnimator;"), v20, v20, v20, v20);
  v22 = v21;
  v23 = 250;
  v24 = (jobject)env->CallObjectMethod((jobject)v22, env->GetMethodID(env->FindClass("android/view/ViewPropertyAnimator"), "setDuration", "(J)Landroid/view/ViewPropertyAnimator;"), v23, v6, v23, v23);
  v25 = v24;
  env->CallVoidMethod((jobject)v25, env->GetMethodID(env->FindClass("android/view/ViewPropertyAnimator"), "start", "()V"), v23, v23, v23, v23);
goto L_42;

L_42:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︇︂(Z)V -> Java_bin_nt_main_MainActivity__0115f_0fe07_0fe02__Z */

/* FAILED Lbin/nt/main/MainActivity;->ᅟ︍︁(J)V: java.lang.IllegalStateException: unknown phi type v7_0 = phi[] */

/* Lbin/nt/main/MainActivity;->ᅟ︎︁(I)Landroid/widget/TextView; */
jobject Java_bin_nt_main_MainActivity__0115f_0fe0e_0fe01__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jint v8 = 0;
  jobject v0 = NULL;
  jint v3 = 0;
  jint v7 = 0;
  jint v6 = 0;
  jint v5 = 0;
  jint v4 = 0;
  jobject v2 = NULL;
  jint v1 = 0;

L_0:
  v2 = env->AllocObject(env->FindClass("android/widget/TextView"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/TextView"), "<init>", "(Landroid/content/Context;)V"), v0, v2, v2, v2);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(I)V"), v1, v2, v2, v2);
  v3 = 2130969434;
  v4 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︄︂", "(Landroid/content/Context;I)I"), v0, v3, v2, v2, v2);
  v5 = v4;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextColor", "(I)V"), v5, v2, v2, v2);
  v6 = 1096810496;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextSize", "(F)V"), v6, v2, v2, v2);
  v7 = 17;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/TextView"), "setGravity", "(I)V"), v7, v2, v2, v2);
  v8 = 8;
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v8, v2, v2, v2);
  /* return terminator */
  return (jobject)(intptr_t)v2;
EX_Return: return (jobject)0;
EX_UnwindBlock: return (jobject)0;
}

/* RegisterNatives entry for ᅟ︎︁(I)Landroid/widget/TextView; -> Java_bin_nt_main_MainActivity__0115f_0fe0e_0fe01__I */

/* FAILED Lbin/nt/main/PhotoViewerActivity;-><init>()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/PhotoViewerActivity;->ᅟ︍︁(Lbin/nt/main/PhotoViewerActivity;)V: java.lang.IllegalStateException: unknown phi type v3_3 = phi[] */

/* FAILED Lbin/nt/main/PhotoViewerActivity;->onCreate(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/PhotoViewerActivity;->onDestroy()V: java.lang.StackOverflowError */

/* Lbin/nt/main/PhotoViewerActivity;->onKeyDown(ILandroid/view/KeyEvent;)Z */
jboolean Java_bin_nt_main_PhotoViewerActivity_onKeyDown__ILandroid_view_KeyEvent_2(JNIEnv* env, jobject thiz, jint p0, jobject p1) {
  jthrowable pendingException = NULL;
  jint v6 = 0;
  jint v8 = 0;
  jint v1 = 0;
  jboolean v10 = 0;
  jobject v0 = NULL;
  jboolean v11 = 0;
  jobject v2 = NULL;
  jint v7 = 0;
  jint v9 = 0;
  jint v5 = 0;
  jint v3 = 0;
  jint v4 = 0;

L_0:
  v3 = 24;
  v4 = 1;
  /* UNSUPPORTED: if-ne */
  if (v1 != v3) { goto L_b;
 } else { goto L_5;
 }

L_5:
  v5 = 1067450368;
v8 = (jint)v5; v9 = (jint)v3; goto L_7;

L_b:
  v6 = 25;
  /* UNSUPPORTED: if-ne */
  if (v1 != v6) { goto L_13;
 } else { goto L_f;
 }

L_f:
  v7 = 1061997773;
  /* UNSUPPORTED: goto */
v8 = (jint)v7; v9 = (jint)v6; goto L_7;

L_7:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︁︂", "(F)V"), v8, v9, v9, v9);
  /* return terminator */
  return (jboolean)(intptr_t)v4;

L_13:
  v10 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "onKeyDown", "(ILandroid/view/KeyEvent;)Z"), v1, v2, v6, v6);
  v11 = v10;
  /* return terminator */
  return (jboolean)(intptr_t)v11;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for onKeyDown(ILandroid/view/KeyEvent;)Z -> Java_bin_nt_main_PhotoViewerActivity_onKeyDown__ILandroid_view_KeyEvent_2 */

/* Lbin/nt/main/PhotoViewerActivity;->onResume()V */
void Java_bin_nt_main_PhotoViewerActivity_onResume__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/fragment/app/FragmentActivity"), "onResume", "()V"), v0, v0, v0, v0);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︎︁", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for onResume()V -> Java_bin_nt_main_PhotoViewerActivity_onResume__ */

/* FAILED Lbin/nt/main/PhotoViewerActivity;->onSaveInstanceState(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/PhotoViewerActivity;->ᅟ︀︂()V */
void Java_bin_nt_main_PhotoViewerActivity__0115f_0fe00_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jint v4 = 0;
  jobject v7 = NULL;
  jobject v15 = NULL;
  jint v1 = 0;
  jint v8 = 0;
  jobject v17 = NULL;
  jobject v12 = NULL;
  jobject v13 = NULL;
  jobject v6 = NULL;
  jobject v11 = NULL;
  jobject v10 = NULL;
  jobject v16 = NULL;
  jobject v2 = NULL;
  jint v3 = 0;
  jobject v14 = NULL;
  jint v5 = 0;
  jobject v9 = NULL;

L_0:
  v1 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︉︂", "I"));
  /* UNSUPPORTED: if-ltz */
  if (v1 < 0) { goto L_33;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︄︂", "Ljava/util/ArrayList;"));
  v3 = (jint)(intptr_t)env->CallIntMethod((jobject)v2, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v1, v1, v1, v1);
  v4 = v3;
  /* UNSUPPORTED: if-lt */
  if (v1 < v4) { goto L_d;
 } else { goto L_c;
 }

L_c:
  /* UNSUPPORTED: goto */
goto L_33;

L_d:
  v5 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︉︂", "I"));
  v6 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("java/util/ArrayList"), "get", "(I)Ljava/lang/Object;"), v5, v5, v5, v5);
  v7 = v6;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/String"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︃︂", "LI/ᅟ︎︁;"));
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︇︀", "Landroidx/appcompat/widget/Toolbar;"));
  v11 = env->AllocObject(env->FindClass("java/io/File"));
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("java/io/File"), "<init>", "(Ljava/lang/String;)V"), v8, v8, v8, v8);
  v12 = (jobject)env->CallObjectMethod((jobject)v11, env->GetMethodID(env->FindClass("java/io/File"), "getName", "()Ljava/lang/String;"), v8, v8, v8, v8);
  v13 = v12;
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("androidx/appcompat/widget/Toolbar"), "setTitle", "(Ljava/lang/CharSequence;)V"), v13, v8, v8, v8);
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︃︂", "LI/ᅟ︎︁;"));
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v15, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︇︀", "Landroidx/appcompat/widget/Toolbar;"));
  v16 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︂️"), env->GetStaticMethodID(env->FindClass("I/ᅟ︂️"), "ᅟ︁︀", "(Ljava/lang/String;)Ljava/lang/String;"), v8, v8, v8, v8, v8);
  v17 = (jobject)(intptr_t)v16;
  env->CallVoidMethod((jobject)v15, env->GetMethodID(env->FindClass("androidx/appcompat/widget/Toolbar"), "setSubtitle", "(Ljava/lang/CharSequence;)V"), v17, v17, v17, v17);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ️︁", "()V"), v17, v17, v17, v17);
goto L_33;

L_33:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︀︂()V -> Java_bin_nt_main_PhotoViewerActivity__0115f_0fe00_0fe02__ */

/* Lbin/nt/main/PhotoViewerActivity;->ᅟ︁︂(F)V */
void Java_bin_nt_main_PhotoViewerActivity__0115f_0fe01_0fe02__F(JNIEnv* env, jobject thiz, jfloat p0) {
  jthrowable pendingException = NULL;
  jobject v21 = NULL;
  jfloat v26 = 0;
  jobject v13 = NULL;
  jfloat v31 = 0;
  jobject v33 = NULL;
  jobject v34 = NULL;
  jint v30 = 0;
  jfloat v29 = 0;
  jobject v10 = NULL;
  jint v20 = 0;
  jobject v4 = NULL;
  jint v7 = 0;
  jint v27 = 0;
  jfloat v28 = 0;
  jint v37 = 0;
  jint v39 = 0;
  jint v40 = 0;
  jint v17 = 0;
  jobject v9 = NULL;
  jboolean v12 = 0;
  jobject v8 = NULL;
  jobject v3 = NULL;
  jint v43 = 0;
  jint v6 = 0;
  jobject v2 = NULL;
  jobject v0 = NULL;
  jobject v16 = NULL;
  jint v22 = 0;
  jobject v15 = NULL;
  jint v41 = 0;
  jint v18 = 0;
  jint v35 = 0;
  jint v23 = 0;
  jfloat v24 = 0;
  jint v36 = 0;
  jboolean v11 = 0;
  jfloat v42 = 0;
  jint v19 = 0;
  jfloat v32 = 0;
  jfloat v38 = 0;
  jlong v44 = 0;
  jobject v5 = NULL;
  jfloat v25 = 0;
  jlong v14 = 0;
  jfloat v1 = 0;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︃︂", "LI/ᅟ︎︁;"));
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v3, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︄︀", "Lbin/nt/ui/HackyViewPager;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("androidx/viewpager/widget/ViewPager"), "getAdapter", "()Landroidx/viewpager/widget/PagerAdapter;"), v3, v3, v3, v3);
  v5 = v4;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︈︄"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  /* UNSUPPORTED: if-nez */
  if (v6 != 0) { goto L_d;
 } else { goto L_c;
 }

L_c:
  /* return terminator */
  return;

L_d:
  v7 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︉︂", "I"));
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅠ︈︄"), "ᅟ︁︀", "Ljava/util/ArrayList;"));
  v9 = (jobject)env->CallObjectMethod((jobject)v8, env->GetMethodID(env->FindClass("java/util/ArrayList"), "iterator", "()Ljava/util/Iterator;"), v8, v8, v8, v8);
  v10 = v9;
v13 = (jobject)v10; goto L_15;

L_15:
  v11 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/Iterator"), "hasNext", "()Z"), v13, v13, v13, v13);
  v12 = v11;
  /* UNSUPPORTED: if-eqz */
  if (v12 == 0) { goto L_26;
 } else { goto L_1b;
 }

L_1b:
  v15 = (jobject)env->CallObjectMethod((jobject)v13, env->GetMethodID(env->FindClass("java/util/Iterator"), "next", "()Ljava/lang/Object;"), v13, v13, v13, v13);
  v16 = v15;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("I/ᅠ︇︄"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v18 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅠ︇︄"), "ᅟ︁︀", "I"));
  /* UNSUPPORTED: if-ne */
  if (v18 != v7) { v13 = (jobject)(intptr_t)v14; goto L_15;
 } else { goto L_25;
 }

L_25:
  /* UNSUPPORTED: goto */
v20 = (jint)v17; goto L_27;

L_26:
  v19 = 0;
v20 = (jint)v19; goto L_27;

L_27:
  /* UNSUPPORTED: if-eqz */
  if (v20 == 0) { goto L_5a;
 } else { goto L_29;
 }

L_29:
  v21 = (jobject)env->GetObjectField((jobject)(intptr_t)v20, env->GetFieldID(env->FindClass("I/ᅠ︇︄"), "ᅟ︄︀", "Lcom/github/chrisbanes/photoview/PhotoView;"));
  v22 = (jint)(intptr_t)env->CallIntMethod((jobject)v21, env->GetMethodID(env->FindClass("android/view/View"), "getVisibility", "()I"), v21, v21, v21, v21);
  v23 = v22;
  /* UNSUPPORTED: if-eqz */
  if (v23 == 0) { goto L_32;
 } else { goto L_31;
 }

L_31:
  /* UNSUPPORTED: goto */
goto L_5a;

L_32:
  v24 = (jfloat)(intptr_t)env->CallFloatMethod((jobject)v21, env->GetMethodID(env->FindClass("com/github/chrisbanes/photoview/PhotoView"), "getScale", "()F"), v21, v21, v21, v21);
  v25 = v24;
  /* UNSUPPORTED: mul-float */
  v27 = 1077936128;
  v28 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "min", "(FF)F"), v26, v27, v21, v21, v21);
  v29 = v28;
  v30 = 1065353216;
  v31 = (jfloat)(intptr_t)env->CallStaticFloatMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(FF)F"), v30, v29, v21, v21, v21);
  v32 = v31;
  v33 = (jobject)env->GetObjectField((jobject)(intptr_t)v33, env->GetFieldID(env->FindClass("com/github/chrisbanes/photoview/PhotoView"), "ᅟ︇︀", "Lcom/github/chrisbanes/photoview/PhotoViewAttacher;"));
  v34 = (jobject)env->GetObjectField((jobject)(intptr_t)v33, env->GetFieldID(env->FindClass("com/github/chrisbanes/photoview/PhotoViewAttacher"), "ᅟ︋︀", "Landroid/widget/ImageView;"));
  v35 = (jint)(intptr_t)env->CallIntMethod((jobject)v34, env->GetMethodID(env->FindClass("android/view/View"), "getRight", "()I"), v33, v33, v33, v33);
  v36 = v35;
  /* UNSUPPORTED: div-int-lit8 */
  v38 = (jfloat)v38;
  v39 = (jint)(intptr_t)env->CallIntMethod((jobject)v34, env->GetMethodID(env->FindClass("android/view/View"), "getBottom", "()I"), v33, v33, v33, v33);
  v40 = v39;
  /* UNSUPPORTED: div-int-lit8 */
  v42 = (jfloat)v42;
  v43 = 1;
  env->CallVoidMethod((jobject)v33, env->GetMethodID(env->FindClass("com/github/chrisbanes/photoview/PhotoViewAttacher"), "ᅟ︅︀", "(FFFZ)V"), v32, v38, v42, v43);
goto L_5a;

L_5a:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︂(F)V -> Java_bin_nt_main_PhotoViewerActivity__0115f_0fe01_0fe02__F */

/* FAILED Lbin/nt/main/PhotoViewerActivity;->ᅟ︇︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/PhotoViewerActivity;->ᅟ︎︁()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/PhotoViewerActivity;->ᅟ️︁()V */
void Java_bin_nt_main_PhotoViewerActivity__0115f_0fe0f_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v13 = 0;
  jobject v11 = NULL;
  jobject v15 = NULL;
  jobject v16 = NULL;
  jobject v18 = NULL;
  jboolean v3 = 0;
  jobject v1 = NULL;
  jobject v8 = NULL;
  jobject v14 = NULL;
  jobject v17 = NULL;
  jint v5 = 0;
  jint v4 = 0;
  jint v12 = 0;
  jobject v20 = NULL;
  jint v7 = 0;
  jboolean v2 = 0;
  jint v6 = 0;
  jint v21 = 0;
  jobject v10 = NULL;
  jobject v0 = NULL;
  jobject v19 = NULL;
  jobject v9 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︅︂", "Ljava/util/LinkedHashSet;"));
  v2 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v1, env->GetMethodID(env->FindClass("java/util/Set"), "isEmpty", "()Z"), v1, v1, v1, v1);
  v3 = v2;
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_d;
 } else { goto L_8;
 }

L_8:
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︉︂", "I"));
  /* UNSUPPORTED: add-int-lit8 */
  /* UNSUPPORTED: goto */
v21 = (jint)v5; goto L_11;

L_d:
  v6 = (jint)(intptr_t)env->CallIntMethod((jobject)v1, env->GetMethodID(env->FindClass("java/util/Set"), "size", "()I"), v1, v1, v1, v1);
  v7 = v6;
v21 = (jint)v7; goto L_11;

L_11:
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︃︂", "LI/ᅟ︎︁;"));
  v9 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("I/ᅟ︎︁"), "ᅟ︃︀", "Landroid/widget/TextView;"));
  v10 = (jobject)env->GetStaticObjectField(env->FindClass("java/util/Locale"), env->GetStaticFieldID(env->FindClass("java/util/Locale"), "US", "Ljava/util/Locale;"));
  v11 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/PhotoViewerActivity"), "ᅟ︄︂", "Ljava/util/ArrayList;"));
  v12 = (jint)(intptr_t)env->CallIntMethod((jobject)v11, env->GetMethodID(env->FindClass("java/util/ArrayList"), "size", "()I"), v21, v21, v21, v21);
  v13 = v12;
  v14 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "()V"), v21, v21, v21, v21);
  v15 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(I)Ljava/lang/StringBuilder;"), v21, v21, v21, v21);
  v16 = env->NewStringUTF("/");
  v17 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v16, v16, v16, v16);
  v18 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(I)Ljava/lang/StringBuilder;"), v13, v16, v16, v16);
  v19 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v16, v16, v16, v16);
  v20 = v19;
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(Ljava/lang/CharSequence;)V"), v20, v20, v20, v20);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ️︁()V -> Java_bin_nt_main_PhotoViewerActivity__0115f_0fe0f_0fe01__ */

/* Lbin/nt/main/Preferences;-><init>()V */
void Java_bin_nt_main_Preferences__0003cinit_0003e__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;

L_0:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/BaseActivity"), "<init>", "()V"), v0, v0, v0, v0);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for <init>()V -> Java_bin_nt_main_Preferences__0003cinit_0003e__ */

/* FAILED Lbin/nt/main/Preferences;->onCreate(Landroid/os/Bundle;)V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/Preferences;->onOptionsItemSelected(Landroid/view/MenuItem;)Z */
jboolean Java_bin_nt_main_Preferences_onOptionsItemSelected__Landroid_view_MenuItem_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v0 = NULL;
  jboolean v3 = 0;
  jboolean v2 = 0;
  jobject v1 = NULL;

L_0:
  v2 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v0, env->GetMethodID(env->FindClass("android/app/Activity"), "onOptionsItemSelected", "(Landroid/view/MenuItem;)Z"), v1, v0, v0, v0);
  v3 = v2;
  /* return terminator */
  return (jboolean)(intptr_t)v3;
EX_Return: return (jboolean)0;
EX_UnwindBlock: return (jboolean)0;
}

/* RegisterNatives entry for onOptionsItemSelected(Landroid/view/MenuItem;)Z -> Java_bin_nt_main_Preferences_onOptionsItemSelected__Landroid_view_MenuItem_2 */

/* FAILED Lbin/nt/main/Preferences;->ᅟ︄︁()Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/Preferences;->ᅟ︅︁()V */
void Java_bin_nt_main_Preferences__0115f_0fe05_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v3 = 0;
  jobject v1 = NULL;
  jobject v0 = NULL;
  jint v5 = 0;
  jint v4 = 0;
  jobject v2 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/Preferences"), "ᅟ︃︂", "LI/ᅟ️︁;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_f;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅟ️︁"), "ᅟ︁︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("androidx/appcompat/widget/Toolbar"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v4 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︁︁", "(Landroid/content/Context;)I"), v0, v3, v3, v3, v3);
  v5 = v4;
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("androidx/appcompat/widget/Toolbar"), "setTitleTextColor", "(I)V"), v5, v3, v3, v3);
goto L_f;

L_f:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︁()V -> Java_bin_nt_main_Preferences__0115f_0fe05_0fe01__ */

/* FAILED Lbin/nt/main/TextEditorActivity;-><init>()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/TextEditorActivity;->onBackPressed()V */
void Java_bin_nt_main_TextEditorActivity_onBackPressed__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v17 = NULL;
  jobject v5 = NULL;
  jobject v0 = NULL;
  jobject v8 = NULL;
  jint v10 = 0;
  jint v11 = 0;
  jobject v9 = NULL;
  jint v15 = 0;
  jint v18 = 0;
  jobject v16 = NULL;
  jint v3 = 0;
  jobject v12 = NULL;
  jobject v13 = NULL;
  jobject v6 = NULL;
  jobject v2 = NULL;
  jobject v20 = NULL;
  jobject v7 = NULL;
  jobject v4 = NULL;
  jint v14 = 0;
  jobject v19 = NULL;
  jint v21 = 0;
  jboolean v1 = 0;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "Z"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_43;
 } else { goto L_4;
 }

L_4:
  v2 = env->AllocObject(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "<init>", "(Landroid/content/Context;)V"), v0, v2, v2, v2);
  v3 = 2131886294;
  v4 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︇︀", "(I)Landroidx/appcompat/app/AlertDialog$Builder;"), v3, v2, v2, v2);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︀︀", "Landroidx/appcompat/app/AlertController$AlertParams;"));
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertController$AlertParams"), "ᅟ︀︀", "Landroid/content/Context;"));
  v7 = (jobject)env->CallObjectMethod((jobject)v6, env->GetMethodID(env->FindClass("android/content/Context"), "getText", "(I)Ljava/lang/CharSequence;"), v3, v2, v2, v2);
  v8 = v7;
  env->SetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertController$AlertParams"), "ᅟ︅︀", "Ljava/lang/CharSequence;"), (jobject)(intptr_t)v8);
  v9 = env->AllocObject(env->FindClass("I/ᅠ︊︉"));
  v10 = 1;
  env->CallVoidMethod((jobject)v9, env->GetMethodID(env->FindClass("I/ᅠ︊︉"), "<init>", "(Lbin/nt/main/TextEditorActivity;I)V"), v0, v10, v2, v2);
  v11 = 2131886293;
  v12 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︄︀", "(ILandroid/content/DialogInterface$OnClickListener;)Landroidx/appcompat/app/AlertDialog$Builder;"), v11, v9, v2, v2);
  v13 = env->AllocObject(env->FindClass("I/ᅠ︊︉"));
  v14 = 2;
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("I/ᅠ︊︉"), "<init>", "(Lbin/nt/main/TextEditorActivity;I)V"), v0, v14, v2, v2);
  v15 = 2131886146;
  v16 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︂︀", "(ILandroid/content/DialogInterface$OnClickListener;)Landroidx/appcompat/app/AlertDialog$Builder;"), v15, v13, v2, v2);
  v17 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertController$AlertParams"), "ᅟ︀︀", "Landroid/content/Context;"));
  v18 = 2131886127;
  v19 = (jobject)env->CallObjectMethod((jobject)v17, env->GetMethodID(env->FindClass("android/content/Context"), "getText", "(I)Ljava/lang/CharSequence;"), v18, v2, v2, v2);
  v20 = v19;
  env->SetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertController$AlertParams"), "ᅟ︊︀", "Ljava/lang/CharSequence;"), (jobject)(intptr_t)v20);
  v21 = 0;
  env->SetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertController$AlertParams"), "ᅟ︋︀", "Landroid/content/DialogInterface$OnClickListener;"), (jobject)(intptr_t)v21);
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︉︀", "()V"), v2, v2, v2, v2);
  /* UNSUPPORTED: goto */
goto L_46;

L_43:
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/activity/ComponentActivity"), "onBackPressed", "()V"), v1, v1, v1, v1);
goto L_46;

L_46:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for onBackPressed()V -> Java_bin_nt_main_TextEditorActivity_onBackPressed__ */

/* Lbin/nt/main/TextEditorActivity;->onContentChanged()V */
void Java_bin_nt_main_TextEditorActivity_onContentChanged__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v5 = NULL;
  jlong v8 = 0;
  jobject v3 = NULL;
  jobject v4 = NULL;
  jlong v7 = 0;
  jboolean v1 = 0;
  jboolean v6 = 0;
  jint v2 = 0;
  jobject v0 = NULL;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︇︂", "Z"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { v5 = (jobject)v0; v6 = (jboolean)v1; goto L_e;
 } else { goto L_4;
 }

L_4:
  v2 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "Z"), v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { v5 = (jobject)v0; v6 = (jboolean)v1; goto L_e;
 } else { goto L_b;
 }

L_b:
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/Object"), "getClass", "()Ljava/lang/Class;"), v3, v3, v3, v3);
v5 = (jobject)(intptr_t)v7; v6 = (jboolean)(intptr_t)v8; goto L_e;

L_e:
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "()V"), v6, v6, v6, v6);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for onContentChanged()V -> Java_bin_nt_main_TextEditorActivity_onContentChanged__ */

/* FAILED Lbin/nt/main/TextEditorActivity;->onCreate(Landroid/os/Bundle;)V: java.lang.StackOverflowError */

/* FAILED Lbin/nt/main/TextEditorActivity;->onDestroy()V: java.lang.IllegalStateException: unknown phi type v3_3 = phi[v3_1 = phi[v3_0, v3_0], v3_4 = phi[v3_1 = phi[v3_0, v3_0]]] */

/* FAILED Lbin/nt/main/TextEditorActivity;->onResume()V: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︀︂(I)V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe00_0fe02__I(JNIEnv* env, jobject thiz, jint p0) {
  jthrowable pendingException = NULL;
  jobject v10 = NULL;
  jobject v22 = NULL;
  jint v12 = 0;
  jobject v4 = NULL;
  jint v2 = 0;
  jobject v20 = NULL;
  jint v9 = 0;
  jint v1 = 0;
  jobject v8 = NULL;
  jobject v19 = NULL;
  jint v7 = 0;
  jint v13 = 0;
  jint v16 = 0;
  jobject v11 = NULL;
  jobject v3 = NULL;
  jint v5 = 0;
  jint v21 = 0;
  jint v17 = 0;
  jint v18 = 0;
  jint v14 = 0;
  jint v15 = 0;
  jobject v0 = NULL;
  jint v6 = 0;

L_0:
  v2 = 2131362234;
  v3 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "findViewById", "(I)Landroid/view/View;"), v2, v2, v2, v2);
  v4 = v3;
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("android/widget/ProgressBar"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v6 = 1;
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︇︂", "Z"), v6);
  v7 = 0;
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v7, v5, v5, v5);
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/widget/ProgressBar"), "setIndeterminate", "(Z)V"), v6, v5, v5, v5);
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;"));
  v9 = 4;
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v9, v5, v5, v5);
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  v11 = env->AllocObject(env->FindClass("I/ᅠ︌︉"));
  v12 = 2;
  env->CallVoidMethod((jobject)v11, env->GetMethodID(env->FindClass("I/ᅠ︌︉"), "<init>", "(Lbin/nt/main/TextEditorActivity;Landroid/widget/ProgressBar;I)V"), v0, v5, v12, v5);
  v13 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v10, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︃︀", "I"));
  /* UNSUPPORTED: sub-int-2addr */
  v15 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "min", "(II)I"), v1, v14, v14, v14, v14);
  v16 = v15;
  v17 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("java/lang/Math"), env->GetStaticMethodID(env->FindClass("java/lang/Math"), "max", "(II)I"), v7, v16, v14, v14, v14);
  v18 = v17;
  v19 = env->AllocObject(env->FindClass("java/lang/Thread"));
  v20 = env->AllocObject(env->FindClass("I/ᅟ︃︈"));
  v21 = 4;
  env->CallVoidMethod((jobject)v20, env->GetMethodID(env->FindClass("I/ᅟ︃︈"), "<init>", "(Ljava/lang/Object;ILjava/lang/Object;I)V"), v10, v18, v11, v21);
  v22 = env->NewStringUTF("editor-page-load");
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("java/lang/Thread"), "<init>", "(Ljava/lang/Runnable;Ljava/lang/String;)V"), v20, v22, v19, v19);
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("java/lang/Thread"), "start", "()V"), v19, v19, v19, v19);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︀︂(I)V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe00_0fe02__I */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︁︂()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe01_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jboolean v12 = 0;
  jobject v17 = NULL;
  jobject v5 = NULL;
  jboolean v9 = 0;
  jobject v18 = NULL;
  jobject v1 = NULL;
  jboolean v15 = 0;
  jobject v3 = NULL;
  jobject v6 = NULL;
  jobject v2 = NULL;
  jboolean v8 = 0;
  jboolean v11 = 0;
  jobject v7 = NULL;
  jobject v0 = NULL;
  jboolean v14 = 0;
  jobject v13 = NULL;
  jint v16 = 0;
  jobject v4 = NULL;
  jobject v10 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︁︃", "Landroid/widget/EditText;"));
  /* UNSUPPORTED: if-nez */
  if (v1 != 0) { goto L_5;
 } else { goto L_4;
 }

L_4:
  /* return terminator */
  return;

L_5:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︊︃", "LI/ᅟ︍︋;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("I/ᅟ︍︋"), "ᅟ︅︀", "()V"), v2, v2, v2, v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︁︃", "Landroid/widget/EditText;"));
  v4 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("android/widget/EditText"), "getText", "()Landroid/text/Editable;"), v3, v3, v3, v3);
  v5 = v4;
  v6 = (jobject)env->CallObjectMethod((jobject)v5, env->GetMethodID(env->FindClass("java/lang/Object"), "toString", "()Ljava/lang/String;"), v5, v5, v5, v5);
  v7 = v6;
  v8 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v7, env->GetMethodID(env->FindClass("java/lang/String"), "isEmpty", "()Z"), v7, v7, v7, v7);
  v9 = v8;
  /* UNSUPPORTED: if-eqz */
  if (v9 == 0) { goto L_1b;
 } else { goto L_1a;
 }

L_1a:
  /* return terminator */
  return;

L_1b:
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︄︃", "Landroid/widget/CheckBox;"));
  v11 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v10, env->GetMethodID(env->FindClass("android/widget/CompoundButton"), "isChecked", "()Z"), v7, v7, v7, v7);
  v12 = v11;
  v13 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︃", "Landroid/widget/CheckBox;"));
  v14 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v13, env->GetMethodID(env->FindClass("android/widget/CompoundButton"), "isChecked", "()Z"), v7, v7, v7, v7);
  v15 = v14;
  /* UNSUPPORTED: xor-int-lit8 */
  v17 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︊︃", "LI/ᅟ︍︋;"));
  v18 = env->AllocObject(env->FindClass("I/ᅟ︋︋"));
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("I/ᅟ︋︋"), "<init>", "(ZZ)V"), v16, v12, v7, v7);
  env->CallVoidMethod((jobject)v17, env->GetMethodID(env->FindClass("I/ᅟ︍︋"), "ᅟ︄︀", "(Ljava/lang/String;LI/ᅟ︋︋;)V"), v7, v18, v7, v7);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︁︂()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe01_0fe02__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︂︂()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe02_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v48 = NULL;
  jobject v20 = NULL;
  jobject v30 = NULL;
  jobject v39 = NULL;
  jobject v42 = NULL;
  jobject v16 = NULL;
  jint v8 = 0;
  jobject v29 = NULL;
  jobject v17 = NULL;
  jint v7 = 0;
  jobject v38 = NULL;
  jobject v33 = NULL;
  jobject v31 = NULL;
  jobject v22 = NULL;
  jobject v34 = NULL;
  jobject v26 = NULL;
  jobject v28 = NULL;
  jobject v25 = NULL;
  jobject v24 = NULL;
  jint v3 = 0;
  jobject v13 = NULL;
  jobject v12 = NULL;
  jobject v18 = NULL;
  jobject v19 = NULL;
  jobject v44 = NULL;
  jint v9 = 0;
  jint v2 = 0;
  jobject v10 = NULL;
  jobject v0 = NULL;
  jobject v43 = NULL;
  jobject v47 = NULL;
  jobject v23 = NULL;
  jobject v5 = NULL;
  jobject v37 = NULL;
  jobject v35 = NULL;
  jobject v11 = NULL;
  jobject v15 = NULL;
  jboolean v1 = 0;
  jobject v40 = NULL;
  jobject v21 = NULL;
  jobject v41 = NULL;
  jobject v46 = NULL;
  jobject v49 = NULL;
  jobject v14 = NULL;
  jobject v4 = NULL;
  jobject v6 = NULL;
  jobject v45 = NULL;
  jobject v36 = NULL;
  jobject v32 = NULL;
  jobject v27 = NULL;

L_0:
  v1 = (jboolean)(intptr_t)env->GetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︉︃", "Z"));
  v2 = 0;
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_10;
 } else { goto L_5;
 }

L_5:
  v3 = 2131886284;
  v4 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;II)Landroid/widget/Toast;"), v0, v3, v2, v3, v3);
  v5 = v4;
  env->CallVoidMethod((jobject)v5, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v5, v5, v5, v5);
  /* return terminator */
  return;

L_10:
  v6 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  v7 = 1;
  v8 = 2131886295;
  v9 = 2131886297;
  /* UNSUPPORTED: if-eqz */
  if (v6 == 0) { goto L_55;
 } else { goto L_1b;
 }

L_1b:
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v11 = (jobject)env->CallObjectMethod((jobject)v10, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getText", "()LI/ᅟ︍︆;"), v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v12 = v11;
  v13 = (jobject)env->CallObjectMethod((jobject)v12, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "toString", "()Ljava/lang/String;"), v6, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v14 = v13;
  env->CallVoidMethod((jobject)v6, env->GetMethodID(env->FindClass("I/ᅠ︍︃"), "ᅟ︄︀", "(Ljava/lang/String;)V"), v14, v6, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "Z"), v2); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v15 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;II)Landroid/widget/Toast;"), v0, v9, v2, v6, v6); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  v16 = v15;
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v16, v16, v16, v16); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︇︂", "()V"), v16, v16, v16, v16); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_3; }
goto L_34;

L_35:
  v17 = pendingException;
  v18 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "()V"), v17, v17, v17, v17);
  v19 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "getString", "(I)Ljava/lang/String;"), v8, v17, v17, v17);
  v20 = v19;
  v21 = (jobject)env->CallObjectMethod((jobject)v18, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v20, v17, v17, v17);
  v22 = (jobject)env->CallObjectMethod((jobject)v17, env->GetMethodID(env->FindClass("java/lang/Throwable"), "getMessage", "()Ljava/lang/String;"), v17, v17, v17, v17);
  v23 = v22;
  v24 = (jobject)env->CallObjectMethod((jobject)v18, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v23, v23, v23, v23);
  v25 = (jobject)env->CallObjectMethod((jobject)v18, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v23, v23, v23, v23);
  v26 = v25;
  v27 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"), v0, v26, v7, v26, v26);
  v28 = v27;
  env->CallVoidMethod((jobject)v28, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v28, v28, v28, v28);
goto L_54;

L_34:
  /* UNSUPPORTED: goto */
goto L_54;

L_54:
  /* return terminator */
  return;

L_55:
  v29 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︄︂", "LI/ᅟ︅︎;"));
  /* UNSUPPORTED: if-nez */
  if (v29 != 0) { goto L_5a;
 } else { goto L_59;
 }

L_59:
  /* return terminator */
  return;

L_5a:
  v30 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  v31 = (jobject)env->CallObjectMethod((jobject)v30, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getText", "()LI/ᅟ︍︆;"), v29, v29, v29, v29); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  v32 = v31;
  v33 = (jobject)env->CallObjectMethod((jobject)v32, env->GetMethodID(env->FindClass("I/ᅟ︍︆"), "toString", "()Ljava/lang/String;"), v29, v29, v29, v29); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  v34 = v33;
  env->SetObjectField((jobject)(intptr_t)v29, env->GetFieldID(env->FindClass("I/ᅟ︅︎"), "ᅟ︄︀", "Ljava/lang/Object;"), (jobject)(intptr_t)v34); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  v35 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︄︂", "LI/ᅟ︅︎;")); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  env->CallVoidMethod((jobject)v35, env->GetMethodID(env->FindClass("I/ᅟ︅︎"), "ᅟ︀︀", "()V"), v35, v35, v35, v35); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  env->SetBooleanField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "Z"), v2); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  v36 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;II)Landroid/widget/Toast;"), v0, v9, v2, v35, v35); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
  v37 = v36;
  env->CallVoidMethod((jobject)v37, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v37, v37, v37, v37); if(env->ExceptionCheck()){ pendingException=env->ExceptionOccurred(); env->ExceptionClear(); goto EX_LandingPad_9; }
goto L_74;

L_75:
  v38 = pendingException;
  v39 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  env->CallVoidMethod((jobject)v39, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "()V"), v38, v38, v38, v38);
  v40 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("android/content/Context"), "getString", "(I)Ljava/lang/String;"), v8, v38, v38, v38);
  v41 = v40;
  v42 = (jobject)env->CallObjectMethod((jobject)v39, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v41, v38, v38, v38);
  v43 = (jobject)env->CallObjectMethod((jobject)v38, env->GetMethodID(env->FindClass("java/lang/Throwable"), "getMessage", "()Ljava/lang/String;"), v38, v38, v38, v38);
  v44 = v43;
  v45 = (jobject)env->CallObjectMethod((jobject)v39, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v44, v44, v44, v44);
  v46 = (jobject)env->CallObjectMethod((jobject)v39, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v44, v44, v44, v44);
  v47 = v46;
  v48 = (jobject)env->CallStaticObjectMethod(env->FindClass("android/widget/Toast"), env->GetStaticMethodID(env->FindClass("android/widget/Toast"), "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"), v0, v47, v7, v47, v47);
  v49 = v48;
  env->CallVoidMethod((jobject)v49, env->GetMethodID(env->FindClass("android/widget/Toast"), "show", "()V"), v49, v49, v49, v49);
goto L_94;

L_74:
  /* UNSUPPORTED: goto */
goto L_94;

L_94:
  /* return terminator */
  return;

EX_LandingPad_3:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_35;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;

EX_LandingPad_9:
  pendingException = env->ExceptionOccurred(); env->ExceptionClear();
  if (pendingException && env->IsInstanceOf(pendingException, env->FindClass("java/lang/Exception"))) goto L_75;
  if(pendingException) env->Throw(pendingException); goto EX_UnwindBlock;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︂︂()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe02_0fe02__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︃︂()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe03_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v20 = 0;
  jobject v15 = NULL;
  jobject v23 = NULL;
  jint v6 = 0;
  jobject v1 = NULL;
  jint v2 = 0;
  jlong v8 = 0;
  jint v13 = 0;
  jobject v19 = NULL;
  jlong v9 = 0;
  jint v10 = 0;
  jobject v11 = NULL;
  jobject v21 = NULL;
  jobject v17 = NULL;
  jint v7 = 0;
  jobject v14 = NULL;
  jint v18 = 0;
  jarray v4 = NULL;
  jint v5 = 0;
  jobject v0 = NULL;
  jobject v16 = NULL;
  jobject v12 = NULL;
  jint v3 = 0;
  jint v22 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_3a;
 } else { goto L_4;
 }

L_4:
  v2 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︃︀", "I"));
  v3 = 1;
  /* UNSUPPORTED: if-gt */
  if (v2 > v3) { goto L_a;
 } else { goto L_9;
 }

L_9:
  /* UNSUPPORTED: goto */
goto L_3a;

L_a:
  v4 = env->NewObjectArray((jsize)(intptr_t)v2, env->FindClass("java/lang/String"), NULL);
  v5 = 0;
v6 = (jint)v5; v7 = (jint)v2; goto L_d;

L_d:
  /* UNSUPPORTED: if-ge */
  if (v6 >= v7) { goto L_19;
 } else { goto L_f;
 }

L_f:
  /* UNSUPPORTED: add-int-lit8 */
  v11 = (jobject)env->CallStaticObjectMethod(env->FindClass("java/lang/String"), env->GetStaticMethodID(env->FindClass("java/lang/String"), "valueOf", "(I)Ljava/lang/String;"), v10, v7, v7, v7, v7);
  v12 = (jobject)(intptr_t)v11;
  env->SetObjectArrayElement((jobjectArray)v4, (jsize)v6, (jobject)(intptr_t)v12);
  /* dbg-move v13 v10 dv=I sv=I */
  /* UNSUPPORTED: goto */
v6 = (jint)(intptr_t)v8; v7 = (jint)(intptr_t)v9; goto L_d;

L_19:
  v14 = env->AllocObject(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"));
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "<init>", "(Landroid/content/Context;)V"), v0, v14, v14, v14);
  v15 = (jobject)env->GetObjectField((jobject)(intptr_t)v14, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︀︀", "Landroidx/appcompat/app/AlertController$AlertParams;"));
  v16 = env->NewStringUTF("Paging editing");
  env->SetObjectField((jobject)(intptr_t)v15, env->GetFieldID(env->FindClass("androidx/appcompat/app/AlertController$AlertParams"), "ᅟ︃︀", "Ljava/lang/CharSequence;"), (jobject)(intptr_t)v16);
  v17 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  v18 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v18, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︄︀", "I"));
  v19 = env->AllocObject(env->FindClass("I/ᅠ︊︉"));
  v20 = 3;
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("I/ᅠ︊︉"), "<init>", "(Lbin/nt/main/TextEditorActivity;I)V"), v0, v20, v14, v14);
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︆︀", "([Ljava/lang/CharSequence;ILandroid/content/DialogInterface$OnClickListener;)V"), v4, v18, v19, v14);
  v21 = env->NewStringUTF("CLOSE");
  v22 = 0;
  v23 = (jobject)env->CallObjectMethod((jobject)v14, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︃︀", "(Ljava/lang/CharSequence;Landroid/content/DialogInterface$OnClickListener;)Landroidx/appcompat/app/AlertDialog$Builder;"), v21, v22, v14, v14);
  env->CallVoidMethod((jobject)v14, env->GetMethodID(env->FindClass("androidx/appcompat/app/AlertDialog$Builder"), "ᅟ︉︀", "()V"), v14, v14, v14, v14);
goto L_3a;

L_3a:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︃︂()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe03_0fe02__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︄︂()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe04_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v36 = 0;
  jobject v22 = NULL;
  jobject v31 = NULL;
  jobject v14 = NULL;
  jlong v38 = 0;
  jobject v15 = NULL;
  jboolean v18 = 0;
  jboolean v19 = 0;
  jobject v8 = NULL;
  jobject v24 = NULL;
  jobject v30 = NULL;
  jint v28 = 0;
  jlong v39 = 0;
  jobject v35 = NULL;
  jobject v0 = NULL;
  jobject v20 = NULL;
  jobject v23 = NULL;
  jint v13 = 0;
  jboolean v25 = 0;
  jint v34 = 0;
  jobject v12 = NULL;
  jobject v16 = NULL;
  jobject v1 = NULL;
  jboolean v10 = 0;
  jint v17 = 0;
  jint v5 = 0;
  jobject v27 = NULL;
  jobject v7 = NULL;
  jboolean v32 = 0;
  jobject v4 = NULL;
  jint v21 = 0;
  jobject v2 = NULL;
  jobject v37 = NULL;
  jboolean v11 = 0;
  jboolean v26 = 0;
  jobject v3 = NULL;
  jobject v29 = NULL;
  jobject v6 = NULL;
  jint v9 = 0;
  jboolean v33 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︋︂", "Landroidx/appcompat/widget/PopupMenu;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_54;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("androidx/appcompat/widget/PopupMenu"), "ᅟ︀︀", "Landroidx/appcompat/view/menu/MenuBuilder;"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_9;
 } else { goto L_8;
 }

L_8:
  /* UNSUPPORTED: goto */
goto L_54;

L_9:
  v3 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v4, env->GetFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︄︀", "Landroid/content/SharedPreferences;"));
  v5 = 2131362126;
  v6 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/view/menu/MenuBuilder"), "findItem", "(I)Landroid/view/MenuItem;"), v5, v2, v2, v2);
  v7 = v6;
  v8 = env->NewStringUTF("editor_word_wrap");
  v9 = 0;
  v10 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getBoolean", "(Ljava/lang/String;Z)Z"), v8, v9, v2, v2);
  v11 = v10;
  v12 = (jobject)env->CallObjectMethod((jobject)v7, env->GetMethodID(env->FindClass("android/view/MenuItem"), "setChecked", "(Z)Landroid/view/MenuItem;"), v11, v2, v2, v2);
  v13 = 2131362114;
  v14 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/view/menu/MenuBuilder"), "findItem", "(I)Landroid/view/MenuItem;"), v13, v2, v2, v2);
  v15 = v14;
  v16 = env->NewStringUTF("editor_show_line_numbers");
  v17 = 1;
  v18 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getBoolean", "(Ljava/lang/String;Z)Z"), v16, v17, v2, v2);
  v19 = v18;
  v20 = (jobject)env->CallObjectMethod((jobject)v15, env->GetMethodID(env->FindClass("android/view/MenuItem"), "setChecked", "(Z)Landroid/view/MenuItem;"), v19, v2, v2, v2);
  v21 = 2131362123;
  v22 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/view/menu/MenuBuilder"), "findItem", "(I)Landroid/view/MenuItem;"), v21, v2, v2, v2);
  v23 = v22;
  v24 = env->NewStringUTF("editor_symbol_bar");
  v25 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v4, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getBoolean", "(Ljava/lang/String;Z)Z"), v24, v17, v2, v2);
  v26 = v25;
  v27 = (jobject)env->CallObjectMethod((jobject)v23, env->GetMethodID(env->FindClass("android/view/MenuItem"), "setChecked", "(Z)Landroid/view/MenuItem;"), v26, v2, v2, v2);
  v28 = 2131362116;
  v29 = (jobject)env->CallObjectMethod((jobject)v2, env->GetMethodID(env->FindClass("androidx/appcompat/view/menu/MenuBuilder"), "findItem", "(I)Landroid/view/MenuItem;"), v28, v2, v2, v2);
  v30 = v29;
  v31 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;"));
  /* UNSUPPORTED: if-eqz */
  if (v31 == 0) { v36 = (jint)v9; v37 = (jobject)v30; goto L_51;
 } else { goto L_4a;
 }

L_4a:
  v32 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v31, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "ᅟ︉︂", "()Z"), v30, v30, v30, v30);
  v33 = v32;
  /* UNSUPPORTED: if-nez */
  if (v33 != 0) { v36 = (jint)v9; v37 = (jobject)v30; goto L_51;
 } else { goto L_50;
 }

L_50:
  v34 = 1;
v36 = (jint)(intptr_t)v38; v37 = (jobject)(intptr_t)v39; goto L_51;

L_51:
  v35 = (jobject)env->CallObjectMethod((jobject)v37, env->GetMethodID(env->FindClass("android/view/MenuItem"), "setChecked", "(Z)Landroid/view/MenuItem;"), v36, v37, v37, v37);
goto L_54;

L_54:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︄︂()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe04_0fe02__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︅︁()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe05_0fe01__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jint v6 = 0;
  jobject v7 = NULL;
  jint v5 = 0;
  jlong v9 = 0;
  jlong v12 = 0;
  jobject v0 = NULL;
  jobject v8 = NULL;
  jobject v10 = NULL;
  jint v4 = 0;
  jint v1 = 0;
  jlong v11 = 0;
  jobject v2 = NULL;
  jobject v3 = NULL;

L_0:
  v1 = 2131361997;
  v2 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "findViewById", "(I)Landroid/view/View;"), v1, v1, v1, v1);
  v3 = v2;
  /* UNSUPPORTED: if-eqz */
  if (v3 == 0) { goto L_e;
 } else { goto L_9;
 }

L_9:
  v4 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/BaseActivity"), "ᅟ︎︁", "I"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/view/View"), "setBackgroundColor", "(I)V"), v4, v3, v3, v3);
goto L_e;

L_e:
  v5 = (jint)(intptr_t)env->CallStaticIntMethod(env->FindClass("I/ᅠ︄︉"), env->GetStaticMethodID(env->FindClass("I/ᅠ︄︉"), "ᅟ︁︁", "(Landroid/content/Context;)I"), v0, v3, v3, v3, v3);
  v6 = v5;
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︅︃", "Landroid/widget/TextView;"));
  /* UNSUPPORTED: if-eqz */
  if (v7 == 0) { goto L_19;
 } else { goto L_16;
 }

L_16:
  env->CallVoidMethod((jobject)v7, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextColor", "(I)V"), v6, v6, v6, v6);
goto L_19;

L_19:
  v8 = (jobject)env->GetObjectField((jobject)(intptr_t)v9, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︃", "Landroid/widget/TextView;"));
  /* UNSUPPORTED: if-eqz */
  if (v8 == 0) { goto L_20;
 } else { goto L_1d;
 }

L_1d:
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextColor", "(I)V"), v6, v6, v6, v6);
goto L_20;

L_20:
  v10 = (jobject)env->GetObjectField((jobject)(intptr_t)v11, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︉︂", "Landroid/widget/TextView;"));
  /* UNSUPPORTED: if-eqz */
  if (v10 == 0) { goto L_27;
 } else { goto L_24;
 }

L_24:
  env->CallVoidMethod((jobject)v10, env->GetMethodID(env->FindClass("android/widget/TextView"), "setTextColor", "(I)V"), v12, v12, v12, v12);
goto L_27;

L_27:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︁()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe05_0fe01__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︅︂(Z)V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe05_0fe02__Z(JNIEnv* env, jobject thiz, jboolean p0) {
  jthrowable pendingException = NULL;
  jobject v3 = NULL;
  jint v2 = 0;
  jboolean v15 = 0;
  jint v6 = 0;
  jobject v4 = NULL;
  jint v9 = 0;
  jobject v13 = NULL;
  jobject v8 = NULL;
  jobject v14 = NULL;
  jint v16 = 0;
  jobject v0 = NULL;
  jint v10 = 0;
  jint v11 = 0;
  jobject v12 = NULL;
  jboolean v1 = 0;
  jint v5 = 0;
  jobject v7 = NULL;

L_0:
  v2 = 2131362277;
  v3 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "findViewById", "(I)Landroid/view/View;"), v2, v2, v2, v2);
  v4 = v3;
  v5 = 0;
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v5, v4, v4, v4);
  v6 = 2131362241;
  v7 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "findViewById", "(I)Landroid/view/View;"), v6, v6, v6, v6);
  v8 = v7;
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_16;
 } else { goto L_14;
 }

L_14:
  v9 = 0;
  /* UNSUPPORTED: goto */
v16 = (jint)v9; goto L_18;

L_16:
  v10 = 8;
v16 = (jint)v10; goto L_18;

L_18:
  env->CallVoidMethod((jobject)v8, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v16, v8, v8, v8);
  v11 = 2131362284;
  v12 = (jobject)env->CallObjectMethod((jobject)v0, env->GetMethodID(env->FindClass("androidx/appcompat/app/AppCompatActivity"), "findViewById", "(I)Landroid/view/View;"), v11, v8, v8, v8);
  v13 = v12;
  env->CallVoidMethod((jobject)v13, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v5, v8, v8, v8);
  v14 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︁︃", "Landroid/widget/EditText;"));
  v15 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v14, env->GetMethodID(env->FindClass("android/view/View"), "requestFocus", "()Z"), v8, v8, v8, v8);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︅︂(Z)V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe05_0fe02__Z */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︆︂()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe06_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v12 = NULL;
  jobject v7 = NULL;
  jobject v23 = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jobject v14 = NULL;
  jobject v32 = NULL;
  jobject v28 = NULL;
  jint v17 = 0;
  jobject v2 = NULL;
  jobject v11 = NULL;
  jobject v25 = NULL;
  jobject v27 = NULL;
  jint v9 = 0;
  jobject v20 = NULL;
  jobject v19 = NULL;
  jint v29 = 0;
  jobject v16 = NULL;
  jobject v5 = NULL;
  jobject v3 = NULL;
  jobject v0 = NULL;
  jobject v10 = NULL;
  jobject v22 = NULL;
  jobject v30 = NULL;
  jobject v15 = NULL;
  jobject v24 = NULL;
  jint v18 = 0;
  jobject v13 = NULL;
  jobject v33 = NULL;
  jobject v31 = NULL;
  jobject v6 = NULL;
  jobject v21 = NULL;
  jobject v26 = NULL;
  jint v8 = 0;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { goto L_54;
 } else { goto L_4;
 }

L_4:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︃", "Landroid/widget/TextView;"));
  /* UNSUPPORTED: if-nez */
  if (v2 != 0) { goto L_9;
 } else { goto L_8;
 }

L_8:
  /* UNSUPPORTED: goto */
goto L_54;

L_9:
  v3 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "()V"), v3, v3, v3, v3);
  v4 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;"));
  v5 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getCursor", "()LI/ᅟ︅︇;"), v3, v3, v3, v3);
  v6 = v5;
  v7 = (jobject)env->GetObjectField((jobject)(intptr_t)v7, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v8 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v8, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︁︀", "I"));
  /* UNSUPPORTED: add-int-lit8 */
  v10 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(I)Ljava/lang/StringBuilder;"), v9, v3, v3, v3);
  v11 = env->NewStringUTF(":");
  v12 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v11, v3, v3, v3);
  v13 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︃︂", "Lbin/nt/editor/widget/CodeEditor;"));
  v14 = (jobject)env->CallObjectMethod((jobject)v13, env->GetMethodID(env->FindClass("bin/nt/editor/widget/CodeEditor"), "getCursor", "()LI/ᅟ︅︇;"), v3, v3, v3, v3);
  v15 = v14;
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v16, env->GetFieldID(env->FindClass("I/ᅟ︅︇"), "ᅟ︂︀", "LI/ᅟ︂︅;"));
  v17 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v17, env->GetFieldID(env->FindClass("I/ᅟ︂︅"), "ᅟ︂︀", "I"));
  /* UNSUPPORTED: add-int-lit8 */
  v19 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(I)Ljava/lang/StringBuilder;"), v18, v3, v3, v3);
  v20 = env->NewStringUTF("   ");
  v21 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v20, v3, v3, v3);
  v22 = (jobject)env->CallObjectMethod((jobject)v3, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v3, v3, v3, v3);
  v23 = v22;
  v24 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︄︂", "LI/ᅟ︅︎;"));
  /* UNSUPPORTED: if-eqz */
  if (v24 == 0) { goto L_4f;
 } else { goto L_3e;
 }

L_3e:
  v25 = (jobject)env->CallStaticObjectMethod(env->FindClass("I/ᅟ︍︀"), env->GetStaticMethodID(env->FindClass("I/ᅟ︍︀"), "ᅟ︎︀", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v23, v23, v23, v23, v23);
  v26 = v25;
  v27 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︄︂", "LI/ᅟ︅︎;"));
  v28 = (jobject)env->GetObjectField((jobject)(intptr_t)v28, env->GetFieldID(env->FindClass("I/ᅟ︅︎"), "ᅟ︀︀", "Ljava/lang/Object;"));
  if(v0 && !env->IsInstanceOf((jobject)v0, env->FindClass("java/lang/String"))) { env->ThrowNew(env->FindClass("java/lang/ClassCastException"), "check-cast"); goto EX_UnwindBlock; }
  v30 = (jobject)env->CallObjectMethod((jobject)v26, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v29, v26, v26, v26);
  v31 = (jobject)env->CallObjectMethod((jobject)v26, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v26, v26, v26, v26);
  v32 = v31;
goto L_4f;

L_4f:
  v33 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︃", "Landroid/widget/TextView;"));
  env->CallVoidMethod((jobject)v33, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(Ljava/lang/CharSequence;)V"), v23, v23, v23, v23);
goto L_54;

L_54:
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︆︂()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe06_0fe02__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︇︂()V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe07_0fe02__(JNIEnv* env, jobject thiz) {
  jthrowable pendingException = NULL;
  jobject v38 = NULL;
  jobject v9 = NULL;
  jobject v28 = NULL;
  jint v17 = 0;
  jobject v21 = NULL;
  jobject v18 = NULL;
  jint v31 = 0;
  jobject v40 = NULL;
  jobject v37 = NULL;
  jint v6 = 0;
  jint v3 = 0;
  jobject v16 = NULL;
  jobject v24 = NULL;
  jobject v4 = NULL;
  jlong v34 = 0;
  jobject v36 = NULL;
  jobject v14 = NULL;
  jobject v13 = NULL;
  jobject v10 = NULL;
  jobject v15 = NULL;
  jobject v8 = NULL;
  jint v12 = 0;
  jobject v35 = NULL;
  jobject v33 = NULL;
  jobject v1 = NULL;
  jobject v5 = NULL;
  jobject v26 = NULL;
  jint v7 = 0;
  jobject v20 = NULL;
  jobject v22 = NULL;
  jobject v27 = NULL;
  jobject v11 = NULL;
  jobject v32 = NULL;
  jobject v19 = NULL;
  jobject v30 = NULL;
  jobject v39 = NULL;
  jint v2 = 0;
  jobject v0 = NULL;
  jobject v23 = NULL;
  jobject v25 = NULL;
  jobject v29 = NULL;

L_0:
  v1 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  /* UNSUPPORTED: if-eqz */
  if (v1 == 0) { v33 = (jobject)v0; goto L_55;
 } else { goto L_4;
 }

L_4:
  v2 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v2, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︃︀", "I"));
  v3 = 1;
  /* UNSUPPORTED: if-gt */
  if (v2 > v3) { goto L_a;
 } else { goto L_9;
 }

L_9:
  /* UNSUPPORTED: goto */
v33 = (jobject)(intptr_t)v34; goto L_55;

L_a:
  v4 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  env->CallVoidMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "()V"), v4, v4, v4, v4);
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  v6 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v6, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︄︀", "I"));
  /* UNSUPPORTED: add-int-2addr */
  v8 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(I)Ljava/lang/StringBuilder;"), v7, v4, v4, v4);
  v9 = env->NewStringUTF("/");
  v10 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v9, v4, v4, v4);
  v11 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  v12 = (jint)(intptr_t)env->GetIntField((jobject)(intptr_t)v12, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︃︀", "I"));
  v13 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(I)Ljava/lang/StringBuilder;"), v12, v4, v4, v4);
  v14 = (jobject)env->CallObjectMethod((jobject)v4, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v4, v4, v4, v4);
  v15 = v14;
  v16 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︉︂", "Landroid/widget/TextView;"));
  v17 = 0;
  env->CallVoidMethod((jobject)v16, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v17, v15, v15, v15);
  v18 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︉︂", "Landroid/widget/TextView;"));
  env->CallVoidMethod((jobject)v18, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(Ljava/lang/CharSequence;)V"), v15, v15, v15, v15);
  v19 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︅︃", "Landroid/widget/TextView;"));
  v20 = env->AllocObject(env->FindClass("java/lang/StringBuilder"));
  v21 = env->NewStringUTF("(");
  env->CallVoidMethod((jobject)v20, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "<init>", "(Ljava/lang/String;)V"), v21, v15, v15, v15);
  v22 = (jobject)env->CallObjectMethod((jobject)v20, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v15, v15, v15, v15);
  v23 = env->NewStringUTF(") ");
  v24 = (jobject)env->CallObjectMethod((jobject)v20, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v23, v23, v23, v23);
  v25 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  v26 = (jobject)env->GetObjectField((jobject)(intptr_t)v26, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︀︀", "Ljava/lang/String;"));
  v27 = (jobject)env->CallObjectMethod((jobject)v20, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "append", "(Ljava/lang/String;)Ljava/lang/StringBuilder;"), v26, v26, v26, v26);
  v28 = (jobject)env->CallObjectMethod((jobject)v20, env->GetMethodID(env->FindClass("java/lang/StringBuilder"), "toString", "()Ljava/lang/String;"), v26, v26, v26, v26);
  v29 = v28;
  env->CallVoidMethod((jobject)v19, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(Ljava/lang/CharSequence;)V"), v29, v29, v29, v29);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "()V"), v29, v29, v29, v29);
  /* return terminator */
  return;

L_55:
  v30 = (jobject)env->GetObjectField((jobject)(intptr_t)v33, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︉︂", "Landroid/widget/TextView;"));
  v31 = 8;
  env->CallVoidMethod((jobject)v30, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v31, v30, v30, v30);
  v32 = (jobject)env->GetObjectField((jobject)(intptr_t)v33, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︂", "LI/ᅠ︍︃;"));
  /* UNSUPPORTED: if-eqz */
  if (v32 == 0) { goto L_63;
 } else { goto L_60;
 }

L_60:
  v35 = (jobject)env->GetObjectField((jobject)(intptr_t)v35, env->GetFieldID(env->FindClass("I/ᅠ︍︃"), "ᅟ︀︀", "Ljava/lang/String;"));
  /* UNSUPPORTED: goto */
v40 = (jobject)v35; goto L_6c;

L_63:
  v36 = (jobject)env->GetObjectField((jobject)(intptr_t)v33, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︄︂", "LI/ᅟ︅︎;"));
  /* UNSUPPORTED: if-eqz */
  if (v36 == 0) { goto L_6a;
 } else { goto L_67;
 }

L_67:
  v37 = (jobject)env->GetObjectField((jobject)(intptr_t)v37, env->GetFieldID(env->FindClass("I/ᅟ︅︎"), "ᅟ︃︀", "Ljava/lang/String;"));
  /* UNSUPPORTED: goto */
v40 = (jobject)v37; goto L_6c;

L_6a:
  v38 = env->NewStringUTF("untitled");
v40 = (jobject)v38; goto L_6c;

L_6c:
  v39 = (jobject)env->GetObjectField((jobject)(intptr_t)v33, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︅︃", "Landroid/widget/TextView;"));
  env->CallVoidMethod((jobject)v39, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(Ljava/lang/CharSequence;)V"), v40, v40, v40, v40);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︇︂()V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe07_0fe02__ */

/* Lbin/nt/main/TextEditorActivity;->ᅟ︍︁(Ljava/lang/String;)V */
void Java_bin_nt_main_TextEditorActivity__0115f_0fe0d_0fe01__Ljava_lang_String_2(JNIEnv* env, jobject thiz, jobject p0) {
  jthrowable pendingException = NULL;
  jobject v2 = NULL;
  jint v7 = 0;
  jboolean v9 = 0;
  jint v11 = 0;
  jobject v0 = NULL;
  jboolean v8 = 0;
  jobject v3 = NULL;
  jobject v1 = NULL;
  jobject v4 = NULL;
  jobject v6 = NULL;
  jint v10 = 0;
  jobject v5 = NULL;

L_0:
  v2 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︅︃", "Landroid/widget/TextView;"));
  env->CallVoidMethod((jobject)v2, env->GetMethodID(env->FindClass("android/widget/TextView"), "setText", "(Ljava/lang/CharSequence;)V"), v1, v2, v2, v2);
  env->CallVoidMethod((jobject)v0, env->GetMethodID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︆︂", "()V"), v2, v2, v2, v2);
  v3 = (jobject)env->GetObjectField((jobject)(intptr_t)v0, env->GetFieldID(env->FindClass("bin/nt/main/TextEditorActivity"), "ᅟ︈︃", "Landroid/view/View;"));
  v4 = (jobject)env->GetStaticObjectField(env->FindClass("bin/nt/main/App"), env->GetStaticFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︆︀", "Lbin/nt/main/App;"));
  v5 = (jobject)env->GetObjectField((jobject)(intptr_t)v5, env->GetFieldID(env->FindClass("bin/nt/main/App"), "ᅟ︄︀", "Landroid/content/SharedPreferences;"));
  v6 = env->NewStringUTF("editor_symbol_bar");
  v7 = 0;
  v8 = (jboolean)(intptr_t)env->CallBooleanMethod((jobject)v5, env->GetMethodID(env->FindClass("android/content/SharedPreferences"), "getBoolean", "(Ljava/lang/String;Z)Z"), v6, v7, v5, v5);
  v9 = v8;
  /* UNSUPPORTED: if-eqz */
  if (v9 == 0) { goto L_18;
 } else { goto L_17;
 }

L_17:
  /* UNSUPPORTED: goto */
v11 = (jint)v7; goto L_1a;

L_18:
  v10 = 8;
v11 = (jint)v10; goto L_1a;

L_1a:
  env->CallVoidMethod((jobject)v3, env->GetMethodID(env->FindClass("android/view/View"), "setVisibility", "(I)V"), v11, v9, v9, v9);
  /* return terminator */
  return;
EX_Return: return;
EX_UnwindBlock: return;
}

/* RegisterNatives entry for ᅟ︍︁(Ljava/lang/String;)V -> Java_bin_nt_main_TextEditorActivity__0115f_0fe0d_0fe01__Ljava_lang_String_2 */

/* FAILED Lbin/nt/main/TextEditorActivity;->ᅟ︎︁(Landroid/view/MenuItem;)Z: java.lang.IllegalStateException: unknown phi type v0_0 = phi[] */

/* FAILED Lbin/nt/main/TextEditorActivity;->ᅟ️︁()V: java.lang.IllegalStateException: unknown phi type v0_4 = phi[v0_2, v0_5 = phi[v0_2], v0_2] */
