#include "function.h"
#include "util/string_funcs.h"
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

string Function::call(vector<string> vals)
{
    string c_body = _body;

    if (_args.size() == 0)
        return _body;
    
    vector<string> stmts = split(c_body, ';');
    for (size_t j = 0; j < _args.size(); j++)
    {
        string val = vals[j];
        string arg = _args[j];
        for (size_t i; i < stmts.size(); i++)
        {
            stmts[i] = find_and_replace(stmts[i], arg, val, 0);
        }
    }

    return join(stmts, ';');
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
    for (size_t i = 0; i < args.size(); i++)
    {
        if (args[i].size() < 1)
            continue;
        
        _args[i] = args[i];
    }
}
