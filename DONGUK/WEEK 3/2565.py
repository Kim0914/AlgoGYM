import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * n

data = []
for _ in range(n):
    a, b = map(int, input().split())
    data.append((a,b))


data.sort(key = lambda x: x[0])

for i in range(n):
    dp[i] = 1
    for j in range(i):
        if data[j][1] < data[i][1]:
            dp[i] = max(dp[i], dp[j]+1)

print(n - max(dp))