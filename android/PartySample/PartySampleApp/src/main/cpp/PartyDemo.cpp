#include <memory>
#include "PartyDemo.h"

using namespace Party;
using namespace PartySample;

std::string g_playfabTitleId ="";

std::string g_customId;
std::string g_networkName;
std::string g_networkDescriptor;

std::mutex g_mtx;
std::condition_variable g_cv;
bool g_isSpinDone = false;
bool g_isRunning = false;
bool g_shouldShutdown = false;
bool g_reconnecting = false;
bool g_connected = false;
constexpr uint32_t c_maxReconnectAttempts = 10;
uint32_t g_reconnectsRemaining = 0;
bool g_initializeCompleted = false;

JavaVM* g_jvm;
jobject g_javaNetworkManager ;

PartyString
GetErrorMessage(
    PartyError error
    )
{
    PartyString errString = nullptr;
    PartyManager::GetErrorMessage(error, &errString);

    return errString;
}

bool
GetJavaEnv(
    JNIEnv** env,
    bool& needDetach
    )
{
    RETURN_IF(g_jvm == nullptr, false);
    needDetach = false;
    RETURN_IF(g_jvm->GetEnv((void**)env, JNI_VERSION_1_4) == JNI_OK, true);
    needDetach = true;
    RETURN_IF(g_jvm->AttachCurrentThread(env, nullptr) == JNI_OK, true);
    needDetach = false;
    DbgLog(TAG, "GetJavaEnv", "Failed to AttachCurrentThread");
    return false;
}

void
RunJavaMethod(
    std::string methodName,
    std::string signature,
    std::function<void(JNIEnv*, jmethodID)> callback
    )
{
    JNIEnv* env;
    bool needDetach = false;
    RETURN_VOID_IF_FALSE(GetJavaEnv(&env, needDetach));

    jclass ntClass = env->GetObjectClass(g_javaNetworkManager);
    jmethodID jmethodId = env->GetMethodID(ntClass, methodName.c_str(), signature.c_str());
    if (jmethodId != 0)
    {
        callback(env, jmethodId);
    }

    if(needDetach == true)
    {
        g_jvm->DetachCurrentThread();
    }
}

void
ResetChat(
    PartyString error
    )
{
    RunJavaMethod(
        "resetChat",
        "(Ljava/lang/String;)V",
        [error](
            JNIEnv* env,
            jmethodID jmethodId
            )
        {
            DbgLog(TAG, "call resetChat method");
            env->CallVoidMethod(g_javaNetworkManager, jmethodId, env->NewStringUTF(error));
        });
}

void
ResetMessage()
{
    RunJavaMethod(
        "resetMessage",
        "()V",
        [](
            JNIEnv* env,
            jmethodID jmethodId
            )
        {
            DbgLog(TAG, "call resetMessage method");
            env->CallVoidMethod(g_javaNetworkManager, jmethodId);
        });
}

void
SendSysLogToUI(
    const char* format,
    ...
    )
{
    va_list arglist;
    va_start(arglist, format);
    std::shared_ptr<char> messageString(new char[2048]);
    vsnprintf(messageString.get(), 2048, format, arglist);
    va_end(arglist);

    DbgLog(TAG, format, messageString.get());

    RunJavaMethod(
        "addErrorMessage",
        "(Ljava/lang/String;)V",
        [&messageString](
            JNIEnv* env,
            jmethodID jmethodId
            )
        {
            DbgLog(TAG, "call addErrorMessage method");

            env->CallVoidMethod(
                g_javaNetworkManager,
                jmethodId,
                env->NewStringUTF(messageString.get()));
        }
    );
}

void
OnNetworkConnected(
    std::string network
    )
{
    g_connected = true;
    RunJavaMethod(
        "onNetworkCreated",
        "(Ljava/lang/String;)V",
        [network](
            JNIEnv* env,
            jmethodID jmethodId
            )
        {
            DbgLog(TAG, "call onNetworkCreated method");
            env->CallVoidMethod(g_javaNetworkManager, jmethodId, env->NewStringUTF(network.c_str()));
        });
}

