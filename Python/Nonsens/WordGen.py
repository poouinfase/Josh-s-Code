import random

f = open("Weight.txt", 'r')
weights = eval(f.readline())
f.close()


def normalize(dis):
    su = 0
    for i in dis:
        su += dis[i]
    if not su:
        return None
    for i in dis:
        dis[i] = dis[i] / su


def weigrand(dis):
    rand_Threshold = random.random()
    su = 0
    for i in dis:
        rand_Threshold += -1 * dis[i]
        su += dis[i]
        if rand_Threshold <= 0:
            return i
    if su == 0:
        return None
    return 'z'


def main(seed="A", leng=3):
    out = seed
    for _ in range(int(leng)):
        di = weights[out[-1]]
        chis = weigrand(di)
        if not chis:
            break
        out += chis
    print(out)


if __name__ == "__main__":
    for i in weights:
        normalize(weights[i])
    seed = input("Seed? ") or random.choice('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    leng = input("Length? ") or round(random.random() * 17)
    while input() != "q":
        main(seed, leng)
