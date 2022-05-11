import sys
from collections import deque
input = sys.stdin.readline

N = int(input())

tree = [[] * (1+N) for _ in range(1+N)]
res = [0] * (1+N)
visited = [0] * (1+N)

def init():
    for _ in range(N-1):
        a, b = map(int, input().split())
        tree[a].append(b)
        tree[b].append(a)


def search(start):
    q = deque()
    q.append(start)

    while q:
        now = q.popleft()
        visited[now] = 1

        for v in tree[now]:
            if visited[v] == 0:
                res[v] = now
                q.append(v)
        

init()
search(1)

for i in range(2, N+1):
    print(res[i])





