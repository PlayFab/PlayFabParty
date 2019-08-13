#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

// BEGIN GENERATED SECTION: DO NOT EDIT

typedef enum PARTY_NETWORK_CREATION_TEST_FAILURE
{
    PARTY_NETWORK_CREATION_TEST_FAILURE_NONE,
    PARTY_NETWORK_CREATION_TEST_FAILURE_TITLE_NOT_ENABLED_FOR_PARTY,
    PARTY_NETWORK_CREATION_TEST_FAILURE_AUTHORIZATION_FAILED,
    PARTY_NETWORK_CREATION_TEST_FAILURE_REQUEST_SERVER_TIMEOUT,
    PARTY_NETWORK_CREATION_TEST_FAILURE_NO_SERVERS_AVAILABLE,
    PARTY_NETWORK_CREATION_TEST_FAILURE_SERVICE_ERROR,
    PARTY_NETWORK_CREATION_TEST_FAILURE_USER_THROTTLED,
} PARTY_NETWORK_CREATION_TEST_FAILURE;

typedef struct PARTY_JITTER_BUFFER_STATS_FOR_TEST
{
    uint32_t receivedAudioInMillisecondsSinceCreation;
    uint32_t receivedButDroppedPacketCountSinceCreation;
} PARTY_JITTER_BUFFER_STATS_FOR_TEST;

typedef struct PARTY_AUDIO_RENDER_STATS_FOR_TEST
{
    uint32_t renderCountSinceCreation;
} PARTY_AUDIO_RENDER_STATS_FOR_TEST;

// END GENERATED SECTION

PartyError
PARTY_API
PartyTestStartDestroyingNetwork(
    PARTY_NETWORK_HANDLE network,
    PartyError destroyError
    );

PartyError
PARTY_API
PartyTestInjectCreateNewNetworkFailure(
    PARTY_HANDLE partyManager,
    PARTY_NETWORK_CREATION_TEST_FAILURE createNewNetworkFailure
    );

PartyError
PARTY_API
PartyTestGetJitterBufferStatsForTest(
    PARTY_CHAT_CONTROL_HANDLE remoteChatControl,
    _Out_ PARTY_JITTER_BUFFER_STATS_FOR_TEST* stats
    );

PartyError
PARTY_API
PartyTestGetAudioRenderStatsForTest(
    PARTY_CHAT_CONTROL_HANDLE localChatControl,
    _Out_ PARTY_AUDIO_RENDER_STATS_FOR_TEST* stats
    );

PartyError
PARTY_API
PartyTestGetLocalUserToken(
    PARTY_LOCAL_USER_HANDLE localUser,
    _Outptr_ PartyString* token
    );

PartyError
PARTY_API
PartyTestRefreshLocalUserToken(
    PARTY_LOCAL_USER_HANDLE localUser
    );

#ifdef __cplusplus
}
#endif
