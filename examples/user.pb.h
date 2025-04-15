// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#ifndef PROTOBUF_INCLUDED_user_2eproto
#define PROTOBUF_INCLUDED_user_2eproto

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
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_user_2eproto 

namespace protobuf_user_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_user_2eproto
namespace example {
class LoginRequest;
class LoginRequestDefaultTypeInternal;
extern LoginRequestDefaultTypeInternal _LoginRequest_default_instance_;
class LoginResponse;
class LoginResponseDefaultTypeInternal;
extern LoginResponseDefaultTypeInternal _LoginResponse_default_instance_;
class ResultCode;
class ResultCodeDefaultTypeInternal;
extern ResultCodeDefaultTypeInternal _ResultCode_default_instance_;
}  // namespace example
namespace google {
namespace protobuf {
template<> ::example::LoginRequest* Arena::CreateMaybeMessage<::example::LoginRequest>(Arena*);
template<> ::example::LoginResponse* Arena::CreateMaybeMessage<::example::LoginResponse>(Arena*);
template<> ::example::ResultCode* Arena::CreateMaybeMessage<::example::ResultCode>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace example {

// ===================================================================

class ResultCode : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.ResultCode) */ {
 public:
  ResultCode();
  virtual ~ResultCode();

  ResultCode(const ResultCode& from);

