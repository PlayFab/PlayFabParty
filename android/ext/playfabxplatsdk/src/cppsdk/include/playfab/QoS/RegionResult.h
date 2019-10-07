#pragma once

#include <string>
#include <playfab/PlayFabMultiplayerDataModels.h>

namespace PlayFabInternal
{
    namespace QoS
    {
        /// <summary>
        /// The result of pinging a datacenter.
        /// </summary>
        struct RegionResult
        {
        public:
            RegionResult(std::string region, int latencyMs, int errorCode);
            RegionResult() = delete;

            // The datacenter region
            std::string region;

            // Average latency to reach the data center
            int latencyMs;

            // Last error code recieved while pinging
            int errorCode;
        };
    }
}
