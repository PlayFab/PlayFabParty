// Copyright (C) Microsoft Corporation. All rights reserved.
//
// This header file is used to include headers of transport plugins supported on each platform.

#pragma once

#include <playfab/PlayFabPlatformMacros.h>

#if defined(PLAYFAB_PLATFORM_XBOX)  || defined(PLAYFAB_PLATFORM_UWP)
#include <playfab/PlayFabIXHR2HttpPlugin.h>
#endif // PLAYFAB_PLATFORM_XBOX

#if defined(PLAYFAB_PLATFORM_WINDOWS) && !defined(PLAYFAB_PLATFORM_UWP)
#include <playfab/PlayFabWinHttpPlugin.h>
#endif // PLAYFAB_PLATFORM_WINDOWS

#ifdef PLAYFAB_PLATFORM_LINUX
#include <playfab/PlayFabCurlHttpPlugin.h>
#endif // PLAYFAB_PLATFORM_LINUX

#if defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_MACOS)
#include <playfab/PlayFabIOSHttpPlugin.h>
#endif // PLAYFAB_PLATFORM_IOS || PLAYFAB_PLATFORM_MACOS

#ifdef PLAYFAB_PLATFORM_ANDROID
#include <playfab/PlayFabAndroidHttpPlugin.h>
#endif // PLAYFAB_PLATFORM_ANDROID
