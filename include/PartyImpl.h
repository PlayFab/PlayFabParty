#pragma once

#include <Party_c.h>

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
// PartyManager class implementation
//

PartyError PartyLocalUser::GetEntityId(
    _Outptr_ PartyString * entityId
    ) const party_no_throw
{
    return PartyLocalUserGetEntityId(
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(this),
        entityId);
}

PartyError PartyLocalUser::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyLocalUserGetCustomContext(
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(this),
        customContext);
}

PartyError PartyLocalUser::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyLocalUserSetCustomContext(
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(this),
        customContext);
}

PartyError PartyLocalEndpoint::GetLocalUser(
    _Outptr_result_maybenull_ PartyLocalUser ** localUser
    ) const party_no_throw
{
    return PartyEndpointGetLocalUser(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        const_cast<PARTY_LOCAL_USER_HANDLE *>(reinterpret_cast<const PARTY_LOCAL_USER_HANDLE *>(localUser)));
}

PartyError PartyLocalEndpoint::SendMessage(
    uint32_t targetEndpointCount,
    _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints,
    PartySendMessageOptions options,
    _In_opt_ const PartySendMessageQueuingConfiguration * queuingConfiguration,
    uint32_t dataBufferCount,
    _In_reads_(dataBufferCount) const PartyDataBuffer * dataBuffers,
    _In_opt_ void * messageIdentifier
    ) party_no_throw
{
    return PartyEndpointSendMessage(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        targetEndpointCount,
        reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(targetEndpoints),
        static_cast<PARTY_SEND_MESSAGE_OPTIONS>(options),
        reinterpret_cast<const PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION *>(queuingConfiguration),
        dataBufferCount,
        reinterpret_cast<const PARTY_DATA_BUFFER *>(dataBuffers),
        messageIdentifier);
}

PartyError PartyLocalEndpoint::CancelMessages(
    uint32_t targetEndpointCount,
    _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints,
    PartyCancelMessagesFilterExpression filterExpression,
    uint32_t messageIdentityFilterMask,
    uint32_t filteredMessageIdentitiesToMatch,
    _Out_opt_ uint32_t * canceledMessagesCount
    ) party_no_throw
{
    return PartyEndpointCancelMessages(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        targetEndpointCount,
        reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(targetEndpoints),
        static_cast<PARTY_CANCEL_MESSAGES_FILTER_EXPRESSION>(filterExpression),
        messageIdentityFilterMask,
        filteredMessageIdentitiesToMatch,
        canceledMessagesCount);
}

PartyError PartyLocalEndpoint::FlushMessages(
    uint32_t targetEndpointCount,
    _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints
    ) party_no_throw
{
    return PartyEndpointFlushMessages(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        targetEndpointCount,
        reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(targetEndpoints));
}

PartyError PartyLocalEndpoint::GetEndpointStatistics(
    uint32_t targetEndpointCount,
    _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints,
    uint32_t statisticCount,
    _In_reads_(statisticCount) const PartyEndpointStatistic * statisticTypes,
    _Out_writes_all_(statisticCount) uint64_t * statisticValues
    ) const party_no_throw
{
    return PartyEndpointGetEndpointStatistics(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        targetEndpointCount,
        reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(targetEndpoints),
        statisticCount,
        reinterpret_cast<const PARTY_ENDPOINT_STATISTIC *>(statisticTypes),
        statisticValues);
}

PartyError PartyLocalEndpoint::SetSharedProperties(
    uint32_t propertyCount,
    _In_reads_(propertyCount) const PartyString * keys,
    _In_reads_(propertyCount) const PartyDataBuffer * values
    ) party_no_throw
{
    return PartyEndpointSetProperties(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        propertyCount,
        keys,
        reinterpret_cast<const PARTY_DATA_BUFFER*>(values));
}

PartyError PartyEndpoint::GetLocal(
    _Outptr_result_maybenull_ PartyLocalEndpoint ** localEndpoint
    ) const party_no_throw
{
    PartyError error;
    PartyBool isLocal;

    error = PartyEndpointIsLocal(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        &isLocal);
    if (PARTY_SUCCEEDED(error))
    {
        if (isLocal != 0)
        {
            *localEndpoint = const_cast<PartyLocalEndpoint *>(reinterpret_cast<const PartyLocalEndpoint *>(this));
        }
        else
        {
            *localEndpoint = nullptr;
        }
    }

    return error;
}

PartyError PartyEndpoint::GetEntityId(
    _Outptr_result_maybenull_ PartyString * entityId
    ) const party_no_throw
{
    return PartyEndpointGetEntityId(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        entityId);
}

PartyError PartyEndpoint::GetSharedProperty(
    PartyString key,
    _Outptr_result_maybenull_ const PartyDataBuffer ** value
    ) const party_no_throw
{
    return PartyEndpointGetProperty(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        key,
        reinterpret_cast<const PARTY_DATA_BUFFER**>(value));
}

PartyError PartyEndpoint::GetSharedPropertyKeys(
    _Out_ uint32_t * propertyCount,
    _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
    ) const party_no_throw
{
    return PartyEndpointGetPropertyKeys(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        propertyCount,
        keys);
}

PartyError PartyEndpoint::GetNetwork(
    _Outptr_ PartyNetwork ** network
    ) const party_no_throw
{
    return PartyEndpointGetNetwork(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        const_cast<PARTY_NETWORK_HANDLE *>(reinterpret_cast<const PARTY_NETWORK_HANDLE *>(network)));
}

PartyError PartyEndpoint::GetDevice(
    _Outptr_ PartyDevice ** device
    ) const party_no_throw
{
    return PartyEndpointGetDevice(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        const_cast<PARTY_DEVICE_HANDLE *>(reinterpret_cast<const PARTY_DEVICE_HANDLE *>(device)));
}

PartyError PartyEndpoint::GetUniqueIdentifier(
    _Out_ uint16_t * uniqueIdentifier
    ) const
{
    return PartyEndpointGetUniqueIdentifier(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        uniqueIdentifier);
}

PartyError PartyEndpoint::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyEndpointGetCustomContext(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        customContext);
}

PartyError PartyEndpoint::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyEndpointSetCustomContext(
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(this),
        customContext);
}

PartyError PartyLocalDevice::CreateChatControl(
    const PartyLocalUser * localUser,
    _In_opt_ PartyString languageCode,
    _In_opt_ void * asyncIdentifier,
    _Outptr_opt_ PartyLocalChatControl ** localChatControl
    ) party_no_throw
{
    return PartyDeviceCreateChatControl(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(localUser),
        languageCode,
        asyncIdentifier,
        const_cast<PARTY_CHAT_CONTROL_HANDLE *>(reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE *>(localChatControl)));
}

PartyError PartyLocalDevice::DestroyChatControl(
    _In_ PartyLocalChatControl * localChatControl,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyDeviceDestroyChatControl(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(localChatControl),
        asyncIdentifier);
}

PartyError PartyLocalDevice::SetSharedProperties(
    uint32_t propertyCount,
    _In_reads_(propertyCount) const PartyString * keys,
    _In_reads_(propertyCount) const PartyDataBuffer * values
    ) party_no_throw
{
    return PartyDeviceSetProperties(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        propertyCount,
        keys,
        reinterpret_cast<const PARTY_DATA_BUFFER*>(values));
}

PartyError PartyDevice::GetLocal(
    _Outptr_result_maybenull_ PartyLocalDevice ** localDevice
    ) const party_no_throw
{
    PartyError error;
    PartyBool isLocal;

    error = PartyDeviceIsLocal(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        &isLocal);
    if (PARTY_SUCCEEDED(error))
    {
        if (isLocal != 0)
        {
            *localDevice = const_cast<PartyLocalDevice *>(reinterpret_cast<const PartyLocalDevice *>(this));
        }
        else
        {
            *localDevice = nullptr;
        }
    }

    return error;
}

PartyError PartyDevice::GetChatControls(
    _Out_ uint32_t * chatControlCount,
    _Outptr_result_buffer_(*chatControlCount) PartyChatControlArray * chatControls
    ) const party_no_throw
{
    return PartyDeviceGetChatControls(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        chatControlCount,
        const_cast<const PARTY_CHAT_CONTROL_HANDLE **>(reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE *const*>(chatControls)));
}

PartyError PartyDevice::GetSharedProperty(
    PartyString key,
    _Outptr_result_maybenull_ const PartyDataBuffer ** value
    ) const party_no_throw
{
    return PartyDeviceGetProperty(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        key,
        reinterpret_cast<const PARTY_DATA_BUFFER**>(value));
}

PartyError PartyDevice::GetSharedPropertyKeys(
    _Out_ uint32_t * propertyCount,
    _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
    ) const party_no_throw
{
    return PartyDeviceGetPropertyKeys(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        propertyCount,
        keys);
}

PartyError PartyDevice::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyDeviceGetCustomContext(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        customContext);
}

PartyError PartyDevice::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyDeviceSetCustomContext(
        reinterpret_cast<PARTY_DEVICE_HANDLE>(this),
        customContext);
}

PartyError PartyInvitation::GetCreatorEntityId(
    _Outptr_result_maybenull_ PartyString * entityId
    ) const party_no_throw
{
    return PartyInvitationGetCreatorEntityId(
        reinterpret_cast<PARTY_INVITATION_HANDLE>(this),
        entityId);
}

PartyError PartyInvitation::GetInvitationConfiguration(
    _Outptr_ const PartyInvitationConfiguration ** configuration
    ) const party_no_throw
{
    return PartyInvitationGetInvitationConfiguration(
        reinterpret_cast<PARTY_INVITATION_HANDLE>(this),
        reinterpret_cast<const PARTY_INVITATION_CONFIGURATION **>(configuration));
}

PartyError PartyInvitation::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyInvitationGetCustomContext(
        reinterpret_cast<PARTY_INVITATION_HANDLE>(this),
        customContext);
}

PartyError PartyInvitation::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyInvitationSetCustomContext(
        reinterpret_cast<PARTY_INVITATION_HANDLE>(this),
        customContext);
}

PartyError PartyNetwork::AuthenticateLocalUser(
    const PartyLocalUser * localUser,
    PartyString invitationIdentifier,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkAuthenticateLocalUser(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(localUser),
        invitationIdentifier,
        asyncIdentifier);
}

PartyError PartyNetwork::RemoveLocalUser(
    const PartyLocalUser * localUser,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkRemoveLocalUser(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(localUser),
        asyncIdentifier);
}

PartyError PartyNetwork::CreateInvitation(
    const PartyLocalUser * localUser,
    _In_opt_ const PartyInvitationConfiguration * invitationConfiguration,
    void* asyncIdentifier,
    _Outptr_opt_ PartyInvitation ** invitation
    ) party_no_throw
{
    return PartyNetworkCreateInvitation(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_LOCAL_USER_HANDLE>(localUser),
        reinterpret_cast<const PARTY_INVITATION_CONFIGURATION *>(invitationConfiguration),
        asyncIdentifier,
        const_cast<PARTY_INVITATION_HANDLE *>(reinterpret_cast<const PARTY_INVITATION_HANDLE *>(invitation)));
}

PartyError PartyNetwork::RevokeInvitation(
    const PartyLocalUser * localUser,
    PartyInvitation * invitation,
    void* asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkRevokeInvitation(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<const PARTY_LOCAL_USER_HANDLE>(localUser),
        reinterpret_cast<const PARTY_INVITATION_HANDLE>(invitation),
        asyncIdentifier);
}

PartyError PartyNetwork::GetInvitations(
    _Out_ uint32_t* invitationCount,
    _Outptr_result_buffer_(*invitationCount) PartyInvitationArray * invitations
    ) const party_no_throw
{
    return PartyNetworkGetInvitations(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        invitationCount,
        const_cast<const PARTY_INVITATION_HANDLE **>(reinterpret_cast<const PARTY_INVITATION_HANDLE *const*>(invitations)));
}

PartyError PartyNetwork::CreateEndpoint(
    _In_opt_ const PartyLocalUser * localUser,
    uint32_t propertyCount,
    _In_reads_opt_(propertyCount) const PartyString * keys,
    _In_reads_opt_(propertyCount) const PartyDataBuffer * values,
    _In_opt_ void * asyncIdentifier,
    _Outptr_opt_ PartyLocalEndpoint ** localEndpoint
    ) party_no_throw
{
    return PartyNetworkCreateEndpoint(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<const PARTY_LOCAL_USER_HANDLE>(localUser),
        propertyCount,
        keys,
        reinterpret_cast<const PARTY_DATA_BUFFER*>(values),
        asyncIdentifier,
        const_cast<PARTY_ENDPOINT_HANDLE *>(reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(localEndpoint)));
}

PartyError PartyNetwork::DestroyEndpoint(
    _In_ PartyLocalEndpoint * localEndpoint,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkDestroyEndpoint(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_ENDPOINT_HANDLE>(localEndpoint),
        asyncIdentifier);
}

PartyError PartyNetwork::LeaveNetwork(
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkLeaveNetwork(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        asyncIdentifier);
}

PartyError PartyNetwork::GetEndpoints(
    _Out_ uint32_t * endpointCount,
    _Outptr_result_buffer_(*endpointCount) PartyEndpointArray * endpoints
    ) const party_no_throw
{
    return PartyNetworkGetEndpoints(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        endpointCount,
        const_cast<const PARTY_ENDPOINT_HANDLE **>(reinterpret_cast<const PARTY_ENDPOINT_HANDLE *const*>(endpoints)));
}

PartyError PartyNetwork::FindEndpointByUniqueIdentifier(
    uint16_t uniqueIdentifier,
    _Outptr_ PartyEndpoint** endpoint
    ) const party_no_throw
{
    return PartyNetworkFindEndpointByUniqueIdentifier(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        uniqueIdentifier,
        const_cast<PARTY_ENDPOINT_HANDLE *>(reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(endpoint)));
}

PartyError PartyNetwork::GetDevices(
    _Out_ uint32_t * deviceCount,
    _Outptr_result_buffer_(*deviceCount) PartyDeviceArray * devices
    ) const party_no_throw
{
    return PartyNetworkGetDevices(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        deviceCount,
        const_cast<const PARTY_DEVICE_HANDLE **>(reinterpret_cast<const PARTY_DEVICE_HANDLE *const*>(devices)));
}

PartyError PartyNetwork::GetLocalUsers(
    _Out_ uint32_t * userCount,
    _Outptr_result_buffer_(*userCount) PartyLocalUserArray * users
    ) const party_no_throw
{
    return PartyNetworkGetLocalUsers(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        userCount,
        const_cast<const PARTY_LOCAL_USER_HANDLE **>(reinterpret_cast<const PARTY_LOCAL_USER_HANDLE *const*>(users)));
}

PartyError PartyNetwork::GetNetworkDescriptor(
    _Out_ PartyNetworkDescriptor * networkDescriptor
    ) const party_no_throw
{
    return PartyNetworkGetNetworkDescriptor(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_NETWORK_DESCRIPTOR *>(networkDescriptor));
}

PartyError PartyNetwork::GetNetworkConfiguration(
    _Outptr_ const PartyNetworkConfiguration ** networkConfiguration
    ) const party_no_throw
{
    return PartyNetworkGetNetworkConfiguration(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<const PARTY_NETWORK_CONFIGURATION **>(networkConfiguration));
}

