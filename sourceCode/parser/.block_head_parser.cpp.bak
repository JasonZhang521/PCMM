/*
 * =====================================================================================
 *
 *       Filename:  block_head_parser.cpp
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
#include <set>
#include <map>
#include "pdc_exception.h"
#include "block_head_parser.h"
#include "remove_character.h"
BlockHeadParser::BlockHeadParser(char seperator)
:seperator_(seperator)
{
}
/* Parameter:
 *   headStr: head string;
 *   result: put the string seperated by separator in the head string into vector.
 * Return value: 
 *   the number the seperated string.
 * */
size_t BlockHeadParser::operator()(const std::string& headStr, std::vector<std::string>& result)
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
    if (headStr.size() <= 0)
    {
        return 0;
    }
    else
    {
        if (headStr[0] == seperator_)
        {
            pos = 1;
            begining = 1;
        }
    }
    std::set<std::string> duplicatedStringSet;
    std::map<std::string, size_t> stringCountMap;
    std::string subString;
    RemoveCharacter remover;
    while ((pos = headStr.find(seperator_, begining)) != std::string::npos)
    { 
        subString = headStr.substr(begining, pos - begining); 
        /*
         * If the String is appear more than once, recored it into set.
         * */
        subString = remover(subString);
        if(++stringCountMap[subString] > 1)
        {
            duplicatedStringSet.insert(subString);
        }
        result.push_back(subString);
        begining = pos + 1; 
    }
    /*
     * The last string
     * */
    if (begining < headStr.size())
    {
        subString = headStr.substr(begining,  headStr.size() - begining); 
        /*
         * If the String is appear more than once, recored it into set.
         * */
        subString = remover(subString);
        if(++stringCountMap[subString] > 1)
        {
            duplicatedStringSet.insert(subString);
        }
        result.push_back(subString);
    }
    /*
     * Rebuild the strings in the vector - change the duplicated name.
     * */
    for (size_t i = 0; i < result.size(); ++i)
    {
        static std::string prefixString;
        static bool needResetPrefix = true;
        if (duplicatedStringSet.find(result[i]) != duplicatedStringSet.end())
        {
            if (i == 0)
            {
                throw PdcException("error in put head string, the first item can not be duplicated!");
            }
            if (needResetPrefix)
            {
                needResetPrefix = false;
                prefixString = result[i - 1];
            }
            result[i] = prefixString + std::string(":") + result[i];
        }
        else
        {
            needResetPrefix = true;
        }
    }
    return result.size();
}
