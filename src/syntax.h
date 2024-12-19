#ifndef _SYNTAX_H
#define _SYNTAX_H

#include <string>
#include <vector>
#include "types.h"
#include "./json_parse/json.h"

using std::string;
using std::vector;

const string CFILE_NAME =  "./config/syntax.json";

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
        void print(const Leaf& leaf) const;


    private:
        Leaf* _root;
        string _config_file;
        void _free_memory(Leaf* leaf);
        Leaf* _get_tree_from_file();
        Leaf* _parse_json(string json);
};

#endif