PartyError PartyNetwork::KickDevice(
    const PartyDevice * targetDevice,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkKickDevice(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_DEVICE_HANDLE>(targetDevice),
        asyncIdentifier);
}

PartyError PartyNetwork::KickUser(
    PartyString targetEntityId,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkKickUser(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        targetEntityId,
        asyncIdentifier);
}

PartyError PartyNetwork::GetSharedProperty(
    PartyString key,
    _Outptr_result_maybenull_ const PartyDataBuffer ** value
    ) const party_no_throw
{
    return PartyNetworkGetProperty(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        key,
        reinterpret_cast<const PARTY_DATA_BUFFER**>(value));
}

PartyError PartyNetwork::GetSharedPropertyKeys(
    _Out_ uint32_t * propertyCount,
    _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
    ) const party_no_throw
{
    return PartyNetworkGetPropertyKeys(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        propertyCount,
        keys);
}

PartyError PartyNetwork::SetSharedProperties(
    uint32_t propertyCount,
    _In_reads_(propertyCount) const PartyString * keys,
    _In_reads_(propertyCount) const PartyDataBuffer * values
    ) party_no_throw
{
    return PartyNetworkSetProperties(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        propertyCount,
        keys,
        reinterpret_cast<const PARTY_DATA_BUFFER*>(values));
}

PartyError PartyNetwork::ConnectChatControl(
    _In_ PartyLocalChatControl* chatControl,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkConnectChatControl(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(chatControl),
        asyncIdentifier);
}

PartyError PartyNetwork::DisconnectChatControl(
    _In_ PartyLocalChatControl* chatControl,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyNetworkDisconnectChatControl(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(chatControl),
        asyncIdentifier);
}

PartyError PartyNetwork::GetChatControls(
    _Out_ uint32_t * chatControlCount,
    _Outptr_result_buffer_(*chatControlCount) PartyChatControlArray * chatControls
    ) const party_no_throw
{
    return PartyNetworkGetChatControls(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        chatControlCount,
        const_cast<const PARTY_CHAT_CONTROL_HANDLE **>(reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE *const*>(chatControls)));
}

PartyError PartyNetwork::GetNetworkStatistics(
    uint32_t statisticCount,
    _In_reads_(statisticCount) const PartyNetworkStatistic * statisticTypes,
    _Out_writes_all_(statisticCount) uint64_t * statisticValues
    ) const party_no_throw
{
    return PartyNetworkGetNetworkStatistics(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        statisticCount,
        reinterpret_cast<const PARTY_NETWORK_STATISTIC *>(statisticTypes),
        statisticValues);
}

PartyError PartyNetwork::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyNetworkGetCustomContext(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        customContext);
}

PartyError PartyNetwork::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyNetworkSetCustomContext(
        reinterpret_cast<PARTY_NETWORK_HANDLE>(this),
        customContext);
}

PartyError PartyLocalChatControl::GetLocalUser(
    _Outptr_ PartyLocalUser ** localUser
    ) const party_no_throw
{
    return PartyChatControlGetLocalUser(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        const_cast<PARTY_LOCAL_USER_HANDLE *>(reinterpret_cast<const PARTY_LOCAL_USER_HANDLE *>(localUser)));
}

PartyError PartyLocalChatControl::SetPermissions(
    const PartyChatControl * targetChatControl,
    PartyChatPermissionOptions chatPermissionOptions
    ) party_no_throw
{
    return PartyChatControlSetPermissions(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        static_cast<PARTY_CHAT_PERMISSION_OPTIONS>(chatPermissionOptions));
}

PartyError PartyLocalChatControl::GetPermissions(
    const PartyChatControl * targetChatControl,
    _Out_ PartyChatPermissionOptions * chatPermissionOptions
    ) const party_no_throw
{
    return PartyChatControlGetPermissions(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        reinterpret_cast<PARTY_CHAT_PERMISSION_OPTIONS*>(chatPermissionOptions));
}

PartyError PartyLocalChatControl::SendText(
    uint32_t targetChatControlCount,
    _In_reads_(targetChatControlCount) PartyChatControlArray targetChatControls,
    PartyString chatText,
    uint32_t dataBufferCount,
    _In_reads_(dataBufferCount) const PartyDataBuffer * dataBuffers
    ) party_no_throw
{
    return PartyChatControlSendText(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        targetChatControlCount,
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE *>(targetChatControls),
        chatText,
        dataBufferCount,
        reinterpret_cast<const PARTY_DATA_BUFFER *>(dataBuffers));
}

