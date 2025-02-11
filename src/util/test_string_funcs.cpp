#include <iostream>
#include "string_funcs.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool test_split();
bool test_join();
bool test_find_and_replace();
bool test_is_found();
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
    {.input = "console.log(name)", .find = "name", .replace = "\"Rick\"", .output = "console.log(\"Rick\")"},
    {.input = "var sum = num1 + num2", .find = "num1", .replace = "5", .output = "var sum = 5 + num2"}
};

struct test_case_found
{
    string input;
    string find;
    bool output;
};

test_case_found is_found_cases[3] = {
    {.input = "\nreturn true", .find = "return", .output = true},
    {.input = "var num = 5", .find = "return", .output = false},
    {.input = "return true\n", .find = "return", .output = true}
};


int main()
{
    int passed = 0;
    int total = 4;

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
    
    cout << endl;
    if (test_is_found())
    {
        passed++;
        cout << "test_is_found passed" << endl;
    }
    else
        cout << "test_is_found failed" << endl;
    
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
    cout << "'find_and_replace' function test:" << endl;
    for (int i = 0; i < 3; i++)
    {
        string expected_output = fr_cases[i].output;
        string actual_output = find_and_replace(fr_cases[i].input, fr_cases[i].find, fr_cases[i].replace, 0);

        cout << "Testing" << " \"" << fr_cases[i].input << "\"";
        cout << " with find = \"" << fr_cases[i].find << "\"";
        cout << " and replace = \"" << fr_cases[i].replace << "\"" << endl;

        if (actual_output.compare(expected_output) != 0)
            return false;
    }

    return true;
}

bool test_is_found()
{
    cout << "'is_found' function test:" << endl;
    for (int i = 0; i < 3; i++)
    {
        bool expected_output = is_found_cases[i].output;
        bool actual_output = is_found(is_found_cases[i].input, is_found_cases[i].find);

        cout << "Testing" << " \"" << is_found_cases[i].input << "\"";
        cout << " with find = \"" << is_found_cases[i].find << "\"" << endl;

        if (actual_output != expected_output)
            return false;
    }

    return true;
}