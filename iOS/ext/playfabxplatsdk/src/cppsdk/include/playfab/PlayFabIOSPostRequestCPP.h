#pragma once
#include <string>
#include <playfab/PlayFabCallRequestContainer.h>

namespace PlayFabInternal
{
    class PlayFabIOSPostRequestCPP
    {
    public:
        static void prepare(const std::string &url, const std::string &body);
        static bool open(CallRequestContainer& req, Int32& httpStatusCode);
        static void AddContainerHeaders(const std::string &HeaderKey, const std::string &HeaderValue);
        static void SetPlayFabPredefinedHeaders();
    };
};
