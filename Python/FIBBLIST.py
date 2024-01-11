def fiborec(n,a=None):
    if n==1 or n==0:
        return 0
    if n==2:
        return 1
    else:
        try:a.add(fiborec(n-1,a)+fiborec(n-2,a))
        except:pass
        return fiborec(n-1)+fiborec(n-2)

def quick(arr,low=0,high=None):
    if high==None:
        high=len(arr)-1;

    if low>=high: 
        return 0;

    r=part(arr,low,high);
    quick(arr,low,r-1);
    quick(arr,r+1,high);

def part(arr,low,high):
    p=high;
    piv=arr[p];
    ritmo=low-1;
    for i in range(low,high):
        if arr[i]<=piv:
            ritmo+=1;
            arr[ritmo],arr[i]=arr[i],arr[ritmo];
    ritmo+=1;
    arr[ritmo],arr[p]=arr[p],arr[ritmo];
    return ritmo;
from os import urandom as ran
arr=[]
toint= lambda x: int.from_bytes(x)
for _ in range(7):
    arr.append(toint(ran(1)));
quick(arr);
print(arr);