#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Python implementation for merge sort, complexity O(NlogN)

def merge(A, p, q, r):
    L = A[p: q+1]
    R = A[q+1: r+1]
    L.append(float('inf'))
    R.append(float('inf'))

    i, j = 0, 0
    for k in range(p, r+1):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def merge_sort(A, p, r):
    if p < r:
        q = (p+r)//2
        merge_sort(A, p, q)
        merge_sort(A, q+1, r)
        merge(A, p, q, r)

if __name__ == '__main__':
    A = [3, 41, 52, 26, 38, 57, 9, 49]
    print("Before sort:{}".format(A))
    merge_sort(A, 0, 7)
    print("After sort:{}".format(A))
    
