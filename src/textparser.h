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
        string _process_string(uint_64& pos);
        vector<string> _parse_code();
        Token _create_u_object_token(string component, vector<string>, size_t& idx);
        bool _is_number(string);
        bool _is_valid_closing(string text, char o_symbol, char c_symbol);
};

#endif