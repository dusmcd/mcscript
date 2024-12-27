#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>

using std::string;

class Object
{
    public:
        void virtual Print() = 0;
        virtual ~Object() {}
        virtual string add(const Object* const) const {throw;}
        virtual string subtract(const Object* const) const {throw;}
        virtual string multiply(const Object* const) const {throw;}
        virtual string divide(const Object* const) const {throw;}
        virtual int get_num() const { return -1;}
};


#endif