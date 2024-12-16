#ifndef _SYNTAX_H
#define _SYNTAX_H

#include <string>
#include <vector>
#include "types.h"

using std::string;
using std::vector;

struct Leaf
{
    SyntaxType syntax_type;
    Leaf* children;
    int num_children;
};

class SyntaxTree
{
    public:
        SyntaxTree();
        
        // free up leaves and root
        ~SyntaxTree();

        // getters
        Leaf* get_root() const;

        // setters
        void set_root(Leaf* root);


    private:
        Leaf* _root;
        string _config_file;
        void _free_memory(Leaf* leaf);
        void _get_tree_from_file();
        void _parse_json();
};

#endif