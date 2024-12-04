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
        ~Program();

        // getter
        vector<Token> get_tokens() const;

        void run();
    private:
        vector<Token> _tokens;
        // need something that will store the object used in a statement
        vector<Base*> _objects;
        vector<string> _object_names;

        void _clear_objects();
        void _process_object(string object_name);
        void _process_method(string method_name, Object& arg);
        
};





#endif