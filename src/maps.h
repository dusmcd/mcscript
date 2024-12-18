#ifndef _MAPS_H
#define _MAPS_H

#include <unordered_map>
#include "types.h"

using std::unordered_map;

static unordered_map<string, SyntaxType> syntax_map = {
    {"console", SyntaxType::object},
    {"log", SyntaxType::method},
    {".", SyntaxType::dot},
    {"(", SyntaxType::o_paren},
    {")", SyntaxType::c_paren},
    {"\"", SyntaxType::text},
    {"var", SyntaxType::keyword},
    {"=", SyntaxType::a_operator},
    {";", SyntaxType::end}
};

static unordered_map<string, Operations> operations_map = {
    {"var", Operations::declare},
    {"=", Operations::assign}
};

static unordered_map<string, SyntaxType> string_to_type = {
    {"begin", SyntaxType::begin},
    {"object", SyntaxType::object},
    {"method", SyntaxType::method},
    {"text", SyntaxType::text},
    {"dot", SyntaxType::dot},
    {"o_paren", SyntaxType::o_paren},
    {"c_paren", SyntaxType::c_paren},
    {"property", SyntaxType::property},
    {"keyword", SyntaxType::keyword},
    {"identifier", SyntaxType::identifier},
    {"a_operator", SyntaxType::a_operator},
    {"end", SyntaxType::end},
};

#endif