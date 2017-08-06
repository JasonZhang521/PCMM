#ifndef _ENVIRONMENT_ISHELLCOMMAND_H_
#define _ENVIRONMENT_ISHELLCOMMAND_H_
#include <vector>
#include <string>

namespace Environment {
using CommandOutputString = std::vector<std::string>;
static const CommandOutputString InvalidCommandOutputString;
class IShellCommand
{
protected:
    std::vector<std::string> cmdOutput_;
public:
    IShellCommand();
    virtual ~IShellCommand();
    virtual void execute() = 0;
    virtual void stop() = 0;
    virtual bool isInactive() = 0;
    virtual const CommandOutputString& getCommandOutput() const;
};
}

#endif // _ENVIRONMENT_ISHELLCOMMAND_H_
