import sys
input = sys.stdin.readline

n, m = map(int, input().split())
memory = list(map(int, input().split()))
costs = list(map(int, input().split()))

max_cost = sum(costs)
dp = [[0] * (max_cost+1) for _ in range(n+1)]

min_cost = 99999999
for i in range(1, n+1):
    for j in range(max_cost + 1):

        if costs[i-1] > j:
            dp[i][j] = dp[i-1][j]
        
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-costs[i-1]] + memory[i-1])

        
        if dp[i][j] >= m:
            min_cost = min(min_cost, j)

print(min_cost)