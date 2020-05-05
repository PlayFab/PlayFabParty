//
// Used to store a network descriptor on the server retrievable by the roomId
// Inputs:
//    roomId - The hash key used to store and retrieve the network descriptor.
//    networkDescriptor - The network descriptor used to connect to a party network.
//
handlers.save_network_descriptor = function (args, context) {
  if (args && args.hasOwnProperty("roomId")) {
    var roomId = args.roomId;
  } else {
    return;
  }

  if (args && args.hasOwnProperty("networkDescriptor")) {
    var networkDescriptor = args.networkDescriptor;
  } else {
    return;
  }

  try {
    server.CreateSharedGroup({ SharedGroupId: roomId });
  } catch (err) {
    log.info("Shared group " + roomId + " already exists.");
    log.error(err);
  }

  var updateRequest = {
    SharedGroupId: roomId,
    Data: {
      network: networkDescriptor,
    },
  };

  server.UpdateSharedGroupData(updateRequest);
};

//
// Used to retrieve a previously stored network descriptor by roomId.
// Inputs:
//    roomId - The hash key used to store and retrieve the network descriptor.
//
handlers.get_network_descriptor = function (args, context) {
  if (args && args.hasOwnProperty("roomId")) {
    var roomId = args.roomId;
  } else {
    return;
  }

  try {
    var getRes = server.GetSharedGroupData({ SharedGroupId: roomId });
    return getRes.Data;
  } catch (err) {
    return;
  }
};
