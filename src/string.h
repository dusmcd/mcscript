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
        string subtract(const Object* const) const;
        string multiply(const Object* const) const;
        string divide (const Object* const) const;
        string get_string() const;

    private:
        string _string;
};


#endif