class process:
    def __init__(self, ariv, pid,  burst, prior, wait=0):
        self.pid = int(pid)
        self.burst = int(burst)
        self.prior = int(prior)
        self.admitted = int(wait)
        self.arival = int(ariv)
        self.cacheburs = int(burst)

    def __getitem__(self, ind):
        match(ind):
            case 0: return self.pid
            case 1: return self.burst
            case 2: return self.prior
            case 3: return self.admitted
            case 4: return self.arival
            case _: raise BaseException("ONLY FIVE THINGS")

    def __setitem__(self, ind, val):
        match(ind):
            case 0:  self.pid = val
            case 1:  self.burst = val
            case 2:  self.prior = val
            case 3:  self.admitted = val
            case 4:  self.arival = val
            case _: raise BaseException("ONLY FIVE THINGS")

    def __str__(self):
        return f"Pid: {self.pid}\nBurst: {self.cacheburs}" +\
            f"\nprior: {self.prior}\nwait: {self.admitted}\n"


def FCFS():
    time = 0
    f = open('Proctabl.txt', 'r')
    proclis = []
    for procAt in f.readlines():
        proclis.append(process(*procAt.split()))
    f.close()
    for i in range(len(proclis)):
        s = True
        while s:
            s = False
            if proclis[i][4] > time:
                s = True
                time += 1
                continue
            proclis[i][3] = time
            time += proclis[i][1]
    print(*proclis, sep='\n')


def PRIORITY_PREMPTIVE():
    time = 0
    f = open('Proctabl.txt', 'r')
    proclis = []
    for procAt in f.readlines():
        proclis.append(process(*procAt.split()))
    f.close()
    procomp = 0
    ready = []
    while procomp < len(proclis):
        for i in proclis:
            if i[4] == time:
                ready.append(i)
        if len(ready) == 0:
            time += 1
            continue
        best = ready[0]
        for i in ready:
            if i[2] < best[2]:
                best = i
            if i[2] == best[2]:
                best = best if (best[4] < i[4]) else i
        for i in ready:
            if best is not i:
                i[3] += 1
        best[1] += -1
        if best[1] == 0:
            ready.remove(best)
            procomp += 1
        time += 1
    print(*proclis, sep='\n')


def PRIORITY_NONPREMPTIVE():
    time = 0
    f = open('Proctabl.txt', 'r')
    proclis = []
    for procAt in f.readlines():
        proclis.append(process(*procAt.split()))
    f.close()
    procomp = 0
    ready = []
    best = None
    while procomp < len(proclis):
        for i in proclis:
            if i[4] == time:
                ready.append(i)
        if len(ready) == 0:
            time += 1
            continue
        if best is None:
            best = ready[0]
            for i in ready:
                if i[2] < best[2]:
                    best = i
                if i[2] == best[2]:
                    best = best if (best[4] < i[4]) else i
        for i in ready:
            if best is not i:
                i[3] += 1
        best[1] += -1
        if best[1] == 0:
            ready.remove(best)
            best = None
            procomp += 1
        time += 1
    print(*proclis, sep='\n')


def SJF_PREMPTIVE():
    time = 0
    f = open('Proctabl.txt', 'r')
    proclis = []
    for procAt in f.readlines():
        proclis.append(process(*procAt.split()))
    f.close()
    procomp = 0
    ready = []
    while procomp < len(proclis):
        for i in proclis:
            if i[4] == time:
                ready.append(i)
        if len(ready) == 0:
            time += 1
            continue
        best = ready[0]
        for i in ready:
            if i[1] < best[1]:
                best = i
            if i[1] == best[1]:
                best = best if (best[4] < i[4]) else i
        for i in ready:
            if best is not i:
                i[3] += 1
        best[1] += -1
        if best[1] == 0:
            ready.remove(best)
            procomp += 1
        time += 1
    print(*proclis, sep='\n')


def SJF_NONPREMPTIVE():
    time = 0
    f = open('Proctabl.txt', 'r')
    proclis = []
    for procAt in f.readlines():
        proclis.append(process(*procAt.split()))
    f.close()
    procomp = 0
    ready = []
    best = None
    while procomp < len(proclis):
        for i in proclis:
            if i[4] == time:
                ready.append(i)
        if len(ready) == 0:
            time += 1
            continue
        if best is None:
            best = ready[0]
            for i in ready:
                if i[1] < best[1]:
                    best = i
                if i[1] == best[1]:
                    best = best if (best[4] < i[4]) else i
            # print("BEST: at ", time, "\n",  best)
        for i in ready:
            if best is not i:
                i[3] += 1
        best[1] += -1
        time += 1
        if best[1] == 0:
            ready.remove(best)
            procomp += 1
            best = None
    print(*proclis, sep='\n')


def ROUNDROBIN(TimQ=20):
    time = 0
    f = open('Proctabl.txt', 'r')
    proclis = []
    for procAt in f.readlines():
        proclis.append(process(*procAt.split()))
    f.close()
    procomp = 0
    ready = []
    while procomp < len(proclis):
        for i in proclis:
            if i[4] <= time and i[4] > time-TimQ:
                ready.append(i)
        if len(ready) == 0:
            time += 1
            continue
        wt = min(TimQ, ready[0][1])
        ready[0][1] += -1 * wt
        tmp = ready.pop(0)
        for i in ready:
            i[3] += wt
        if tmp[1] != 0:
            ready.append(tmp)
        else:
            procomp += 1

        if len(ready):
            time += TimQ
        else:
            time += 1
    print(*proclis, sep='\n')


print("1 FCFS\n2 PRIORITIRY_PREMPTIVE\n3 PRIORITY_NONPREMEPTIVE",
      "\n4 SJF_PREMPTIVE\n5 SJF_NONPREMPTIVE\n6 ROUNDROBIN", sep='')


match(int(input())):
    case 1: FCFS()
    case 2: PRIORITY_PREMPTIVE()
    case 3: PRIORITY_NONPREMPTIVE()
    case 4: SJF_PREMPTIVE()
    case 5: SJF_NONPREMPTIVE()
    case 6: ROUNDROBIN()

