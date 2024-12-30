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
    Token begin = {.type = SyntaxType::begin};
    begin.content.data = "";
    begin.content.type = Type::other;
    tokens.push_back(begin);

    for (size_t i = 0; i < code_components.size(); i++)
    {
        string component = code_components[i];
        if ( i > 0 && 
            i < code_components.size() - 1 && 
            syntax_map.count(code_components[i - 1]) > 0 &&
            syntax_map.at(code_components[i - 1]) == SyntaxType::end)
                tokens.push_back(begin);
        

        if (component.compare("") == 0 ||
            component.compare(" ") == 0 ||
            component.compare("\n") == 0)
            continue;

        
        SyntaxType type = syntax_map.count(component) > 0 ? syntax_map.at(component) : SyntaxType::identifier;

        if (_is_number(component))
            type = SyntaxType::u_object;

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
        // if (_text[i] == '\n')
        //     continue;

        if (_text[i] == ' ' || _text[i] == '\n')
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
        else if (_text[i] == '{')
        {
            current_comp = _process_func(i);
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
    else if (isdigit(component[0]))
    {
        token.content.data = component;
        token.content.type = Type::integer;
    }

    return token;
}

bool TextParser::_is_number(string comp)
{
    try
    {
        std::stoi(comp);
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    
}

bool TextParser::_is_valid_closing(string text, char o_symbol, char c_symbol)
{
    vector<char> symbol_stack;
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == o_symbol)
            symbol_stack.push_back(text[i]);
        else if (text[i] == c_symbol)
        {
            if (symbol_stack.empty())
                return false;
            symbol_stack.pop_back();
        }
    }

    return symbol_stack.size() == 0;
}

string TextParser::_process_func(size_t& pos)
{
    string body;
    int j = 0;
    while (true)
    {
        body.insert(j, 1, _text[pos]);
        if (_text[pos] == '}' && _is_valid_closing(body, '{', '}'))
            break;

        j++;
        pos++;
    }

    return body;
}