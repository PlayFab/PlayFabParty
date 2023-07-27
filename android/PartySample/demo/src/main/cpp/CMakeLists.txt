cmake_minimum_required(VERSION 3.6)
cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

project(partysample)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set code repository root
set(CODE_REPOSIORY_ROOT ${PROJECT_SOURCE_DIR}/../../../../../..)

# Set final shared libraries output folder
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CODE_REPOSIORY_ROOT}/android/output/android/debug/${ANDROID_ABI})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CODE_REPOSIORY_ROOT}/android/output/android/release/${ANDROID_ABI})

# BINARY_DIR is a temp folder used by cmake itself.
# Binary folder can be remove freely.
# See more details: https://cmake.org/cmake/help/v3.4/command/add_subdirectory.html
# /output/android/
set(BINARY_DIR ${CODE_REPOSIORY_ROOT}/android/output_int/android/${ANDROID_ABI}/obj)

include_directories(
    # For PlayFab SDK
    ${CODE_REPOSIORY_ROOT}/android/ext/playfabxplatsdk/src/cppsdk/include
    # For Party.h
    ${CODE_REPOSIORY_ROOT}/include
    # For Network library
    ${CODE_REPOSIORY_ROOT}/android/PartySampleNetworkCommon/inc
    ${CODE_REPOSIORY_ROOT}/android/PartySampleNetworkCommon/lib
)

file(GLOB SOURCES "./*.cpp")
file(GLOB NETWORKSOURCES ${CODE_REPOSIORY_ROOT}/android/PartySampleNetworkCommon/lib/*.cpp)
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
    ${CODE_REPOSIORY_ROOT}/android/bin/${libpath}/${ANDROID_ABI}/libparty.so)

find_library(party
    party
    ${CODE_REPOSIORY_ROOT}/android/bin/${libpath}/${ANDROID_ABI}
    NO_DEFAULT_PATH
    CMAKE_FIND_ROOT_PATH_BOTH)

# find_library(cppsdk_lib
#         cppsdk
#         ${CODE_REPOSIORY_ROOT}/android/bin/${libpath}/${ANDROID_ABI}/lib
#         NO_DEFAULT_PATH
#         CMAKE_FIND_ROOT_PATH_BOTH)

find_library(OpenSLES_lib
    OpenSLES)

set(
    cppsdk_lib
    ${CODE_REPOSIORY_ROOT}/android/bin/${libpath}/${ANDROID_ABI}/lib/libcppsdk.a
)
message(NOTICE "cppsdk_lib_PATH: ${cppsdk_lib}")

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