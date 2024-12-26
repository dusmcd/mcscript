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
        ~String() override;
        string add(const Object* const) const;

    private:
        string _string;
};


#endif