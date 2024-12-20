#include "json.h"
#include "../maps.h"

Json::Json(string json)
{
    set_json(json);
}

Leaf* Json::parse()
{
    _components = _split_to_components(); 
    Leaf* leaf = new Leaf;
    for (size_t i = 0; i < _components.size(); i++)
    {
        string component = _components[i];
        if (component.compare("{") == 0)
        {
            i++;
            *leaf = _process_object(i);
        }
        else if (component.compare("[") == 0)
            _process_array(i);
    }
    return leaf;
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

Leaf Json::_process_object(size_t& idx)
{
    Leaf leaf;
    string key;
    int offset = 0;
    while (true)
    {
        string current = _components[idx];
        if (current.compare("}") == 0)
            return leaf;
        
        if (current.compare(",") == 0)
        {
            idx++;
            continue;
        }

        switch(offset)
        {
            case 0:
                key = current;
                break;
            case 1:
                if (current.compare(":") == 0)
                    break;
                else
                    throw;
            case 2:
                _set_leaf(leaf, key, current, idx);
                idx++;
                offset = 0;
                continue;
            default:
            {
                // not sure
            }
        }

        idx++;
        offset++;            
    }
}

void Json::_set_leaf(Leaf& leaf, string key, string val, size_t& idx)
{
    if (key.compare("type") == 0)
        leaf.syntax_type = string_to_type[val];
    else if (key.compare("num_children") == 0)
    {
        int num = atoi(val.c_str());
        leaf.num_children = num;
    }
    else if (key.compare("children") == 0)
    {
        if (val.compare("[") == 0)
            leaf.children = _process_array(idx, leaf.num_children);
        else
            leaf.children = nullptr;
    }
}

Leaf* Json::_process_array(size_t& idx, int size)
{
    Leaf* leaves = new Leaf[size];
    int i = 0;
    while(true)
    {
        idx++;
        string current = _components[idx];

        if (current.compare("]") == 0)
            return leaves;
        if (current.compare(",") == 0)
        {
            i++;
            continue;
        }
        
        if (current.compare("{") == 0)
        {
            idx++;
            leaves[i] = _process_object(idx);
        }
    }
}