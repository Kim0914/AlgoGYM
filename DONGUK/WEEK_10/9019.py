import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

def D(num):
    if (num * 2) > 9999:
        return (num * 2) % 10000

    else:
        return num * 2

def S(num):
    if num == 0:
        return 9999

    else:
        return num - 1

def L(num):

    next_num = 10 * (num % 1000) + num //1000
        
    return next_num


def R(num):

    next_num = 1000 * (num % 10) + num // 10

    return next_num
        


def search(a, b):

    dp = [0] * (10001)

    q = deque()
    q.append(a)
    dp[a] = ''

    while q:
        num = q.popleft()

        if num == b:
            break
        
        d, s, l, r = D(num), S(num), L(num), R(num)

        if 0 <= d <= 10000 and dp[d] == 0:
            dp[d] = dp[num] + 'D'
            q.append(d)

        if 0 <= s <= 10000 and dp[s] == 0:
            dp[s] = dp[num] + 'S'
            q.append(s)

        if 0 <= l <= 10000 and dp[l] == 0:
            dp[l] = dp[num] + 'L'
            q.append(l)

        if 0 <= r <= 10000 and dp[r] == 0:
            dp[r] = dp[num] + 'R'
            q.append(r)


    print(dp[b])

        
for _ in range(T):
    a, b = map(int, input().split())

    search(a, b)
