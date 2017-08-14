#include "ShellCommandDataType.h"
namespace Environment {

std::map<ShellCommandType, std::string> ShellCommandString::cmdTypeToCmdString_ =
{
    {ShellCommandType::DiskUsageDf, std::string("df")}
};

std::map<std::string, ShellCommandType> ShellCommandString::cmdStringToCmdType_ =
{
    {std::string("df"), ShellCommandType::DiskUsageDf},
    {std::string("du -s /home"), ShellCommandType::DiskUsageDuHome}
};

const std::string ShellCommandString::InvalidCmd("InvalidCmd");

const std::string& ShellCommandString::getCmdString(ShellCommandType cmdType)
{
    auto it = cmdTypeToCmdString_.find(cmdType);
    if (it == cmdTypeToCmdString_.end())
    {
        return InvalidCmd;
    }
    else
    {
        return it->second;
    }
}

ShellCommandType ShellCommandString::getCmdType(const std::string& cmdStr)
{
    auto it = cmdStringToCmdType_.find(cmdStr);
    if (it == cmdStringToCmdType_.end())
    {
        return ShellCommandType::InvalidType;
    }
    else
    {
        return it->second;
    }
}
}
