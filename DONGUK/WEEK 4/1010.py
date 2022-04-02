T = int(input())

def calc(n, k):
    mul = 1
    for _ in range(k):
        mul = mul * n
        n = n - 1

    div = 1
    while k > 0:
        div = div * k
        k = k - 1

    return mul // div


for _ in range(T):
    n, m = map(int, input().split())
    print(calc(m, n))

