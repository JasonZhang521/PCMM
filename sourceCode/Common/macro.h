#ifndef _MACRO_H_
#define _MACRO_H_

#define STRING(str) #str
#define GETCLASSNAME(name) static const std::string className() \
                           {                           \
                                  return component() + \
                                         std::string("::") +\
                                         std::string(#name);\
                           }

#endif // MACRO_H
