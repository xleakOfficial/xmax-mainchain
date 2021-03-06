// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: netmessage.proto

#ifndef PROTOBUF_netmessage_2eproto__INCLUDED
#define PROTOBUF_netmessage_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_netmessage_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsHelloMsgImpl();
void InitDefaultsHelloMsg();
void InitDefaultsVersionMsgImpl();
void InitDefaultsVersionMsg();
void InitDefaultsVerAckMsgImpl();
void InitDefaultsVerAckMsg();
void InitDefaultsAddrMsgImpl();
void InitDefaultsAddrMsg();
void InitDefaultsGetAddrMsgImpl();
void InitDefaultsGetAddrMsg();
inline void InitDefaults() {
  InitDefaultsHelloMsg();
  InitDefaultsVersionMsg();
  InitDefaultsVerAckMsg();
  InitDefaultsAddrMsg();
  InitDefaultsGetAddrMsg();
}
}  // namespace protobuf_netmessage_2eproto
namespace google {
namespace protobuf {
class AddrMsg;
class AddrMsgDefaultTypeInternal;
extern AddrMsgDefaultTypeInternal _AddrMsg_default_instance_;
class GetAddrMsg;
class GetAddrMsgDefaultTypeInternal;
extern GetAddrMsgDefaultTypeInternal _GetAddrMsg_default_instance_;
class HelloMsg;
class HelloMsgDefaultTypeInternal;
extern HelloMsgDefaultTypeInternal _HelloMsg_default_instance_;
class VerAckMsg;
class VerAckMsgDefaultTypeInternal;
extern VerAckMsgDefaultTypeInternal _VerAckMsg_default_instance_;
class VersionMsg;
class VersionMsgDefaultTypeInternal;
extern VersionMsgDefaultTypeInternal _VersionMsg_default_instance_;
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {

// ===================================================================

class HelloMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.HelloMsg) */ {
 public:
  HelloMsg();
  virtual ~HelloMsg();

  HelloMsg(const HelloMsg& from);

