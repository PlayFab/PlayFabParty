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
            RegionResult(PlayFabInternal::MultiplayerModels::AzureRegion region, int latencyMs, int errorCode);
            RegionResult() = delete;

            // The datacenter region
            PlayFabInternal::MultiplayerModels::AzureRegion region;

            // Average latency to reach the data center
            int latencyMs;

            // Last error code recieved while pinging
            int errorCode;
        };
    }
}