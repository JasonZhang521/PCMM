#include "ClusterMgtMessageFactory.h"
#include "ClusterMgtBrieflyRequest.h"
#include "ClusterMgtBrieflyResponse.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

using namespace IpcMessage;
using namespace ClusterMgtMessage;

class ClusterMgtMessageFactoryTest : public ::testing::Test
{
};

TEST_F(ClusterMgtMessageFactoryTest, CreateMessage)
{
	std::unique_ptr<IIpcMessageFactory> factory(new ClusterMgtMessageFactory());
	ASSERT_EQ(factory->messageType(), IpcMessage_ClusterMgt);
	std::unique_ptr<IIpcMessage> msg1(factory->createMessage(ClusterMgtBrieflyRequestMessage));
	ASSERT_TRUE(dynamic_cast<ClusterMgtBrieflyRequest*>(msg1.get()) != nullptr);
	std::unique_ptr<IIpcMessage> msg2(factory->createMessage(ClusterMgtBrieflyResponseMessage));
	ASSERT_TRUE(dynamic_cast<ClusterMgtBrieflyResponse*>(msg2.get()) != nullptr);
}
