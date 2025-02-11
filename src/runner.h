#ifndef _RUNNER_H
#define _RUNNER_H

#include <string>
#include "object.h"
#include <unordered_map>


void run_program(std::string code);
void run_program(std::string code, ::Object* return_addr);
void run_program(std::string code, ::Object* return_addr, std::unordered_map<std::string,
   ::Object*> g_variables);
void run_program(std::string code, std::unordered_map<std::string, ::Object*> g_variables);


#endif