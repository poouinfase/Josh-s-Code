import numpy as np
from time import perf_counter as p
# from numba import vectorize, njit

# @vectorize(target_backend = 'cuda')


def Multip(a, b):
    return a*b


N = 2**22
A = np.ones(N, dtype=float)
B = np.ones(N, dtype=float)
st = p()
C = Multip(A, B)
en = p()
print(en-st)
print(C[:6:], C[-6::], sep='\n')
