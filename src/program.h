#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "syntax.h"
#include "object_dict.h"
#include <vector>
#include "object.h"
#include "types.h"


using std::vector;

class Program
{

    public:
        Program(vector<Token> tokens);

        // getter
        vector<Token> get_tokens() const;

        void run();
    private:
        vector<Token> _tokens;
        vector<string> _object_names;
        vector<string> _method_names;
        vector<SyntaxType> _operations;
        vector<Object*> _func_args;

        void _process_object(string object_name);
        void _process_method(string method_name);
        void _process_u_object(Token token);
};





#endif