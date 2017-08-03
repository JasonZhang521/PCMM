#include "ShellCommandThread.h"
#include "RemoveCharacter.h"
#include "Random.h"
#include "LoopMain.h"
#include "SystemErrorInfo.h"
#include "Lock.h"
#include "Trace.h"
#include <thread>
#include <iostream>

namespace Environment {

ShellCommandThread::ShellCommandThread(const std::string& cmd, uint32_t timeout)
    : TimerHandler::ITimer(timeout)
    , cmd_(cmd)
    , excuteState_(ExcuteState::InActive)
{

}

ShellCommandThread::~ShellCommandThread()
{
    shellCmdThread_->join();
}

void ShellCommandThread::execute()
{
    excuteState_ = ExcuteState::Command_Start;
    // start the thread
    shellCmdThread_ = std::unique_ptr<std::thread>(new std::thread(std::bind(&ShellCommandThread::startThread, this)));
    // start the timer
    Core::LoopMain::instance().registerTimer(this);
}

void ShellCommandThread::stop()
{
    Core::LoopMain::instance().deRegisterTimer(getTimerId());

    Lock lock(mutex_);
    if (excuteState_ == ExcuteState::Command_Start)
    {
        excuteState_ = ExcuteState::Thread_Stop;
    }
    else
    {
        excuteState_ = ExcuteState::InActive;
    }
}

void ShellCommandThread::onTime()
{
	std::cout << "onTime" << std::endl;
    ExcuteState excuteState = ExcuteState::InActive;

    {
        Lock lock(mutex_);
        excuteState = excuteState_;
    }

    if (excuteState == ExcuteState::Command_Start)
    {
		std::cout << "ExcuteState::Command_Start" << std::endl;
        resetTimer();
        Core::LoopMain::instance().registerTimer(this);
    }
    else if (excuteState == ExcuteState::Command_Stop)
    {
		std::cout << "ExcuteState::Command_Stop" << std::endl;
        getCmdOutPutFromFile();
        excuteState_ = ExcuteState::OutPut_Retreived;
        resetTimer(5000);
        Core::LoopMain::instance().registerTimer(this);
    }
    else if (excuteState == ExcuteState::OutPut_Retreived)
    {
		std::cout << "ExcuteState::OutPut_Retreived" << std::endl;
        execute();
    }
}

bool ShellCommandThread::isInactive()
{
    return (excuteState_ == ExcuteState::InActive);
}

std::ostream& ShellCommandThread::operator<<(std::ostream& os)
{
    os << "["
       << "cmd=" << cmd_
       << ", outPutFile=" << outPutFile_
       << ", cmdOutput=";
    for (auto str : cmdOutput_)
    {
        os << str << std::endl;
    }
    os << "]";
    return os;
}

void ShellCommandThread::startThread()
{
	std::cout << "startThread" << std::endl;
    if (outPutFile_.empty())
    {
        RemoveCharacter remover(' ', RemovePlace::LOCATION_FRONT | RemovePlace::LOCATION_MIDDLE | RemovePlace::LOCATION_END);
        const std::string filePrefix = remover(cmd_);
        Random random;
        outPutFile_ = "." + filePrefix + "." + random.generateUpLetterString(10);
    }
	std::cout << "outPutFile:" << outPutFile_ << std::endl;
    const std::string cmd = cmd_ + " > " + outPutFile_;
	std::cout << "cmd:" << cmd << std::endl;
    system(cmd.c_str());

	std::cout << "cmd end:" << cmd << std::endl;
    // set the thread stopped flag
    {
        Lock lock(mutex_);
        if (excuteState_ == ExcuteState::Command_Start)
        {
            excuteState_ = ExcuteState::Command_Stop;
        }
        else if (excuteState_ == ExcuteState::Thread_Stop)
        {
            excuteState_ = ExcuteState::InActive;
        }
    }
	std::cout << "thread end:" << cmd << std::endl;
}

void ShellCommandThread::getCmdOutPutFromFile()
{
    std::ifstream ifs(outPutFile_.c_str());

    if (!ifs.good())
    {
        TRACE_WARNING("Failed to open file: " << outPutFile_ << ", stop reading, try next time." << std::endl);
        return;
    }
    std::vector<std::string> lines;
    char buffer[512];
    while(ifs.good())
    {
        std::fill(buffer, buffer + 512, 0);
        ifs.getline(buffer, 512);
        std::stringstream ss;
        ss << buffer;
        std::string oneline = ss.str();
        lines.push_back(oneline);
    }

    if (!lines.empty())
    {
        cmdOutput_.swap(lines);
    }
}

}
