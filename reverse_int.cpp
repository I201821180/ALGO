/* 输入一个整数，使用递归方式倒序输出这个整数 */

#include <iostream>

void print_reverse(int n)
{
    if ( n/10 == 0)
    {
        std::cout << n;
    }
    else
    {
        int last = n % 10;
        int newone = n / 10;
        std::cout << last;
        print_reverse(newone);
    }
}

int main()
{
    std::cout << "Input a integer: ";
    int i;
    std::cin >> i;

    print_reverse(i);
    std::cout << std::endl;

    return 0;
}
