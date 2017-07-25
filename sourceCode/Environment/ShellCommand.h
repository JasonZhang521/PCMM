#ifndef SHELLCOMMAND_H
#define SHELLCOMMAND_H
#include "ITimer.h"
#include "Component.h"
#include "Macro.h"
#include <string>

namespace Environment {
class ShellCommand : TimerHandler::ITimer
{
    std::string cmd_;
    std::string outPutFile_;
    std::string cmdOutput_;
    pid_t pid_;
public:
    ShellCommand(const std::string& cmd);
    ~ShellCommand();
    void execute();
    virtual void onTime();
    virtual std::ostream& operator<<(std::ostream& os);

public:
    GETCLASSNAME(ShellCommand)
};

}

#endif // SHELLCOMMAND_H
