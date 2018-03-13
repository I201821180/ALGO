/*
 * 二进制中1的个数C++实现
 */

#include <iostream>

int NumberOf1(int n)
{
    unsigned int flag = 1;
    int count = 0;

    while (flag)
    {
        if (n & flag)
        {
            count++;
        }

        flag = flag << 1;
    }

    return count;
}

int main()
{
    std::cout << "9 has " << NumberOf1(9) << " ones" << std::endl;
    return 0;
}

