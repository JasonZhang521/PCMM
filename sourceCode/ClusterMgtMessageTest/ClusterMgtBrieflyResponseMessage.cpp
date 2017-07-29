#include "ClusterMgtBrieflyResponse.h"
#include "SystemInfoBriefly.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>
#include <iostream>

using namespace IpcMessage;
using namespace ClusterMgtMessage;
using namespace Environment;
using namespace Network;
using namespace Serialize;

class ClusterMgtBrieflyResponseTest : public ::testing::Test
{
};

TEST_F(ClusterMgtBrieflyResponseTest, ReadWrite)
{
	uint64_t startTimeStamp = 1000;
	uint32_t elapseTime = 500;
    MiscInfo miscInfo;
    miscInfo.setNodeStartTimeStamp(startTimeStamp);
    miscInfo.setElapseTimeFromNodeStart(elapseTime);

	const uint16_t numOfCpu = 4;
	std::string modelName("Intel");
	std::string frequency("4000M");
	int usage = 80;
	CpuInfoBriefly cpuInfo;
	cpuInfo.setNumOfCpu(numOfCpu);
	cpuInfo.setModelName(modelName);
	cpuInfo.setFrequency(frequency);
	cpuInfo.setUsage(usage);

	const std::string memTotal("1024 KB");
	const std::string memFree("512 KB");
	MemoryInfoBriefly memoryInfo;
	memoryInfo.setMemTotal(memTotal);
	memoryInfo.setMemFree(memFree);

	std::string macAddress("45:E5:32:BC");
	IpAddresses addresses;
	addresses.push_back(IpAddress("168.192.4.5"));
	addresses.push_back(IpAddress("168.192.4.6"));
	NetworkInfo networkInfo;
	networkInfo.setMacAddress(macAddress);
	networkInfo.setHostIpAddresses(addresses);

	SystemInfoBriefly info;
	info.setMiscInfo(miscInfo);
	info.setCpuInfoBriefly(cpuInfo);
	info.setMemoryInfoBriefly(memoryInfo);
	info.setNetworkInfo(networkInfo);

    ClusterMgtBrieflyResponse response;
	response.setSystemInfoBriefly(info);
	std::cout << response << std::endl;

	WriteBuffer wBuffer;
	response.serialize(wBuffer);
    ReadBuffer rBuffer;
	rBuffer.setDataSize(wBuffer.getDataSize());
	std::copy(reinterpret_cast<char*>(wBuffer.getBuffer()), reinterpret_cast<char*>(wBuffer.getBuffer()) + wBuffer.getDataSize(), reinterpret_cast<char*>(rBuffer.getBuffer()));
	ClusterMgtBrieflyResponse newResponse;
	newResponse.unserialize(rBuffer);
	std::cout << newResponse << std::endl;
    ASSERT_EQ(info, newResponse.getSystemInfoBriefly());

}
