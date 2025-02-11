#ifndef _BASE_H
#define _BASE_H

#include <string>
#include "object.h"


class Base
{
    public:
        virtual ~Base() {}

        void virtual CallMethod(std::string, Object*) = 0;
};



#endif

