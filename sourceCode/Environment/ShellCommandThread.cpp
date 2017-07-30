#include "ShellCommandThread.h"
#include "RemoveCharacter.h"
#include "Random.h"
#include "LoopMain.h"
#include "SystemErrorInfo.h"
#include "Lock.h"
#include "Trace.h"
#include <thread>

namespace Environment {

ShellCommandThread::ShellCommandThread(const std::string& cmd, uint32_t timeout)
    : TimerHandler::ITimer(timeout)
    , cmd_(cmd)
    , excuteState_(ExcuteState::Invalid)
{

}

ShellCommandThread::~ShellCommandThread()
{

}

void ShellCommandThread::execute()
{
    excuteState_ = ExcuteState::Thread_Start;
    // start the thread
    shellCmdThread_ = std::unique_ptr<std::thread>(new std::thread(std::bind(&ShellCommandThread::startThread, this)));
    // start the timer
    Core::LoopMain::instance().registerTimer(this);
}

void ShellCommandThread::onTime()
{
    ExcuteState excuteState = ExcuteState::Invalid;

    {
        Lock lock(mutex_);
        excuteState = excuteState_;
    }

    if (excuteState == ExcuteState::Thread_Start)
    {
        resetTimer();
        Core::LoopMain::instance().registerTimer(this);
    }
    else if (excuteState == ExcuteState::Thread_Stop)
    {
        getCmdOutPutFromFile();
        excuteState_ = ExcuteState::OutPut_Retreived;
        resetTimer(5000);
        Core::LoopMain::instance().registerTimer(this);
    }
    else if (excuteState == ExcuteState::OutPut_Retreived)
    {
        execute();
    }
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
    if (outPutFile_.empty())
    {
        RemoveCharacter remover(' ', RemovePlace::LOCATION_FRONT | RemovePlace::LOCATION_MIDDLE | RemovePlace::LOCATION_END);
        const std::string filePrefix = remover(cmd_);
        Random random;
        outPutFile_ = "." + filePrefix + "." + random.generateUpLetterString(10);
    }
    const std::string cmd = cmd_ + " > " + outPutFile_;
    system(cmd.c_str());

    // set the thread stopped flag
    {
        Lock lock(mutex_);
        excuteState_ = ExcuteState::Thread_Stop;
    }
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
