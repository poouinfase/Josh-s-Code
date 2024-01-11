import re
f=open(input(),"r")
su=0
for LINE in f.readlines():
    su+=int(re.search("\d",LINE).group(0))*10;
    su+=int(re.search("\d",LINE[::-1]).group(0));

print(su)
f.close()
