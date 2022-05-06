import sys
from collections import deque
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

ans = deque()
val = max(dp)
for i in range(n-1, -1, -1):
    if dp[i] == val:
        ans.appendleft(nums[i])
        val -= 1

print(*ans)
