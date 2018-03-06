/*
 * C++ implementation for the quicksort, complexity O(NlogN)
 */

#include <iostream>


int partition(int *A, int l, int r)
{
    int i = l, j = r;
    int x = A[i]; // pivot

    while (i < j)
    {
        // Find a A[j] to fill A[i]
        while (i < j && A[j] > x)
        {
            j--;
        }

        if (i < j)
        {
            A[i] = A[j];
            i++;
        }

        // Find a A[i] to fill A[j]
        while (i < j && A[i] < x)
        {
            i++;
        }

        if (i < j)
        {
            A[j] = A[i];
            j--;
        }
    }

    A[i] = x;

    return i;
}

void quick_sort(int *A, int l, int r)
{
    if (l < r)
    {
        int q = partition(A, l, r);
        quick_sort(A, l, q-1);
        quick_sort(A, q+1, r);
    }
}

int main()
{
    int A[10] = {4, 1, 3, 2, 10, 8, 7, 9, 11, 5};
    quick_sort(A, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

