# Party Errors
// BEGIN GENERATED SECTION: DO NOT EDIT

## Common errors
Number | Description
------ | ------
0x0001 | Encountered unknown error.
0x0002 | Failed to allocate memory.
0x0003 | API not implemented.
0x0004 | Invalid argument specified.
0x0005 | Failed to create new thread.
0x0006 | Failed to find specified resource.
0x0007 | The operation is pending.
0x0008 | Unmapped platform error.
0x0009 | Unmapped messaging error.
0x000A | The buffer passed is too small.
0x000B | A component is in an invalid state to perform the requested operation.
0x000C | A thread created in a suspended state could not be started.
0x000D | The packet's sequence number is outside of the expected range.
0x000E | The packet's sequence number matched that of a packet already queued.
0x000F | The packet queue cannot hold anymore packets.
0x0010 | An invalid data-from-endpoint message was received.
0x0011 | An unknown data-from-endpoint message type was received.
0x0012 | A data-from-endpoint message had too many endpoint IDs.
0x0013 | An invalid endpoint domain was encountered.
0x0014 | An invalid endpoint destroyed reason was encountered.
0x0015 | An invalid private endpoint data message was received.
0x0016 | None of the receivers for a transcription message had transcription enabled.
0x0017 | No chat control was associated with the specified endpoint.
0x0018 | The specified Entity ID is invalid.
0x0019 | The buffer could not be parsed as a packed string.
0x0020 | The token is too large to process.
0x0021 | Creation data on public endpoints is not supported.
0x0022 | The specified Entity ID is not known.
0x0023 | The token is expired or otherwise invalid.
0x0024 | The user is not authorized to execute the operation.
0x0025 | An invalid authentication result was encountered.
0x0026 | At least one data buffer with at least one byte must be provided.
0x0027 | The end of the buffer was reached before parsing was complete.
0x0029 | A specified argument was valid but support is unimplemented.
0x002A | The buffer could not be deserialized as a json object.
0x002B | Failed to reference specified json value.
0x002C | An error was encountered while validating the entity token.
0x002D | The provided network configuration struct was invalid.
0x002E | The provided invitation failed to specify an identifier.
0x002F | The provided invitation specified too many Entity IDs.
0x0030 | The provided invitation's identifier was too long.
0x0031 | The provided invitation's revocability was invalid.
0x0032 | Another invitation with the provided identifier already exists in the network.
0x0033 | The dtls certificate fingerprint returned in the allocation response was invalid.
0x0034 | A port returned in the allocation response was invalid.
0x0035 | An expected port was returned more than once in the allocation response.
0x0036 | This operation is already in progress.
0x0037 | A web request completed with an unexpected http status.
0x0038 | A web request was canceled.
0x0039 | Insufficient buffer supplied to xrn.
0x003A | Network interface not ready.
0x003B | Network interface has failed.
0x003C | Failed to bind because the local address is already in use.
0x003D | Failed to complete the operation because a system limit was reached.
0x003E | Xrn failed to complete operation because associated data was too large.
0x003F | No response from the remote side.
0x0040 | Far side denied an incoming connection.
0x0041 | Attempted an invalid xrn operation.
0x0042 | An xrn network error occurred.
0x0043 | An xrn error occurred.
0x0044 | A packet was dropped on the wire.
0x0045 | A packet with malformed data was received.
0x0046 | A duplicate handle was supplied to xrn.
0x0047 | Bad channel provided to xrn.
0x0048 | Xrn channel was terminated.
0x0049 | Xrn link was remotely terminated.
0x004A | Xrn link was locally terminated.
0x004B | An invalid address was specified to xrn.
0x004C | Remote side forcibly closed socket.
0x004D | Xrn operation canceled.
0x004E | Xrn operation timedout.
0x004F | Xrn session removed.
0x0050 | Xrn has no secure association with the remote endpoint.
0x0051 | An xrn link cannot be created because one already exists to that remote address.
0x0052 | An attempt to create a secure connection timed out.
0x0053 | The http request timed out.
0x0054 | An internal error was encountered while processing an http request.
0x0055 | The http connection was reset or terminated.
0x0056 | The http operation was unexpectedly canceled.
0x0057 | The http response was smaller than expected.
0x0058 | The http response was larger than expected.
0x0059 | Could not store another entity token; limit reached.
0x005A | Failed to find the matching entity token.

