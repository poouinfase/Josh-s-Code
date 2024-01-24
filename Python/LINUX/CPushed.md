
FCFS
AIM: To schedule processes in order of arrival.

ALGORITHM:
STEP 1: Start
STEP 2: Read the ready queue for any processes if process is found go to step 3 else wait 1 cycle and repeat step 2
STEP 3: Execute process that is the lowest index in the ready queue
STEP 4: Set the process to the completed state and go to step 2

CODE:
```python
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
```

OUTPUT:
1 FCFS
2 PRIORITIRY_PREMPTIVE
3 PRIORITY_NONPREMEPTIVE
4 SJF_PREMPTIVE
5 SJF_NONPREMPTIVE
6 ROUNDROBIN
1
Pid: 1
Burst: 53
prior: 1
wait: 0

Pid: 2
Burst: 17
prior: 0
wait: 53

Pid: 3
Burst: 68
prior: 3
wait: 70

Pid: 4
Burst: 24
prior: 4
wait: 138

SJF_NONPREMEPTIVE:

AIM: To schedule process in order of shortest burst time.

ALGORITHM:
STEP 1: Start
STEP 2: Check the ready queue, if it is empty wait one cycle and repeat step 2, else go to  step 3
STEP 3: Go through the ready queue and execute the process with the smallest burst time for the entire burst time.
STEP 4: Set the process to the completed and send it to the completed queue
STEP 5: Go to step 2

CODE:
```python
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
```
OUTPUT:
1 FCFS
2 PRIORITIRY_PREMPTIVE
3 PRIORITY_NONPREMEPTIVE
4 SJF_PREMPTIVE
5 SJF_NONPREMPTIVE
6 ROUNDROBIN
5
Pid: 1
Burst: 53
prior: 1
wait: 41

Pid: 2
Burst: 17
prior: 0
wait: 0

Pid: 3
Burst: 68
prior: 3
wait: 94

Pid: 4
Burst: 24
prior: 4
wait: 17

SJF_PREMEPTIVE:

AIM: To schedule process in order of shortest burst time.

ALGORITHM:
STEP 1: Start
STEP 2: Check the ready queue, if it is empty wait one cycle and repeat step 2, else go to  step 3
STEP 3: Go through the ready queue and execute the process with the smallest burst time for 1 cycle.
STEP 4: If process burst time is 0 set the process to the completed and send it to the completed queue
STEP 5: Go to step 2

CODE:
```python
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
```
OUTPUT:
1 FCFS
2 PRIORITIRY_PREMPTIVE
3 PRIORITY_NONPREMEPTIVE
4 SJF_PREMPTIVE
5 SJF_NONPREMPTIVE
6 ROUNDROBIN
4
Pid: 1
Burst: 53
prior: 1
wait: 41

Pid: 2
Burst: 17
prior: 0
wait: 0

Pid: 3
Burst: 68
prior: 3
wait: 94

Pid: 4
Burst: 24
prior: 4
wait: 17

PRIORITY_NONPREMEPTIVE:

AIM: To schedule process in order of highest priority.

ALGORITHM:
STEP 1: Start
STEP 2: Check the ready queue, if it is empty wait one cycle and repeat step 2, else go to  step 3
STEP 3: Go through the ready queue and execute the process with the highest priority time for the entire burst time.
STEP 4: Set the process to the completed and send it to the completed queue
STEP 5: Go to step 2

CODE:
```python
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
```
OUTPUT:
1 FCFS
2 PRIORITIRY_PREMPTIVE
3 PRIORITY_NONPREMEPTIVE
4 SJF_PREMPTIVE
5 SJF_NONPREMPTIVE
6 ROUNDROBIN
3
Pid: 1
Burst: 53
prior: 1
wait: 17

Pid: 2
Burst: 17
prior: 0
wait: 0

Pid: 3
Burst: 68
prior: 3
wait: 70

Pid: 4
Burst: 24
prior: 4
wait: 138

PRIORITY_PREMPTIVE:

AIM: To schedule process in order of highest priority.

ALGORITHM:
STEP 1: Start
STEP 2: Check the ready queue, if it is empty wait one cycle and repeat step 2, else go to  step 3
STEP 3: Go through the ready queue and execute the process with the highest priority time for 1 cycle.
STEP 4: If process burst time is 0 set the process to the completed and send it to the completed queue
STEP 5: Go to step 2

CODE:
```python
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
```
OUTPUT:
1 FCFS
2 PRIORITIRY_PREMPTIVE
3 PRIORITY_NONPREMEPTIVE
4 SJF_PREMPTIVE
5 SJF_NONPREMPTIVE
6 ROUNDROBIN
2
Pid: 1
Burst: 53
prior: 1
wait: 17

Pid: 2
Burst: 17
prior: 0
wait: 0

Pid: 3
Burst: 68
prior: 3
wait: 70

Pid: 4
Burst: 24
prior: 4
wait: 138

ROUNDROBIN:

ALGORITHM:
STEP 1: Start
STEP 2: Check the ready queue, if it is empty wait one cyle and repeat step 2, else go to step 3
STEP 3: Go through each process in the ready queue and execute it for the time quanta allotted cycles
STEP 4: Check if there are any completed processes queue, if there are remove them and add them to the completed process list.
STEP 5: Go to step 2

```python
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

```
OUTPUT:
1 FCFS
2 PRIORITIRY_PREMPTIVE
3 PRIORITY_NONPREMEPTIVE
4 SJF_PREMPTIVE
5 SJF_NONPREMPTIVE
6 ROUNDROBIN
6
Pid: 1
Burst: 53
prior: 1
wait: 81

Pid: 2
Burst: 17
prior: 0
wait: 20

Pid: 3
Burst: 68
prior: 3
wait: 94

Pid: 4
Burst: 24
prior: 4
wait: 97
