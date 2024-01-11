from time import perf_counter as time
def srand(seed:int):
    return seed>>1|((1 & ((seed >> 0) ^ (seed >> 1) ^ (seed >> 3) ^ (seed >> 12)))<<15);

def galois(lfsr:int):
    lsb = lfsr & 1; # /* Get LSB (i.e., the output bit). */
    lfsr >>= 1;      #          /* Shift register */
    lfsr ^= -lsb & 0xB400; #      /*  apply toggle mask. */
    return lfsr

def timeTester(f):
    ti=time();
    for i in range(100000):
        f(i);
    return time()-ti

def averageTime(f,n=10):
    summ=0
    for _ in range(n):
        summ+=timeTester(f)
    return summ/n

def periodFinder():
    st=1;
    tmp=galois(st);
    p=0;
    summ=0;
    while(st!=tmp):
        p+=1;summ+=tmp;
        tmp=galois(tmp);
    return p,summ;

def analyse(f):
    rmax=6500000;
    st=1;
    tmp=f(st);
    p=0;
    sm=0;
    max=tmp;
    min=tmp;
    while(p<rmax and tmp!=st):
        p+=1;
        sm+=tmp;
        if max<tmp: max=tmp;
        if min>tmp: min=tmp;
        tmp=f(tmp);
    average=sm/p;
    return p,sm,average,max,min;
        


print(analyse(srand),analyse(galois),sep="\n")