## Client errors
Number | Description
------ | ------
0x1000 | Bumblelon must be initialized.
0x1001 | A user is already associated with the specified chat control.
0x1002 | The operation was called with an invalid handle.
0x1003 | Cannot create local user; local user limit reached.
0x1004 | Cannot create local user; local user already exists.
0x1005 | Only one party manager instance may exist at a time.
0x1006 | Cannot connect to network; network already connected.
0x1007 | Internet connectivity error encountered.
0x1008 | Operation could not be performed because object is being destroyed.
0x1009 | Cannot create another chat control; chat control limit reached.
0x100B | Codec failed.
0x100C | The thread affinity mask requested a processor that is not selected for the process affinity mask.
0x100D | Failed to authorize the client to make a multiplayer server request.
0x100E | Information about the endpoint is not yet available because the endpoint is still being created.
0x100F | The network received a message that cannot be handled in its current state.
0x1010 | No servers were available to allocate.
0x1011 | Could not connect to audio client.
0x1012 | Audio operation failed because it was provided an unsupported audio format.
0x1013 | The device handle must reference a local device.
0x1014 | The chat control handle must reference a local chat control.
0x1015 | The endpoint handle must reference a local endpoint.
0x1016 | The specified audio output is pending initialization.
0x1017 | The specified audio output was recognized but disabled.
0x1018 | The specified audio output was recognized but not present.
0x1019 | The specified audio output was recognized but currently unplugged.
0x101A | The allocation service is unavailable.
0x101B | The caller tried to send a message using too many data buffers.
0x101C | The relay announced a remote endpoint with an ID on the local device's endpoint ID range.
0x101D | The client tried to create a remote device table with too many entries.
0x101E | The relay announced a remote device with an index that is already in use on the client.
0x101F | The client could not find the remote device with the specified index.
0x1020 | The client tried to access the invalid device index.
0x1021 | The client tried to access a remote device index larger than the remote device table.
0x1022 | The client could not find the specified endpoint ID.
0x1023 | The specified endpoint ID was invalid or out of range.
0x1024 | Tried to create an endpoint with an ID that was already in use.
0x1025 | Could not allocate an endpoint because the table is full.
0x102B | The network received the network information message while in the wrong state.
0x102C | The endpoint table is not initialized and ready for the operation.
0x102E | The relay sent a setup-forwarding-channel-data message that the client doesn't understand.
0x102F | Using a local target chat control is unsupported.
0x1030 | The relay sent a data-from-endpoint message with an endpoint not on the destination device.
0x1031 | The client tried to send data from an endpoint to too many target endpoints.
0x1034 | The network handle provided does not own the provided endpoint handle.
0x1037 | The relay sent a teardown-forwarding-channel-data message that the client doesn't understand.
0x1038 | The client received a no-more-traffic-to-local-endpoint message targeting an endpoint not waiting for it.
0x1039 | The client received a no-more-traffic-to-local-endpoint message targeting a remote endpoint.
0x103A | The client received an authentication response without having sent an authentication request.
0x103B | The network received a remote device left message while in the wrong state.
0x103C | The network received a no-more-traffic-to-local-endpoint message while in the wrong state.
0x103E | The client failed to resolve the network's IP address and port strings.
0x103F | The multiplayer server response specified an unexpected azure region.
0x1040 | Attempted to create an endpoint or connect a chat control with an unauthenticated local user.
0x1042 | The serialized network descriptor is not supported by this version of Bumblelion.
0x1043 | The network identifier is invalid.
0x1044 | The region name is invalid.
0x1045 | The opaque connection information is invalid.
0x1046 | The size of the serialized network descriptor string is too small to be deserialized into valid data.
0x1047 | Too many outstanding requests to the playfab service.
0x1048 | An expected port was not found in the multiplayer server allocation response.
0x1049 | The chat control is already in the specified network.
0x104A | The chat control is not in the specified network.
0x104B | The opaque connection information is not supported by this version of Bumblelion.
0x104C | The hostname contained in the opaque connection information blob was invalid.
0x104D | The port contained in the opaque connection information blob was invalid.
0x104E | The network configuration is not available yet.
0x104F | The audio render volume was out of the allowable range [0.0, 1.0].
0x1050 | The audio requested message can only be sent to 1 endpoint.
0x1051 | Attempted to perform an invitation operation on behalf of an unauthenticated local user.
0x1052 | An invitation operation response was received without a corresponding request.
0x1056 | The provided chat text string was longer than the max chat text string length.
0x1057 | All receiving chat controls have muted chat text from the source chat control.
0x1058 | The provided target chat control list contained at least one duplicate chat control.
0x1059 | The provided target endpoint list contained at least one duplicate endpoint.
0x105A | A platform error resulted in failure to determine the preferred UI language.
0x105B | XAudio 2.7 debug version not installed on system (install the DirectX SDK Developer Runtime).
0x105C | XAudio 2.7 not installed on system (install the DirectX End-user Runtimes (June 2010)).
0x105E | Authentication was attempted for a user that is already authenticated.
0x105F | Tried to exceed the maximum allowed encoders.
0x1060 | Tried to exceed the maximum allowed decoders.
0x1061 | The request provided to the speech synthesis service was malformed.
0x1062 | The text-to-speech synthesis request was rejected by the service for being too large.
0x1063 | The text-to-speech synthesis request was throttled.
0x1064 | The text-to-speech synthesis request was unauthorized.
0x1065 | The text-to-speech synthesis request was canceled.
0x1066 | The provided text-to-speech synthesis string was longer than the max text-to-speech synthesis string length.
0x1067 | Tried to exceed the maximum allowed hardware encoders.
0x1068 | Tried to exceed the maximum allowed hardware decoders.
0x1069 | Parsing the transcription phrase text failed.
0x106A | The region list could not be determined.
0x106B | This version of the party library is not compatible with the relay.
0x106C | The hostname returned by the allocation request was invalid.
0x106D | The send message queuing priority was not within the allowed range.
0x1071 | The ping to the quality of service beacon timed out.
0x1072 | No supported regions were found.
0x1073 | The request provided to the PlayFab service was malformed.
0x1074 | The title is not authorized to perform the operation.
0x1075 | Tried to send to a local target; loopback is not yet supported.
0x1076 | The transcriber message queue is full.
0x1077 | Received an invalid message from the transcription service.
0x1078 | Failed to submit the ogg packet to the stream.
0x1079 | The specified text to speech profile was invalid.
0x107A | Attempted to synthesize text without setting a text to speech profile.
0x107B | The provided gender was not recognized.
0x107C | The remote transcription operation failed.
0x107D | An invalid transcription error type was received.
0x107E | The specified text to speech profile identifier was too long.
0x107F | The specified text to speech profile name was too long.
0x1080 | The specified language code was too long.
0x1081 | The playfab service has throttled requests for this user.
0x1082 | The playfab service has throttled requests for this title.
0x1083 | Parsing the transcription hypothesis text failed.
0x1084 | The requested statistic list contained at least one duplicate statistic type.
0x1085 | The requested statistic list contained an unrecognized or unsupported statistic type.
0x1086 | Title not enabled for playfab party.
0x1087 | The request to populate text-to-speech profiles was canceled.
0x1089 | The service provided an invalid translation response.
0x108A | The network's configuration will not allow any more unique users.
0x108B | The network's configuration will not allow any more users on this device.
0x108C | The network's configuration will not allow this user to authenticate on anymore devices.
0x108D | The network's configuration will not allow this device to connect because the maximum number of devices are already connected.
0x108E | The operation failed because it depended on a user authentication that also failed.
0x108F | An invalid translation result type was received.
0x1090 | Endpoints cannot be created without a successfully authenticated user or an authentication in progress.
0x1092 | The request to populate text-to-speech profiles encountered an unhandled service error.
0x1094 | A translation request returned an unexpected response.
0x1096 | A relay sent a migration connect message when one was not expected.
0x1097 | The replacement relay reported a different network configuration than the original relay.
0x1098 | The specified audio device is already in use.
0x1099 | The network descriptor checksum doesn't match the expected value.
0x109A | The serialized network descriptor checksum doesn't match the expected value.
0x109B | The network descriptor is a placeholder that can't be used on this device at this time.
0x109C | The serialized network descriptor is not in an expected format.
0x109D | The relay rejected the connection because it was not expecting this device during migration.
0x109E | The create invitation operation was canceled.
0x109F | The revoke invitation operation was canceled.
0x10A2 | The operation could not be completed because the invitation does not exist.
0x10A4 | A quality of service beacon server region name was invalid.
0x10A5 | A quality of service beacon server hostname was invalid.
0x10A6 | The service returned more quality of service beacon server regions than are supported.
0x10A7 | A packet was received with an invalid or unsupported amount of audio.
0x10A8 | A packet was received that could not be parsed as an opus packet.
0x10AA | The network operation cannot complete because creating the network failed.
0x10AB | Access to the specified audio output is restricted.
0x10AC | The audio device couldn't be initialized because the app doesn't have microphone focus.
0x10AD | No audio device was initialized because the app doesn't have microphone focus.
0x10AE | No user could be found for the specified context.
0x10AF | A user, but no audio device, was found for the specified context.
0x10B0 | Submitting an opus packet to the repacketizer failed.
0x10B1 | Retrieving the repacketizer output failed.
0x10B2 | The audio source didn't provide enough audio to build a full audio frame.
0x10B3 | A libogg sync operation failed.
0x10B4 | A libogg stream operation failed.
0x10B5 | The ogg file was invalid.
0x10B6 | The new relay failed to authenticate a user from the old relay.
0x10B7 | The new relay failed to authenticate a user from the old relay with an unexpected result.
0x10BA | The translation operation was canceled due to chat control destruction.
0x10BC | The service failed to validate the provided text-to-speech profile.
0x10BD | The service could not allocate a relay because the requested version was invalid.

## Platform-specific errors
Number | Description
------ | ------
0x3000 | The thread affinity mask did not specify any processors that are valid for XAudio2 to affinitize its threads to.
0x3001 | Unmapped XAudio2 error.
0x3002 | Audio operation failed because windows audio service is not running.
0x3003 | GetEnvironmentVariable returned an unmapped error.
0x3004 | Could not locate the audio device interface path.
0x3005 | Device selection type not supported on this platform.
0x3006 | Could not initialize the Android audio device.
0x3009 | The Android audio render device is not ready.
0x300A | Android JNI exception.
0x300B | Could not find iOS audio unit.
0x300C | Could not set format to iOS audio unit.
0x300D | Could not set render callback to iOS audio unit.
0x300E | Could not initialize iOS audio unit.
0x300F | The thread affinity mask did not specify any processors that are valid for Android to affinitize its threads to.
0x3010 | Could not set the thread affinity for Android.
0x3011 | No platform user was specified.
// END GENERATED SECTION
