#include "program.h"
#include "objectcreate.h"
#include "u_objectcreate.h"
#include "types.h"
#include <iostream>
#include "string.h"
#include "maps.h"


using std::cout;
using std::endl;

Program::Program(vector<Token> tokens)
{
    _tokens = tokens;
}

vector<Token> Program::get_tokens() const
{
    return _tokens;
}

void Program::run()
{
    SyntaxTree tree = SyntaxTree();
    Leaf* current_leaf = tree.get_root();
    for (uint_64 i = 0; i < _tokens.size(); i++)
    {
        Token token = _tokens[i];

        switch(current_leaf->syntax_type)
        {
            case SyntaxType::object:
                _process_object(token.content);
                break;
            case SyntaxType::method:
            {
                _method_names.push_back(token.content);
                _operations.push_back(Operations::call_method);
                break;
            }
            case SyntaxType::text:
            {
                _process_u_object(token);
                break;
            }
            case SyntaxType::c_paren:
            {
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
            case SyntaxType::a_operator:
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
            throw;
        
    }

    // TODO: free up object_dict
    delete object_dict["console"];
    object_dict["console"] = nullptr;
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
        throw;

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
    Operations next_operation = _operations.back();
    Object* obj = create_u_object(token.type, token.content);

    switch(next_operation)
    {
        case Operations::call_method:
            _func_args.push_back(obj);
            _operations.pop_back();
            break;
        case Operations::assign:
            string name = _variable_names.back();
            if (_variables.count(name) < 1)
                throw;
            _variables[name] = obj;
            break;
    }
    _operations.pop_back();
}

void Program::_process_identifier(const Token& token)
{
    Operations next_operation = _operations.back();
    switch(next_operation)
    {
        case Operations::declare:
            _variables[token.content] = nullptr;
            _variable_names.push_back(token.content);
            break;
        case Operations::call_method:
            if (_variables.count(token.content) < 1)
                throw;
            _func_args.push_back(_variables[token.content]);
            break;
        default:
            throw;
    }
    
    _operations.pop_back();
}

void Program::_process_keyword(const Token& token)
{
    if (operations_map.count(token.content) == 0)
        throw;

    Operations next_operation = operations_map[token.content];
    _operations.push_back(next_operation);

}

void Program::_process_operator(const Token& token)
{
    if (operations_map.count(token.content) == 0)
        throw;
    
    Operations next_operation = operations_map[token.content];
    _operations.push_back(next_operation);
}