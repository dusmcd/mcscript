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

    for (size_t i = 0; i < code_components.size(); i++)
    {
        if (i == 0)
        {
            Token begin = {.type = SyntaxType::begin};
            begin.content.data = "";
            begin.content.type = Type::other;
            tokens.push_back(begin);
        }

        else if (syntax_map.count(code_components[i - 1]) > 0 &&
         syntax_map.at(code_components[i - 1]) == SyntaxType::end)
        {
            Token begin = {.type = SyntaxType::begin};
            begin.content.data = "";
            begin.content.type = Type::other;
            tokens.push_back(begin);
        }

        string component = code_components[i];
        SyntaxType type = syntax_map.count(component) > 0 ? syntax_map[component] : SyntaxType::identifier;

        Token token;
        if (type == SyntaxType::u_object)
        {
            token = _create_u_object_token(component, code_components, i);
            tokens.push_back(token);
            continue; 
        }


        token.type = type;
        token.content.data = component;
        token.content.type = Type::other;
        tokens.push_back(token);
    }

    return tokens;
}

string TextParser::_process_string(size_t& pos)
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
    for (size_t i = 0; i < _text.size(); i++)
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

Token TextParser::_create_u_object_token(string component, vector<string> code_components, size_t& idx)
{
    Token token = {.type = SyntaxType::u_object};
    if (component.compare("\"") == 0)
    {
        idx++;
        token.content.data = code_components[idx];
        token.content.type = Type::text;
    }

    return token;
}