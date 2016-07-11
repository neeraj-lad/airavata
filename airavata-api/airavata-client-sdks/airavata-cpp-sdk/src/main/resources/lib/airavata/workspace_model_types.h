/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef workspace_model_TYPES_H
#define workspace_model_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "airavata_commons_types.h"


namespace apache { namespace airavata { namespace model { namespace workspace {

struct GatewayApprovalStatus {
  enum type {
    REQUESTED = 0,
    APPROVED = 1,
    ACTIVE = 2,
    DEACTIVATED = 3
  };
};

extern const std::map<int, const char*> _GatewayApprovalStatus_VALUES_TO_NAMES;

struct NotificationPriority {
  enum type {
    LOW = 0,
    NORMAL = 1,
    HIGH = 2
  };
};

extern const std::map<int, const char*> _NotificationPriority_VALUES_TO_NAMES;

class Group;

class Project;

class User;

class Gateway;

class Notification;

typedef struct _Group__isset {
  _Group__isset() : description(false) {}
  bool description :1;
} _Group__isset;

class Group {
 public:

  Group(const Group&);
  Group& operator=(const Group&);
  Group() : groupName(), description() {
  }

  virtual ~Group() throw();
  std::string groupName;
  std::string description;

  _Group__isset __isset;

  void __set_groupName(const std::string& val);

  void __set_description(const std::string& val);

