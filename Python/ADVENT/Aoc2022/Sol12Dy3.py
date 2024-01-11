def twosacks(s:str):
    bicki=len(s)//2;
    return (s[:bicki:],s[bicki::])

f=open("input/Day3.txt",'r');
sum=0;

val={chr(x):x-ord('a')+1 for x in range(ord('a'),ord('z')+1)}
val.update({chr(x):27+x-ord('A') for x in range(ord('A'),ord("Z")+1)})

for LINE in f.readlines():
    top,bot=twosacks(LINE);
    bot=set(bot)
    out=None;
    for i in top:
        if i in bot:out=i;break;
    sum+=val[out]; 
print(sum);

f.seek(0)
l=f.readlines()
sum=0;
print(l[:3:])
while l:
    a,b,c=sorted([l.pop(),l.pop(),l.pop()],key= lambda a:len(a))
    print(a,b,c);
    b=set(b);
    c=set(c);
    for i in a:
        if i in b and i in c:sum+=val[i];break;
print(sum);
