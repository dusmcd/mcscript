#include "my_exception.h"

MyException::MyException(string msg)
{
    set_msg(msg);
}

const char* MyException::what() const noexcept
{
    return _msg.c_str();
}

void MyException::set_msg(string msg)
{
    _msg = msg;
}

string MyException::get_msg() const
{
    return _msg;
}