def mark(studentMark):
    ansKey = ['A', 'B', 'B', 'A', 'C']
    sc = 0
    for i in range(min(len(studentMark), len(ansKey))):
        if studentMark[i] == ansKey[i]:
            sc += 1
        elif studentMark[i] == 'X':
            pass
        else:
            sc += -0.25
    return sc


score = []
for _ in range(int(input())):
    score.append(mark(input().split(",")))

correl = {'C'+str(a+1): score[a] for a in range(len(score))}
scor = sorted(score)[::-1]

for i in scor:
    for j in correl:
        if correl[j] == i:
            print(j, i)
            correl[j] = 'emp'
