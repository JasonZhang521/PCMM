#ifndef SHELLCOMMANDOUTPUTPARSE_H
#define SHELLCOMMANDOUTPUTPARSE_H
#include "ShellCommandDataType.h"
#include "ShellCommandDfOutput.h"

namespace Environment {
using CommandOutputString = std::vector<std::string>;
class ShellCommandOutputParse
{
public:
    ShellCommandOutputParse();
    static void ParseDfOutput(const CommandOutputString& strs, ShellCommandDfOutputs& outPuts);
    static void ParseDuHomeOutput(const CommandOutputString& strs, uint64_t& used);
};

}

#endif // SHELLCOMMANDOUTPUTPARSE_H
