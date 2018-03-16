/*
 * 调整数组顺序是奇数位于偶数前面
 */

#include <vector>
#include <iostream>

using namespace std;

bool isEven(int n)
{
    return (n % 2) == 0;
}

void reOrderArray(vector<int> & array)
{
    if (array.size() == 0)
    {
        return;
    }

    vector<int> evens, odds;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (isEven(array[i]))
        {
            evens.push_back(array[i]);
        }
        else
        {
            odds.push_back(array[i]);
        }
    }

    vector<int> all;
    all.reserve(odds.size() + evens.size());
    all.insert(all.end(), odds.begin(), odds.end());
    all.insert(all.end(), evens.begin(), evens.end());

    array.swap(all);
}

int main()
{
    vector<int> array = {2, 4, 6, 1, 3, 5, 7};

    reOrderArray(array);
    
    for (size_t i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

