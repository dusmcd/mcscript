#ifndef _STRING_FUNCS_H
#define _STRING_FUNCS_H

#include <string>
#include <vector>



std::vector<std::string> split(std::string str, char ch);
std::string join(std::vector<std::string>, char);
std::string find_and_replace(const std::string& str, std::string find, std::string replace, int pos = 0);
bool is_found(const std::string& str, std::string find);



#endif