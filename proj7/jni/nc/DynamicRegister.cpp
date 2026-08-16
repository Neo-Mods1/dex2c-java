#include <jni.h>

#include "dex2c.hpp"

const char *dynamic_register_compile_methods(JNIEnv *env) {
    jclass clazz;
    clazz = env->FindClass("I/ᅟ︀︃");
    if (clazz == NULL) return "Class not found: I/ᅟ︀︃";
    const JNINativeMethod export_method_0[] = {
        {"<init>", "(Lbin/nt/main/App;)V", (void *)Java_I__0115f_0fe00_0fe03__0003cinit_0003e__Lbin_nt_main_App_2},
    };
    env->RegisterNatives(clazz, export_method_0, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︀︇");
    if (clazz == NULL) return "Class not found: I/ᅟ︀︇";
    const JNINativeMethod export_method_1[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;ILI/ᅟ︂︅;LI/ᅟ︂︅;Ljava/lang/CharSequence;Z)V", (void *)Java_I__0115f_0fe00_0fe07__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2ILI__0115f_0fe02_0fe05_2LI__0115f_0fe02_0fe05_2Ljava_lang_CharSequence_2Z},
    };
    env->RegisterNatives(clazz, export_method_1, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︀︌");
    if (clazz == NULL) return "Class not found: I/ᅟ︀︌";
    const JNINativeMethod export_method_2[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe00_0fe0c__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_2, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︁︁");
    if (clazz == NULL) return "Class not found: I/ᅟ︁︁";
    const JNINativeMethod export_method_3[] = {
        {"<init>", "(Lbin/nt/main/BaseActivity;LI/ᅟ︎︀;Landroid/graphics/Bitmap;[F[Z)V", (void *)Java_I__0115f_0fe01_0fe01__0003cinit_0003e__Lbin_nt_main_BaseActivity_2LI__0115f_0fe0e_0fe00_2Landroid_graphics_Bitmap_2_3F_3Z},
    };
    env->RegisterNatives(clazz, export_method_3, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︁︌");
    if (clazz == NULL) return "Class not found: I/ᅟ︁︌";
    const JNINativeMethod export_method_4[] = {
        {"ᅟ︃︁", "(Lbin/nt/editor/widget/CodeEditor;FF)V", (void *)Java_I__0115f_0fe01_0fe0c__0115f_0fe03_0fe01__Lbin_nt_editor_widget_CodeEditor_2FF},
    };
    env->RegisterNatives(clazz, export_method_4, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︁︎");
    if (clazz == NULL) return "Class not found: I/ᅟ︁︎";
    const JNINativeMethod export_method_5[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;)V", (void *)Java_I__0115f_0fe01_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2},
    };
    env->RegisterNatives(clazz, export_method_5, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︂︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︂︍";
    const JNINativeMethod export_method_6[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;I)V", (void *)Java_I__0115f_0fe02_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2I},
    };
    env->RegisterNatives(clazz, export_method_6, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︃︁");
    if (clazz == NULL) return "Class not found: I/ᅟ︃︁";
    const JNINativeMethod export_method_7[] = {
        {"ᅟ︄︁", "(Lbin/nt/editor/widget/CodeEditor;FF)V", (void *)Java_I__0115f_0fe03_0fe01__0115f_0fe04_0fe01__Lbin_nt_editor_widget_CodeEditor_2FF},
    };
    env->RegisterNatives(clazz, export_method_7, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︃︆");
    if (clazz == NULL) return "Class not found: I/ᅟ︃︆";
    const JNINativeMethod export_method_8[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Z)V", (void *)Java_I__0115f_0fe03_0fe06__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Z},
    };
    env->RegisterNatives(clazz, export_method_8, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︃︇");
    if (clazz == NULL) return "Class not found: I/ᅟ︃︇";
    const JNINativeMethod export_method_9[] = {
        {"<init>", "(Lbin/nt/main/CrashActivity;I)V", (void *)Java_I__0115f_0fe03_0fe07__0003cinit_0003e__Lbin_nt_main_CrashActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_9, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︃︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︃︍";
    const JNINativeMethod export_method_10[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;ZILjava/lang/String;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;)V", (void *)Java_I__0115f_0fe03_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2ZILjava_lang_String_2Ljava_io_File_2Ljava_lang_String_2Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_10, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︄︀");
    if (clazz == NULL) return "Class not found: I/ᅟ︄︀";
    const JNINativeMethod export_method_11[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/Object;Ljava/io/Serializable;Ljava/io/Serializable;)V", (void *)Java_I__0115f_0fe04_0fe00__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_Object_2Ljava_io_Serializable_2Ljava_io_Serializable_2},
    };
    env->RegisterNatives(clazz, export_method_11, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︄︇");
    if (clazz == NULL) return "Class not found: I/ᅟ︄︇";
    const JNINativeMethod export_method_12[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;Landroid/view/ContextMenu;LI/ᅟ︂︅;)V", (void *)Java_I__0115f_0fe04_0fe07__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Landroid_view_ContextMenu_2LI__0115f_0fe02_0fe05_2},
    };
    env->RegisterNatives(clazz, export_method_12, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︄︊");
    if (clazz == NULL) return "Class not found: I/ᅟ︄︊";
    const JNINativeMethod export_method_13[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe04_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_13, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︄︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︄︍";
    const JNINativeMethod export_method_14[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Landroid/net/Uri;Ljava/lang/String;Ljava/util/List;LI/ᅟ︋︋;Landroid/widget/EditText;Landroid/widget/EditText;Landroid/widget/EditText;)V", (void *)Java_I__0115f_0fe04_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_net_Uri_2Ljava_lang_String_2Ljava_util_List_2LI__0115f_0fe0b_0fe0b_2Landroid_widget_EditText_2Landroid_widget_EditText_2Landroid_widget_EditText_2},
    };
    env->RegisterNatives(clazz, export_method_14, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︄︎");
    if (clazz == NULL) return "Class not found: I/ᅟ︄︎";
    const JNINativeMethod export_method_15[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;[ZLjava/util/List;Ljava/lang/String;)V", (void *)Java_I__0115f_0fe04_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2_3ZLjava_util_List_2Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_15, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︅︁");
    if (clazz == NULL) return "Class not found: I/ᅟ︅︁";
    const JNINativeMethod export_method_16[] = {
        {"ᅟ︆︁", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe05_0fe01__0115f_0fe06_0fe01__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_16, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︅︊");
    if (clazz == NULL) return "Class not found: I/ᅟ︅︊";
    const JNINativeMethod export_method_17[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;Z)V", (void *)Java_I__0115f_0fe05_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Z},
    };
    env->RegisterNatives(clazz, export_method_17, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︅︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︅︍";
    const JNINativeMethod export_method_18[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Z)V", (void *)Java_I__0115f_0fe05_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Z},
    };
    env->RegisterNatives(clazz, export_method_18, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︅️");
    if (clazz == NULL) return "Class not found: I/ᅟ︅️";
    const JNINativeMethod export_method_19[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;IZ)V", (void *)Java_I__0115f_0fe05_0fe0f__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2IZ},
    };
    env->RegisterNatives(clazz, export_method_19, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︆︁");
    if (clazz == NULL) return "Class not found: I/ᅟ︆︁";
    const JNINativeMethod export_method_20[] = {
        {"ᅟ︃︁", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe06_0fe01__0115f_0fe03_0fe01__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_20, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︆︃");
    if (clazz == NULL) return "Class not found: I/ᅟ︆︃";
    const JNINativeMethod export_method_21[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/io/File;LI/ᅟ︍︎;)V", (void *)Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_io_File_2LI__0115f_0fe0d_0fe0e_2},
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/util/ArrayList;Ljava/io/File;Ljava/lang/String;)V", (void *)Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_util_ArrayList_2Ljava_io_File_2Ljava_lang_String_2},
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;[ZLjava/lang/String;Ljava/io/File;)V", (void *)Java_I__0115f_0fe06_0fe03__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2_3ZLjava_lang_String_2Ljava_io_File_2},
    };
    env->RegisterNatives(clazz, export_method_21, 3);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︆︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︆︍";
    const JNINativeMethod export_method_22[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;IILjava/lang/String;Ljava/lang/String;ZJLjava/util/ArrayList;Ljava/lang/String;)V", (void *)Java_I__0115f_0fe06_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2IILjava_lang_String_2Ljava_lang_String_2ZJLjava_util_ArrayList_2Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_22, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︆︎");
    if (clazz == NULL) return "Class not found: I/ᅟ︆︎";
    const JNINativeMethod export_method_23[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe06_0fe0e__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/Serializable;Ljava/lang/Object;)V", (void *)Java_I__0115f_0fe06_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_Serializable_2Ljava_lang_Object_2},
    };
    env->RegisterNatives(clazz, export_method_23, 2);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︇︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︇︍";
    const JNINativeMethod export_method_24[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;LI/ᅟ︋︋;Landroid/content/Context;Ljava/lang/String;Ljava/util/List;)V", (void *)Java_I__0115f_0fe07_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2LI__0115f_0fe0b_0fe0b_2Landroid_content_Context_2Ljava_lang_String_2Ljava_util_List_2},
    };
    env->RegisterNatives(clazz, export_method_24, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︈︌");
    if (clazz == NULL) return "Class not found: I/ᅟ︈︌";
    const JNINativeMethod export_method_25[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe08_0fe0c__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_25, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︈︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︈︍";
    const JNINativeMethod export_method_26[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;ZLandroid/content/Context;IIZ)V", (void *)Java_I__0115f_0fe08_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2ZLandroid_content_Context_2IIZ},
    };
    env->RegisterNatives(clazz, export_method_26, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︈︎");
    if (clazz == NULL) return "Class not found: I/ᅟ︈︎";
    const JNINativeMethod export_method_27[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;)V", (void *)Java_I__0115f_0fe08_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2},
    };
    env->RegisterNatives(clazz, export_method_27, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︉︅");
    if (clazz == NULL) return "Class not found: I/ᅟ︉︅";
    const JNINativeMethod export_method_28[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;Ljava/lang/Runnable;I)V", (void *)Java_I__0115f_0fe09_0fe05__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Ljava_lang_Runnable_2I},
    };
    env->RegisterNatives(clazz, export_method_28, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︉︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︉︍";
    const JNINativeMethod export_method_29[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/lang/String;LI/ᅟ️︁;LI/ᅟ︎︎;Z)V", (void *)Java_I__0115f_0fe09_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_lang_String_2LI__0115f_0fe0f_0fe01_2LI__0115f_0fe0e_0fe0e_2Z},
    };
    env->RegisterNatives(clazz, export_method_29, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︉︎");
    if (clazz == NULL) return "Class not found: I/ᅟ︉︎";
    const JNINativeMethod export_method_30[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︁︍;LI/ᅟ︁︍;)V", (void *)Java_I__0115f_0fe09_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe01_0fe0d_2LI__0115f_0fe01_0fe0d_2},
    };
    env->RegisterNatives(clazz, export_method_30, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︊︀");
    if (clazz == NULL) return "Class not found: I/ᅟ︊︀";
    const JNINativeMethod export_method_31[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︍︆;)V", (void *)Java_I__0115f_0fe0a_0fe00__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe0d_0fe06_2},
    };
    env->RegisterNatives(clazz, export_method_31, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︊︊");
    if (clazz == NULL) return "Class not found: I/ᅟ︊︊";
    const JNINativeMethod export_method_32[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe0a_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_32, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︊︋");
    if (clazz == NULL) return "Class not found: I/ᅟ︊︋";
    const JNINativeMethod export_method_33[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Landroid/content/Context;Ljava/lang/String;Ljava/lang/Object;I)V", (void *)Java_I__0115f_0fe0a_0fe0b__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Landroid_content_Context_2Ljava_lang_String_2Ljava_lang_Object_2I},
    };
    env->RegisterNatives(clazz, export_method_33, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︊︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︊︍";
    const JNINativeMethod export_method_34[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Z)V", (void *)Java_I__0115f_0fe0a_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2Z},
    };
    env->RegisterNatives(clazz, export_method_34, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︊︎");
    if (clazz == NULL) return "Class not found: I/ᅟ︊︎";
    const JNINativeMethod export_method_35[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;Z)V", (void *)Java_I__0115f_0fe0a_0fe0e__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2Z},
    };
    env->RegisterNatives(clazz, export_method_35, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︋︉");
    if (clazz == NULL) return "Class not found: I/ᅟ︋︉";
    const JNINativeMethod export_method_36[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe0b_0fe09__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_36, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︋︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︋︍";
    const JNINativeMethod export_method_37[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅟ︎︎;I)V", (void *)Java_I__0115f_0fe0b_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__0115f_0fe0e_0fe0e_2I},
    };
    env->RegisterNatives(clazz, export_method_37, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︌︄");
    if (clazz == NULL) return "Class not found: I/ᅟ︌︄";
    const JNINativeMethod export_method_38[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__0115f_0fe0c_0fe04__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_38, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︌︊");
    if (clazz == NULL) return "Class not found: I/ᅟ︌︊";
    const JNINativeMethod export_method_39[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;Landroid/view/KeyEvent;LI/ᅟ︋︊;)V", (void *)Java_I__0115f_0fe0c_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2Landroid_view_KeyEvent_2LI__0115f_0fe0b_0fe0a_2},
    };
    env->RegisterNatives(clazz, export_method_39, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︌︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︌︍";
    const JNINativeMethod export_method_40[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/io/File;Ljava/io/File;LI/ᅟ︂︄;LI/ᅟ︎︎;Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V", (void *)Java_I__0115f_0fe0c_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_io_File_2Ljava_io_File_2LI__0115f_0fe02_0fe04_2LI__0115f_0fe0e_0fe0e_2Landroid_content_Context_2Ljava_lang_String_2Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_40, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︍︁");
    if (clazz == NULL) return "Class not found: I/ᅟ︍︁";
    const JNINativeMethod export_method_41[] = {
        {"<init>", "(Landroidx/drawerlayout/widget/DrawerLayout;Landroid/widget/ImageView;Landroid/widget/LinearLayout;Lcom/google/android/material/bottomnavigation/BottomNavigationView;Landroid/widget/LinearLayout;Landroidx/drawerlayout/widget/DrawerLayout;Landroidx/recyclerview/widget/RecyclerView;Landroidx/appcompat/widget/Toolbar;Landroid/widget/FrameLayout;Landroidx/coordinatorlayout/widget/CoordinatorLayout;Landroid/widget/ImageView;Lbin/nt/ui/HackyViewPager;Landroid/view/View;Lcom/google/android/material/tabs/TabLayout;Landroid/widget/ImageView;Landroidx/appcompat/widget/Toolbar;)V", (void *)Java_I__0115f_0fe0d_0fe01__0003cinit_0003e__Landroidx_drawerlayout_widget_DrawerLayout_2Landroid_widget_ImageView_2Landroid_widget_LinearLayout_2Lcom_google_android_material_bottomnavigation_BottomNavigationView_2Landroid_widget_LinearLayout_2Landroidx_drawerlayout_widget_DrawerLayout_2Landroidx_recyclerview_widget_RecyclerView_2Landroidx_appcompat_widget_Toolbar_2Landroid_widget_FrameLayout_2Landroidx_coordinatorlayout_widget_CoordinatorLayout_2Landroid_widget_ImageView_2Lbin_nt_ui_HackyViewPager_2Landroid_view_View_2Lcom_google_android_material_tabs_TabLayout_2Landroid_widget_ImageView_2Landroidx_appcompat_widget_Toolbar_2},
    };
    env->RegisterNatives(clazz, export_method_41, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︍︌");
    if (clazz == NULL) return "Class not found: I/ᅟ︍︌";
    const JNINativeMethod export_method_42[] = {
        {"<init>", "(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V", (void *)Java_I__0115f_0fe0d_0fe0c__0003cinit_0003e__Lbin_nt_ui_fastscroll_FastScrollerRecyclerView_2},
    };
    env->RegisterNatives(clazz, export_method_42, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︎︀");
    if (clazz == NULL) return "Class not found: I/ᅟ︎︀";
    const JNINativeMethod export_method_43[] = {
        {"<init>", "(Lbin/nt/main/BaseActivity;Landroid/graphics/Bitmap;Landroid/graphics/Paint;[Landroid/graphics/Rect;[FLandroid/graphics/Paint;)V", (void *)Java_I__0115f_0fe0e_0fe00__0003cinit_0003e__Lbin_nt_main_BaseActivity_2Landroid_graphics_Bitmap_2Landroid_graphics_Paint_2_3Landroid_graphics_Rect_2_3FLandroid_graphics_Paint_2},
    };
    env->RegisterNatives(clazz, export_method_43, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︎︁");
    if (clazz == NULL) return "Class not found: I/ᅟ︎︁";
    const JNINativeMethod export_method_44[] = {
        {"<init>", "(Landroid/widget/FrameLayout;Landroid/widget/LinearLayout;Landroid/widget/FrameLayout;Landroid/widget/TextView;Lbin/nt/ui/HackyViewPager;Landroid/widget/CheckBox;Landroid/widget/ImageButton;Landroidx/appcompat/widget/Toolbar;Landroid/widget/FrameLayout;)V", (void *)Java_I__0115f_0fe0e_0fe01__0003cinit_0003e__Landroid_widget_FrameLayout_2Landroid_widget_LinearLayout_2Landroid_widget_FrameLayout_2Landroid_widget_TextView_2Lbin_nt_ui_HackyViewPager_2Landroid_widget_CheckBox_2Landroid_widget_ImageButton_2Landroidx_appcompat_widget_Toolbar_2Landroid_widget_FrameLayout_2},
    };
    env->RegisterNatives(clazz, export_method_44, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︎︊");
    if (clazz == NULL) return "Class not found: I/ᅟ︎︊";
    const JNINativeMethod export_method_45[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︂︅;Landroid/view/MotionEvent;)V", (void *)Java_I__0115f_0fe0e_0fe0a__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe02_0fe05_2Landroid_view_MotionEvent_2},
    };
    env->RegisterNatives(clazz, export_method_45, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︎︌");
    if (clazz == NULL) return "Class not found: I/ᅟ︎︌";
    const JNINativeMethod export_method_46[] = {
        {"<init>", "(Lbin/nt/ui/fastscroll/FastScrollerRecyclerView;)V", (void *)Java_I__0115f_0fe0e_0fe0c__0003cinit_0003e__Lbin_nt_ui_fastscroll_FastScrollerRecyclerView_2},
    };
    env->RegisterNatives(clazz, export_method_46, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ︎︍");
    if (clazz == NULL) return "Class not found: I/ᅟ︎︍";
    const JNINativeMethod export_method_47[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;[Z[Ljava/lang/String;Ljava/lang/String;)V", (void *)Java_I__0115f_0fe0e_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2_3Z_3Ljava_lang_String_2Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_47, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ️︁");
    if (clazz == NULL) return "Class not found: I/ᅟ️︁";
    const JNINativeMethod export_method_48[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;LI/ᅠ︉︌;)V", (void *)Java_I__0115f_0fe0f_0fe01__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2LI__01160_0fe09_0fe0c_2},
        {"ᅟ︂︀", "(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︅︇;LI/ᅟ︍︆;LI/ᅟ︌︊;LI/ᅠ︋︀;)Z", (void *)Java_I__0115f_0fe0f_0fe01__0115f_0fe02_0fe00__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe05_0fe07_2LI__0115f_0fe0d_0fe06_2LI__0115f_0fe0c_0fe0a_2LI__01160_0fe0b_0fe00_2},
    };
    env->RegisterNatives(clazz, export_method_48, 2);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅟ️︍");
    if (clazz == NULL) return "Class not found: I/ᅟ️︍";
    const JNINativeMethod export_method_49[] = {
        {"<init>", "(Lbin/nt/fragments/FileBrowserFragment;Ljava/lang/String;LI/ᅟ︎︎;I)V", (void *)Java_I__0115f_0fe0f_0fe0d__0003cinit_0003e__Lbin_nt_fragments_FileBrowserFragment_2Ljava_lang_String_2LI__0115f_0fe0e_0fe0e_2I},
    };
    env->RegisterNatives(clazz, export_method_49, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︀︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︀︂";
    const JNINativeMethod export_method_50[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;I)V", (void *)Java_I__01160_0fe00_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_50, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︀︄");
    if (clazz == NULL) return "Class not found: I/ᅠ︀︄";
    const JNINativeMethod export_method_51[] = {
        {"<init>", "(Lbin/nt/main/PhotoViewerActivity;)V", (void *)Java_I__01160_0fe00_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2},
    };
    env->RegisterNatives(clazz, export_method_51, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︁︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︁︂";
    const JNINativeMethod export_method_52[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;I)V", (void *)Java_I__01160_0fe01_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_52, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︁︄");
    if (clazz == NULL) return "Class not found: I/ᅠ︁︄";
    const JNINativeMethod export_method_53[] = {
        {"<init>", "(Lbin/nt/main/PhotoViewerActivity;I)V", (void *)Java_I__01160_0fe01_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_53, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︂︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︂︂";
    const JNINativeMethod export_method_54[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;I)V", (void *)Java_I__01160_0fe02_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_54, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︂︃");
    if (clazz == NULL) return "Class not found: I/ᅠ︂︃";
    const JNINativeMethod export_method_55[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__01160_0fe02_0fe03__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_55, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︂︄");
    if (clazz == NULL) return "Class not found: I/ᅠ︂︄";
    const JNINativeMethod export_method_56[] = {
        {"<init>", "(Lbin/nt/main/PhotoViewerActivity;)V", (void *)Java_I__01160_0fe02_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2},
    };
    env->RegisterNatives(clazz, export_method_56, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︃︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︃︂";
    const JNINativeMethod export_method_57[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;Ljava/io/File;Ljava/util/ArrayList;I)V", (void *)Java_I__01160_0fe03_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Ljava_io_File_2Ljava_util_ArrayList_2I},
    };
    env->RegisterNatives(clazz, export_method_57, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︄︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︄︂";
    const JNINativeMethod export_method_58[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;ILjava/lang/String;ILjava/lang/String;)V", (void *)Java_I__01160_0fe04_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2ILjava_lang_String_2ILjava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_58, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︄︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︄︉";
    const JNINativeMethod export_method_59[] = {
        {"ᅟ︋︂", "(Lbin/nt/main/BaseActivity;II[Landroid/graphics/Rect;LI/ᅟ︈︈;)V", (void *)Java_I__01160_0fe04_0fe09__0115f_0fe0b_0fe02__Lbin_nt_main_BaseActivity_2II_3Landroid_graphics_Rect_2LI__0115f_0fe08_0fe08_2},
    };
    env->RegisterNatives(clazz, export_method_59, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︅︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︅︂";
    const JNINativeMethod export_method_60[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;Landroid/view/MenuItem;Landroid/view/View;I)V", (void *)Java_I__01160_0fe05_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Landroid_view_MenuItem_2Landroid_view_View_2I},
    };
    env->RegisterNatives(clazz, export_method_60, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︆︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︆︂";
    const JNINativeMethod export_method_61[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;)V", (void *)Java_I__01160_0fe06_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2},
    };
    env->RegisterNatives(clazz, export_method_61, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︆︈");
    if (clazz == NULL) return "Class not found: I/ᅠ︆︈";
    const JNINativeMethod export_method_62[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__01160_0fe06_0fe08__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_62, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︆︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︆︉";
    const JNINativeMethod export_method_63[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;I)V", (void *)Java_I__01160_0fe06_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_63, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︇︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︇︂";
    const JNINativeMethod export_method_64[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;)V", (void *)Java_I__01160_0fe07_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2},
    };
    env->RegisterNatives(clazz, export_method_64, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︇︈");
    if (clazz == NULL) return "Class not found: I/ᅠ︇︈";
    const JNINativeMethod export_method_65[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;)V", (void *)Java_I__01160_0fe07_0fe08__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2},
    };
    env->RegisterNatives(clazz, export_method_65, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︇︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︇︉";
    const JNINativeMethod export_method_66[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;I)V", (void *)Java_I__01160_0fe07_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_66, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︈︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︈︂";
    const JNINativeMethod export_method_67[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;)V", (void *)Java_I__01160_0fe08_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2},
    };
    env->RegisterNatives(clazz, export_method_67, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︈︄");
    if (clazz == NULL) return "Class not found: I/ᅠ︈︄";
    const JNINativeMethod export_method_68[] = {
        {"<init>", "(Lbin/nt/main/PhotoViewerActivity;)V", (void *)Java_I__01160_0fe08_0fe04__0003cinit_0003e__Lbin_nt_main_PhotoViewerActivity_2},
    };
    env->RegisterNatives(clazz, export_method_68, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︈︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︈︉";
    const JNINativeMethod export_method_69[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;II)V", (void *)Java_I__01160_0fe08_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2II},
    };
    env->RegisterNatives(clazz, export_method_69, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︉︂");
    if (clazz == NULL) return "Class not found: I/ᅠ︉︂";
    const JNINativeMethod export_method_70[] = {
        {"<init>", "(Lbin/nt/main/MainActivity;Landroid/widget/FrameLayout;Landroid/widget/FrameLayout;)V", (void *)Java_I__01160_0fe09_0fe02__0003cinit_0003e__Lbin_nt_main_MainActivity_2Landroid_widget_FrameLayout_2Landroid_widget_FrameLayout_2},
    };
    env->RegisterNatives(clazz, export_method_70, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︉︆");
    if (clazz == NULL) return "Class not found: I/ᅠ︉︆";
    const JNINativeMethod export_method_71[] = {
        {"<init>", "(Lbin/nt/editor/widget/CodeEditor;IIIII)V", (void *)Java_I__01160_0fe09_0fe06__0003cinit_0003e__Lbin_nt_editor_widget_CodeEditor_2IIIII},
    };
    env->RegisterNatives(clazz, export_method_71, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︉︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︉︉";
    const JNINativeMethod export_method_72[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;I)V", (void *)Java_I__01160_0fe09_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_72, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︊︄");
    if (clazz == NULL) return "Class not found: I/ᅠ︊︄";
    const JNINativeMethod export_method_73[] = {
        {"<init>", "(Lbin/nt/fragments/PreferenceFragment;)V", (void *)Java_I__01160_0fe0a_0fe04__0003cinit_0003e__Lbin_nt_fragments_PreferenceFragment_2},
    };
    env->RegisterNatives(clazz, export_method_73, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︊︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︊︉";
    const JNINativeMethod export_method_74[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;I)V", (void *)Java_I__01160_0fe0a_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2I},
    };
    env->RegisterNatives(clazz, export_method_74, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︋︄");
    if (clazz == NULL) return "Class not found: I/ᅠ︋︄";
    const JNINativeMethod export_method_75[] = {
        {"<init>", "(Lbin/nt/fragments/PreferenceFragment;Landroidx/preference/Preference;I)V", (void *)Java_I__01160_0fe0b_0fe04__0003cinit_0003e__Lbin_nt_fragments_PreferenceFragment_2Landroidx_preference_Preference_2I},
    };
    env->RegisterNatives(clazz, export_method_75, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︋︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︋︉";
    const JNINativeMethod export_method_76[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;)V", (void *)Java_I__01160_0fe0b_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2},
    };
    env->RegisterNatives(clazz, export_method_76, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︌︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︌︉";
    const JNINativeMethod export_method_77[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;Landroid/widget/ProgressBar;I)V", (void *)Java_I__01160_0fe0c_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2Landroid_widget_ProgressBar_2I},
    };
    env->RegisterNatives(clazz, export_method_77, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︍︈");
    if (clazz == NULL) return "Class not found: I/ᅠ︍︈";
    const JNINativeMethod export_method_78[] = {
        {"ᅟ︂︀", "(Lbin/nt/main/TextEditorActivity;)Ljava/lang/Object;", (void *)Java_I__01160_0fe0d_0fe08__0115f_0fe02_0fe00__Lbin_nt_main_TextEditorActivity_2},
    };
    env->RegisterNatives(clazz, export_method_78, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︍︉");
    if (clazz == NULL) return "Class not found: I/ᅠ︍︉";
    const JNINativeMethod export_method_79[] = {
        {"<init>", "(Lbin/nt/main/TextEditorActivity;)V", (void *)Java_I__01160_0fe0d_0fe09__0003cinit_0003e__Lbin_nt_main_TextEditorActivity_2},
    };
    env->RegisterNatives(clazz, export_method_79, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︍︊");
    if (clazz == NULL) return "Class not found: I/ᅠ︍︊";
    const JNINativeMethod export_method_80[] = {
        {"<init>", "(ILandroid/graphics/Paint$FontMetricsInt;IIIIIIFLbin/nt/editor/widget/CodeEditor;LI/ᅟ︌︉;LI/ᅠ︎︃;LI/ᅠ︎︃;Landroid/graphics/Paint$FontMetricsInt;)V", (void *)Java_I__01160_0fe0d_0fe0a__0003cinit_0003e__ILandroid_graphics_Paint_00024FontMetricsInt_2IIIIIIFLbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe0c_0fe09_2LI__01160_0fe0e_0fe03_2LI__01160_0fe0e_0fe03_2Landroid_graphics_Paint_00024FontMetricsInt_2},
    };
    env->RegisterNatives(clazz, export_method_80, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("I/ᅠ︎︆");
    if (clazz == NULL) return "Class not found: I/ᅠ︎︆";
    const JNINativeMethod export_method_81[] = {
        {"ᅟ︁︀", "(Lbin/nt/editor/widget/CodeEditor;LI/ᅟ︂︅;)LI/ᅟ︂︅;", (void *)Java_I__01160_0fe0e_0fe06__0115f_0fe01_0fe00__Lbin_nt_editor_widget_CodeEditor_2LI__0115f_0fe02_0fe05_2},
    };
    env->RegisterNatives(clazz, export_method_81, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("androidx/core/content/ContextCompat");
    if (clazz == NULL) return "Class not found: androidx/core/content/ContextCompat";
    const JNINativeMethod export_method_82[] = {
        {"ᅟ︇︀", "(Landroid/content/Context;Lbin/nt/xapk/ApkInstallReceiver;Landroid/content/IntentFilter;)V", (void *)Java_androidx_core_content_ContextCompat__0115f_0fe07_0fe00__Landroid_content_Context_2Lbin_nt_xapk_ApkInstallReceiver_2Landroid_content_IntentFilter_2},
    };
    env->RegisterNatives(clazz, export_method_82, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/editor/widget/CodeEditor");
    if (clazz == NULL) return "Class not found: bin/nt/editor/widget/CodeEditor";
    const JNINativeMethod export_method_83[] = {
        {"<clinit>", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0003cclinit_0003e__},
        {"computeHorizontalScrollExtent", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_computeHorizontalScrollExtent__},
        {"computeVerticalScrollExtent", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_computeVerticalScrollExtent__},
        {"getAccessibilityClassName", "()Ljava/lang/CharSequence;", (void *)Java_bin_nt_editor_widget_CodeEditor_getAccessibilityClassName__},
        {"getBlockIndex", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getBlockIndex__},
        {"getBlockLineWidth", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getBlockLineWidth__},
        {"getClipboardManager", "()Landroid/content/ClipboardManager;", (void *)Java_bin_nt_editor_widget_CodeEditor_getClipboardManager__},
        {"getColorScheme", "()LI/ᅟ︌︉;", (void *)Java_bin_nt_editor_widget_CodeEditor_getColorScheme__},
        {"getCurrentCursorBlock", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getCurrentCursorBlock__},
        {"getCursor", "()LI/ᅟ︅︇;", (void *)Java_bin_nt_editor_widget_CodeEditor_getCursor__},
        {"getCursorAnimator", "()LI/ᅟ︆︇;", (void *)Java_bin_nt_editor_widget_CodeEditor_getCursorAnimator__},
        {"getCursorBlink", "()LI/ᅟ︇︇;", (void *)Java_bin_nt_editor_widget_CodeEditor_getCursorBlink__},
        {"getCursorRange", "()LI/ᅠ️︉;", (void *)Java_bin_nt_editor_widget_CodeEditor_getCursorRange__},
        {"getDiagnosticIndicatorStyle", "()LI/ᅟ︄︈;", (void *)Java_bin_nt_editor_widget_CodeEditor_getDiagnosticIndicatorStyle__},
        {"getDiagnostics", "()LI/ᅟ︅︈;", (void *)Java_bin_nt_editor_widget_CodeEditor_getDiagnostics__},
        {"getDividerMarginLeft", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getDividerMarginLeft__},
        {"getDividerMarginRight", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getDividerMarginRight__},
        {"getDividerWidth", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getDividerWidth__},
        {"getDpUnit", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getDpUnit__},
        {"getEdgeEffectColor", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getEdgeEffectColor__},
        {"getEditable", "()Z", (void *)Java_bin_nt_editor_widget_CodeEditor_getEditable__},
        {"getEditorLanguage", "()LI/ᅠ︍︀;", (void *)Java_bin_nt_editor_widget_CodeEditor_getEditorLanguage__},
        {"getEventHandler", "()LI/ᅟ︄︌;", (void *)Java_bin_nt_editor_widget_CodeEditor_getEventHandler__},
        {"getExtraArguments", "()Landroid/os/Bundle;", (void *)Java_bin_nt_editor_widget_CodeEditor_getExtraArguments__},
        {"getFirstVisibleLine", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getFirstVisibleLine__},
        {"getFormatTip", "()Ljava/lang/String;", (void *)Java_bin_nt_editor_widget_CodeEditor_getFormatTip__},
        {"getGraphPaint", "()LI/ᅠ︎︃;", (void *)Java_bin_nt_editor_widget_CodeEditor_getGraphPaint__},
        {"getHandleStyle", "()LI/ᅠ︌︆;", (void *)Java_bin_nt_editor_widget_CodeEditor_getHandleStyle__},
        {"getHighlightTexts", "()LI/ᅟ︉️;", (void *)Java_bin_nt_editor_widget_CodeEditor_getHighlightTexts__},
        {"getHorizontalEdgeEffect", "()Landroid/widget/EdgeEffect;", (void *)Java_bin_nt_editor_widget_CodeEditor_getHorizontalEdgeEffect__},
        {"getHorizontalScrollbarThumbDrawable", "()Landroid/graphics/drawable/Drawable;", (void *)Java_bin_nt_editor_widget_CodeEditor_getHorizontalScrollbarThumbDrawable__},
        {"getHorizontalScrollbarTrackDrawable", "()Landroid/graphics/drawable/Drawable;", (void *)Java_bin_nt_editor_widget_CodeEditor_getHorizontalScrollbarTrackDrawable__},
        {"getInlayHintRenderers", "()Ljava/util/List;", (void *)Java_bin_nt_editor_widget_CodeEditor_getInlayHintRenderers__},
        {"getInlayHints", "()LI/ᅟ️️;", (void *)Java_bin_nt_editor_widget_CodeEditor_getInlayHints__},
        {"getInputMethodManager", "()Landroid/view/inputmethod/InputMethodManager;", (void *)Java_bin_nt_editor_widget_CodeEditor_getInputMethodManager__},
        {"getInputType", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getInputType__},
        {"getInsertHandleDescriptor", "()LI/ᅠ︋︆;", (void *)Java_bin_nt_editor_widget_CodeEditor_getInsertHandleDescriptor__},
        {"getInsertSelectionWidth", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getInsertSelectionWidth__},
        {"getKeyMetaStates", "()LI/ᅠ︌︀;", (void *)Java_bin_nt_editor_widget_CodeEditor_getKeyMetaStates__},
        {"getLastVisibleLine", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getLastVisibleLine__},
        {"getLastVisibleRow", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getLastVisibleRow__},
        {"getLayout", "()LI/ᅠ︁︁;", (void *)Java_bin_nt_editor_widget_CodeEditor_getLayout__},
        {"getLeftHandleDescriptor", "()LI/ᅠ︋︆;", (void *)Java_bin_nt_editor_widget_CodeEditor_getLeftHandleDescriptor__},
        {"getLineCount", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineCount__},
        {"getLineInfoTextSize", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineInfoTextSize__},
        {"getLineNumberAlign", "()Landroid/graphics/Paint$Align;", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineNumberAlign__},
        {"getLineNumberMarginLeft", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineNumberMarginLeft__},
        {"getLineNumberMetrics", "()Landroid/graphics/Paint$FontMetricsInt;", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineNumberMetrics__},
        {"getLineNumberTipTextProvider", "()LI/ᅠ︈︁;", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineNumberTipTextProvider__},
        {"getLineSeparator", "()LI/ᅠ︉︁;", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineSeparator__},
        {"getLineSpacingExtra", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineSpacingExtra__},
        {"getLineSpacingMultiplier", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineSpacingMultiplier__},
        {"getLineSpacingPixels", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getLineSpacingPixels__},
        {"getLnPanelPosition", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getLnPanelPosition__},
        {"getLnPanelPositionMode", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getLnPanelPositionMode__},
        {"getNonPrintablePaintingFlags", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getNonPrintablePaintingFlags__},
        {"getOffsetX", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getOffsetX__},
        {"getOffsetY", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getOffsetY__},
        {"getOtherPaint", "()LI/ᅠ︎︃;", (void *)Java_bin_nt_editor_widget_CodeEditor_getOtherPaint__},
        {"getProps", "()LI/ᅟ︆︈;", (void *)Java_bin_nt_editor_widget_CodeEditor_getProps__},
        {"getRenderContext", "()LI/ᅠ︆︅;", (void *)Java_bin_nt_editor_widget_CodeEditor_getRenderContext__},
        {"getRenderer", "()LI/ᅟ︇︋;", (void *)Java_bin_nt_editor_widget_CodeEditor_getRenderer__},
        {"getRightHandleDescriptor", "()LI/ᅠ︋︆;", (void *)Java_bin_nt_editor_widget_CodeEditor_getRightHandleDescriptor__},
        {"getRowHeight", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getRowHeight__},
        {"getRowHeightOfText", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getRowHeightOfText__},
        {"getScrollMaxX", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getScrollMaxX__},
        {"getScroller", "()LI/ᅟ︈︋;", (void *)Java_bin_nt_editor_widget_CodeEditor_getScroller__},
        {"getSearcher", "()LI/ᅟ︍︋;", (void *)Java_bin_nt_editor_widget_CodeEditor_getSearcher__},
        {"getSelectingTarget", "()LI/ᅟ︂︅;", (void *)Java_bin_nt_editor_widget_CodeEditor_getSelectingTarget__},
        {"getSnippetController", "()LI/ᅠ︆︈;", (void *)Java_bin_nt_editor_widget_CodeEditor_getSnippetController__},
        {"getStyles", "()LI/ᅠ︎︈;", (void *)Java_bin_nt_editor_widget_CodeEditor_getStyles__},
        {"getTabWidth", "()I", (void *)Java_bin_nt_editor_widget_CodeEditor_getTabWidth__},
        {"getText", "()LI/ᅟ︍︆;", (void *)Java_bin_nt_editor_widget_CodeEditor_getText__},
        {"getTextBorderWidth", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getTextBorderWidth__},
        {"getTextLetterSpacing", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getTextLetterSpacing__},
        {"getTextPaint", "()LI/ᅠ︎︃;", (void *)Java_bin_nt_editor_widget_CodeEditor_getTextPaint__},
        {"getTextScaleX", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getTextScaleX__},
        {"getTextSizePx", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getTextSizePx__},
        {"getTypefaceLineNumber", "()Landroid/graphics/Typeface;", (void *)Java_bin_nt_editor_widget_CodeEditor_getTypefaceLineNumber__},
        {"getTypefaceText", "()Landroid/graphics/Typeface;", (void *)Java_bin_nt_editor_widget_CodeEditor_getTypefaceText__},
        {"getVerticalEdgeEffect", "()Landroid/widget/EdgeEffect;", (void *)Java_bin_nt_editor_widget_CodeEditor_getVerticalEdgeEffect__},
        {"getVerticalExtraSpaceFactor", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor_getVerticalExtraSpaceFactor__},
        {"getVerticalScrollbarThumbDrawable", "()Landroid/graphics/drawable/Drawable;", (void *)Java_bin_nt_editor_widget_CodeEditor_getVerticalScrollbarThumbDrawable__},
        {"getVerticalScrollbarTrackDrawable", "()Landroid/graphics/drawable/Drawable;", (void *)Java_bin_nt_editor_widget_CodeEditor_getVerticalScrollbarTrackDrawable__},
        {"isHorizontalScrollBarEnabled", "()Z", (void *)Java_bin_nt_editor_widget_CodeEditor_isHorizontalScrollBarEnabled__},
        {"isVerticalScrollBarEnabled", "()Z", (void *)Java_bin_nt_editor_widget_CodeEditor_isVerticalScrollBarEnabled__},
        {"onConfigurationChanged", "(Landroid/content/res/Configuration;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_onConfigurationChanged__Landroid_content_res_Configuration_2},
        {"onKeyMultiple", "(IILandroid/view/KeyEvent;)Z", (void *)Java_bin_nt_editor_widget_CodeEditor_onKeyMultiple__IILandroid_view_KeyEvent_2},
        {"onKeyUp", "(ILandroid/view/KeyEvent;)Z", (void *)Java_bin_nt_editor_widget_CodeEditor_onKeyUp__ILandroid_view_KeyEvent_2},
        {"performAccessibilityAction", "(ILandroid/os/Bundle;)Z", (void *)Java_bin_nt_editor_widget_CodeEditor_performAccessibilityAction__ILandroid_os_Bundle_2},
        {"removeCallbacks", "(Ljava/lang/Runnable;)Z", (void *)Java_bin_nt_editor_widget_CodeEditor_removeCallbacks__Ljava_lang_Runnable_2},
        {"setBlockLineEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setBlockLineEnabled__Z},
        {"setBlockLineWidth", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setBlockLineWidth__F},
        {"setColorScheme", "(LI/ᅟ︌︉;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setColorScheme__LI__0115f_0fe0c_0fe09_2},
        {"setCursorAnimationEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setCursorAnimationEnabled__Z},
        {"setCursorAnimator", "(LI/ᅟ︆︇;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setCursorAnimator__LI__0115f_0fe06_0fe07_2},
        {"setCursorBlinkPeriod", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setCursorBlinkPeriod__I},
        {"setCursorWidth", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setCursorWidth__F},
        {"setDiagnosticIndicatorStyle", "(LI/ᅟ︄︈;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setDiagnosticIndicatorStyle__LI__0115f_0fe04_0fe08_2},
        {"setDiagnostics", "(LI/ᅟ︅︈;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setDiagnostics__LI__0115f_0fe05_0fe08_2},
        {"setDisableSoftKbdIfHardKbdAvailable", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setDisableSoftKbdIfHardKbdAvailable__Z},
        {"setDisplayLnPanel", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setDisplayLnPanel__Z},
        {"setDividerMargin", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setDividerMargin__F},
        {"setDividerWidth", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setDividerWidth__F},
        {"setEdgeEffectColor", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setEdgeEffectColor__I},
        {"setFirstLineNumberAlwaysVisible", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setFirstLineNumberAlwaysVisible__Z},
        {"setFontFeatureSettings", "(Ljava/lang/String;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setFontFeatureSettings__Ljava_lang_String_2},
        {"setFormatTip", "(Ljava/lang/String;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setFormatTip__Ljava_lang_String_2},
        {"setHardwareAcceleratedDrawAllowed", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHardwareAcceleratedDrawAllowed__Z},
        {"setHighlightBracketPair", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHighlightBracketPair__Z},
        {"setHighlightCurrentBlock", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHighlightCurrentBlock__Z},
        {"setHighlightCurrentLine", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHighlightCurrentLine__Z},
        {"setHighlightTexts", "(LI/ᅟ︉️;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHighlightTexts__LI__0115f_0fe09_0fe0f_2},
        {"setHorizontalScrollBarEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollBarEnabled__Z},
        {"setHorizontalScrollbarThumbDrawable", "(Landroid/graphics/drawable/Drawable;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollbarThumbDrawable__Landroid_graphics_drawable_Drawable_2},
        {"setHorizontalScrollbarTrackDrawable", "(Landroid/graphics/drawable/Drawable;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setHorizontalScrollbarTrackDrawable__Landroid_graphics_drawable_Drawable_2},
        {"setInputType", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setInputType__I},
        {"setLayoutBusy", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLayoutBusy__Z},
        {"setLineInfoTextSize", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineInfoTextSize__F},
        {"setLineNumberAlign", "(Landroid/graphics/Paint$Align;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineNumberAlign__Landroid_graphics_Paint_00024Align_2},
        {"setLineNumberEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineNumberEnabled__Z},
        {"setLineNumberMarginLeft", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineNumberMarginLeft__F},
        {"setLineNumberTipTextProvider", "(LI/ᅠ︈︁;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineNumberTipTextProvider__LI__01160_0fe08_0fe01_2},
        {"setLineSpacingExtra", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineSpacingExtra__F},
        {"setLineSpacingMultiplier", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLineSpacingMultiplier__F},
        {"setLnPanelPosition", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLnPanelPosition__I},
        {"setLnPanelPositionMode", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setLnPanelPositionMode__I},
        {"setNonPrintablePaintingFlags", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setNonPrintablePaintingFlags__I},
        {"setPinLineNumber", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setPinLineNumber__Z},
        {"setRenderFunctionCharacters", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setRenderFunctionCharacters__Z},
        {"setScalable", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setScalable__Z},
        {"setScrollBarEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setScrollBarEnabled__Z},
        {"setSelectionHandleStyle", "(LI/ᅠ︌︆;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setSelectionHandleStyle__LI__01160_0fe0c_0fe06_2},
        {"setSoftKeyboardEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setSoftKeyboardEnabled__Z},
        {"setStickyTextSelection", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setStickyTextSelection__Z},
        {"setStyles", "(LI/ᅠ︎︈;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setStyles__LI__01160_0fe0e_0fe08_2},
        {"setTabWidth", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTabWidth__I},
        {"setTextBorderWidth", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTextBorderWidth__F},
        {"setTextLetterSpacing", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTextLetterSpacing__F},
        {"setTextScaleX", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTextScaleX__F},
        {"setTextSizePx", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTextSizePx__F},
        {"setTypefaceLineNumber", "(Landroid/graphics/Typeface;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTypefaceLineNumber__Landroid_graphics_Typeface_2},
        {"setTypefaceText", "(Landroid/graphics/Typeface;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setTypefaceText__Landroid_graphics_Typeface_2},
        {"setUndoEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setUndoEnabled__Z},
        {"setVerticalExtraSpaceFactor", "(F)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setVerticalExtraSpaceFactor__F},
        {"setVerticalScrollBarEnabled", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollBarEnabled__Z},
        {"setVerticalScrollbarThumbDrawable", "(Landroid/graphics/drawable/Drawable;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollbarThumbDrawable__Landroid_graphics_drawable_Drawable_2},
        {"setVerticalScrollbarTrackDrawable", "(Landroid/graphics/drawable/Drawable;)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setVerticalScrollbarTrackDrawable__Landroid_graphics_drawable_Drawable_2},
        {"setWordwrap", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor_setWordwrap__Z},
        {"ᅟ︁︀", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe00__},
        {"ᅟ︁︃", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe03__},
        {"ᅟ︁︄", "(IIII)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe01_0fe04__IIII},
        {"ᅟ︂︁", "(LI/ᅟ︍︆;)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe02_0fe01__LI__0115f_0fe0d_0fe06_2},
        {"ᅟ︂︃", "(I)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe02_0fe03__I},
        {"ᅟ︃︀", "()Z", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe00__},
        {"ᅟ︃︂", "(FF)J", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe02__FF},
        {"ᅟ︃︃", "(IILandroid/view/KeyEvent;)Z", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe03__IILandroid_view_KeyEvent_2},
        {"ᅟ︃︄", "(ZZ)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe03_0fe04__ZZ},
        {"ᅟ︄︂", "(FF)J", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe02__FF},
        {"ᅟ︄︃", "(ILandroid/view/KeyEvent;)Z", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe03__ILandroid_view_KeyEvent_2},
        {"ᅟ︄︄", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe04_0fe04__},
        {"ᅟ︅︃", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe05_0fe03__},
        {"ᅟ︆︀", "(Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe00__Z},
        {"ᅟ︆︃", "(Ljava/lang/String;)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe03__Ljava_lang_String_2},
        {"ᅟ︆︄", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe06_0fe04__},
        {"ᅟ︈︀", "(IILjava/lang/CharSequence;)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe08_0fe00__IILjava_lang_CharSequence_2},
        {"ᅟ︈︃", "(Ljava/lang/Runnable;)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe08_0fe03__Ljava_lang_Runnable_2},
        {"ᅟ︉︁", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe01__},
        {"ᅟ︉︂", "()Z", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe02__},
        {"ᅟ︉︃", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe09_0fe03__},
        {"ᅟ︊︂", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0a_0fe02__},
        {"ᅟ︊︃", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0a_0fe03__},
        {"ᅟ︋︂", "()Z", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0b_0fe02__},
        {"ᅟ︋︃", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0b_0fe03__},
        {"ᅟ︍︃", "(II)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0d_0fe03__II},
        {"ᅟ︎︂", "()F", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0e_0fe02__},
        {"ᅟ︎︃", "(FF)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0e_0fe03__FF},
        {"ᅟ️︁", "()V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe01__},
        {"ᅟ️︂", "(LI/ᅠ︎︆;Z)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe02__LI__01160_0fe0e_0fe06_2Z},
        {"ᅟ️︃", "(II)V", (void *)Java_bin_nt_editor_widget_CodeEditor__0115f_0fe0f_0fe03__II},
    };
    env->RegisterNatives(clazz, export_method_83, 180);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/fragments/FileBrowserFragment");
    if (clazz == NULL) return "Class not found: bin/nt/fragments/FileBrowserFragment";
    const JNINativeMethod export_method_84[] = {
        {"ᅟ︇︅", "(Ljava/lang/String;)Ljava/io/File;", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe07_0fe05__Ljava_lang_String_2},
        {"ᅟ︉︄", "(LI/ᅟ︎︎;)Ljava/io/InputStream;", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe09_0fe04__LI__0115f_0fe0e_0fe0e_2},
        {"ᅟ️︄", "(Landroid/content/SharedPreferences;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0f_0fe04__Landroid_content_SharedPreferences_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2},
        {"ᅟ︀︂", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe00_0fe02__},
        {"ᅟ︀︅", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe00_0fe05__},
        {"ᅟ︁︄", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe01_0fe04__},
        {"ᅟ︁︅", "(LI/ᅟ︎︎;Ljava/lang/String;Landroid/content/Context;Ljava/lang/String;)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe01_0fe05__LI__0115f_0fe0e_0fe0e_2Ljava_lang_String_2Landroid_content_Context_2Ljava_lang_String_2},
        {"ᅟ︂︄", "()Z", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe02_0fe04__},
        {"ᅟ︃︄", "(ZZ)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe03_0fe04__ZZ},
        {"ᅟ︃︅", "(I)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe03_0fe05__I},
        {"ᅟ︄︂", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe04_0fe02__},
        {"ᅟ︄︄", "(Ljava/lang/String;)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe04_0fe04__Ljava_lang_String_2},
        {"ᅟ︅︄", "(LI/ᅟ︎︎;Z)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe05_0fe04__LI__0115f_0fe0e_0fe0e_2Z},
        {"ᅟ︅︅", "(Ljava/lang/String;Z)Landroid/widget/EditText;", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe05_0fe05__Ljava_lang_String_2Z},
        {"ᅟ︆︂", "(Landroid/os/Bundle;)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe06_0fe02__Landroid_os_Bundle_2},
        {"ᅟ︇︂", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe07_0fe02__},
        {"ᅟ︈︂", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe08_0fe02__},
        {"ᅟ︈︄", "(LI/ᅟ︎︎;)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe08_0fe04__LI__0115f_0fe0e_0fe0e_2},
        {"ᅟ︋︃", "()Z", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0b_0fe03__},
        {"ᅟ︌︃", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0c_0fe03__},
        {"ᅟ︌︄", "(ILjava/lang/String;)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0c_0fe04__ILjava_lang_String_2},
        {"ᅟ︍︃", "(ILjava/util/List;)V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0d_0fe03__ILjava_util_List_2},
        {"ᅟ︍︄", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0d_0fe04__},
        {"ᅟ️︃", "()V", (void *)Java_bin_nt_fragments_FileBrowserFragment__0115f_0fe0f_0fe03__},
    };
    env->RegisterNatives(clazz, export_method_84, 24);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/fragments/PreferenceFragment");
    if (clazz == NULL) return "Class not found: bin/nt/fragments/PreferenceFragment";
    const JNINativeMethod export_method_85[] = {
        {"ᅟ︀︂", "()V", (void *)Java_bin_nt_fragments_PreferenceFragment__0115f_0fe00_0fe02__},
        {"ᅟ︌︃", "(Landroidx/preference/Preference;)V", (void *)Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0c_0fe03__Landroidx_preference_Preference_2},
        {"ᅟ︎︁", "(Landroid/os/Bundle;)V", (void *)Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0e_0fe01__Landroid_os_Bundle_2},
        {"ᅟ️︁", "(Landroid/view/LayoutInflater;Landroid/view/ViewGroup;Landroid/os/Bundle;)Landroid/view/View;", (void *)Java_bin_nt_fragments_PreferenceFragment__0115f_0fe0f_0fe01__Landroid_view_LayoutInflater_2Landroid_view_ViewGroup_2Landroid_os_Bundle_2},
    };
    env->RegisterNatives(clazz, export_method_85, 4);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/App");
    if (clazz == NULL) return "Class not found: bin/nt/main/App";
    const JNINativeMethod export_method_86[] = {
        {"<init>", "()V", (void *)Java_bin_nt_main_App__0003cinit_0003e__},
        {"ᅟ︀︀", "(Ljava/lang/String;)V", (void *)Java_bin_nt_main_App__0115f_0fe00_0fe00__Ljava_lang_String_2},
        {"ᅟ︃︀", "()Ljava/io/File;", (void *)Java_bin_nt_main_App__0115f_0fe03_0fe00__},
        {"ᅟ︄︀", "(Ljava/lang/String;)Ljava/io/File;", (void *)Java_bin_nt_main_App__0115f_0fe04_0fe00__Ljava_lang_String_2},
        {"ᅟ︇︀", "(Ljava/lang/String;)V", (void *)Java_bin_nt_main_App__0115f_0fe07_0fe00__Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_86, 5);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/BaseActivity");
    if (clazz == NULL) return "Class not found: bin/nt/main/BaseActivity";
    const JNINativeMethod export_method_87[] = {
        {"ᅟ︅︁", "()V", (void *)Java_bin_nt_main_BaseActivity__0115f_0fe05_0fe01__},
    };
    env->RegisterNatives(clazz, export_method_87, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/CrashActivity");
    if (clazz == NULL) return "Class not found: bin/nt/main/CrashActivity";
    const JNINativeMethod export_method_88[] = {
        {"<clinit>", "()V", (void *)Java_bin_nt_main_CrashActivity__0003cclinit_0003e__},
        {"<init>", "()V", (void *)Java_bin_nt_main_CrashActivity__0003cinit_0003e__},
        {"ᅟ︅︁", "()V", (void *)Java_bin_nt_main_CrashActivity__0115f_0fe05_0fe01__},
        {"ᅟ︍︁", "()V", (void *)Java_bin_nt_main_CrashActivity__0115f_0fe0d_0fe01__},
    };
    env->RegisterNatives(clazz, export_method_88, 4);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/EditorPreferencesActivity");
    if (clazz == NULL) return "Class not found: bin/nt/main/EditorPreferencesActivity";
    const JNINativeMethod export_method_89[] = {
        {"<init>", "()V", (void *)Java_bin_nt_main_EditorPreferencesActivity__0003cinit_0003e__},
    };
    env->RegisterNatives(clazz, export_method_89, 1);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/EditorPreferencesActivity$EditorPreferenceFragment");
    if (clazz == NULL) return "Class not found: bin/nt/main/EditorPreferencesActivity$EditorPreferenceFragment";
    const JNINativeMethod export_method_90[] = {
        {"<init>", "()V", (void *)Java_bin_nt_main_EditorPreferencesActivity_00024EditorPreferenceFragment__0003cinit_0003e__},
        {"ᅟ︊︃", "(Ljava/lang/String;)V", (void *)Java_bin_nt_main_EditorPreferencesActivity_00024EditorPreferenceFragment__0115f_0fe0a_0fe03__Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_90, 2);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/MainActivity");
    if (clazz == NULL) return "Class not found: bin/nt/main/MainActivity";
    const JNINativeMethod export_method_91[] = {
        {"ᅟ︁︂", "(Landroid/content/Intent;)Z", (void *)Java_bin_nt_main_MainActivity__0115f_0fe01_0fe02__Landroid_content_Intent_2},
        {"onBackPressed", "()V", (void *)Java_bin_nt_main_MainActivity_onBackPressed__},
        {"ᅟ︂︂", "()V", (void *)Java_bin_nt_main_MainActivity__0115f_0fe02_0fe02__},
        {"ᅟ︄︂", "()V", (void *)Java_bin_nt_main_MainActivity__0115f_0fe04_0fe02__},
        {"ᅟ︅︁", "()V", (void *)Java_bin_nt_main_MainActivity__0115f_0fe05_0fe01__},
        {"ᅟ︅︂", "()V", (void *)Java_bin_nt_main_MainActivity__0115f_0fe05_0fe02__},
        {"ᅟ︇︂", "(Z)V", (void *)Java_bin_nt_main_MainActivity__0115f_0fe07_0fe02__Z},
        {"ᅟ︎︁", "(I)Landroid/widget/TextView;", (void *)Java_bin_nt_main_MainActivity__0115f_0fe0e_0fe01__I},
    };
    env->RegisterNatives(clazz, export_method_91, 8);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/PhotoViewerActivity");
    if (clazz == NULL) return "Class not found: bin/nt/main/PhotoViewerActivity";
    const JNINativeMethod export_method_92[] = {
        {"onKeyDown", "(ILandroid/view/KeyEvent;)Z", (void *)Java_bin_nt_main_PhotoViewerActivity_onKeyDown__ILandroid_view_KeyEvent_2},
        {"onResume", "()V", (void *)Java_bin_nt_main_PhotoViewerActivity_onResume__},
        {"ᅟ︀︂", "()V", (void *)Java_bin_nt_main_PhotoViewerActivity__0115f_0fe00_0fe02__},
        {"ᅟ︁︂", "(F)V", (void *)Java_bin_nt_main_PhotoViewerActivity__0115f_0fe01_0fe02__F},
        {"ᅟ️︁", "()V", (void *)Java_bin_nt_main_PhotoViewerActivity__0115f_0fe0f_0fe01__},
    };
    env->RegisterNatives(clazz, export_method_92, 5);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/Preferences");
    if (clazz == NULL) return "Class not found: bin/nt/main/Preferences";
    const JNINativeMethod export_method_93[] = {
        {"<init>", "()V", (void *)Java_bin_nt_main_Preferences__0003cinit_0003e__},
        {"onOptionsItemSelected", "(Landroid/view/MenuItem;)Z", (void *)Java_bin_nt_main_Preferences_onOptionsItemSelected__Landroid_view_MenuItem_2},
        {"ᅟ︅︁", "()V", (void *)Java_bin_nt_main_Preferences__0115f_0fe05_0fe01__},
    };
    env->RegisterNatives(clazz, export_method_93, 3);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/main/TextEditorActivity");
    if (clazz == NULL) return "Class not found: bin/nt/main/TextEditorActivity";
    const JNINativeMethod export_method_94[] = {
        {"onBackPressed", "()V", (void *)Java_bin_nt_main_TextEditorActivity_onBackPressed__},
        {"onContentChanged", "()V", (void *)Java_bin_nt_main_TextEditorActivity_onContentChanged__},
        {"ᅟ︀︂", "(I)V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe00_0fe02__I},
        {"ᅟ︁︂", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe01_0fe02__},
        {"ᅟ︂︂", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe02_0fe02__},
        {"ᅟ︃︂", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe03_0fe02__},
        {"ᅟ︄︂", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe04_0fe02__},
        {"ᅟ︅︁", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe05_0fe01__},
        {"ᅟ︅︂", "(Z)V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe05_0fe02__Z},
        {"ᅟ︆︂", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe06_0fe02__},
        {"ᅟ︇︂", "()V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe07_0fe02__},
        {"ᅟ︍︁", "(Ljava/lang/String;)V", (void *)Java_bin_nt_main_TextEditorActivity__0115f_0fe0d_0fe01__Ljava_lang_String_2},
    };
    env->RegisterNatives(clazz, export_method_94, 12);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/ui/HackyViewPager");
    if (clazz == NULL) return "Class not found: bin/nt/ui/HackyViewPager";
    const JNINativeMethod export_method_95[] = {
        {"<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", (void *)Java_bin_nt_ui_HackyViewPager__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2},
        {"onInterceptTouchEvent", "(Landroid/view/MotionEvent;)Z", (void *)Java_bin_nt_ui_HackyViewPager_onInterceptTouchEvent__Landroid_view_MotionEvent_2},
    };
    env->RegisterNatives(clazz, export_method_95, 2);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/ui/PanelView");
    if (clazz == NULL) return "Class not found: bin/nt/ui/PanelView";
    const JNINativeMethod export_method_96[] = {
        {"getLinearLayoutManager", "()Landroidx/recyclerview/widget/LinearLayoutManager;", (void *)Java_bin_nt_ui_PanelView_getLinearLayoutManager__},
        {"getRecyclerView", "()Landroidx/recyclerview/widget/RecyclerView;", (void *)Java_bin_nt_ui_PanelView_getRecyclerView__},
        {"setJellyColor", "(I)V", (void *)Java_bin_nt_ui_PanelView_setJellyColor__I},
        {"setOnPanelTouchedListener", "(LI/ᅠ️︃;)V", (void *)Java_bin_nt_ui_PanelView_setOnPanelTouchedListener__LI__01160_0fe0f_0fe03_2},
        {"setPanelBackground", "(I)V", (void *)Java_bin_nt_ui_PanelView_setPanelBackground__I},
        {"setPullToRefreshListener", "(LI/ᅠ︁︅;)V", (void *)Java_bin_nt_ui_PanelView_setPullToRefreshListener__LI__01160_0fe01_0fe05_2},
        {"setRefreshing", "(Z)V", (void *)Java_bin_nt_ui_PanelView_setRefreshing__Z},
        {"ᅟ︁︀", "(LI/ᅟ︁︍;Z)V", (void *)Java_bin_nt_ui_PanelView__0115f_0fe01_0fe00__LI__0115f_0fe01_0fe0d_2Z},
    };
    env->RegisterNatives(clazz, export_method_96, 8);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/ui/animation/InnerShadow");
    if (clazz == NULL) return "Class not found: bin/nt/ui/animation/InnerShadow";
    const JNINativeMethod export_method_97[] = {
        {"<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", (void *)Java_bin_nt_ui_animation_InnerShadow__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2},
        {"onDraw", "(Landroid/graphics/Canvas;)V", (void *)Java_bin_nt_ui_animation_InnerShadow_onDraw__Landroid_graphics_Canvas_2},
    };
    env->RegisterNatives(clazz, export_method_97, 2);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/ui/fastscroll/FastScrollerRecyclerView");
    if (clazz == NULL) return "Class not found: bin/nt/ui/fastscroll/FastScrollerRecyclerView";
    const JNINativeMethod export_method_98[] = {
        {"<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", (void *)Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2},
        {"onInterceptTouchEvent", "(Landroid/view/MotionEvent;)Z", (void *)Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_onInterceptTouchEvent__Landroid_view_MotionEvent_2},
        {"setLayoutManager", "(Landroidx/recyclerview/widget/RecyclerView$LayoutManager;)V", (void *)Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_setLayoutManager__Landroidx_recyclerview_widget_RecyclerView_00024LayoutManager_2},
        {"setTrackVisible", "(Z)V", (void *)Java_bin_nt_ui_fastscroll_FastScrollerRecyclerView_setTrackVisible__Z},
    };
    env->RegisterNatives(clazz, export_method_98, 4);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/ui/jellyrefresh/JellyRefreshLayout");
    if (clazz == NULL) return "Class not found: bin/nt/ui/jellyrefresh/JellyRefreshLayout";
    const JNINativeMethod export_method_99[] = {
        {"<init>", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", (void *)Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0003cinit_0003e__Landroid_content_Context_2Landroid_util_AttributeSet_2},
        {"setJellyColor", "(I)V", (void *)Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setJellyColor__I},
        {"setLoadingView", "(Landroid/view/View;)V", (void *)Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setLoadingView__Landroid_view_View_2},
        {"setSweepDirection", "(Z)V", (void *)Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout_setSweepDirection__Z},
        {"ᅟ︃︀", "(LI/ᅠ︊︀;F)V", (void *)Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0115f_0fe03_0fe00__LI__01160_0fe0a_0fe00_2F},
        {"ᅟ︄︀", "(F)F", (void *)Java_bin_nt_ui_jellyrefresh_JellyRefreshLayout__0115f_0fe04_0fe00__F},
    };
    env->RegisterNatives(clazz, export_method_99, 6);
    env->DeleteLocalRef(clazz);

    clazz = env->FindClass("bin/nt/xapk/ApkInstallReceiver");
    if (clazz == NULL) return "Class not found: bin/nt/xapk/ApkInstallReceiver";
    const JNINativeMethod export_method_100[] = {
        {"<init>", "()V", (void *)Java_bin_nt_xapk_ApkInstallReceiver__0003cinit_0003e__},
    };
    env->RegisterNatives(clazz, export_method_100, 1);
    env->DeleteLocalRef(clazz);

    return NULL;
}
