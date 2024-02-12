import sys

input = sys.stdin.readline

N, K = map(int, input().split())

products = []
for i in range(N):
    W, V = map(int, input().split())

    products.append((W, V))

dp = [[0] * (K + 1) for _ in range(N+1)]
for i in range(1, N+1):
    weight = products[i-1][0]
    value = products[i-1][1]

    for bag in range(1, K+1):
        if bag >= weight:
            dp[i][bag] = max(dp[i-1][bag], dp[i-1][bag-weight] + value)
        else:
            dp[i][bag] = dp[i-1][bag]

print(dp[-1][-1])