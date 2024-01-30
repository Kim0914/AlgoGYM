import math, sys

input = sys.stdin.readline

n = int(input())
houses = []
for _ in range(n):
    houses.append(list(map(int, input().split())))

INF = math.inf
answer = INF
for k in range(3):
    dp = [[INF] * 3 for _ in range(n)]
    for i in range(1, n):
        for j in range(3):
            if i == 1:
                if j == k:
                    continue
                dp[i][j] = houses[i][j] + houses[0][k]

            elif i == n-1:
                if j == k:
                    continue
                if j == 0:
                    dp[i][j] = houses[i][j] + min(dp[i-1][1], dp[i-1][2])
                elif j == 1:
                    dp[i][j] = houses[i][j] + min(dp[i-1][0], dp[i-1][2])
                else:
                    dp[i][j] = houses[i][j] + min(dp[i-1][0], dp[i-1][1])

            else:
                if j == 0:
                    dp[i][j] = houses[i][j] + min(dp[i-1][1], dp[i-1][2])
                elif j == 1:
                    dp[i][j] = houses[i][j] + min(dp[i-1][0], dp[i-1][2])
                else:
                    dp[i][j] = houses[i][j] + min(dp[i-1][0], dp[i-1][1])
    answer = min(answer, min(dp[-1]))

print(answer)