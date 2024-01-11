from time import perf_counter as p 
from numba import cuda,njit

@njit(target_backend='cuda')
def contnumba(n):
  dic={0:0,1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0}
  for i in range(10**n):
    while i:
      dic[i%10]+=1
      i//=10
  return dic

if __name__=='__main__':
    t0=p()
    print(contnumba(9))
    tn=p()
    print(tn-t0)
