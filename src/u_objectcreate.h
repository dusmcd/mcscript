#ifndef _U_OBJECTCREATE_H
#define _U_OBJECTCREATE_H

#include "object.h"
#include <unordered_map>
#include <functional>
#include <string>
#include "types.h"

using std::unordered_map;
using std::function;
using std::string;


Object* create_u_object(Type object_type, string content);

Object* create_string(string content);
Object* create_integer(string num);

static unordered_map<Type, function<Object*(string)>> u_factory_map = {
    {Type::text, &create_string},
    {Type::integer, &create_integer}
};


#endif