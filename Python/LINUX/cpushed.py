import os
from time import sleep
from pointAndProcess import point, process
from multiprocessing import shared_memory as SM

# proc = process(10, 1, 0, 0)
# proc[1] += -1
# print(proc[0])
# lis = SM.ShareableList([0]*50, name='processLisr')
# lis.shm.close()
# poin = point("processLisr")
# poin[0] = proc
# print(poin[0])
# poin.unlink()


def daemon(naem):
    poiner = point('processList')
    specmem = SM.ShareableList(name='specmem')
    f = open('Proctabl.txt', 'r')
    tim = 0
    procs = f.readlines()
    f.close()
    procnum = 1
    print(procs)
    while specmem[tim] != -1 and specmem[procnum] < len(procs):
        procats = procs[procnum]
    poiner.close()
    specmem.shm.close()
    quit()


def main():
    lis = SM.ShareableList([0]*50, name='processList')
    specmem = SM.ShareableList([0, 0], name='specmem')
    lis.shm.close()
    pid = os.fork()
    if (pid == -1):
        raise BaseException('Ono')
    if (pid == 0):
        daemon('processList')
    poiners = point('processList')
    sleep(1)
    poiners.unlink()
    tim = 0
    for _ in range(50):
        specmem[tim] += 1
        print(specmem[tim])
        sleep(0.01)

    specmem[tim] = -1
    specmem.shm.close()
    specmem.shm.unlink()


if __name__ == "__main__":
    main()