PartyError PartyLocalChatControl::SetAudioInput(
    PartyAudioDeviceSelectionType audioDeviceSelectionType,
    _In_opt_ PartyString audioDeviceSelectionContext,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetAudioInput(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_AUDIO_DEVICE_SELECTION_TYPE>(audioDeviceSelectionType),
        audioDeviceSelectionContext,
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetAudioInput(
    _Out_opt_ PartyAudioDeviceSelectionType * audioDeviceSelectionType,
    _Outptr_ PartyString * audioDeviceSelectionContext,
    _Outptr_ PartyString * deviceId
    ) const party_no_throw
{
    return PartyChatControlGetAudioInput(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_AUDIO_DEVICE_SELECTION_TYPE*>(audioDeviceSelectionType),
        audioDeviceSelectionContext,
        deviceId);
}

PartyError PartyLocalChatControl::SetAudioOutput(
    PartyAudioDeviceSelectionType audioDeviceSelectionType,
    _In_opt_ PartyString audioDeviceSelectionContext,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetAudioOutput(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_AUDIO_DEVICE_SELECTION_TYPE>(audioDeviceSelectionType),
        audioDeviceSelectionContext,
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetAudioOutput(
    _Out_opt_ PartyAudioDeviceSelectionType * audioDeviceSelectionType,
    _Outptr_ PartyString * audioDeviceSelectionContext,
    _Outptr_ PartyString * deviceId
    ) const party_no_throw
{
    return PartyChatControlGetAudioOutput(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_AUDIO_DEVICE_SELECTION_TYPE*>(audioDeviceSelectionType),
        audioDeviceSelectionContext,
        deviceId);
}

PartyError PartyLocalChatControl::PopulateAvailableTextToSpeechProfiles(
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlPopulateAvailableTextToSpeechProfiles(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetAvailableTextToSpeechProfiles(
    _Out_ uint32_t * profileCount,
    _Outptr_result_buffer_(*profileCount) PartyTextToSpeechProfileArray * profiles
    ) const party_no_throw
{
    return PartyChatControlGetAvailableTextToSpeechProfiles(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        profileCount,
        const_cast<const PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE**>(reinterpret_cast<const PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE *const*>(profiles)));
}

PartyError PartyLocalChatControl::SetTextToSpeechProfile(
    PartySynthesizeTextToSpeechType type,
    PartyString profile,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetTextToSpeechProfile(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_SYNTHESIZE_TEXT_TO_SPEECH_TYPE>(type),
        profile,
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetTextToSpeechProfile(
    PartySynthesizeTextToSpeechType type,
    _Outptr_result_maybenull_ PartyTextToSpeechProfile ** profile
    ) const party_no_throw
{
    return PartyChatControlGetTextToSpeechProfile(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_SYNTHESIZE_TEXT_TO_SPEECH_TYPE>(type),
        const_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE *>(reinterpret_cast<const PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE*>(profile)));
}

PartyError PartyLocalChatControl::SynthesizeTextToSpeech(
    PartySynthesizeTextToSpeechType type,
    PartyString textToSynthesize,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSynthesizeTextToSpeech(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_SYNTHESIZE_TEXT_TO_SPEECH_TYPE>(type),
        textToSynthesize,
        asyncIdentifier);
}

PartyError PartyLocalChatControl::SetLanguage(
    PartyString languageCode,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetLanguage(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        languageCode,
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetLanguage(
    _Outptr_ PartyString * languageCode
    ) const party_no_throw
{
    return PartyChatControlGetLanguage(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        languageCode);
}

PartyError PartyLocalChatControl::SetTranscriptionOptions(
    PartyVoiceChatTranscriptionOptions options,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetTranscriptionOptions(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS>(options),
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetTranscriptionOptions(
    _Out_ PartyVoiceChatTranscriptionOptions * options
    ) const party_no_throw
{
    return PartyChatControlGetTranscriptionOptions(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS*>(options));
}

PartyError PartyLocalChatControl::SetTextChatOptions(
    PartyTextChatOptions options,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetTextChatOptions(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        static_cast<PARTY_TEXT_CHAT_OPTIONS>(options),
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetTextChatOptions(
    _Out_ PartyTextChatOptions * options
    ) const party_no_throw
{
    return PartyChatControlGetTextChatOptions(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_TEXT_CHAT_OPTIONS*>(options));
}


PartyError PartyLocalChatControl::SetAudioRenderVolume(
    const PartyChatControl * targetChatControl,
    float volume
    ) party_no_throw
{
    return PartyChatControlSetAudioRenderVolume(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        volume);
}

PartyError PartyLocalChatControl::GetAudioRenderVolume(
    const PartyChatControl * targetChatControl,
    _Out_ float * volume
    ) const party_no_throw
{
    return PartyChatControlGetAudioRenderVolume(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        volume);
}

PartyError PartyLocalChatControl::SetAudioInputMuted(
    PartyBool muted
    ) party_no_throw
{
    return PartyChatControlSetAudioInputMuted(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        muted);
}

PartyError PartyLocalChatControl::GetAudioInputMuted(
    _Out_ PartyBool * muted
    ) const party_no_throw
{
    return PartyChatControlGetAudioInputMuted(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        muted);
}

PartyError PartyLocalChatControl::SetIncomingAudioMuted(
    const PartyChatControl * targetChatControl,
    PartyBool muted
    ) party_no_throw
{
    return PartyChatControlSetIncomingAudioMuted(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        muted);
}

PartyError PartyLocalChatControl::GetIncomingAudioMuted(
    const PartyChatControl * targetChatControl,
    _Out_ PartyBool * muted
    ) const party_no_throw
{
    return PartyChatControlGetIncomingAudioMuted(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        muted);
}

PartyError PartyLocalChatControl::SetIncomingTextMuted(
    const PartyChatControl * targetChatControl,
    PartyBool muted
    ) party_no_throw
{
    return PartyChatControlSetIncomingTextMuted(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        muted);
}

PartyError PartyLocalChatControl::GetIncomingTextMuted(
    const PartyChatControl * targetChatControl,
    _Out_ PartyBool * muted
    ) const party_no_throw
{
    return PartyChatControlGetIncomingTextMuted(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        muted);
}

PartyError PartyLocalChatControl::GetLocalChatIndicator(
    _Out_ PartyLocalChatControlChatIndicator * chatIndicator
    ) const party_no_throw
{
    return PartyChatControlGetLocalChatIndicator(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<PARTY_LOCAL_CHAT_CONTROL_CHAT_INDICATOR *>(chatIndicator));
}

PartyError PartyLocalChatControl::GetChatIndicator(
    const PartyChatControl * targetChatControl,
    _Out_ PartyChatControlChatIndicator * chatIndicator
    ) const party_no_throw
{
    return PartyChatControlGetChatIndicator(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE>(targetChatControl),
        reinterpret_cast<PARTY_CHAT_CONTROL_CHAT_INDICATOR *>(chatIndicator));
}

PartyError PartyLocalChatControl::SetAudioEncoderBitrate(
    uint32_t bitrate,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyChatControlSetAudioEncoderBitrate(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        bitrate,
        asyncIdentifier);
}

PartyError PartyLocalChatControl::GetAudioEncoderBitrate(
    _Out_ uint32_t * bitrate
    ) const party_no_throw
{
    return PartyChatControlGetAudioEncoderBitrate(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        bitrate);
}

PartyError PartyLocalChatControl::SetSharedProperties(
    uint32_t propertyCount,
    _In_reads_(propertyCount) const PartyString * keys,
    _In_reads_(propertyCount) const PartyDataBuffer * values
    ) party_no_throw
{
    return PartyChatControlSetProperties(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        propertyCount,
        keys,
        reinterpret_cast<const PARTY_DATA_BUFFER*>(values));
}

PartyError PartyChatControl::GetLocal(
    _Outptr_result_maybenull_ PartyLocalChatControl ** localChatControl
    ) const party_no_throw
{
    PartyError error;
    PartyBool isLocal;

    error = PartyChatControlIsLocal(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        &isLocal);
    if (PARTY_SUCCEEDED(error))
    {
        if (isLocal != 0)
        {
            *localChatControl = const_cast<PartyLocalChatControl *>(reinterpret_cast<const PartyLocalChatControl *>(this));
        }
        else
        {
            *localChatControl = nullptr;
        }
    }

    return error;
}

PartyError PartyChatControl::GetDevice(
    _Outptr_ PartyDevice ** device
    ) const party_no_throw
{
    return PartyChatControlGetDevice(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        const_cast<PARTY_DEVICE_HANDLE *>(reinterpret_cast<const PARTY_DEVICE_HANDLE *>(device)));
}

PartyError PartyChatControl::GetEntityId(
    _Outptr_ PartyString * entityId
    ) const party_no_throw
{
    return PartyChatControlGetEntityId(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        entityId);
}

PartyError PartyChatControl::GetSharedProperty(
    PartyString key,
    _Outptr_result_maybenull_ const PartyDataBuffer ** value
    ) const party_no_throw
{
    return PartyChatControlGetProperty(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        key,
        reinterpret_cast<const PARTY_DATA_BUFFER**>(value));
}

PartyError PartyChatControl::GetSharedPropertyKeys(
    _Out_ uint32_t * propertyCount,
    _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
    ) const party_no_throw
{
    return PartyChatControlGetPropertyKeys(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        propertyCount,
        keys);
}

PartyError PartyChatControl::GetNetworks(
    _Out_ uint32_t * networkCount,
    _Outptr_result_buffer_(*networkCount) PartyNetworkArray * networks
    ) const party_no_throw
{
    return PartyChatControlGetNetworks(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        networkCount,
        const_cast<const PARTY_NETWORK_HANDLE **>(reinterpret_cast<const PARTY_NETWORK_HANDLE *const*>(networks)));
}

PartyError PartyChatControl::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyChatControlSetCustomContext(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        customContext);
}

PartyError PartyChatControl::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyChatControlGetCustomContext(
        reinterpret_cast<PARTY_CHAT_CONTROL_HANDLE>(this),
        customContext);
}

PartyError PartyTextToSpeechProfile::GetIdentifier(
    _Outptr_ PartyString * identifier
    ) const party_no_throw
{
    return PartyTextToSpeechProfileGetIdentifier(
        reinterpret_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE>(this),
        identifier);
}

PartyError PartyTextToSpeechProfile::GetName(
    _Outptr_ PartyString * name
    ) const party_no_throw
{
    return PartyTextToSpeechProfileGetName(
        reinterpret_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE>(this),
        name);
}

PartyError PartyTextToSpeechProfile::GetLanguageCode(
    _Outptr_ PartyString * languageCode
    ) const party_no_throw
{
    return PartyTextToSpeechProfileGetLanguageCode(
        reinterpret_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE>(this),
        languageCode);
}

PartyError PartyTextToSpeechProfile::GetGender(
    _Out_ PartyGender * gender
    ) const party_no_throw
{
    return PartyTextToSpeechProfileGetGender(
        reinterpret_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE>(this),
        reinterpret_cast<PARTY_GENDER *>(gender));
}

PartyError PartyTextToSpeechProfile::GetCustomContext(
    _Outptr_result_maybenull_ void ** customContext
    ) const party_no_throw
{
    return PartyTextToSpeechProfileGetCustomContext(
        reinterpret_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE>(this),
        customContext);
}

PartyError PartyTextToSpeechProfile::SetCustomContext(
    _In_opt_ void * customContext
    ) party_no_throw
{
    return PartyTextToSpeechProfileSetCustomContext(
        reinterpret_cast<PARTY_TEXT_TO_SPEECH_PROFILE_HANDLE>(this),
        customContext);
}

PartyManager::PartyManager() :
    _handle(nullptr)
{
}

PartyManager::~PartyManager()
{
}

PartyManager& PartyManager::GetSingleton() party_no_throw
{
    static PartyManager singleton;
    return singleton;
}

PartyError PartyManager::GetErrorMessage(
    PartyError error,
    _Outptr_ PartyString* errorMessage
    ) party_no_throw
{
    return PartyGetErrorMessage(error, errorMessage);
}

PartyError PartyManager::SerializeNetworkDescriptor(
    const PartyNetworkDescriptor * networkDescriptor,
    _Out_writes_z_(c_maxSerializedNetworkDescriptorStringLength + 1) char * serializedNetworkDescriptorString
    )
{
    return PartySerializeNetworkDescriptor(
        reinterpret_cast<const PARTY_NETWORK_DESCRIPTOR *>(networkDescriptor),
        serializedNetworkDescriptorString);
}

PartyError PartyManager::DeserializeNetworkDescriptor(
    PartyString serializedNetworkDescriptorString,
    _Out_ PartyNetworkDescriptor * networkDescriptor
    )
{
    return PartyDeserializeNetworkDescriptor(
        serializedNetworkDescriptorString,
        reinterpret_cast<PARTY_NETWORK_DESCRIPTOR *>(networkDescriptor));
}

PartyError PartyManager::SetMemoryCallbacks(
    _In_opt_ PartyAllocateMemoryCallback allocateMemoryCallback,
    _In_opt_ PartyFreeMemoryCallback freeMemoryCallback
    ) party_no_throw
{
    return PartySetMemoryCallbacks(allocateMemoryCallback, freeMemoryCallback);
}

PartyError PartyManager::GetMemoryCallbacks(
    _Out_ PartyAllocateMemoryCallback * allocateMemoryCallback,
    _Out_ PartyFreeMemoryCallback * freeMemoryCallback
    ) party_no_throw
{
    return PartyGetMemoryCallbacks(allocateMemoryCallback, freeMemoryCallback);
}

PartyError PartyManager::SetThreadAffinityMask(
    PartyThreadId threadId,
    uint64_t threadAffinityMask
    ) party_no_throw
{
    return PartySetThreadAffinityMask(
        static_cast<PARTY_THREAD_ID>(threadId),
        threadAffinityMask);
}

PartyError PartyManager::GetThreadAffinityMask(
    PartyThreadId threadId,
    _Out_ uint64_t * threadAffinityMask
    ) party_no_throw
{
    return PartyGetThreadAffinityMask(
        static_cast<PARTY_THREAD_ID>(threadId),
        threadAffinityMask);
}

PartyError PartyManager::Initialize(
    PartyString titleId
    ) party_no_throw
{
    void* newHandle = nullptr;

    PartyError error = PartyInitialize(
        titleId,
        const_cast<PARTY_HANDLE *>(reinterpret_cast<const PARTY_HANDLE *>(&newHandle)));
    if (PARTY_SUCCEEDED(error))
    {
        _handle = newHandle;
    }

    return error;
}

PartyError PartyManager::Cleanup() party_no_throw
{
    PartyError error = PartyCleanup(reinterpret_cast<PARTY_HANDLE>(_handle));
    _handle = nullptr;

    return error;
}

PartyError PartyManager::StartProcessingStateChanges(
    _Out_ uint32_t * stateChangeCount,
    _Outptr_result_buffer_(*stateChangeCount) PartyStateChangeArray * stateChanges
    ) party_no_throw
{
    return PartyStartProcessingStateChanges(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        stateChangeCount,
        reinterpret_cast<const PARTY_STATE_CHANGE * const **>(stateChanges));
}

PartyError PartyManager::FinishProcessingStateChanges(
    uint32_t stateChangeCount,
    _In_reads_(stateChangeCount) PartyStateChangeArray stateChanges
    ) party_no_throw
{
    return PartyFinishProcessingStateChanges(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        stateChangeCount,
        reinterpret_cast<const PARTY_STATE_CHANGE * const *>(stateChanges));
}

PartyError PartyManager::GetRegions(
    _Out_ uint32_t * regionListCount,
    _Outptr_result_buffer_(*regionListCount) const PartyRegion ** regionList
    ) party_no_throw
{
    return PartyGetRegions(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        regionListCount,
        reinterpret_cast<const PARTY_REGION **>(regionList));
}

PartyError PartyManager::CreateNewNetwork(
    const PartyLocalUser * localUser,
    const PartyNetworkConfiguration * networkConfiguration,
    uint32_t regionCount,
    const PartyRegion * regions,
    _In_opt_ const PartyInvitationConfiguration * initialInvitationConfiguration,
    _In_opt_ void * asyncIdentifier,
    _Out_opt_ PartyNetworkDescriptor * networkDescriptor,
    _Out_writes_opt_z_(c_maxInvitationIdentifierStringLength + 1) char * appliedInitialInvitationIdentifier
    ) party_no_throw
{
    return PartyCreateNewNetwork(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        reinterpret_cast<const PARTY_LOCAL_USER_HANDLE>(localUser),
        reinterpret_cast<const PARTY_NETWORK_CONFIGURATION *>(networkConfiguration),
        regionCount,
        reinterpret_cast<const PARTY_REGION *>(regions),
        reinterpret_cast<const PARTY_INVITATION_CONFIGURATION *>(initialInvitationConfiguration),
        asyncIdentifier,
        reinterpret_cast<PARTY_NETWORK_DESCRIPTOR *>(networkDescriptor),
        appliedInitialInvitationIdentifier);
}

PartyError  PartyManager::ConnectToNetwork(
    const PartyNetworkDescriptor * networkDescriptor,
    _In_opt_ void * asyncIdentifier,
    _Outptr_opt_ PartyNetwork ** network
    ) party_no_throw
{
    return PartyConnectToNetwork(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        reinterpret_cast<const PARTY_NETWORK_DESCRIPTOR *>(networkDescriptor),
        asyncIdentifier,
        const_cast<PARTY_NETWORK_HANDLE *>(reinterpret_cast<const PARTY_NETWORK_HANDLE *>(network)));
}

PartyError PartyManager::SynchronizeMessagesBetweenEndpoints(
    uint32_t endpointCount,
    _In_reads_(endpointCount) PartyEndpointArray endpoints,
    PartySynchronizeMessagesBetweenEndpointsOptions options,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartySynchronizeMessagesBetweenEndpoints(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        endpointCount,
        reinterpret_cast<const PARTY_ENDPOINT_HANDLE *>(endpoints),
        static_cast<PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_OPTIONS>(options),
        asyncIdentifier);
}

PartyError PartyManager::GetLocalDevice(
    _Outptr_ PartyLocalDevice ** localDevice
    ) const party_no_throw
{
    return PartyGetLocalDevice(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        const_cast<PARTY_DEVICE_HANDLE *>(reinterpret_cast<const PARTY_DEVICE_HANDLE *>(localDevice)));
}

PartyError PartyManager::CreateLocalUser(
    PartyString entityId,
    PartyString titlePlayerEntityToken,
    _Outptr_ PartyLocalUser ** localUser
    ) party_no_throw
{
    return PartyCreateLocalUser(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        entityId,
        titlePlayerEntityToken,
        const_cast<PARTY_LOCAL_USER_HANDLE *>(reinterpret_cast<const PARTY_LOCAL_USER_HANDLE *>(localUser)));
}

PartyError PartyManager::DestroyLocalUser(
    const PartyLocalUser * localUser,
    _In_opt_ void * asyncIdentifier
    ) party_no_throw
{
    return PartyDestroyLocalUser(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        reinterpret_cast<const PARTY_LOCAL_USER_HANDLE>(localUser),
        asyncIdentifier);
}

PartyError PartyManager::GetLocalUsers(
    _Out_ uint32_t * userCount,
    _Outptr_result_buffer_(*userCount) PartyLocalUserArray * users
    ) const party_no_throw
{
    return PartyGetLocalUsers(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        userCount,
        const_cast<const PARTY_LOCAL_USER_HANDLE **>(reinterpret_cast<const PARTY_LOCAL_USER_HANDLE *const*>(users)));
}

PartyError PartyManager::GetNetworks(
    _Out_ uint32_t * networkCount,
    _Outptr_result_buffer_(*networkCount) PartyNetworkArray * networks
    ) const party_no_throw
{
    return PartyGetNetworks(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        networkCount,
        const_cast<const PARTY_NETWORK_HANDLE **>(reinterpret_cast<const PARTY_NETWORK_HANDLE *const*>(networks)));
}

PartyError PartyManager::GetChatControls(
    _Out_ uint32_t * chatControlCount,
    _Outptr_result_buffer_(*chatControlCount) PartyChatControlArray * chatControls
    ) const party_no_throw
{
    return PartyGetChatControls(
        reinterpret_cast<PARTY_HANDLE>(_handle),
        chatControlCount,
        const_cast<const PARTY_CHAT_CONTROL_HANDLE **>(reinterpret_cast<const PARTY_CHAT_CONTROL_HANDLE *const*>(chatControls)));
}

//
// C to C++ structure and constant verification
//
#pragma push_macro("C_ASSERT")
#undef C_ASSERT
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]

// BEGIN GENERATED SECTION: DO NOT EDIT

C_ASSERT(PARTY_MAX_NETWORK_CONFIGURATION_MAX_DEVICE_COUNT == c_maxNetworkConfigurationMaxDeviceCount);
C_ASSERT(PARTY_MAX_NETWORK_CONFIGURATION_MAX_ENDPOINTS_PER_DEVICE_COUNT == c_maxNetworkConfigurationMaxEndpointsPerDeviceCount);
C_ASSERT(PARTY_MAX_LOCAL_USERS_PER_DEVICE_COUNT == c_maxLocalUsersPerDeviceCount);
C_ASSERT(PARTY_OPAQUE_CONNECTION_INFORMATION_BYTE_COUNT == c_opaqueConnectionInformationByteCount);
C_ASSERT(PARTY_MAX_INVITATION_IDENTIFIER_STRING_LENGTH == c_maxInvitationIdentifierStringLength);
C_ASSERT(PARTY_MAX_INVITATION_ENTITY_ID_COUNT == c_maxInvitationEntityIdCount);
C_ASSERT(PARTY_MAX_ENTITY_ID_STRING_LENGTH == c_maxEntityIdStringLength);
C_ASSERT(PARTY_NETWORK_IDENTIFIER_STRING_LENGTH == c_networkIdentifierStringLength);
C_ASSERT(PARTY_MAX_REGION_NAME_STRING_LENGTH == c_maxRegionNameStringLength);
C_ASSERT(PARTY_MAX_SERIALIZED_NETWORK_DESCRIPTOR_STRING_LENGTH == c_maxSerializedNetworkDescriptorStringLength);
C_ASSERT(PARTY_MAX_AUDIO_DEVICE_IDENTIFIER_STRING_LENGTH == c_maxAudioDeviceIdentifierStringLength);
C_ASSERT(PARTY_MAX_LANGUAGE_CODE_STRING_LENGTH == c_maxLanguageCodeStringLength);
C_ASSERT(PARTY_MAX_CHAT_TEXT_MESSAGE_STRING_LENGTH == c_maxChatTextMessageStringLength);
C_ASSERT(PARTY_MAX_CHAT_TRANSCRIPTION_MESSAGE_STRING_LENGTH == c_maxChatTranscriptionMessageStringLength);
C_ASSERT(PARTY_MAX_TEXT_TO_SPEECH_PROFILE_IDENTIFIER_STRING_LENGTH == c_maxTextToSpeechProfileIdentifierStringLength);
C_ASSERT(PARTY_MAX_TEXT_TO_SPEECH_PROFILE_NAME_STRING_LENGTH == c_maxTextToSpeechProfileNameStringLength);
C_ASSERT(PARTY_MAX_TEXT_TO_SPEECH_INPUT_STRING_LENGTH == c_maxTextToSpeechInputStringLength);
C_ASSERT(PARTY_ANY_PROCESSOR == c_anyProcessor);
C_ASSERT(PARTY_MIN_SEND_MESSAGE_QUEUING_PRIORITY == c_minSendMessageQueuingPriority);
C_ASSERT(PARTY_CHAT_SEND_MESSAGE_QUEUING_PRIORITY == c_chatSendMessageQueuingPriority);
C_ASSERT(PARTY_DEFAULT_SEND_MESSAGE_QUEUING_PRIORITY == c_defaultSendMessageQueuingPriority);
C_ASSERT(PARTY_MAX_SEND_MESSAGE_QUEUING_PRIORITY == c_maxSendMessageQueuingPriority);

C_ASSERT(PARTY_STATE_CHANGE_TYPE_REGIONS_CHANGED == static_cast<uint32_t>(PartyStateChangeType::RegionsChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_DESTROY_LOCAL_USER_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::DestroyLocalUserCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CREATE_NEW_NETWORK_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::CreateNewNetworkCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CONNECT_TO_NETWORK_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::ConnectToNetworkCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_AUTHENTICATE_LOCAL_USER_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::AuthenticateLocalUserCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_NETWORK_CONFIGURATION_MADE_AVAILABLE == static_cast<uint32_t>(PartyStateChangeType::NetworkConfigurationMadeAvailable));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_NETWORK_DESCRIPTOR_CHANGED == static_cast<uint32_t>(PartyStateChangeType::NetworkDescriptorChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_LOCAL_USER_REMOVED == static_cast<uint32_t>(PartyStateChangeType::LocalUserRemoved));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_REMOVE_LOCAL_USER_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::RemoveLocalUserCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_LOCAL_USER_KICKED == static_cast<uint32_t>(PartyStateChangeType::LocalUserKicked));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CREATE_ENDPOINT_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::CreateEndpointCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_DESTROY_ENDPOINT_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::DestroyEndpointCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_ENDPOINT_CREATED == static_cast<uint32_t>(PartyStateChangeType::EndpointCreated));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_ENDPOINT_DESTROYED == static_cast<uint32_t>(PartyStateChangeType::EndpointDestroyed));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_REMOTE_DEVICE_CREATED == static_cast<uint32_t>(PartyStateChangeType::RemoteDeviceCreated));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_REMOTE_DEVICE_DESTROYED == static_cast<uint32_t>(PartyStateChangeType::RemoteDeviceDestroyed));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_REMOTE_DEVICE_JOINED_NETWORK == static_cast<uint32_t>(PartyStateChangeType::RemoteDeviceJoinedNetwork));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_REMOTE_DEVICE_LEFT_NETWORK == static_cast<uint32_t>(PartyStateChangeType::RemoteDeviceLeftNetwork));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_DEVICE_PROPERTIES_CHANGED == static_cast<uint32_t>(PartyStateChangeType::DevicePropertiesChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_LEAVE_NETWORK_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::LeaveNetworkCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_NETWORK_DESTROYED == static_cast<uint32_t>(PartyStateChangeType::NetworkDestroyed));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_ENDPOINT_MESSAGE_RECEIVED == static_cast<uint32_t>(PartyStateChangeType::EndpointMessageReceived));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_DATA_BUFFERS_RETURNED == static_cast<uint32_t>(PartyStateChangeType::DataBuffersReturned));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_ENDPOINT_PROPERTIES_CHANGED == static_cast<uint32_t>(PartyStateChangeType::EndpointPropertiesChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SynchronizeMessagesBetweenEndpointsCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CREATE_INVITATION_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::CreateInvitationCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_REVOKE_INVITATION_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::RevokeInvitationCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_INVITATION_CREATED == static_cast<uint32_t>(PartyStateChangeType::InvitationCreated));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_INVITATION_DESTROYED == static_cast<uint32_t>(PartyStateChangeType::InvitationDestroyed));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_NETWORK_PROPERTIES_CHANGED == static_cast<uint32_t>(PartyStateChangeType::NetworkPropertiesChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_KICK_DEVICE_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::KickDeviceCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_KICK_USER_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::KickUserCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CREATE_CHAT_CONTROL_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::CreateChatControlCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_DESTROY_CHAT_CONTROL_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::DestroyChatControlCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CHAT_CONTROL_CREATED == static_cast<uint32_t>(PartyStateChangeType::ChatControlCreated));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CHAT_CONTROL_DESTROYED == static_cast<uint32_t>(PartyStateChangeType::ChatControlDestroyed));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetChatAudioEncoderBitrateCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CHAT_TEXT_RECEIVED == static_cast<uint32_t>(PartyStateChangeType::ChatTextReceived));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_VOICE_CHAT_TRANSCRIPTION_RECEIVED == static_cast<uint32_t>(PartyStateChangeType::VoiceChatTranscriptionReceived));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_CHAT_AUDIO_INPUT_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetChatAudioInputCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_CHAT_AUDIO_OUTPUT_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetChatAudioOutputCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_LOCAL_CHAT_AUDIO_INPUT_CHANGED == static_cast<uint32_t>(PartyStateChangeType::LocalChatAudioInputChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED == static_cast<uint32_t>(PartyStateChangeType::LocalChatAudioOutputChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetTextToSpeechProfileCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SynthesizeTextToSpeechCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_LANGUAGE_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetLanguageCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_TRANSCRIPTION_OPTIONS_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetTranscriptionOptionsCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_SET_TEXT_CHAT_OPTIONS_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::SetTextChatOptionsCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CHAT_CONTROL_PROPERTIES_CHANGED == static_cast<uint32_t>(PartyStateChangeType::ChatControlPropertiesChanged));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CHAT_CONTROL_JOINED_NETWORK == static_cast<uint32_t>(PartyStateChangeType::ChatControlJoinedNetwork));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CHAT_CONTROL_LEFT_NETWORK == static_cast<uint32_t>(PartyStateChangeType::ChatControlLeftNetwork));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_CONNECT_CHAT_CONTROL_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::ConnectChatControlCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_DISCONNECT_CHAT_CONTROL_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::DisconnectChatControlCompleted));
C_ASSERT(PARTY_STATE_CHANGE_TYPE_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED == static_cast<uint32_t>(PartyStateChangeType::PopulateAvailableTextToSpeechProfilesCompleted));

