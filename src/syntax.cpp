#include "syntax.h"
#include <iostream>

using std::cout;
using std::endl;

SyntaxTree::SyntaxTree() 
{
    Leaf* root = new Leaf[1];
    root->syntax_type = SyntaxType::object;
    root->num_children = 1;

    _add_object_children(root);
    set_root(root);

}

SyntaxTree::~SyntaxTree()
{
    _free_memory(_root);
    _root = nullptr;
}

Leaf* SyntaxTree::get_root() const
{
    return _root;
}

void SyntaxTree::set_root(Leaf* root)
{
    if (root != nullptr)
        _root = root;
}

void SyntaxTree::print() const
{
    // print the tree to console
    cout << "Printing syntax tree..." << endl;
    _print_leaf(_root);
}

void SyntaxTree::_print_leaf(Leaf* leaf) const
{
    if (leaf != nullptr)
    {
        cout << leaf->syntax_type << endl;
        for (int i = 0; i < leaf->num_children; i++)
            _print_leaf(leaf->children + i);
    }
}

void SyntaxTree::_free_memory(Leaf* leaf)
{
    if (leaf != nullptr)
    {
        _free_memory(leaf->children);
        delete [] leaf;
    }
}

void SyntaxTree::_add_object_children(Leaf* object)
{
    Leaf* children = new Leaf[object->num_children];
    children[0].syntax_type = SyntaxType::dot;
    children[0].num_children = 2;

    _add_dot_children(&(children[0]));

    object->children = children;
}

void SyntaxTree::_add_dot_children(Leaf* dot)
{
    Leaf* children = new Leaf[dot->num_children];
    children[0].num_children = 1;
    children[0].syntax_type = SyntaxType::method;
    children[0].children = nullptr;
    _add_method_children(&(children[0]));

    children[1].num_children = 0;
    children[1].syntax_type = SyntaxType::property;
    children[1].children = nullptr;

    dot->children = children;
}

void SyntaxTree::_add_method_children(Leaf* method)
{
    Leaf* children = new Leaf[method->num_children];
    children[0].syntax_type = SyntaxType::o_paren;
    children[0].num_children = 1;
    children[0].children = nullptr;
    _add_o_paren_children(&(children[0]));

    method->children = children;
}

void SyntaxTree::_add_o_paren_children(Leaf* o_paren)
{
    Leaf* children = new Leaf[o_paren->num_children];
    children[0].syntax_type = SyntaxType::text;
    children[0].num_children = 1;
    children[0].children = nullptr;
    _add_text_children(&(children[0]));

    o_paren->children = children;
}

void SyntaxTree::_add_text_children(Leaf* text)
{
    Leaf *children = new Leaf[text->num_children];
    children[0].syntax_type = SyntaxType::c_paren;
    children[0].num_children = 1;
    children[0].children = nullptr;
    _add_c_paren_children(&(children[0]));

    text->children = children;
}

void SyntaxTree::_add_c_paren_children(Leaf* c_paren)
{
    Leaf *children = new Leaf[c_paren->num_children];
    children[0].syntax_type = SyntaxType::end;
    children[0].num_children = 0;
    children[0].children = nullptr;

    c_paren->children = children;
}