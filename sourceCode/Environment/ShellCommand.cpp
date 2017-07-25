#include "ShellCommand.h"
#include "RemoveCharacter.h"
#include "Random.h"
#include "LoopMain.h"
#include "SystemErrorInfo.h"
#include "Trace.h"
#include <stdlib.h>

#ifndef WIN32
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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
        TRACE_ERROR("fork failed: " << IoPlatformWrapper::GetLastErrorMessage() << std::endl);
    }
    // Child process
    else if (pid_ == 0)
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
