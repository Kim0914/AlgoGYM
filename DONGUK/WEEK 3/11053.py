import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * n

nums = list(map(int, input().split()))


for i in range(n):
    dp[i] = 1
    for j in range(i):
        if nums[j] < nums[i]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))
'''
10 20 10 30 20 50
'''