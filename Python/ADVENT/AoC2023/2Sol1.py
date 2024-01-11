import re
f=open("input\Day2.txt",'r')
l=[]

for LINE in f.readlines():
    dic={"red":0,"green":0,"blue":0}
    pull=LINE[8::].split(';') 
    print(pull)
    for ins in pull:
        print(ins)
        for col in ins.lstrip(':').split(','):
            col=col.lstrip().rstrip('\n').split(' ')
            print(col)
            dic[col[1]]=int(col[0]) if int(col[0])> dic[col[1]] else dic[col[1]]
    if dic["red"]>12 or dic["green"]>13 or dic["blue"]>14: l.append(LINE)
sum=0;
for i in l:
    i=i[5::]
    i=i[:i.index(':'):]
    print(i)
    sum+=int(i);
print(sum)




