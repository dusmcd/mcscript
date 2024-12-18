#include "json.h"

Json::Json(string json)
{
    set_json(json);
}

Leaf* Json::parse()
{

}

string Json::_get_string(int& pos)
{
    string result;
    int i = 0;
    while (true)
    {
        char current = _json[pos++];
        if (current == '"')
            return result;
        
        result.insert(i, 0, current);
        i++;
    }
}

void Json::set_json(string json)
{
    // validate json later
    _json = json;
}