// App.h: Provides an interop layer so that the main C# app can interact with the underlying C++ sample

extern "C"
{
    typedef void (__stdcall * LogCallback)(const char* system, const char* message);
    typedef void (__stdcall * OnPlayerJoinedCallback)(const char* entityId, const char* displayName);
    typedef void (__stdcall * OnPlayerChatIndicatorUpdatedCallback)(const char* entityId, bool isLocalChatIndicator, int32_t chatIndicator);
    typedef void (__stdcall * OnPlayerTextMessageReceivedCallback)(const char* entityId, const char* textMessage);
    typedef void (__stdcall * OnPlayerVoiceTranscriptionReceivedCallback)(const char* entityId, const char* voiceTranscription);
    typedef void (__stdcall * OnPlayerLeftCallback)(const char* entityId);

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
        );

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_PollLogQueue(
        LogCallback callback
        );

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_CreateAndJoinPartyNetwork(
        const char* partyNetworkRoomId
        );

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_JoinPartyNetwork(
        const char* partyNetworkRoomId
        );

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_LeavePartyNetwork();

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_SendChatText(
        const char* chatText
        );

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_SynthesizeTextToSpeech(
        const char* textToSynthesize
        );

    __declspec(dllexport)
    void
    __stdcall
    PartySampleApp_SetPlayerMute(
        const char* playerEntityId,
        bool isMuted
        );
}
