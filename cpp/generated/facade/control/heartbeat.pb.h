// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: facade/control/heartbeat.proto

#ifndef PROTOBUF_INCLUDED_facade_2fcontrol_2fheartbeat_2eproto
#define PROTOBUF_INCLUDED_facade_2fcontrol_2fheartbeat_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "common/location.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_facade_2fcontrol_2fheartbeat_2eproto 

namespace protobuf_facade_2fcontrol_2fheartbeat_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_facade_2fcontrol_2fheartbeat_2eproto
namespace com {
namespace fleetmgr {
namespace interfaces {
namespace facade {
namespace control {
class HeartbeatRequest;
class HeartbeatRequestDefaultTypeInternal;
extern HeartbeatRequestDefaultTypeInternal _HeartbeatRequest_default_instance_;
class HeartbeatResponse;
class HeartbeatResponseDefaultTypeInternal;
extern HeartbeatResponseDefaultTypeInternal _HeartbeatResponse_default_instance_;
}  // namespace control
}  // namespace facade
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace google {
namespace protobuf {
template<> ::com::fleetmgr::interfaces::facade::control::HeartbeatRequest* Arena::CreateMaybeMessage<::com::fleetmgr::interfaces::facade::control::HeartbeatRequest>(Arena*);
template<> ::com::fleetmgr::interfaces::facade::control::HeartbeatResponse* Arena::CreateMaybeMessage<::com::fleetmgr::interfaces::facade::control::HeartbeatResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace com {
namespace fleetmgr {
namespace interfaces {
namespace facade {
namespace control {

// ===================================================================

class HeartbeatRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.fleetmgr.interfaces.facade.control.HeartbeatRequest) */ {
 public:
  HeartbeatRequest();
  virtual ~HeartbeatRequest();

  HeartbeatRequest(const HeartbeatRequest& from);

  inline HeartbeatRequest& operator=(const HeartbeatRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HeartbeatRequest(HeartbeatRequest&& from) noexcept
    : HeartbeatRequest() {
    *this = ::std::move(from);
  }

  inline HeartbeatRequest& operator=(HeartbeatRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HeartbeatRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HeartbeatRequest* internal_default_instance() {
    return reinterpret_cast<const HeartbeatRequest*>(
               &_HeartbeatRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(HeartbeatRequest* other);
  friend void swap(HeartbeatRequest& a, HeartbeatRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HeartbeatRequest* New() const final {
    return CreateMaybeMessage<HeartbeatRequest>(NULL);
  }

  HeartbeatRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<HeartbeatRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const HeartbeatRequest& from);
  void MergeFrom(const HeartbeatRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HeartbeatRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int64 key = 1;
  void clear_key();
  static const int kKeyFieldNumber = 1;
  ::google::protobuf::int64 key() const;
  void set_key(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:com.fleetmgr.interfaces.facade.control.HeartbeatRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int64 key_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_facade_2fcontrol_2fheartbeat_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class HeartbeatResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.fleetmgr.interfaces.facade.control.HeartbeatResponse) */ {
 public:
  HeartbeatResponse();
  virtual ~HeartbeatResponse();

  HeartbeatResponse(const HeartbeatResponse& from);

  inline HeartbeatResponse& operator=(const HeartbeatResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HeartbeatResponse(HeartbeatResponse&& from) noexcept
    : HeartbeatResponse() {
    *this = ::std::move(from);
  }

  inline HeartbeatResponse& operator=(HeartbeatResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HeartbeatResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HeartbeatResponse* internal_default_instance() {
    return reinterpret_cast<const HeartbeatResponse*>(
               &_HeartbeatResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(HeartbeatResponse* other);
  friend void swap(HeartbeatResponse& a, HeartbeatResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HeartbeatResponse* New() const final {
    return CreateMaybeMessage<HeartbeatResponse>(NULL);
  }

  HeartbeatResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<HeartbeatResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const HeartbeatResponse& from);
  void MergeFrom(const HeartbeatResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HeartbeatResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .com.fleetmgr.interfaces.Location location = 2;
  bool has_location() const;
  void clear_location();
  static const int kLocationFieldNumber = 2;
  private:
  const ::com::fleetmgr::interfaces::Location& _internal_location() const;
  public:
  const ::com::fleetmgr::interfaces::Location& location() const;
  ::com::fleetmgr::interfaces::Location* release_location();
  ::com::fleetmgr::interfaces::Location* mutable_location();
  void set_allocated_location(::com::fleetmgr::interfaces::Location* location);

  // int64 key = 1;
  void clear_key();
  static const int kKeyFieldNumber = 1;
  ::google::protobuf::int64 key() const;
  void set_key(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:com.fleetmgr.interfaces.facade.control.HeartbeatResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::com::fleetmgr::interfaces::Location* location_;
  ::google::protobuf::int64 key_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_facade_2fcontrol_2fheartbeat_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HeartbeatRequest

// int64 key = 1;
inline void HeartbeatRequest::clear_key() {
  key_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 HeartbeatRequest::key() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.facade.control.HeartbeatRequest.key)
  return key_;
}
inline void HeartbeatRequest::set_key(::google::protobuf::int64 value) {
  
  key_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.facade.control.HeartbeatRequest.key)
}

// -------------------------------------------------------------------

// HeartbeatResponse

// int64 key = 1;
inline void HeartbeatResponse::clear_key() {
  key_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 HeartbeatResponse::key() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.facade.control.HeartbeatResponse.key)
  return key_;
}
inline void HeartbeatResponse::set_key(::google::protobuf::int64 value) {
  
  key_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.facade.control.HeartbeatResponse.key)
}

// .com.fleetmgr.interfaces.Location location = 2;
inline bool HeartbeatResponse::has_location() const {
  return this != internal_default_instance() && location_ != NULL;
}
inline const ::com::fleetmgr::interfaces::Location& HeartbeatResponse::_internal_location() const {
  return *location_;
}
inline const ::com::fleetmgr::interfaces::Location& HeartbeatResponse::location() const {
  const ::com::fleetmgr::interfaces::Location* p = location_;
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.facade.control.HeartbeatResponse.location)
  return p != NULL ? *p : *reinterpret_cast<const ::com::fleetmgr::interfaces::Location*>(
      &::com::fleetmgr::interfaces::_Location_default_instance_);
}
inline ::com::fleetmgr::interfaces::Location* HeartbeatResponse::release_location() {
  // @@protoc_insertion_point(field_release:com.fleetmgr.interfaces.facade.control.HeartbeatResponse.location)
  
  ::com::fleetmgr::interfaces::Location* temp = location_;
  location_ = NULL;
  return temp;
}
inline ::com::fleetmgr::interfaces::Location* HeartbeatResponse::mutable_location() {
  
  if (location_ == NULL) {
    auto* p = CreateMaybeMessage<::com::fleetmgr::interfaces::Location>(GetArenaNoVirtual());
    location_ = p;
  }
  // @@protoc_insertion_point(field_mutable:com.fleetmgr.interfaces.facade.control.HeartbeatResponse.location)
  return location_;
}
inline void HeartbeatResponse::set_allocated_location(::com::fleetmgr::interfaces::Location* location) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(location_);
  }
  if (location) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      location = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, location, submessage_arena);
    }
    
  } else {
    
  }
  location_ = location;
  // @@protoc_insertion_point(field_set_allocated:com.fleetmgr.interfaces.facade.control.HeartbeatResponse.location)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace control
}  // namespace facade
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_facade_2fcontrol_2fheartbeat_2eproto