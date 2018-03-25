/*
 * 第一次只出现一次的字符
 */

#include <string>
#include <iostream>
#include <map>

using namespace std;

int FirstNotRepeatingChar(string str)
{
    map<char, int> hash_table;

    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (hash_table.find(*it) != hash_table.end())
        {
            hash_table[*it] += 1;
        }
        else
        {
            hash_table[*it] = 1;
        }
    }

    int idx = -1;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (hash_table[str[i]] == 1)
        {
            idx = int(i);
            break;
        }
    }

    return idx;
}

int main()
{
    string str = "abaccdeff";
    cout << FirstNotRepeatingChar(str) << endl;
    return 0;
}

