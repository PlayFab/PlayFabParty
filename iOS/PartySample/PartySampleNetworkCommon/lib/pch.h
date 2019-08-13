//Include storage primitives
#include <string>
#include <queue>
#include <errno.h>

//Include the Party Libraries
#include "PartyPal.h"
#include "Party.h"

//Include the local headers
#include "Manager.h"
#include "NetworkMessages.h"
#include "NetworkManager.h"
//#include "Managers.h"
#include "PlayFabManager.h"
#include "INetworkStateChangeManager.h"


#if defined(__ANDROID__)
#include <android/log.h>
#define DbgLog(TAG, format, ...)  __android_log_print(ANDROID_LOG_INFO, TAG, format, ##__VA_ARGS__);
#define TAG "PartySample"
#define DEBUGLOG(format, ...) DbgLog(TAG, format, ##__VA_ARGS__)
#endif

#if defined(__APPLE__)
#define DEBUGLOG printf
#endif

// The following functionality is emulated for posix platforms.

#ifndef MultiByteToWideChar
#define MultiByteToWideChar(codePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar) \
    (static_cast<int>(std::mbstowcs((lpWideCharStr), (lpMultiByteStr), (static_cast<size_t>(cbMultiByte)))))
#endif

#define CopyMemory(dest, src, count) memcpy(dest, src, count)
#define _countof(arr)   ((sizeof(arr))/(sizeof(arr[0])))