  inline ResultCode& operator=(const ResultCode& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ResultCode(ResultCode&& from) noexcept
    : ResultCode() {
    *this = ::std::move(from);
  }

  inline ResultCode& operator=(ResultCode&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ResultCode& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ResultCode* internal_default_instance() {
    return reinterpret_cast<const ResultCode*>(
               &_ResultCode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ResultCode* other);
  friend void swap(ResultCode& a, ResultCode& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ResultCode* New() const final {
    return CreateMaybeMessage<ResultCode>(NULL);
  }

  ResultCode* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ResultCode>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ResultCode& from);
  void MergeFrom(const ResultCode& from);
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
  void InternalSwap(ResultCode* other);
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

  // bytes errmsg = 2;
  void clear_errmsg();
  static const int kErrmsgFieldNumber = 2;
  const ::std::string& errmsg() const;
  void set_errmsg(const ::std::string& value);
  #if LANG_CXX11
  void set_errmsg(::std::string&& value);
  #endif
  void set_errmsg(const char* value);
  void set_errmsg(const void* value, size_t size);
  ::std::string* mutable_errmsg();
  ::std::string* release_errmsg();
  void set_allocated_errmsg(::std::string* errmsg);

  // int32 errcode = 1;
  void clear_errcode();
  static const int kErrcodeFieldNumber = 1;
  ::google::protobuf::int32 errcode() const;
  void set_errcode(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:example.ResultCode)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr errmsg_;
  ::google::protobuf::int32 errcode_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_user_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class LoginRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.LoginRequest) */ {
 public:
  LoginRequest();
  virtual ~LoginRequest();

  LoginRequest(const LoginRequest& from);

  inline LoginRequest& operator=(const LoginRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  LoginRequest(LoginRequest&& from) noexcept
    : LoginRequest() {
    *this = ::std::move(from);
  }

  inline LoginRequest& operator=(LoginRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const LoginRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LoginRequest* internal_default_instance() {
    return reinterpret_cast<const LoginRequest*>(
               &_LoginRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(LoginRequest* other);
  friend void swap(LoginRequest& a, LoginRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline LoginRequest* New() const final {
    return CreateMaybeMessage<LoginRequest>(NULL);
  }

  LoginRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<LoginRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const LoginRequest& from);
  void MergeFrom(const LoginRequest& from);
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
  void InternalSwap(LoginRequest* other);
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

  // bytes name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // bytes pwd = 2;
  void clear_pwd();
  static const int kPwdFieldNumber = 2;
  const ::std::string& pwd() const;
  void set_pwd(const ::std::string& value);
  #if LANG_CXX11
  void set_pwd(::std::string&& value);
  #endif
  void set_pwd(const char* value);
  void set_pwd(const void* value, size_t size);
  ::std::string* mutable_pwd();
  ::std::string* release_pwd();
  void set_allocated_pwd(::std::string* pwd);

  // @@protoc_insertion_point(class_scope:example.LoginRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr pwd_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_user_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class LoginResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:example.LoginResponse) */ {
 public:
  LoginResponse();
  virtual ~LoginResponse();

  LoginResponse(const LoginResponse& from);

  inline LoginResponse& operator=(const LoginResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  LoginResponse(LoginResponse&& from) noexcept
    : LoginResponse() {
    *this = ::std::move(from);
  }

  inline LoginResponse& operator=(LoginResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const LoginResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LoginResponse* internal_default_instance() {
    return reinterpret_cast<const LoginResponse*>(
               &_LoginResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(LoginResponse* other);
  friend void swap(LoginResponse& a, LoginResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline LoginResponse* New() const final {
    return CreateMaybeMessage<LoginResponse>(NULL);
  }

  LoginResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<LoginResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const LoginResponse& from);
  void MergeFrom(const LoginResponse& from);
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
  void InternalSwap(LoginResponse* other);
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

  // .example.ResultCode result = 1;
  bool has_result() const;
  void clear_result();
  static const int kResultFieldNumber = 1;
  private:
  const ::example::ResultCode& _internal_result() const;
  public:
  const ::example::ResultCode& result() const;
  ::example::ResultCode* release_result();
  ::example::ResultCode* mutable_result();
  void set_allocated_result(::example::ResultCode* result);

  // bool success = 2;
  void clear_success();
  static const int kSuccessFieldNumber = 2;
  bool success() const;
  void set_success(bool value);

  // @@protoc_insertion_point(class_scope:example.LoginResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::example::ResultCode* result_;
  bool success_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_user_2eproto::TableStruct;
};
// ===================================================================

class UserServiceRpc_Stub;

class UserServiceRpc : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline UserServiceRpc() {};
 public:
  virtual ~UserServiceRpc();

  typedef UserServiceRpc_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void login(::google::protobuf::RpcController* controller,
                       const ::example::LoginRequest* request,
                       ::example::LoginResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(UserServiceRpc);
};

class UserServiceRpc_Stub : public UserServiceRpc {
 public:
  UserServiceRpc_Stub(::google::protobuf::RpcChannel* channel);
  UserServiceRpc_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~UserServiceRpc_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements UserServiceRpc ------------------------------------------

  void login(::google::protobuf::RpcController* controller,
                       const ::example::LoginRequest* request,
                       ::example::LoginResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(UserServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ResultCode

// int32 errcode = 1;
inline void ResultCode::clear_errcode() {
  errcode_ = 0;
}
inline ::google::protobuf::int32 ResultCode::errcode() const {
  // @@protoc_insertion_point(field_get:example.ResultCode.errcode)
  return errcode_;
}
inline void ResultCode::set_errcode(::google::protobuf::int32 value) {
  
  errcode_ = value;
  // @@protoc_insertion_point(field_set:example.ResultCode.errcode)
}

// bytes errmsg = 2;
inline void ResultCode::clear_errmsg() {
  errmsg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ResultCode::errmsg() const {
  // @@protoc_insertion_point(field_get:example.ResultCode.errmsg)
  return errmsg_.GetNoArena();
}
inline void ResultCode::set_errmsg(const ::std::string& value) {
  
  errmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:example.ResultCode.errmsg)
}
#if LANG_CXX11
inline void ResultCode::set_errmsg(::std::string&& value) {
  
  errmsg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:example.ResultCode.errmsg)
}
#endif
inline void ResultCode::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  errmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:example.ResultCode.errmsg)
}
inline void ResultCode::set_errmsg(const void* value, size_t size) {
  
  errmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:example.ResultCode.errmsg)
}
inline ::std::string* ResultCode::mutable_errmsg() {
  
  // @@protoc_insertion_point(field_mutable:example.ResultCode.errmsg)
  return errmsg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ResultCode::release_errmsg() {
  // @@protoc_insertion_point(field_release:example.ResultCode.errmsg)
  
  return errmsg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResultCode::set_allocated_errmsg(::std::string* errmsg) {
  if (errmsg != NULL) {
    
  } else {
    
  }
  errmsg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), errmsg);
  // @@protoc_insertion_point(field_set_allocated:example.ResultCode.errmsg)
}

// -------------------------------------------------------------------

// LoginRequest

// bytes name = 1;
inline void LoginRequest::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequest::name() const {
  // @@protoc_insertion_point(field_get:example.LoginRequest.name)
  return name_.GetNoArena();
}
inline void LoginRequest::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:example.LoginRequest.name)
}
#if LANG_CXX11
inline void LoginRequest::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:example.LoginRequest.name)
}
#endif
inline void LoginRequest::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:example.LoginRequest.name)
}
inline void LoginRequest::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:example.LoginRequest.name)
}
inline ::std::string* LoginRequest::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:example.LoginRequest.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequest::release_name() {
  // @@protoc_insertion_point(field_release:example.LoginRequest.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequest::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:example.LoginRequest.name)
}

// bytes pwd = 2;
inline void LoginRequest::clear_pwd() {
  pwd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequest::pwd() const {
  // @@protoc_insertion_point(field_get:example.LoginRequest.pwd)
  return pwd_.GetNoArena();
}
inline void LoginRequest::set_pwd(const ::std::string& value) {
  
  pwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:example.LoginRequest.pwd)
}
#if LANG_CXX11
inline void LoginRequest::set_pwd(::std::string&& value) {
  
  pwd_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:example.LoginRequest.pwd)
}
#endif
inline void LoginRequest::set_pwd(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  pwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:example.LoginRequest.pwd)
}
inline void LoginRequest::set_pwd(const void* value, size_t size) {
  
  pwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:example.LoginRequest.pwd)
}
inline ::std::string* LoginRequest::mutable_pwd() {
  
  // @@protoc_insertion_point(field_mutable:example.LoginRequest.pwd)
  return pwd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequest::release_pwd() {
  // @@protoc_insertion_point(field_release:example.LoginRequest.pwd)
  
  return pwd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequest::set_allocated_pwd(::std::string* pwd) {
  if (pwd != NULL) {
    
  } else {
    
  }
  pwd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pwd);
  // @@protoc_insertion_point(field_set_allocated:example.LoginRequest.pwd)
}

// -------------------------------------------------------------------

// LoginResponse

// .example.ResultCode result = 1;
inline bool LoginResponse::has_result() const {
  return this != internal_default_instance() && result_ != NULL;
}
inline void LoginResponse::clear_result() {
  if (GetArenaNoVirtual() == NULL && result_ != NULL) {
    delete result_;
  }
  result_ = NULL;
}
inline const ::example::ResultCode& LoginResponse::_internal_result() const {
  return *result_;
}
inline const ::example::ResultCode& LoginResponse::result() const {
  const ::example::ResultCode* p = result_;
  // @@protoc_insertion_point(field_get:example.LoginResponse.result)
  return p != NULL ? *p : *reinterpret_cast<const ::example::ResultCode*>(
      &::example::_ResultCode_default_instance_);
}
inline ::example::ResultCode* LoginResponse::release_result() {
  // @@protoc_insertion_point(field_release:example.LoginResponse.result)
  
  ::example::ResultCode* temp = result_;
  result_ = NULL;
  return temp;
}
inline ::example::ResultCode* LoginResponse::mutable_result() {
  
  if (result_ == NULL) {
    auto* p = CreateMaybeMessage<::example::ResultCode>(GetArenaNoVirtual());
    result_ = p;
  }
  // @@protoc_insertion_point(field_mutable:example.LoginResponse.result)
  return result_;
}
inline void LoginResponse::set_allocated_result(::example::ResultCode* result) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete result_;
  }
  if (result) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      result = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, result, submessage_arena);
    }
    
  } else {
    
  }
  result_ = result;
  // @@protoc_insertion_point(field_set_allocated:example.LoginResponse.result)
}

// bool success = 2;
inline void LoginResponse::clear_success() {
  success_ = false;
}
inline bool LoginResponse::success() const {
  // @@protoc_insertion_point(field_get:example.LoginResponse.success)
  return success_;
}
inline void LoginResponse::set_success(bool value) {
  
  success_ = value;
  // @@protoc_insertion_point(field_set:example.LoginResponse.success)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace example

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_user_2eproto
