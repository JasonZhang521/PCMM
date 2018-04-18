#ifndef _COMMON_NUMBER_H_
#define _COMMON_NUMBER_H_
#include <string>

class Number
{
    int num_;
public:
    Number(int num);
    std::string getHex() const;
    std::string getHexAlign() const;

};

#endif // _COMMON_NUMBER_H_
