#ifndef _BASE_H
#define _BASE_H

#include <functional>
#include <unordered_map>
#include <string>
#include "object.h"

using std::function;
using std::unordered_map;
using std::string;

class Base
{
    public:
        virtual ~Base() {}

        void virtual CallMethod(string, Object*) = 0;
};



#endif