void
OnEndpointMessageReceived(
    std::string sender,
    std::string message
    )
{
    RunJavaMethod(
        "onMessageReceived",
        "(Ljava/lang/String;Ljava/lang/String;)V",
        [sender, message](
            JNIEnv* env,
            jmethodID jmethodId
            )
        {
            DbgLog(TAG, "call onMessageReceived method");
            env->CallVoidMethod(
                g_javaNetworkManager,
                jmethodId,
                env->NewStringUTF(sender.c_str()),
                env->NewStringUTF(message.c_str()));
        });
}

void
OnVoiceChatTranscriptionReceived(
    std::string sender,
    std::string message
    )
{
    RunJavaMethod(
        "onTranscriptMessageReceived",
        "(Ljava/lang/String;Ljava/lang/String;)V",
        [sender, message](
            JNIEnv* env,
            jmethodID jmethodId
            )
        {
            DbgLog(TAG, "call onTranscriptMessageReceived method");
            env->CallVoidMethod(
                g_javaNetworkManager,
                jmethodId,
                env->NewStringUTF(sender.c_str()),
                env->NewStringUTF(message.c_str()));
        });
}

void
OnChatControlCreated(
    std::string sender
    )
{
    RunJavaMethod(
        "onPlayerJoined",
        "(Ljava/lang/String;Ljava/lang/String;)V",
        [sender](
            JNIEnv* env,
            jmethodID jmethodId
        )
        {
            DbgLog(TAG, "call onPlayerJoined method");
            env->CallVoidMethod(
                g_javaNetworkManager,
                jmethodId,
                env->NewStringUTF(sender.c_str()),
                env->NewStringUTF(sender.c_str()));
        });
}

void
OnChatControlDestroyed(
    std::string sender
    )
{
    RunJavaMethod(
            "onPlayerLeft",
            "(Ljava/lang/String;)V",
            [sender](
                JNIEnv* env,
                jmethodID jmethodId
                )
            {
                DbgLog(TAG, "call onPlayerLeft method");
                env->CallVoidMethod(g_javaNetworkManager, jmethodId, env->NewStringUTF(sender.c_str()));
            });

}

void
OnPlayerStateChange(
    std::string player,
    std::string state
    )
{
    RunJavaMethod(
        "updatePlayerState",
        "(Ljava/lang/String;Ljava/lang/String;)V",
        [player, state](
            JNIEnv* env,
            jmethodID jmethodId)
        {
            env->CallVoidMethod(
                g_javaNetworkManager,
                jmethodId,
                env->NewStringUTF(player.c_str()),
                env->NewStringUTF(state.c_str()));
        });
}

template <typename TSignInCallback>
void
SignInToPlayFab(TSignInCallback onComplete)
{
    Managers::Get<PlayFabManager>()->Initialize(g_playfabTitleId.c_str());
    Managers::Get<PlayFabManager>()->SignIn(
        [onComplete](
            bool isSuccess,
            std::string message
            )
        {

            if (isSuccess)
            {
                SendSysLogToUI("PlayFab SignIn: OK");
                std::map<const std::string, const std::string>* map = Managers::Get<NetworkStateChangeManager>()->GetUserMap();
                map->emplace(Managers::Get<PlayFabManager>()->EntityId(), Managers::Get<PlayFabManager>()->displayName());
                g_initializeCompleted = true;
                onComplete(true);
            }
            else
            {
                SendSysLogToUI("SignIn Failed! error=\"%s\"", message.c_str());
                onComplete(false);
            }
        },
        g_customId);
}

void
InitializePlayFabParty()
{
    Managers::Get<NetworkManager>()->Initialize(g_playfabTitleId.c_str());
}

void
HoldSpin()
{
    std::unique_lock <std::mutex> lck(g_mtx);
    g_cv.wait(lck,[]{ return g_isSpinDone; });
}

void
ReleaseSpin()
{
    {
        std::unique_lock<std::mutex> lck(g_mtx);
        g_isSpinDone = true;
    }
    g_cv.notify_one();
}

