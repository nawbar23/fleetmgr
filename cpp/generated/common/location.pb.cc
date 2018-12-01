// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/location.proto

#include "common/location.pb.h"

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
class LocationDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Location>
      _instance;
} _Location_default_instance_;
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace protobuf_common_2flocation_2eproto {
static void InitDefaultsLocation() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::com::fleetmgr::interfaces::_Location_default_instance_;
    new (ptr) ::com::fleetmgr::interfaces::Location();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::com::fleetmgr::interfaces::Location::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Location =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsLocation}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Location.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::com::fleetmgr::interfaces::Location, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::com::fleetmgr::interfaces::Location, latitude_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::com::fleetmgr::interfaces::Location, longitude_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::com::fleetmgr::interfaces::Location, altitude_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::com::fleetmgr::interfaces::Location)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::com::fleetmgr::interfaces::_Location_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "common/location.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\025common/location.proto\022\027com.fleetmgr.in"
      "terfaces\"A\n\010Location\022\020\n\010latitude\030\001 \001(\001\022\021"
      "\n\tlongitude\030\002 \001(\001\022\020\n\010altitude\030\003 \001(\001B\002P\001b"
      "\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 127);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "common/location.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_common_2flocation_2eproto
namespace com {
namespace fleetmgr {
namespace interfaces {

// ===================================================================

void Location::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Location::kLatitudeFieldNumber;
const int Location::kLongitudeFieldNumber;
const int Location::kAltitudeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Location::Location()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_common_2flocation_2eproto::scc_info_Location.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:com.fleetmgr.interfaces.Location)
}
Location::Location(const Location& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&latitude_, &from.latitude_,
    static_cast<size_t>(reinterpret_cast<char*>(&altitude_) -
    reinterpret_cast<char*>(&latitude_)) + sizeof(altitude_));
  // @@protoc_insertion_point(copy_constructor:com.fleetmgr.interfaces.Location)
}

void Location::SharedCtor() {
  ::memset(&latitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&altitude_) -
      reinterpret_cast<char*>(&latitude_)) + sizeof(altitude_));
}

Location::~Location() {
  // @@protoc_insertion_point(destructor:com.fleetmgr.interfaces.Location)
  SharedDtor();
}

void Location::SharedDtor() {
}

void Location::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Location::descriptor() {
  ::protobuf_common_2flocation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_common_2flocation_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Location& Location::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_common_2flocation_2eproto::scc_info_Location.base);
  return *internal_default_instance();
}


void Location::Clear() {
// @@protoc_insertion_point(message_clear_start:com.fleetmgr.interfaces.Location)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&latitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&altitude_) -
      reinterpret_cast<char*>(&latitude_)) + sizeof(altitude_));
  _internal_metadata_.Clear();
}

bool Location::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:com.fleetmgr.interfaces.Location)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // double latitude = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &latitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double longitude = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(17u /* 17 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &longitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double altitude = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(25u /* 25 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &altitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:com.fleetmgr.interfaces.Location)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:com.fleetmgr.interfaces.Location)
  return false;
#undef DO_
}

void Location::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:com.fleetmgr.interfaces.Location)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double latitude = 1;
  if (this->latitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->latitude(), output);
  }

  // double longitude = 2;
  if (this->longitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->longitude(), output);
  }

  // double altitude = 3;
  if (this->altitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->altitude(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:com.fleetmgr.interfaces.Location)
}

::google::protobuf::uint8* Location::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:com.fleetmgr.interfaces.Location)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // double latitude = 1;
  if (this->latitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->latitude(), target);
  }

  // double longitude = 2;
  if (this->longitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->longitude(), target);
  }

  // double altitude = 3;
  if (this->altitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->altitude(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:com.fleetmgr.interfaces.Location)
  return target;
}

size_t Location::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:com.fleetmgr.interfaces.Location)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // double latitude = 1;
  if (this->latitude() != 0) {
    total_size += 1 + 8;
  }

  // double longitude = 2;
  if (this->longitude() != 0) {
    total_size += 1 + 8;
  }

  // double altitude = 3;
  if (this->altitude() != 0) {
    total_size += 1 + 8;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Location::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:com.fleetmgr.interfaces.Location)
  GOOGLE_DCHECK_NE(&from, this);
  const Location* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Location>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:com.fleetmgr.interfaces.Location)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:com.fleetmgr.interfaces.Location)
    MergeFrom(*source);
  }
}

void Location::MergeFrom(const Location& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:com.fleetmgr.interfaces.Location)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.latitude() != 0) {
    set_latitude(from.latitude());
  }
  if (from.longitude() != 0) {
    set_longitude(from.longitude());
  }
  if (from.altitude() != 0) {
    set_altitude(from.altitude());
  }
}

void Location::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:com.fleetmgr.interfaces.Location)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Location::CopyFrom(const Location& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:com.fleetmgr.interfaces.Location)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Location::IsInitialized() const {
  return true;
}

void Location::Swap(Location* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Location::InternalSwap(Location* other) {
  using std::swap;
  swap(latitude_, other->latitude_);
  swap(longitude_, other->longitude_);
  swap(altitude_, other->altitude_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Location::GetMetadata() const {
  protobuf_common_2flocation_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_common_2flocation_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace interfaces
}  // namespace fleetmgr
}  // namespace com
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::com::fleetmgr::interfaces::Location* Arena::CreateMaybeMessage< ::com::fleetmgr::interfaces::Location >(Arena* arena) {
  return Arena::CreateInternal< ::com::fleetmgr::interfaces::Location >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)