C_ASSERT(PARTY_STATE_CHANGE_RESULT_SUCCEEDED == static_cast<uint32_t>(PartyStateChangeResult::Succeeded));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_UNKNOWN_ERROR == static_cast<uint32_t>(PartyStateChangeResult::UnknownError));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_CANCELED_BY_TITLE == static_cast<uint32_t>(PartyStateChangeResult::CanceledByTitle));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_INTERNET_CONNECTIVITY_ERROR == static_cast<uint32_t>(PartyStateChangeResult::InternetConnectivityError));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_PARTY_SERVICE_ERROR == static_cast<uint32_t>(PartyStateChangeResult::PartyServiceError));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_NO_SERVERS_AVAILABLE == static_cast<uint32_t>(PartyStateChangeResult::NoServersAvailable));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_USER_NOT_AUTHORIZED == static_cast<uint32_t>(PartyStateChangeResult::UserNotAuthorized));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_USER_CREATE_NETWORK_THROTTLED == static_cast<uint32_t>(PartyStateChangeResult::UserCreateNetworkThrottled));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_TITLE_NOT_ENABLED_FOR_PARTY == static_cast<uint32_t>(PartyStateChangeResult::TitleNotEnabledForParty));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_TITLE_CREATE_NETWORK_THROTTLED == static_cast<uint32_t>(PartyStateChangeResult::TitleCreateNetworkThrottled));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_NETWORK_LIMIT_REACHED == static_cast<uint32_t>(PartyStateChangeResult::NetworkLimitReached));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_NETWORK_NO_LONGER_EXISTS == static_cast<uint32_t>(PartyStateChangeResult::NetworkNoLongerExists));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_NETWORK_NOT_JOINABLE == static_cast<uint32_t>(PartyStateChangeResult::NetworkNotJoinable));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_VERSION_MISMATCH == static_cast<uint32_t>(PartyStateChangeResult::VersionMismatch));
C_ASSERT(PARTY_STATE_CHANGE_RESULT_LEAVE_NETWORK_CALLED == static_cast<uint32_t>(PartyStateChangeResult::LeaveNetworkCalled));

C_ASSERT(PARTY_LOCAL_USER_REMOVED_REASON_AUTHENTICATION_FAILED == static_cast<uint32_t>(PartyLocalUserRemovedReason::AuthenticationFailed));
C_ASSERT(PARTY_LOCAL_USER_REMOVED_REASON_REMOVE_LOCAL_USER == static_cast<uint32_t>(PartyLocalUserRemovedReason::RemoveLocalUser));
C_ASSERT(PARTY_LOCAL_USER_REMOVED_REASON_DESTROY_LOCAL_USER == static_cast<uint32_t>(PartyLocalUserRemovedReason::DestroyLocalUser));
C_ASSERT(PARTY_LOCAL_USER_REMOVED_REASON_DESTROY_NETWORK == static_cast<uint32_t>(PartyLocalUserRemovedReason::DestroyNetwork));

C_ASSERT(PARTY_DESTROYED_REASON_REQUESTED == static_cast<uint32_t>(PartyDestroyedReason::Requested));
C_ASSERT(PARTY_DESTROYED_REASON_DISCONNECTED == static_cast<uint32_t>(PartyDestroyedReason::Disconnected));
C_ASSERT(PARTY_DESTROYED_REASON_KICKED == static_cast<uint32_t>(PartyDestroyedReason::Kicked));
C_ASSERT(PARTY_DESTROYED_REASON_DEVICE_LOST_AUTHENTICATION == static_cast<uint32_t>(PartyDestroyedReason::DeviceLostAuthentication));
C_ASSERT(PARTY_DESTROYED_REASON_CREATION_FAILED == static_cast<uint32_t>(PartyDestroyedReason::CreationFailed));

C_ASSERT(PARTY_THREAD_ID_AUDIO == static_cast<uint32_t>(PartyThreadId::Audio));
C_ASSERT(PARTY_THREAD_ID_NETWORKING == static_cast<uint32_t>(PartyThreadId::Networking));

C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_DEFAULT == static_cast<uint32_t>(PartySendMessageOptions::Default));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_GUARANTEED_DELIVERY == static_cast<uint32_t>(PartySendMessageOptions::GuaranteedDelivery));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_BEST_EFFORT_DELIVERY == static_cast<uint32_t>(PartySendMessageOptions::BestEffortDelivery));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_SEQUENTIAL_DELIVERY == static_cast<uint32_t>(PartySendMessageOptions::SequentialDelivery));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_NONSEQUENTIAL_DELIVERY == static_cast<uint32_t>(PartySendMessageOptions::NonsequentialDelivery));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_COPY_DATA_BUFFERS == static_cast<uint32_t>(PartySendMessageOptions::CopyDataBuffers));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_DONT_COPY_DATA_BUFFERS == static_cast<uint32_t>(PartySendMessageOptions::DontCopyDataBuffers));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_COALESCE_OPPORTUNISTICALLY == static_cast<uint32_t>(PartySendMessageOptions::CoalesceOpportunistically));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_ALWAYS_COALESCE_UNTIL_FLUSHED == static_cast<uint32_t>(PartySendMessageOptions::AlwaysCoalesceUntilFlushed));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_REQUIRE_TIMELY_ACKNOWLEDGEMENT == static_cast<uint32_t>(PartySendMessageOptions::RequireTimelyAcknowledgement));
C_ASSERT(PARTY_SEND_MESSAGE_OPTIONS_ALLOW_LAZY_ACKNOWLEDGEMENT == static_cast<uint32_t>(PartySendMessageOptions::AllowLazyAcknowledgement));

C_ASSERT(PARTY_MESSAGE_RECEIVED_OPTIONS_NONE == static_cast<uint32_t>(PartyMessageReceivedOptions::None));
C_ASSERT(PARTY_MESSAGE_RECEIVED_OPTIONS_GUARANTEED_DELIVERY == static_cast<uint32_t>(PartyMessageReceivedOptions::GuaranteedDelivery));
C_ASSERT(PARTY_MESSAGE_RECEIVED_OPTIONS_SEQUENTIAL_DELIVERY == static_cast<uint32_t>(PartyMessageReceivedOptions::SequentialDelivery));
C_ASSERT(PARTY_MESSAGE_RECEIVED_OPTIONS_REQUIRED_FRAGMENTATION == static_cast<uint32_t>(PartyMessageReceivedOptions::RequiredFragmentation));

C_ASSERT(PARTY_CANCEL_MESSAGES_FILTER_EXPRESSION_NONE == static_cast<uint32_t>(PartyCancelMessagesFilterExpression::None));
C_ASSERT(PARTY_CANCEL_MESSAGES_FILTER_EXPRESSION_IDENTITY_AND_MASK_EQUALS_MATCH_VALUE == static_cast<uint32_t>(PartyCancelMessagesFilterExpression::IdentityAndMaskEqualsMatchValue));
C_ASSERT(PARTY_CANCEL_MESSAGES_FILTER_EXPRESSION_IDENTITY_AND_MASK_DOES_NOT_EQUAL_MATCH_VALUE == static_cast<uint32_t>(PartyCancelMessagesFilterExpression::IdentityAndMaskDoesNotEqualMatchValue));

C_ASSERT(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_OPTIONS_NONE == static_cast<uint32_t>(PartySynchronizeMessagesBetweenEndpointsOptions::None));
C_ASSERT(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_OPTIONS_SYNCHRONIZE_MESSAGES_WITH_SHARED_PROPERTIES == static_cast<uint32_t>(PartySynchronizeMessagesBetweenEndpointsOptions::SynchronizeMessagesWithSharedProperties));

C_ASSERT(PARTY_NETWORK_STATISTIC_AVERAGE_RELAY_SERVER_ROUND_TRIP_LATENCY_IN_MILLISECONDS == static_cast<uint32_t>(PartyNetworkStatistic::AverageRelayServerRoundTripLatencyInMilliseconds));
C_ASSERT(PARTY_NETWORK_STATISTIC_SENT_PROTOCOL_PACKETS == static_cast<uint32_t>(PartyNetworkStatistic::SentProtocolPackets));
C_ASSERT(PARTY_NETWORK_STATISTIC_SENT_PROTOCOL_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::SentProtocolBytes));
C_ASSERT(PARTY_NETWORK_STATISTIC_RETRIED_PROTOCOL_PACKETS == static_cast<uint32_t>(PartyNetworkStatistic::RetriedProtocolPackets));
C_ASSERT(PARTY_NETWORK_STATISTIC_RETRIED_PROTOCOL_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::RetriedProtocolBytes));
C_ASSERT(PARTY_NETWORK_STATISTIC_DROPPED_PROTOCOL_PACKETS == static_cast<uint32_t>(PartyNetworkStatistic::DroppedProtocolPackets));
C_ASSERT(PARTY_NETWORK_STATISTIC_RECEIVED_PROTOCOL_PACKETS == static_cast<uint32_t>(PartyNetworkStatistic::ReceivedProtocolPackets));
C_ASSERT(PARTY_NETWORK_STATISTIC_RECEIVED_PROTOCOL_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::ReceivedProtocolBytes));
C_ASSERT(PARTY_NETWORK_STATISTIC_CURRENTLY_QUEUED_SEND_MESSAGES == static_cast<uint32_t>(PartyNetworkStatistic::CurrentlyQueuedSendMessages));
C_ASSERT(PARTY_NETWORK_STATISTIC_CURRENTLY_QUEUED_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::CurrentlyQueuedSendMessageBytes));
C_ASSERT(PARTY_NETWORK_STATISTIC_CURRENTLY_ACTIVE_SEND_MESSAGES == static_cast<uint32_t>(PartyNetworkStatistic::CurrentlyActiveSendMessages));
C_ASSERT(PARTY_NETWORK_STATISTIC_CURRENTLY_ACTIVE_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::CurrentlyActiveSendMessageBytes));
C_ASSERT(PARTY_NETWORK_STATISTIC_TIMED_OUT_SEND_MESSAGES == static_cast<uint32_t>(PartyNetworkStatistic::TimedOutSendMessages));
C_ASSERT(PARTY_NETWORK_STATISTIC_TIMED_OUT_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::TimedOutSendMessageBytes));
C_ASSERT(PARTY_NETWORK_STATISTIC_CANCELED_SEND_MESSAGES == static_cast<uint32_t>(PartyNetworkStatistic::CanceledSendMessages));
C_ASSERT(PARTY_NETWORK_STATISTIC_CANCELED_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyNetworkStatistic::CanceledSendMessageBytes));

C_ASSERT(PARTY_ENDPOINT_STATISTIC_CURRENTLY_QUEUED_SEND_MESSAGES == static_cast<uint32_t>(PartyEndpointStatistic::CurrentlyQueuedSendMessages));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_CURRENTLY_QUEUED_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyEndpointStatistic::CurrentlyQueuedSendMessageBytes));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_CURRENTLY_ACTIVE_SEND_MESSAGES == static_cast<uint32_t>(PartyEndpointStatistic::CurrentlyActiveSendMessages));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_CURRENTLY_ACTIVE_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyEndpointStatistic::CurrentlyActiveSendMessageBytes));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_TIMED_OUT_SEND_MESSAGES == static_cast<uint32_t>(PartyEndpointStatistic::TimedOutSendMessages));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_TIMED_OUT_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyEndpointStatistic::TimedOutSendMessageBytes));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_CANCELED_SEND_MESSAGES == static_cast<uint32_t>(PartyEndpointStatistic::CanceledSendMessages));
C_ASSERT(PARTY_ENDPOINT_STATISTIC_CANCELED_SEND_MESSAGE_BYTES == static_cast<uint32_t>(PartyEndpointStatistic::CanceledSendMessageBytes));

