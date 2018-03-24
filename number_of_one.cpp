/*
 * 从1到n证书中出现1的次数
 */

#include <cmath>
#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n < 10)
    {
        return 1;
    }


    int digits = 0;
    int h;
    int n_copy = n;

    while (n_copy != 0)
    {
        digits++;
        h = n_copy % 10;
        n_copy = n_copy/10;
    }

    int number = 0;

    if (h > 1)
    {
        number += pow(10, digits-1);
    }
    else
    {
        number += (n - pow(10, digits-1) + 1);
    }

    number += h*pow(10, digits-2)*(digits-1);

    number += NumberOf1Between1AndN_Solution(n - h*pow(10, digits-1));

    return number;
}

int main()
{
    cout << NumberOf1Between1AndN_Solution(10) << endl;
    return 0;
}

