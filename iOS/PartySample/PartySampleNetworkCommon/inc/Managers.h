// Holds the persistent controllers and allows easy access to their functionality.
// Must be initialized with an INetworkStateChangeManager to route the results to the consumer library.

#include "Manager.h"
#include "NetworkManager.h"
#include "PlayFabManager.h"
#include "INetworkStateChangeManager.h"

namespace PartySample
{
    class Managers
    {
    public:
        Managers()
        {
        }

        // Initializes the main managers for networking.
        // Also aliases the implementation for the INetworkStateChangeManager
        // for internal use and external use.
        template<class T>
        static void Initialize()
        {
            RegisterNewManager<NetworkManager>();
            RegisterNewManager<PlayFabManager>();
            RegisterNewManager<T>();
            RegisterInterface<INetworkStateChangeManager, T>();
        }

        // Creates a manager and adds it to local storage for easy access through Get.
        template<class T>
        static void RegisterNewManager()
        {
            m_managersByType[typeid(T).name()] = CreateManager<T>();
        }

        // Gets a class, T2, from storage and aliases it to another class name for interface implemenations.
        template<class T, class T2>
        static void RegisterInterface()
        {
            m_managersByType[typeid(T).name()] = Get<T2>();
        }

        // Retrieves a preiously registerd class from local storage.
        template<class T>
        static std::shared_ptr<T> Get()
        {
            return std::static_pointer_cast<T>(m_managersByType[typeid(T).name()]);
        }

    private:

        // Creates a manager class and stores it in the local map.
        template<typename ManagerType>
        static std::shared_ptr<Manager> CreateManager()
        {
            return std::static_pointer_cast<Manager>(std::make_shared<ManagerType>());
        }

        // The storage implementation for manager classes.
        static std::map<const char *, std::shared_ptr<Manager>> m_managersByType;
    };
}

