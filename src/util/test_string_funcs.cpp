#include <iostream>
#include "string_funcs.h"

using std::cout;
using std::endl;

bool test_split();
bool test_join();
bool test_find_and_replace();
void print_vector(vector<string>);

struct test_case_s
{
    string str;
    char ch;
    vector<string> output;
};

vector<string> split_outputs[3] = {
    {"My", "name", "is", "nobody"},
    {"console.log", "'Hello');"},
    {"console", "log('Hello');"}
};

test_case_s split_cases[3] = {
    {.str = "My name is nobody", .ch = ' ', .output = split_outputs[0]},
    {.str = "console.log('Hello');", .ch = '(', .output = split_outputs[1]},
    {.str = "console.log('Hello');", .ch = '.', .output = split_outputs[2]}
};

struct test_case_j
{
    vector<string> input;
    char ch;
    string output;
};

test_case_j join_cases[3] = {
    {.input = split_outputs[0], .ch = ' ', .output = "My name is nobody"},
    {.input = split_outputs[1], .ch = '(', .output = "console.log('Hello');"},
    {.input = split_outputs[2], .ch = '.', .output = "console.log('Hello');"}
};

struct test_case_fr
{
    string input;
    string find;
    string replace;
    string output;
};

test_case_fr fr_cases[3] = {
    {.input = "I am the gingerbread man", .find = "man", .replace = "lady", .output = "I am the gingerbread lady"},
    {.input = "console.log(name);", .find = "name", .replace = "\"Rick\"", .output = "console.log(\"Rick\")"},
    {.input = "var sum = num1 + num2;", .find = "num1", .replace = "5", .output = "var sum = 5 + num2;"}
};


int main()
{
    int passed = 0;
    int total = 3;

    if (test_split())
    {
        passed++;
        cout << "test_split passed" << endl;
    }
    else
        cout << "test_split failed" << endl;
    
    cout << endl;
    if (test_join())
    {
        passed++;
        cout << "test_join passed" << endl;
    }
    else
        cout << "test_join failed" << endl;
    
    cout << endl;
    if (test_find_and_replace())
    {
        passed++;
        cout << "test_find_and_replace passed" << endl;
    }
    else
        cout << "test_find_and_replace failed" << endl;
    
    cout << passed << " of " << total << " tests passed" << endl;
    return 0;
}

bool test_split()
{
    cout << "'split' function test:" << endl;
    for (int i = 0; i < 3; i++)
    {
        string str = split_cases[i].str;
        char ch = split_cases[i].ch;
        vector<string> expected_output = split_cases[i].output;
        cout << "Testing \"" << str << "\"";
        cout << " with split character '" << ch << "'" << endl;

        vector<string> actual_output = split(str, ch);
        for (size_t i = 0; i < expected_output.size(); i++)
        {
            if (expected_output[i] != actual_output[i])
                return false;
        }
    }

    return true;
}

bool test_join()
{
    cout << "'join' function test:" << endl;
    for (int i = 0; i < 3; i++)
    {
        vector<string> input = join_cases[i].input;
        char ch = join_cases[i].ch;
        string expected_output = join_cases[i].output;
        cout << "Testing ";  
        print_vector(input);
        cout << " with join character '" << ch << "'" << endl;

        string actual_output = join(input, ch);

        if (actual_output.compare(expected_output) != 0)
            return false;
    }

    return true;
}

void print_vector(vector<string> strs)
{
    cout << "[";
    for (size_t i = 0; i < strs.size(); i++)
    {
        cout << strs[i];

        if (i < strs.size() - 1)
            cout << ", ";
        
    }

    cout << "]";
}


bool test_find_and_replace()
{
    for (int i = 0; i < 3; i++)
    {
        string expected_output = fr_cases[i].output;
        string actual_output = find_and_replace(fr_cases[i].input, fr_cases[i].find, fr_cases[i].replace, 0);

        if (actual_output.compare(expected_output) != 0)
            return false;
    }

    return true;
}