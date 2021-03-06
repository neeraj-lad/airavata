--
--
-- Licensed to the Apache Software Foundation (ASF) under one
-- or more contributor license agreements.  See the NOTICE file
-- distributed with this work for additional information
-- regarding copyright ownership.  The ASF licenses this file
-- to you under the Apache License, Version 2.0 (the
-- "License"); you may not use this file except in compliance
-- with the License.  You may obtain a copy of the License at
--
--   http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing,
-- software distributed under the License is distributed on an
-- "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
-- KIND, either express or implied.  See the License for the
-- specific language governing permissions and limitations
-- under the License.
--

/* Licensed to the Apache Software Foundation (ASF) under one or more contributor license agreements. See the NOTICE file
distributed with this work for additional information regarding copyright ownership. The ASF licenses this file to you under
the Apache License, Version 2.0 (theÏ "License"); you may not use this file except in compliance with the License. You may
obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0 Unless required by applicable law or agreed to
in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF
ANY ~ KIND, either express or implied. See the License for the specific language governing permissions and limitations under
the License. */

# Will migrate 0.16 DataBase schema to 0.17 Database Schema

CREATE TABLE `USER_RESOURCE_PROFILE` (
  `USER_ID` varchar(255) NOT NULL,
  `CREATION_TIME` datetime DEFAULT NULL,
  `CS_TOKEN` varchar(255) DEFAULT NULL,
  `GATEWAY_ID` varchar(255) DEFAULT NULL,
  `IDENTITY_SERVER_PWD_CRED_TOKEN` varchar(255) DEFAULT NULL,
  `IDENTITY_SERVER_TENANT` varchar(255) DEFAULT NULL,
  `UPDATE_TIME` datetime DEFAULT NULL,
  PRIMARY KEY (`USER_ID`,`GATEWAY_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE `USER_STORAGE_PREFERENCE` (
  `STORAGE_RESOURCE_ID` varchar(255) NOT NULL,
  `USER_ID` varchar(255) NOT NULL,
  `RESOURCE_CS_TOKEN` varchar(255) DEFAULT NULL,
  `FS_ROOT_LOCATION` varchar(255) DEFAULT NULL,
  `GATEWAY_ID` varchar(255) DEFAULT NULL,
  `LOGIN_USERNAME` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`STORAGE_RESOURCE_ID`,`USER_ID`,`GATEWAY_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE `CLOUD_JOB_SUBMISSION` (
  `JOB_SUBMISSION_INTERFACE_ID` varchar(255) NOT NULL,
  `EXECUTABLE_TYPE` varchar(255) DEFAULT NULL,
  `NODE_ID` varchar(255) DEFAULT NULL,
  `PROVIDER_NAME` varchar(255) DEFAULT NULL,
  `SECURITY_PROTOCOL` varchar(255) DEFAULT NULL,
  `USER_ACCOUNT_NAME` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`JOB_SUBMISSION_INTERFACE_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE `USER_COMPUTE_RESOURCE_PREFERENCE` (
  `RESOURCE_ID` varchar(255) NOT NULL,
  `USER_ID` varchar(255) NOT NULL,
  `PREFERED_BATCH_QUEUE` varchar(255) DEFAULT NULL,
  `RESOURCE_CS_TOKEN` varchar(255) DEFAULT NULL,
  `GATEWAY_ID` varchar(255) DEFAULT NULL,
  `LOGIN_USERNAME` varchar(255) DEFAULT NULL,
  `ALLOCATION_PROJECT_NUMBER` varchar(255) DEFAULT NULL,
  `QUALITY_OF_SERVICE` varchar(255) DEFAULT NULL,
  `RESERVATION` varchar(255) DEFAULT NULL,
  `RESERVATION_END_TIME` datetime DEFAULT NULL,
  `RESERVATION_START_TIME` datetime DEFAULT NULL,
  `SCRATCH_LOCATION` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`RESOURCE_ID`,`USER_ID`,`GATEWAY_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
ALTER TABLE `BATCH_QUEUE` ADD `DEFAULT_CPU_COUNT` int(11) DEFAULT NULL;
ALTER TABLE `BATCH_QUEUE` ADD `DEFAULT_NODE_COUNT` int(11) DEFAULT NULL;
ALTER TABLE `BATCH_QUEUE` ADD `IS_DEFAULT_QUEUE` bit(1) DEFAULT NULL;
ALTER TABLE `BATCH_QUEUE` ADD `CPU_PER_NODE` int(11) DEFAULT NULL;
ALTER TABLE `LOCAL_SUBMISSION` ADD `SECURITY_PROTOCOL` varchar(255) DEFAULT NULL;
ALTER TABLE `APPLICATION_DEPLOYMENT` ADD `DEFAULT_QUEUE_NAME` varchar(255) DEFAULT NULL;
ALTER TABLE `APPLICATION_DEPLOYMENT` ADD `DEFAULT_CPU_COUNT` int(11) DEFAULT NULL;
ALTER TABLE `APPLICATION_INPUT` ADD `IS_READ_ONLY` tinyint(1) NOT NULL DEFAULT '0';
ALTER TABLE `APPLICATION_DEPLOYMENT` ADD `DEFAULT_NODE_COUNT` int(11) DEFAULT NULL;
ALTER TABLE `APPLICATION_DEPLOYMENT` ADD `EDITABLE_BY_USER` bit(1) DEFAULT NULL;
ALTER TABLE `GATEWAY_CLIENT_CREDENTIAL` CHANGE `CLIENT_KEY` `CLIENT_KEY` varchar(255) NOT NULL;
