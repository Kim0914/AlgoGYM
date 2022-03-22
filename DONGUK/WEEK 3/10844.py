import sys
input = sys.stdin.readline

N = int(input())

num = 1 * (10 ** (N - 1))
dp = [[0] * 10 for _ in range(N+1)]

# 한 자리 숫자 계산
for i in range(1, 10):
    dp[1][i] = 1

for i in range(2, N+1):
    for j in range(10):
        if j == 0:
            dp[i][j] = dp[i-1][j+1]
        
        elif j == 9:
            dp[i][j] = dp[i-1][j-1]

        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

print(sum(dp[N]) % 1000000000)


'''
10, 12 | 101, 121, 123
21, 23 | 210, 212, 232, 234
32, 34 | 321, 323, 343, 345
43, 45 | 432, 434, 454, 456
54, 56 
65, 67
76, 78
87, 89
98

즉 마지막 자리수가 0이면 1만 가능
1 ~ 8 이면 해당 숫자 += 1 숫자 가능
9이면 8만 가능
'''