void
GetPlayerState()
{
    std::shared_ptr<NetworkManager> manager = Managers::Get<NetworkManager>();

    PartyLocalChatControl* localChatControl = manager->GetLocalChatControl();
    RETURN_VOID_IF(localChatControl == nullptr);

    for (auto& item : *(Managers::Get<NetworkStateChangeManager>()->GetUserMap()))
    {
        std::string userIdentifier = item.first;

        PartyChatControl* chatControl = manager->GetChatControl(userIdentifier);
        if (chatControl != nullptr)
        {
            std::string userName = item.second;

            if (g_customId == userName)
            {
                Party::PartyLocalChatControlChatIndicator indicator;
                localChatControl->GetLocalChatIndicator(&indicator);
                switch (indicator)
                {
                    case Party::PartyLocalChatControlChatIndicator::AudioInputMuted:
                    case Party::PartyLocalChatControlChatIndicator::NoAudioInput:
                    case Party::PartyLocalChatControlChatIndicator::Silent:
                        DbgLog(
                            TAG,
                            "GetLocalChatIndicator: %s AudioInputMuted|NoAudioInput|Silent",
                            userName.c_str());
                        OnPlayerStateChange(userName, "silent");
                        break;
                    case Party::PartyLocalChatControlChatIndicator::Talking:
                        DbgLog(TAG, "GetLocalChatIndicator: %s Talking", userName.c_str());
                        OnPlayerStateChange(userName, "talking");
                        break;
                }
            }
            else
            {
                Party::PartyChatControlChatIndicator indicator;
                localChatControl->GetChatIndicator(chatControl, &indicator);
                switch (indicator)
                {
                    case Party::PartyChatControlChatIndicator::IncomingCommunicationsMuted:
                    case Party::PartyChatControlChatIndicator::IncomingVoiceDisabled:
                    case Party::PartyChatControlChatIndicator::Silent:
                    case Party::PartyChatControlChatIndicator::NoRemoteInput:
                    case Party::PartyChatControlChatIndicator::RemoteAudioInputMuted:
                        DbgLog(
                            TAG,
                            "PartyChatControlChatIndicator: %s IncomingCommunicationsMuted|IncomingVoiceDisabled|Silent|NoRemoteInput|RemoteAudioInputMuted",
                            userName.c_str());
                        OnPlayerStateChange(userName, "silent");
                        break;
                    case Party::PartyChatControlChatIndicator::Talking:
                        DbgLog(TAG, "PartyChatControlChatIndicator: %s Talking", userName.c_str());
                        OnPlayerStateChange(userName, "talking");
                        break;
                }
            }
        }
    }
}

void
SetLanguage(
    int languageIdx
    )
{
    Managers::Get<NetworkManager>()->SetLanguageCode(
            LanguageOptions::s_languageCodes[languageIdx],
            LanguageOptions::s_languageNames[languageIdx]
            );
}

void
DoLeave(
    std::string message
    )
{
    g_isSpinDone = false;
    Managers::Get<NetworkManager>()->LeaveNetwork(
            [message]()
            {
                ResetMessage();
                SendSysLogToUI(message.c_str());
                g_shouldShutdown = true;
            });
}

void
OnDisconnect(
        bool disconnectWasExpected
        )
{
    g_connected = false;
    if(!disconnectWasExpected)
    {
        if(!g_reconnecting && g_reconnectsRemaining == 0)
        {
            g_reconnecting = true;
            g_reconnectsRemaining = c_maxReconnectAttempts;
        }
    }
    else
    {
        g_shouldShutdown = true;
    }

}

