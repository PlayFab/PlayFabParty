// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#ifdef SDK_UNIX
#include <pal.h>
#endif // SDK_UNIX

#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <future>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <chrono>
#include <mutex>
#include <condition_variable>
#include <thread>

#include <playfab/PlayFabPlatformMacros.h>

#define UNREFERENCED_PARAMETER(P) (P)

#if defined (PLAYFAB_PLATFORM_LINUX)
#include <stdio.h>
#elif defined (PLAYFAB_PLATFORM_WINDOWS) || defined (_WIN32)

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <json/json.h>

#endif // PLAYFAB_PLATFORM_LINUX

#include <playfab/PlayFabJsonHeaders.h>