C_ASSERT(PARTY_INVITATION_REVOCABILITY_CREATOR == static_cast<uint32_t>(PartyInvitationRevocability::Creator));
C_ASSERT(PARTY_INVITATION_REVOCABILITY_ANYONE == static_cast<uint32_t>(PartyInvitationRevocability::Anyone));

C_ASSERT(PARTY_CHAT_PERMISSION_OPTIONS_NONE == static_cast<uint32_t>(PartyChatPermissionOptions::None));
C_ASSERT(PARTY_CHAT_PERMISSION_OPTIONS_SEND_AUDIO == static_cast<uint32_t>(PartyChatPermissionOptions::SendAudio));
C_ASSERT(PARTY_CHAT_PERMISSION_OPTIONS_RECEIVE_AUDIO == static_cast<uint32_t>(PartyChatPermissionOptions::ReceiveAudio));
C_ASSERT(PARTY_CHAT_PERMISSION_OPTIONS_RECEIVE_TEXT == static_cast<uint32_t>(PartyChatPermissionOptions::ReceiveText));

C_ASSERT(PARTY_AUDIO_DEVICE_SELECTION_TYPE_NONE == static_cast<uint32_t>(PartyAudioDeviceSelectionType::None));
C_ASSERT(PARTY_AUDIO_DEVICE_SELECTION_TYPE_SYSTEM_DEFAULT == static_cast<uint32_t>(PartyAudioDeviceSelectionType::SystemDefault));
C_ASSERT(PARTY_AUDIO_DEVICE_SELECTION_TYPE_PLATFORM_USER_DEFAULT == static_cast<uint32_t>(PartyAudioDeviceSelectionType::PlatformUserDefault));
C_ASSERT(PARTY_AUDIO_DEVICE_SELECTION_TYPE_MANUAL == static_cast<uint32_t>(PartyAudioDeviceSelectionType::Manual));

C_ASSERT(PARTY_AUDIO_INPUT_STATE_NO_INPUT == static_cast<uint32_t>(PartyAudioInputState::NoInput));
C_ASSERT(PARTY_AUDIO_INPUT_STATE_INITIALIZED == static_cast<uint32_t>(PartyAudioInputState::Initialized));
C_ASSERT(PARTY_AUDIO_INPUT_STATE_NOT_FOUND == static_cast<uint32_t>(PartyAudioInputState::NotFound));
C_ASSERT(PARTY_AUDIO_INPUT_STATE_USER_CONSENT_DENIED == static_cast<uint32_t>(PartyAudioInputState::UserConsentDenied));
C_ASSERT(PARTY_AUDIO_INPUT_STATE_UNSUPPORTED_FORMAT == static_cast<uint32_t>(PartyAudioInputState::UnsupportedFormat));
C_ASSERT(PARTY_AUDIO_INPUT_STATE_ALREADY_IN_USE == static_cast<uint32_t>(PartyAudioInputState::AlreadyInUse));
C_ASSERT(PARTY_AUDIO_INPUT_STATE_UNKNOWN_ERROR == static_cast<uint32_t>(PartyAudioInputState::UnknownError));

C_ASSERT(PARTY_AUDIO_OUTPUT_STATE_NO_OUTPUT == static_cast<uint32_t>(PartyAudioOutputState::NoOutput));
C_ASSERT(PARTY_AUDIO_OUTPUT_STATE_INITIALIZED == static_cast<uint32_t>(PartyAudioOutputState::Initialized));
C_ASSERT(PARTY_AUDIO_OUTPUT_STATE_NOT_FOUND == static_cast<uint32_t>(PartyAudioOutputState::NotFound));
C_ASSERT(PARTY_AUDIO_OUTPUT_STATE_UNSUPPORTED_FORMAT == static_cast<uint32_t>(PartyAudioOutputState::UnsupportedFormat));
C_ASSERT(PARTY_AUDIO_OUTPUT_STATE_ALREADY_IN_USE == static_cast<uint32_t>(PartyAudioOutputState::AlreadyInUse));
C_ASSERT(PARTY_AUDIO_OUTPUT_STATE_UNKNOWN_ERROR == static_cast<uint32_t>(PartyAudioOutputState::UnknownError));

C_ASSERT(PARTY_LOCAL_CHAT_CONTROL_CHAT_INDICATOR_SILENT == static_cast<uint32_t>(PartyLocalChatControlChatIndicator::Silent));
C_ASSERT(PARTY_LOCAL_CHAT_CONTROL_CHAT_INDICATOR_TALKING == static_cast<uint32_t>(PartyLocalChatControlChatIndicator::Talking));
C_ASSERT(PARTY_LOCAL_CHAT_CONTROL_CHAT_INDICATOR_AUDIO_INPUT_MUTED == static_cast<uint32_t>(PartyLocalChatControlChatIndicator::AudioInputMuted));
C_ASSERT(PARTY_LOCAL_CHAT_CONTROL_CHAT_INDICATOR_NO_AUDIO_INPUT == static_cast<uint32_t>(PartyLocalChatControlChatIndicator::NoAudioInput));

C_ASSERT(PARTY_CHAT_CONTROL_CHAT_INDICATOR_SILENT == static_cast<uint32_t>(PartyChatControlChatIndicator::Silent));
C_ASSERT(PARTY_CHAT_CONTROL_CHAT_INDICATOR_TALKING == static_cast<uint32_t>(PartyChatControlChatIndicator::Talking));
C_ASSERT(PARTY_CHAT_CONTROL_CHAT_INDICATOR_INCOMING_VOICE_DISABLED == static_cast<uint32_t>(PartyChatControlChatIndicator::IncomingVoiceDisabled));
C_ASSERT(PARTY_CHAT_CONTROL_CHAT_INDICATOR_INCOMING_COMMUNICATIONS_MUTED == static_cast<uint32_t>(PartyChatControlChatIndicator::IncomingCommunicationsMuted));

C_ASSERT(PARTY_GENDER_NEUTRAL == static_cast<uint32_t>(PartyGender::Neutral));
C_ASSERT(PARTY_GENDER_FEMALE == static_cast<uint32_t>(PartyGender::Female));
C_ASSERT(PARTY_GENDER_MALE == static_cast<uint32_t>(PartyGender::Male));

C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_PHRASE_TYPE_HYPOTHESIS == static_cast<uint32_t>(PartyVoiceChatTranscriptionPhraseType::Hypothesis));
C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_PHRASE_TYPE_FINAL == static_cast<uint32_t>(PartyVoiceChatTranscriptionPhraseType::Final));

C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS_NONE == static_cast<uint32_t>(PartyVoiceChatTranscriptionOptions::None));
C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS_TRANSCRIBE_SELF == static_cast<uint32_t>(PartyVoiceChatTranscriptionOptions::TranscribeSelf));
C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS_TRANSCRIBE_OTHER_CHAT_CONTROLS_WITH_MATCHING_LANGUAGES == static_cast<uint32_t>(PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithMatchingLanguages));
C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS_TRANSCRIBE_OTHER_CHAT_CONTROLS_WITH_NON_MATCHING_LANGUAGES == static_cast<uint32_t>(PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithNonMatchingLanguages));
C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS_DISABLE_HYPOTHESIS_PHRASES == static_cast<uint32_t>(PartyVoiceChatTranscriptionOptions::DisableHypothesisPhrases));
C_ASSERT(PARTY_VOICE_CHAT_TRANSCRIPTION_OPTIONS_TRANSLATE_TO_LOCAL_LANGUAGE == static_cast<uint32_t>(PartyVoiceChatTranscriptionOptions::TranslateToLocalLanguage));

C_ASSERT(PARTY_TEXT_CHAT_OPTIONS_NONE == static_cast<uint32_t>(PartyTextChatOptions::None));
C_ASSERT(PARTY_TEXT_CHAT_OPTIONS_TRANSLATE_TO_LOCAL_LANGUAGE == static_cast<uint32_t>(PartyTextChatOptions::TranslateToLocalLanguage));

C_ASSERT(PARTY_TRANSLATION_RECEIVED_OPTIONS_NONE == static_cast<uint32_t>(PartyTranslationReceivedOptions::None));
C_ASSERT(PARTY_TRANSLATION_RECEIVED_OPTIONS_TRUNCATED == static_cast<uint32_t>(PartyTranslationReceivedOptions::Truncated));

C_ASSERT(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_TYPE_NARRATION == static_cast<uint32_t>(PartySynthesizeTextToSpeechType::Narration));
C_ASSERT(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_TYPE_VOICE_CHAT == static_cast<uint32_t>(PartySynthesizeTextToSpeechType::VoiceChat));

C_ASSERT(sizeof(PARTY_NETWORK_DESCRIPTOR) == sizeof(PartyNetworkDescriptor));
C_ASSERT(sizeof(PARTY_NETWORK_DESCRIPTOR::networkIdentifier) == sizeof(PartyNetworkDescriptor::networkIdentifier));
C_ASSERT(offsetof(PARTY_NETWORK_DESCRIPTOR, networkIdentifier) == offsetof(PartyNetworkDescriptor, networkIdentifier));
C_ASSERT(sizeof(PARTY_NETWORK_DESCRIPTOR::regionName) == sizeof(PartyNetworkDescriptor::regionName));
C_ASSERT(offsetof(PARTY_NETWORK_DESCRIPTOR, regionName) == offsetof(PartyNetworkDescriptor, regionName));
C_ASSERT(sizeof(PARTY_NETWORK_DESCRIPTOR::opaqueConnectionInformation) == sizeof(PartyNetworkDescriptor::opaqueConnectionInformation));
C_ASSERT(offsetof(PARTY_NETWORK_DESCRIPTOR, opaqueConnectionInformation) == offsetof(PartyNetworkDescriptor, opaqueConnectionInformation));

C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION) == sizeof(PartyNetworkConfiguration));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION::maxUserCount) == sizeof(PartyNetworkConfiguration::maxUserCount));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION, maxUserCount) == offsetof(PartyNetworkConfiguration, maxUserCount));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION::maxDeviceCount) == sizeof(PartyNetworkConfiguration::maxDeviceCount));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION, maxDeviceCount) == offsetof(PartyNetworkConfiguration, maxDeviceCount));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION::maxUsersPerDeviceCount) == sizeof(PartyNetworkConfiguration::maxUsersPerDeviceCount));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION, maxUsersPerDeviceCount) == offsetof(PartyNetworkConfiguration, maxUsersPerDeviceCount));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION::maxDevicesPerUserCount) == sizeof(PartyNetworkConfiguration::maxDevicesPerUserCount));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION, maxDevicesPerUserCount) == offsetof(PartyNetworkConfiguration, maxDevicesPerUserCount));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION::maxEndpointsPerDeviceCount) == sizeof(PartyNetworkConfiguration::maxEndpointsPerDeviceCount));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION, maxEndpointsPerDeviceCount) == offsetof(PartyNetworkConfiguration, maxEndpointsPerDeviceCount));

C_ASSERT(sizeof(PARTY_REGION) == sizeof(PartyRegion));
C_ASSERT(sizeof(PARTY_REGION::regionName) == sizeof(PartyRegion::regionName));
C_ASSERT(offsetof(PARTY_REGION, regionName) == offsetof(PartyRegion, regionName));
C_ASSERT(sizeof(PARTY_REGION::roundTripLatencyInMilliseconds) == sizeof(PartyRegion::roundTripLatencyInMilliseconds));
C_ASSERT(offsetof(PARTY_REGION, roundTripLatencyInMilliseconds) == offsetof(PartyRegion, roundTripLatencyInMilliseconds));

C_ASSERT(sizeof(PARTY_INVITATION_CONFIGURATION) == sizeof(PartyInvitationConfiguration));
C_ASSERT(sizeof(PARTY_INVITATION_CONFIGURATION::identifier) == sizeof(PartyInvitationConfiguration::identifier));
C_ASSERT(offsetof(PARTY_INVITATION_CONFIGURATION, identifier) == offsetof(PartyInvitationConfiguration, identifier));
C_ASSERT(sizeof(PARTY_INVITATION_CONFIGURATION::revocability) == sizeof(PartyInvitationConfiguration::revocability));
C_ASSERT(offsetof(PARTY_INVITATION_CONFIGURATION, revocability) == offsetof(PartyInvitationConfiguration, revocability));
C_ASSERT(sizeof(PARTY_INVITATION_CONFIGURATION::entityIdCount) == sizeof(PartyInvitationConfiguration::entityIdCount));
C_ASSERT(offsetof(PARTY_INVITATION_CONFIGURATION, entityIdCount) == offsetof(PartyInvitationConfiguration, entityIdCount));
C_ASSERT(sizeof(PARTY_INVITATION_CONFIGURATION::entityIds) == sizeof(PartyInvitationConfiguration::entityIds));
C_ASSERT(offsetof(PARTY_INVITATION_CONFIGURATION, entityIds) == offsetof(PartyInvitationConfiguration, entityIds));

C_ASSERT(sizeof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION) == sizeof(PartySendMessageQueuingConfiguration));
C_ASSERT(sizeof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION::priority) == sizeof(PartySendMessageQueuingConfiguration::priority));
C_ASSERT(offsetof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION, priority) == offsetof(PartySendMessageQueuingConfiguration, priority));
C_ASSERT(sizeof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION::identityForCancelFilters) == sizeof(PartySendMessageQueuingConfiguration::identityForCancelFilters));
C_ASSERT(offsetof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION, identityForCancelFilters) == offsetof(PartySendMessageQueuingConfiguration, identityForCancelFilters));
C_ASSERT(sizeof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION::timeoutInMilliseconds) == sizeof(PartySendMessageQueuingConfiguration::timeoutInMilliseconds));
C_ASSERT(offsetof(PARTY_SEND_MESSAGE_QUEUING_CONFIGURATION, timeoutInMilliseconds) == offsetof(PartySendMessageQueuingConfiguration, timeoutInMilliseconds));

C_ASSERT(sizeof(PARTY_DATA_BUFFER) == sizeof(PartyDataBuffer));
C_ASSERT(sizeof(PARTY_DATA_BUFFER::buffer) == sizeof(PartyDataBuffer::buffer));
C_ASSERT(offsetof(PARTY_DATA_BUFFER, buffer) == offsetof(PartyDataBuffer, buffer));
C_ASSERT(sizeof(PARTY_DATA_BUFFER::bufferByteCount) == sizeof(PartyDataBuffer::bufferByteCount));
C_ASSERT(offsetof(PARTY_DATA_BUFFER, bufferByteCount) == offsetof(PartyDataBuffer, bufferByteCount));

