from numba import njit, cuda 
import numpy as np 
# to measure exec time 
from timeit import default_timer as timer    
  
# normal function to run on cpu 
def func(a):                                 
    for i in range(a.size): 
        a[i]+= 1      
  
# function optimized to run on gpu  
@njit(target_backend='cuda')                          
def func2(a): 
    for i in range(a.size): 
        a[i]+= 1
if __name__=="__main__": 
    n = 10**6
    a = np.ones(n, dtype = np.float64) 
    func2(np.arange(3)) 
    start = timer() 
    func(a) 
    print("without GPU:", timer()-start)     
      
    start = timer() 
    func2(a) 
    print("with GPU:", timer()-start)
#HAHAHAHHAHAH
