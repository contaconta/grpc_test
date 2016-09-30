// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cpyhello.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "cpyhello.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace cpyhello {

namespace {

const ::google::protobuf::Descriptor* GreeReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GreeReq_reflection_ = NULL;
const ::google::protobuf::Descriptor* GreeRes_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GreeRes_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_cpyhello_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_cpyhello_2eproto() {
  protobuf_AddDesc_cpyhello_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "cpyhello.proto");
  GOOGLE_CHECK(file != NULL);
  GreeReq_descriptor_ = file->message_type(0);
  static const int GreeReq_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeReq, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeReq, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeReq, message_),
  };
  GreeReq_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      GreeReq_descriptor_,
      GreeReq::default_instance_,
      GreeReq_offsets_,
      -1,
      -1,
      -1,
      sizeof(GreeReq),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeReq, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeReq, _is_default_instance_));
  GreeRes_descriptor_ = file->message_type(1);
  static const int GreeRes_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeRes, host_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeRes, message_),
  };
  GreeRes_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      GreeRes_descriptor_,
      GreeRes::default_instance_,
      GreeRes_offsets_,
      -1,
      -1,
      -1,
      sizeof(GreeRes),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeRes, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GreeRes, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_cpyhello_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      GreeReq_descriptor_, &GreeReq::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      GreeRes_descriptor_, &GreeRes::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_cpyhello_2eproto() {
  delete GreeReq::default_instance_;
  delete GreeReq_reflection_;
  delete GreeRes::default_instance_;
  delete GreeRes_reflection_;
}

void protobuf_AddDesc_cpyhello_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_cpyhello_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016cpyhello.proto\022\010cpyhello\"4\n\007GreeReq\022\n\n"
    "\002id\030\001 \001(\005\022\014\n\004name\030\002 \001(\t\022\017\n\007message\030\003 \001(\t"
    "\"(\n\007GreeRes\022\014\n\004host\030\001 \001(\t\022\017\n\007message\030\002 \001"
    "(\t2B\n\nCpyGreeter\0224\n\nmySayHello\022\021.cpyhell"
    "o.GreeReq\032\021.cpyhello.GreeRes\"\000b\006proto3", 198);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "cpyhello.proto", &protobuf_RegisterTypes);
  GreeReq::default_instance_ = new GreeReq();
  GreeRes::default_instance_ = new GreeRes();
  GreeReq::default_instance_->InitAsDefaultInstance();
  GreeRes::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_cpyhello_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_cpyhello_2eproto {
  StaticDescriptorInitializer_cpyhello_2eproto() {
    protobuf_AddDesc_cpyhello_2eproto();
  }
} static_descriptor_initializer_cpyhello_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GreeReq::kIdFieldNumber;
const int GreeReq::kNameFieldNumber;
const int GreeReq::kMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GreeReq::GreeReq()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:cpyhello.GreeReq)
}

void GreeReq::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

GreeReq::GreeReq(const GreeReq& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:cpyhello.GreeReq)
}

void GreeReq::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

GreeReq::~GreeReq() {
  // @@protoc_insertion_point(destructor:cpyhello.GreeReq)
  SharedDtor();
}

void GreeReq::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void GreeReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GreeReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GreeReq_descriptor_;
}

const GreeReq& GreeReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_cpyhello_2eproto();
  return *default_instance_;
}

GreeReq* GreeReq::default_instance_ = NULL;

GreeReq* GreeReq::New(::google::protobuf::Arena* arena) const {
  GreeReq* n = new GreeReq;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GreeReq::Clear() {
// @@protoc_insertion_point(message_clear_start:cpyhello.GreeReq)
  id_ = 0;
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool GreeReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:cpyhello.GreeReq)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // optional string name = 2;
      case 2: {
        if (tag == 18) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cpyhello.GreeReq.name"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_message;
        break;
      }

      // optional string message = 3;
      case 3: {
        if (tag == 26) {
         parse_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->message().data(), this->message().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cpyhello.GreeReq.message"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cpyhello.GreeReq)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cpyhello.GreeReq)
  return false;
#undef DO_
}

void GreeReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cpyhello.GreeReq)
  // optional int32 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional string name = 2;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeReq.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // optional string message = 3;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeReq.message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->message(), output);
  }

  // @@protoc_insertion_point(serialize_end:cpyhello.GreeReq)
}