C_ASSERT(sizeof(PARTY_TRANSLATION) == sizeof(PartyTranslation));
C_ASSERT(sizeof(PARTY_TRANSLATION::result) == sizeof(PartyTranslation::result));
C_ASSERT(offsetof(PARTY_TRANSLATION, result) == offsetof(PartyTranslation, result));
C_ASSERT(sizeof(PARTY_TRANSLATION::errorDetail) == sizeof(PartyTranslation::errorDetail));
C_ASSERT(offsetof(PARTY_TRANSLATION, errorDetail) == offsetof(PartyTranslation, errorDetail));
C_ASSERT(sizeof(PARTY_TRANSLATION::languageCode) == sizeof(PartyTranslation::languageCode));
C_ASSERT(offsetof(PARTY_TRANSLATION, languageCode) == offsetof(PartyTranslation, languageCode));
C_ASSERT(sizeof(PARTY_TRANSLATION::options) == sizeof(PartyTranslation::options));
C_ASSERT(offsetof(PARTY_TRANSLATION, options) == offsetof(PartyTranslation, options));
C_ASSERT(sizeof(PARTY_TRANSLATION::translation) == sizeof(PartyTranslation::translation));
C_ASSERT(offsetof(PARTY_TRANSLATION, translation) == offsetof(PartyTranslation, translation));

C_ASSERT(sizeof(PARTY_STATE_CHANGE) == sizeof(PartyStateChange));
C_ASSERT(sizeof(PARTY_STATE_CHANGE::stateChangeType) == sizeof(PartyStateChange::stateChangeType));
C_ASSERT(offsetof(PARTY_STATE_CHANGE, stateChangeType) == offsetof(PartyStateChange, stateChangeType));

C_ASSERT(sizeof(PARTY_REGIONS_CHANGED_STATE_CHANGE) == sizeof(PartyRegionsChangedStateChange));
C_ASSERT(sizeof(PARTY_REGIONS_CHANGED_STATE_CHANGE::result) == sizeof(PartyRegionsChangedStateChange::result));
C_ASSERT(offsetof(PARTY_REGIONS_CHANGED_STATE_CHANGE, result) == offsetof(PartyRegionsChangedStateChange, result));
C_ASSERT(sizeof(PARTY_REGIONS_CHANGED_STATE_CHANGE::errorDetail) == sizeof(PartyRegionsChangedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_REGIONS_CHANGED_STATE_CHANGE, errorDetail) == offsetof(PartyRegionsChangedStateChange, errorDetail));

C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE) == sizeof(PartyCreateNewNetworkCompletedStateChange));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::result) == sizeof(PartyCreateNewNetworkCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, result) == offsetof(PartyCreateNewNetworkCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyCreateNewNetworkCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyCreateNewNetworkCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyCreateNewNetworkCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyCreateNewNetworkCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::networkConfiguration) == sizeof(PartyCreateNewNetworkCompletedStateChange::networkConfiguration));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, networkConfiguration) == offsetof(PartyCreateNewNetworkCompletedStateChange, networkConfiguration));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::regionCount) == sizeof(PartyCreateNewNetworkCompletedStateChange::regionCount));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, regionCount) == offsetof(PartyCreateNewNetworkCompletedStateChange, regionCount));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::regions) == sizeof(PartyCreateNewNetworkCompletedStateChange::regions));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, regions) == offsetof(PartyCreateNewNetworkCompletedStateChange, regions));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyCreateNewNetworkCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyCreateNewNetworkCompletedStateChange, asyncIdentifier));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::networkDescriptor) == sizeof(PartyCreateNewNetworkCompletedStateChange::networkDescriptor));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, networkDescriptor) == offsetof(PartyCreateNewNetworkCompletedStateChange, networkDescriptor));
C_ASSERT(sizeof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE::appliedInitialInvitationIdentifier) == sizeof(PartyCreateNewNetworkCompletedStateChange::appliedInitialInvitationIdentifier));
C_ASSERT(offsetof(PARTY_CREATE_NEW_NETWORK_COMPLETED_STATE_CHANGE, appliedInitialInvitationIdentifier) == offsetof(PartyCreateNewNetworkCompletedStateChange, appliedInitialInvitationIdentifier));

C_ASSERT(sizeof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE) == sizeof(PartyConnectToNetworkCompletedStateChange));
C_ASSERT(sizeof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE::result) == sizeof(PartyConnectToNetworkCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE, result) == offsetof(PartyConnectToNetworkCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyConnectToNetworkCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyConnectToNetworkCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE::networkDescriptor) == sizeof(PartyConnectToNetworkCompletedStateChange::networkDescriptor));
C_ASSERT(offsetof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE, networkDescriptor) == offsetof(PartyConnectToNetworkCompletedStateChange, networkDescriptor));
C_ASSERT(sizeof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyConnectToNetworkCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyConnectToNetworkCompletedStateChange, asyncIdentifier));
C_ASSERT(sizeof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE::network) == sizeof(PartyConnectToNetworkCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_CONNECT_TO_NETWORK_COMPLETED_STATE_CHANGE, network) == offsetof(PartyConnectToNetworkCompletedStateChange, network));

C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE) == sizeof(PartyAuthenticateLocalUserCompletedStateChange));
C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE::result) == sizeof(PartyAuthenticateLocalUserCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE, result) == offsetof(PartyAuthenticateLocalUserCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyAuthenticateLocalUserCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyAuthenticateLocalUserCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE::network) == sizeof(PartyAuthenticateLocalUserCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE, network) == offsetof(PartyAuthenticateLocalUserCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyAuthenticateLocalUserCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyAuthenticateLocalUserCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE::invitationIdentifier) == sizeof(PartyAuthenticateLocalUserCompletedStateChange::invitationIdentifier));
C_ASSERT(offsetof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE, invitationIdentifier) == offsetof(PartyAuthenticateLocalUserCompletedStateChange, invitationIdentifier));
C_ASSERT(sizeof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyAuthenticateLocalUserCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_AUTHENTICATE_LOCAL_USER_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyAuthenticateLocalUserCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION_MADE_AVAILABLE_STATE_CHANGE) == sizeof(PartyNetworkConfigurationMadeAvailableStateChange));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION_MADE_AVAILABLE_STATE_CHANGE::network) == sizeof(PartyNetworkConfigurationMadeAvailableStateChange::network));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION_MADE_AVAILABLE_STATE_CHANGE, network) == offsetof(PartyNetworkConfigurationMadeAvailableStateChange, network));
C_ASSERT(sizeof(PARTY_NETWORK_CONFIGURATION_MADE_AVAILABLE_STATE_CHANGE::networkConfiguration) == sizeof(PartyNetworkConfigurationMadeAvailableStateChange::networkConfiguration));
C_ASSERT(offsetof(PARTY_NETWORK_CONFIGURATION_MADE_AVAILABLE_STATE_CHANGE, networkConfiguration) == offsetof(PartyNetworkConfigurationMadeAvailableStateChange, networkConfiguration));

C_ASSERT(sizeof(PARTY_NETWORK_DESCRIPTOR_CHANGED_STATE_CHANGE) == sizeof(PartyNetworkDescriptorChangedStateChange));
C_ASSERT(sizeof(PARTY_NETWORK_DESCRIPTOR_CHANGED_STATE_CHANGE::network) == sizeof(PartyNetworkDescriptorChangedStateChange::network));
C_ASSERT(offsetof(PARTY_NETWORK_DESCRIPTOR_CHANGED_STATE_CHANGE, network) == offsetof(PartyNetworkDescriptorChangedStateChange, network));

C_ASSERT(sizeof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE) == sizeof(PartyLocalUserRemovedStateChange));
C_ASSERT(sizeof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE::network) == sizeof(PartyLocalUserRemovedStateChange::network));
C_ASSERT(offsetof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE, network) == offsetof(PartyLocalUserRemovedStateChange, network));
C_ASSERT(sizeof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE::localUser) == sizeof(PartyLocalUserRemovedStateChange::localUser));
C_ASSERT(offsetof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE, localUser) == offsetof(PartyLocalUserRemovedStateChange, localUser));
C_ASSERT(sizeof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE::removedReason) == sizeof(PartyLocalUserRemovedStateChange::removedReason));
C_ASSERT(offsetof(PARTY_LOCAL_USER_REMOVED_STATE_CHANGE, removedReason) == offsetof(PartyLocalUserRemovedStateChange, removedReason));

C_ASSERT(sizeof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE) == sizeof(PartyRemoveLocalUserCompletedStateChange));
C_ASSERT(sizeof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE::result) == sizeof(PartyRemoveLocalUserCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE, result) == offsetof(PartyRemoveLocalUserCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyRemoveLocalUserCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyRemoveLocalUserCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE::network) == sizeof(PartyRemoveLocalUserCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE, network) == offsetof(PartyRemoveLocalUserCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyRemoveLocalUserCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyRemoveLocalUserCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyRemoveLocalUserCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_REMOVE_LOCAL_USER_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyRemoveLocalUserCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE) == sizeof(PartyDestroyLocalUserCompletedStateChange));
C_ASSERT(sizeof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE::result) == sizeof(PartyDestroyLocalUserCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE, result) == offsetof(PartyDestroyLocalUserCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyDestroyLocalUserCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyDestroyLocalUserCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyDestroyLocalUserCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyDestroyLocalUserCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyDestroyLocalUserCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_DESTROY_LOCAL_USER_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyDestroyLocalUserCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_LOCAL_USER_KICKED_STATE_CHANGE) == sizeof(PartyLocalUserKickedStateChange));
C_ASSERT(sizeof(PARTY_LOCAL_USER_KICKED_STATE_CHANGE::network) == sizeof(PartyLocalUserKickedStateChange::network));
C_ASSERT(offsetof(PARTY_LOCAL_USER_KICKED_STATE_CHANGE, network) == offsetof(PartyLocalUserKickedStateChange, network));
C_ASSERT(sizeof(PARTY_LOCAL_USER_KICKED_STATE_CHANGE::localUser) == sizeof(PartyLocalUserKickedStateChange::localUser));
C_ASSERT(offsetof(PARTY_LOCAL_USER_KICKED_STATE_CHANGE, localUser) == offsetof(PartyLocalUserKickedStateChange, localUser));

C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE) == sizeof(PartyCreateEndpointCompletedStateChange));
C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE::result) == sizeof(PartyCreateEndpointCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE, result) == offsetof(PartyCreateEndpointCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyCreateEndpointCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyCreateEndpointCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE::network) == sizeof(PartyCreateEndpointCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE, network) == offsetof(PartyCreateEndpointCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyCreateEndpointCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyCreateEndpointCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyCreateEndpointCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyCreateEndpointCompletedStateChange, asyncIdentifier));
C_ASSERT(sizeof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE::localEndpoint) == sizeof(PartyCreateEndpointCompletedStateChange::localEndpoint));
C_ASSERT(offsetof(PARTY_CREATE_ENDPOINT_COMPLETED_STATE_CHANGE, localEndpoint) == offsetof(PartyCreateEndpointCompletedStateChange, localEndpoint));

C_ASSERT(sizeof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE) == sizeof(PartyDestroyEndpointCompletedStateChange));
C_ASSERT(sizeof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE::result) == sizeof(PartyDestroyEndpointCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE, result) == offsetof(PartyDestroyEndpointCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyDestroyEndpointCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyDestroyEndpointCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE::network) == sizeof(PartyDestroyEndpointCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE, network) == offsetof(PartyDestroyEndpointCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE::localEndpoint) == sizeof(PartyDestroyEndpointCompletedStateChange::localEndpoint));
C_ASSERT(offsetof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE, localEndpoint) == offsetof(PartyDestroyEndpointCompletedStateChange, localEndpoint));
C_ASSERT(sizeof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyDestroyEndpointCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_DESTROY_ENDPOINT_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyDestroyEndpointCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_ENDPOINT_CREATED_STATE_CHANGE) == sizeof(PartyEndpointCreatedStateChange));
C_ASSERT(sizeof(PARTY_ENDPOINT_CREATED_STATE_CHANGE::network) == sizeof(PartyEndpointCreatedStateChange::network));
C_ASSERT(offsetof(PARTY_ENDPOINT_CREATED_STATE_CHANGE, network) == offsetof(PartyEndpointCreatedStateChange, network));
C_ASSERT(sizeof(PARTY_ENDPOINT_CREATED_STATE_CHANGE::endpoint) == sizeof(PartyEndpointCreatedStateChange::endpoint));
C_ASSERT(offsetof(PARTY_ENDPOINT_CREATED_STATE_CHANGE, endpoint) == offsetof(PartyEndpointCreatedStateChange, endpoint));

C_ASSERT(sizeof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE) == sizeof(PartyEndpointDestroyedStateChange));
C_ASSERT(sizeof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE::network) == sizeof(PartyEndpointDestroyedStateChange::network));
C_ASSERT(offsetof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE, network) == offsetof(PartyEndpointDestroyedStateChange, network));
C_ASSERT(sizeof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE::endpoint) == sizeof(PartyEndpointDestroyedStateChange::endpoint));
C_ASSERT(offsetof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE, endpoint) == offsetof(PartyEndpointDestroyedStateChange, endpoint));
C_ASSERT(sizeof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE::reason) == sizeof(PartyEndpointDestroyedStateChange::reason));
C_ASSERT(offsetof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE, reason) == offsetof(PartyEndpointDestroyedStateChange, reason));
C_ASSERT(sizeof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE::errorDetail) == sizeof(PartyEndpointDestroyedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_ENDPOINT_DESTROYED_STATE_CHANGE, errorDetail) == offsetof(PartyEndpointDestroyedStateChange, errorDetail));

C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_CREATED_STATE_CHANGE) == sizeof(PartyRemoteDeviceCreatedStateChange));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_CREATED_STATE_CHANGE::device) == sizeof(PartyRemoteDeviceCreatedStateChange::device));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_CREATED_STATE_CHANGE, device) == offsetof(PartyRemoteDeviceCreatedStateChange, device));

C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_DESTROYED_STATE_CHANGE) == sizeof(PartyRemoteDeviceDestroyedStateChange));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_DESTROYED_STATE_CHANGE::device) == sizeof(PartyRemoteDeviceDestroyedStateChange::device));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_DESTROYED_STATE_CHANGE, device) == offsetof(PartyRemoteDeviceDestroyedStateChange, device));

C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_JOINED_NETWORK_STATE_CHANGE) == sizeof(PartyRemoteDeviceJoinedNetworkStateChange));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_JOINED_NETWORK_STATE_CHANGE::device) == sizeof(PartyRemoteDeviceJoinedNetworkStateChange::device));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_JOINED_NETWORK_STATE_CHANGE, device) == offsetof(PartyRemoteDeviceJoinedNetworkStateChange, device));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_JOINED_NETWORK_STATE_CHANGE::network) == sizeof(PartyRemoteDeviceJoinedNetworkStateChange::network));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_JOINED_NETWORK_STATE_CHANGE, network) == offsetof(PartyRemoteDeviceJoinedNetworkStateChange, network));

C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE) == sizeof(PartyRemoteDeviceLeftNetworkStateChange));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE::reason) == sizeof(PartyRemoteDeviceLeftNetworkStateChange::reason));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE, reason) == offsetof(PartyRemoteDeviceLeftNetworkStateChange, reason));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE::errorDetail) == sizeof(PartyRemoteDeviceLeftNetworkStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE, errorDetail) == offsetof(PartyRemoteDeviceLeftNetworkStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE::device) == sizeof(PartyRemoteDeviceLeftNetworkStateChange::device));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE, device) == offsetof(PartyRemoteDeviceLeftNetworkStateChange, device));
C_ASSERT(sizeof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE::network) == sizeof(PartyRemoteDeviceLeftNetworkStateChange::network));
C_ASSERT(offsetof(PARTY_REMOTE_DEVICE_LEFT_NETWORK_STATE_CHANGE, network) == offsetof(PartyRemoteDeviceLeftNetworkStateChange, network));

