#ifndef _TEXTPARSER_H
#define _TEXTPARSER_H

#include <string>
#include <vector>
#include "types.h"

using std::string;
using std::vector;

class TextParser
{
    public:
        TextParser(string text);

        // getters
        string get_text() const;

        // setters
        void set_text(string text);

        vector<Token> tokenize();



    private:
        string _text;
        string _process_string(size_t& pos);
        string _process_func(size_t& pos);
        vector<string> _parse_code();
        Token _create_u_object_token(string component, vector<string>, size_t& idx);
        Token _create_function_token(vector<string>, size_t& idx);
        bool _is_number(string);
        bool _is_valid_closing(string text, char o_symbol, char c_symbol);
};

#endif