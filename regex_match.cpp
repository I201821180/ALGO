/*
 * 正则表达式匹配
 */
#include <iostream>


bool match_core(char *str, char *pattern)
{
    if (*str == '\0' && *pattern == '\0')
    {
        return true;
    }

    if (*str != '\0' && *pattern == '\0')
    {
        return false;
    }

    if (*(pattern + 1) == '*')
    {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
        {
            return match_core(str, pattern+2)
                || match_core(str+1, pattern)
                || match_core(str+1, pattern+2);
        }
        else
        {
            return match_core(str, pattern+2);
        }
    }
    
    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
    {
        return match_core(str+1, pattern+1);
    }

    return false;
}

bool match(char *str, char *pattern)
{
    if (str == nullptr || pattern == nullptr)
    {
        return false;
    }

    return match_core(str, pattern);
}

int main()
{
    char str1[10] = "aaa";

    char pattern1[10] = "a.a";
    char pattern2[10] = "ab*a";

    if (match(str1, pattern1))
    {
        std::cout << "match" << std::endl;
    }
    else
    {
        std::cout << "not match" << std::endl;
    }

    if (match(str1, pattern2))
    {
        std::cout << "match" << std::endl;
    }
    else
    {
        std::cout << "not match" << std::endl;
    }
}

