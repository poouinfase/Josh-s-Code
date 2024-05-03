
def make_pi(n=1000):
    q, r, t, k, m, x = 1, 0, 1, 1, 3, 3
    for j in range(n):
        if 4 * q + r - t < m * t:
            print(m)
            yield abs(m)
            q, r, t, k, m, x = 10*q, 10*(r-m*t), t, k, (10*(3*q+r))//t - 10*m, x
        else:
            q, r, t, k, m, x = q*k, (2*q+r)*x, t*x, k+1, (q*(7*k+2)+r*x)//(t*x), x+2

def genpi(n):
    arr=[str(i) for i in make_pi(n)]
    print(arr);
    st=arr[0]+"."+"".join(arr[1::])
    return st

print(genpi(10**3))

