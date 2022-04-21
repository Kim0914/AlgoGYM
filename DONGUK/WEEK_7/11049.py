import sys, math
input = sys.stdin.readline

n = int(input())

mat = []
for _ in range(n):
    r, c = map(int, input().split())
    mat.append((r, c))

dp = [[0] * n for _ in range(n)]

for i in range(1, n): # 몇 번째 대각선인지
    for j in range(n-i): # 대각선에서 몇 번째 열인지

        if i == 1:
            dp[j][j+i] = mat[j][0] * mat[j][1] * mat[j+1][1]
            continue

        dp[j][j+i] = math.inf
        for k in range(j, j+i):
            dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + (mat[j][0] * mat[k][1] * mat[j+i][1]) )

print(dp[0][n-1])
    