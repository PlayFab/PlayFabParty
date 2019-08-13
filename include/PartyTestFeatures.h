#pragma once

#ifndef __cplusplus
#error "This header requires C++"
#endif // end if not defined __cplusplus

namespace Party {

enum class PartyNetworkCreationTestFailure
{
    None,
    TitleNotEnabledForParty,
    AuthorizationFailed,
    RequestServerTimeout,
    NoServersAvailable,
    ServiceError,
    UserThrottled,
};

struct PartyJitterBufferStatsForTest
{
    uint32_t receivedAudioInMillisecondsSinceCreation;
    uint32_t receivedButDroppedPacketCountSinceCreation;
};

struct PartyAudioRenderStatsForTest
{
    uint32_t renderCountSinceCreation;
};

class PartyTestManager
{
public:
    /// <summary>
    /// Starts ungracefully leaving a network.
    /// </summary>
    static
    PartyError StartDestroyingNetwork(
        PartyNetwork * network,
        PartyError destroyError
        ) party_no_throw;

    /// <summary>
    /// Forces <paramref name="partyManager" /> to simulate CreateNewNetwork failures.
    /// </summary>
    static
    PartyError InjectCreateNewNetworkFailure(
        PartyManager * partyManager,
        PartyNetworkCreationTestFailure createNewNetworkFailure
        ) party_no_throw;

    /// <summary>
    /// Retrieves stats from the jitter buffer associated with a remote chat control.
    /// </summary>
    static
    PartyError GetJitterBufferStatsForTest(
        PartyChatControl * remoteChatControl,
        _Out_ PartyJitterBufferStatsForTest * stats
        ) party_no_throw;

    /// <summary>
    /// Retrieves stats from the audio render pipeline associated with a local chat control.
    /// </summary>
    static
    PartyError GetAudioRenderStatsForTest(
        PartyLocalChatControl * localChatControl,
        _Out_ PartyAudioRenderStatsForTest * stats
        ) party_no_throw;

    /// <summary>
    /// Get the current token associated with <paramref name="localUser" />.
    /// </summary>
    /// <remarks>
    /// The returned <paramref name="token" /> is valid until the next call to GetLocalUserToken().
    /// </remarks>
    static
    PartyError GetLocalUserToken(
        const PartyLocalUser * localUser,
        _Outptr_ PartyString * token
        ) party_no_throw;

    /// <summary>
    /// Force the local user to internally refresh their PlayFab token.
    /// </summary>
    static
    PartyError RefreshLocalUserToken(
        PartyLocalUser * localUser
        ) party_no_throw;
};

}; // Party
