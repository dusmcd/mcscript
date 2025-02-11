#ifndef _INTEGER_H
#define _INTEGER_H

#include "object.h"

class Integer : public Object
{

    public:
        Integer(int num);
        void Print();
        ~Integer() override;
        std::string add(const Object* const) const;
        std::string subtract(const Object* const) const;
        std::string multiply(const Object* const) const;
        std::string divide(const Object* const) const;

        // setters
        void set_num(int num);

        // getters
        int get_num() const;

    private:
        int _num;
};


#endif