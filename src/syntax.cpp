#include "syntax.h"

SyntaxTree* create_syntax_tree()
{
    Leaf* root = new Leaf[1];
    root->syntax_type = SyntaxType::object;
    root->num_children = 1;

    add_object_children(root);
    SyntaxTree* tree = new SyntaxTree[1];
    tree->root = root;

    return tree;
}

void add_object_children(Leaf* object)
{
    Leaf* children = new Leaf[object->num_children];
    children[0].syntax_type = SyntaxType::connector;
    children[0].num_children = 2;

    add_dot_children(children);

    object->children = children;
}

void add_dot_children(Leaf* dot)
{
    Leaf* children = new Leaf[dot->num_children];
    children[0].num_children = 1;
    children[0].syntax_type = SyntaxType::method;
    children[0].children = nullptr;

    children[1].num_children = 1;
    children[1].syntax_type = SyntaxType::property;
    children[1].children = nullptr;

    dot->children = children;
}