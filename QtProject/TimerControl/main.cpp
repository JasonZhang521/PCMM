#include "SystemTime.h"
#include "TimeStat.h"
#include <iostream>
int main(int argc, char *argv[])
{
   TimeStat stat;
   std::cout << SystemTime::currentTimeStampAsMillisecond() << std::endl;
   std::cout << SystemTime::expiredTimeStampAsMillisecond(1000) << std::endl;
   for (int i = 0; i < 1000000; ++i)
   {
       int j = i * i;
   }
   std::cout << stat.getElapseTimeAsMilliSecond() << std::endl;
   std::cout << SystemTime::currentTimeStampAsMillisecond() << std::endl;
   return 0;
}
