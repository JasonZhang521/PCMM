#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "CpuUsage.h"
#include <iostream>
using namespace Environment;

class CpuUsageTest : public ::testing::Test
{
};

TEST_F(CpuUsageTest, Test)
{
    CpuUsage usage;
    const CpuUsageEntrys& entrys = usage.getCpuUsageEntrys();
	for (CpuUsageEntrys::const_iterator it = entrys.cbegin(); it != entrys.cend(); ++it)
	{
        std::cout << *it << std::endl;
	}
	usage.update();
	for (CpuUsageEntrys::const_iterator it = entrys.cbegin(); it != entrys.cend(); ++it)
	{
        std::cout << *it << std::endl;
	}
}

