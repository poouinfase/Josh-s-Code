from JITTESTS import prim
import multiprocessing as mp
if __name__ == '__main__':
    n_cpu = mp.cpu_count()
    pool = mp.Pool(processes=n_cpu)
    results = "".join(filter(lambda x: x is not None,
                      pool.map(prim, range(0, 10))))
    print(results)

