#include "integer.h"
#include <iostream>

using std::cout;
using std::endl;

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