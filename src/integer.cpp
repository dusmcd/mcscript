#include "integer.h"
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;
using std::string;

Integer::Integer(int num)
{
   set_num(num); 
}

void Integer::Print()
{
    cout << _num << endl;
}

void Integer::set_num(int num)
{
    _num = num;
}

int Integer::get_num() const
{
    return _num;
}

Integer::~Integer()
{

}

string Integer::add(const Object* const right) const
{
    int sum = _num + right->get_num();
    return to_string(sum);
}

string Integer::subtract(const Object* const right) const
{
    int diff = _num - right->get_num();
    return to_string(diff);
}

string Integer::multiply(const Object* const right) const
{
    int product = _num * right->get_num();
    return to_string(product);
}

string Integer::divide(const Object* const right) const
{
    int quotient = _num / right->get_num();
    return to_string(quotient);
}