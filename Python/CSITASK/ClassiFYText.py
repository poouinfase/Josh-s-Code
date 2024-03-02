import gzip as zlib

def CompLen(st:str):
    return len(zlib.compress(st.encode()))

def NormalizeCompressDistance(stX:str,stY:str):
    LeXY:int=CompLen(stX+stY)
    LenX:int=CompLen(stX)
    LenY:int=CompLen(stY)
    NCD:float = (LeXY-min(LenX,LenY))/max(LenX,LenY)
    return NCD

def main():
    BASE = "food poisoning chicken Tarama 17th february"
    Test =[BASE,"We are here about your car's extended warranty", "Yeah, I got food poisoning on the 17th of february. I had the chicken tikka at Tarama", "The hot singles have breached containment in your area, evacuate immediately","I know where you live"]
    coun =1;
    for i in Test:
        print(coun,NormalizeCompressDistance(BASE.lower(),i.lower()),i)
        coun+=1



if __name__ == "__main__":
    main()
