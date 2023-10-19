#pragma once

//Include c++ std library utilities
#include <mutex>
#include <string>
#include <queue>
#include <errno.h>

//Include platform specific definitions
#if defined(__ANDROID__) || defined(__APPLE__)
#include "PosixPch.h"
#elif defined(_WIN32)
#include "WinPch.h"
#endif // __ANDROID__ || __APPLE__ || _WIN32

//Include the Party Libraries
#include <Party.h>
#include <Party_c.h>

//Include the local headers
#include "Manager.h"
#include "NetworkMessages.h"
#include "NetworkManager.h"
#include "PlayFabManager.h"
#include "INetworkStateChangeManager.h"
#include "DebugLog.h"
