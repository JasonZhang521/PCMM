#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Environment.h"
#include "ShellCommandThread.h"
#include "ShellCommandOutputParse.h"
#include "LoopMain.h"
#include <thread>
#include <iostream>

#ifdef WIN32
#else
#include <unistd.h>
#endif
using namespace Environment;

class EnvironmentTest : public ::testing::Test
{
};

#ifdef WIN32
#else
static void loopControl()
{
	Core::LoopMain::instance().loopStart();
}
TEST_F(EnvironmentTest, Test)
{
	Environment::Environment env;
    IShellCommand* command = new ShellCommandThread(ShellCommandString::getCmdString(ShellCommandType::DiskUsageDf), 1000);
	env.registerShellCmd(ShellCommandType::DiskUsageDf, command);
	std::thread th(loopControl);
	while(1)
	{
		const CommandOutputString& strings = env.getShellCmdOutput(ShellCommandType::DiskUsageDf);
		if (strings.empty())
		{
			sleep(1);
			continue;
		}
		for (auto str : strings)
		{
			std::cout << str << std::endl;
		}
	    DfOutputs dfOutputs;
	    ShellCommandOutputParse::ParseDuOutput(strings, dfOutputs);
		for (auto output : dfOutputs)
		{
			std::cout << "-------------------------------------" << std::endl;
			std::cout << "mountedOn:" << output.mountedOn << std::endl;
			std::cout << "fileSystem:" << output.fileSystem << std::endl;
			std::cout << "oneKBlock:" << output.oneKBlock << std::endl;
			std::cout << "used:" << output.used << std::endl;
			std::cout << "available:" << output.available << std::endl;
			std::cout << "pecentageUsed:" << output.pecentageUsed << std::endl;
			std::cout << "-------------------------------------" << std::endl;
		}
		break;
	}
	
    command->stop();
	Core::LoopMain::instance().loopStop();
	th.join();
}

#endif
