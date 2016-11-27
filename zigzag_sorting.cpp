/*
 * Z字形排序
 */

#include <iostream>

#define SIZE 8

int main()
{
    int matrix[SIZE][SIZE] = {{0}};
    int sorted[SIZE][SIZE] = {{0}};

    // 初始化原始矩阵
    int * p = &matrix[0][0];
    for (int i = 0; i < SIZE*SIZE; ++i)
    {
        *(p + i) = i;
    }

    // 输出原始矩阵
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            std::cout.width(4);
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // 进行Z字形排序
    int x = 0, y = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            *(*(sorted + x) + y) = *(*(matrix + i) + j);

            // 向右移动
            if ((x == 0 || x == SIZE-1) && y % 2 == 0)
            {
                y++;
                continue;
            }

            // 向下移动
            if ((y == 0 || y == SIZE-1) && x % 2 == 1)
            {
                x++;
                continue;
            }

            // 向左下移动
            if ((x + y) % 2 == 1)
            {
                y--;
                x++;
            }
            // 右上
            else if ((x + y) % 2 == 0)
            {
                y++;
                x--;
            }
        }
    }

    // 输出排序后矩阵
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            std::cout.width(4);
            std::cout << sorted[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}

