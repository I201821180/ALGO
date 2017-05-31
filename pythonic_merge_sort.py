#!/usr/bin/env python
# -*- coding: utf-8 -*-
# More pythonic implementation for merge sort, complexity O(NlogN)

def merge(L, R):
    A = L + R
    L.append(float('inf'))
    R.append(float('inf'))

    i, j = 0, 0
    for k in range(len(A)):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

    return A

def merge_sort(A):
    if len(A) > 1:
        q = (len(A)-1)//2
        L = merge_sort(A[: q+1])
        R = merge_sort(A[q+1:])
        return merge(L, R)
    else:
        return A

if __name__ == '__main__':
    A = [3, 41, 52, 26, 38, 57, 9, 49]
    print("Before sort:{}".format(A))
    A = merge_sort(A)
    print("After sort:{}".format(A))

