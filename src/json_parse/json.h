#ifndef _JSON_H
#define _JSON_H

#include <string>
#include "../types.h"

using std::string;

class Json
{
    public:
        Json(string json);
        Leaf* parse();

        // setters
        void set_json(string json);

    private:
        string _get_string(int& pos);
        string _json;
};


#endif