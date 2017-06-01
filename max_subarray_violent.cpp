/*
 * Solve the max subarray violently, complexity O(N^2)
 */
#include <iostream>

void find_max_subarray(int *A, int len, int *max_left, int *max_right, int *max_sum)
{
    for (int i = 0; i < len; ++i)
    {
        int sum = A[i];
        if (sum > *max_sum)
        {
            *max_sum = sum;
            *max_left = i;
            *max_right = i;
        }

        for (int j = i+1; j < len; ++j)
        {
            sum += A[j];

            if (sum > *max_sum)
            {
                *max_sum = sum;
                *max_left = i;
                *max_right = j;
            }
        }
    }
}

int main(void)
{
    int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int max_left = 0;
    int max_right = 0;
    int max_sum = 0;

    find_max_subarray(A, 16, &max_left, &max_right, &max_sum);

    std::cout << "max_left: " << max_left << std::endl;
    std::cout << "max_right: " << max_right << std::endl;
    std::cout << "max_sum: " << max_sum << std::endl;

    return 0;
}

