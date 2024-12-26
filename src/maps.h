#ifndef _MAPS_H
#define _MAPS_H

#include <unordered_map>
#include "types.h"

using std::unordered_map;

static const unordered_map<string, SyntaxType> syntax_map = {
    {"console", SyntaxType::object},
    {"log", SyntaxType::method},
    {".", SyntaxType::dot},
    {"(", SyntaxType::o_paren},
    {")", SyntaxType::c_paren},
    {"\"", SyntaxType::u_object},
    {"var", SyntaxType::keyword},
    {"=", SyntaxType::operator_t},
    {"+", SyntaxType::operator_t},
    {";", SyntaxType::end}
};

static const unordered_map<string, Operations> operations_map = {
    {"var", Operations::declare},
    {"=", Operations::assign},
    {"+", Operations::add},
};

static const unordered_map<string, SyntaxType> string_to_type = {
    {"begin", SyntaxType::begin},
    {"object", SyntaxType::object},
    {"method", SyntaxType::method},
    {"u_object", SyntaxType::u_object},
    {"dot", SyntaxType::dot},
    {"o_paren", SyntaxType::o_paren},
    {"c_paren", SyntaxType::c_paren},
    {"property", SyntaxType::property},
    {"keyword", SyntaxType::keyword},
    {"identifier", SyntaxType::identifier},
    {"operator_t", SyntaxType::operator_t},
    {"end", SyntaxType::end},
};

#endif