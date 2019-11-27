#include <stdafx.h>

#include <playfab/QoS/RegionResult.h>

namespace PlayFabInternal
{
    namespace QoS
    {
        RegionResult::RegionResult(const std::string& region, int latencyMs, int errorCode) :
            region(region), latencyMs(latencyMs), errorCode(errorCode)
        {
        }
    }
}