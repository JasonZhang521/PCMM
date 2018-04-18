#include "Number.h"
#include <sstream>
#include <iomanip>

Number::Number(int num)
    :num_(num)
{

}

std::string Number::getHex() const
{
    std::stringstream ss;
    ss << setiosflags(std::ios::uppercase) << std::hex << num_;
    return ss.str();
}

std::string Number::getHexAlign() const
{
    std::stringstream ss;
    ss << setiosflags(std::ios::uppercase) << std::hex << num_;
    if (ss.str().size() % 2 == 1)
    {
        return "0" + ss.str();
    }
    else
    {
        return ss.str();
    }
}
