import sys
input = sys.stdin.readline

n = int(input())

# 1. 증가 
# 2. 감소
# 3. 증가 -> 감소 
dp = [[0] * n for _ in range(3)]


nums = list(map(int, input().split()))

# 증가
for i in range(n):
    dp[0][i] = 1
    for j in range(i):
        if nums[j] < nums[i]:
            dp[0][i] = max(dp[0][i], dp[0][j] + 1)

# 감소
for i in range(n-1, -1, -1):
    dp[1][i] = 1
    for j in range(n-1, i, -1):
        if nums[j] < nums[i]:
            dp[1][i] = max(dp[1][i], dp[1][j] + 1)



for i in range(n):
    dp[2][i] = dp[0][i] + dp[1][i] - 1

ans = []              
for d in dp:
    ans.append(max(d))

print(max(ans))