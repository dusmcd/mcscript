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

struct SyntaxTree
{
    Leaf* root;
};

SyntaxTree* create_syntax_tree();
void add_object_children(Leaf* object);
void add_dot_children(Leaf* dot);

#endif