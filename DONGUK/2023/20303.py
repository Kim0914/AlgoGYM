import sys
from collections import deque

input = sys.stdin.readline

N, M, K = map(int, input().split())

candies = list(map(int, input().split()))

friend_dict = {}
for i in range(1, N+1):
    friend_dict[i] = []

for _ in range(M):
    a, b = map(int, input().split())
    friend_dict[a].append(b)
    friend_dict[b].append(a)

lands = []
visited = [0] * (N+1)
for i in range(1, N+1):
    if visited[i] == 1:
        continue
    q = deque()
    land = []
    q.append(i)
    visited[i] = 1
    cnt = 0
    while q:
        top = q.popleft()
        land.append(top)

        cnt += candies[top-1]
        neighbors = friend_dict[top]
        for neighbor in neighbors:
            if visited[neighbor] == 0:
                visited[neighbor] = 1
                q.append(neighbor)

    lands.append((len(land), cnt))


dp = [[0] * K for _ in range(len(lands) + 1)]
for i in range(1, len(lands) + 1):
    cur_weight = lands[i-1][0]
    cur_val = lands[i-1][1]
    for j in range(1, K):
        if j - cur_weight >= 0:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-cur_weight] + cur_val)
        else:
            dp[i][j] = dp[i-1][j]
print(dp[-1][-1])