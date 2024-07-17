n = int(1)

for _ in range(14):
    print(int(n),end=" ")
    n+=n%2
    n*=1.5
    n+=1
    n%=27
    # while n in h: n+=1

