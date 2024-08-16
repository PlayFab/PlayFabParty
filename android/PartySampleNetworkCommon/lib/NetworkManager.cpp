#include "pch.h"
#include "NetworkManager.h"
#include "Managers.h"
#include "PartyImpl.h"

using namespace PartySample;
using namespace Party;

NetworkManager::NetworkManager() :
    m_state(NetworkManagerState::Initialize),
    m_localUser(nullptr),
    m_localEndpoint(nullptr),
    m_localChatControl(nullptr),
    m_network(nullptr),
    m_isChatControlConnected(false),
    m_isTextToSpeechProfileSet(false),
    m_partyInitialized(false),
    m_populateProfilesCompleted(false),
    m_ttsProfileNeedsUpdate(false),
    m_languageCode("en-US"),
    m_languageName("English (United States)"),
    m_renderVolume(1.f)
{
}

NetworkManager::~NetworkManager()
{
    DEBUGLOG("NetworkManager::~NetworkManager()\n");
}

void
NetworkManager::SetLanguageCode(
    const char* lang,
    const char* name
    )
{
    DEBUGLOG("setting language %s \n", m_languageCode);

    //Record the language code locally for use when creating the local chat control.
    m_languageCode = lang;
    m_languageName = name;

    //If the chat control already exists, try to change the language.
    if (m_localChatControl != nullptr)
    {
        //Set the language code on the chat control.
        PartyError err = m_localChatControl->SetLanguage(   // Not implemented yet
            m_languageCode,                                 // Language Code
            nullptr                                         // Async identifier
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Setting the language failed: %s \n", GetErrorMessage(err));
        }

        // Update the text to speech profile later in the DoWork loop.
        m_ttsProfileNeedsUpdate = true;
    }
}

void
NetworkManager::Initialize(
    const char* titleId
    )
{
    DEBUGLOG("NetworkManager::Initialize()\n");

    auto& partyManager = PartyManager::GetSingleton();
    PartyError err;

    //Only initialize the party manager once.
    if (m_partyInitialized == false)
    {
        // Initialize PlayFab Party
        err = partyManager.Initialize(titleId);
        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Initialize failed: %s\n", GetErrorMessage(err));
            return;
        }

        m_partyInitialized = true;
    }

    //Only create a local user object if it doesn't exist.
    if (m_localUser == nullptr)
    {
        PartyString entityId = Managers::Get<PlayFabManager>()->EntityId().c_str();
        PartyString entityToken = Managers::Get<PlayFabManager>()->EntityToken().c_str();

        // Create a local user object
        err = partyManager.CreateLocalUser(
            entityId,                                   // User id
            entityToken,                                // User entity token
            &m_localUser                                // OUT local user object
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("CreateLocalUser failed: %s\n", GetErrorMessage(err));
            return;
        }
    }
}

void
NetworkManager::Shutdown()
{
    DEBUGLOG("NetworkManager::Shutdown()\n");
    std::unique_lock<std::mutex> lock(m_networkLock);
    m_state = NetworkManagerState::Initialize;

    // This cleans up everything allocated in Initialize() and
    // should only be used when done with networking
    PartyManager::GetSingleton().Cleanup();

    m_localChatControl = nullptr;
    m_localEndpoint = nullptr;
    m_network = nullptr;
    m_localUser = nullptr;
    m_partyInitialized = false;
    m_isChatControlConnected = false;
    m_isTextToSpeechProfileSet = false;
    m_populateProfilesCompleted = false;
    m_ttsProfileNeedsUpdate = false;
}

// Note: This PlayFabParty sample integration sets all chatControl objects to the same volume
// attenuation.  As such, it also caches the volume setting so that newly created chatControls
// (ie when a new user joins the chat room) can have their volume set to match. Note that it is
// also possible to set volume on a per chatControl (that is, per user) basis provided that you have
// the UI implemented to do so.
void
NetworkManager::SetPlayerVolume(
    float volumeZeroToOne
    )
{
    if (m_renderVolume == volumeZeroToOne) {
        return;
    }

    std::unique_lock<std::mutex> lock(m_networkLock);
    m_renderVolume = volumeZeroToOne;
    for (auto cc : m_chatControls)
    {
        if(cc.second == m_localChatControl)
        {
            continue;
        }

        PartyError err = m_localChatControl->SetAudioRenderVolume(cc.second, volumeZeroToOne);
        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetAudioRenderVolume failed for chat control 0x%p: %s\n", cc.second, GetErrorMessage(err));
        }
    }
}

void
NetworkManager::CreateAndConnectToNetwork(
    const char* networkId,
    std::function<void(std::string)> callback,
    std::function<void(PartyError)> errorCallback
    )
{
    DEBUGLOG("NetworkManager::CreateAndConnectToNetwork()\n");

    PartyNetworkConfiguration cfg = {};

    // Set up the network to allow 29 single-device players of any device type
    cfg.maxDeviceCount = 29;
    cfg.maxDevicesPerUserCount = 1;
    cfg.maxEndpointsPerDeviceCount = 1;
    cfg.maxUserCount = 29;
    cfg.maxUsersPerDeviceCount = 1;

    //Get the uid from the local chat control
    PartyString uid = nullptr;
    PartyError err = m_localUser->GetEntityId(&uid);

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("GetEntityId failed: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return;
    }

    // Setup the network invitation configuration to use the network id as an invitation id and allow anyone to join.
    PartyInvitationConfiguration invitationConfiguration{
        networkId,                                  // invitation identifier
        PartyInvitationRevocability::Anyone,        // revokability
        0,                                          // authorized user count
        nullptr                                     // authorized user list
    };

    // Initialize an empty network descriptor to hold the result of the following call.
    PartyNetworkDescriptor networkDescriptor = {};

    // Create a new network descriptor
    err = PartyManager::GetSingleton().CreateNewNetwork(
        m_localUser,                                // Local User
        &cfg,                                       // Network Config
        0,                                          // Region List Count
        nullptr,                                    // Region List
        &invitationConfiguration,                   // Invitation configuration
        nullptr,                                    // Async Identifier
        &networkDescriptor,                         // OUT network descriptor
        nullptr                                     // applied initialinvitationidentifier.
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("CreateNewNetwork failed: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return;
    }

    // Connect to the new network
    if (InternalConnectToNetwork(networkDescriptor, networkId, errorCallback))
    {
        m_state = NetworkManagerState::WaitingForNetwork;
        m_onNetworkCreated = callback;
        m_onNetworkCreatedError = errorCallback;
        m_onNetworkConnectedError = errorCallback;
    }
}

void
NetworkManager::ConnectToNetwork(
    const char* networkId,
    const char* descriptor,
    std::function<void(void)> callback,
    std::function<void(PartyError)> errorCallback
    )
{
    DEBUGLOG("NetworkManager::ConnectToNetwork()\n");

    PartyNetworkDescriptor networkDescriptor = {};

    // Deserialize the remote network's descriptor
    PartyError err = PartyManager::DeserializeNetworkDescriptor(descriptor, &networkDescriptor);

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectToNetwork failed to deserialize descriptor: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return;
    }

    // Connect to the remote network
    if (InternalConnectToNetwork(networkDescriptor, networkId, errorCallback))
    {
        m_state = NetworkManagerState::WaitingForNetwork;
        m_onNetworkConnected = callback;
        m_onNetworkConnectedError = errorCallback;
    }
}

