// Copyright (C) Microsoft Corporation. All rights reserved.
//
// This header file is used to include platform-specific headers of JsonCpp library.

#pragma once

#include <playfab/PlayFabPlatformMacros.h>

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
#include <jsoncpp/json/json.h>
#endif // PLAYFAB_PLATFORM_WINDOWS || PLAYFAB_PLATFORM_XBOX

#if defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID)
#include <jsoncpp/json/json.h>
#endif // PLAYFAB_PLATFORM_LINUX
