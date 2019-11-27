#include <stdafx.h>

#include <playfab/QoS/DataCenterResult.h>

using namespace std;

namespace PlayFabInternal
{
    namespace QoS
    {
        DataCenterResult::DataCenterResult(PlayFabInternal::MultiplayerModels::AzureRegion region, const std::string& dataCenterName, int latencyMs, int errorCode) :
            region(region), dataCenterName(dataCenterName), latencyMs(latencyMs), lastErrorCode(errorCode)
        {
        }
    }
}