#pragma once

#include "PartyPal.h"

#define MultiByteToWideChar(codePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar) \
    (static_cast<int>(std::mbstowcs((lpWideCharStr), (lpMultiByteStr), (static_cast<size_t>(cbMultiByte)))))

#define CopyMemory(dest, src, count) memcpy(dest, src, count)
#define _countof(arr)   ((sizeof(arr))/(sizeof(arr[0])))
