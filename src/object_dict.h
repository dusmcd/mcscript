#ifndef _OBJECT_DICT_H
#define _OBJECT_DICT_H

#include <string>
#include <unordered_map>
#include "base.h"
#include "object.h"

using std::string;
using std::unordered_map;

static unordered_map<string, Base*> object_dict = 
{
    {"console", nullptr}
};

static unordered_map<string, Object*> u_object_dict = {
    {"string", nullptr}
};




#endif