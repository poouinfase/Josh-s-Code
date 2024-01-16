def siv(val, f):
    val += 1
    lst = [True] * val
    for i in range(2, val):
        if lst[i]:
            _ = f.write("\n"+str(i))
            for j in range(i * i, val, i):
                lst[j] = False


if __name__ == '__main__':
    from time import perf_counter as p
    import os
    os.chdir(r"C:\Users\catte\OneDrive\Documents\My\FUqaround\Python")
    f = open("Seiveprim.txt", "w")
    t0 = p()
    siv(2**16, f)
    tn = p()
    _ = f.write('\n'+str(tn-t0))
    print(str(tn-t0))
    f.close()
