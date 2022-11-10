// Copyright (C) Microsoft Corporation. All rights reserved.
//
// This header file is used to include platform-specific headers of JsonCpp library.

#pragma once

#include <playfab/PlayFabPlatformMacros.h>

/*
BUMBLELION CHANGE
Adjusted the #include paths to always pull from the jsoncpp source code included locally here in our copy of the 
PlayFabXPlatSDK
*/

#include <jsoncpp/json/json.h>

#if defined(PLAYFAB_PLATFORM_SWITCH)
#include <jsoncpp/json/json-forwards.h>
#else // PLAYFAB_PLATFORM_SWITCH
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>
#endif // PLAYFAB_PLATFORM_SWITCH
