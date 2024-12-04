#include "textparser.h"

TextParser::TextParser(string text)
{
    set_text(text);
}

void TextParser::set_text(string text)
{
    if (text.size() > 0)
        _text = text;
}

string TextParser::get_text() const
{
    return _text;
}

vector<Token> TextParser::tokenize()
{
    // this is the hard part...
    vector<Token> tokens;
    string current_token;
    int j = 0;

    for (uint_64 i = 0; i < _text.size(); i++)
    {
        if (_text[i] == ' ')
            continue;

        // if (_text[i] == '.')
        // {
        //     tokens.push_back(current_token);
        //     tokens.push_back(".");
        //     current_token = "";
        //     j = 0;
        //     continue;
        // }
        // else if (_text[i] == '(')
        // {
        //     tokens.push_back(current_token);
        //     tokens.push_back("(");
        //     current_token = "";
        //     j = 0;
        //     continue;
        // }
        // else if (_text[i] == ')')
        // {
        //     tokens.push_back(current_token);
        //     tokens.push_back(")");
        //     current_token = "";
        //     j = 0;
        //     continue;
        // }
        // else if (_text[i] == '"')
        // {
        //     tokens.push_back("\"");
        //     current_token = _process_string(i + 1);
        //     tokens.push_back(current_token);
        //     tokens.push_back("\"");
        //     // "Hello" more stuff
        //     i += current_token.size() + 1;
        //     j = 0;
        //     current_token = "";
        //     continue;
        // }

        
        current_token.insert(j, 1, _text[i]);
        j++;
    }

    return tokens;
}

string TextParser::_process_string(int pos)
{
    char current;
    int i = pos;
    int j = 0;
    string token;
    while (true)
    {
        current = _text[i];
        if (current == '"')
            break;

        token.insert(j, 1, current);

        i++;
        j++;
    }

    return token;
}

