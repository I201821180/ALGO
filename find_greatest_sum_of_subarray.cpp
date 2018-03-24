/*
 * 连续子数组的最大值
 */

#include <vector>
#include <iostream>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    vector<int> max_values(array.size(), 0);

    max_values[0] = array[0];
    int greatest = max_values[0];

    for (size_t i = 1; i < array.size(); i++)
    {
        if (max_values[i-1] <= 0)
        {
            max_values[i] = array[i];
        }
        else
        {
            max_values[i] = max_values[i-1] + array[i];
        }

        if (max_values[i] > greatest)
        {
            greatest = max_values[i];
        }
    }

    return greatest;
}

int main()
{
    vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    int greatest = FindGreatestSumOfSubArray(array);

    cout << greatest << endl;

    return 0;
}

