#pragma once

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN

// Windows Header Files
#include <windows.h>

// Standard library headers
#include <assert.h>
#include <stdarg.h>
#include <thread>
#include <mutex>
#include <vector>

// External dependencies
#include <Party.h>

// Headers from PartyNetworkSampleCommon
#include <Managers.h>

#include "App.h"
#include "NetworkStateChangeManager.h"
#include "Log.h"
