

class Encoder:
    def __init__(self, key, val=8):
        self.siz = val
        self.key = key

    def encode(self, tupIn):
        siz = self.siz
        if len(tupIn) != 4:
            tupIn += ' '*(4-len(tupIn))
        tupIn = tuple(ord(i) for i in tupIn[:])

        return tupIn[0] << (3*siz) \
            | tupIn[1] << (2*siz) | tupIn[2] << (1*siz) | tupIn[3]

    def encrypt(self, base):
        exp = int(self.key)
        if (base == 0):
            return 0
        t = 1
        while (exp > 0):  # Simplifying multiplication by squaring itself
            if ((exp & 1) != 0):
                t = t * base
            base = base * base
            exp >>= 1
        return t

    def decrypt(self, base):
        return int(base**(1/self.key))

    # def decrypt(self, base):
    #     ex = self.key
    #     while ex:
    #         if (ex & 1):
    #             base **= 1.
    #         base **= 0.5
    #         ex >>= 1
    #     return int(base)

    def decode(self, n):
        siz = self.siz
        mas = 2**siz-1
        tmp = map(lambda x: chr(int(x)), ((n >> (3*siz)) & mas,
                                          (n >> (2*siz)) & mas,
                                          (n >> (1*siz)) & mas,
                                          (n >> (0*siz)) & mas))
        return "".join(tmp)


def brk(strin, siz):
    lisBrok = []
    for i in range(0, len(strin)):
        if i % 4 == 0:
            lisBrok.append([])
        lisBrok[-1].append(strin[i])
    return list(map("".join, lisBrok))


def main():
    lis = brk(input(), 4)
    Worker = Encoder(8)
    ren = [Worker.encrypt(Worker.encode(i)) for i in lis]
    print(*ren, sep='\n')
    print("".join([Worker.decode(Worker.decrypt(i)) for i in ren]))
    quit()


if __name__ == "__main__":
    main()

