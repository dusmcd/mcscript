#ifndef _TYPES_H
#define _TYPES_H

#include <unordered_map>
#include <string>
#include <functional>

using std::unordered_map;
using std::string;
using uint_64 = long unsigned int;

enum SyntaxType
{
    begin,
    object,
    method,
    text,
    dot,
    o_paren,
    c_paren,
    property,
    keyword,
    identifier,
    end
};

enum Operations
{
    call_method,
    declare,
    assign
};

struct Token
{
    SyntaxType type;
    string content;
};

static unordered_map<string, SyntaxType> syntax_map = {
    {"console", SyntaxType::object},
    {"log", SyntaxType::method},
    {".", SyntaxType::dot},
    {"(", SyntaxType::o_paren},
    {")", SyntaxType::c_paren},
    {"\"", SyntaxType::text},
    {"var", SyntaxType::keyword},
    {";", SyntaxType::end}
};

static unordered_map<string, Operations> operations_map = {
    {"var", Operations::declare},
    {"=", Operations::assign}
};



#endif