/* 输出回文数 */

#include <iostream>

int reverse(int a)
{
    int reversed = 0;

    while (a)
    {
        reversed = reversed*10 + a%10;
        a /= 10;
    }

    return reversed;
}

void find_palindromic(int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        int reversed = reverse(i);
        if (reversed == i)
        {
            std::cout << i << std::endl;
        }
    }
}

int main()
{
    find_palindromic(300, 5000);

    return 0;
}

