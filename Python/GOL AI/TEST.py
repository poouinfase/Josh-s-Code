""" from GAMEFIELD import*

a=field(5,5)

a.randfillfield()
brep=[]
s=0
while(s not in brep):
    brep.append(s)
    a.randfillfield()
    a.printfield()
    s=a.hashthefield()
    print(s)

a.randfillfield()
s=a.hashthefield()
print(s)
a.printfield()
a.printer.printfieldtoCommandLine(a.fieldthehash(s)) """
s=""
for i in range(16):
    s=s+str(i)
    a=set(s)
    for i in a:
        print(i,end=" ")
    print("")
s=""
print("Second attmept")
for i in range(5):
    s=s+str(4-i)
    a=set(s)
    for i in a:
        print(i,end=" ")
    print("")

