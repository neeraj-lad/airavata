package org.apache.airavata.registry.core.repositories.appcatalog;

import org.apache.airavata.model.appcatalog.computeresource.BatchQueue;
import org.apache.airavata.model.appcatalog.computeresource.ComputeResourceDescription;
import org.apache.airavata.model.appcatalog.groupresourceprofile.BatchQueueResourcePolicy;
import org.apache.airavata.model.appcatalog.groupresourceprofile.ComputeResourcePolicy;
import org.apache.airavata.model.appcatalog.groupresourceprofile.GroupComputeResourcePreference;
import org.apache.airavata.model.appcatalog.groupresourceprofile.GroupResourceProfile;
import org.apache.airavata.registry.core.entities.appcatalog.GroupResourceProfilePK;
import org.apache.airavata.registry.core.repositories.util.Initialize;
import org.apache.airavata.registry.cpi.AppCatalogException;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertTrue;

/**
 * Created by skariyat on 2/10/18.
 */
public class GroupResourceProfileRepositoryTest {

    private static Initialize initialize;
    private ComputeResourceRepository computeResourceRepository;
    private GroupResourceProfileRepository groupResourceProfileRepository;
    private String gatewayId = "TEST_GATEWAY";
    private String groupResourceProfileId = "TEST_GROUP_PROFILE_ID";
    private static final Logger logger = LoggerFactory.getLogger(ComputeResourceRepository.class);

    @Before
    public void setUp() {
        try {
            initialize = new Initialize("appcatalog-derby.sql");
            initialize.initializeDB();
            computeResourceRepository = new ComputeResourceRepository();
            groupResourceProfileRepository = new GroupResourceProfileRepository();
        } catch (Exception e) {
            logger.error(e.getMessage(), e);
        }
    }

    @After
    public void tearDown() throws Exception {
        System.out.println("********** TEAR DOWN ************");
        groupResourceProfileRepository.removeGroupResourceProfile(gatewayId, groupResourceProfileId);
        initialize.stopDerbyServer();
    }

