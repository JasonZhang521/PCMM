#ifndef _ENVIRONMENT_SHELLCOMMANDPROCESS_H_
#define _ENVIRONMENT_SHELLCOMMANDPROCESS_H_
#include "IShellCommand.h"
#include "ITimer.h"
#include "Component.h"
#include "Macro.h"
#include <string>

namespace Environment {
class ShellCommandProcess : public TimerHandler::ITimer, public IShellCommand
{
    std::string cmd_;
    bool oneTimeCommand_;
    std::string outPutFile_;
    pid_t pid_;
public:
    ShellCommandProcess(const std::string& cmd, bool oneTimeCommand);
    ~ShellCommandProcess();
protected:
    virtual void execute();
    virtual void stop();
    virtual bool isInactive();
    virtual void onTime();
    virtual std::ostream& operator<<(std::ostream& os);
    void getCmdOutPutFromFile();
public:
    GETCLASSNAME(ShellCommandProcess)

private:
    static std::string MagicString;
};

}

#endif // _ENVIRONMENT_SHELLCOMMANDPROCESS_H_
