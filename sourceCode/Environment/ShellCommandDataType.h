#ifndef SHELLCOMMANDDATATYPE_H
#define SHELLCOMMANDDATATYPE_H
#include <map>
#include <string>
#include <vector>
#include <stdint.h>

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



/* *** df output
 *
Filesystem        1K-blocks      Used Available Use% Mounted on
/dev/sda2             57591044  20032372  34633156  37% /
tmpfs                  1019896       276   1019620   1% /dev/shm
/dev/sda1               297485     30366    251759  11% /boot
/dev/sr0               3351190   3351190         0 100% /media/RHEL_6.0 x86_64 Disc 1
*/
struct DfOutput
{
    std::string fileSystem;
    uint64_t oneKBlock = 0;
    uint64_t used = 0;
    uint64_t available = 0;
    uint8_t pecentageUsed = 0;
    std::string mountedOn = 0;
};

using DfOutputs = std::vector<DfOutput>;

}
#endif // SHELLCOMMANDDATATYPE_H
