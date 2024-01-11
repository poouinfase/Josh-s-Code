f=open("input/Day1Input.txt","r")
l=[0]
for i in f.readlines():
    if i=='\n':l.append(0);continue;
    l[-1]+=int(i[:-1:])
l=sorted(l)[::-1]
print(l[0]+l[1]+l[2])
