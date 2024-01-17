from multiprocessing import shared_memory as SM


class process:
    def __init__(self, pid, burst, prior, wait):
        self.pid = pid
        self.burst = burst
        self.prior = prior
        self.wait = wait

    def __getitem__(self, ind):
        match(ind):
            case 0: return self.pid
            case 1: return self.burst
            case 2: return self.prior
            case 3: return self.wait
            case _: raise BaseException("ONLY FOUR THINGS")

    def __setitem__(self, ind, val):
        match(ind):
            case 0:  self.pid = val
            case 1:  self.burst = val
            case 2:  self.prior = val
            case 3:  self.wait = val
            case _: raise BaseException("ONLY FOUR THINGS")

    def __str__(self):
        return f"Pid: {self.pid}\nBurst: {self.burst}" +\
            f"\nprior: {self.prior}\nwait: {self.wait}"


class point():
    def __init__(self, val):
        self.val = SM.ShareableList(name=val)  # [0]*8  #
        self.siz = 16

    def __getitem__(self, ind):
        n = self.val[ind]
        siz = self.siz
        mas = 2**siz-1
        return process((n >> (3*siz)) & mas,
                       (n >> (2*siz)) & mas,
                       (n >> (1*siz)) & mas,
                       (n >> (0*siz)) & mas)

    def encode(self, tupIn):
        siz = self.siz
        return tupIn[0] << (3*siz) \
            | tupIn[1] << (2*siz) | tupIn[2] << (1*siz) | tupIn[3]

    def __setitem__(self, Ind, val: process):
        self.val[Ind] = self.encode(val)

    def unlink(self):
        self.val.shm.close()
        self.val.shm.unlink()

    def close(self):
        self.val.shm.close()