extern "C"
{

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_demo_PartySampleFocusService_disconnectAudioInput(
        JNIEnv *env,
        jobject thiz
        )
    {
        SendSysLogToUI("Lost Focus! Disconnecting Audio Input/Output Devices");
        Managers::Get<NetworkManager>()->DisconnectAudioInput();
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_demo_PartySampleFocusService_connectAudioInput(
        JNIEnv *env,
        jobject thiz
        )
    {
        SendSysLogToUI("Gained Focus! Restoring Audio Input/Output Devices (if any)");
        Managers::Get<NetworkManager>()->ConnectAudioInput();
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_setLanguage(
            JNIEnv* env,
            jobject thiz,
            jint idx
    )
    {
        SetLanguage(idx);
    }

    JNIEXPORT jboolean JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_initialize(
        JNIEnv* env,
        jobject thiz,
        jstring playerId
        )
    {
        if (g_jvm == nullptr) {
            env->GetJavaVM(&g_jvm);
        }

        g_javaNetworkManager = env->NewGlobalRef(thiz);

        const char* customIdCStr = env->GetStringUTFChars(playerId, NULL);
        g_customId = reinterpret_cast<PartyString>(customIdCStr);
        env->ReleaseStringUTFChars(playerId, customIdCStr);

        DbgLog(TAG, "Initialize with player: %s", g_customId.c_str());

        g_isRunning = true;
        Managers::Initialize<NetworkStateChangeManager>();
        Managers::Get<NetworkManager>()->SetOnNetworkDestroyed(OnDisconnect);
        SignInToPlayFab([](bool success)
        {
            if (success)
            {
                InitializePlayFabParty();
            }
            else
            {
                SendSysLogToUI("Failed PlayFab Sign-In!");
            }
        });

        return true;
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_setPlayerVolume(
        JNIEnv* env,
        jobject thiz,
        jfloat volumeZeroToOne
        )
    {
        Managers::Get<NetworkManager>()->SetPlayerVolume(volumeZeroToOne);
    }

    JNIEXPORT jboolean JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_createAndConnectToNetwork(
        JNIEnv* env,
        jobject thiz,
        jstring type,
        jstring languageCode
        )
    {
        if (g_isRunning && g_initializeCompleted)
        {

            const char* networkNameCStr = env->GetStringUTFChars(type, NULL);
            g_networkName = networkNameCStr;
            env->ReleaseStringUTFChars(type, networkNameCStr);
            g_isSpinDone = false;
            DbgLog(TAG, "CreateAndConnectToNetwork()");
            Managers::Get<NetworkManager>()->CreateAndConnectToNetwork(
                    g_networkName.c_str(),
                    [](std::string message)
                    {
                        SendSysLogToUI("create network: %s", message.c_str());
                        Managers::Get<PlayFabManager>()->SetDescriptor(g_networkName, message.c_str(),
                                                                       []()
                        {
                            SendSysLogToUI("set network descriptor succeeded");
                            ReleaseSpin();
                        });

                        OnNetworkConnected(g_networkName);
                    },
                    [](PartyError error)
                    {
                        SendSysLogToUI("create network failed: %s",  GetErrorMessage(error));
                        ReleaseSpin();
                        ResetChat(GetErrorMessage(error));
                    }
            );

            HoldSpin();
            return true;
        }
        else
        {
            SendSysLogToUI("Please wait for initialization to finish.");
            return false;
        }
    }

    JNIEXPORT jboolean JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_connectedToNetwork(
        JNIEnv* env,
        jobject thiz
        )
    {
        return g_connected;
    }

    bool joinNetwork(bool rejoining)
    {
        if (g_isRunning && g_initializeCompleted)
        {
            if (!rejoining)
            {
                Managers::Get<NetworkManager>()->Initialize(g_playfabTitleId.c_str());
                g_isSpinDone = false;
                Managers::Get<PlayFabManager>()->GetDescriptor(
                        g_networkName,
                        [rejoining](std::string networkDescriptor)
                        {
                            if (!rejoining)
                            {
                                SendSysLogToUI("OnGetDescriptorForConnectTo : %s",
                                               networkDescriptor.c_str());
                            }
                            g_networkDescriptor = networkDescriptor;
                            ReleaseSpin();
                        }
                );

                HoldSpin();
            }
            // When network connection is not stable, waiting for ConnectToNetwork callback will cost longer time.
            // To avoid App UI busy waiting, return to UI after ConnectToNetwork returns.
            Managers::Get<NetworkManager>()->ConnectToNetwork(
                    g_networkName.c_str(),
                    g_networkDescriptor.c_str(),
                    [rejoining]()
                    {
                        g_reconnectsRemaining = 0;
                        g_reconnecting = false;

                        if (rejoining)
                        {
                            SendSysLogToUI("Connection re-established.");
                        }
                        else
                        {
                            SendSysLogToUI("ConnectToNetwork succeeded.");
                        }

                        OnNetworkConnected(g_networkName);
                    },
                    [rejoining](PartyError error)
                    {
                        if (!rejoining || g_reconnectsRemaining == 0)
                        {
                            ResetChat(GetErrorMessage(error));
                            SendSysLogToUI("OnConnectToNetworkFailed %s", GetErrorMessage(error));
                        }
                        else
                        {
                            SendSysLogToUI("OnConnectToNetworkFailed %s", GetErrorMessage(error));
                            SendSysLogToUI("Rejoining failed. Trying again (%i)...", g_reconnectsRemaining);
                        }
                    });

            return true;
        }
        else
        {
            SendSysLogToUI("Please wait for initialization to finish.");
            return false;
        }
    }

    JNIEXPORT jboolean JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_joinNetwork(
        JNIEnv* env,
        jobject thiz,
        jstring networkId
        )
    {
        if (g_isRunning && g_initializeCompleted) {
            const char *networkNameCStr = env->GetStringUTFChars(networkId, NULL);
            g_networkName = networkNameCStr;
            env->ReleaseStringUTFChars(networkId, networkNameCStr);
            return joinNetwork(false);
        }
        else {
            SendSysLogToUI("Please wait for initialization to finish.");
            return false;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_leaveNetwork(
        JNIEnv* env,
        jobject thiz
        )
    {
        DoLeave("Leave network done.");
        HoldSpin();
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_doWork(
        JNIEnv* env,
        jobject thiz
        )
    {
        if (g_isRunning)
        {
            Managers::Get<PlayFabManager>()->Tick();
            Managers::Get<NetworkManager>()->DoWork();
            GetPlayerState();
        }

        if (g_shouldShutdown)
        {
            g_shouldShutdown = false;
            Managers::Get<NetworkManager>()->Shutdown();
            Managers::Get<NetworkManager>()->Initialize(g_playfabTitleId.c_str());
            ReleaseSpin();
        }
        else if(Managers::Get<NetworkManager>()->IsConnecting() == false)
        {
            if (g_reconnectsRemaining > 0)
            {
                SendSysLogToUI("Trying to reconnect with %i attempts remaining...", g_reconnectsRemaining);
                --g_reconnectsRemaining;
                joinNetwork(true);
            }
            else if (g_reconnecting)
            {
                SendSysLogToUI("Failed attempting to reconnect after %i attempts!", c_maxReconnectAttempts);
                g_reconnecting = false;
                g_shouldShutdown = true;
            }
        }
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_sendTextMessage(
        JNIEnv* env,
        jobject thiz,
        jstring message,
        jboolean isTTS
        )
    {
        const char* chatTextCStr = env->GetStringUTFChars(message, NULL);

        Party::PartyChatControlArray chatControls;
        uint32_t chatControlCount;

        Managers::Get<NetworkManager>()->SendTextAsVoice(chatTextCStr);

        env->ReleaseStringUTFChars(message, chatTextCStr);
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_getPlayerState(
        JNIEnv* env,
        jobject thiz
        )
    {
        if (g_isRunning)
        {
            GetPlayerState();
        }
    }

    JNIEXPORT void JNICALL
    Java_com_microsoft_playfab_partysample_sdk_NetworkManager_setPlayFabTitleID (
        JNIEnv* env,
        jobject thiz,
        jstring titleID
        )
    {
        const char* titleCStr = env->GetStringUTFChars(titleID, NULL);
        g_playfabTitleId = titleCStr;
        env->ReleaseStringUTFChars(titleID, titleCStr);
    }
}
