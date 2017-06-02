/*
 * Find max subarray using divide and conquer method, complexity O(NlogN).
 */

#include <iostream>
#include <limits>

void find_max_cross_subarray(int *A, int mid, int left, int right,
                             int *max_left, int *max_right, int *max_sum)
{
    // Left.
    int sum_left = 0;
    int max_sum_left = std::numeric_limits<int>::min();
    for (int i = mid; i >= left; --i)
    {
        sum_left += A[i];
        if (sum_left > max_sum_left)
        {
            max_sum_left = sum_left;
            *max_left = i;
        }
    }

    // Right.
    int sum_right = 0;
    int max_sum_right = std::numeric_limits<int>::min();
    for (int i = mid + 1; i <= right; ++i)
    {
        sum_right += A[i];
        if (sum_right > max_sum_right)
        {
            max_sum_right = sum_right;
            *max_right = i;
        }
    }

    *max_sum = max_sum_left + max_sum_right;
}

void find_max_subarray(int *A, int left, int right,
                       int *max_left, int *max_right, int *max_sum)
{
    // Base case.
    if (left >= right)
    {
        *max_left = left;
        *max_right = right;
        *max_sum = A[left];
    }
    else
    {
        // Divide.
        int mid = (right + left)/2;
        // Left.
        int left_max_left = 0;
        int left_max_right = 0;
        int left_max_sum = 0;
        find_max_subarray(A, left, mid, &left_max_left, &left_max_right,
                          &left_max_sum);
        // Right.
        int right_max_left = 0;
        int right_max_right = 0;
        int right_max_sum = 0;
        find_max_subarray(A, mid+1, right, &right_max_left, &right_max_right,
                          &right_max_sum);

        // Middle.
        int mid_max_left = 0;
        int mid_max_right = 0;
        int mid_max_sum = 0;
        find_max_cross_subarray(A, mid, left, right,
                                &mid_max_left, &mid_max_right, &mid_max_sum);

        if (left_max_sum > mid_max_sum && left_max_sum > right_max_sum)
        {
            *max_sum = left_max_sum;
            *max_left = left_max_left;
            *max_right = left_max_right;
        }
        else if (mid_max_sum > left_max_sum && mid_max_sum > right_max_sum)
        {
            *max_sum = mid_max_sum;
            *max_left = mid_max_left;
            *max_right = mid_max_right;
        }
        else
        {
            *max_sum = right_max_sum;
            *max_left = right_max_left;
            *max_right = right_max_right;
        }
    }
}

int main(void)
{
    int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int max_left = 0;
    int max_right = 0;
    int max_sum = 0;

    find_max_subarray(A, 0, 15, &max_left, &max_right, &max_sum);

    std::cout << "max_left: " << max_left << std::endl;
    std::cout << "max_right: " << max_right << std::endl;
    std::cout << "max_sum: " << max_sum << std::endl;

    return 0;
}

