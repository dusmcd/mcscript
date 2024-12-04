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
};

#endif