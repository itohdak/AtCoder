#!/usr/bin/env python
#-*- coding: utf-8 -*-

if __name__ == "__main__":
    N, K = map(int, raw_input().split())
    A = []
    B = []
    C = []
    for n in range(N):
        input = map(int, raw_input().split())
        A.append(input[0])
        B.append(input[1])
        C.append(input[1] / float(input[0]))
    ans = 0
    while min(A) <= K:
        max_index = C.index(max(C))
        ans += B[max_index]
        K -= A[max_index]
        A = A[0:max_index] + A[max_index+1:len(A)]
        B = B[0:max_index] + B[max_index+1:len(B)]
        C = C[0:max_index] + C[max_index+1:len(C)]

    print ans
