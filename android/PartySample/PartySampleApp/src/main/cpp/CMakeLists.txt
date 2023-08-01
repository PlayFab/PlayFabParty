cmake_minimum_required(VERSION 3.6)
cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

project(partysample)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set code repository root
set(REPO_ROOT ${PROJECT_SOURCE_DIR}/../../../../../..)

# Set final shared libraries output folder
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${REPO_ROOT}/android/output/android/debug/${ANDROID_ABI})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${REPO_ROOT}/android/output/android/release/${ANDROID_ABI})

# BINARY_DIR is a temp folder used by cmake itself.
# Binary folder can be remove freely.
# See more details: https://cmake.org/cmake/help/v3.4/command/add_subdirectory.html
# /output/android/
set(BINARY_DIR ${REPO_ROOT}/android/output_int/android/${ANDROID_ABI}/obj)

# add_subdirectory(${REPO_ROOT}/external/XPlatCppSdk/build/Android/)

include_directories(
    # For PlayFab SDK
    # ${REPO_ROOT}/android/ext/playfabxplatsdk/src/cppsdk/include
    ${REPO_ROOT}/external/XPlatCppSdk/code/include
    ${REPO_ROOT}/external/XPlatCppSdk/external/jsoncpp/include

    # For Party.h
    ${REPO_ROOT}/include

    # For Network library
    ${REPO_ROOT}/android/PartySampleNetworkCommon/inc
    ${REPO_ROOT}/android/PartySampleNetworkCommon/lib
)

file(GLOB SOURCES "./*.cpp")
file(GLOB NETWORKSOURCES ${REPO_ROOT}/android/PartySampleNetworkCommon/lib/*.cpp)
add_library(partysample SHARED ${SOURCES} ${NETWORKSOURCES})

SET_TARGET_PROPERTIES(partysample
    PROPERTIES COMPILE_FLAGS "-Wno-unused-variable \
                                -Wno-unknown-pragmas \
                                -Wno-unused-parameter \
                                -Wno-unused-private-field \
                                -Wno-reorder \
                                -Wno-format \
                                -Wno-infinite-recursion"
    )

set(libpath release)

find_library(
    log_lib
    log
)

# Use shared library for party in demo apps
add_library(party SHARED IMPORTED)
set_target_properties(party PROPERTIES IMPORTED_LOCATION
    ${REPO_ROOT}/android/bin/${libpath}/${ANDROID_ABI}/libparty.so)

find_library(party
    party
    ${REPO_ROOT}/android/bin/${libpath}/${ANDROID_ABI}
    NO_DEFAULT_PATH
    CMAKE_FIND_ROOT_PATH_BOTH)

# find_library(cppsdk_lib
#     cppsdk
#     ${REPO_ROOT}/android/bin/${libpath}/${ANDROID_ABI}/lib
#     NO_DEFAULT_PATH
#     CMAKE_FIND_ROOT_PATH_BOTH)

find_library(cppsdk_lib
    XPlatCppSdk
    ${REPO_ROOT}/external/XPlatCppSdk/build/Android/XPlatCppSdk/build/intermediates/cmake/debug/obj/${ANDROID_ABI}/
    NO_DEFAULT_PATH
    CMAKE_FIND_ROOT_PATH_BOTH)

find_library(OpenSLES_lib
    OpenSLES)

# set(
#     cppsdk_lib
#     ${REPO_ROOT}/android/bin/${libpath}/${ANDROID_ABI}/lib/libcppsdk.a
# )
# message(NOTICE "cppsdk_lib_PATH: ${cppsdk_lib}")

target_link_libraries(
    # Target
    partysample

    # Dependencies
    ${cppsdk_lib}
    ${OpenSLES_lib}
    ${log_lib}
    ${party}
    libz.a
)