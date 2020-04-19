#!/usr/bin/env python
#-*- coding: utf-8 -*-

import numpy as np
from itertools import product

if __name__ == "__main__":
    N, M, K = map(int, raw_input().split())
    success = False
    for n, m in product(range(N), range(M)):
        rows = np.zeros((N, M))
        rows[:, 0:n] = 1
        cols = np.zeros((N, M))
        cols[0:m, :] = 1
        board = rows + cols
        board = np.where(board % 2 == 1, 1, 0)
        if np.sum(board) == K:
            success = True
            break
    if success:
        print "Yes"
    else:
        print "No"


