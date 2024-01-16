from numba import njit


@njit(target_backend="cuda")
def prim(n: int) -> bool:
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


n = 238050987
cpy = n-1
while (cpy):
    if (n % cpy == 0 and prim(cpy)):
        print(cpy)
        break
    cpy += -1
