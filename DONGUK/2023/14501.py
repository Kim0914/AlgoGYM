import sys

input = sys.stdin.readline

N = int(input())

times = []
pays = []
for _ in range(N):
    t, p = map(int, input().split())
    times.append(t)
    pays.append(p)

dp = [0 for i in range(N+1)]
for i in range(N):
    for j in range(i + times[i], N+1):
        if dp[j] < dp[i] + pays[i]:
            dp[j] = dp[i] + pays[i]
print(dp[-1])