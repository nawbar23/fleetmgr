cmake_minimum_required(VERSION 2.8)

project(FmSdk)

# set gRPC repo directory
set(_GRPC_DIR ../../../../grpc)

add_subdirectory(${_GRPC_DIR} ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
message(STATUS "Using gRPC via add_subdirectory.")

set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP grpsc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

add_compile_options(-std=c++11)

include_directories(include)
include_directories(generated)

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
