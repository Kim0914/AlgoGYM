import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))


dp = [[0] * (n) for _ in range(n)] 
for i in range(n):
    dp[i][i] = 1

for i in range(n-1):
    if nums[i] == nums[i+1]:
        dp[i][i+1] = 1


for i in range(2, n): 
    for j in range(n-i):
        if nums[j] == nums[i+j] and dp[j+1][j+i-1] == 1:
            dp[j][i+j] = 1

'''
i=2, j=0, 1, 2, 3, 4
i=3, j=0, 1, 2, 3
i=4, j=0, 1, 2
'''

m = int(input())
for _ in range(m):
    s, e = map(int, input().split())
    print(dp[s-1][e-1])

    