PartyError
NetworkManager::CreateChatControlIfNecessary()
{
    auto& partyManager = PartyManager::GetSingleton();

    // Only create local chat controls if they don't exist.
    if (m_localChatControl == nullptr)
    {
        PartyLocalDevice* localDevice = nullptr;

        // Retrieve the local device
        PartyError err = partyManager.GetLocalDevice(&localDevice);

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("GetLocalDevice failed: %s\n", GetErrorMessage(err));
            return err;
        }

        // Create a chat control for the local user on the local device
        err = localDevice->CreateChatControl(
                m_localUser,                                // Local user object
                m_languageCode,                             // Language id
                nullptr,                                    // Async identifier
                &m_localChatControl                         // OUT local chat control
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("CreateChatControl failed: %s\n", GetErrorMessage(err));
            return err;
        }

        // Use system default settings for the audio input device
        err = m_localChatControl->SetAudioInput(
                PartyAudioDeviceSelectionType::SystemDefault,   // Selection type
                nullptr,                                        // Device id
                nullptr                                         // Async identifier
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetAudioInput failed: %s\n", GetErrorMessage(err));
            return err;
        }

        // Use system default settings for the audio output device
        err = m_localChatControl->SetAudioOutput(
                PartyAudioDeviceSelectionType::SystemDefault,   // Selection type
                nullptr,                                        // Device id
                nullptr                                         // Async identifier
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetAudioOutput failed: %s\n", GetErrorMessage(err));
            return err;
        }

        // Get the available list of text to speech profiles
        err = m_localChatControl->PopulateAvailableTextToSpeechProfiles(nullptr);

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Populating available TextToSpeechProfiles failed: %s \n", GetErrorMessage(err));
            return err;
        }

        // Set transcription options for transcribing other users regardless of language, and ourselves.
        PartyVoiceChatTranscriptionOptions transcriptionOptions =
                PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithMatchingLanguages |
                PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithNonMatchingLanguages |
                PartyVoiceChatTranscriptionOptions::TranslateToLocalLanguage |
                PartyVoiceChatTranscriptionOptions::TranscribeSelf;

        // Set the transcription options on our chat control.
        err = m_localChatControl->SetTranscriptionOptions(
                transcriptionOptions,                       // Transcription options
                nullptr                                     // Async identifier
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetTranscriptionOptions failed: %s\n", GetErrorMessage(err));
            return err;
        }

        // Enable translation to local language in chat controls.
        err = m_localChatControl->SetTextChatOptions(
                PartyTextChatOptions::TranslateToLocalLanguage,
                nullptr
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetTextChatOptions failed: %s\n", GetErrorMessage(err));
            return err;
        }
    }

    return c_partyErrorSuccess;
}

bool
NetworkManager::InternalConnectToNetwork(
    const Party::PartyNetworkDescriptor& descriptor,
    const char* networkId,
    std::function<void(PartyError)> errorCallback
    )
{
    // Before trying to connect to a chat network, we may need to
    // create the chat controls in case they haven't already been set up
    PartyError err = CreateChatControlIfNecessary();
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectToNetwork failed when trying to create chat controls!");
        errorCallback(err);
        return false;
    }

    // This portion of connecting to the network is the same for
    // both creating a new and joining an existing network.
    err = PartyManager::GetSingleton().ConnectToNetwork(
        &descriptor,                                // Network descriptor
        nullptr,                                    // Async identifier
        &m_network                                  // OUT network
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectToNetwork failed: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return false;
    }

    // Authenticate the local user on the network so we can participate in it
    err = m_network->AuthenticateLocalUser(
        m_localUser,                                // Local user
        networkId,                                  // Invitation Id
        nullptr                                     // Async identifier
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("AuthenticateLocalUser failed: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return false;
    }

    // Connect the local user chat control to the network so we can use VOIP
    err = m_network->ConnectChatControl(
        m_localChatControl,                         // Local chat control
        nullptr                                     // Async identifier
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectChatControl failed: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return false;
    }

    // Establish a network endoint for game message traffic
    err = m_network->CreateEndpoint(
        m_localUser,                                // Local user
        0,                                          // Property Count
        nullptr,                                    // Property name keys
        nullptr,                                    // Property Values
        nullptr,                                    // Async identifier
        &m_localEndpoint                            // OUT local endpoint
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("Failed to CreateEndpoint: %s\n", GetErrorMessage(err));
        errorCallback(err);
        return false;
    }

    return true;
}

