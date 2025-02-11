#ifndef _OBJECTCREATE_H
#define _OBJECTCREATE_H

#include "base.h"
#include <string>
#include <unordered_map>
#include "console.h"
#include <functional>



Base* create_object(std::string object_name);

Base* create_console();

static std::unordered_map<std::string, std::function<Base*(void)>> factory_map = {
    {"console", &create_console}
};

#endif