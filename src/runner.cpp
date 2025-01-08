#include "runner.h"
#include "textparser.h"
#include "program.h"
#include <iostream>

void run_program(string code, Object* return_addr)
{
   TextParser parser = TextParser(code);
   try
   {
        vector<Token> tokens = parser.tokenize();
        
        Program program = Program(tokens);
        if (return_addr == nullptr)
          program.run();
        else
          *return_addr = *(program.run());
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}