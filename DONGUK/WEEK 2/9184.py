d = {}

def dp(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    if (a, b, c) in d:
        return d[(a, b, c)]

    
    if a > 20 or b > 20 or c > 20:
        return dp(20, 20, 20)


    if a < b and b < c:
        d[(a, b, c)] = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c)
        return d[(a, b, c)]
    
    else:
        d[(a, b, c)] = dp(a-1, b, c) + dp(a-1, b-1, c) + dp(a-1, b, c-1) - dp(a-1, b-1, c-1)
        return d[(a, b, c)]


while True:
    a, b, c = map(int, input().split())

    if a == -1 and b == -1 and c == -1:
        break

    ans = dp(a,b,c)
    print('w({}, {}, {}) = {}'.format(a, b, c, ans))
