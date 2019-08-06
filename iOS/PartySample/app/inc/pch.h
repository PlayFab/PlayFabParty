#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include "PartyPal.h"
#include "Party.h"

#include <INetworkStateChangeManager.h>
#include "INetworkMessageHandler.h"

#define DEBUGLOG printf

// Polluting the global namespace with 'using namespace' statements (as opposed to 'namespace X = Alias' statements) is
// poor practice. That being said, we designed our naming conventions such that even if consumers do this, our API should
// still be unique and readable. To "stress test" these naming conventions we will pollute the global namespace.
using namespace PartySample;
using namespace Party;

