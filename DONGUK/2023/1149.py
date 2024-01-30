import math, sys

input = sys.stdin.readline
n = int(input())

houses = []
for _ in range(n):
    lis = list(map(int, input().split()))
    houses.append(lis)

INF = math.inf
dp = [[INF] * 3 for _ in range(n)]

for i in range(n):
    for j in range(3):
        if i == 0:
            dp[i][j] = houses[i][j]
        else:
            if j == 0:
                dp[i][j] = houses[i][j] + min(dp[i-1][1], dp[i-1][2])
            elif j == 1:
                dp[i][j] = houses[i][j] + min(dp[i-1][0], dp[i-1][2])
            else:
                dp[i][j] = houses[i][j] + min(dp[i-1][0], dp[i-1][1])

print(min(dp[-1]))