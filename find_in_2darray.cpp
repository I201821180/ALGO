/*
 * C++ implementation of number finding in 2D array, complexity O(MxN)
 */

#include <iostream>

bool find(int *matrix, int rows, int columns, int number)
{
    if (matrix == nullptr || rows <= 0 || columns <= 0)
    {
        return false;
    }

    int r = 0;
    int c = columns - 1;

    while (r < rows && c >= 0)
    {
        if (matrix[r*rows+c] == number)
        {
            return true;
        }
        else if (matrix[r*rows+c] > number)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    return false;
}

int main()
{
    int matrix[16] = {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15
    };

    bool found = find(matrix, 4, 4, 7);

    if (found)
    {
        std::cout << "Found" << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
}

