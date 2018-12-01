// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/channel.proto

#ifndef PROTOBUF_INCLUDED_common_2fchannel_2eproto
#define PROTOBUF_INCLUDED_common_2fchannel_2eproto

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
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_common_2fchannel_2eproto 

namespace protobuf_common_2fchannel_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_common_2fchannel_2eproto
namespace com {
namespace fleetmgr {
namespace interfaces {
class Channel;
class ChannelDefaultTypeInternal;
extern ChannelDefaultTypeInternal _Channel_default_instance_;
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace google {
namespace protobuf {
template<> ::com::fleetmgr::interfaces::Channel* Arena::CreateMaybeMessage<::com::fleetmgr::interfaces::Channel>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace com {
namespace fleetmgr {
namespace interfaces {

// ===================================================================

class Channel : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.fleetmgr.interfaces.Channel) */ {
 public:
  Channel();
  virtual ~Channel();

  Channel(const Channel& from);

  inline Channel& operator=(const Channel& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Channel(Channel&& from) noexcept
    : Channel() {
    *this = ::std::move(from);
  }

  inline Channel& operator=(Channel&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Channel& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Channel* internal_default_instance() {
    return reinterpret_cast<const Channel*>(
               &_Channel_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Channel* other);
  friend void swap(Channel& a, Channel& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Channel* New() const final {
    return CreateMaybeMessage<Channel>(NULL);
  }

  Channel* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Channel>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Channel& from);
  void MergeFrom(const Channel& from);
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
  void InternalSwap(Channel* other);
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

  // string ip = 2;
  void clear_ip();
  static const int kIpFieldNumber = 2;
  const ::std::string& ip() const;
  void set_ip(const ::std::string& value);
  #if LANG_CXX11
  void set_ip(::std::string&& value);
  #endif
  void set_ip(const char* value);
  void set_ip(const char* value, size_t size);
  ::std::string* mutable_ip();
  ::std::string* release_ip();
  void set_allocated_ip(::std::string* ip);

  // string routeKey = 4;
  void clear_routekey();
  static const int kRouteKeyFieldNumber = 4;
  const ::std::string& routekey() const;
  void set_routekey(const ::std::string& value);
  #if LANG_CXX11
  void set_routekey(::std::string&& value);
  #endif
  void set_routekey(const char* value);
  void set_routekey(const char* value, size_t size);
  ::std::string* mutable_routekey();
  ::std::string* release_routekey();
  void set_allocated_routekey(::std::string* routekey);

  // int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // int32 port = 3;
  void clear_port();
  static const int kPortFieldNumber = 3;
  ::google::protobuf::int32 port() const;
  void set_port(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:com.fleetmgr.interfaces.Channel)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr ip_;
  ::google::protobuf::internal::ArenaStringPtr routekey_;
  ::google::protobuf::int64 id_;
  ::google::protobuf::int32 port_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_common_2fchannel_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Channel

// int64 id = 1;
inline void Channel::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Channel::id() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Channel.id)
  return id_;
}
inline void Channel::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Channel.id)
}

// string ip = 2;
inline void Channel::clear_ip() {
  ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Channel::ip() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Channel.ip)
  return ip_.GetNoArena();
}
inline void Channel::set_ip(const ::std::string& value) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Channel.ip)
}
#if LANG_CXX11
inline void Channel::set_ip(::std::string&& value) {
  
  ip_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:com.fleetmgr.interfaces.Channel.ip)
}
#endif
inline void Channel::set_ip(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.fleetmgr.interfaces.Channel.ip)
}
inline void Channel::set_ip(const char* value, size_t size) {
  
  ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.fleetmgr.interfaces.Channel.ip)
}
inline ::std::string* Channel::mutable_ip() {
  
  // @@protoc_insertion_point(field_mutable:com.fleetmgr.interfaces.Channel.ip)
  return ip_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Channel::release_ip() {
  // @@protoc_insertion_point(field_release:com.fleetmgr.interfaces.Channel.ip)
  
  return ip_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Channel::set_allocated_ip(::std::string* ip) {
  if (ip != NULL) {
    
  } else {
    
  }
  ip_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ip);
  // @@protoc_insertion_point(field_set_allocated:com.fleetmgr.interfaces.Channel.ip)
}

// int32 port = 3;
inline void Channel::clear_port() {
  port_ = 0;
}
inline ::google::protobuf::int32 Channel::port() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Channel.port)
  return port_;
}
inline void Channel::set_port(::google::protobuf::int32 value) {
  
  port_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Channel.port)
}

// string routeKey = 4;
inline void Channel::clear_routekey() {
  routekey_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Channel::routekey() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Channel.routeKey)
  return routekey_.GetNoArena();
}
inline void Channel::set_routekey(const ::std::string& value) {
  
  routekey_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Channel.routeKey)
}
#if LANG_CXX11
inline void Channel::set_routekey(::std::string&& value) {
  
  routekey_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:com.fleetmgr.interfaces.Channel.routeKey)
}
#endif
inline void Channel::set_routekey(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  routekey_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.fleetmgr.interfaces.Channel.routeKey)
}
inline void Channel::set_routekey(const char* value, size_t size) {
  
  routekey_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.fleetmgr.interfaces.Channel.routeKey)
}
inline ::std::string* Channel::mutable_routekey() {
  
  // @@protoc_insertion_point(field_mutable:com.fleetmgr.interfaces.Channel.routeKey)
  return routekey_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Channel::release_routekey() {
  // @@protoc_insertion_point(field_release:com.fleetmgr.interfaces.Channel.routeKey)
  
  return routekey_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Channel::set_allocated_routekey(::std::string* routekey) {
  if (routekey != NULL) {
    
  } else {
    
  }
  routekey_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), routekey);
  // @@protoc_insertion_point(field_set_allocated:com.fleetmgr.interfaces.Channel.routeKey)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_common_2fchannel_2eproto
