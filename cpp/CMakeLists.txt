cmake_minimum_required(VERSION 3.2)

project(FmSdk)

# set gRPC repo directory
set(_GRPC_DIR ${PROJECT_SOURCE_DIR}/../../../../grpc)

add_subdirectory(${_GRPC_DIR} ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
message(STATUS "Using gRPC via add_subdirectory.")

set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

add_compile_options(-std=c++11)

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
    ${PROJECT_SOURCE_DIR}/source/event/input/UserEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/event/output/FacadeEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/state/IState.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/Disconnected.cpp
    ${PROJECT_SOURCE_DIR}/source/state/pilot/Disconnected.cpp
    ${PROJECT_SOURCE_DIR}/source/timer/ITimer.cpp
    ${PROJECT_SOURCE_DIR}/source/traffic/Channel.cpp
    ${PROJECT_SOURCE_DIR}/source/traffic/socket/ISocket.cpp
    # TODO genetated files should be automatically generated and added to sources :)
    ${PROJECT_SOURCE_DIR}/generated/common/add_channels.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/add_channels.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/attach_channels.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/attach_channels.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/channel.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/channel.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/channel_validation.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/channel_validation.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/connection_state.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/connection_state.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/handover_data.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/handover_data.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/location.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/location.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/role.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/common/role.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/attach.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/attach.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/operate.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/operate.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/list_devices.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/core/list_devices.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/facade_service.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/facade_service.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/heartbeat.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/heartbeat.grpc.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/setup.pb.cc
    ${PROJECT_SOURCE_DIR}/generated/facade/control/setup.grpc.pb.cc
    )

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/IClient.hpp
    ${PROJECT_SOURCE_DIR}/include/Device.hpp
    ${PROJECT_SOURCE_DIR}/include/Pilot.hpp
    ${PROJECT_SOURCE_DIR}/include/core/CoreClient.hpp
    ${PROJECT_SOURCE_DIR}/include/core/https/IHttpsClient.hpp
    ${PROJECT_SOURCE_DIR}/include/event/input/UserEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/event/output/FacadeEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/state/IState.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/Disconnected.hpp
    ${PROJECT_SOURCE_DIR}/include/state/pilot/Disconnected.hpp
    ${PROJECT_SOURCE_DIR}/include/timer/ITimer.hpp
    ${PROJECT_SOURCE_DIR}/include/traffic/Channel.hpp
    ${PROJECT_SOURCE_DIR}/include/traffic/socket/ISocket.hpp
    )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(fm_sdk STATIC ${SOURCES} ${HEADERS})
link_libraries(${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})
