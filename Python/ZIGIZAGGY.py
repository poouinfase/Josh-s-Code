def convert(s: str, numRows: int) -> str:
    bnc=0;
    out="";
    zig= True;
    for i in s:
        if bnc < numRows and zig: out += i; bnc +=1;
        if bnc == numRows:bnc = numRows - 2; zig = False;continue;
        if not zig:
            out += '\n'+' '*bnc + i;
            bnc += -1
            if bnc == 0: out+='\n';zig = True;
    print(out)

convert("PAYPALISHIRING",4)
