#include "program.h"
#include "objectcreate.h"
#include "u_objectcreate.h"
#include "types.h"
#include <iostream>
#include "string.h"
#include "maps.h"
#include "errors/my_exception.h"
#include "function.h"
#include "runner.h"
#include "integer.h"
#include <typeinfo>


using std::cout;
using std::endl;
using std::string;
using std::vector;

Program::Program(vector<Token> tokens)
{
    _tokens = tokens;
}

Program::Program(vector<Token> tokens, v_map g_variables)
{
    _tokens = tokens;
    _variables = g_variables;
}

vector<Token> Program::get_tokens() const
{
    return _tokens;
}

Object* Program::run()
{
    SyntaxTree tree = SyntaxTree();
    Leaf* current_leaf = tree.get_root();

    for (size_t i = 0; i < _tokens.size(); i++)
    {
        Token token = _tokens[i];

        switch(current_leaf->syntax_type)
        {
            case SyntaxType::object:
                _process_object(std::get<string>(token.content.data));
                break;
            case SyntaxType::method:
            {
                _method_names.push_back(std::get<string>(token.content.data));
                _operations.push_back(Operations::call_method);
                break;
            }
            case SyntaxType::u_object:
            {
                _process_u_object(token);
                break;
            }
            case SyntaxType::c_paren:
            {
                if (_operations.back() == Operations::call_function)
                    _call_function(_variable_names.back());
                else
                    _process_method(_method_names.back());
                break;
            }
            case SyntaxType::identifier:
            {
                _process_identifier(token);
                break;
            }
            case SyntaxType::keyword:
            {
                _process_keyword(token);
                break;
            }
            case SyntaxType::operator_t:
                _process_operator(token);
                break;
            default:
            {
                // not sure whether I need this
            }
        }

                        
        if (current_leaf->children == nullptr && token.type == SyntaxType::end)
        {
            _object_names.clear();
            _method_names.clear();
            _operations.clear();
            _func_args.clear();
            _variable_names.clear();
            _operands.clear();
            current_leaf = tree.get_root();
            continue;
        }
        // traverse syntax tree to determine proper syntax
        bool token_found = false;
        SyntaxType syntax_type = _tokens[i + 1].type;
        for (int j = 0; j < current_leaf->num_children; j++)
        {
            if (current_leaf->children[j].syntax_type == syntax_type)
            {
                current_leaf = &(current_leaf->children[j]);
                token_found = true;
                break;
            }
        }

        if (!token_found)
            throw MyException("syntax error");
        
    }

    delete object_dict["console"];
    object_dict["console"] = nullptr;
    _free_u_objects();

    return nullptr;
}


void Program::_process_object(string object_name)
{
    if (object_dict.count(object_name) > 0)
    {
        if (object_dict[object_name] == nullptr)
        {
            // allocate memory for object and get reference to it
            Base* new_object = create_object(object_name);
            object_dict[object_name] = new_object;
        }
        _object_names.push_back(object_name);
    }
    else
        throw MyException("object not found");

}

void Program::_process_method(string method_name)
{
    string object_name = _object_names.back();
    Base* obj = object_dict[object_name];
    Object* arg =  _func_args.back();
    obj->CallMethod(method_name, arg);
}


