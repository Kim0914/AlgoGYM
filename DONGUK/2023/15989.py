import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())

    dp = [[0] * (4) for _ in range(10001)]

    dp[1][1] = 1
    dp[2][1] = 1
    dp[2][2] = 1
    dp[3][1] = 1
    dp[3][2] = 1
    dp[3][3] = 1

    for num in range(4, n+1):
        dp[num][1] = dp[num-1][1]
        dp[num][2] = dp[num-2][1] + dp[num-2][2]
        dp[num][3] = dp[num-3][1] + dp[num-3][2] + dp[num-3][3]

    print(dp[n][1] + dp[n][2] + dp[n][3])

    