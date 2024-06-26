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
        class DataCenterResult
        {
        public:
            DataCenterResult(PlayFabInternal::MultiplayerModels::AzureRegion region, const std::string& dataCenterName, int latencyMs, int errorCode);
            DataCenterResult() = delete;
            DataCenterResult(DataCenterResult&&) = default;
            DataCenterResult(const DataCenterResult&) = delete;
            DataCenterResult& operator=(DataCenterResult&&) = delete;
            DataCenterResult& operator=(const DataCenterResult&) = delete;

            // The datacenter region
            PlayFabInternal::MultiplayerModels::AzureRegion region;

            // The datacenter name
            std::string dataCenterName;

            // Average latency to reach the data center
            int latencyMs;

            // Last error code recieved while pinging
            int lastErrorCode;
        };
    }
}