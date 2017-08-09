#include "DiskUsageInfo.h"
#include "ShellCommandDataType.h"
#include "ShellCommandOutputParse.h"
#include "Environment.h"
#include "ShellCommandDfOutput.h"
#include <ostream>
namespace Environment {
DiskUsageInfo::DiskUsageInfo()
{

}

void DiskUsageInfo::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    rootDirUsage_.serialize(writeBuffer);
    bootInitDirUsage_.serialize(writeBuffer);
}

void DiskUsageInfo::unserialize(Serialize::ReadBuffer& readBuffer)
{
    rootDirUsage_.unserialize(readBuffer);
    bootInitDirUsage_.unserialize(readBuffer);
}

std::ostream& DiskUsageInfo::operator <<(std::ostream& os) const
{
    os << "["
       << "rootDirUsage=" << rootDirUsage_
       << ", bootInitDirUsage=" << bootInitDirUsage_
       << "]";
    return os;
}

bool DiskUsageInfo::operator ==(const DiskUsageInfo& info) const
{
    return (rootDirUsage_ == info.rootDirUsage_ &&
            bootInitDirUsage_ == info.bootInitDirUsage_);
}

void DiskUsageInfo::update()
{
    using CommandOutputString = std::vector<std::string>;
    const CommandOutputString& strs = Environment::instance().getShellCmdOutput(ShellCommandType::DiskUsageDf);
    ShellCommandDfOutputs dfOutputs;
    ShellCommandOutputParse::ParseDfOutput(strs, dfOutputs);
    for (auto dfOutput : dfOutputs)
    {
        if (dfOutput.getMountedOn() == std::string("/"))
        {
            rootDirUsage_ = dfOutput;
        }

        if (dfOutput.getMountedOn() == std::string("/boot"))
        {
            bootInitDirUsage_ = dfOutput;
        }
    }

}

}
