/*
 * =====================================================================================
 *
 *       Filename:  block_line_parser.cpp
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  02/09/15 05:40:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "block_line_parser.h"

BlockLineParser::BlockLineParser(char seperator)
:seperator_(seperator)
{
}
/* Parameter:
 *   oneLineStr: one line string;
 *   result: put the string seperated by separator in the one line string into vector.
 * Return value: 
 *   the number the seperated string.
 * */
size_t BlockLineParser::operator()(const std::string& oneLineStr, std::vector<std::string>& result)
{
    /* 
     * Return value
     * the number of strings.
     * */
    size_t count = 0;
    /*
     * Begining of the searching position.
     * */
    size_t begining = 0;
    /*
     * Parsing 
     * */
    size_t pos = 0;
    /*
     * If line string is empty, return.
     * If the first character is seperator, forwarding.
     * */
    if (oneLineStr.size() <= 0)
    {
        return 0;
    }
    else
    {
        if (oneLineStr[0] == seperator_)
        {
            pos = 1;
            begining = 1;
        }
    }
    while ((pos = oneLineStr.find(seperator_, begining)) != std::string::npos)
    {
        result.push_back(oneLineStr.substr(begining, pos - begining));
        begining = pos + 1; 
    }
    /*
     * The last string
     * */
    if (begining < oneLineStr.size())
    {
        result.push_back(oneLineStr.substr(begining, oneLineStr.size() - begining));
    }
    return result.size();
}
