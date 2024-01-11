import re;
f=open("B.txt",'r');
dic={"one":"o1e","two":"t2o","three":"t3e","four":"f4r","five":"f5e","six":"s6x","seven":"s7n","eight":"e8t","nine":"n9e","zero":"z0o"}
all="".join(f.readlines());
f.close()
for _ in range(10):
    for i in dic:
        all=re.sub(i,dic[i],all)
f=open("C.txt",'w');
f.seek(0);
f.write(all);
f.close();
