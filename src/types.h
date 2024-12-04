#ifndef _TYPES_H
#define _TYPES_H

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;
using uint_64 = long unsigned int;

// static unordered_map<string, string> syntax_types = {
//     {"console", "object"},
//     {"log", "method"},
//     {".", "."},
//     {"\"", "\""},
//     {"(", "("},
//     {")", ")"},
// };
enum SyntaxType
{
    object,
    method,
    text,
    connector,
    property
};

struct Token
{
    string name;
    SyntaxType type;
    string content;
};



#endif