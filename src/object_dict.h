#ifndef _OBJECT_DICT_H
#define _OBJECT_DICT_H

#include <string>
#include <unordered_map>
#include "base.h"
#include "object.h"


static std::unordered_map<std::string, Base*> object_dict = 
{
    {"console", nullptr}
};





#endif