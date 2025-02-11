#ifndef _U_OBJECTCREATE_H
#define _U_OBJECTCREATE_H

#include "object.h"
#include <unordered_map>
#include <functional>
#include <string>
#include "types.h"



::Object* create_u_object(::Type object_type, std::string content);

::Object* create_string(std::string content);
::Object* create_integer(std::string num);

static std::unordered_map<::Type, std::function<::Object*(std::string)>> u_factory_map = {
    {::Type::text, &create_string},
    {::Type::integer, &create_integer}
};


#endif