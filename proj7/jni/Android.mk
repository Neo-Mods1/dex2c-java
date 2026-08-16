LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := stub
LOCAL_CFLAGS    := -O2
LOCAL_CPPFLAGS  := -fno-exceptions -fno-rtti
LOCAL_LDLIBS    := -llog
LOCAL_SRC_FILES := $(call all-cpp-files-under, nc)
LOCAL_LDFLAGS   := -Wl,--version-script=$(LOCAL_PATH)/nc/export.map
include $(BUILD_SHARED_LIBRARY)
