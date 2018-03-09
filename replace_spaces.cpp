/*
 * C++ implementation for the replacing the spaces in a string, complexity O(N)
 */

#include <iostream>

void replace_spaces(char *str, int length)
{
    if (str == nullptr || length <= 0)
    {
        return;
    }

    int nspaces = 0;
    int ori_length = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            nspaces++;
        }

        ori_length++;
        i++;
    }

    int new_length = ori_length + nspaces*2;

    if (new_length > length)
    {
        return;
    }

    int j = new_length;

    while (j != i)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j--;
            i--;
        }
        else
        {
            str[j] = '0';
            str[j-1] = '2';
            str[j-2] = '%';
            j -= 3;
            i--;
        }
    }

    return;
}

int main()
{
    int length = 20;
    char str[20] = "We are happy.";
    replace_spaces(str, length);
    int i = 0;
    while (str[i] != '\0')
    {
        std::cout << str[i];
        i++;
    }
    std::cout << std::endl;

}

