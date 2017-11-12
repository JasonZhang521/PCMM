#include "UnixProcess.h"
#include <unistd.h>

namespace ProcessManagement
{

UnixProcess::UnixProcess()
{

}

UnixProcess::~UnixProcess()
{

}

void UnixProcess::config(LPConfig config, const std::string&)
{

}

void UnixProcess::startProcess()
{
    pid_t pid = fork();
    if (pid > 0)
}

void UnixProcess::stopProcess()
{

}

void UnixProcess::checkStatus()
{

}

}
