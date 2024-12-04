#ifndef _STRING_H
#define _STRING_H

#include "object.h"
#include <string>

using std::string;

class String : public Object
{
    public:
        void Print();
        String(string content);

    private:
        string _string;
};


#endif