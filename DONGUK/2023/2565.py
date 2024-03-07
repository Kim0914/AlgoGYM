import sys

input = sys.stdin.readline

N = int(input())

nums = []
for _ in range(N):
    a, b = map(int, input().split())
    nums.append((a, b))
nums.sort(key=lambda x : x[0])

dp = [1] * (N)

for i in range(N):
    cur_num = nums[i][1]
    for j in range(i):
        if cur_num > nums[j][1]:
            dp[i] = max(dp[j] + 1, dp[i])

print(N - max(dp))