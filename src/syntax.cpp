#include "syntax.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

SyntaxTree::SyntaxTree() 
{
    Leaf* root = new Leaf[1];
    root->syntax_type = SyntaxType::begin;
    root->num_children = 2;
    set_root(root);

    root->children = _get_tree_from_file();
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


void SyntaxTree::_free_memory(Leaf* leaf)
{
    if (leaf != nullptr)
    {
        for (int i = 1; i < leaf->num_children; i++)
        {
            Leaf child = leaf->children[i];
            _free_memory(child.children);
        }
        _free_memory(leaf->children);
        delete [] leaf;
    }
}

Leaf* SyntaxTree::_get_tree_from_file()
{
    string file_name = CFILE_NAME;
    ifstream config_file(file_name);

    config_file.seekg(0, config_file.end);
    int length = config_file.tellg();
    config_file.seekg(0, config_file.beg);

    char next;
    for (int i = 0; i < length; i++)
    {
        config_file >> std::noskipws >> next;
        _config_file.insert(i, 1, next);
    }

    return _parse_json(_config_file);
}

Leaf* SyntaxTree::_parse_json(string json)
{
    Json json_parser = Json(json);
    return json_parser.parse();
}

