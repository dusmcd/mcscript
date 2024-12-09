#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "object.h"
#include "base.h"
#include <unordered_map>
#include <functional>
#include <string>

using std::unordered_map;
using std::function;
using std::string;


class Console : public Base
{
    public:
        Console();
        ~Console() override;
        void Log(Object*) const;

        void CallMethod(string method_name, Object* arg) override;
    
    private:
        unordered_map<string, function<void(const Console&, Object*)>> _method_map;
        void _set_map();

};


#endif
