#ifndef _TYPES_H
#define _TYPES_H

#include <unordered_map>
#include <string>

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
    a_operator,
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

struct Leaf
{
    SyntaxType syntax_type;
    Leaf* children;
    int num_children;
};






#endif