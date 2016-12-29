/* 使用MP算法进行模式匹配 */

#include <cstring>
#include <iostream>

/*
 * 获取失效列表的过程也是一个模式匹配过程，需要是两个模式字符串进行相对平移来进行匹配。
 */
void calF(const char * s, int * F)
{
    int i = 0;
    int j = -1;
    F[0] = -1;

    while (s[i] != '\0')
    {
        while (j > -1 && s[i] != s[j])
        {
            // 利用前面的失效函数进行对齐
            j = F[j];
        }
        F[++i] = ++j;
    }
}

int MP_match(const char * target, const char * pattern)
{
    int i = 0, j = 0;
    int len_pattern = strlen(pattern);

    int * F = new int[len_pattern];

    // 获取失效列表
    calF(pattern, F);

    while (target[i] != '\0')
    {
        while (j >= 0 && target[i] != pattern[j])
        {
            // 平移模式串对齐
            j = F[j];
        }

        if (j >= len_pattern - 1)
        {
            return i - len_pattern + 1;
        }

        j++;
        i++;
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

