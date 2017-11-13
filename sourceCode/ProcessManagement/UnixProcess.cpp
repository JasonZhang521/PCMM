#include "UnixProcess.h"
#include "FilePathHandler.h"
#include "Trace.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

namespace ProcessManagement
{

UnixProcess::UnixProcess()
{

}

UnixProcess::~UnixProcess()
{

}

void UnixProcess::config(LPConfig config, const std::string& val)
{
    if (LPConfig::PATH == config)
    {
        executedBinaryPath_ = val;
    }
}

void UnixProcess::startProcess()
{
    pid_t pid = fork();
    // parent process
    if (pid > 0)
    {
        pid_ = pid;
    }
    else if (pid == 0)
    {
        const std::string processName = FilePathHandler::getFileName();
        execl(executedBinaryPath_.c_str(), processName.c_str());
    }
    else
    {
        TRACE_ERROR("Can not fork the process:" << executedBinaryPath_);
    }
}

void UnixProcess::stopProcess()
{
    kill(pid_, 9);
}

void UnixProcess::checkStatus()
{
    int status = -1;
    waitpid(pid, &status, WNOHANG);
    if (WIFEXITED(status))
    {
        status_ = LPStatus::STOPPED;
        TRACE_NOTICE("process id=" << pid << " exit normally, exit status =" << WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        status_ = LPStatus::STOPPED;
        TRACE_NOTICE("process id=" << pid << " exit by signal, signal is " << WTERMSIG(status));
        if (WCOREDUMP(status))
        {
            TRACE_NOTICE("process id=" << pid << "core dumped");
        }
    }
    else
    {
        status_ = LPStatus::RUNNING;
    }
}

}
