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
#include "workspace_model_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace apache { namespace airavata { namespace model { namespace workspace {

int _kGatewayApprovalStatusValues[] = {
  GatewayApprovalStatus::REQUESTED,
  GatewayApprovalStatus::APPROVED,
  GatewayApprovalStatus::ACTIVE,
  GatewayApprovalStatus::DEACTIVATED
};
const char* _kGatewayApprovalStatusNames[] = {
  "REQUESTED",
  "APPROVED",
  "ACTIVE",
  "DEACTIVATED"
};
const std::map<int, const char*> _GatewayApprovalStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kGatewayApprovalStatusValues, _kGatewayApprovalStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kNotificationPriorityValues[] = {
  NotificationPriority::LOW,
  NotificationPriority::NORMAL,
  NotificationPriority::HIGH
};
const char* _kNotificationPriorityNames[] = {
  "LOW",
  "NORMAL",
  "HIGH"
};
const std::map<int, const char*> _NotificationPriority_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kNotificationPriorityValues, _kNotificationPriorityNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


Group::~Group() throw() {
}


void Group::__set_groupName(const std::string& val) {
  this->groupName = val;
}

void Group::__set_description(const std::string& val) {
  this->description = val;
__isset.description = true;
}

uint32_t Group::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_groupName = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->groupName);
          isset_groupName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_groupName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Group::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Group");

  xfer += oprot->writeFieldBegin("groupName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->groupName);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.description) {
    xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->description);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Group &a, Group &b) {
  using ::std::swap;
  swap(a.groupName, b.groupName);
  swap(a.description, b.description);
  swap(a.__isset, b.__isset);
}

Group::Group(const Group& other0) {
  groupName = other0.groupName;
  description = other0.description;
  __isset = other0.__isset;
}
Group& Group::operator=(const Group& other1) {
  groupName = other1.groupName;
  description = other1.description;
  __isset = other1.__isset;
  return *this;
}
void Group::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Group(";
  out << "groupName=" << to_string(groupName);
  out << ", " << "description="; (__isset.description ? (out << to_string(description)) : (out << "<null>"));
  out << ")";
}


Project::~Project() throw() {
}


void Project::__set_projectID(const std::string& val) {
  this->projectID = val;
}

void Project::__set_owner(const std::string& val) {
  this->owner = val;
}

void Project::__set_name(const std::string& val) {
  this->name = val;
}

void Project::__set_description(const std::string& val) {
  this->description = val;
__isset.description = true;
}

void Project::__set_creationTime(const int64_t val) {
  this->creationTime = val;
__isset.creationTime = true;
}

void Project::__set_sharedUsers(const std::vector<std::string> & val) {
  this->sharedUsers = val;
__isset.sharedUsers = true;
}

void Project::__set_sharedGroups(const std::vector<std::string> & val) {
  this->sharedGroups = val;
__isset.sharedGroups = true;
}

uint32_t Project::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_projectID = false;
  bool isset_owner = false;
  bool isset_name = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->projectID);
          isset_projectID = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->owner);
          isset_owner = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          isset_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->creationTime);
          this->__isset.creationTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->sharedUsers.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->sharedUsers.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += iprot->readString(this->sharedUsers[_i6]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.sharedUsers = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->sharedGroups.clear();
            uint32_t _size7;
            ::apache::thrift::protocol::TType _etype10;
            xfer += iprot->readListBegin(_etype10, _size7);
            this->sharedGroups.resize(_size7);
            uint32_t _i11;
            for (_i11 = 0; _i11 < _size7; ++_i11)
            {
              xfer += iprot->readString(this->sharedGroups[_i11]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.sharedGroups = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_projectID)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_owner)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Project::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Project");

  xfer += oprot->writeFieldBegin("projectID", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->projectID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("owner", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->owner);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.description) {
    xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->description);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.creationTime) {
    xfer += oprot->writeFieldBegin("creationTime", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->creationTime);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sharedUsers) {
    xfer += oprot->writeFieldBegin("sharedUsers", ::apache::thrift::protocol::T_LIST, 6);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->sharedUsers.size()));
      std::vector<std::string> ::const_iterator _iter12;
      for (_iter12 = this->sharedUsers.begin(); _iter12 != this->sharedUsers.end(); ++_iter12)
      {
        xfer += oprot->writeString((*_iter12));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sharedGroups) {
    xfer += oprot->writeFieldBegin("sharedGroups", ::apache::thrift::protocol::T_LIST, 7);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->sharedGroups.size()));
      std::vector<std::string> ::const_iterator _iter13;
      for (_iter13 = this->sharedGroups.begin(); _iter13 != this->sharedGroups.end(); ++_iter13)
      {
        xfer += oprot->writeString((*_iter13));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Project &a, Project &b) {
  using ::std::swap;
  swap(a.projectID, b.projectID);
  swap(a.owner, b.owner);
  swap(a.name, b.name);
  swap(a.description, b.description);
  swap(a.creationTime, b.creationTime);
  swap(a.sharedUsers, b.sharedUsers);
  swap(a.sharedGroups, b.sharedGroups);
  swap(a.__isset, b.__isset);
}

