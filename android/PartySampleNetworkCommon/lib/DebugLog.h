#pragma once

#if defined(__ANDROID__)
#include <android/log.h>
#define DbgLog(TAG, format, ...)  __android_log_print(ANDROID_LOG_INFO, TAG, format, ##__VA_ARGS__);
#define TAG "PartySample"
#define DEBUGLOG(format, ...) DbgLog(TAG, format, ##__VA_ARGS__)

#elif defined(__APPLE__)
#define DEBUGLOG printf

#elif defined(_WIN32)
void DebugLogWin(const char* format, ...);
#define DEBUGLOG DebugLogWin

#else
#error Platform needs definition for DEBUGLOG

#endif
