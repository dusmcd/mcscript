#ifndef _OBJECT_H
#define _OBJECT_H

class Object
{
    public:
        void virtual Print() = 0;
        virtual ~Object() {}
        virtual Object* add(const Object* const) const = 0;
        virtual int get_num() const { return -1;}
};


#endif