#include "function.h"
#include <iostream>

using std::cout;
using std::endl;

Function::Function(const Func& func)
{
    set_body(func.body);
    set_args(func.args);
    
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

vector<string> Function::get_args() const
{
    return _args;
}

// setters
void Function::set_body(string body)
{
    _body = body;
}

void Function::set_args(vector<string> args)
{
    _args = args;
}
