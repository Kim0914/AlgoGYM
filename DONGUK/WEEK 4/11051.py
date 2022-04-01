n, k = map(int, input().split())

dp = [[0] * (n+1) for _ in range(n+1)]

def calc(n, k):
    mul = 1
    for _ in range(k):
        mul = mul * n
        n = n - 1

    div = 1
    while k > 0:
        div = div * k
        k = k - 1

    return mul // div


for i in range(1, n+1):
    for j in range(i+1):
        if j == 0 or j == i:
            dp[i][j] = 1
            continue

        if dp[i-1][j-1] != 0 and dp[i-1][j] != 0:
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007

        else:
            dp[i][j] = calc(i, j) % 10007
        
print(dp[n][k])
