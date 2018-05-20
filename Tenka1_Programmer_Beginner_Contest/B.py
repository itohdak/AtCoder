#!/usr/bin/env python
#-*- coding: utf-8 -*-

if __name__ == "__main__":
    N = int(raw_input())
    A = []
    B = []
    for n in range(N):
        input = map(int, raw_input().split())
        A.append(input[0])
        B.append(input[1])
    minimam = min(B)
    print A[B.index(minimam)] + minimam
