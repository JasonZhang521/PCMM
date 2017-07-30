#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <stdint.h>
namespace Environment {
class Environment
{

public:
    Environment();
    static Environment& instance();
    void registerShellCmd(const std::string& cmd);
};
}

#endif // ENVIRONMENT_H
