#ifndef _CONFIGUREMANAGMENT_MAUICONFIG_H_
#define _CONFIGUREMANAGMENT_MAUICONFIG_H_
#include <stdint.h>
#include <string>

namespace ConfigureManagement {
class MauiConfig
{
    uint16_t serverPort_;
    std::string jobNodeMatchPolicy_;
public:
    MauiConfig();
};
}

#endif // _CONFIGUREMANAGMENT_MAUICONFIG_H_
