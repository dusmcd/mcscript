#include "textparser.h"
#include <iostream>

using std::cout;
using std::endl;

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
    vector<string> code_components = _parse_code();

    for (uint_64 i = 0; i < code_components.size(); i++)
    {
        string component = code_components[i];
        SyntaxType type = syntax_map[component];
        Token token;
        if (type == SyntaxType::text)
        {
           token.content = code_components[i + 1];
           i++;
           token.type = type;
           tokens.push_back(token);
           continue; 
        }

        token.type = type;
        token.content = component;
        tokens.push_back(token);
    }

    return tokens;
}

string TextParser::_process_string(uint_64& pos)
{
    char current;
    int j = 0;
    string token;
    while (true)
    {
        current = _text[pos];
        if (current == '"')
            break;

        token.insert(j, 1, current);

        pos++;
        j++;
    }

    return token;
}

vector<string> TextParser::_parse_code()
{
    vector<string> components;
    string current_comp;
    int j = 0;
    for (uint_64 i = 0; i < _text.size(); i++)
    {
        if (_text[i] == '.')
        {
            components.push_back(current_comp);
            components.push_back(".");
            current_comp = "";
            j = 0;
            continue;
        }
        else if (_text[i] == '(')
        {
            components.push_back(current_comp);
            components.push_back("(");
            current_comp = "";
            j = 0;
            continue;
        }
        else if (_text[i] == ')')
        {
            components.push_back(current_comp);
            components.push_back(")");
            current_comp = "";
            j = 0;
            continue;
        }
        else if (_text[i] == '"')
        {
            components.push_back("\"");
            i++;
            current_comp = _process_string(i);
            j = 0;
            continue;
        }
        else if (_text[i] == ';')
        {
            components.push_back(";");
            j = 0;
            continue;
        }

        current_comp.insert(j, 1, _text[i]);
        j++;

    }
    
    return components;
}

