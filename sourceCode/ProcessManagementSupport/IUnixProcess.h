#ifndef _PROCESSMANAGEMENTSUPPORT_ILINUXPROCESS_H_
#define _PROCESSMANAGEMENTSUPPORT_ILINUXPROCESS_H_
#include <string>
namespace ProcessManagementSupport
{

enum class LPConfig
{
    PATH
};

enum class LPStatus
{
    STARTING,
    RUNNING,
    STOPPING,
    STOPPED
};

class IUnixProcess
{
protected:
    LPStatus status_;
public:
    IUnixProcess();
    virtual ~IUnixProcess();
    virtual void config(LPConfig config, const std::string&) = 0;
    virtual void startProcess() = 0;
    virtual void stopProcess() = 0;
    LPStatus checkStatus() {return status_;}
};
}
#endif // _PROCESSMANAGEMENTSUPPORT_ILINUXPROCESS_H_
