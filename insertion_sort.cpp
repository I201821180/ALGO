/*
 * C++ implementation for insertion sort, complexity O(n^2)
 */
#include <iostream>

void insertion_sort(int * A, int len)
{
    for (int j = 1; j <= len-1; ++j)
    {
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = key;
    }
}

int main(void)
{
    int A[9] = {3, 41, 52, 26, 38, 57, 9, 49};
    std::cout << "Before sort: ";
    for (int i = 0; i < 9; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    insertion_sort(A, 9);
    std::cout << "After sort: ";
    for (int i = 0; i < 9; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

