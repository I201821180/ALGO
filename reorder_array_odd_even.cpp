/*
 * 调整数组顺序是奇数位于偶数前面
 */

#include <vector>
#include <iostream>

using namespace std;

bool isEven(int n)
{
    return (n % 2) == 0;
}

void reOrderArray(vector<int> & array)
{
    if (array.size() == 0)
    {
        return;
    }

    int i = 0, j = array.size() - 1;

    while (i < j)
    {
        while (!isEven(array[i]))
        {
            i++;
        }

        while (isEven(array[j]))
        {
            j--;
        }

        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

int main()
{
    vector<int> array = {4, 5, 1, 2, 3, 7};

    reOrderArray(array);
    
    for (size_t i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

