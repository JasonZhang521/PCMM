/*
 * =====================================================================================
 *
 *       Filename:  block_head_parser.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/09/15 05:36:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef _BLOCK_HEAD_PARSER_H_
#define _BLOCK_HEAD_PARSER_H_
#include <vector>
#include <string>
#include <functional>
/* 
 * Parse one head string into seperated string by seperator.
 * */
class BlockHeadParser : public std::binary_function<const std::string&, std::vector<std::string>&, size_t >
{
    char seperator_;
public:
    BlockHeadParser(char seperator = '|');
    size_t operator()(const std::string& headStr, std::vector<std::string>& result);
};

#endif
