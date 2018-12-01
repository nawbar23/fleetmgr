// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/connection_state.proto

#include "common/connection_state.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace com {
namespace fleetmgr {
namespace interfaces {
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace protobuf_common_2fconnection_5fstate_2eproto {
void InitDefaults() {
}

const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];
const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "common/connection_state.proto", schemas, file_default_instances, TableStruct::offsets,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\035common/connection_state.proto\022\027com.fle"
      "etmgr.interfaces*s\n\017ConnectionState\022\036\n\032U"
      "NDEFINED_CONNECTION_STATE\020\000\022\016\n\nCONNECTIN"
      "G\020\001\022\r\n\tCONNECTED\020\002\022\017\n\013UNREACHABLE\020\003\022\020\n\014D"
      "ISCONNECTED\020\004B\002P\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 185);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "common/connection_state.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_common_2fconnection_5fstate_2eproto
namespace com {
namespace fleetmgr {
namespace interfaces {
const ::google::protobuf::EnumDescriptor* ConnectionState_descriptor() {
  protobuf_common_2fconnection_5fstate_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_common_2fconnection_5fstate_2eproto::file_level_enum_descriptors[0];
}
bool ConnectionState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)