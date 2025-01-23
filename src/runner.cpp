#include "runner.h"
#include "textparser.h"
#include "program.h"
#include <iostream>

using std::endl;

void run_program(string code)
{
   TextParser parser = TextParser(code);
   try
   {
        vector<Token> tokens = parser.tokenize();
        
        Program program = Program(tokens);
        program.run();
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << endl;
   }
   
}

void run_program(string code, Object* return_addr)
{
    TextParser parser = TextParser(code);
    try
    {
        vector<Token> tokens = parser.tokenize();

        Program program = Program(tokens);
        *return_addr = *(program.run());
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << endl;
    }
    
}
void run_program(string code, Object* return_addr, unordered_map<string, Object*> g_variables)
{
    TextParser parser = TextParser(code);
    try
    {
        vector<Token> tokens = parser.tokenize();

        Program program = Program(tokens, g_variables);
        *return_addr = *(program.run());
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << endl;
    }

}
void run_program(string code, unordered_map<string, Object*> g_variables)
{
    TextParser parser = TextParser(code);
    try
    {
        vector<Token> tokens = parser.tokenize();

        Program program = Program(tokens, g_variables);
        program.run();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << endl;
    }

}
