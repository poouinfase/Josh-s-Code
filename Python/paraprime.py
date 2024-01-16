import os
import multiprocessing as mp
from time import perf_counter as p
from JITTESTS import prim

if __name__ == "__main__":
    st = 2**32
    os.chdir(r"C:\Users\catte\OneDrive\Documents\My\FUqaround\Python")
    n_cpu = mp.cpu_count()
    pool = mp.Pool(processes=n_cpu)
    results = []
    t0 = p()
    results.extend(pool.map(prim, range(2, st)))
    tn = p()
    f = open("Primepara.txt", "w")
    f.write("\n".join(filter(lambda x: x is not None, results)))
    f.write('\n'+str(tn-t0))
    f.close()
