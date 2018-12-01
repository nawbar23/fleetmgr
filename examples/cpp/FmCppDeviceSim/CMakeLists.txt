project(FmCppDeviceSim)
cmake_minimum_required(VERSION 3.2)

add_compile_options(-std=c++11)

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH "/home/nawbar/skydive/grpc" "/home/nawbar/skydive/grpc/third_party/protobuf")

# Cmake find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

set(PROTOS
    #${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/helloworld.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/add_channels.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/attach_channels.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/channel.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/channel_validation.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/connection_state.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/handover_data.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/location.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/common/role.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/core/attach.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/core/list_devices.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/core/operate.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/facade/control/facade_service.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/facade/control/heartbeat.proto
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../proto/facade/control/setup.proto
)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

add_executable(greeter_server
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)
target_link_libraries(greeter_server
    gRPC::grpc++_reflection
    protobuf::libprotobuf
)
