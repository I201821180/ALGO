#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Python implementation for insertion sort, complexity O(n^2)

def insertion_sort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1

        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i -= 1

        A[i+1] = key

if __name__ == '__main__':
    A = [3, 41, 52, 26, 38, 57, 9, 49]
    print("Before sort:{}".format(A))
    insertion_sort(A)
    print("After sort:{}".format(A))

