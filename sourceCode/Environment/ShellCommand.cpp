#include "ShellCommand.h"
#include "RemoveCharacter.h"
#include "Random.h"
#include "LoopMain.h"
#include <stdlib.h>
#include <string.h>

#ifndef WIN32
#include <unistd.h>
#endif

namespace Environment {
ShellCommand::ShellCommand(const std::string& cmd)
    : TimerHandler::ITimer(100)
    , cmd_(cmd)
    , pid_(-1)
{

}

ShellCommand::~ShellCommand()
{

}

void ShellCommand::execute()
{
#ifndef WIN32
    if ((pid_ = fork()) < 0)
    {
        TRACE_ERROR("fork failed: " << strerror(errno) << std::endl);
    }
    // Child process
    else if (pid_ == 0)
    {
        if (outPutFile_.empty())
        {
            RemoveCharacter remover(' ', RemovePlace::LOCATION_FRONT | RemovePlace::LOCATION_MIDDLE | RemovePlace::LOCATION_END);
            const std::string filePrefix = remover(cmd_);
            outPutFile_ = "." + filePrefix + "." + Random::generateUpLetterString(10);
        }
        const std::string cmd = cmd_ + " > " + outPutFile_;
        system(cmd.c_str());
    }
    else
    {
        Core::LoopMain::instance().registerTimer(this);
    }
#endif
}

void ShellCommand::onTime()
{
#ifndef WIN32
    int       status;
    pid_t ret = ::waitpid(pid_, &status, WNOHANG);

    if (ret > 0)
    {
        if (!WIFEXITED(status))
        {
            execute();
        }
    }
    else if (ret == -1)
    {
        resetTimer();
        Core::LoopMain::instance().registerTimer(this);
    }
#endif
}

std::ostream& ShellCommand::operator<<(std::ostream& os)
{
    os << "["
       << "cmd=" << cmd_
       << ", outPutFile=" << outPutFile_
       << ", cmdOutput" << cmdOutput_
       << "]";
    return os;
}

}
