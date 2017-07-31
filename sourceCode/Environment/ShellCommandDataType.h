#ifndef SHELLCOMMANDDATATYPE_H
#define SHELLCOMMANDDATATYPE_H
#include <map>
#include <string>
namespace Environment {

enum class ShellCommandType
{
    DiskUsageDf,
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
