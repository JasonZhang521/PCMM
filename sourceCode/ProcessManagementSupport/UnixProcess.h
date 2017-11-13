#ifndef _PROCESSMANAGEMENTSUPPORT_LINUXPROCESS_H_
#define _PROCESSMANAGEMENTSUPPORT_LINUXPROCESS_H_
#include "IUnixProcess.h"
#include "Component.h"
#include "Macro.h"

namespace ProcessManagementSupport
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
#endif // _PROCESSMANAGEMENTSUPPORT_LINUXPROCESS_H_
