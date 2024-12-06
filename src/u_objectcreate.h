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


Object* create_u_object(SyntaxType object_type, string content);

Object* create_string(string content);

static unordered_map<SyntaxType, function<Object*(string)>> u_factory_map = {
    {SyntaxType::text, &create_string}
};

#endif