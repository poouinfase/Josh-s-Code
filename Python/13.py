# Q1
import re
str = input()
reg = r"ab*"
print(re.findall(reg, str))
# Q2
strin = input()
reg = r"ab+"
print(re.findall(reg, strin))
# Q3
strin = input()
reg = r"ab{0,1}"
print(re.findall(reg, strin))
# Q4
strin = input()
reg = r"abbb"
print(re.findall(reg, strin))
# Q5
strin = input()
reg = r"ab{2,3}"
print(re.findall(reg, strin))
# 6
strin = input()
reg = r"[a-z]+_[a-z]+"
print(re.findall(reg, strin))
# 7
strin = input()
reg = r"[A-Z][a-z]+"
print(re.findall(reg, strin))
# 8
strin = input()
reg = r"a[^b]*b"
print(re.match(reg, strin))
# 9
strin = input()
reg = r"[a-zA-Z]*z[a-zA-Z]*"
print(re.match(reg, strin))
# 10
strin = input()
reg = r"[a-zA-Z]+z[a-zA-Z]+"
print(re.match(reg, strin))
# 11
strin = input()
reg = "[A-Za-z0-9_]{%d}" % (len(strin))
print(re.match(reg, strin))
# 12
strin = input()
n = input("Number to be checked: ")
reg = "^"+n+".*"
print(re.match(reg, strin))
# 13
strin = input()
n = input("Number to be checked: ")
reg = ".*"+n+"$"
print(re.match(reg, strin))
# 14
strin = list(input())
for i in range(len(strin)):
    if strin[i] == " ":
        strin[i] = "_"
        continue
    if strin[i] == "_":
        strin[i] = " "
strin = "".join(strin)
print(strin)
# 15
strin = input()
reg = r"\b[ae][^ ]*"
print(re.findall(reg, strin))
# 16
strin = input()
reg = r"[ .,]"
print(re.sub(reg, ":", strin))
# 17
strin = input()
reg = r"[\s.,]{1,2}"
print(re.sub(reg, ":", strin))
# 18
strin = input()
if strin[-1] != " ":
    strin = strin+' '
strin = re.sub(" ", "  ", strin)
reg = r" \w{5} "
print(re.findall(reg, strin))
# 19
strin = input()
if strin[-1] != " ":
    strin = strin+' '
strin = re.sub(" ", "  ", strin)
reg = r" \w{3,5} "
print(re.findall(reg, strin))
# 20
strin = input()
if strin[-1] != " ":
    strin = strin+' '
strin = re.sub(" ", "  ", strin)
reg = r" \w{4,} "
print(re.findall(reg, strin))

