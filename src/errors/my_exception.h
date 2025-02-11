#ifndef _MY_EXCEPTION_H
#define _MY_EXCEPTION_H

#include <iostream>
#include <string>


class MyException : public std::exception
{
    public:
        MyException(std::string msg);
        const char* what() const noexcept; 

        // getters
        std::string get_msg() const;

        // setters
        void set_msg(std::string msg);

    private:
        std::string _msg;
};




#endif