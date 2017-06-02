#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Find max subarray using divide and conquer method, complexity O(NlogN).

def find_max_cross_subarray(A):
    mid = len(A)//2
    # Left.
    max_left  = max([A[i: mid] for i in range(mid)], key=sum)
    # Right.
    max_right = max([A[mid: i] for i in range(mid, len(A))], key=sum)

    return max_left + max_right


def find_max_subarray(A):
    # Base case.
    if len(A) <= 1:
        return A
    else:
        mid = len(A)//2
        # Left.
        max_left = find_max_subarray(A[: mid])
        # Right.
        max_right = find_max_subarray(A[mid:])
        # Middle.
        max_middle = find_max_cross_subarray(A)

        return max([max_left, max_right, max_middle], key=sum)

if '__main__' == __name__:
    A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7];
    max_subarray = find_max_subarray(A)
    print('Max subarray: {}'.format(max_subarray))
    print('Max sum: {}'.format(sum(max_subarray)))

