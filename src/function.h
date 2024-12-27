#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "object.h"
#include <vector>

using std::vector;

class Function : public Object
{
    public:
        Function(string body);
        void Print();
        ~Function() override;

        // getters
        string get_body() const;
        vector<Object*> get_args() const;

        // setters
        void set_body(string body);
        void set_args(vector<Object*> args);

    private:
        string _body;
        vector<Object*> _args;
};



#endif