#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "ShellCommandDataType.h"
#include "IShellCommand.h"
#include <string>
#include <memory>
#include <stdint.h>
namespace Environment {
class Environment
{
    using CmdDb = std::map<ShellCommandType, std::unique_ptr<IShellCommand> >;
    CmdDb cmdDb_;
public:
    Environment();
    static Environment& instance();
    void registerShellCmd(ShellCommandType cmdType, IShellCommand* cmd);
    void deRegisterShellCmd(ShellCommandType cmdType);
    const CommandOutputString& getShellCmdOutput(ShellCommandType cmdType);
};
}

#endif // ENVIRONMENT_H
