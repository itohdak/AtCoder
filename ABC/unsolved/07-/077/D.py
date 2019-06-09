#!/usr/bin/env python
#-*- coding: utf-8 -*-

import numpy as np

if __name__ == "__main__":
    K = int(raw_input())
    graph = np.ones(K, int) * K
    graph[1] = 0
    visited = np.zeros(K, int)

    queue = []
    visited[1] = 1
    queue.append(1)
    while graph[0] == K:
        tmp = queue[0]
        queue = queue[1:]

        target1 = (tmp + 1) % K
        graph[target1] = min(graph[target1], graph[tmp] + 1)
        if visited[target1] == 0:
            visited[target1] = 1
            queue.append(target1)

        target2 = (tmp * 10) % K
        graph[target2] = min(graph[target2], graph[tmp])
        if visited[target2] == 0:
            visited[target2] = 1
            queue.append(target2)


    print int(graph[0] + 1)
