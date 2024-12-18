#ifndef _JSON_H
#define _JSON_H

#include <string>
#include "../types.h"
#include <vector>

using std::string;
using std::vector;

/*
    {
        "key": "value",
        "key2": 2,
        "key3": "hello there" 
    }
    [{, "key", ":", "value", ",", "key2", 2, ","]
*/

class Json
{
    public:
        Json(string json);
        Leaf* parse();

        // setters
        void set_json(string json);

    private:
        string _get_string(size_t& pos);
        string _get_integer(size_t& pos);
        string _json;
        vector<string> _split_to_components();
        vector<string> _components;
};


#endif