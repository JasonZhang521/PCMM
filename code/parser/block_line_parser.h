/*
 * =====================================================================================
 *
 *       Filename:  block_line_parser.h
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
#ifndef _BLOCK_LINE_PARSER_H_
#define _BLOCK_LINE_PARSER_H_
#include <vector>
#include <string>
/* 
 * Parse one line string into seperated string by seperator.
 * */
class BlockLineParser : public std::binary_function<const std::string&, std::vector<std::string>&, size_t >
{
    char seperator_;
public:
    BlockLineParser(char seperator = '|');
    size_t operator()(const std::string& oneLineStr, std::vector<std::string>& result);
};

#endif
