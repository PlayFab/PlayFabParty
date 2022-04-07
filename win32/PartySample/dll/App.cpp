// App.cpp: Provides an interop layer so that the main C# app can interact with the underlying C++ sample

#include "pch.h"

static std::mutex g_appMutex;
// App state guarded by g_appMutex
static std::string g_activePartyNetworkRoomId;
static bool g_joinNetworkInProgress = false;
static bool g_leaveNetworkInProgress = false;

static
const char*
GetPartyErrorMessage(
    PartyError error
    )
{
    const char* errorMessage;
    if (PARTY_SUCCEEDED(Party::PartyManager::GetErrorMessage(error, &errorMessage)))
    {
        return errorMessage;
    }
    else
    {
        return "<unrecognizd PartyError>";
    }
}

static
void
AppThread()
{
    while (true)
    {
        PartySample::Managers::Get<PartySample::PlayFabManager>()->Tick();
        PartySample::Managers::Get<PartySample::NetworkManager>()->DoWork();
        Sleep(30);
    }
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_Initialize(
    const char* playFabTitleId,
    const char* playFabPlayerCustomId,
    OnPlayerJoinedCallback onPlayerJoinedCallback,
    OnPlayerChatIndicatorUpdatedCallback onPlayerChatIndicatorUpdatedCallback,
    OnPlayerTextMessageReceivedCallback onPlayerTextMessageReceivedCallback,
    OnPlayerVoiceTranscriptionReceivedCallback onPlayerVoiceTranscriptionReceivedCallback,
    OnPlayerLeftCallback onPlayerLeftCallback
    )
{

    PartySample::Managers::Initialize<NetworkStateChangeManager>();
    PartySample::Managers::Get<NetworkStateChangeManager>()->Initialize(
        onPlayerJoinedCallback,
        onPlayerChatIndicatorUpdatedCallback,
        onPlayerTextMessageReceivedCallback,
        onPlayerVoiceTranscriptionReceivedCallback,
        onPlayerLeftCallback);
    PartySample::Managers::Get<PartySample::PlayFabManager>()->Initialize(playFabTitleId);

    const std::string titleId = playFabTitleId;
    auto OnPlayFabSignInComplete = [titleId, onPlayerJoinedCallback](bool succeeded, std::string errorMessage)
    {
        if (!succeeded)
        {
            QueueLog("SignIn", "Failed! error=\"%s\"", errorMessage.c_str());
            return;
        }

        QueueLog("SignIn", "Succeeded!");

        // Don't initialize PlayFab Party (via NetworkManager) until PlayFab Signin completes.
        // NetworkManager depends on signin setting the PlayFabManager's EntityID and EntityToken.
        PartySample::Managers::Get<PartySample::NetworkManager>()->Initialize(titleId.c_str());

        // TODO: Currently, the NetworkManager in PartyNetworkSampleCommon doesn't fire any events for when the
        // local user is recognized as part of the session. For now, mimic alerting the app of the local user "joining"
        // here.
        onPlayerJoinedCallback(
            PartySample::Managers::Get<PartySample::PlayFabManager>()->EntityId().c_str(),
            PartySample::Managers::Get<PartySample::PlayFabManager>()->displayName().c_str());
    };

    PartySample::Managers::Get<PartySample::PlayFabManager>()->SignIn(OnPlayFabSignInComplete, playFabPlayerCustomId);
    std::thread(AppThread).detach();
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_PollLogQueue(
    LogCallback callback
    )
{
    for (const AppLogEntry& log : DrainLogQueue())
    {
        callback(log.system.c_str(), log.message.c_str());
    }
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_CreateAndJoinPartyNetwork(
    const char* partyNetworkRoomId
    )
{
    std::lock_guard<std::mutex> g_appLock(g_appMutex);

    if (g_joinNetworkInProgress)
    {
        QueueLog("Network", "Cannot create network while joining another network.");
        return;
    }

    if (!g_activePartyNetworkRoomId.empty())
    {
        QueueLog("Network", "Cannot create network while joined to a network.");
        return;
    }

    g_joinNetworkInProgress = true;

    // capture the room id so it can be logged later in the async callbacks
    const std::string roomId = partyNetworkRoomId;

    auto OnCreatePartyNetworkSucceeded = [roomId](std::string networkDescriptor)
    {
        QueueLog("Network", "PartyNetwork \"%s\" created! NetworkDescriptor=\"%s\"", roomId.c_str(), networkDescriptor.c_str());
        QueueLog("Network", "Sharing NetworkDescriptor for \"%s\"...", roomId.c_str());

        auto OnSetNetworkDescriptorCompleted = [roomId]()
        {
            QueueLog("Network", "NetworkDescriptor for \"%s\" shared!", roomId.c_str());
        };

        PartySample::Managers::Get<PartySample::PlayFabManager>()->SetDescriptor(
            roomId,
            networkDescriptor,
            OnSetNetworkDescriptorCompleted);

        g_activePartyNetworkRoomId = roomId;
        g_joinNetworkInProgress = false;
    };

    auto OnCreatePartyNetworkFailed = [roomId](PartyError error)
    {
        QueueLog(
            "Network",
            "Failed to create PartyNetwork for \"%s\"! err=0x%08x \"%s\"",
            roomId.c_str(),
            error,
            GetPartyErrorMessage(error));
        g_joinNetworkInProgress = false;
    };

    PartySample::Managers::Get<PartySample::NetworkManager>()->CreateAndConnectToNetwork(
        partyNetworkRoomId,
        OnCreatePartyNetworkSucceeded,
        OnCreatePartyNetworkFailed);
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_JoinPartyNetwork(
    const char* partyNetworkRoomId
    )
{
    std::lock_guard<std::mutex> g_appLock(g_appMutex);

    if (g_joinNetworkInProgress)
    {
        QueueLog("Network", "Cannot join new network while joining another network.");
        return;
    }

    if (!g_activePartyNetworkRoomId.empty())
    {
        QueueLog("Network", "Cannot join new network while joined to a network.");
        return;
    }

    g_joinNetworkInProgress = true;

    // capture the room id so it can be logged later in the async callbacks
    const std::string roomId = partyNetworkRoomId;

    auto OnDescriptorFetched = [roomId](std::string networkDescriptor)
    {
        QueueLog("Network", "Found network descriptor for \"%s\": \"%s\"", roomId.c_str(), networkDescriptor.c_str());

        auto OnJoinPartyNetworkSucceeded = [roomId]()
        {
            QueueLog("Network", "PartyNetwork \"%s\" joined!", roomId.c_str());

            g_activePartyNetworkRoomId = roomId;
            g_joinNetworkInProgress = false;
        };

        auto OnJoinPartyNetworkFailed = [roomId](PartyError error)
        {
            QueueLog(
                "Network",
                "Failed to join PartyNetwork for \"%s\"! err=0x%08x \"%s\"",
                roomId.c_str(),
                error,
                GetPartyErrorMessage(error));

            g_joinNetworkInProgress = false;
        };

        PartySample::Managers::Get<PartySample::NetworkManager>()->ConnectToNetwork(
            roomId.c_str(),
            networkDescriptor.c_str(),
            OnJoinPartyNetworkSucceeded,
            OnJoinPartyNetworkFailed);
    };

    PartySample::Managers::Get<PartySample::PlayFabManager>()->GetDescriptor(partyNetworkRoomId, OnDescriptorFetched);
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_LeavePartyNetwork()
{
    std::lock_guard<std::mutex> g_appLock(g_appMutex);

    if (g_leaveNetworkInProgress)
    {
        QueueLog("Network", "Cannot leave network while leaving already in progress.");
        return;
    }

    if (g_activePartyNetworkRoomId.empty())
    {
        QueueLog("Network", "Not currently joined to any network");
        return;
    }

    g_leaveNetworkInProgress = true;

    auto OnLeavePartyNetworkCompleted = []()
    {
        QueueLog("Network", "PartyNetwork \"%s\" left!", g_activePartyNetworkRoomId.c_str());

        g_activePartyNetworkRoomId.clear();
        g_leaveNetworkInProgress = false;
    };

    PartySample::Managers::Get<PartySample::NetworkManager>()->LeaveNetwork(OnLeavePartyNetworkCompleted);
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_SendChatText(
    const char* chatText
    )
{
    PartySample::Managers::Get<PartySample::NetworkManager>()->SendTextMessage(chatText);
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_SynthesizeTextToSpeech(
    const char* textToSynthesize
    )
{
    PartySample::Managers::Get<PartySample::NetworkManager>()->SendTextAsVoice(textToSynthesize);
}

__declspec(dllexport)
void
__stdcall
PartySampleApp_SetPlayerMute(
    const char* playerEntityId,
    bool isMuted
    )
{
    const std::string& localPlayerEntityId = PartySample::Managers::Get<PartySample::PlayFabManager>()->EntityId();
    if (playerEntityId == localPlayerEntityId)
    {
        PartySample::Managers::Get<PartySample::NetworkManager>()->SetLocalPlayerMuted(isMuted);
    }
    else
    {
        PartySample::Managers::Get<PartySample::NetworkManager>()->SetRemotePlayerMuted(playerEntityId, isMuted);
    }
}
