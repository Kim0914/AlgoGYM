import sys
input = sys.stdin.readline

n, k = map(int, input().split())
dp = [0] * (k + 1)

nums = []
for _ in range(n):
    nums.append(int(input()))


for i in range(n):
    num = nums[i]
    for j in range(num, k+1):
        if i == 0:
            if j % num == 0:
                dp[j] += 1
        
        else:
            if j == num:
                dp[j] += 1
            
            else:
                dp[j] += dp[j-num]
            
print(dp[k])



