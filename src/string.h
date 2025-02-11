#ifndef _STRING_H
#define _STRING_H

#include "object.h"
#include <string>


class String : public ::Object
{
    public:
        void Print();
        String(std::string content);
        ~String() override;
        std::string add(const Object* const) const;
        std::string subtract(const Object* const) const;
        std::string multiply(const Object* const) const;
        std::string divide (const Object* const) const;
        std::string get_string() const;

    private:
        std::string _string;
};


#endif