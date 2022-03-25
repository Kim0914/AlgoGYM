import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

dp = [0] * n
dp[0] = nums[0]

for i in range(1, n):
    dp[i] = max(dp[i-1]+nums[i], nums[i])

print(max(dp))

'''
10
10 -4 3 1 5 6 -35 12 21 -1
'''