#include "u_objectcreate.h"
#include "string.h"
#include "integer.h"

Object* create_u_object(Type object_type, string content)
{
    return u_factory_map[object_type](content);
}

Object* create_string(string content)
{
    String* user_string = new String(content);
    return user_string;
}

Object* create_integer(string num)
{
    int i_num = atoi(num.c_str());
    Integer* user_integer = new Integer(i_num);

    return user_integer;
}