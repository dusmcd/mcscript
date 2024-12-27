#include "function.h"
#include <iostream>

using std::cout;
using std::endl;

Function::Function(string body)
{
    set_body(body);
}

Function::~Function()
{

}

void Function::Print()
{
    cout << _body << endl;
}

string Function::get_body() const
{
    return _body;
}

vector<Object*> Function::get_args() const
{
    return _args;
}

// setters
void Function::set_body(string body)
{
    _body = body;
}

void Function::set_args(vector<Object*> args)
{
    _args = args;
}
