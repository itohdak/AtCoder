#!/usr/bin/env python
#-*- coding: utf-8 -*-

import numpy as np

if __name__ == "__main__":
    H, W = map(int, raw_input().split())
    words = {}
    for h in range(H):
        input = raw_input()
        for w in range(W):
            if input[w] in words.keys():
                words[input[w]] += 1
            else:
                words[input[w]] = 1

    
