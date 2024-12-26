#ifndef _INTEGER_H
#define _INTEGER_H

#include "object.h"

class Integer : public Object
{

    public:
        Integer(int num);
        void Print();
        ~Integer() override;
        string add(const Object* const) const;
        string subtract(const Object* const) const;
        string multiply(const Object* const) const;
        string divide(const Object* const) const;

        // setters
        void set_num(int num);

        // getters
        int get_num() const;

    private:
        int _num;
};


#endif