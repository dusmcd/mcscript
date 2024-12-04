#include "program.h"
#include "objectcreate.h"
#include "types.h"
#include <iostream>
#include "string.h"


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
    SyntaxTree* tree = create_syntax_tree();
    Leaf* current_leaf = tree->root;
    for (uint_64 i = 0; i < _tokens.size(); i++)
    {
        Token token = _tokens[i];
        if (current_leaf->syntax_type == SyntaxType::object)
            _process_object(token.content);
        else if (current_leaf->syntax_type == SyntaxType::method)
        {
            String message = String("Hello world!");
            _process_method(token.content, message);

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

    delete [] tree;
    // TODO: release memory from child nodes
    //  maybe convert the tree to a class
}

Program::~Program()
{
    for (Base* obj : _objects)
    {
        delete obj;
        obj = nullptr;
    }
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
        _objects.push_back(object_dict[object_name]);
        _object_names.push_back(object_name);
    }
    else
        throw;

}

void Program::_process_method(string method_name, Object& arg)
{
    Base* obj = _objects.back();
    obj->CallMethod(method_name, arg);
}