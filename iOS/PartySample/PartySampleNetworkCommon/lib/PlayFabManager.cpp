#include "pch.h"
#include "PlayFabManager.h"
#include "Managers.h"

#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabAuthenticationApi.h"
#include "playfab/PlayFabMultiplayerApi.h"
#include "playfab/PlayFabDataApi.h"

using namespace PartySample;
#ifdef USE_PUBLIC_PLAYFAB_SDK
using namespace PlayFab;
#else
using namespace PlayFabInternal;
#endif
using namespace ClientModels;

PlayFabManager::PlayFabManager()
{
}

PlayFabManager::~PlayFabManager()
{
}

void PlayFabManager::Initialize(
    const char* titleId
    )
{
    // Set the title id to be used for all future calls.
    PlayFabSettings::titleId = titleId;
}

// Authenticate the user with playfab using the specified custom id and setting the display name to that id.
void 
PlayFabManager::SignIn(
    std::function<void(bool, std::string&)> callback, 
    std::string userId
    )
{
    DEBUGLOG("PlayFabManager::SignIn()\n");

    // Create a login request with the userId as customId, creating an account if none exists.
    LoginWithCustomIDRequest loginRequest;
    loginRequest.CreateAccount = true;
    loginRequest.CustomId = userId.c_str();

    // Request player data with the sign in request to check the display name.
    GetPlayerCombinedInfoRequestParams reqParams;
    reqParams.GetUserAccountInfo = true;
    loginRequest.InfoRequestParameters = reqParams;

    // Try to login.
    DEBUGLOG("Login with custom id called %s\n", userId.c_str());

    PlayFabClientAPI::LoginWithCustomID(
        loginRequest,
        [this, callback, userId](const LoginResult& loginResult, void*)
        {
            // Sign in was successful.
            DEBUGLOG("Playfab::signin -- Login with custom id callback\n");

            // Save the PlayFab id and entity data for Party authentication.
            m_playfabId = loginResult.PlayFabId;
            if (loginResult.EntityToken.notNull() && loginResult.EntityToken->Entity.notNull())
            {
                m_entityKey = loginResult.EntityToken->Entity;
                m_entityToken = loginResult.EntityToken->EntityToken;
            }

            // Attempt to get the display name.
            if (loginResult.InfoResultPayload.notNull() &&
                loginResult.InfoResultPayload->AccountInfo.notNull() &&
                loginResult.InfoResultPayload->AccountInfo->TitleInfo.notNull())
            {
                m_displayName = loginResult.InfoResultPayload->AccountInfo->TitleInfo->DisplayName;
            }

            // Save the display name locally if it is not empty.
            if (m_displayName.empty())
            {
                m_displayName = m_entityKey.Id;
            }

            // If the display name does not match the user id, update the display name on PlayFab.
            if (m_displayName.empty() || m_displayName != userId)
            {
                // Create a request to update the display name to the userId
                UpdateUserTitleDisplayNameRequest updateDisplayNameRequest;
                updateDisplayNameRequest.DisplayName = userId.c_str();

                //Attempt to update the display name.
                PlayFabClientAPI::UpdateUserTitleDisplayName(
                    updateDisplayNameRequest,
                    [this, callback](const UpdateUserTitleDisplayNameResult& result, void*)
                    {
                        // We were able to update the display name.
                        // Call the callback with success and an empty error message.
                        if (callback != nullptr)
                        {
                            m_displayName = result.DisplayName;
                            std::string message;
                            callback(true, message);
                        }
                    },
                    [callback](const PlayFabError& error, void*)
                    {
                        // We were unable to update the user display name.
                        // Call the callback with an error message.
                        if (callback != nullptr)
                        {
                            std::string message(error.ErrorMessage);
                            callback(false, message);
                        }
                    }
                );
            }
            else
            {
                // Sign in was successful and the display name is already set.
                // Call the callback if it exists.
                if (callback != nullptr)
                {
                    std::string message;
                    callback(true, message);
                }
            }
        },
        [callback](const PlayFabError& error, void*)
        {
            // On failure, send an error message to the callback if it exists.
            if (callback != nullptr)
            {
                std::string message = error.ErrorMessage;
                callback(false, message);
            }
        }
    );
}

// Update the internal APIs
void 
PlayFabManager::Tick()
{
    PlayFabClientAPI::Update();
    PlayFabMultiplayerAPI::Update();
    PlayFabDataAPI::Update();
}

void 
PlayFabManager::onSetDescriptorSuccess(
    ExecuteCloudScriptResult& response, 
    void* customData
    )
{
    // Log success to standard output
    DEBUGLOG("Success setting object\n");

    // Send a message to the chat window indicating succeess
    std::string sender("System");
    std::string message("Network data saved.");
    Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

    // Call the callback function.
    m_onCompletedSettingDescriptor();
}

void 
PlayFabManager::onSetDescriptorFailed(
    const PlayFab::PlayFabError&, 
    void* customData
    )
{
    // Log the failure to standard output.
    DEBUGLOG("Fail setting object\n");

    //Send a message to the chat window indicating failure.
    std::string sender("System");
    std::string message("Failed to set network.");
    Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

    // Call the callback function.
    m_onCompletedSettingDescriptor();
}

