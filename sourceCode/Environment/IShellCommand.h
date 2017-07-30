#ifndef _ENVIRONMENT_ISHELLCOMMAND_H_
#define _ENVIRONMENT_ISHELLCOMMAND_H_
#include <vector>
#include <string>

namespace Environment {
class IShellCommand
{
protected:
    std::vector<std::string> cmdOutput_;
public:
    IShellCommand();
    ~IShellCommand();
    virtual void execute() = 0;
    virtual const std::vector<std::string>& getCommandOutput() const;
};
}

#endif // _ENVIRONMENT_ISHELLCOMMAND_H_