void
NetworkManager::SendNetworkMessage(
    uint32_t targetCount,
    PartyEndpoint** targets,
    const NetworkMessage& message
    )
{
    if (m_localEndpoint && m_state == NetworkManagerState::NetworkConnected)
    {
        auto packet = message.Serialize();

        // Form the data packet into a data buffer structure
        PartyDataBuffer data[] = {
            {
                static_cast<const void*>(packet.data()),
                static_cast<uint32_t>(packet.size())
            },
        };

        // Set delivery options for guaranteed and sequential delivery.
        PartySendMessageOptions deliveryOptions =
            PartySendMessageOptions::GuaranteedDelivery |
            PartySendMessageOptions::SequentialDelivery;

        // Send out the message to all other peers
        PartyError err = m_localEndpoint->SendMessage(
            targetCount,                            // endpoint count; 0 = broadcast
            targets,                                // endpoint list
            deliveryOptions,                        // send message options
            nullptr,                                // configuration
            1,                                      // buffer count
            data,                                   // buffer
            nullptr                                 // async identifier
        );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Failed to SendMessage: %s\n", GetErrorMessage(err));
        }
    }
}

void
NetworkManager::BroadcastNetworkMessage(
    const NetworkMessage& message
    )
{
    SendNetworkMessage(0, nullptr, message);
}

void
NetworkManager::SendTextAsVoice(
    std::string text
    )
{
    // Only synthesize TTS voice if we've got a local chat control
    if (m_localChatControl == nullptr)
    {
        DEBUGLOG("Info: Can't SynthesizeTextToSpeech. No local chat control.");
        return;
    }

    // Synthesize the text to speech.
    DEBUGLOG("Synthesizing speech for text \"%s\"\n", text.c_str());
    PartyError err = m_localChatControl->SynthesizeTextToSpeech(
        PartySynthesizeTextToSpeechType::VoiceChat,
        text.c_str(),                           // Text to synthesize
        nullptr                                 // Async identifier
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("Failed to SynthesizeTextToSpeech: %s\n", GetErrorMessage(err));
    }
}

void
NetworkManager::SendTextMessage(
    PartyString chatText
    )
{
    // Only send the text message if we've got a local chat control to send it with
    if (m_localChatControl == nullptr)
    {
        DEBUGLOG("Info: Can't SendText. No local chat control.");
        return;
    }

    // Convert the message into a raw data.
    Party::PartyDataBuffer dataBuffers[] = { NetworkMessage::PartyStringAsDataBuffer(chatText) };

    // Get all of the chat controls from the Party Manager
    Party::PartyChatControlArray chatControls;
    uint32_t chatControlCount;
    PartyError err = Party::PartyManager::GetSingleton().GetChatControls(&chatControlCount, &chatControls);
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("GetChatControls Failed! %s", GetErrorMessage(err));
        return;
    }

    // Add all of the chat controls to a list except the local user's chat control.
    std::vector<PartyChatControl*> targetChatControls;
    for (uint32_t chatControlIndex = 0; chatControlIndex < chatControlCount; ++chatControlIndex)
    {
        PartyChatControl* chatControl = chatControls[chatControlIndex];
        if (chatControl != m_localChatControl)
        {
            targetChatControls.push_back(chatControl);
        }
    }

    // If the local user has a chat control, use it to send the data buffer to the retrieved chat controls.
    err = m_localChatControl->SendText(
        static_cast<uint32_t>(targetChatControls.size()),
        targetChatControls.data(),
        chatText,
        _countof(dataBuffers),
        dataBuffers
        );

    if (PARTY_SUCCEEDED(err))
    {
        DEBUGLOG("Info: Sending text message to %zu/%u chat controls", targetChatControls.size(), chatControlCount);
    }
    else
    {
        DEBUGLOG("Info: Failed to send text message! %s", GetErrorMessage(err));
    }
}

void
NetworkManager::LeaveNetwork(
    std::function<void(void)> callback
    )
{
    DEBUGLOG("NetworkManager::LeaveNetwork()\n");

    // Mute the microphone to save on processing.
    SetLocalPlayerMuted(true);
    m_isChatControlConnected = false;
    m_isTextToSpeechProfileSet = false;
    m_populateProfilesCompleted = false;
    m_ttsProfileNeedsUpdate = false;

    // Make sure we aren't already leaving or disconnected from a network.
    if (m_state != NetworkManagerState::Leaving && m_network != nullptr)
    {
        //Change our local state and save the callback for once the leave operation completes.
        m_state = NetworkManagerState::Leaving;
        m_onNetworkLeft = callback;

        // Disconnect local chat control before leave network.
        if (m_localChatControl != nullptr)
        {
            m_network->DisconnectChatControl(m_localChatControl, nullptr);
        }

        // Call leave on the Party APIs.
        m_network->LeaveNetwork(nullptr);
    }
    else
    {
        // We're already leaving or don't have a network. Call the callback.
        if (callback != nullptr)
        {
            callback();
        }
    }
}

void
NetworkManager::SetOnNetworkDestroyed(
        std::function<void(bool)> callback
)
{
    m_onNetworkDestroyed = callback;
}

bool
NetworkManager::IsConnecting() const
{
    return m_state == NetworkManagerState::WaitingForConnect ||
            m_state == NetworkManagerState::WaitingForNetwork;
}

void
NetworkManager::ConnectAudioInput()
{
    assert(m_localChatControl != nullptr);

    m_localChatControl->SetAudioInput(
            PartyAudioDeviceSelectionType::SystemDefault,
            nullptr,
            nullptr
            );
}

void
NetworkManager::DisconnectAudioInput()
{
    assert(m_localChatControl != nullptr);

    m_localChatControl->SetAudioInput(
            PartyAudioDeviceSelectionType::None,
            nullptr,
            nullptr
            );
}

