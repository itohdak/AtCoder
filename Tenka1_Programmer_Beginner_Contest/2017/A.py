#!/usr/bin/env python
#-*- coding: utf-8 -*-

if __name__ == "__main__":
    S = raw_input()
    num = 0
    for i in range(6):
        if int(S[i]) == 1:
            num += 1
    print num