::google::protobuf::uint8* GreeReq::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:cpyhello.GreeReq)
  // optional int32 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional string name = 2;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeReq.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // optional string message = 3;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeReq.message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->message(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:cpyhello.GreeReq)
  return target;
}

int GreeReq::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:cpyhello.GreeReq)
  int total_size = 0;

  // optional int32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  // optional string name = 2;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // optional string message = 3;
  if (this->message().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->message());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GreeReq::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:cpyhello.GreeReq)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const GreeReq* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const GreeReq>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:cpyhello.GreeReq)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:cpyhello.GreeReq)
    MergeFrom(*source);
  }
}

void GreeReq::MergeFrom(const GreeReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cpyhello.GreeReq)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.message().size() > 0) {

    message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
}

void GreeReq::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:cpyhello.GreeReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GreeReq::CopyFrom(const GreeReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cpyhello.GreeReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GreeReq::IsInitialized() const {

  return true;
}

void GreeReq::Swap(GreeReq* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GreeReq::InternalSwap(GreeReq* other) {
  std::swap(id_, other->id_);
  name_.Swap(&other->name_);
  message_.Swap(&other->message_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GreeReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GreeReq_descriptor_;
  metadata.reflection = GreeReq_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GreeReq

// optional int32 id = 1;
void GreeReq::clear_id() {
  id_ = 0;
}
 ::google::protobuf::int32 GreeReq::id() const {
  // @@protoc_insertion_point(field_get:cpyhello.GreeReq.id)
  return id_;
}
 void GreeReq::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:cpyhello.GreeReq.id)
}

// optional string name = 2;
void GreeReq::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& GreeReq::name() const {
  // @@protoc_insertion_point(field_get:cpyhello.GreeReq.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeReq::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cpyhello.GreeReq.name)
}
 void GreeReq::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cpyhello.GreeReq.name)
}
 void GreeReq::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cpyhello.GreeReq.name)
}
 ::std::string* GreeReq::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:cpyhello.GreeReq.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* GreeReq::release_name() {
  // @@protoc_insertion_point(field_release:cpyhello.GreeReq.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeReq::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:cpyhello.GreeReq.name)
}

// optional string message = 3;
void GreeReq::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& GreeReq::message() const {
  // @@protoc_insertion_point(field_get:cpyhello.GreeReq.message)
  return message_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeReq::set_message(const ::std::string& value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cpyhello.GreeReq.message)
}
 void GreeReq::set_message(const char* value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cpyhello.GreeReq.message)
}
 void GreeReq::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cpyhello.GreeReq.message)
}
 ::std::string* GreeReq::mutable_message() {
  
  // @@protoc_insertion_point(field_mutable:cpyhello.GreeReq.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* GreeReq::release_message() {
  // @@protoc_insertion_point(field_release:cpyhello.GreeReq.message)
  
  return message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeReq::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:cpyhello.GreeReq.message)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GreeRes::kHostFieldNumber;
const int GreeRes::kMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GreeRes::GreeRes()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:cpyhello.GreeRes)
}

void GreeRes::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

GreeRes::GreeRes(const GreeRes& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:cpyhello.GreeRes)
}

void GreeRes::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  host_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

GreeRes::~GreeRes() {
  // @@protoc_insertion_point(destructor:cpyhello.GreeRes)
  SharedDtor();
}

void GreeRes::SharedDtor() {
  host_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void GreeRes::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GreeRes::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GreeRes_descriptor_;
}

const GreeRes& GreeRes::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_cpyhello_2eproto();
  return *default_instance_;
}

GreeRes* GreeRes::default_instance_ = NULL;

