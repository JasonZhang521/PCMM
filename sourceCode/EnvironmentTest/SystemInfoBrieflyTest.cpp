#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "SystemInfoBriefly.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include <iostream>
#include <string>

#ifdef WIN32
#else
#include <unistd.h>
#endif
using namespace Environment;
using namespace Serialize;
class SystemInfoBrieflyTest : public ::testing::Test
{
};

#ifdef WIN32
#else

TEST_F(SystemInfoBrieflyTest, Test)
{
    SystemInfoBriefly info;
	usleep(3000);
    info.update();
	std::cout << info << std::endl;
	usleep(3000);
	info.update();
	std::cout << info << std::endl;
}

TEST_F(SystemInfoBrieflyTest, ReadWrite)
{
	uint64_t startTimeStamp = 1000;
	uint32_t elapseTime = 500;
        MiscInfo miscInfo;
        miscInfo.setNodeStartTimeStamp(startTimeStamp);
        miscInfo.setElapseTimeFromNodeStart(elapseTime);




	WriteBuffer wBuffer;
	info1.serialize(wBuffer);
        SystemInfoBriefly info2;
	ReadBuffer rBuffer;
	rBuffer.setDataSize(wBuffer.getDataSize());
	std::copy(reinterpret_cast<char*>(wBuffer.getBuffer()), reinterpret_cast<char*>(wBuffer.getBuffer()) + wBuffer.getDataSize(), reinterpret_cast<char*>(rBuffer.getBuffer()));
	info2.unserialize(rBuffer);
	std::cout << info2 << std::endl;
	ASSERT_EQ(info2.getNodeStartTimeStamp(), startTimeStamp);
	ASSERT_EQ(info2.getElapseTimeFromNodeStart(), elapseTime);
}
#endif
