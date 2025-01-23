#include "string_funcs.h"

vector<string> split(string str, char ch)
{
    vector<string> result;
    string current;
    int j = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ch)
        {
            result.push_back(current);
            current = "";
            j = 0;
            continue;
        }

        current.insert(j, 1, str[i]);

        j++;
    }

    result.push_back(current);

    return result;
}

string join(vector<string> words, char joiner)
{
    string result = "";
    for (string word : words)
    {
        result.append(word);
        result.append(1, joiner);
    }

    return result.substr(0, result.size() - 1);
}


string find_and_replace(const string& str, string find, string replace, int pos)
{
    char symbols[3] = {'(', ')', '.'};
    char symbol = symbols[pos];

    vector<string> comps = split(str, symbol);
    for (size_t i = 0; i < comps.size(); i++)
    {
        vector<string> words = split(comps[i], ' ');
        for (size_t j = 0; j < words.size(); j++)
        {
            string word = words[j];
            if (word.size() < 1)
                continue;

            string temp = word.substr(1, word.size() - 1);
            string temp2 = word.substr(0, word.size() - 1);
            if (word.compare(find) == 0)
                words[j] = replace;

            // accounting for opening paren
            else if (temp.compare(find) == 0)
            {
                word = "(";
                word.append(replace);
                words[j] = word;
            }
            // accounting for closing paren
            else if (temp2.compare(find) == 0)
            {
                word = replace;
                word.append(")");
                words[j] = word;
            }
        }
        comps[i] = join(words, ' ');
    }

    string next = join(comps, symbol);

    if (pos == 2)
        return next;
    
    pos++;
    return find_and_replace(next, find, replace, pos);
}

bool is_found(const string& str, string find)
{
    vector<string> words = split(str, ' ');
    for (string word : words)
    {
        string temp1 = word.substr(1, word.size() - 1);
        string temp2 = word.substr(0, word.size() - 1);

        if (word.compare(find) == 0)
            return true;
        else if (temp1.compare(find) == 0)
            return true;
        else if (temp2.compare(find) == 0)
            return true;
    }

    return false;
}