  inline HelloMsg& operator=(const HelloMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HelloMsg(HelloMsg&& from) noexcept
    : HelloMsg() {
    *this = ::std::move(from);
  }

  inline HelloMsg& operator=(HelloMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HelloMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HelloMsg* internal_default_instance() {
    return reinterpret_cast<const HelloMsg*>(
               &_HelloMsg_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(HelloMsg* other);
  friend void swap(HelloMsg& a, HelloMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HelloMsg* New() const PROTOBUF_FINAL { return New(NULL); }

  HelloMsg* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const HelloMsg& from);
  void MergeFrom(const HelloMsg& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(HelloMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string msg = 1;
  void clear_msg();
  static const int kMsgFieldNumber = 1;
  const ::std::string& msg() const;
  void set_msg(const ::std::string& value);
  #if LANG_CXX11
  void set_msg(::std::string&& value);
  #endif
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  ::std::string* mutable_msg();
  ::std::string* release_msg();
  void set_allocated_msg(::std::string* msg);

  // @@protoc_insertion_point(class_scope:google.protobuf.HelloMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr msg_;
  mutable int _cached_size_;
  friend struct ::protobuf_netmessage_2eproto::TableStruct;
  friend void ::protobuf_netmessage_2eproto::InitDefaultsHelloMsgImpl();
};
// -------------------------------------------------------------------

class VersionMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.VersionMsg) */ {
 public:
  VersionMsg();
  virtual ~VersionMsg();

  VersionMsg(const VersionMsg& from);

  inline VersionMsg& operator=(const VersionMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VersionMsg(VersionMsg&& from) noexcept
    : VersionMsg() {
    *this = ::std::move(from);
  }

  inline VersionMsg& operator=(VersionMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VersionMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VersionMsg* internal_default_instance() {
    return reinterpret_cast<const VersionMsg*>(
               &_VersionMsg_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(VersionMsg* other);
  friend void swap(VersionMsg& a, VersionMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VersionMsg* New() const PROTOBUF_FINAL { return New(NULL); }

  VersionMsg* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VersionMsg& from);
  void MergeFrom(const VersionMsg& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(VersionMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:google.protobuf.VersionMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_netmessage_2eproto::TableStruct;
  friend void ::protobuf_netmessage_2eproto::InitDefaultsVersionMsgImpl();
};
// -------------------------------------------------------------------

class VerAckMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.VerAckMsg) */ {
 public:
  VerAckMsg();
  virtual ~VerAckMsg();

  VerAckMsg(const VerAckMsg& from);

  inline VerAckMsg& operator=(const VerAckMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VerAckMsg(VerAckMsg&& from) noexcept
    : VerAckMsg() {
    *this = ::std::move(from);
  }

  inline VerAckMsg& operator=(VerAckMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VerAckMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VerAckMsg* internal_default_instance() {
    return reinterpret_cast<const VerAckMsg*>(
               &_VerAckMsg_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(VerAckMsg* other);
  friend void swap(VerAckMsg& a, VerAckMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VerAckMsg* New() const PROTOBUF_FINAL { return New(NULL); }

  VerAckMsg* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VerAckMsg& from);
  void MergeFrom(const VerAckMsg& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(VerAckMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:google.protobuf.VerAckMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_netmessage_2eproto::TableStruct;
  friend void ::protobuf_netmessage_2eproto::InitDefaultsVerAckMsgImpl();
};
// -------------------------------------------------------------------

class AddrMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.AddrMsg) */ {
 public:
  AddrMsg();
  virtual ~AddrMsg();

  AddrMsg(const AddrMsg& from);

  inline AddrMsg& operator=(const AddrMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AddrMsg(AddrMsg&& from) noexcept
    : AddrMsg() {
    *this = ::std::move(from);
  }

  inline AddrMsg& operator=(AddrMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AddrMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddrMsg* internal_default_instance() {
    return reinterpret_cast<const AddrMsg*>(
               &_AddrMsg_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(AddrMsg* other);
  friend void swap(AddrMsg& a, AddrMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AddrMsg* New() const PROTOBUF_FINAL { return New(NULL); }

  AddrMsg* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const AddrMsg& from);
  void MergeFrom(const AddrMsg& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(AddrMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string addrList = 1;
  int addrlist_size() const;
  void clear_addrlist();
  static const int kAddrListFieldNumber = 1;
  const ::std::string& addrlist(int index) const;
  ::std::string* mutable_addrlist(int index);
  void set_addrlist(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_addrlist(int index, ::std::string&& value);
  #endif
  void set_addrlist(int index, const char* value);
  void set_addrlist(int index, const char* value, size_t size);
  ::std::string* add_addrlist();
  void add_addrlist(const ::std::string& value);
  #if LANG_CXX11
  void add_addrlist(::std::string&& value);
  #endif
  void add_addrlist(const char* value);
  void add_addrlist(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& addrlist() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_addrlist();

  // @@protoc_insertion_point(class_scope:google.protobuf.AddrMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> addrlist_;
  mutable int _cached_size_;
  friend struct ::protobuf_netmessage_2eproto::TableStruct;
  friend void ::protobuf_netmessage_2eproto::InitDefaultsAddrMsgImpl();
};
// -------------------------------------------------------------------

class GetAddrMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.GetAddrMsg) */ {
 public:
  GetAddrMsg();
  virtual ~GetAddrMsg();

  GetAddrMsg(const GetAddrMsg& from);

  inline GetAddrMsg& operator=(const GetAddrMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GetAddrMsg(GetAddrMsg&& from) noexcept
    : GetAddrMsg() {
    *this = ::std::move(from);
  }

  inline GetAddrMsg& operator=(GetAddrMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GetAddrMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetAddrMsg* internal_default_instance() {
    return reinterpret_cast<const GetAddrMsg*>(
               &_GetAddrMsg_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(GetAddrMsg* other);
  friend void swap(GetAddrMsg& a, GetAddrMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GetAddrMsg* New() const PROTOBUF_FINAL { return New(NULL); }

  GetAddrMsg* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GetAddrMsg& from);
  void MergeFrom(const GetAddrMsg& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(GetAddrMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:google.protobuf.GetAddrMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_netmessage_2eproto::TableStruct;
  friend void ::protobuf_netmessage_2eproto::InitDefaultsGetAddrMsgImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HelloMsg

// string msg = 1;
inline void HelloMsg::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HelloMsg::msg() const {
  // @@protoc_insertion_point(field_get:google.protobuf.HelloMsg.msg)
  return msg_.GetNoArena();
}
inline void HelloMsg::set_msg(const ::std::string& value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.HelloMsg.msg)
}
#if LANG_CXX11
inline void HelloMsg::set_msg(::std::string&& value) {
  
  msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.HelloMsg.msg)
}
#endif
inline void HelloMsg::set_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.HelloMsg.msg)
}
inline void HelloMsg::set_msg(const char* value, size_t size) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.HelloMsg.msg)
}
inline ::std::string* HelloMsg::mutable_msg() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.HelloMsg.msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HelloMsg::release_msg() {
  // @@protoc_insertion_point(field_release:google.protobuf.HelloMsg.msg)
  
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HelloMsg::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.HelloMsg.msg)
}

// -------------------------------------------------------------------

// VersionMsg

// -------------------------------------------------------------------

// VerAckMsg

// -------------------------------------------------------------------

// AddrMsg

// repeated string addrList = 1;
inline int AddrMsg::addrlist_size() const {
  return addrlist_.size();
}
inline void AddrMsg::clear_addrlist() {
  addrlist_.Clear();
}
inline const ::std::string& AddrMsg::addrlist(int index) const {
  // @@protoc_insertion_point(field_get:google.protobuf.AddrMsg.addrList)
  return addrlist_.Get(index);
}
inline ::std::string* AddrMsg::mutable_addrlist(int index) {
  // @@protoc_insertion_point(field_mutable:google.protobuf.AddrMsg.addrList)
  return addrlist_.Mutable(index);
}
inline void AddrMsg::set_addrlist(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:google.protobuf.AddrMsg.addrList)
  addrlist_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void AddrMsg::set_addrlist(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:google.protobuf.AddrMsg.addrList)
  addrlist_.Mutable(index)->assign(std::move(value));
}
#endif
inline void AddrMsg::set_addrlist(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  addrlist_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.protobuf.AddrMsg.addrList)
}
inline void AddrMsg::set_addrlist(int index, const char* value, size_t size) {
  addrlist_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.AddrMsg.addrList)
}
inline ::std::string* AddrMsg::add_addrlist() {
  // @@protoc_insertion_point(field_add_mutable:google.protobuf.AddrMsg.addrList)
  return addrlist_.Add();
}
inline void AddrMsg::add_addrlist(const ::std::string& value) {
  addrlist_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.protobuf.AddrMsg.addrList)
}
#if LANG_CXX11
inline void AddrMsg::add_addrlist(::std::string&& value) {
  addrlist_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:google.protobuf.AddrMsg.addrList)
}
#endif
inline void AddrMsg::add_addrlist(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  addrlist_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.protobuf.AddrMsg.addrList)
}
inline void AddrMsg::add_addrlist(const char* value, size_t size) {
  addrlist_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.protobuf.AddrMsg.addrList)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
AddrMsg::addrlist() const {
  // @@protoc_insertion_point(field_list:google.protobuf.AddrMsg.addrList)
  return addrlist_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
AddrMsg::mutable_addrlist() {
  // @@protoc_insertion_point(field_mutable_list:google.protobuf.AddrMsg.addrList)
  return &addrlist_;
}

// -------------------------------------------------------------------

// GetAddrMsg

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_netmessage_2eproto__INCLUDED
