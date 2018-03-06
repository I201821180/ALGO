/* 
 * C++ implementation for heap sort, complexity O(NlogN)
 */

#include <iostream>


int left(int i)
{
    return 2*(i+1) - 1;
}

int right(int i)
{
    return 2*(i+1);
}

int parent(int i)
{
    return (i+1)/2 - 1;
}

void max_heapify(int *A, int i, int size)
{
    // Indices of left and right nodes.
    int l = left(i);
    int r = right(i);

    // Index of the largest node.
    int largest;

    // Compare the left node with parent.
    if (l < size && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    // Compare the right node with the largest one.
    if (r < size && A[r] > A[largest])
    {
        largest = r;
    }

    // Exchange values.
    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        max_heapify(A, largest, size);
    }
}

void build_max_heap(int *A, int size)
{
    for (int i = size/2 - 1; i >= 0; i--)
    {
        max_heapify(A, i, size);
    }
}

void heap_sort(int *A, int size)
{
    build_max_heap(A, size);

    for (int i = size-1; i > 0; i--)
    {
        max_heapify(A, 0, i+1);

        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
    }
}

int main()
{
    int A[10] = {4, 1, 3, 2, 10, 8, 7, 9, 11, 5};
    heap_sort(A, 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

