/* 使用BF算法进行模式匹配 */

#include <iostream>
#include <cstring>

int BF_match(const char * target, const char * pattern)
{
    int len_target = strlen(target);
    int len_pattern = strlen(pattern);

    for (int ti = 0; ti <= (len_target - len_pattern); ++ti)
    {
        int pi = 0;
        for (; pi < len_pattern; ++pi)
        {
            if ( *(pattern + pi) != *(target + pi + ti) )
            {
                break;
            }
        }
        
        if (pi == len_pattern)
        {
            return ti;
        }
    }

    return -1;
}

int main()
{
    char target[50];
    char pattern[50];

    std::cout << "Input target string:";
    std::cin >> target;

    std::cout << "Input patter string:";
    std::cin >> pattern;

    int result = BF_match(target, pattern);

    if (result < 0)
    {
        std::cout << "Not found." << std::endl;
    }
    else
    {
        std::cout << "Found pattern, index = " << result << std::endl;
    }

    return 0;
}

