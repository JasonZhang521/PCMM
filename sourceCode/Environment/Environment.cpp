#include "Environment.h"
#include <memory>
namespace Environment {
Environment::Environment()
{
}

Environment& Environment::instance()
{
    static std::unique_ptr<Environment> instance(new Environment());
    return *instance;
}

}
