#ifndef _ENVIRONMENT_SHELLCOMMANDDATATYPE_H_
#define _ENVIRONMENT_SHELLCOMMANDDATATYPE_H_
#include <map>
#include <string>
#include <vector>
#include <stdint.h>

namespace Environment {

enum class ShellCommandType
{
    DiskUsageDf,
    DiskUsageDuHome,
    InvalidType
};

class ShellCommandString
{
    static std::map<ShellCommandType, std::string> cmdTypeToCmdString_;
    static std::map<std::string, ShellCommandType> cmdStringToCmdType_;
    static const std::string InvalidCmd;
public:
    static const std::string& getCmdString(ShellCommandType cmdType);
    static ShellCommandType getCmdType(const std::string& cmdStr);
};

}
#endif // SHELLCOMMANDDATATYPE_H
