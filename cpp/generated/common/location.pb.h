// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/location.proto

#ifndef PROTOBUF_INCLUDED_common_2flocation_2eproto
#define PROTOBUF_INCLUDED_common_2flocation_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_common_2flocation_2eproto 

namespace protobuf_common_2flocation_2eproto {
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
}  // namespace protobuf_common_2flocation_2eproto
namespace com {
namespace fleetmgr {
namespace interfaces {
class Location;
class LocationDefaultTypeInternal;
extern LocationDefaultTypeInternal _Location_default_instance_;
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace google {
namespace protobuf {
template<> ::com::fleetmgr::interfaces::Location* Arena::CreateMaybeMessage<::com::fleetmgr::interfaces::Location>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace com {
namespace fleetmgr {
namespace interfaces {

// ===================================================================

class Location : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.fleetmgr.interfaces.Location) */ {
 public:
  Location();
  virtual ~Location();

  Location(const Location& from);

  inline Location& operator=(const Location& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Location(Location&& from) noexcept
    : Location() {
    *this = ::std::move(from);
  }

  inline Location& operator=(Location&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Location& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Location* internal_default_instance() {
    return reinterpret_cast<const Location*>(
               &_Location_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Location* other);
  friend void swap(Location& a, Location& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Location* New() const final {
    return CreateMaybeMessage<Location>(NULL);
  }

  Location* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Location>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Location& from);
  void MergeFrom(const Location& from);
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
  void InternalSwap(Location* other);
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

  // double latitude = 1;
  void clear_latitude();
  static const int kLatitudeFieldNumber = 1;
  double latitude() const;
  void set_latitude(double value);

  // double longitude = 2;
  void clear_longitude();
  static const int kLongitudeFieldNumber = 2;
  double longitude() const;
  void set_longitude(double value);

  // double altitude = 3;
  void clear_altitude();
  static const int kAltitudeFieldNumber = 3;
  double altitude() const;
  void set_altitude(double value);

  // @@protoc_insertion_point(class_scope:com.fleetmgr.interfaces.Location)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double latitude_;
  double longitude_;
  double altitude_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_common_2flocation_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Location

// double latitude = 1;
inline void Location::clear_latitude() {
  latitude_ = 0;
}
inline double Location::latitude() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Location.latitude)
  return latitude_;
}
inline void Location::set_latitude(double value) {
  
  latitude_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Location.latitude)
}

// double longitude = 2;
inline void Location::clear_longitude() {
  longitude_ = 0;
}
inline double Location::longitude() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Location.longitude)
  return longitude_;
}
inline void Location::set_longitude(double value) {
  
  longitude_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Location.longitude)
}

// double altitude = 3;
inline void Location::clear_altitude() {
  altitude_ = 0;
}
inline double Location::altitude() const {
  // @@protoc_insertion_point(field_get:com.fleetmgr.interfaces.Location.altitude)
  return altitude_;
}
inline void Location::set_altitude(double value) {
  
  altitude_ = value;
  // @@protoc_insertion_point(field_set:com.fleetmgr.interfaces.Location.altitude)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_common_2flocation_2eproto