Project::Project(const Project& other14) {
  projectID = other14.projectID;
  owner = other14.owner;
  name = other14.name;
  description = other14.description;
  creationTime = other14.creationTime;
  sharedUsers = other14.sharedUsers;
  sharedGroups = other14.sharedGroups;
  __isset = other14.__isset;
}
Project& Project::operator=(const Project& other15) {
  projectID = other15.projectID;
  owner = other15.owner;
  name = other15.name;
  description = other15.description;
  creationTime = other15.creationTime;
  sharedUsers = other15.sharedUsers;
  sharedGroups = other15.sharedGroups;
  __isset = other15.__isset;
  return *this;
}
void Project::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Project(";
  out << "projectID=" << to_string(projectID);
  out << ", " << "owner=" << to_string(owner);
  out << ", " << "name=" << to_string(name);
  out << ", " << "description="; (__isset.description ? (out << to_string(description)) : (out << "<null>"));
  out << ", " << "creationTime="; (__isset.creationTime ? (out << to_string(creationTime)) : (out << "<null>"));
  out << ", " << "sharedUsers="; (__isset.sharedUsers ? (out << to_string(sharedUsers)) : (out << "<null>"));
  out << ", " << "sharedGroups="; (__isset.sharedGroups ? (out << to_string(sharedGroups)) : (out << "<null>"));
  out << ")";
}


User::~User() throw() {
}


void User::__set_userName(const std::string& val) {
  this->userName = val;
}

void User::__set_groupList(const std::vector<Group> & val) {
  this->groupList = val;
__isset.groupList = true;
}

