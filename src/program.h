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
        Program(vector<Token> tokens, unordered_map<string, Object*> g_variables);

        // getter
        vector<Token> get_tokens() const;

        Object* run();
    private:
        vector<Token> _tokens;
        vector<string> _object_names;
        vector<string> _method_names;
        vector<Operations> _operations;
        vector<Object*> _func_args;
        vector<string> _variable_names;
        unordered_map<string, Object*> _variables;
        vector<Object*> _u_objects;
        vector<Object*> _operands;

        void _process_object(string object_name);
        void _process_method(string method_name);
        void _process_u_object(const Token& token);
        void _process_identifier(const Token& token);
        void _process_keyword(const Token& token);
        void _process_operator(const Token& token);
        void _process_function(const Func& func);
        void _call_function(string func_name);
        void _free_u_objects();
};





#endif