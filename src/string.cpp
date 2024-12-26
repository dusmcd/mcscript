#include "string.h"
#include <iostream>

using std::cout;
using std::endl;


String::String(string content)
{
    _string = content;
}
void String::Print()
{
    cout << _string << endl;
}

String::~String() 
{

}

string String::add(const Object* const right) const
{
    return "";
}

string String::subtract(const Object* const right) const
{
    throw;
}

string String::multiply(const Object* const) const
{
    throw;
}

string String::divide (const Object* const) const
{
    throw;
}


