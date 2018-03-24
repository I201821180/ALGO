/*
 * 丑数
 */

#include <vector>
#include <iostream>

using namespace std;

int GetUglyNumber_Solution(int index)
{
    if (index <= 0)
    {
        return 0;
    }

    vector<int> ugly_numbers = {1};

    int i = 1;
    int greatest = 1;

    while (i < index)
    {
        size_t j;
        int ugly_2, ugly_3, ugly_5;
        
        for (j = 0; 2*ugly_numbers[j] <= greatest; j++) {}
        ugly_2 = 2*ugly_numbers[j];

        for (j = 0; 3*ugly_numbers[j] <= greatest; j++) {}
        ugly_3 = 3*ugly_numbers[j];

        for (j = 0; 5*ugly_numbers[j] <= greatest; j++) {}
        ugly_5 = 5*ugly_numbers[j];

        if (ugly_2 < ugly_3)
        {
            greatest = ugly_2;
        }
        else
        {
            greatest = ugly_3;
        }

        if (ugly_5 < greatest)
        {
            greatest = ugly_5;
        }

        ugly_numbers.push_back(greatest);
        i++;
    }

    return ugly_numbers[i-1];
}

int main()
{
    cout << GetUglyNumber_Solution(1) << endl;
    cout << GetUglyNumber_Solution(10) << endl;

    return 0;
}

