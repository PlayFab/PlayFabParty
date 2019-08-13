#pragma once

#ifndef __cplusplus
#error "This header requires C++"
#endif // end if not defined __cplusplus

namespace Party {

#define PARTY_SAL_SUPPORT
#ifdef PARTY_SAL_SUPPORT
#pragma prefast(push)
#pragma prefast(disable:__WARNING_DANGEROUS_POINTERCAST, "All of the C++ structures are related to the corresponding C structures")
#endif // PARTY_SAL_SUPPORT

//
// PartyTestManager class implementation
//

PartyError PartyTestManager::StartDestroyingNetwork(
    PartyNetwork * network,
    PartyError destroyError
    ) party_no_throw
{
    return PartyTestStartDestroyingNetwork(reinterpret_cast<PARTY_NETWORK_HANDLE>(network), destroyError);
}

PartyError PartyTestManager::InjectCreateNewNetworkFailure(
    PartyManager * partyManager,
    PartyNetworkCreationTestFailure createNewNetworkFailure
    ) party_no_throw
{
    return PartyTestInjectCreateNewNetworkFailure(
        reinterpret_cast<PARTY_HANDLE>(partyManager),
        static_cast<PARTY_NETWORK_CREATION_TEST_FAILURE>(createNewNetworkFailure));
}

PartyError PartyTestManager::GetJitterBufferStatsForTest(
    PartyChatControl * remoteChatControl,
    _Out_ PartyJitterBufferStatsForTest* stats
    ) party_no_throw
{
    return PartyTestGetJitterBufferStatsForTest(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(remoteChatControl),
        reinterpret_cast<PARTY_JITTER_BUFFER_STATS_FOR_TEST*>(stats));
}

PartyError PartyTestManager::GetAudioRenderStatsForTest(
    PartyLocalChatControl * localChatControl,
    _Out_ PartyAudioRenderStatsForTest* stats
    ) party_no_throw
{
    return PartyTestGetAudioRenderStatsForTest(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(localChatControl),
        reinterpret_cast<PARTY_AUDIO_RENDER_STATS_FOR_TEST*>(stats));
}

PartyError PartyTestManager::GetLocalUserToken(
    const PartyLocalUser * localUser,
    _Outptr_ PartyString * token
    ) party_no_throw
{
    return PartyTestGetLocalUserToken(
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(localUser),
        token);
}

PartyError PartyTestManager::RefreshLocalUserToken(
    PartyLocalUser * localUser
    ) party_no_throw
{
    return PartyTestRefreshLocalUserToken(reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(localUser));
}

#ifdef PARTY_SAL_SUPPORT
#pragma prefast(pop)
#endif // PARTY_SAL_SUPPORT

#pragma push_macro("C_ASSERT")
#undef C_ASSERT
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]

// BEGIN GENERATED SECTION: DO NOT EDIT

C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_NONE == static_cast<uint32_t>(PartyNetworkCreationTestFailure::None));
C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_TITLE_NOT_ENABLED_FOR_PARTY == static_cast<uint32_t>(PartyNetworkCreationTestFailure::TitleNotEnabledForParty));
C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_AUTHORIZATION_FAILED == static_cast<uint32_t>(PartyNetworkCreationTestFailure::AuthorizationFailed));
C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_REQUEST_SERVER_TIMEOUT == static_cast<uint32_t>(PartyNetworkCreationTestFailure::RequestServerTimeout));
C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_NO_SERVERS_AVAILABLE == static_cast<uint32_t>(PartyNetworkCreationTestFailure::NoServersAvailable));
C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_SERVICE_ERROR == static_cast<uint32_t>(PartyNetworkCreationTestFailure::ServiceError));
C_ASSERT(PARTY_NETWORK_CREATION_TEST_FAILURE_USER_THROTTLED == static_cast<uint32_t>(PartyNetworkCreationTestFailure::UserThrottled));

C_ASSERT(sizeof(PARTY_JITTER_BUFFER_STATS_FOR_TEST) == sizeof(PartyJitterBufferStatsForTest));
C_ASSERT(sizeof(PARTY_JITTER_BUFFER_STATS_FOR_TEST::receivedAudioInMillisecondsSinceCreation) == sizeof(PartyJitterBufferStatsForTest::receivedAudioInMillisecondsSinceCreation));
C_ASSERT(offsetof(PARTY_JITTER_BUFFER_STATS_FOR_TEST, receivedAudioInMillisecondsSinceCreation) == offsetof(PartyJitterBufferStatsForTest, receivedAudioInMillisecondsSinceCreation));
C_ASSERT(sizeof(PARTY_JITTER_BUFFER_STATS_FOR_TEST::receivedButDroppedPacketCountSinceCreation) == sizeof(PartyJitterBufferStatsForTest::receivedButDroppedPacketCountSinceCreation));
C_ASSERT(offsetof(PARTY_JITTER_BUFFER_STATS_FOR_TEST, receivedButDroppedPacketCountSinceCreation) == offsetof(PartyJitterBufferStatsForTest, receivedButDroppedPacketCountSinceCreation));

C_ASSERT(sizeof(PARTY_AUDIO_RENDER_STATS_FOR_TEST) == sizeof(PartyAudioRenderStatsForTest));
C_ASSERT(sizeof(PARTY_AUDIO_RENDER_STATS_FOR_TEST::renderCountSinceCreation) == sizeof(PartyAudioRenderStatsForTest::renderCountSinceCreation));
C_ASSERT(offsetof(PARTY_AUDIO_RENDER_STATS_FOR_TEST, renderCountSinceCreation) == offsetof(PartyAudioRenderStatsForTest, renderCountSinceCreation));

C_ASSERT(sizeof(PARTY_ENDPOINT_HANDLE) == sizeof(PartyEndpoint*));
C_ASSERT(sizeof(PARTY_ENDPOINT_HANDLE) == sizeof(PartyLocalEndpoint*));
C_ASSERT(sizeof(PARTY_DEVICE_HANDLE) == sizeof(PartyDevice*));
C_ASSERT(sizeof(PARTY_DEVICE_HANDLE) == sizeof(PartyLocalDevice*));
C_ASSERT(sizeof(PARTY_INVITATION_HANDLE) == sizeof(PartyInvitation*));
C_ASSERT(sizeof(PARTY_NETWORK_HANDLE) == sizeof(PartyNetwork*));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_HANDLE) == sizeof(PartyChatControl*));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_HANDLE) == sizeof(PartyLocalChatControl*));
C_ASSERT(sizeof(PARTY_LOCAL_USER_HANDLE) == sizeof(PartyLocalUser*));

C_ASSERT(sizeof(PartyStateChangeType) == sizeof(uint32_t));

// END GENERATED SECTION

#pragma pop_macro("C_ASSERT")

}; // Party
