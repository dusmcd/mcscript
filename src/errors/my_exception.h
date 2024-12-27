#ifndef _MY_EXCEPTION_H
#define _MY_EXCEPTION_H

#include <iostream>
#include <string>

using std::string;
using std::exception;

class MyException : public exception
{
    public:
        MyException(string msg);
        const char* what() const noexcept; 

        // getters
        string get_msg() const;

        // setters
        void set_msg(string msg);

    private:
        string _msg;
};




#endif