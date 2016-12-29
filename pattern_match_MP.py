# -*- coding: utf-8 -*-
# MP算法进行模式匹配的python实现

# 获取失效列表
def calF(s):
    F = [0]*(len(s) + 1)
    F[0] = -1
    i = 0
    j = -1

    while i < len(s):
        while j > -1 and s[i] != s[j]:
            j = F[j]
        j += 1
        i += 1
        F[i] = j

    return F

def match_MP(target, pattern):
    i = 0
    j = 0

    F = calF(pattern)

    while i < len(target):
        while j >= 0 and target[i] != pattern[j]:
            j = F[j]
        if j >= len(pattern) - 1:
            return i - len(pattern) + 1
        i += 1
        j += 1

    return -1

