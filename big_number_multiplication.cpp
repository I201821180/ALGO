#include <iostream>
#include <memory.h>

int * multi(int * num1, int size1, int * num2, int size2)
{
    int size = size1 + size2;
    int * ret = new int[size];

    // 初始化数组的值
    memset(ret, 0, size*sizeof(int));

    // 遍历右侧加数的各位
    for (int i2 = 0; i2 < size2; ++i2)
    {
        int k = i2; // 返回数组的索引
        
        for (int i1 = 0; i1 < size1; ++i1)
        {
            ret[k++] += num2[i2]*num1[i1];
        }
    }

    // 进位处理
    for (int i = 0; i < size; ++i)
    {
        if (ret[i] >= 10)
        {
            ret[i-1] += 1;
            ret[i] %= 10;
        }
    }

    return ret;
}

