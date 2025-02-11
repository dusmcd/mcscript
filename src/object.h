#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>


class Object
{
    public:
        void virtual Print() = 0;
        virtual ~Object() {}
        virtual std::string add(const Object* const) const {throw;}
        virtual std::string subtract(const Object* const) const {throw;}
        virtual std::string multiply(const Object* const) const {throw;}
        virtual std::string divide(const Object* const) const {throw;}
        virtual int get_num() const { return -1;}
};


#endif