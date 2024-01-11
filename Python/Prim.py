from time import perf_counter
def fac(n):
    f=1
    for i in range(1,n):
       f*=i
    return f

def primbyfac(n):
    z=(fac(n-1)+1)/n
    z%=1
    return z==0

def primbyittr(n):
    for i in range(2,round(n**0.5)+1):
        if n%i==0:
            return False
    return True

def perfocmp():
    time=perf_counter()
    for i in range(1,100):
        primbyfac(i)
    print("Fact:",perf_counter()-time)
    time=perf_counter()
    for i in range(1,100):
        primbyittr(i)
    print("Ittr:",perf_counter()-time)

perfocmp()