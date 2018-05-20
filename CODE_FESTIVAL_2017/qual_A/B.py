#!/usr/bin/env python
#-*- coding: utf-8 -*-

from itertools import product

if __name__ == "__main__":
    N, M, K = map(int, raw_input().split())
    success = False
    for n, m in product(range(N+1), range(M+1)):
        if n*M + m*N - 2*n*m == K:
            success = True
            break
    if success:
        print "Yes"
    else:
        print "No"


