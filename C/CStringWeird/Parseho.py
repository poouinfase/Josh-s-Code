"""
Seco
1330401100
LOLOI
"""
progName = input()
binInInt = int(input());
actChars = input();
print(progName,binInInt,actChars,sep="\n");
print(binOfChars := bin(binInInt)[2:]);

def alignbits(strin):
    if len(strin) % 2 != 0:
        strin = '0' +strin;
    return strin

alignbits(binOfChars)
while binOfChars:
    print(f"{actChars[-1]} {alignbits(bin(ord(actChars[-1]))[2::])}: ",binOfChars[:7:])
    binOfChars=binOfChars[8::]
    actChars=actChars[:-1:]