void Program::_process_u_object(const Token& token)
{
    if (token.content.type == Type::function_t)
    {
        const Func func = std::get<Func>(token.content.data);
        _process_function(func);
        return;
    }

    Operations next_operation = _operations.size() == 0 ? Operations::none : _operations.back();

    Object* obj;
    if (_variables.count(std::get<string>(token.content.data)) == 1)
        obj = _variables.at(std::get<string>(token.content.data));
    else
    {
        obj = create_u_object(token.content.type, std::get<string>(token.content.data));
        _u_objects.push_back(obj);
    }
         
    string name;
    switch(next_operation)
    {
        case Operations::call_method:
            _func_args.push_back(obj);
            _operations.pop_back();
            break;
        case Operations::call_function:
            _func_args.push_back(obj);
            break;
        case Operations::assign:
            name = _variable_names.back();
            if (_variables.count(name) == 1)
                _variables[name] = _u_objects.back();
            else if (_globals.count(name) == 1)
                _globals[name] = _u_objects.back();
            else
                throw MyException("identifier not found");
            _operands.push_back(_u_objects.back());
            // _operations.pop_back();
            break;
        case Operations::add:
            _operands.push_back(obj);
            if (_operands.size() == 2)
            {
                string new_obj = _operands[0]->add(_operands[1]);
                Token sum_token = {.type = SyntaxType::u_object};
                sum_token.content.data = new_obj;
                sum_token.content.type = token.content.type;
                _operations.pop_back();
                _process_u_object(sum_token);
            }
            break;
        case Operations::subtract:
            _operands.push_back(obj);
            if (_operands.size() == 2)
            {
                string new_obj = _operands[0]->subtract(_operands[1]);
                Token new_token = {.type = SyntaxType::u_object};
                new_token.content.data = new_obj;
                new_token.content.type = token.content.type;
                _operations.pop_back();
                _process_u_object(new_token);
            }
            break;
        case Operations::multiply:
            _operands.push_back(obj);
            if (_operands.size() == 2)
            {
                string new_obj = _operands[0]->multiply(_operands[1]);
                Token new_token = {.type = SyntaxType::u_object};
                new_token.content.data = new_obj;
                new_token.content.type = token.content.type;
                _operations.pop_back();
                _process_u_object(new_token);
            }
            break;
        case Operations::divide:
            _operands.push_back(obj);
            if (_operands.size() == 2)
            {
                string new_obj = _operands[0]->divide(_operands[1]);
                Token new_token = {.type = SyntaxType::u_object};
                new_token.content.data = new_obj;
                new_token.content.type = token.content.type;
                _operations.pop_back();
                _process_u_object(new_token);
            }
            break;
        default:
            _operands.push_back(obj);
    }
}

void Program::_process_identifier(const Token& token)
{
    Operations next_operation = _operations.empty() ? Operations::none : _operations.back();
    string data = std::get<string>(token.content.data);
    switch(next_operation)
    {
        case Operations::declare:
            _variables[data] = nullptr;
            _variable_names.push_back(data);
            break;
        default:
            if (_variables.count(data) < 1 && _globals.count(data) < 1)
                throw MyException("operation not allowed");

            Object* obj = _variables.at(data);
            _variable_names.push_back(data);
            if (typeid(*obj) == typeid(Function))
            {
                _operations.push_back(Operations::call_function);
            }
            else
                _process_u_object(token);
            

    }
    
}

void Program::_process_keyword(const Token& token)
{
    string data = std::get<string>(token.content.data);
    if (operations_map.count(data) == 0)
        throw MyException("not a valid keyword");

    Operations next_operation = operations_map.at(data);
    _operations.push_back(next_operation);

}

void Program::_process_operator(const Token& token)
{
    string data = std::get<string>(token.content.data);
    if (operations_map.count(data) == 0)
        throw MyException("not a valid operator");
    
    Operations next_operation = operations_map.at(data);
    _operations.push_back(next_operation);
}

void Program::_free_u_objects()
{
    for (Object* obj : _u_objects)
    {
        delete obj;
        obj = nullptr;
    }

    for (const auto& [name, pointer] : _variables)
    {
        _variables[name] = nullptr;
    }
}

void Program::_process_function(const Func& func)
{
    Function* function = new Function(func);
    _u_objects.push_back(function);
    _variables[func.name] = function;
}

void Program::_call_function(string func_name)
{
    Function* function = dynamic_cast<Function*>(_variables[func_name]);
    vector<string> vals;
    for (Object* obj : _func_args)
    {
        if (dynamic_cast<Integer*>(obj) != nullptr)
            vals.push_back(std::to_string(obj->get_num()));
        else if (dynamic_cast<String*>(obj) != nullptr)
        {
            String* u_string = dynamic_cast<String*>(obj);
            vals.push_back(u_string->get_string());
        }
    }
    _variable_names.pop_back();
    _operations.pop_back();
    
    Operations next_operation = _operations.empty() ? Operations::none : _operations.back();
    bool is_var_name = !_variable_names.empty();

    if (function->is_return_val() && is_var_name && next_operation == Operations::assign)
    {
        Object* return_addr = _variables.at(_variable_names.back());
        run_program(function->call(vals), return_addr, _variables);
    }
    else
        run_program(function->call(vals), _variables);
    
}