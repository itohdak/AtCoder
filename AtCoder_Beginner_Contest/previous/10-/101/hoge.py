import numpy as np
import matplotlib.pyplot as plt

def S(x):
    ret = 0
    for i in range(15):
        ret += x % 10
        x /= 10
    return ret

def calc(x):
    return 1.0 * x / S(x)

# n = 200
# x = np.arange(1, n, 1)
# y = 1. * x / hoge(x)
# x = np.arange(1, n, 1)

# plt.plot(x, y)
# plt.show()
