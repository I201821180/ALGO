/*
 * 把数组排成最小的数
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comb_compare(const string & n1, const string & n2)
{
    string comb1 = n1 + n2;
    string comb2 = n2 + n1;

    return comb1 < comb2;
}

string PrintMinNumber(vector<int> numbers)
{
    if (numbers.size() <= 0)
    {
        return "";
    }

    vector<string> str_numbers;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        str_numbers.push_back(to_string(numbers[i]));
    }

    sort(str_numbers.begin(), str_numbers.end(), comb_compare);

    string result;
    for (size_t i = 0; i < str_numbers.size(); i++)
    {
        result += str_numbers[i];
    }

    return result;
}

int main()
{
    vector<int> numbers = {3, 32, 321};
    cout << PrintMinNumber(numbers) << endl;
    return 0;
}

