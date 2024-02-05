import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))

dp = [0] * N
dp[0] = nums[0]
for i in range(1, N):
    dp[i] = nums[i] + dp[i-1]

for _ in range(M):
    start, end = map(int, input().split())

    print(dp[end-1] - dp[start-1] + nums[start-1])