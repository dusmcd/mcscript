#include "json.h"

Json::Json(string json)
{
    set_json(json);
}

Leaf* Json::parse()
{
    _components = _split_to_components(); 
}

vector<string> Json::_split_to_components()
{
    vector<string> components;
    size_t length = _json.length();
    for (size_t i = 0; i < length; i++)
    {
        char current = _json[i];
        string current_str;
        switch(current)
        {
            case ' ':
                continue;
            case '\n':
                continue;
            case '"':
                components.push_back(_get_string(i));
                break;
            default:
                if (isdigit(current))
                {
                    components.push_back(_get_integer(i));
                }
                else if (current == 't')
                {
                    components.push_back("true");
                    i += 3;
                }
                else if (current == 'f')
                {
                    components.push_back("false");
                    i += 4;
                }
                else
                {
                    current_str.insert(0, 1, current);
                    components.push_back(current_str);
                }
        }
    }
    return components;
}

string Json::_get_string(size_t& pos)
{
    string result;
    int i = 0;
    while (true)
    {
        pos++;
        char current = _json[pos];
        if (current == '"')
        {
            return result;
        }
        
        result.insert(i, 1, current);
        i++;
    }
}

void Json::set_json(string json)
{
    // validate json later
    _json = json;
}

string Json::_get_integer(size_t& pos)
{
    string result;
    char current;
    int i = 0;
    while (true)
    {
        current = _json[pos];
        if (pos + 1 >= _json.length() || !isdigit(_json[pos + 1]))
        {
            result.insert(i, 1, current);
            return result;
        }

        result.insert(i, 1, current);
        i++;
        pos++;
    }

}

