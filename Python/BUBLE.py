def bubsort(l):
    s=True
    while s:
        s=False
        for i in range(len(l)-1):
            if l[i]>l[i+1]:
                s=True
                l[i],l[i+1]=l[i+1],l[i]
from random import random
l=[int(random()*10) for _ in range(10)]
print(l)
bubsort(l)
print(l)
