import matplotlib.pyplot as plt
f = open('Timings.txt', 'r')
algo1 = {'x': [], 'y': []}
algo2 = {'x': [], 'y': []}
parseDict = {'1': algo1, '2': algo2}
stin = f.readlines()
f.close()
for i in stin:
    if i == '\n':
        continue
    listLook = i.split()
    pi = parseDict[listLook[0]]
    pi['x'].append(int(listLook[1]))
    pi['y'].append(float(listLook[2]))
plt.plot(algo1['x'], algo1['y'])
plt.plot(algo2['x'], algo2['y'])
print(algo1['x'], algo1['y'])
plt.show()
plt.savefig('Comp.png')

