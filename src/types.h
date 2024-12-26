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
    u_object,
    dot,
    o_paren,
    c_paren,
    property,
    keyword,
    identifier,
    operator_t,
    end
};

enum Operations
{
    call_method,
    declare,
    assign,
    add
};

enum Type
{
    integer,
    text,
    boolean,
    other
};

struct Content
{
    string data;
    Type type;
};

struct Token
{
    SyntaxType type;
    Content content;
};

struct Leaf
{
    SyntaxType syntax_type;
    Leaf* children;
    int num_children;
};






#endif