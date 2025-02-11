#ifndef _JSON_H
#define _JSON_H

#include <string>
#include "../types.h"
#include <vector>


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
        Json(std::string json);
        Leaf* parse();

        // setters
        void set_json(std::string json);

    private:
        std::string _get_string(size_t& pos);
        std::string _get_integer(size_t& pos);
        Leaf _process_object(size_t& idx);
        Leaf* _process_array(size_t& idx, int size = 2);
        void _set_leaf(Leaf& leaf, std::string key, std::string val, size_t& idx);
        std::string _json;
        std::vector<std::string> _split_to_components();
        std::vector<std::string> _components;
};


#endif