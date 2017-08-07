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
    static void ParseDuOutput(const CommandOutputString strs, ShellCommandDfOutputs& outPuts);
};

}

#endif // SHELLCOMMANDOUTPUTPARSE_H
