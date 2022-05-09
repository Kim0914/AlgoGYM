import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split()) # 수빈이, 동생
visited = [0] * (100001)
dp = [0] * (100001)
prior = [0] * (100001)

def path(K):
    ans = deque()
    ans.appendleft(K)
    target = prior[K]

    if target == N:
        ans.appendleft(N)
        print(*ans)
        return

    while target != N:
        ans.appendleft(target)
        target = prior[target]

        if target == N:
            ans.appendleft(target)

    print(*ans)


def search(N):
    q = deque()
    q.append(N)
    

    while q:
        v = q.popleft()
        visited[v] = 1

        if v == K:
            break

        nv = 2 * v
        if 0 <= nv <= 100000 and visited[nv] == 0:
            visited[nv] = 1
            q.append(nv)
            dp[nv] = dp[v] + 1
            prior[nv] = v

        nv = v - 1
        if 0 <= nv <= 100000 and visited[nv] == 0:
            visited[nv] = 1
            q.append(nv)
            dp[nv] = dp[v] + 1
            prior[nv] = v
        
        nv = v + 1
        if 0 <= nv <= 100000 and visited[nv] == 0:
            visited[nv] = 1
            q.append(nv)
            dp[nv] = dp[v] + 1
            prior[nv] = v

    print(dp[K])


if N >= K:
    print(N-K)

    for i in range(N, K-1, -1):
        print(i, end = ' ')

else:
    search(N)
    path(K)
