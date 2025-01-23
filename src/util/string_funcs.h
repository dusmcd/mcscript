#ifndef _STRING_FUNCS_H
#define _STRING_FUNCS_H

#include <string>
#include <vector>

using std::string;
using std::vector;


vector<string> split(string str, char ch);
string join(vector<string>, char);
string find_and_replace(const string& str, string find, string replace, int pos = 0);
bool is_found(const string& str, string find);



#endif