C_ASSERT(sizeof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE) == sizeof(PartyDevicePropertiesChangedStateChange));
C_ASSERT(sizeof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE::device) == sizeof(PartyDevicePropertiesChangedStateChange::device));
C_ASSERT(offsetof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE, device) == offsetof(PartyDevicePropertiesChangedStateChange, device));
C_ASSERT(sizeof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE::propertyCount) == sizeof(PartyDevicePropertiesChangedStateChange::propertyCount));
C_ASSERT(offsetof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE, propertyCount) == offsetof(PartyDevicePropertiesChangedStateChange, propertyCount));
C_ASSERT(sizeof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE::keys) == sizeof(PartyDevicePropertiesChangedStateChange::keys));
C_ASSERT(offsetof(PARTY_DEVICE_PROPERTIES_CHANGED_STATE_CHANGE, keys) == offsetof(PartyDevicePropertiesChangedStateChange, keys));

C_ASSERT(sizeof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE) == sizeof(PartyLeaveNetworkCompletedStateChange));
C_ASSERT(sizeof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE::result) == sizeof(PartyLeaveNetworkCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE, result) == offsetof(PartyLeaveNetworkCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyLeaveNetworkCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyLeaveNetworkCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE::network) == sizeof(PartyLeaveNetworkCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE, network) == offsetof(PartyLeaveNetworkCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyLeaveNetworkCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_LEAVE_NETWORK_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyLeaveNetworkCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_NETWORK_DESTROYED_STATE_CHANGE) == sizeof(PartyNetworkDestroyedStateChange));
C_ASSERT(sizeof(PARTY_NETWORK_DESTROYED_STATE_CHANGE::reason) == sizeof(PartyNetworkDestroyedStateChange::reason));
C_ASSERT(offsetof(PARTY_NETWORK_DESTROYED_STATE_CHANGE, reason) == offsetof(PartyNetworkDestroyedStateChange, reason));
C_ASSERT(sizeof(PARTY_NETWORK_DESTROYED_STATE_CHANGE::errorDetail) == sizeof(PartyNetworkDestroyedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_NETWORK_DESTROYED_STATE_CHANGE, errorDetail) == offsetof(PartyNetworkDestroyedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_NETWORK_DESTROYED_STATE_CHANGE::network) == sizeof(PartyNetworkDestroyedStateChange::network));
C_ASSERT(offsetof(PARTY_NETWORK_DESTROYED_STATE_CHANGE, network) == offsetof(PartyNetworkDestroyedStateChange, network));

C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE) == sizeof(PartyEndpointMessageReceivedStateChange));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::network) == sizeof(PartyEndpointMessageReceivedStateChange::network));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, network) == offsetof(PartyEndpointMessageReceivedStateChange, network));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::senderEndpoint) == sizeof(PartyEndpointMessageReceivedStateChange::senderEndpoint));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, senderEndpoint) == offsetof(PartyEndpointMessageReceivedStateChange, senderEndpoint));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::receiverEndpointCount) == sizeof(PartyEndpointMessageReceivedStateChange::receiverEndpointCount));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, receiverEndpointCount) == offsetof(PartyEndpointMessageReceivedStateChange, receiverEndpointCount));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::receiverEndpoints) == sizeof(PartyEndpointMessageReceivedStateChange::receiverEndpoints));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, receiverEndpoints) == offsetof(PartyEndpointMessageReceivedStateChange, receiverEndpoints));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::options) == sizeof(PartyEndpointMessageReceivedStateChange::options));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, options) == offsetof(PartyEndpointMessageReceivedStateChange, options));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::messageSize) == sizeof(PartyEndpointMessageReceivedStateChange::messageSize));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, messageSize) == offsetof(PartyEndpointMessageReceivedStateChange, messageSize));
C_ASSERT(sizeof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE::messageBuffer) == sizeof(PartyEndpointMessageReceivedStateChange::messageBuffer));
C_ASSERT(offsetof(PARTY_ENDPOINT_MESSAGE_RECEIVED_STATE_CHANGE, messageBuffer) == offsetof(PartyEndpointMessageReceivedStateChange, messageBuffer));

C_ASSERT(sizeof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE) == sizeof(PartyDataBuffersReturnedStateChange));
C_ASSERT(sizeof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE::network) == sizeof(PartyDataBuffersReturnedStateChange::network));
C_ASSERT(offsetof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE, network) == offsetof(PartyDataBuffersReturnedStateChange, network));
C_ASSERT(sizeof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE::localSenderEndpoint) == sizeof(PartyDataBuffersReturnedStateChange::localSenderEndpoint));
C_ASSERT(offsetof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE, localSenderEndpoint) == offsetof(PartyDataBuffersReturnedStateChange, localSenderEndpoint));
C_ASSERT(sizeof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE::dataBufferCount) == sizeof(PartyDataBuffersReturnedStateChange::dataBufferCount));
C_ASSERT(offsetof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE, dataBufferCount) == offsetof(PartyDataBuffersReturnedStateChange, dataBufferCount));
C_ASSERT(sizeof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE::dataBuffers) == sizeof(PartyDataBuffersReturnedStateChange::dataBuffers));
C_ASSERT(offsetof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE, dataBuffers) == offsetof(PartyDataBuffersReturnedStateChange, dataBuffers));
C_ASSERT(sizeof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE::messageIdentifier) == sizeof(PartyDataBuffersReturnedStateChange::messageIdentifier));
C_ASSERT(offsetof(PARTY_DATA_BUFFERS_RETURNED_STATE_CHANGE, messageIdentifier) == offsetof(PartyDataBuffersReturnedStateChange, messageIdentifier));

C_ASSERT(sizeof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE) == sizeof(PartyEndpointPropertiesChangedStateChange));
C_ASSERT(sizeof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE::endpoint) == sizeof(PartyEndpointPropertiesChangedStateChange::endpoint));
C_ASSERT(offsetof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE, endpoint) == offsetof(PartyEndpointPropertiesChangedStateChange, endpoint));
C_ASSERT(sizeof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE::propertyCount) == sizeof(PartyEndpointPropertiesChangedStateChange::propertyCount));
C_ASSERT(offsetof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE, propertyCount) == offsetof(PartyEndpointPropertiesChangedStateChange, propertyCount));
C_ASSERT(sizeof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE::keys) == sizeof(PartyEndpointPropertiesChangedStateChange::keys));
C_ASSERT(offsetof(PARTY_ENDPOINT_PROPERTIES_CHANGED_STATE_CHANGE, keys) == offsetof(PartyEndpointPropertiesChangedStateChange, keys));

C_ASSERT(sizeof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE) == sizeof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange));
C_ASSERT(sizeof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE::endpointCount) == sizeof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange::endpointCount));
C_ASSERT(offsetof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE, endpointCount) == offsetof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange, endpointCount));
C_ASSERT(sizeof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE::endpoints) == sizeof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange::endpoints));
C_ASSERT(offsetof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE, endpoints) == offsetof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange, endpoints));
C_ASSERT(sizeof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE::options) == sizeof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange::options));
C_ASSERT(offsetof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE, options) == offsetof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange, options));
C_ASSERT(sizeof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SYNCHRONIZE_MESSAGES_BETWEEN_ENDPOINTS_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySynchronizeMessagesBetweenEndpointsCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE) == sizeof(PartyCreateInvitationCompletedStateChange));
C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE::result) == sizeof(PartyCreateInvitationCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE, result) == offsetof(PartyCreateInvitationCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyCreateInvitationCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyCreateInvitationCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE::network) == sizeof(PartyCreateInvitationCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE, network) == offsetof(PartyCreateInvitationCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyCreateInvitationCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyCreateInvitationCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyCreateInvitationCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyCreateInvitationCompletedStateChange, asyncIdentifier));
C_ASSERT(sizeof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE::invitation) == sizeof(PartyCreateInvitationCompletedStateChange::invitation));
C_ASSERT(offsetof(PARTY_CREATE_INVITATION_COMPLETED_STATE_CHANGE, invitation) == offsetof(PartyCreateInvitationCompletedStateChange, invitation));

C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE) == sizeof(PartyRevokeInvitationCompletedStateChange));
C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE::result) == sizeof(PartyRevokeInvitationCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE, result) == offsetof(PartyRevokeInvitationCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyRevokeInvitationCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyRevokeInvitationCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE::network) == sizeof(PartyRevokeInvitationCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE, network) == offsetof(PartyRevokeInvitationCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyRevokeInvitationCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyRevokeInvitationCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE::invitation) == sizeof(PartyRevokeInvitationCompletedStateChange::invitation));
C_ASSERT(offsetof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE, invitation) == offsetof(PartyRevokeInvitationCompletedStateChange, invitation));
C_ASSERT(sizeof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyRevokeInvitationCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_REVOKE_INVITATION_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyRevokeInvitationCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_INVITATION_CREATED_STATE_CHANGE) == sizeof(PartyInvitationCreatedStateChange));
C_ASSERT(sizeof(PARTY_INVITATION_CREATED_STATE_CHANGE::network) == sizeof(PartyInvitationCreatedStateChange::network));
C_ASSERT(offsetof(PARTY_INVITATION_CREATED_STATE_CHANGE, network) == offsetof(PartyInvitationCreatedStateChange, network));
C_ASSERT(sizeof(PARTY_INVITATION_CREATED_STATE_CHANGE::invitation) == sizeof(PartyInvitationCreatedStateChange::invitation));
C_ASSERT(offsetof(PARTY_INVITATION_CREATED_STATE_CHANGE, invitation) == offsetof(PartyInvitationCreatedStateChange, invitation));

C_ASSERT(sizeof(PARTY_INVITATION_DESTROYED_STATE_CHANGE) == sizeof(PartyInvitationDestroyedStateChange));
C_ASSERT(sizeof(PARTY_INVITATION_DESTROYED_STATE_CHANGE::network) == sizeof(PartyInvitationDestroyedStateChange::network));
C_ASSERT(offsetof(PARTY_INVITATION_DESTROYED_STATE_CHANGE, network) == offsetof(PartyInvitationDestroyedStateChange, network));
C_ASSERT(sizeof(PARTY_INVITATION_DESTROYED_STATE_CHANGE::invitation) == sizeof(PartyInvitationDestroyedStateChange::invitation));
C_ASSERT(offsetof(PARTY_INVITATION_DESTROYED_STATE_CHANGE, invitation) == offsetof(PartyInvitationDestroyedStateChange, invitation));
C_ASSERT(sizeof(PARTY_INVITATION_DESTROYED_STATE_CHANGE::reason) == sizeof(PartyInvitationDestroyedStateChange::reason));
C_ASSERT(offsetof(PARTY_INVITATION_DESTROYED_STATE_CHANGE, reason) == offsetof(PartyInvitationDestroyedStateChange, reason));
C_ASSERT(sizeof(PARTY_INVITATION_DESTROYED_STATE_CHANGE::errorDetail) == sizeof(PartyInvitationDestroyedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_INVITATION_DESTROYED_STATE_CHANGE, errorDetail) == offsetof(PartyInvitationDestroyedStateChange, errorDetail));

C_ASSERT(sizeof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE) == sizeof(PartyNetworkPropertiesChangedStateChange));
C_ASSERT(sizeof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE::network) == sizeof(PartyNetworkPropertiesChangedStateChange::network));
C_ASSERT(offsetof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE, network) == offsetof(PartyNetworkPropertiesChangedStateChange, network));
C_ASSERT(sizeof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE::propertyCount) == sizeof(PartyNetworkPropertiesChangedStateChange::propertyCount));
C_ASSERT(offsetof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE, propertyCount) == offsetof(PartyNetworkPropertiesChangedStateChange, propertyCount));
C_ASSERT(sizeof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE::keys) == sizeof(PartyNetworkPropertiesChangedStateChange::keys));
C_ASSERT(offsetof(PARTY_NETWORK_PROPERTIES_CHANGED_STATE_CHANGE, keys) == offsetof(PartyNetworkPropertiesChangedStateChange, keys));

C_ASSERT(sizeof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE) == sizeof(PartyKickDeviceCompletedStateChange));
C_ASSERT(sizeof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE::result) == sizeof(PartyKickDeviceCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE, result) == offsetof(PartyKickDeviceCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyKickDeviceCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyKickDeviceCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE::network) == sizeof(PartyKickDeviceCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE, network) == offsetof(PartyKickDeviceCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE::kickedDevice) == sizeof(PartyKickDeviceCompletedStateChange::kickedDevice));
C_ASSERT(offsetof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE, kickedDevice) == offsetof(PartyKickDeviceCompletedStateChange, kickedDevice));
C_ASSERT(sizeof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyKickDeviceCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_KICK_DEVICE_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyKickDeviceCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE) == sizeof(PartyKickUserCompletedStateChange));
C_ASSERT(sizeof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE::result) == sizeof(PartyKickUserCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE, result) == offsetof(PartyKickUserCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyKickUserCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyKickUserCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE::network) == sizeof(PartyKickUserCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE, network) == offsetof(PartyKickUserCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE::kickedEntityId) == sizeof(PartyKickUserCompletedStateChange::kickedEntityId));
C_ASSERT(offsetof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE, kickedEntityId) == offsetof(PartyKickUserCompletedStateChange, kickedEntityId));
C_ASSERT(sizeof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyKickUserCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_KICK_USER_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyKickUserCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE) == sizeof(PartyCreateChatControlCompletedStateChange));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::result) == sizeof(PartyCreateChatControlCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, result) == offsetof(PartyCreateChatControlCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyCreateChatControlCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyCreateChatControlCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localDevice) == sizeof(PartyCreateChatControlCompletedStateChange::localDevice));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localDevice) == offsetof(PartyCreateChatControlCompletedStateChange, localDevice));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localUser) == sizeof(PartyCreateChatControlCompletedStateChange::localUser));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localUser) == offsetof(PartyCreateChatControlCompletedStateChange, localUser));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::languageCode) == sizeof(PartyCreateChatControlCompletedStateChange::languageCode));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, languageCode) == offsetof(PartyCreateChatControlCompletedStateChange, languageCode));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyCreateChatControlCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyCreateChatControlCompletedStateChange, asyncIdentifier));
C_ASSERT(sizeof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartyCreateChatControlCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_CREATE_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartyCreateChatControlCompletedStateChange, localChatControl));

C_ASSERT(sizeof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE) == sizeof(PartyDestroyChatControlCompletedStateChange));
C_ASSERT(sizeof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE::result) == sizeof(PartyDestroyChatControlCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE, result) == offsetof(PartyDestroyChatControlCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyDestroyChatControlCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyDestroyChatControlCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localDevice) == sizeof(PartyDestroyChatControlCompletedStateChange::localDevice));
C_ASSERT(offsetof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localDevice) == offsetof(PartyDestroyChatControlCompletedStateChange, localDevice));
C_ASSERT(sizeof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartyDestroyChatControlCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartyDestroyChatControlCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyDestroyChatControlCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_DESTROY_CHAT_CONTROL_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyDestroyChatControlCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_CHAT_CONTROL_CREATED_STATE_CHANGE) == sizeof(PartyChatControlCreatedStateChange));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_CREATED_STATE_CHANGE::chatControl) == sizeof(PartyChatControlCreatedStateChange::chatControl));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_CREATED_STATE_CHANGE, chatControl) == offsetof(PartyChatControlCreatedStateChange, chatControl));

