cmake_minimum_required(VERSION 3.2)

project(FmSdk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

include_directories(include)
include_directories(generated)

#[[
# Protocol Buffers root directory
set(PROTO_PATH "${CMAKE_SOURCE_DIR}/../proto")

# Protocol Buffers objects to be generated
set(PROTOS
    "common/add_channels"
    "common/attach_channels"
    "common/channel"
    "common/channel_validation"
    "common/connection_state"
    "common/handover_data"
    "common/location"
    "common/role"
    "core/attach"
    "core/list_devices"
    "core/operate"
    "facade/control/facade_service"
    "facade/control/heartbeat"
    "facade/control/setup"
    )

find_package(Protobuf REQUIRED)

set(GENERATED_PROTOBUF_PATH "${CMAKE_BINARY_DIR}/generated")
file(MAKE_DIRECTORY ${GENERATED_PROTOBUF_PATH})
include_directories(${GENERATED_PROTOBUF_PATH})

set(GENERATED_PROTOBUF_SOURCES)
set(GENERATED_PROTOBUF_HEADERS)

foreach(FIL ${PROTOS})
    list(APPEND ${GENERATED_PROTOBUF_SOURCES}
        "${GENERATED_PROTOBUF_PATH}/${FIL}.pb.cc"
        "${GENERATED_PROTOBUF_PATH}/${FIL}.grpc.pb.cc")

    list(APPEND ${GENERATED_PROTOBUF_HEADERS}
        "${GENERATED_PROTOBUF_PATH}/${FIL}.pb.h"
        "${GENERATED_PROTOBUF_PATH}/${FIL}.grpc.pb.h")

    message(STATUS "To gen: ${PROTO_PATH}/${FIL}.proto")

    add_custom_command(
        OUTPUT "${GENERATED_PROTOBUF_PATH}/${FIL}.pb.h"
        "${GENERATED_PROTOBUF_PATH}/${FIL}.pb.cc"
        "${GENERATED_PROTOBUF_PATH}/${FIL}.grpc.pb.cc"
        "${GENERATED_PROTOBUF_PATH}/${FIL}.grpc.pb.h"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
        ARGS "--proto_path=${PROTO_PATH}"
        "--cpp_out=${GENERATED_PROTOBUF_PATH}"
        "${PROTO_PATH}/${FIL}.proto"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
        ARGS "--proto_path=${PROTO_PATH}"
        "--grpc_out=${GENERATED_PROTOBUF_PATH}"
        "--plugin=protoc-gen-grpc=/usr/local/bin/GRPC_CPP_PLUGIN"
        "${PROTO_PATH}/${FIL}.proto"
        COMMENT "Generating: ${FIL}"
        )
endforeach()
]]

set(SOURCES
    ${PROJECT_SOURCE_DIR}/source/IClient.cpp
    ${PROJECT_SOURCE_DIR}/source/Device.cpp
    ${PROJECT_SOURCE_DIR}/source/Pilot.cpp
    ${PROJECT_SOURCE_DIR}/source/core/CoreClient.cpp
    ${PROJECT_SOURCE_DIR}/source/core/https/IHttpsClient.cpp
    ${PROJECT_SOURCE_DIR}/source/event/input/IInputEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/event/input/user/UserEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/event/input/connection/ConnectionEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/event/input/connection/Received.cpp
    ${PROJECT_SOURCE_DIR}/source/event/output/FacadeEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/backend/ClientBackend.cpp
    ${PROJECT_SOURCE_DIR}/source/backend/HeartbeatHandler.cpp
    ${PROJECT_SOURCE_DIR}/source/state/IState.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/Disconnected.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/Connecting.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/Connected.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/Disconnecting.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/connected/Ready.cpp
    ${PROJECT_SOURCE_DIR}/source/state/pilot/Disconnected.cpp
    ${PROJECT_SOURCE_DIR}/source/state/pilot/Connecting.cpp
    ${PROJECT_SOURCE_DIR}/source/state/pilot/Connected.cpp
    ${PROJECT_SOURCE_DIR}/source/state/pilot/Disconnecting.cpp
    ${PROJECT_SOURCE_DIR}/source/timer/ITimer.cpp
    ${PROJECT_SOURCE_DIR}/source/traffic/Channel.cpp
    ${PROJECT_SOURCE_DIR}/source/traffic/socket/ISocket.cpp
    # TODO genetated files should be automatically generated and added to sources :)
    ${PROJECT_SOURCE_DIR}/generated/common/add_channels.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/attach_channels.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/channel.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/channel_validation.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/connection_state.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/handover_data.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/location.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/role.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/attach.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/operate.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/list_devices.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/heartbeat.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/setup.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/facade_service.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/facade_service.grpc.pb.cc
    )

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/IClient.hpp
    ${PROJECT_SOURCE_DIR}/include/Device.hpp
    ${PROJECT_SOURCE_DIR}/include/Pilot.hpp
    ${PROJECT_SOURCE_DIR}/include/core/CoreClient.hpp
    ${PROJECT_SOURCE_DIR}/include/core/https/IHttpsClient.hpp
    ${PROJECT_SOURCE_DIR}/include/event/input/IInputEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/event/input/user/UserEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/event/input/connection/ConnectionEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/event/input/connection/Received.hpp
    ${PROJECT_SOURCE_DIR}/include/event/output/FacadeEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/backend/ClientBackend.hpp
    ${PROJECT_SOURCE_DIR}/include/backend/HeartbeatHandler.hpp
    ${PROJECT_SOURCE_DIR}/include/state/IState.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/Disconnected.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/Connecting.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/Connected.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/Disconnecting.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/connected/Ready.hpp
    ${PROJECT_SOURCE_DIR}/include/state/pilot/Disconnected.hpp
    ${PROJECT_SOURCE_DIR}/include/state/pilot/Connecting.hpp
    ${PROJECT_SOURCE_DIR}/include/state/pilot/Connected.hpp
    ${PROJECT_SOURCE_DIR}/include/state/pilot/Disconnecting.hpp
    ${PROJECT_SOURCE_DIR}/include/timer/ITimer.hpp
    ${PROJECT_SOURCE_DIR}/include/traffic/Channel.hpp
    ${PROJECT_SOURCE_DIR}/include/traffic/socket/ISocket.hpp
    )

if(${CMAKE_GENERATOR} MATCHES "Unix Makefiles")
    message(STATUS ${CMAKE_BUILD_TOOL})
    set(CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} -j2")
    message(STATUS "Added arguments to CMAKE_BUILD_TOOL: ${CMAKE_MAKE_PROGRAM}")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    message(STATUS "Added parallel build arguments to CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
endif()

add_library(fm_sdk STATIC ${SOURCES} ${HEADERS})
