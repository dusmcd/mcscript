#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "syntax.h"
#include "object_dict.h"
#include <vector>
#include "object.h"
#include "types.h"


using v_map = std::unordered_map<std::string, ::Object*>;

class Program
{

    public:
        Program(std::vector<::Token> tokens);
        Program(std::vector<::Token> tokens, v_map g_variables);

        // getter
        std::vector<::Token> get_tokens() const;

        Object* run();
    private:
        std::vector<::Token> _tokens;
        std::vector<std::string> _object_names;
        std::vector<std::string> _method_names;
        std::vector<::Operations> _operations;
        std::vector<::Object*> _func_args;
        std::vector<std::string> _variable_names;
        v_map _variables;
        v_map _globals;
        std::vector<::Object*> _u_objects;
        std::vector<::Object*> _operands;

        void _process_object(std::string object_name);
        void _process_method(std::string method_name);
        void _process_u_object(const ::Token& token);
        void _process_identifier(const ::Token& token);
        void _process_keyword(const ::Token& token);
        void _process_operator(const ::Token& token);
        void _process_function(const ::Func& func);
        void _call_function(std::string func_name);
        void _free_u_objects();
};





#endif