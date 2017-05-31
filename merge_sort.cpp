/*
 * C++ implementation for merge sort, complexity O(NlogN)
 */

#include <iostream>
#include <limits>

void merge(int * A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    // Allocate new arrays.
    int * L = new int [n1+1];
    for (int i = 0; i < n1; ++i)
    {
        *(L + i) = A[p + i];
    }
    *(L + n1) = std::numeric_limits<int>::max();

    int * R = new int [n2+1];
    for (int i = 0; i < n2; ++i)
    {
        *(R + i) = A[q + i + 1];
    }
    *(R + n2) = std::numeric_limits<int>::max();

    // Merge two arrays.
    int i = 0;
    int j = 0;
    for (int k = p; k < r + 1; ++k)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }

    delete [] L;
    delete [] R;
}

void merge_sort(int * A, int p, int r)
{
    if (p < r)
    {
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(void)
{
    int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};
    std::cout << "Before sort: ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    merge_sort(A, 0, 7);
    std::cout << "After sort: ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