    @Test
    public void GroupResourceProfileRepositoryTest() throws AppCatalogException {
        ComputeResourceDescription description = new ComputeResourceDescription();

        description.setHostName("localhost");
        description.setResourceDescription("test compute resource");
        List<String> ipdaresses = new ArrayList<String>();
        ipdaresses.add("222.33.43.444");
        ipdaresses.add("23.344.44.454");
        description.setIpAddresses(ipdaresses);

        BatchQueue batchQueue1 = new BatchQueue();
        batchQueue1.setQueueName("queue1");
        batchQueue1.setQueueDescription("que1Desc1");
        batchQueue1.setMaxRunTime(10);
        batchQueue1.setMaxNodes(4);
        batchQueue1.setMaxJobsInQueue(1);

        BatchQueue batchQueue2 = new BatchQueue();
        batchQueue2.setQueueName("queue2");
        batchQueue2.setQueueDescription("que1Desc2");
        batchQueue2.setMaxRunTime(10);
        batchQueue2.setMaxNodes(4);
        batchQueue2.setMaxJobsInQueue(1);

        List<BatchQueue> batchQueueList = new ArrayList<BatchQueue>();
        batchQueueList.add(batchQueue1);
        batchQueueList.add(batchQueue2);
        description.setBatchQueues(batchQueueList);

        String resourceId1 = computeResourceRepository.addComputeResource(description);

        ComputeResourceDescription cm2 = new ComputeResourceDescription();
        cm2.setHostName("localhost2");
        cm2.setResourceDescription("test compute host");

        BatchQueue cm_batchQueue1 = new BatchQueue();
        cm_batchQueue1.setQueueName("cmqueue1");
        cm_batchQueue1.setQueueDescription("cmque1Desc1");
        cm_batchQueue1.setMaxRunTime(10);
        cm_batchQueue1.setMaxNodes(4);
        cm_batchQueue1.setMaxJobsInQueue(1);

        BatchQueue cm_batchQueue2 = new BatchQueue();
        cm_batchQueue2.setQueueName("cmqueue2");
        cm_batchQueue2.setQueueDescription("cmque1Desc2");
        cm_batchQueue2.setMaxRunTime(10);
        cm_batchQueue2.setMaxNodes(4);
        cm_batchQueue2.setMaxJobsInQueue(1);

        List<BatchQueue> cmbatchQueueList = new ArrayList<BatchQueue>();
        cmbatchQueueList.add(cm_batchQueue1);
        cmbatchQueueList.add(cm_batchQueue2);
        cm2.setBatchQueues(cmbatchQueueList);

        String resourceId2 = computeResourceRepository.addComputeResource(cm2);

        ComputeResourceDescription computeResourceDescription = computeResourceRepository.getComputeResource(resourceId2);

        GroupResourceProfile groupResourceProfile = new GroupResourceProfile();
        groupResourceProfile.setGatewayId(gatewayId);
        groupResourceProfile.setGroupResourceProfileId(groupResourceProfileId);
        groupResourceProfile.setGroupResourceProfileName("TEST_GROUP_PROFILE_NAME");

        GroupComputeResourcePreference groupComputeResourcePreference1 = new GroupComputeResourcePreference();
        groupComputeResourcePreference1.setGatewayId(gatewayId);
        groupComputeResourcePreference1.setComputeResourceId(resourceId1);
        groupComputeResourcePreference1.setGroupResourceProfileId(groupResourceProfileId);

        GroupComputeResourcePreference groupComputeResourcePreference2 = new GroupComputeResourcePreference();
        groupComputeResourcePreference2.setGatewayId(gatewayId);
        groupComputeResourcePreference2.setComputeResourceId(resourceId2);
        groupComputeResourcePreference2.setGroupResourceProfileId(groupResourceProfileId);

        List<GroupComputeResourcePreference> groupComputeResourcePreferenceList = new ArrayList<>();
        groupComputeResourcePreferenceList.add(groupComputeResourcePreference1);
        groupComputeResourcePreferenceList.add(groupComputeResourcePreference2);

        groupResourceProfile.setComputePreferences(groupComputeResourcePreferenceList);

        ComputeResourcePolicy computeResourcePolicy = new ComputeResourcePolicy();
        computeResourcePolicy.setComputeResourceId(resourceId1);
        computeResourcePolicy.setResourcePolicyId("TEST_COM_RESOURCE_POLICY_ID1");
        computeResourcePolicy.setGroupResourceProfileId(groupResourceProfileId);
        computeResourcePolicy.setGatewayId(gatewayId);
        computeResourcePolicy.addToAllowedBatchQueues("queue1");

        ComputeResourcePolicy computeResourcePolicy2 = new ComputeResourcePolicy();
        computeResourcePolicy2.setComputeResourceId(resourceId2);
        computeResourcePolicy2.setResourcePolicyId("TEST_COM_RESOURCE_POLICY_ID2");
        computeResourcePolicy2.setGroupResourceProfileId(groupResourceProfileId);
        computeResourcePolicy2.setGatewayId(gatewayId);
        computeResourcePolicy2.addToAllowedBatchQueues("cmqueue1");

        List<ComputeResourcePolicy> computeResourcePolicyList =  new ArrayList<>();
        computeResourcePolicyList.add(computeResourcePolicy);
        computeResourcePolicyList.add(computeResourcePolicy2);

        groupResourceProfile.setComputeResourcePolicies(computeResourcePolicyList);

        BatchQueueResourcePolicy batchQueueResourcePolicy = new BatchQueueResourcePolicy();
        batchQueueResourcePolicy.setComputeResourceId(resourceId1);
        batchQueueResourcePolicy.setGroupResourceProfileId(groupResourceProfileId);
        batchQueueResourcePolicy.setResourcePolicyId("TEST_BQ_RESOURCE_POLICY_ID1");
        batchQueueResourcePolicy.setQueuename("queue1");
        batchQueueResourcePolicy.setGatewayId(gatewayId);
        batchQueueResourcePolicy.setMaxAllowedCores(2);
        batchQueueResourcePolicy.setMaxAllowedWalltime(10);

        BatchQueueResourcePolicy batchQueueResourcePolicy2 = new BatchQueueResourcePolicy();
        batchQueueResourcePolicy2.setComputeResourceId(resourceId2);
        batchQueueResourcePolicy2.setGroupResourceProfileId(groupResourceProfileId);
        batchQueueResourcePolicy2.setResourcePolicyId("TEST_BQ_RESOURCE_POLICY_ID2");
        batchQueueResourcePolicy2.setQueuename("cmqueue1");
        batchQueueResourcePolicy2.setGatewayId(gatewayId);
        batchQueueResourcePolicy2.setMaxAllowedCores(3);
        batchQueueResourcePolicy2.setMaxAllowedWalltime(12);

        List<BatchQueueResourcePolicy> batchQueueResourcePolicyList = new ArrayList<>();
        batchQueueResourcePolicyList.add(batchQueueResourcePolicy);
        batchQueueResourcePolicyList.add(batchQueueResourcePolicy2);

        groupResourceProfile.setBatchQueueResourcePolicies(batchQueueResourcePolicyList);

        groupResourceProfileRepository.addGroupResourceProfile(groupResourceProfile);

        GroupResourceProfilePK groupResourceProfilePK = new GroupResourceProfilePK();
        groupResourceProfilePK.setGatewayId(gatewayId);
        groupResourceProfilePK.setGroupResourceProfileId(groupResourceProfileId);

        if (groupResourceProfileRepository.isExists(groupResourceProfilePK)) {
            GroupResourceProfile getGroupResourceProfile = groupResourceProfileRepository.getGroupResourceProfile(gatewayId, groupResourceProfileId);

            assertTrue(getGroupResourceProfile.getGatewayId().equals(gatewayId));
            assertTrue(getGroupResourceProfile.getGroupResourceProfileId().equals(groupResourceProfileId));

            assertTrue(getGroupResourceProfile.getComputePreferences().size() == 2);
            assertTrue(getGroupResourceProfile.getComputeResourcePolicies().size() == 2);
            assertTrue(getGroupResourceProfile.getBatchQueueResourcePolicies().size() == 2);
        }

        assertTrue(groupResourceProfileRepository.getGroupComputeResourcePreference(resourceId1,groupResourceProfileId,gatewayId) != null);

        ComputeResourcePolicy getComputeResourcePolicy = groupResourceProfileRepository.getComputeResourcePolicy(groupResourceProfileId, resourceId1, "TEST_COM_RESOURCE_POLICY_ID1", gatewayId);
        assertTrue(getComputeResourcePolicy.getAllowedBatchQueues().get(0).equals("queue1"));

        BatchQueueResourcePolicy getBatchQueuePolicy = groupResourceProfileRepository.getBatchQueueResourcePolicy(groupResourceProfileId, resourceId2, "TEST_BQ_RESOURCE_POLICY_ID2", "cmqueue1", gatewayId);
        assertTrue(getBatchQueuePolicy != null);
        assertTrue(getBatchQueuePolicy.getMaxAllowedCores() == 3);
        assertTrue(getBatchQueuePolicy.getMaxAllowedWalltime() == 12);

        assertTrue(groupResourceProfileRepository.getAllGroupResourceProfiles(gatewayId).size() == 1);
        assertTrue(groupResourceProfileRepository.getAllGroupComputeResourcePreferences(groupResourceProfileId, gatewayId).size() == 2);
        assertTrue(groupResourceProfileRepository.getAllGroupComputeResourcePolicies(groupResourceProfileId, gatewayId).size() == 2);
        assertTrue(groupResourceProfileRepository.getAllGroupBatchQueueResourcePolicies(groupResourceProfileId, gatewayId).size() == 2);

        groupResourceProfileRepository.removeGroupResourceProfile(gatewayId, groupResourceProfileId);
    }
}
