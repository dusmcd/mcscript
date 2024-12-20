#include "u_objectcreate.h"
#include "string.h"

Object* create_u_object(Type object_type, string content)
{
    return u_factory_map[object_type](content);
}

Object* create_string(string content)
{
    String* user_string = new String(content);
    return user_string;
}
