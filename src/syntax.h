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

        void print() const;

    private:
        Leaf* _root;
        void _add_object_children(Leaf* object);
        void _add_dot_children(Leaf* dot);
        void _add_method_children(Leaf* method);
        void _add_o_paren_children(Leaf* o_paren);
        void _add_text_children(Leaf* text);
        void _add_c_paren_children(Leaf* c_paren);
        void _add_root_children(Leaf* root);
        void _free_memory(Leaf* leaf);
        void _print_leaf(Leaf* leaf) const;

};

#endif