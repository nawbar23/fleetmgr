cmake_minimum_required(VERSION 3.3)
project(fm_sdk)

add_compile_options(-std=c++11)

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH 
	"/home/nawbar/skydive/grpc" 
	"/home/nawbar/skydive/grpc/third_party/protobuf")

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

include_directories(${GENERATED_PROTOBUF_PATH})
link_libraries(grpc++_unsecure grpc gpr ${PROTOBUF_LIBRARY})

add_executable(fm_sdk
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${PROTO_SRCS}
    ${GRPC_SRCS}
)
