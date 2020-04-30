cmake_minimum_required(VERSION 3.4.1)

include_directories(
        ${CODE_REPOSIORY_ROOT}/external/gsl/include
        ${CODE_REPOSIORY_ROOT}/external/playfabxplatsdk/src/cppsdk
        ${CODE_REPOSIORY_ROOT}/external/playfabxplatsdk/src/cppsdk/include
        ${CODE_REPOSIORY_ROOT}/external/playfabxplatsdk/src/cppsdk/include/curl
        ${CODE_REPOSIORY_ROOT}/external/playfabxplatsdk/src/cppsdk/include/jsoncpp
        ${CODE_REPOSIORY_ROOT}/external/playfabxplatsdk/src/external/aria/lib/include/public
        ${CODE_REPOSIORY_ROOT}/src/cofa/client/pub
)

file(GLOB SOURCES "*.cpp")
file(GLOB JSONCPP "./source/jsoncpp/*.cpp")

add_library(cppsdk${TEST}
        STATIC
        ${SOURCES}
        ${JSONCPP}
        "./source/playfab/PlayFabAndroidHttpPlugin.cpp"
        "./source/playfab/PlayFabApiSettings.cpp"
        "./source/playfab/PlayFabAuthenticationApi.cpp"
        "./source/playfab/PlayFabAuthenticationContext.cpp"
        "./source/playfab/PlayFabCallRequestContainer.cpp"
        "./source/playfab/PlayFabCallRequestContainerBase.cpp"
        "./source/playfab/PlayFabClientApi.cpp"
        "./source/playfab/PlayFabDataApi.cpp"
        "./source/playfab/PlayFabError.cpp"
        "./source/playfab/PlayFabEvent.cpp"
        "./source/playfab/PlayFabEventApi.cpp"
        "./source/playfab/PlayFabEventBuffer.cpp"
        "./source/playfab/PlayFabEventPipeline.cpp"
        "./source/playfab/PlayFabEventRouter.cpp"
        "./source/playfab/PlayFabEventsApi.cpp"
        "./source/playfab/PlayFabMultiplayerApi.cpp"
        "./source/playfab/PlayFabPluginManager.cpp"
        "./source/playfab/PlayFabSettings.cpp"
        "./source/playfab/PlayFabSpinLock.cpp"
        )

SET_TARGET_PROPERTIES(cppsdk${TEST}
        PROPERTIES COMPILE_FLAGS "-Wno-unused-value \
                                  -Wno-unused-parameter \
                                  -Wno-unknown-pragmas \
                                  -Wno-unused-variable \
                                  -Wno-deprecated-declarations \
                                  -Wno-reorder \
                                  -Wno-nonportable-include-path"
        )

set_target_properties(cppsdk${TEST} PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries(
        cppsdk${TEST}
        libz.a
)