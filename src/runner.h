#ifndef _RUNNER_H
#define _RUNNER_H

#include <string>
#include "object.h"

using std::string;

void run_program(string code, Object* return_addr = nullptr);


#endif