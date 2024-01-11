import numpy as np
from numba import vectorize,njit,cuda
from time import perf_counter as p

#@vectorize(target_backend = 'cuda')
def Multip(a,b):
    return a*b;

N=2**22
A = np.ones(N,dtype=float)
B = np.ones(N,dtype=float)
st = p() 
C=Multip(A,B)
en=p()
print(en-st);
print(C[:6:],C[-6::],sep='\n')

