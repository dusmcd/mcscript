#ifndef _RUNNER_H
#define _RUNNER_H

#include <string>
#include "object.h"
#include <unordered_map>

using std::string;
using std::unordered_map;

void run_program(string code);
void run_program(string code, Object* return_addr);
void run_program(string code, Object* return_addr, unordered_map<string, Object*> g_variables);
void run_program(string code, unordered_map<string, Object*> g_variables);


#endif