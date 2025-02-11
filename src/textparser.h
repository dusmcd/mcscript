#ifndef _TEXTPARSER_H
#define _TEXTPARSER_H

#include <string>
#include <vector>
#include "types.h"


class TextParser
{
    public:
        TextParser(std::string text);

        // getters
        std::string get_text() const;

        // setters
        void set_text(std::string text);

        std::vector<Token> tokenize();



    private:
        std::string _text;
        std::string _process_string(size_t& pos);
        std::string _process_func(size_t& pos);
        std::vector<std::string> _parse_code();
        ::Token _create_u_object_token(std::string component, std::vector<std::string>, size_t& idx);
        ::Token _create_function_token(std::vector<std::string>, size_t& idx);
        bool _is_number(std::string);
        bool _is_valid_closing(std::string text, char o_symbol, char c_symbol);
};

#endif