// Static callback function to pass the response to the PlayFabManager class.
void 
onSetDescriptorSuccessCallback(
    ExecuteCloudScriptResult result, 
    void* customData
    )
{
    Managers::Get<PlayFabManager>()->onSetDescriptorSuccess(result, customData);
}

// Static callback function to pass the response to the PlayFabManager class.
void 
onSetDescriptorFailCallback(
    const PlayFab::PlayFabError& error, 
    void* customData
    )
{
    Managers::Get<PlayFabManager>()->onSetDescriptorFailed(error, customData);
}

void 
PartySample::PlayFabManager::SetDescriptor(
    std::string key, 
    std::string descriptor, 
    std::function<void()> onComplete
    )
{
    m_onCompletedSettingDescriptor = onComplete;

    // Create data indicating to network Id as a key and the descriptor as a value to be stored on the title group storage.
    Json::Value param;
    param["roomId"] = key;
    param["networkDescriptor"] = descriptor;

    // Create the save network descriptor cloud script call using the above data.
    ClientModels::ExecuteCloudScriptRequest request;
    request.FunctionName = "save_network_descriptor";
    request.FunctionParameter = param;

    // Put a message in the chat window indicating that the descriptor is being saved
    char messageBuffer[500];
    sprintf(messageBuffer, "Saving out network data: %s.", descriptor.c_str());
    std::string sender("System");
    std::string message(messageBuffer);
    Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

    // Execute the above cloud script.
    PlayFabClientAPI::ExecuteCloudScript(request, onSetDescriptorSuccessCallback, onSetDescriptorFailCallback);
}

void 
PartySample::PlayFabManager::onGetDescriptorSuccess(
    ExecuteCloudScriptResult& result, 
    void* customData
    )
{
    std::string networkDescriptor;

    // Check if there was an error making the call
    if (result.Error.notNull())
    {
        // An error occured in the cloud script, output the error to standard output
        DEBUGLOG("CloudScript error occured: %hs\n", result.Error->Message.c_str());
        if (m_onCompletedGettingDescriptor != nullptr)
        {
            // Send an error message to the chat window.
            std::string sender("System");
            std::string message("No network id found.");
            Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

            // Call the callback with an empty network descriptor to indicate an error.
            m_onCompletedGettingDescriptor(networkDescriptor);
        }
    }
    else
    {
        // Check the result to make sure its not empty.
        if (result.FunctionResult.empty())
        {
            if (m_onCompletedGettingDescriptor != nullptr)
            {
                // Send an error message to the chat window.
                std::string sender("System");
                std::string message("No network id found.");
                Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

                // Call the callback with an empty network descriptor to indicate an error.
                m_onCompletedGettingDescriptor(networkDescriptor);
            }
        }
        else
        {
            if (m_onCompletedGettingDescriptor != nullptr)
            {
                // Get the network descriptor from the result data.
                networkDescriptor = result.FunctionResult["network"]["Value"].asString();
                DEBUGLOG("Success getting object: %s\n", networkDescriptor.c_str());

                // Send the network descriptor to the chat window.
                char messageBuffer[500];
                sprintf(messageBuffer, "Network found: %s.", networkDescriptor.c_str());
                std::string sender("System");
                std::string message(messageBuffer);
                Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

                // Call the callback with the retrieved network descriptor.
                m_onCompletedGettingDescriptor(networkDescriptor);
            }
        }
    }
}

void  
PartySample::PlayFabManager::onGetDescriptorFail(
    const PlayFab::PlayFabError& error, 
    void* customData
    )
{
    // Post a system message indicating failure to the chat window.
    std::string sender("System");
    std::string message("Failed to get network.");
    Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(sender, message);

    // Log the failure.
    DEBUGLOG("Fail setting object\n");

    //Call the completion callback with an empty string to indicate failure.
    std::string result;
    m_onCompletedGettingDescriptor(result);
}

// Static callback for getting the success callback for the network descriptor and passing it to the manager class.
void 
onGetObjectSuccessCallback(
    ExecuteCloudScriptResult response, 
    void* customData
    )
{
    Managers::Get<PlayFabManager>()->onGetDescriptorSuccess(response, customData);
}

// Static callback to receive the failed callback for getting the network descriptor and passing it to the manager class.
void 
onGetObjectFailCallback(
    const PlayFab::PlayFabError& error, 
    void* customData
    )
{
    Managers::Get<PlayFabManager>()->onGetDescriptorFail(error, customData);
}

void 
PartySample::PlayFabManager::GetDescriptor(
    std::string key, 
    std::function<void(std::string)> onComplete
    )
{
    // Set the completion callback.
    m_onCompletedGettingDescriptor = onComplete;

    // Set the network id that we are using to identify which descriptor we want.
    Json::Value param;
    param["roomId"] = key;

    // Create a network request to get the network descriptor with the above key.
    ClientModels::ExecuteCloudScriptRequest request;
    request.FunctionName = "get_network_descriptor";
    request.FunctionParameter = param;

    //Execute the cloud script.
    PlayFabClientAPI::ExecuteCloudScript(request, onGetObjectSuccessCallback, onGetObjectFailCallback);
}
