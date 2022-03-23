import sys
input = sys.stdin.readline

n = int(input())

dp = [0] * (n)

podo = [int(input()) for _ in range(n)]

for i in range(n):
    if i == 0:
        dp[i] = podo[i]
    
    elif i == 1:
        dp[i] = dp[i-1] + podo[i]

    elif i == 2:
        dp[i] = max((podo[0] + podo[2]), (podo[1]+podo[2]), dp[i-1])

    else:
        dp[i] = max((dp[i-2] + podo[i]), (dp[i-3] + podo[i-1] + podo[i]), dp[i-1])

print(dp[n-1])
