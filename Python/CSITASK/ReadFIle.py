def pars(st:str):
    out =0;
    for i in st:
        out<<=1
        if(i=='\t'):out+=1;
    return out


def main():
    f = open("encrypted.txt","r")
    st = f.read()
    f.close()
    parseThis= [st[i:i+8] for i in range(0, len(st), 8)]
    out=""
    for i in parseThis:
        out+=chr(pars(i))
    print (out)


if __name__ == "__main__":
    main()
