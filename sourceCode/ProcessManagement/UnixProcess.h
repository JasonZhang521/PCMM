#ifndef UNIXPROCESS_H
#define UNIXPROCESS_H
#include "IUnixProcess.h"
#include "Component.h"
#include "Macro.h"

namespace ProcessManagement
{

class UnixProcess : public IUnixProcess
{
    std::string executedBinaryPath_;
    pid_t pid_;
public:
    UnixProcess();
    ~UnixProcess();
    virtual void config(LPConfig config, const std::string&);
    virtual void startProcess();
    virtual void stopProcess();
    virtual void checkStatus();

public:
     GETCLASSNAME(IpcClient)
};

}
#endif // UNIXPROCESS_H