GreeRes* GreeRes::New(::google::protobuf::Arena* arena) const {
  GreeRes* n = new GreeRes;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GreeRes::Clear() {
// @@protoc_insertion_point(message_clear_start:cpyhello.GreeRes)
  host_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool GreeRes::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:cpyhello.GreeRes)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string host = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_host()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->host().data(), this->host().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cpyhello.GreeRes.host"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_message;
        break;
      }

      // optional string message = 2;
      case 2: {
        if (tag == 18) {
         parse_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->message().data(), this->message().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "cpyhello.GreeRes.message"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cpyhello.GreeRes)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cpyhello.GreeRes)
  return false;
#undef DO_
}

void GreeRes::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cpyhello.GreeRes)
  // optional string host = 1;
  if (this->host().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->host().data(), this->host().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeRes.host");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->host(), output);
  }

  // optional string message = 2;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeRes.message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->message(), output);
  }

  // @@protoc_insertion_point(serialize_end:cpyhello.GreeRes)
}

::google::protobuf::uint8* GreeRes::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:cpyhello.GreeRes)
  // optional string host = 1;
  if (this->host().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->host().data(), this->host().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeRes.host");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->host(), target);
  }

  // optional string message = 2;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "cpyhello.GreeRes.message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->message(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:cpyhello.GreeRes)
  return target;
}

int GreeRes::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:cpyhello.GreeRes)
  int total_size = 0;

  // optional string host = 1;
  if (this->host().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->host());
  }

  // optional string message = 2;
  if (this->message().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->message());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GreeRes::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:cpyhello.GreeRes)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const GreeRes* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const GreeRes>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:cpyhello.GreeRes)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:cpyhello.GreeRes)
    MergeFrom(*source);
  }
}

void GreeRes::MergeFrom(const GreeRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cpyhello.GreeRes)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.host().size() > 0) {

    host_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.host_);
  }
  if (from.message().size() > 0) {

    message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
}

void GreeRes::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:cpyhello.GreeRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GreeRes::CopyFrom(const GreeRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cpyhello.GreeRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GreeRes::IsInitialized() const {

  return true;
}

void GreeRes::Swap(GreeRes* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GreeRes::InternalSwap(GreeRes* other) {
  host_.Swap(&other->host_);
  message_.Swap(&other->message_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GreeRes::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GreeRes_descriptor_;
  metadata.reflection = GreeRes_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GreeRes

// optional string host = 1;
void GreeRes::clear_host() {
  host_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& GreeRes::host() const {
  // @@protoc_insertion_point(field_get:cpyhello.GreeRes.host)
  return host_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeRes::set_host(const ::std::string& value) {
  
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cpyhello.GreeRes.host)
}
 void GreeRes::set_host(const char* value) {
  
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cpyhello.GreeRes.host)
}
 void GreeRes::set_host(const char* value, size_t size) {
  
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cpyhello.GreeRes.host)
}
 ::std::string* GreeRes::mutable_host() {
  
  // @@protoc_insertion_point(field_mutable:cpyhello.GreeRes.host)
  return host_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* GreeRes::release_host() {
  // @@protoc_insertion_point(field_release:cpyhello.GreeRes.host)
  
  return host_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeRes::set_allocated_host(::std::string* host) {
  if (host != NULL) {
    
  } else {
    
  }
  host_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), host);
  // @@protoc_insertion_point(field_set_allocated:cpyhello.GreeRes.host)
}

// optional string message = 2;
void GreeRes::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& GreeRes::message() const {
  // @@protoc_insertion_point(field_get:cpyhello.GreeRes.message)
  return message_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeRes::set_message(const ::std::string& value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cpyhello.GreeRes.message)
}
 void GreeRes::set_message(const char* value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cpyhello.GreeRes.message)
}
 void GreeRes::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cpyhello.GreeRes.message)
}
 ::std::string* GreeRes::mutable_message() {
  
  // @@protoc_insertion_point(field_mutable:cpyhello.GreeRes.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* GreeRes::release_message() {
  // @@protoc_insertion_point(field_release:cpyhello.GreeRes.message)
  
  return message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void GreeRes::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:cpyhello.GreeRes.message)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace cpyhello

// @@protoc_insertion_point(global_scope)
