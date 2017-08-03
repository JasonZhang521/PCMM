#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Environment.h"
#include "ShellCommandThread.h"
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
    IShellCommand* command = new ShellCommandThread(ShellCommandString::getCmdString(ShellCommandType::DiskUsageDf), 5000);
	env.registerShellCmd(ShellCommandType::DiskUsageDf, command);
	std::thread th(loopControl);
	sleep(5);
	std::cout << "step 2" << std::endl;
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
		break;
	}
    command->stop();
	Core::LoopMain::instance().loopStop();
}

#endif