C_ASSERT(sizeof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE) == sizeof(PartyChatControlDestroyedStateChange));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE::chatControl) == sizeof(PartyChatControlDestroyedStateChange::chatControl));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE, chatControl) == offsetof(PartyChatControlDestroyedStateChange, chatControl));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE::reason) == sizeof(PartyChatControlDestroyedStateChange::reason));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE, reason) == offsetof(PartyChatControlDestroyedStateChange, reason));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE::errorDetail) == sizeof(PartyChatControlDestroyedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_DESTROYED_STATE_CHANGE, errorDetail) == offsetof(PartyChatControlDestroyedStateChange, errorDetail));

C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE) == sizeof(PartySetChatAudioEncoderBitrateCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetChatAudioEncoderBitrateCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetChatAudioEncoderBitrateCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetChatAudioEncoderBitrateCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetChatAudioEncoderBitrateCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetChatAudioEncoderBitrateCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetChatAudioEncoderBitrateCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE::bitrate) == sizeof(PartySetChatAudioEncoderBitrateCompletedStateChange::bitrate));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE, bitrate) == offsetof(PartySetChatAudioEncoderBitrateCompletedStateChange, bitrate));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetChatAudioEncoderBitrateCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_ENCODER_BITRATE_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetChatAudioEncoderBitrateCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE) == sizeof(PartyChatTextReceivedStateChange));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::senderChatControl) == sizeof(PartyChatTextReceivedStateChange::senderChatControl));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, senderChatControl) == offsetof(PartyChatTextReceivedStateChange, senderChatControl));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::receiverChatControlCount) == sizeof(PartyChatTextReceivedStateChange::receiverChatControlCount));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, receiverChatControlCount) == offsetof(PartyChatTextReceivedStateChange, receiverChatControlCount));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::receiverChatControls) == sizeof(PartyChatTextReceivedStateChange::receiverChatControls));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, receiverChatControls) == offsetof(PartyChatTextReceivedStateChange, receiverChatControls));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::chatText) == sizeof(PartyChatTextReceivedStateChange::chatText));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, chatText) == offsetof(PartyChatTextReceivedStateChange, chatText));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::dataSize) == sizeof(PartyChatTextReceivedStateChange::dataSize));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, dataSize) == offsetof(PartyChatTextReceivedStateChange, dataSize));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::data) == sizeof(PartyChatTextReceivedStateChange::data));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, data) == offsetof(PartyChatTextReceivedStateChange, data));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::translationCount) == sizeof(PartyChatTextReceivedStateChange::translationCount));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, translationCount) == offsetof(PartyChatTextReceivedStateChange, translationCount));
C_ASSERT(sizeof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE::translations) == sizeof(PartyChatTextReceivedStateChange::translations));
C_ASSERT(offsetof(PARTY_CHAT_TEXT_RECEIVED_STATE_CHANGE, translations) == offsetof(PartyChatTextReceivedStateChange, translations));

C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::result) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::result));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, result) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, result));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::errorDetail) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, errorDetail) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::senderChatControl) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::senderChatControl));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, senderChatControl) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, senderChatControl));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::receiverChatControlCount) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::receiverChatControlCount));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, receiverChatControlCount) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, receiverChatControlCount));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::receiverChatControls) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::receiverChatControls));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, receiverChatControls) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, receiverChatControls));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::transcription) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::transcription));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, transcription) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, transcription));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::type) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::type));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, type) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, type));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::translationCount) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::translationCount));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, translationCount) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, translationCount));
C_ASSERT(sizeof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE::translations) == sizeof(PartyVoiceChatTranscriptionReceivedStateChange::translations));
C_ASSERT(offsetof(PARTY_VOICE_CHAT_TRANSCRIPTION_RECEIVED_STATE_CHANGE, translations) == offsetof(PartyVoiceChatTranscriptionReceivedStateChange, translations));

C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE) == sizeof(PartySetChatAudioInputCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetChatAudioInputCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetChatAudioInputCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetChatAudioInputCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetChatAudioInputCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetChatAudioInputCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetChatAudioInputCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE::audioDeviceSelectionType) == sizeof(PartySetChatAudioInputCompletedStateChange::audioDeviceSelectionType));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE, audioDeviceSelectionType) == offsetof(PartySetChatAudioInputCompletedStateChange, audioDeviceSelectionType));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE::audioDeviceSelectionContext) == sizeof(PartySetChatAudioInputCompletedStateChange::audioDeviceSelectionContext));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE, audioDeviceSelectionContext) == offsetof(PartySetChatAudioInputCompletedStateChange, audioDeviceSelectionContext));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetChatAudioInputCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_INPUT_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetChatAudioInputCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE) == sizeof(PartySetChatAudioOutputCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetChatAudioOutputCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetChatAudioOutputCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetChatAudioOutputCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetChatAudioOutputCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetChatAudioOutputCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetChatAudioOutputCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE::audioDeviceSelectionType) == sizeof(PartySetChatAudioOutputCompletedStateChange::audioDeviceSelectionType));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE, audioDeviceSelectionType) == offsetof(PartySetChatAudioOutputCompletedStateChange, audioDeviceSelectionType));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE::audioDeviceSelectionContext) == sizeof(PartySetChatAudioOutputCompletedStateChange::audioDeviceSelectionContext));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE, audioDeviceSelectionContext) == offsetof(PartySetChatAudioOutputCompletedStateChange, audioDeviceSelectionContext));
C_ASSERT(sizeof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetChatAudioOutputCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_CHAT_AUDIO_OUTPUT_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetChatAudioOutputCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE) == sizeof(PartyLocalChatAudioInputChangedStateChange));
C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE::localChatControl) == sizeof(PartyLocalChatAudioInputChangedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE, localChatControl) == offsetof(PartyLocalChatAudioInputChangedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE::state) == sizeof(PartyLocalChatAudioInputChangedStateChange::state));
C_ASSERT(offsetof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE, state) == offsetof(PartyLocalChatAudioInputChangedStateChange, state));
C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE::errorDetail) == sizeof(PartyLocalChatAudioInputChangedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_LOCAL_CHAT_AUDIO_INPUT_CHANGED_STATE_CHANGE, errorDetail) == offsetof(PartyLocalChatAudioInputChangedStateChange, errorDetail));

C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE) == sizeof(PartyLocalChatAudioOutputChangedStateChange));
C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE::localChatControl) == sizeof(PartyLocalChatAudioOutputChangedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE, localChatControl) == offsetof(PartyLocalChatAudioOutputChangedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE::state) == sizeof(PartyLocalChatAudioOutputChangedStateChange::state));
C_ASSERT(offsetof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE, state) == offsetof(PartyLocalChatAudioOutputChangedStateChange, state));
C_ASSERT(sizeof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE::errorDetail) == sizeof(PartyLocalChatAudioOutputChangedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_LOCAL_CHAT_AUDIO_OUTPUT_CHANGED_STATE_CHANGE, errorDetail) == offsetof(PartyLocalChatAudioOutputChangedStateChange, errorDetail));

C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE) == sizeof(PartySetTextToSpeechProfileCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetTextToSpeechProfileCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetTextToSpeechProfileCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetTextToSpeechProfileCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetTextToSpeechProfileCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetTextToSpeechProfileCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetTextToSpeechProfileCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE::type) == sizeof(PartySetTextToSpeechProfileCompletedStateChange::type));
C_ASSERT(offsetof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE, type) == offsetof(PartySetTextToSpeechProfileCompletedStateChange, type));
C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE::profileIdentifier) == sizeof(PartySetTextToSpeechProfileCompletedStateChange::profileIdentifier));
C_ASSERT(offsetof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE, profileIdentifier) == offsetof(PartySetTextToSpeechProfileCompletedStateChange, profileIdentifier));
C_ASSERT(sizeof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetTextToSpeechProfileCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_TEXT_TO_SPEECH_PROFILE_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetTextToSpeechProfileCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange));
C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE::result) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE, result) == offsetof(PartySynthesizeTextToSpeechCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySynthesizeTextToSpeechCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySynthesizeTextToSpeechCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE::type) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange::type));
C_ASSERT(offsetof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE, type) == offsetof(PartySynthesizeTextToSpeechCompletedStateChange, type));
C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE::textToSynthesize) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange::textToSynthesize));
C_ASSERT(offsetof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE, textToSynthesize) == offsetof(PartySynthesizeTextToSpeechCompletedStateChange, textToSynthesize));
C_ASSERT(sizeof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySynthesizeTextToSpeechCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SYNTHESIZE_TEXT_TO_SPEECH_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySynthesizeTextToSpeechCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE) == sizeof(PartySetLanguageCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetLanguageCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetLanguageCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetLanguageCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetLanguageCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetLanguageCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetLanguageCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE::languageCode) == sizeof(PartySetLanguageCompletedStateChange::languageCode));
C_ASSERT(offsetof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE, languageCode) == offsetof(PartySetLanguageCompletedStateChange, languageCode));
C_ASSERT(sizeof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetLanguageCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_LANGUAGE_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetLanguageCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE) == sizeof(PartySetTranscriptionOptionsCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetTranscriptionOptionsCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetTranscriptionOptionsCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetTranscriptionOptionsCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetTranscriptionOptionsCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetTranscriptionOptionsCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetTranscriptionOptionsCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE::options) == sizeof(PartySetTranscriptionOptionsCompletedStateChange::options));
C_ASSERT(offsetof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE, options) == offsetof(PartySetTranscriptionOptionsCompletedStateChange, options));
C_ASSERT(sizeof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetTranscriptionOptionsCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_TRANSCRIPTION_OPTIONS_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetTranscriptionOptionsCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE) == sizeof(PartySetTextChatOptionsCompletedStateChange));
C_ASSERT(sizeof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE::result) == sizeof(PartySetTextChatOptionsCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE, result) == offsetof(PartySetTextChatOptionsCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartySetTextChatOptionsCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartySetTextChatOptionsCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartySetTextChatOptionsCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartySetTextChatOptionsCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE::options) == sizeof(PartySetTextChatOptionsCompletedStateChange::options));
C_ASSERT(offsetof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE, options) == offsetof(PartySetTextChatOptionsCompletedStateChange, options));
C_ASSERT(sizeof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartySetTextChatOptionsCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_SET_TEXT_CHAT_OPTIONS_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartySetTextChatOptionsCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE) == sizeof(PartyChatControlPropertiesChangedStateChange));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE::chatControl) == sizeof(PartyChatControlPropertiesChangedStateChange::chatControl));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE, chatControl) == offsetof(PartyChatControlPropertiesChangedStateChange, chatControl));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE::propertyCount) == sizeof(PartyChatControlPropertiesChangedStateChange::propertyCount));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE, propertyCount) == offsetof(PartyChatControlPropertiesChangedStateChange, propertyCount));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE::keys) == sizeof(PartyChatControlPropertiesChangedStateChange::keys));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_PROPERTIES_CHANGED_STATE_CHANGE, keys) == offsetof(PartyChatControlPropertiesChangedStateChange, keys));

C_ASSERT(sizeof(PARTY_CHAT_CONTROL_JOINED_NETWORK_STATE_CHANGE) == sizeof(PartyChatControlJoinedNetworkStateChange));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_JOINED_NETWORK_STATE_CHANGE::network) == sizeof(PartyChatControlJoinedNetworkStateChange::network));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_JOINED_NETWORK_STATE_CHANGE, network) == offsetof(PartyChatControlJoinedNetworkStateChange, network));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_JOINED_NETWORK_STATE_CHANGE::chatControl) == sizeof(PartyChatControlJoinedNetworkStateChange::chatControl));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_JOINED_NETWORK_STATE_CHANGE, chatControl) == offsetof(PartyChatControlJoinedNetworkStateChange, chatControl));

C_ASSERT(sizeof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE) == sizeof(PartyChatControlLeftNetworkStateChange));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE::reason) == sizeof(PartyChatControlLeftNetworkStateChange::reason));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE, reason) == offsetof(PartyChatControlLeftNetworkStateChange, reason));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE::errorDetail) == sizeof(PartyChatControlLeftNetworkStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE, errorDetail) == offsetof(PartyChatControlLeftNetworkStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE::network) == sizeof(PartyChatControlLeftNetworkStateChange::network));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE, network) == offsetof(PartyChatControlLeftNetworkStateChange, network));
C_ASSERT(sizeof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE::chatControl) == sizeof(PartyChatControlLeftNetworkStateChange::chatControl));
C_ASSERT(offsetof(PARTY_CHAT_CONTROL_LEFT_NETWORK_STATE_CHANGE, chatControl) == offsetof(PartyChatControlLeftNetworkStateChange, chatControl));

C_ASSERT(sizeof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE) == sizeof(PartyConnectChatControlCompletedStateChange));
C_ASSERT(sizeof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::result) == sizeof(PartyConnectChatControlCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, result) == offsetof(PartyConnectChatControlCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyConnectChatControlCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyConnectChatControlCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::network) == sizeof(PartyConnectChatControlCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, network) == offsetof(PartyConnectChatControlCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartyConnectChatControlCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartyConnectChatControlCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyConnectChatControlCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_CONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyConnectChatControlCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE) == sizeof(PartyDisconnectChatControlCompletedStateChange));
C_ASSERT(sizeof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::result) == sizeof(PartyDisconnectChatControlCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, result) == offsetof(PartyDisconnectChatControlCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyDisconnectChatControlCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyDisconnectChatControlCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::network) == sizeof(PartyDisconnectChatControlCompletedStateChange::network));
C_ASSERT(offsetof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, network) == offsetof(PartyDisconnectChatControlCompletedStateChange, network));
C_ASSERT(sizeof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartyDisconnectChatControlCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartyDisconnectChatControlCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyDisconnectChatControlCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_DISCONNECT_CHAT_CONTROL_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyDisconnectChatControlCompletedStateChange, asyncIdentifier));

C_ASSERT(sizeof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE) == sizeof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange));
C_ASSERT(sizeof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE::result) == sizeof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange::result));
C_ASSERT(offsetof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE, result) == offsetof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange, result));
C_ASSERT(sizeof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE::errorDetail) == sizeof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange::errorDetail));
C_ASSERT(offsetof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE, errorDetail) == offsetof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange, errorDetail));
C_ASSERT(sizeof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE::localChatControl) == sizeof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange::localChatControl));
C_ASSERT(offsetof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE, localChatControl) == offsetof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange, localChatControl));
C_ASSERT(sizeof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE::asyncIdentifier) == sizeof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange::asyncIdentifier));
C_ASSERT(offsetof(PARTY_POPULATE_AVAILABLE_TEXT_TO_SPEECH_PROFILES_COMPLETED_STATE_CHANGE, asyncIdentifier) == offsetof(PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange, asyncIdentifier));

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

#ifdef PARTY_SAL_SUPPORT
#pragma prefast(pop)
#endif // PARTY_SAL_SUPPORT

}; // Party
