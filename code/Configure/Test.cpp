/*
 * Test.cpp
 *
 *  Created on: 2015��5��5��
 *      Author: euwyzbc
 */

#include <iostream>
#include "Configure.h"

int main()
{
  std::cout << "this is my first testing" << std::endl;
  Configure::getInstance().setTraceLogBufSize(1000);
  std::cout << "this is after my first testing" << std::endl;
  return 0;
}


