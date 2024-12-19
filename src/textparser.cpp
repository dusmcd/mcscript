#include "textparser.h"
#include <iostream>
#include "maps.h"

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
    vector<Token> tokens;
    vector<string> code_components = _parse_code();

    for (uint_64 i = 0; i < code_components.size(); i++)
    {
        if (i == 0)
        {
            Token begin = {.type = SyntaxType::begin, .content = ""};
            tokens.push_back(begin);
        }

        else if (syntax_map.count(code_components[i - 1]) > 0 &&
         syntax_map.at(code_components[i - 1]) == SyntaxType::end)
        {
            Token begin = {.type = SyntaxType::begin, .content = ""};
            tokens.push_back(begin);
        }

        string component = code_components[i];
        SyntaxType type;
        if (syntax_map.count(component) > 0)
            type = syntax_map[component];
        else
            type = SyntaxType::identifier;
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
        if (_text[i] == '\n')
            continue;

        if (_text[i] == ' ')
        {
            components.push_back(current_comp);
            current_comp = "";
            j = 0;
            continue;
        }
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
            if (current_comp.compare("") != 0) components.push_back(current_comp);
            components.push_back(";");
            current_comp = "";
            j = 0;
            continue;
        }

        current_comp.insert(j, 1, _text[i]);
        j++;

    }
    
    return components;
}

