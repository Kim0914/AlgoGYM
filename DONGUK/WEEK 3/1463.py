import sys
input = sys.stdin.readline

N = int(input())
dp = [0] * 1000001
dp[1] = 0
dp[2] = 1
dp[3] = 1


for i in range(4, 1000001):
    nums = []
    nums.append(i-1)
    if i % 3 == 0:
        nums.append(i//3)
    
    if i % 2 == 0:
        nums.append(i//2)
    
    vals = []
    for num in nums:
        vals.append(dp[num])
    
    dp[i] = min(vals) + 1


print(dp[N])

'''
10 -> 5 -> 4 -> 2
'''