// Convertss a State Change Result to a user friendly string message.
std::string
PartyStateChangeResultToReasonString(
    PartyStateChangeResult result
    )
{
    switch (result)
    {
    case PartyStateChangeResult::Succeeded: return "Succeeded";
    case PartyStateChangeResult::UnknownError: return "An unknown error occured";
    case PartyStateChangeResult::InternetConnectivityError: return "The local device has internet connectivity issues which caused the operation to fail";
    case PartyStateChangeResult::PartyServiceError: return "The Party service is unable to create a new network at this time";
    case PartyStateChangeResult::NoServersAvailable: return "There are no available servers in the regions specified by the call to PartyManager::CreateNewNetwork()";
    case PartyStateChangeResult::CanceledByTitle: return "Operation canceled by title.";
    case PartyStateChangeResult::UserCreateNetworkThrottled: return "The PartyLocalUser specified in the call to PartyManager::CreateNewNetwork() has created too many networks and cannot create new networks at this time";
    case PartyStateChangeResult::TitleNotEnabledForParty: return "The title has not been configured properly in the Party portal";
    case PartyStateChangeResult::NetworkLimitReached: return "The network is full and is not allowing new devices or users to join";
    case PartyStateChangeResult::NetworkNoLongerExists: return "The network no longer exists";
    case PartyStateChangeResult::NetworkNotJoinable: return "The network is not currently allowing new devices or users to join";
    case PartyStateChangeResult::VersionMismatch: return "The network uses a version of the Party library that is incompatible with this library";
    case PartyStateChangeResult::UserNotAuthorized: return "The specified user was not authorized";
    case PartyStateChangeResult::LeaveNetworkCalled: return "The network was gracefully exited by the local device";
    case PartyStateChangeResult::FailedToBindToLocalUdpSocket: return "The library could not bind to the local UDP socket specified in the PartyOption::LocalUdpSocketBindAddress option";
    }
    return "Unknown enumeration value";
}

// Convertss an Audio Input State to a user friendly string message.
std::string
PartyAudioInputStateToString(
    PartyAudioInputState state
    )
{
    switch (state)
    {
    case PartyAudioInputState::Initialized: return "Initialized";
    case PartyAudioInputState::NoInput: return "NoInput";
    case PartyAudioInputState::NotFound: return "NotFound";
    case PartyAudioInputState::UnknownError: return "UnknownError";
    case PartyAudioInputState::UnsupportedFormat: return "UnsupportedFormat";
    case PartyAudioInputState::UserConsentDenied: return "UserConsentDenied";
    default: break;
    }
    return "Unknown enumeration value";
}

// Convertss an Audio Output State to a user friendly string message.
std::string
PartyAudioOutputStateToString(
    PartyAudioOutputState state
    )
{
    switch (state)
    {
    case PartyAudioOutputState::Initialized: return "Initialized";
    case PartyAudioOutputState::NoOutput: return "NoOutput";
    case PartyAudioOutputState::NotFound: return "NotFound";
    case PartyAudioOutputState::UnknownError: return "UnknownError";
    case PartyAudioOutputState::UnsupportedFormat: return "UnsupportedFormat";
    default: break;
    }
    return "Unknown enumeration value";
}

// Convertss an Audio Device Selection Type to a user friendly string message.
std::string
PartyAudioDeviceSelectionTypeToString(
    PartyAudioDeviceSelectionType type
    )
{
    switch (type)
    {
    case PartyAudioDeviceSelectionType::SystemDefault: return "SystemDefault";
    case PartyAudioDeviceSelectionType::PlatformUserDefault: return "PlatformUserDefault";
    case PartyAudioDeviceSelectionType::Manual: return "Manual";
    case PartyAudioDeviceSelectionType::None: return "None";
    }
    return "Unknown enumeration value";
}

// Gets a string version of a PartyError from PartyManager
PartyString
NetworkManager::GetErrorMessage(
    PartyError error
    )
{
    PartyString errString = nullptr;

    PartyError err = PartyManager::GetErrorMessage(error, &errString);
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("Failed to get error message %u.\n", error);
        return "[ERROR]";
    }

    return errString;
}

