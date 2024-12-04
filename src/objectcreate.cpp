#include "objectcreate.h"

Base* create_object(string object_name)
{
    return factory_map[object_name]();
}

Base* create_console()
{
    Console* console = new Console;
    return console;
}
