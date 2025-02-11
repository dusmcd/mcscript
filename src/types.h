#ifndef _TYPES_H
#define _TYPES_H

#include <unordered_map>
#include <string>
#include <variant>
#include <vector>


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
    call_function,
    declare,
    assign,
    add,
    subtract,
    multiply,
    divide,
    return_func,
    none
};

enum Type
{
    integer,
    text,
    boolean,
    function_t,
    other
};

struct Func
{
    std::string body;
    std::vector<std::string> args;
    std::string name = "";
};

using data_t = std::variant<std::string, Func>;

struct Content
{
    data_t data = "";
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