f = open("Weight.txt",'r');
weights = eval(f.readline());
f.close()

import random;

def normalize(dis):
    su = 0;
    for i in dis:
        su += dis[i];
    if not su: return None;
    for i in dis:
        dis[i] = dis[i] / su

def weigrand(dis):
    l = random.random()
    su = 0;
    for i in dis:
        l += -1 * dis[i];
        su += dis[i]
        if l <= 0: return i;
    if su == 0: return None;
    return 'z'

for i in weights:
    normalize(weights[i]);

seed = input("Seed? ") or random.choice('ABCDEFGHIJKLMNOPQRSTUVWXYZ');
leng = input("Length? ") or round(random.random() * 17);
out = seed;
for _ in range(int(leng)):
    di = weights[out[-1]];
    chis = weigrand(di);
    if not chis: break;
    out += chis;

print(out);
