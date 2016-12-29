/* 使用MP算法进行模式匹配 */

#include <cstring>
#include <iostream>

void calF(const char * s, int * F)
{
    F[0] = 0;
    int i = 1, j = 0;

    while (s[i] != '\0')
    {
        if (s[i] == s[j])
        {
            F[i++] = ++j;
        }
        else
        {
            if (j > 0)
            {
                j = 0;
            }
            else
            {
                F[i++] = j;
            }
        }
    }
}

int MP_match(const char * target, const char * pattern)
{
    int i = 0, j = 0;
    int len_pattern = strlen(pattern);

    int * F = new int[len_pattern];

    while (target[i] != '\0')
    {
        if (target[i] == pattern[j])
        {
            i++;
            j++;

            if (j >= len_pattern)
            {
                return i - len_pattern;
            }
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = F[i-1];
            }
        }
    }

    delete [] F;

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

    int result = MP_match(target, pattern);

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

