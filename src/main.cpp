#include "textparser.h"
#include <fstream>
#include <iostream>
#include <string>
#include "program.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

void run(string code);

int main(int argc, char** argv)
{
    string file_name = argv[1];

    int period = file_name.find('.');
    string file_ext = file_name.substr(period + 1, 2);

    if (file_ext.compare("fs") != 0)
    {
        cout << "Incompatible file type" << endl;
        return -1;
    }

    ifstream source_file(file_name);

    source_file.seekg(0, source_file.end);
    int length = source_file.tellg();
    source_file.seekg(0, source_file.beg);

    string code;
    
    char next;
    for (int i = 0; i < length; i++)
    {
        source_file >> std::noskipws >> next;
        code.insert(i, 1, next);
    }

    run(code);
    return 0;
}

void run(string code)
{
   TextParser parser = TextParser(code);
   try
   {
        vector<Token> tokens = parser.tokenize();
        // for (Token token : tokens)
        // {
        //     if (token.content == "")
        //         cout << "Content: " << "NOTHING!";
        //     else
        //         cout << "Content: " << token.content;

        //     cout << ", Type: " << token.type << endl;
        // }
        
        Program program = Program(tokens);
        program.run();
        // if tokens are valid, then run program
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}