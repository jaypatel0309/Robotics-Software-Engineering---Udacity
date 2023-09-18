// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#ifndef PROTOBUF_header_2eproto__INCLUDED
#define PROTOBUF_header_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "time.pb.h"
// @@protoc_insertion_point(includes)

namespace gazebo {
namespace msgs {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_header_2eproto();
void protobuf_AssignDesc_header_2eproto();
void protobuf_ShutdownFile_header_2eproto();

class Header;

// ===================================================================

class Header : public ::google::protobuf::Message {
 public:
  Header();
  virtual ~Header();

  Header(const Header& from);

  inline Header& operator=(const Header& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Header& default_instance();

  void Swap(Header* other);

  // implements Message ----------------------------------------------

  Header* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Header& from);
  void MergeFrom(const Header& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string str_id = 1;
  inline bool has_str_id() const;
  inline void clear_str_id();
  static const int kStrIdFieldNumber = 1;
  inline const ::std::string& str_id() const;
  inline void set_str_id(const ::std::string& value);
  inline void set_str_id(const char* value);
  inline void set_str_id(const char* value, size_t size);
  inline ::std::string* mutable_str_id();
  inline ::std::string* release_str_id();
  inline void set_allocated_str_id(::std::string* str_id);

  // optional .gazebo.msgs.Time stamp = 2;
  inline bool has_stamp() const;
  inline void clear_stamp();
  static const int kStampFieldNumber = 2;
  inline const ::gazebo::msgs::Time& stamp() const;
  inline ::gazebo::msgs::Time* mutable_stamp();
  inline ::gazebo::msgs::Time* release_stamp();
  inline void set_allocated_stamp(::gazebo::msgs::Time* stamp);

  // optional int32 index = 3;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 3;
  inline ::google::protobuf::int32 index() const;
  inline void set_index(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:gazebo.msgs.Header)
 private:
  inline void set_has_str_id();
  inline void clear_has_str_id();
  inline void set_has_stamp();
  inline void clear_has_stamp();
  inline void set_has_index();
  inline void clear_has_index();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* str_id_;
  ::gazebo::msgs::Time* stamp_;
  ::google::protobuf::int32 index_;
  friend void  protobuf_AddDesc_header_2eproto();
  friend void protobuf_AssignDesc_header_2eproto();
  friend void protobuf_ShutdownFile_header_2eproto();

  void InitAsDefaultInstance();
  static Header* default_instance_;
};
// ===================================================================


// ===================================================================

// Header

// optional string str_id = 1;
inline bool Header::has_str_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Header::set_has_str_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Header::clear_has_str_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Header::clear_str_id() {
  if (str_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_id_->clear();
  }
  clear_has_str_id();
}
inline const ::std::string& Header::str_id() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.Header.str_id)
  return *str_id_;
}
inline void Header::set_str_id(const ::std::string& value) {
  set_has_str_id();
  if (str_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_id_ = new ::std::string;
  }
  str_id_->assign(value);
  // @@protoc_insertion_point(field_set:gazebo.msgs.Header.str_id)
}
inline void Header::set_str_id(const char* value) {
  set_has_str_id();
  if (str_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_id_ = new ::std::string;
  }
  str_id_->assign(value);
  // @@protoc_insertion_point(field_set_char:gazebo.msgs.Header.str_id)
}
inline void Header::set_str_id(const char* value, size_t size) {
  set_has_str_id();
  if (str_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_id_ = new ::std::string;
  }
  str_id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:gazebo.msgs.Header.str_id)
}
inline ::std::string* Header::mutable_str_id() {
  set_has_str_id();
  if (str_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:gazebo.msgs.Header.str_id)
  return str_id_;
}
inline ::std::string* Header::release_str_id() {
  clear_has_str_id();
  if (str_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = str_id_;
    str_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Header::set_allocated_str_id(::std::string* str_id) {
  if (str_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete str_id_;
  }
  if (str_id) {
    set_has_str_id();
    str_id_ = str_id;
  } else {
    clear_has_str_id();
    str_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:gazebo.msgs.Header.str_id)
}

// optional .gazebo.msgs.Time stamp = 2;
inline bool Header::has_stamp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Header::set_has_stamp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Header::clear_has_stamp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Header::clear_stamp() {
  if (stamp_ != NULL) stamp_->::gazebo::msgs::Time::Clear();
  clear_has_stamp();
}
inline const ::gazebo::msgs::Time& Header::stamp() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.Header.stamp)
  return stamp_ != NULL ? *stamp_ : *default_instance_->stamp_;
}
inline ::gazebo::msgs::Time* Header::mutable_stamp() {
  set_has_stamp();
  if (stamp_ == NULL) stamp_ = new ::gazebo::msgs::Time;
  // @@protoc_insertion_point(field_mutable:gazebo.msgs.Header.stamp)
  return stamp_;
}
inline ::gazebo::msgs::Time* Header::release_stamp() {
  clear_has_stamp();
  ::gazebo::msgs::Time* temp = stamp_;
  stamp_ = NULL;
  return temp;
}
inline void Header::set_allocated_stamp(::gazebo::msgs::Time* stamp) {
  delete stamp_;
  stamp_ = stamp;
  if (stamp) {
    set_has_stamp();
  } else {
    clear_has_stamp();
  }
  // @@protoc_insertion_point(field_set_allocated:gazebo.msgs.Header.stamp)
}

// optional int32 index = 3;
inline bool Header::has_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Header::set_has_index() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Header::clear_has_index() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Header::clear_index() {
  index_ = 0;
  clear_has_index();
}
inline ::google::protobuf::int32 Header::index() const {
  // @@protoc_insertion_point(field_get:gazebo.msgs.Header.index)
  return index_;
}
inline void Header::set_index(::google::protobuf::int32 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:gazebo.msgs.Header.index)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace gazebo

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_header_2eproto__INCLUDED
