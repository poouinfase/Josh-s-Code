f = open("words_Sanitized.txt",'r')
words = f.readlines()
f.close()
chars = sorted(list(set("".join(words)).difference({'\n'})))

Chars_Dicts = {}
for i in chars:
    Chars_Dicts[i] = dict(zip(chars,[0]*len(chars)))

for i in words:
    for j in range(len(i)-2):
        Chars_Dicts[i[j]][i[j+1]] +=1

f = open("Weight.txt",'w')
f.write(str(Chars_Dicts))
f.close()

