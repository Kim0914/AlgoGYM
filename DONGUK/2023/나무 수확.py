import sys

input = sys.stdin.readline

n = int(input())

graph = [[] for _ in range(n)]
for i in range(n):
    row = list(map(int, input().split()))
    graph[i] = row

dp = [[0] * n for _ in range(n)]
nums = [[0] * n for _ in range(n)]

dp[0][0] = graph[0][0]
nums[0][0] = graph[0][0]

for i in range(n):
    for j in range(n):
        if i == 0 and j == 0:
            continue
        if i == 0 and j != 0:
            dp[i][j] = graph[i][j] + dp[i][j-1]
            nums[i][j] = max(graph[i][j], nums[i][j-1])
        elif i != 0 and j == 0:
            dp[i][j] = graph[i][j] + dp[i-1][j]
            nums[i][j] = max(graph[i][j], nums[i-1][j])
        else:
            if i == n-1 and j == n-1:
                dp[i][j] = graph[i][j] + max(dp[i-1][j] + nums[i-1][j], dp[i][j-1] + nums[i][j-1])
                continue
            if dp[i-1][j] > dp[i][j-1]:
                dp[i][j] = graph[i][j] + dp[i-1][j]
                nums[i][j] = max(graph[i][j], nums[i-1][j])
            elif dp[i-1][j] < dp[i][j-1]:
                dp[i][j] = graph[i][j] + dp[i][j-1]
                nums[i][j] = max(graph[i][j], nums[i][j-1])
            else:
                dp[i][j] = graph[i][j] + dp[i][j-1]
                nums[i][j] = max(graph[i][j], nums[i][j-1], nums[i-1][j])

print(dp[-1][-1])