  bool operator == (const Group & rhs) const
  {
    if (!(groupName == rhs.groupName))
      return false;
    if (__isset.description != rhs.__isset.description)
      return false;
    else if (__isset.description && !(description == rhs.description))
      return false;
    return true;
  }
  bool operator != (const Group &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Group & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Group &a, Group &b);

inline std::ostream& operator<<(std::ostream& out, const Group& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _Project__isset {
  _Project__isset() : description(false), creationTime(false), sharedUsers(false), sharedGroups(false) {}
  bool description :1;
  bool creationTime :1;
  bool sharedUsers :1;
  bool sharedGroups :1;
} _Project__isset;

class Project {
 public:

  Project(const Project&);
  Project& operator=(const Project&);
  Project() : projectID("DO_NOT_SET_AT_CLIENTS"), owner(), name(), description(), creationTime(0) {
  }

  virtual ~Project() throw();
  std::string projectID;
  std::string owner;
  std::string name;
  std::string description;
  int64_t creationTime;
  std::vector<std::string>  sharedUsers;
  std::vector<std::string>  sharedGroups;

  _Project__isset __isset;

  void __set_projectID(const std::string& val);

  void __set_owner(const std::string& val);

  void __set_name(const std::string& val);

  void __set_description(const std::string& val);

  void __set_creationTime(const int64_t val);

  void __set_sharedUsers(const std::vector<std::string> & val);

  void __set_sharedGroups(const std::vector<std::string> & val);

  bool operator == (const Project & rhs) const
  {
    if (!(projectID == rhs.projectID))
      return false;
    if (!(owner == rhs.owner))
      return false;
    if (!(name == rhs.name))
      return false;
    if (__isset.description != rhs.__isset.description)
      return false;
    else if (__isset.description && !(description == rhs.description))
      return false;
    if (__isset.creationTime != rhs.__isset.creationTime)
      return false;
    else if (__isset.creationTime && !(creationTime == rhs.creationTime))
      return false;
    if (__isset.sharedUsers != rhs.__isset.sharedUsers)
      return false;
    else if (__isset.sharedUsers && !(sharedUsers == rhs.sharedUsers))
      return false;
    if (__isset.sharedGroups != rhs.__isset.sharedGroups)
      return false;
    else if (__isset.sharedGroups && !(sharedGroups == rhs.sharedGroups))
      return false;
    return true;
  }
  bool operator != (const Project &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Project & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Project &a, Project &b);

inline std::ostream& operator<<(std::ostream& out, const Project& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _User__isset {
  _User__isset() : groupList(false) {}
  bool groupList :1;
} _User__isset;

class User {
 public:

  User(const User&);
  User& operator=(const User&);
  User() : userName() {
  }

  virtual ~User() throw();
  std::string userName;
  std::vector<Group>  groupList;

  _User__isset __isset;

  void __set_userName(const std::string& val);

  void __set_groupList(const std::vector<Group> & val);

  bool operator == (const User & rhs) const
  {
    if (!(userName == rhs.userName))
      return false;
    if (__isset.groupList != rhs.__isset.groupList)
      return false;
    else if (__isset.groupList && !(groupList == rhs.groupList))
      return false;
    return true;
  }
  bool operator != (const User &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const User & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(User &a, User &b);

inline std::ostream& operator<<(std::ostream& out, const User& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _Gateway__isset {
  _Gateway__isset() : gatewayName(false), domain(false), emailAddress(false), gatewayAcronym(false), gatewayURL(false), gatewayPublicAbstract(false), reviewProposalDescription(false) {}
  bool gatewayName :1;
  bool domain :1;
  bool emailAddress :1;
  bool gatewayAcronym :1;
  bool gatewayURL :1;
  bool gatewayPublicAbstract :1;
  bool reviewProposalDescription :1;
} _Gateway__isset;

class Gateway {
 public:

  Gateway(const Gateway&);
  Gateway& operator=(const Gateway&);
  Gateway() : gatewayId(), gatewayApprovalStatus((GatewayApprovalStatus::type)0), gatewayName(), domain(), emailAddress(), gatewayAcronym(), gatewayURL(), gatewayPublicAbstract(), reviewProposalDescription() {
  }

  virtual ~Gateway() throw();
  std::string gatewayId;
  GatewayApprovalStatus::type gatewayApprovalStatus;
  std::string gatewayName;
  std::string domain;
  std::string emailAddress;
  std::string gatewayAcronym;
  std::string gatewayURL;
  std::string gatewayPublicAbstract;
  std::string reviewProposalDescription;

  _Gateway__isset __isset;

  void __set_gatewayId(const std::string& val);

  void __set_gatewayApprovalStatus(const GatewayApprovalStatus::type val);

  void __set_gatewayName(const std::string& val);

  void __set_domain(const std::string& val);

  void __set_emailAddress(const std::string& val);

  void __set_gatewayAcronym(const std::string& val);

  void __set_gatewayURL(const std::string& val);

  void __set_gatewayPublicAbstract(const std::string& val);

  void __set_reviewProposalDescription(const std::string& val);

  bool operator == (const Gateway & rhs) const
  {
    if (!(gatewayId == rhs.gatewayId))
      return false;
    if (!(gatewayApprovalStatus == rhs.gatewayApprovalStatus))
      return false;
    if (__isset.gatewayName != rhs.__isset.gatewayName)
      return false;
    else if (__isset.gatewayName && !(gatewayName == rhs.gatewayName))
      return false;
    if (__isset.domain != rhs.__isset.domain)
      return false;
    else if (__isset.domain && !(domain == rhs.domain))
      return false;
    if (__isset.emailAddress != rhs.__isset.emailAddress)
      return false;
    else if (__isset.emailAddress && !(emailAddress == rhs.emailAddress))
      return false;
    if (__isset.gatewayAcronym != rhs.__isset.gatewayAcronym)
      return false;
    else if (__isset.gatewayAcronym && !(gatewayAcronym == rhs.gatewayAcronym))
      return false;
    if (__isset.gatewayURL != rhs.__isset.gatewayURL)
      return false;
    else if (__isset.gatewayURL && !(gatewayURL == rhs.gatewayURL))
      return false;
    if (__isset.gatewayPublicAbstract != rhs.__isset.gatewayPublicAbstract)
      return false;
    else if (__isset.gatewayPublicAbstract && !(gatewayPublicAbstract == rhs.gatewayPublicAbstract))
      return false;
    if (__isset.reviewProposalDescription != rhs.__isset.reviewProposalDescription)
      return false;
    else if (__isset.reviewProposalDescription && !(reviewProposalDescription == rhs.reviewProposalDescription))
      return false;
    return true;
  }
  bool operator != (const Gateway &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Gateway & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Gateway &a, Gateway &b);

inline std::ostream& operator<<(std::ostream& out, const Gateway& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _Notification__isset {
  _Notification__isset() : notificationId(false), creationTime(false), publishedTime(false), expirationTime(false), priority(false) {}
  bool notificationId :1;
  bool creationTime :1;
  bool publishedTime :1;
  bool expirationTime :1;
  bool priority :1;
} _Notification__isset;

class Notification {
 public:

  Notification(const Notification&);
  Notification& operator=(const Notification&);
  Notification() : notificationId(), gatewayId(), title(), notificationMessage(), creationTime(0), publishedTime(0), expirationTime(0), priority((NotificationPriority::type)0) {
  }

  virtual ~Notification() throw();
  std::string notificationId;
  std::string gatewayId;
  std::string title;
  std::string notificationMessage;
  int64_t creationTime;
  int64_t publishedTime;
  int64_t expirationTime;
  NotificationPriority::type priority;

  _Notification__isset __isset;

  void __set_notificationId(const std::string& val);

  void __set_gatewayId(const std::string& val);

  void __set_title(const std::string& val);

  void __set_notificationMessage(const std::string& val);

  void __set_creationTime(const int64_t val);

  void __set_publishedTime(const int64_t val);

  void __set_expirationTime(const int64_t val);

  void __set_priority(const NotificationPriority::type val);

  bool operator == (const Notification & rhs) const
  {
    if (__isset.notificationId != rhs.__isset.notificationId)
      return false;
    else if (__isset.notificationId && !(notificationId == rhs.notificationId))
      return false;
    if (!(gatewayId == rhs.gatewayId))
      return false;
    if (!(title == rhs.title))
      return false;
    if (!(notificationMessage == rhs.notificationMessage))
      return false;
    if (__isset.creationTime != rhs.__isset.creationTime)
      return false;
    else if (__isset.creationTime && !(creationTime == rhs.creationTime))
      return false;
    if (__isset.publishedTime != rhs.__isset.publishedTime)
      return false;
    else if (__isset.publishedTime && !(publishedTime == rhs.publishedTime))
      return false;
    if (__isset.expirationTime != rhs.__isset.expirationTime)
      return false;
    else if (__isset.expirationTime && !(expirationTime == rhs.expirationTime))
      return false;
    if (__isset.priority != rhs.__isset.priority)
      return false;
    else if (__isset.priority && !(priority == rhs.priority))
      return false;
    return true;
  }
  bool operator != (const Notification &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Notification & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Notification &a, Notification &b);

inline std::ostream& operator<<(std::ostream& out, const Notification& obj)
{
  obj.printTo(out);
  return out;
}

}}}} // namespace

#endif
