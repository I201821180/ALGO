/* 反转字符串 */

#include <iostream>
#include <string>
#include <cstring>

// C 风格字符串反转输出
void reverse_c(char * s)
{
    int len = strlen(s);

    for (int i = len-1; i >= 0; --i)
    {
        std::cout << *(s+i);
    }
}

// 使用递归反转C风格字符串
void reverse_recursive(char * s, int idx)
{
    if (s[idx] == '\0')
    {
        return;
    }
    else
    {
        reverse_recursive(s, idx+1);
        std::cout << s[idx];
    }
}

// 反转std::string
void reverse_std_string(char * s)
{
    std::string string(s);

    for (auto it = string.rbegin(); it != string.rend(); ++it)
    {
        std::cout << *it;
    }
}

int main()
{
    char s[20];

    std::cout << "Enter a string: ";
    std::cin >> s;

    std::cout << "reverse_c():";
    reverse_c(s);
    std::cout << std::endl;

    std::cout << "reverse_recursive():";
    reverse_recursive(s, 0);
    std::cout << std::endl;

    std::cout << "reverse_std_string():";
    reverse_std_string(s);
    std::cout << std::endl;

    return 0;
}

