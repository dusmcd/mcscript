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

