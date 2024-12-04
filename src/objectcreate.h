#ifndef _OBJECTCREATE_H
#define _OBJECTCREATE_H

#include "base.h"
#include <string>
#include <unordered_map>
#include "console.h"
#include <functional>

using std::string;
using std::unordered_map;


Base* create_object(string object_name);

Base* create_console();

static unordered_map<string, std::function<Base*(void)>> factory_map = {
    {"console", &create_console}
};

#endif