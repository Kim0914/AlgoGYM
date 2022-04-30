import sys
from collections import deque

N, K = map(int, input().split())
dp = [0] * (100001)
visited = [0] * (100001)

def search(v):
    queue = deque()
    queue.append(v)

    while queue:
        v = queue.popleft()

        if v == K:
            return
        
        visited[v] = 1

        next_v = v * 2
        if 0 <= next_v <= 100000 and visited[next_v] == 0:
            visited[next_v] = 1
            dp[next_v] = dp[v]
            queue.append(next_v)

        next_v = v - 1
        if 0 <= next_v <= 100000 and visited[next_v] == 0:
            visited[next_v] = 1
            dp[next_v] = dp[v] + 1
            queue.append(next_v)
        
        next_v = v + 1
        if 0 <= next_v <= 100000 and visited[next_v] == 0:
            visited[next_v] = 1
            dp[next_v] = dp[v] + 1
            queue.append(next_v)


search(N)
print(dp[K])