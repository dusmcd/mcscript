#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "object.h"
#include <vector>
#include "types.h"


class Function : public Object
{
    public:
        Function(const Func& func);
        void Print();
        ~Function() override;

        // getters
        std::string get_body() const;
        std::vector<std::string> get_args() const;

        // setters
        void set_body(std::string body);
        void set_args(std::vector<std::string> args);

        std::string call(std::vector<std::string> vals);
        bool is_return_val();

    private:
        std::string _body;
        std::vector<std::string> _args;
};



#endif