// Main state change handler for the network.
void
NetworkManager::DoWork()
{
    std::unique_lock<std::mutex> lock(m_networkLock);
    if (m_state == NetworkManagerState::Initialize)
    {
        // Network isn't ready to receive state changes yet.
        return;
    }

    PartyStateChangeArray changes;
    uint32_t count;

    // Start processing messages from the Party layer
    PartyError err = PartyManager::GetSingleton().StartProcessingStateChanges(
        &count,
        &changes
    );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("StartProcessingStateChanges failed: %s\n", GetErrorMessage(err));
        return;
    }

    for (uint32_t i = 0; i < count; i++)
    {
        auto change = changes[i];

        switch (change->stateChangeType)
        {
        case PartyStateChangeType::RegionsChanged:
        {
            DEBUGLOG("Region changed \n");
            break;
        }
        case PartyStateChangeType::DestroyLocalUserCompleted:
        {
            DEBUGLOG("local user destroyed \n");
            break;
        }
        case PartyStateChangeType::CreateNewNetworkCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::CreateNewNetworkCompleted\n");
            auto result = static_cast<const PartyCreateNewNetworkCompletedStateChange*>(change);

            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("CreateNewNetworkCompleted:  SUCCESS\n");
                DEBUGLOG("Created new network with: \n");
                DEBUGLOG("    identifier: %s\n", result->networkDescriptor.networkIdentifier);
                DEBUGLOG("    region    : %s\n", result->networkDescriptor.regionName);

                m_state = NetworkManagerState::NetworkConnected;
                if (m_onNetworkCreated)
                {
                    char descriptor[c_maxSerializedNetworkDescriptorStringLength + 1] = {};

                    // Serialize our local network descriptor for other peers to use
                    err = PartyManager::SerializeNetworkDescriptor(
                        &result->networkDescriptor,
                        descriptor
                    );

                    if (PARTY_FAILED(err))
                    {
                        // Call the callback with an empty string to indicate an error.
                        DEBUGLOG("Failed to serialize network descriptor: %s\n", GetErrorMessage(err));
                        m_onNetworkCreated(std::string());
                    }
                    else
                    {
                        // Call the callback with network descriptor.
                        DEBUGLOG("Serialized value: %s\n", descriptor);
                        m_onNetworkCreated(std::string(descriptor));
                    }
                }
            }
            else
            {
                DEBUGLOG("CreateNewNetworkCompleted:  FAIL:  %d \n", result->result);
                DEBUGLOG("   Error Detail:  %d \n", result->errorDetail);
                DEBUGLOG("   Error Reason string: %s \n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("   Error Message string: %s\n", GetErrorMessage(result->errorDetail));

                // Send error callback for the network being created.
                if (m_onNetworkCreatedError)
                {
                    m_onNetworkCreatedError(result->errorDetail);
                }
            }
            break;
        }
        case PartyStateChangeType::ConnectToNetworkCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ConnectToNetworkCompleted\n");
            auto result = static_cast<const PartyConnectToNetworkCompletedStateChange*>(change);

            DEBUGLOG("connected to network with: \n");
            DEBUGLOG("    identifier: %s\n", result->networkDescriptor.networkIdentifier);
            DEBUGLOG("    region    : %s\n", result->networkDescriptor.regionName);


            if (result->result == PartyStateChangeResult::Succeeded)
            {
                // Send a success message to the UI
                Managers::Get<INetworkStateChangeManager>()->ProcessStatusMessage("System", "Connected to network.");

                DEBUGLOG("ConnectToNetworkCompleted:  SUCCESS\n");

                // Change our state to connected.
                m_state = NetworkManagerState::NetworkConnected;

                // If we muted the microphone, unmute it.
                SetLocalPlayerMuted(false);

                // Issue the callback for successfully connecting to a network.
                if (m_onNetworkConnected)
                {
                    m_onNetworkConnected();
                }
            }
            else
            {
                // Send a failure message to the UI
                Managers::Get<INetworkStateChangeManager>()->ProcessStatusMessage("System", "Unable to connect to network.");

                // Log out the error.
                DEBUGLOG("ConnectToNetworkCompleted:  FAIL:  %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("ErrorDetail: %s\n", GetErrorMessage(result->errorDetail));

                // Change our state back to Initialize
                m_state = NetworkManagerState::Initialize;

                // Send the callback for a network connection error.
                if (m_onNetworkConnectedError)
                {
                    m_onNetworkConnectedError(result->errorDetail);
                }
            }
            break;
        }
        case PartyStateChangeType::CreateEndpointCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::CreateEndpointCompleted\n");
            auto result = static_cast<const PartyCreateEndpointCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("CreateEndpointCompleted:  SUCCESS\n");
            }
            else
            {
                DEBUGLOG("CreateEndpointCompleted:  FAIL:  %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("ErrorDetail: %s\n", GetErrorMessage(result->errorDetail));

                // Send error callback for the network being created.
                if (m_onNetworkConnectedError)
                {
                    m_onNetworkConnectedError(result->errorDetail);
                }
            }
            break;
        }
        case PartyStateChangeType::EndpointCreated:
        {
            // Someone has successfully connected to the network with an endpoint.
            // If it's a new remote user, we'll send them our display name.
            DEBUGLOG("PartyStateChange: PartyStateChangeType::EndpointCreated\n");

            auto result = static_cast<const PartyEndpointCreatedStateChange*>(change);
            PartyEndpoint* newEndpoint = result->endpoint;

            if (newEndpoint != m_localEndpoint)
            {
                PartyString remoteEntityId;
                err = newEndpoint->GetEntityId(&remoteEntityId);
                if (PARTY_SUCCEEDED(err))
                {
                    DEBUGLOG("Established endpoint with remote entity %s\n", remoteEntityId);
                }
                else
                {
                    DEBUGLOG("Unable to retrieve EntityId from remote endpoint: %s\n", GetErrorMessage(err));
                    DEBUGLOG("Established endpoint with unknown entity\n");
                }

                // Send the current users display name to the other chat controls.
                const std::string& displayName = Managers::Get<PlayFabManager>()->displayName();
                PartyEndpoint* newRemoteEndpoint = result->endpoint;
                SendNetworkMessage(1, &newRemoteEndpoint, NetworkMessage { NetworkMessageType::UserDisplayName, displayName });
            }
            else
            {
                DEBUGLOG("Established local endpoint\n");
            }

            break;
        }
        case PartyStateChangeType::EndpointDestroyed:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::EndpointDestroyed\n");
            auto result = static_cast<const PartyEndpointDestroyedStateChange*>(change);

            DEBUGLOG("Endpoint is %s\n", result->endpoint == m_localEndpoint ? "local" : "remote");
            DEBUGLOG("Reason: %d\n", result->reason);
            DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));

            if (result->endpoint == m_localEndpoint)
            {
                // Our endpoint was disconnected
                m_localEndpoint = nullptr;
            }
            else
            {
                // Another user has disconnected
                PartyString user = nullptr;
                err = result->endpoint->GetEntityId(&user);

                if (PARTY_FAILED(err))
                {
                    DEBUGLOG("Unable to retrieve user id from endpoint: %s\n", GetErrorMessage(err));
                    break;
                }

                std::string userId(user);
            }
            break;
        }
        case PartyStateChangeType::EndpointMessageReceived:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::EndpointMessageReceived\n");
            auto result = static_cast<const PartyEndpointMessageReceivedStateChange*>(change);

            // Convert the data buffer into a network message
            auto messageBuffer = static_cast<const uint8_t*>(result->messageBuffer);
            NetworkMessage packet { std::vector<uint8_t>(messageBuffer, messageBuffer + result->messageSize) };

            if (packet.MessageType() == NetworkMessageType::UserDisplayName)
            {
                // A user has sent their display name to us. We can register them as having joined the network with this information.
                PartyString senderEntityId;
                err = result->senderEndpoint->GetEntityId(&senderEntityId);

                if (PARTY_SUCCEEDED(err))
                {
                    std::string displayName(packet.StringValue());
                    Managers::Get<INetworkStateChangeManager>()->ProcessPlayerJoined(senderEntityId, displayName);
                }
                else
                {
                    DEBUGLOG("GetEntityId failed: %s\n", GetErrorMessage(err));
                }
            }
            else
            {
                DEBUGLOG("Unexpected MessageType received over endpoint! MessageType=%i\n", packet.MessageType());
            }

            break;
        }
        case PartyStateChangeType::ChatTextReceived:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatTextReceived\n");
            auto result = static_cast<const PartyChatTextReceivedStateChange*>(change);

            PartyString sender = nullptr;
            err = result->senderChatControl->GetEntityId(&sender);

            if (PARTY_SUCCEEDED(err))
            {
                std::string senderId(sender);

                // If we have translations, find the translation for our language code.
                std::string message = findExpectedTranslation(result->translations, result->translationCount);

                // No translation was found, fallback to the raw chat text.
                if (message.empty())
                {
                    message = std::string(result->chatText);
                }

                // A text message has been received. Notify the relevant manager.
                Managers::Get<INetworkStateChangeManager>()->ProcessTextMessage(senderId, message);
            }
            else
            {
                DEBUGLOG("GetEntityId failed: %s\n", GetErrorMessage(err));
            }
            break;
        }
        case PartyStateChangeType::AuthenticateLocalUserCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::AuthenticateLocalUserCompleted\n");
            auto result = static_cast<const PartyAuthenticateLocalUserCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Succeeded\n");
            }
            else
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("ErrorDetail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::LocalUserRemoved:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::LocalUserRemoved\n");
            if (m_state != NetworkManagerState::Leaving)
            {
                DEBUGLOG("Unexpected local user removal!\n");
            }
            break;
        }
        case PartyStateChangeType::LeaveNetworkCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::LeaveNetworkCompleted\n");
            m_state = NetworkManagerState::Initialize;
            // If a callback exists for leaving the network, call it.
            if (m_onNetworkLeft)
            {
                m_onNetworkLeft();
            }
            break;
        }
        case PartyStateChangeType::NetworkDestroyed:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::NetworkDestroyed\n");
            // Clean up the network.
            m_network = nullptr;
            const bool destructionWasExpected = m_state == NetworkManagerState::Leaving;
            if (!destructionWasExpected)
            {
                DEBUGLOG("Unexpected network destruction!\n");
            }
            m_state = NetworkManagerState::Initialize;
            if (m_onNetworkDestroyed)
            {
                m_onNetworkDestroyed(destructionWasExpected);
            }
            break;
        }
        case PartyStateChangeType::NetworkConfigurationMadeAvailable:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::NetworkConfigurationMadeAvailable\n");
            break;
        }
        case PartyStateChangeType::RemoteDeviceCreated:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceCreated\n");
            break;
        }
        case PartyStateChangeType::RemoteDeviceJoinedNetwork:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceJoinedNetwork\n");
            break;
        }
        case PartyStateChangeType::RemoteDeviceDestroyed:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceDestroyed\n");
            break;
        }
        case PartyStateChangeType::RemoteDeviceLeftNetwork:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceLeftNetwork\n");
            break;
        }
        case PartyStateChangeType::ChatControlJoinedNetwork:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlJoinedNetwork\n");
            break;
        }
        case PartyStateChangeType::ChatControlLeftNetwork:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlLeftNetwork\n");
            break;
        }
        case PartyStateChangeType::ChatControlDestroyed:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlDestroyed\n");
            auto result = static_cast<const PartyChatControlDestroyedStateChange*>(change);
            PartyString sender = nullptr;
            err = result->chatControl->GetEntityId(&sender);

            if (PARTY_FAILED(err))
            {
                DEBUGLOG("GetEntityId failed: %s\n", GetErrorMessage(err));
            }
            else
            {
                DEBUGLOG("Destroyed ChatControl from %s\n", sender);
                Managers::Get<INetworkStateChangeManager>()->ProcessPlayerLeft(sender);
                m_chatControls.erase(sender);
            }
            break;
        }
        case PartyStateChangeType::ChatControlCreated:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlCreated\n");
            auto result = static_cast<const PartyChatControlCreatedStateChange*>(change);
            PartyString sender = nullptr;
            err = result->chatControl->GetEntityId(&sender);

            if (PARTY_FAILED(err))
            {
                DEBUGLOG("GetEntityId failed: %s\n", GetErrorMessage(err));
            }
            else
            {
                DEBUGLOG("Created ChatControl for %s\n", sender);
                m_chatControls[sender] = result->chatControl;

                PartyLocalChatControl* local = nullptr;
                err = result->chatControl->GetLocal(&local);

                if (PARTY_FAILED(err))
                {
                    DEBUGLOG("Failed to get LocalChatControl: %s\n", GetErrorMessage(err));
                }
                else if (local == nullptr)
                {
                    // Remote ChatControl added, set chat permissions
                    err = m_localChatControl->SetPermissions(
                        result->chatControl,
                        PartyChatPermissionOptions::ReceiveAudio |
                        PartyChatPermissionOptions::ReceiveText |
                        PartyChatPermissionOptions::SendAudio
                    );

                    if (PARTY_FAILED(err))
                    {
                        DEBUGLOG("Failed to SetPermissions on ChatControl: %s\n", GetErrorMessage(err));
                    }

                     err = m_localChatControl->SetAudioRenderVolume(result->chatControl, m_renderVolume);
                    if (PARTY_FAILED(err))
                    {
                        DEBUGLOG("Failed to SetAudioRenderVolume on incoming remote ChatControl: %s\n", GetErrorMessage(err));
                    }
                }
            }
            break;
        }
        case PartyStateChangeType::ConnectChatControlCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::ConnectChatControlCompleted\n");
            m_isChatControlConnected = true;
            auto result = static_cast<const PartyConnectChatControlCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Succeeded\n");
            }
            else
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("Error detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::CreateChatControlCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::CreateChatControlCompleted\n");
            auto result = static_cast<const PartyCreateChatControlCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Succeeded\n");
            }
            else
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("Error detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::LocalChatAudioInputChanged:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::LocalChatAudioInputChanged\n");
            auto result = static_cast<const PartyLocalChatAudioInputChangedStateChange*>(change);
            if (PARTY_FAILED(result->errorDetail))
            {
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::SetChatAudioInputCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::SetChatAudioInputCompleted\n");
            auto result = static_cast<const PartySetChatAudioInputCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Succeeded\n");
            }
            else
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
            }
            break;
        }
        case PartyStateChangeType::SetChatAudioOutputCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::SetChatAudioOutputCompleted\n");
            auto result = static_cast<const PartySetChatAudioOutputCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Succeeded\n");
            }
            else
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("ErrorDetail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::LocalChatAudioOutputChanged:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::LocalChatAudioOutputChanged\n");
            auto result = static_cast<const PartyLocalChatAudioOutputChangedStateChange*>(change);
            if (PARTY_FAILED(result->errorDetail))
            {
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::VoiceChatTranscriptionReceived:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::VoiceChatTranscriptionReceived\n");
            auto result = static_cast<const PartyVoiceChatTranscriptionReceivedStateChange*>(change);
            PartyString sender = nullptr;

            err = result->senderChatControl->GetEntityId(&sender);
            if (PARTY_FAILED(err))
            {
                DEBUGLOG("GetEntityId failed: %s\n", GetErrorMessage(err));
            }
            else
            {
                // Only add the transcription if it is a final phrase, and not a prediction phrase.
                if (result->type == PartyVoiceChatTranscriptionPhraseType::Final)
                {
                    std::string senderId(sender);

                    // If we have translations, find the translation for our language code.
                    std::string message = findExpectedTranslation(result->translations, result->translationCount);

                    // No translation was found, fallback to the raw transcription.
                    if (message.empty())
                    {
                        message = std::string(result->transcription);
                    }

                    if (!message.empty())
                    {
                        // A voice transcription has been received. Notify the relevant manager.
                        Managers::Get<INetworkStateChangeManager>()->ProcessVoiceMessage(senderId, message);
                    }
                }
            }

            break;
        }
        case PartyStateChangeType::SetTranscriptionOptionsCompleted:
        {
            DEBUGLOG("PartyStateChange: PartyStateChangeType::PartySetTranscriptionOptionsCompletedStateChange\n");
            auto result = static_cast<const PartySetTranscriptionOptionsCompletedStateChange*>(change);
            if (PARTY_FAILED(result->errorDetail))
            {
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::SynthesizeTextToSpeechCompleted:
        {
            DEBUGLOG("PartyStateChangeType::SynthesizeTextToSpeechCompleted\n");
            auto result = static_cast<const PartySynthesizeTextToSpeechCompletedStateChange*>(change);
            if (PARTY_FAILED(result->errorDetail))
            {
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            if (result->result != PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
            }
            break;
        }
        case PartyStateChangeType::SetTextToSpeechProfileCompleted:
        {
            DEBUGLOG("PartyStateChangeType::SetTextToSpeechProfileCompleted\n");
            auto result = static_cast<const PartySetTextToSpeechProfileCompletedStateChange*>(change);
            if (PARTY_FAILED(result->errorDetail))
            {
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            if (result->result != PartyStateChangeResult::Succeeded)
            {
                DEBUGLOG("Failed: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
            }
            else
            {
                DEBUGLOG("TTS Profile Set: %s \n", result->profileIdentifier);
                m_isTextToSpeechProfileSet = true;
            }
            break;
        }
        case PartyStateChangeType::SetLanguageCompleted:
        {
            DEBUGLOG("PartyStateChangeType::SetLanguageCompleted\n");
            auto result = static_cast<const PartySetLanguageCompletedStateChange*>(change);
            DEBUGLOG("setting language code: %s \n", result->languageCode);
            if (PARTY_FAILED(result->errorDetail))
            {
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        case PartyStateChangeType::InvitationCreated:
        {
            DEBUGLOG("PartyStateChangeType::InvitationCreated \n");
            break;
        }
        case PartyStateChangeType::PopulateAvailableTextToSpeechProfilesCompleted:
        {
            DEBUGLOG("PartyStateChangeType::PopulateAvailableTextToSpeechProfilesCompleted\n");
            auto result = static_cast<const PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange*>(change);
            if (result->result == PartyStateChangeResult::Succeeded)
            {
                m_populateProfilesCompleted = true;
                m_ttsProfileNeedsUpdate = true;
            }
            else
            {
                DEBUGLOG("State Change Result: %s\n", PartyStateChangeResultToReasonString(result->result).c_str());
                DEBUGLOG("Error Detail: %s\n", GetErrorMessage(result->errorDetail));
            }
            break;
        }
        default:
            DEBUGLOG("unknown state change \n");
            DEBUGLOG("PartyStateChange: %d\n", change->stateChangeType);
            break;
        }
    }

    // Return the processed changes back to Party
    err = PartyManager::GetSingleton().FinishProcessingStateChanges(count, changes);

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("FinishProcessingStateChanges failed: %s\n", GetErrorMessage(err));
    }

    if (m_populateProfilesCompleted)
    {
        if (m_ttsProfileNeedsUpdate.exchange(false))
        {
            setTextToSpeechProfile();
        }
    }

    ProcessChatIndicatorUpdates();
}

// Searches the list of locally stored chat controls for the specified peer id
// as key and returns the associated chat control, if any.
PartyChatControl*
NetworkManager::GetChatControl(
    const std::string& peer
    )
{
    auto itr = m_chatControls.find(peer);
    if (itr != m_chatControls.end())
    {
        return itr->second;
    }
    return nullptr;
}

// Mutes or unmutes the local chat control if it exists.
void
NetworkManager::SetLocalPlayerMuted(
    bool isMuted
    )
{
    if (m_localChatControl != nullptr)
    {
        m_localChatControl->SetAudioInputMuted(isMuted);
    }
}

// Mute or unmute a remote player
void
NetworkManager::SetRemotePlayerMuted(
    const std::string& remotePlayerEntityId,
    bool isMuted
    )
{
    if (m_localChatControl == nullptr)
    {
        return;
    }

    PartyChatControl* remotePlayerChatControl = GetChatControl(remotePlayerEntityId);
    if (remotePlayerChatControl == nullptr)
    {
        DEBUGLOG("Chat control not found for remote player %s", remotePlayerEntityId.c_str());
        return;
    }

    PartyError err = m_localChatControl->SetIncomingAudioMuted(remotePlayerChatControl, isMuted);
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("Failed to %s remote player %s", isMuted ? "mute" : "unmute", remotePlayerEntityId.c_str());
        return;
    }
}

// Returns if the chat control has passed the connected state change.
bool
NetworkManager::getIsChatControlConnected()
{
    return m_isChatControlConnected;
}

// Returns if the chat control has set a text to speech profile.
// Used on some platforms to disable the TTS buttons when they shouldn't
// be available.
bool
NetworkManager::getIsTextToSpeechProfileSet()
{
    return m_isTextToSpeechProfileSet;
}

// Used to set the text to speech profile after available
// profiles have been populated in the Chat Control.
void
NetworkManager::setTextToSpeechProfile()
{
    // Get the list of availale profiles.
    uint32_t profileCount;
    PartyTextToSpeechProfileArray profiles;
    PartyError err = m_localChatControl->GetAvailableTextToSpeechProfiles(&profileCount, &profiles);
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("GetAvailableTextToSpeechProfiles failed: %s\n", GetErrorMessage(err));
    }
    else
    {
        // Get the first text to speech profile that matches the language code.
        PartyTextToSpeechProfile* textToSpeechProfile = nullptr;
        for (uint32_t i = 0; i < profileCount; ++i)
        {
            // Get the language code for the current profile.
            PartyString languageCode;
            profiles[i]->GetLanguageCode(&languageCode);
            if (PARTY_FAILED(err))
            {
                DEBUGLOG("TextToSpeechProfile GetLanguageCode failed: %s\n", GetErrorMessage(err));
                continue;
            }

            // Compare the current profile language to the currently set language code.
            if (strcmp(languageCode, m_languageCode) == 0)
            {
                // Use this profile.
                textToSpeechProfile = profiles[i];
                break;
            }
        }

        // If we found a profile that matches our language code, set that profile.
        if (textToSpeechProfile != nullptr)
        {
            // Get the identifier for the profile.
            PartyString identifier;
            err = textToSpeechProfile->GetIdentifier(&identifier);
            if (PARTY_FAILED(err))
            {
                DEBUGLOG("TextToSpeechProfile GetIdentifier failed: %s\n", GetErrorMessage(err));
            }
            else
            {
                DEBUGLOG("Setting TTS Profile: %s\n", identifier);

                //Set text to speech profile to enable text to speech messages.
                err = m_localChatControl->SetTextToSpeechProfile(
                    PartySynthesizeTextToSpeechType::VoiceChat,     // Text to Speech Type
                    identifier,                                     // Language profile
                    nullptr                                         // Async identifier
                );

                if (PARTY_FAILED(err))
                {
                    DEBUGLOG("SetTextToSpeechProfile failed: %s\n", GetErrorMessage(err));
                }
            }
        }
        else
        {
            DEBUGLOG("Failed to find a TextToSpeech Profile. Current Language:%s Profile Count:%d\n", m_languageCode, profileCount);
        }
    }
}

// This function compares the language code of the given translation
// against the local language code, returning true if they match.
// This is used as the predicate to find_if in
// NetworkManager::findExpectedTranslation.
bool
NetworkManager::isTranslationInTheLocalLanguage(
    PartyTranslation translation
    )
{
    return strcmp(translation.languageCode, m_languageCode) == 0;
}

// Helper function used in chat and voice message received state changes.
// Given a list of translations, finds the one that has a langauge code
// that matches the currently set language code and returns the translated
// string. If none is found, returns an empty string.
std::string
NetworkManager::findExpectedTranslation(
    PartyTranslation* translations,
    int translationCount
    )
{
    std::string expectedTranslation;

    // Get the beginning and ending of the translation array
    PartyTranslation* arrayBeginning = translations;
    PartyTranslation* arrayEnding = translations + translationCount;

    // Use find_if to get the translation that matches our language code.
    PartyTranslation* translationIterator = std::find_if(
        arrayBeginning,
        arrayEnding,
        std::bind(&NetworkManager::isTranslationInTheLocalLanguage, this, std::placeholders::_1)
    );

    // If we found a valid translation, place the string into expectedTranslation to be returned.
    if (translationIterator != arrayEnding)
    {
        expectedTranslation = std::string(translationIterator->translation);
    }

    return expectedTranslation;
}

void NetworkManager::ProcessChatIndicatorUpdates()
{
    // PlayFab Party is responsive enough that a UI which can handle frequent updates can poll for the chat indicators
    // every frame. Since this code is shared across a number of UI frameworks, we'll cache the chat indicators and only
    // alert the UI when they've changed.

    if (m_localChatControl == nullptr)
    {
        return;
    }

    Party::PartyChatControlArray chatControls;
    uint32_t chatControlCount;
    PartyError err = Party::PartyManager::GetSingleton().GetChatControls(&chatControlCount, &chatControls);
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("GetChatControls Failed! %s", GetErrorMessage(err));
        return;
    }

    // Check for remote chat control indicator updates
    for (uint32_t i = 0; i < chatControlCount; ++i)
    {
        PartyChatControl* chatControl = chatControls[i];
        if (chatControl == m_localChatControl)
        {
            continue;
        }

        PartyChatControlChatIndicator chatIndicator;
        err = m_localChatControl->GetChatIndicator(chatControl, &chatIndicator);
        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Failed to query for remote chat control's chat indicator! %s", GetErrorMessage(err));
            continue;
        }

        PartyString remotePlayerEntityId;
        err = chatControl->GetEntityId(&remotePlayerEntityId);
        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Failed to query for remote chat control's entity ID! %s", GetErrorMessage(err));
            continue;
        }

        if (m_remoteChatControlIndicatorCache[chatControl] != chatIndicator)
        {
            Managers::Get<INetworkStateChangeManager>()->ProcessRemoteChatIndicatorChange(remotePlayerEntityId, chatIndicator);
            m_remoteChatControlIndicatorCache[chatControl] = chatIndicator;
        }
    }

    // Check for remote chat control indicator updates
    PartyLocalChatControlChatIndicator localChatIndicator;
    err = m_localChatControl->GetLocalChatIndicator(&localChatIndicator);
    if (PARTY_SUCCEEDED(err))
    {
        PartyString localPlayerEntityId;
        err = m_localChatControl->GetEntityId(&localPlayerEntityId);
        if (PARTY_SUCCEEDED(err))
        {
            if (m_localChatControlIndicatorCache[m_localChatControl] != localChatIndicator)
            {
                Managers::Get<INetworkStateChangeManager>()->ProcessLocalChatIndicatorChange(localPlayerEntityId, localChatIndicator);
                m_localChatControlIndicatorCache[m_localChatControl] = localChatIndicator;
            }
        }
        else
        {
            DEBUGLOG("Failed to query for local chat control's entity ID! %s", GetErrorMessage(err));
        }
    }
    else
    {
        DEBUGLOG("Failed to query for local chat control's chat indicator! %s", GetErrorMessage(err));
    }
}