uint32_t User::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_userName = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userName);
          isset_userName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->groupList.clear();
            uint32_t _size16;
            ::apache::thrift::protocol::TType _etype19;
            xfer += iprot->readListBegin(_etype19, _size16);
            this->groupList.resize(_size16);
            uint32_t _i20;
            for (_i20 = 0; _i20 < _size16; ++_i20)
            {
              xfer += this->groupList[_i20].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.groupList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_userName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t User::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("User");

  xfer += oprot->writeFieldBegin("userName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->userName);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.groupList) {
    xfer += oprot->writeFieldBegin("groupList", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->groupList.size()));
      std::vector<Group> ::const_iterator _iter21;
      for (_iter21 = this->groupList.begin(); _iter21 != this->groupList.end(); ++_iter21)
      {
        xfer += (*_iter21).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(User &a, User &b) {
  using ::std::swap;
  swap(a.userName, b.userName);
  swap(a.groupList, b.groupList);
  swap(a.__isset, b.__isset);
}

User::User(const User& other22) {
  userName = other22.userName;
  groupList = other22.groupList;
  __isset = other22.__isset;
}
User& User::operator=(const User& other23) {
  userName = other23.userName;
  groupList = other23.groupList;
  __isset = other23.__isset;
  return *this;
}
void User::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "User(";
  out << "userName=" << to_string(userName);
  out << ", " << "groupList="; (__isset.groupList ? (out << to_string(groupList)) : (out << "<null>"));
  out << ")";
}


Gateway::~Gateway() throw() {
}


void Gateway::__set_gatewayId(const std::string& val) {
  this->gatewayId = val;
}

void Gateway::__set_gatewayApprovalStatus(const GatewayApprovalStatus::type val) {
  this->gatewayApprovalStatus = val;
}

void Gateway::__set_gatewayName(const std::string& val) {
  this->gatewayName = val;
__isset.gatewayName = true;
}

void Gateway::__set_domain(const std::string& val) {
  this->domain = val;
__isset.domain = true;
}

void Gateway::__set_emailAddress(const std::string& val) {
  this->emailAddress = val;
__isset.emailAddress = true;
}

void Gateway::__set_gatewayAcronym(const std::string& val) {
  this->gatewayAcronym = val;
__isset.gatewayAcronym = true;
}

void Gateway::__set_gatewayURL(const std::string& val) {
  this->gatewayURL = val;
__isset.gatewayURL = true;
}

void Gateway::__set_gatewayPublicAbstract(const std::string& val) {
  this->gatewayPublicAbstract = val;
__isset.gatewayPublicAbstract = true;
}

void Gateway::__set_reviewProposalDescription(const std::string& val) {
  this->reviewProposalDescription = val;
__isset.reviewProposalDescription = true;
}

void Gateway::__set_gatewayAdminFirstName(const std::string& val) {
  this->gatewayAdminFirstName = val;
__isset.gatewayAdminFirstName = true;
}

void Gateway::__set_gatewayAdminLastName(const std::string& val) {
  this->gatewayAdminLastName = val;
__isset.gatewayAdminLastName = true;
}

void Gateway::__set_gatewayAdminEmail(const std::string& val) {
  this->gatewayAdminEmail = val;
__isset.gatewayAdminEmail = true;
}

void Gateway::__set_identityServerUserName(const std::string& val) {
  this->identityServerUserName = val;
__isset.identityServerUserName = true;
}

void Gateway::__set_identityServerPasswordToken(const std::string& val) {
  this->identityServerPasswordToken = val;
__isset.identityServerPasswordToken = true;
}

uint32_t Gateway::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_gatewayId = false;
  bool isset_gatewayApprovalStatus = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayId);
          isset_gatewayId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast24;
          xfer += iprot->readI32(ecast24);
          this->gatewayApprovalStatus = (GatewayApprovalStatus::type)ecast24;
          isset_gatewayApprovalStatus = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayName);
          this->__isset.gatewayName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->domain);
          this->__isset.domain = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->emailAddress);
          this->__isset.emailAddress = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayAcronym);
          this->__isset.gatewayAcronym = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayURL);
          this->__isset.gatewayURL = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayPublicAbstract);
          this->__isset.gatewayPublicAbstract = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reviewProposalDescription);
          this->__isset.reviewProposalDescription = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayAdminFirstName);
          this->__isset.gatewayAdminFirstName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayAdminLastName);
          this->__isset.gatewayAdminLastName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayAdminEmail);
          this->__isset.gatewayAdminEmail = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->identityServerUserName);
          this->__isset.identityServerUserName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->identityServerPasswordToken);
          this->__isset.identityServerPasswordToken = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_gatewayId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_gatewayApprovalStatus)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Gateway::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Gateway");

  xfer += oprot->writeFieldBegin("gatewayId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->gatewayId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("gatewayApprovalStatus", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->gatewayApprovalStatus);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.gatewayName) {
    xfer += oprot->writeFieldBegin("gatewayName", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->gatewayName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.domain) {
    xfer += oprot->writeFieldBegin("domain", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->domain);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.emailAddress) {
    xfer += oprot->writeFieldBegin("emailAddress", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->emailAddress);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.gatewayAcronym) {
    xfer += oprot->writeFieldBegin("gatewayAcronym", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->gatewayAcronym);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.gatewayURL) {
    xfer += oprot->writeFieldBegin("gatewayURL", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->gatewayURL);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.gatewayPublicAbstract) {
    xfer += oprot->writeFieldBegin("gatewayPublicAbstract", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeString(this->gatewayPublicAbstract);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.reviewProposalDescription) {
    xfer += oprot->writeFieldBegin("reviewProposalDescription", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->reviewProposalDescription);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.gatewayAdminFirstName) {
    xfer += oprot->writeFieldBegin("gatewayAdminFirstName", ::apache::thrift::protocol::T_STRING, 10);
    xfer += oprot->writeString(this->gatewayAdminFirstName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.gatewayAdminLastName) {
    xfer += oprot->writeFieldBegin("gatewayAdminLastName", ::apache::thrift::protocol::T_STRING, 11);
    xfer += oprot->writeString(this->gatewayAdminLastName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.gatewayAdminEmail) {
    xfer += oprot->writeFieldBegin("gatewayAdminEmail", ::apache::thrift::protocol::T_STRING, 12);
    xfer += oprot->writeString(this->gatewayAdminEmail);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.identityServerUserName) {
    xfer += oprot->writeFieldBegin("identityServerUserName", ::apache::thrift::protocol::T_STRING, 13);
    xfer += oprot->writeString(this->identityServerUserName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.identityServerPasswordToken) {
    xfer += oprot->writeFieldBegin("identityServerPasswordToken", ::apache::thrift::protocol::T_STRING, 14);
    xfer += oprot->writeString(this->identityServerPasswordToken);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Gateway &a, Gateway &b) {
  using ::std::swap;
  swap(a.gatewayId, b.gatewayId);
  swap(a.gatewayApprovalStatus, b.gatewayApprovalStatus);
  swap(a.gatewayName, b.gatewayName);
  swap(a.domain, b.domain);
  swap(a.emailAddress, b.emailAddress);
  swap(a.gatewayAcronym, b.gatewayAcronym);
  swap(a.gatewayURL, b.gatewayURL);
  swap(a.gatewayPublicAbstract, b.gatewayPublicAbstract);
  swap(a.reviewProposalDescription, b.reviewProposalDescription);
  swap(a.gatewayAdminFirstName, b.gatewayAdminFirstName);
  swap(a.gatewayAdminLastName, b.gatewayAdminLastName);
  swap(a.gatewayAdminEmail, b.gatewayAdminEmail);
  swap(a.identityServerUserName, b.identityServerUserName);
  swap(a.identityServerPasswordToken, b.identityServerPasswordToken);
  swap(a.__isset, b.__isset);
}

Gateway::Gateway(const Gateway& other25) {
  gatewayId = other25.gatewayId;
  gatewayApprovalStatus = other25.gatewayApprovalStatus;
  gatewayName = other25.gatewayName;
  domain = other25.domain;
  emailAddress = other25.emailAddress;
  gatewayAcronym = other25.gatewayAcronym;
  gatewayURL = other25.gatewayURL;
  gatewayPublicAbstract = other25.gatewayPublicAbstract;
  reviewProposalDescription = other25.reviewProposalDescription;
  gatewayAdminFirstName = other25.gatewayAdminFirstName;
  gatewayAdminLastName = other25.gatewayAdminLastName;
  gatewayAdminEmail = other25.gatewayAdminEmail;
  identityServerUserName = other25.identityServerUserName;
  identityServerPasswordToken = other25.identityServerPasswordToken;
  __isset = other25.__isset;
}
Gateway& Gateway::operator=(const Gateway& other26) {
  gatewayId = other26.gatewayId;
  gatewayApprovalStatus = other26.gatewayApprovalStatus;
  gatewayName = other26.gatewayName;
  domain = other26.domain;
  emailAddress = other26.emailAddress;
  gatewayAcronym = other26.gatewayAcronym;
  gatewayURL = other26.gatewayURL;
  gatewayPublicAbstract = other26.gatewayPublicAbstract;
  reviewProposalDescription = other26.reviewProposalDescription;
  gatewayAdminFirstName = other26.gatewayAdminFirstName;
  gatewayAdminLastName = other26.gatewayAdminLastName;
  gatewayAdminEmail = other26.gatewayAdminEmail;
  identityServerUserName = other26.identityServerUserName;
  identityServerPasswordToken = other26.identityServerPasswordToken;
  __isset = other26.__isset;
  return *this;
}
void Gateway::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Gateway(";
  out << "gatewayId=" << to_string(gatewayId);
  out << ", " << "gatewayApprovalStatus=" << to_string(gatewayApprovalStatus);
  out << ", " << "gatewayName="; (__isset.gatewayName ? (out << to_string(gatewayName)) : (out << "<null>"));
  out << ", " << "domain="; (__isset.domain ? (out << to_string(domain)) : (out << "<null>"));
  out << ", " << "emailAddress="; (__isset.emailAddress ? (out << to_string(emailAddress)) : (out << "<null>"));
  out << ", " << "gatewayAcronym="; (__isset.gatewayAcronym ? (out << to_string(gatewayAcronym)) : (out << "<null>"));
  out << ", " << "gatewayURL="; (__isset.gatewayURL ? (out << to_string(gatewayURL)) : (out << "<null>"));
  out << ", " << "gatewayPublicAbstract="; (__isset.gatewayPublicAbstract ? (out << to_string(gatewayPublicAbstract)) : (out << "<null>"));
  out << ", " << "reviewProposalDescription="; (__isset.reviewProposalDescription ? (out << to_string(reviewProposalDescription)) : (out << "<null>"));
  out << ", " << "gatewayAdminFirstName="; (__isset.gatewayAdminFirstName ? (out << to_string(gatewayAdminFirstName)) : (out << "<null>"));
  out << ", " << "gatewayAdminLastName="; (__isset.gatewayAdminLastName ? (out << to_string(gatewayAdminLastName)) : (out << "<null>"));
  out << ", " << "gatewayAdminEmail="; (__isset.gatewayAdminEmail ? (out << to_string(gatewayAdminEmail)) : (out << "<null>"));
  out << ", " << "identityServerUserName="; (__isset.identityServerUserName ? (out << to_string(identityServerUserName)) : (out << "<null>"));
  out << ", " << "identityServerPasswordToken="; (__isset.identityServerPasswordToken ? (out << to_string(identityServerPasswordToken)) : (out << "<null>"));
  out << ")";
}


Notification::~Notification() throw() {
}


void Notification::__set_notificationId(const std::string& val) {
  this->notificationId = val;
__isset.notificationId = true;
}

void Notification::__set_gatewayId(const std::string& val) {
  this->gatewayId = val;
}

void Notification::__set_title(const std::string& val) {
  this->title = val;
}

void Notification::__set_notificationMessage(const std::string& val) {
  this->notificationMessage = val;
}

void Notification::__set_creationTime(const int64_t val) {
  this->creationTime = val;
__isset.creationTime = true;
}

void Notification::__set_publishedTime(const int64_t val) {
  this->publishedTime = val;
__isset.publishedTime = true;
}

void Notification::__set_expirationTime(const int64_t val) {
  this->expirationTime = val;
__isset.expirationTime = true;
}

void Notification::__set_priority(const NotificationPriority::type val) {
  this->priority = val;
__isset.priority = true;
}

uint32_t Notification::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_gatewayId = false;
  bool isset_title = false;
  bool isset_notificationMessage = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->notificationId);
          this->__isset.notificationId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->gatewayId);
          isset_gatewayId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->title);
          isset_title = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->notificationMessage);
          isset_notificationMessage = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->creationTime);
          this->__isset.creationTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->publishedTime);
          this->__isset.publishedTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->expirationTime);
          this->__isset.expirationTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast27;
          xfer += iprot->readI32(ecast27);
          this->priority = (NotificationPriority::type)ecast27;
          this->__isset.priority = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_gatewayId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_title)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_notificationMessage)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Notification::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Notification");

  if (this->__isset.notificationId) {
    xfer += oprot->writeFieldBegin("notificationId", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->notificationId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("gatewayId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->gatewayId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("title", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->title);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("notificationMessage", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->notificationMessage);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.creationTime) {
    xfer += oprot->writeFieldBegin("creationTime", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->creationTime);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.publishedTime) {
    xfer += oprot->writeFieldBegin("publishedTime", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->publishedTime);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.expirationTime) {
    xfer += oprot->writeFieldBegin("expirationTime", ::apache::thrift::protocol::T_I64, 7);
    xfer += oprot->writeI64(this->expirationTime);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.priority) {
    xfer += oprot->writeFieldBegin("priority", ::apache::thrift::protocol::T_I32, 8);
    xfer += oprot->writeI32((int32_t)this->priority);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Notification &a, Notification &b) {
  using ::std::swap;
  swap(a.notificationId, b.notificationId);
  swap(a.gatewayId, b.gatewayId);
  swap(a.title, b.title);
  swap(a.notificationMessage, b.notificationMessage);
  swap(a.creationTime, b.creationTime);
  swap(a.publishedTime, b.publishedTime);
  swap(a.expirationTime, b.expirationTime);
  swap(a.priority, b.priority);
  swap(a.__isset, b.__isset);
}

Notification::Notification(const Notification& other28) {
  notificationId = other28.notificationId;
  gatewayId = other28.gatewayId;
  title = other28.title;
  notificationMessage = other28.notificationMessage;
  creationTime = other28.creationTime;
  publishedTime = other28.publishedTime;
  expirationTime = other28.expirationTime;
  priority = other28.priority;
  __isset = other28.__isset;
}
Notification& Notification::operator=(const Notification& other29) {
  notificationId = other29.notificationId;
  gatewayId = other29.gatewayId;
  title = other29.title;
  notificationMessage = other29.notificationMessage;
  creationTime = other29.creationTime;
  publishedTime = other29.publishedTime;
  expirationTime = other29.expirationTime;
  priority = other29.priority;
  __isset = other29.__isset;
  return *this;
}
void Notification::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Notification(";
  out << "notificationId="; (__isset.notificationId ? (out << to_string(notificationId)) : (out << "<null>"));
  out << ", " << "gatewayId=" << to_string(gatewayId);
  out << ", " << "title=" << to_string(title);
  out << ", " << "notificationMessage=" << to_string(notificationMessage);
  out << ", " << "creationTime="; (__isset.creationTime ? (out << to_string(creationTime)) : (out << "<null>"));
  out << ", " << "publishedTime="; (__isset.publishedTime ? (out << to_string(publishedTime)) : (out << "<null>"));
  out << ", " << "expirationTime="; (__isset.expirationTime ? (out << to_string(expirationTime)) : (out << "<null>"));
  out << ", " << "priority="; (__isset.priority ? (out << to_string(priority)) : (out << "<null>"));
  out << ")";
}

}}}} // namespace
