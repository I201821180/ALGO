/*
 * 大数乘法
 */
#include <iostream>
#include <memory.h>

#define SIZE1 10
#define SIZE2 10

int * multi(int * num1, int size1, int * num2, int size2)
{
    int size = size1 + size2;
    int * ret = new int[size];

    // 初始化数组的值
    memset(ret, 0, size*sizeof(int));

    // 遍历右侧加数的各位
    for (int i2 = 0; i2 < size2; ++i2)
    {
        int ri = size - i2 - 1;
        int ri2 = size2 - i2 - 1;
        for (int i1 = 0; i1 < size1; ++i1)
        {
            int ri1 = size1 - i1 - 1;
            ret[ri--] += num1[ri1]*num2[ri2];
        }
    }

    // 进位处理
    for (int i = size-1; i > 0; --i)
    {
        if (ret[i] >= 10)
        {
            ret[i-1] += ret[i] / 10;
            ret[i] %= 10;
        }
    }

    return ret;
}

int main()
{
    int n1[SIZE1] = {1, 1, 1, 2, 3, 4, 5, 8, 2, 7};
    int n2[SIZE2] = {2, 3, 1, 2, 3, 3, 6, 7, 6, 6};

    int * ret = multi(n1, SIZE1, n2, SIZE2);

    int size = SIZE1 + SIZE2;

    for (int i = 0; i < size; ++i)
    {
        std::cout.width(2);
        std::cout << *(ret + i);
    }
    std::cout << std::endl;

    // 释放内存
    delete [] ret;

    return 0;
}

