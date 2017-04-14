#include "SystemTime.h"
#include <iostream>
int main(int argc, char *argv[])
{
   std::cout << SystemTime::currentTimeStampAsMillisecond() << std::endl;
   std::cout << SystemTime::expiredTimeStampAsMillisecond(1000) << std::endl;
   return 0;
}
