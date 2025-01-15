#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "object.h"
#include <vector>
#include "types.h"

using std::vector;

class Function : public Object
{
    public:
        Function(const Func& func);
        void Print();
        ~Function() override;

        // getters
        string get_body() const;
        vector<string> get_args() const;

        // setters
        void set_body(string body);
        void set_args(vector<string> args);

        string call(vector<string> vals);

    private:
        string _body;
        vector<string> _args;
};



#endif