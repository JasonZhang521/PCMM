#include "IShellCommand.h"
namespace Environment {
IShellCommand::IShellCommand()
{

}

IShellCommand::~IShellCommand()
{

}

const std::vector<std::string>& IShellCommand::getCommandOutput() const
{
    return cmdOutput_;
}

}
