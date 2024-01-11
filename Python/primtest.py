from numba import njit,prange

@njit(parallel=True)
def primtest(n):
    for i in prange(1,round(n**0.5)+1):
        if n%i==0: return False

@njit
def primestraithg(n):
    for i in prange(1,round(n**0.5)+1):
        if n%i==0: return False
    
def primegae(n):
    for i in prange(1,round(n**0.5)+1):
        if n%i==0: return False

from time import perf_counter as perf
def tim(f):
    st=perf()
    f(100000)
    return perf()-st

print("Parallel jit: %d\n Jit: %d\nNormal: %d\n"%(tim(primtest),tim(primestraithg),tim(primegae)),end='\n')