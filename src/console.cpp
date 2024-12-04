#include "console.h"
#include <iostream>


Console::Console()
{
    _set_map();
}
void Console::Log(Object& obj) const
{
    obj.Print();
}

void Console::Print()
{
    std::cout << "Printing" << std::endl;
}

void Console::CallMethod(string method_name, Object& arg)
{
    _method_map[method_name](*this, arg);
}

void Console::_set_map()
{
    _method_map["log"] = &Console::Log;
}