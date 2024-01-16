from random import random


def bubsort(lisIn):
    s = True
    while s:
        s = False
        for i in range(len(lisIn)-1):
            if lisIn[i] > lisIn[i+1]:
                s = True
                lisIn[i], lisIn[i+1] = lisIn[i+1], lisIn[i]


l = [int(random()*10) for _ in range(10)]
print(l)
bubsort(l)
print(l)
