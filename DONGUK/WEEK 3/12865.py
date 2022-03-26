import sys
input = sys.stdin.readline

# 물건 개수, 최대 무게
n, k = map(int, input().split())
dp = [[0] * (k+1) for _ in range(n+1)]


data = [(0,0)]
for _ in range(n):
    # 무게, 가치
    w, v = map(int, input().split())
    data.append((w,v))


for i in range(1, n+1):
     weight, val = data[i][0], data[i][1]

     for j in range(1, k+1):
        if j < weight:
             dp[i][j] = dp[i-1][j]
            
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + val)

print(dp[n][k])