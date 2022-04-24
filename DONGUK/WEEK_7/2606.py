import sys

n = int(input())
m = int(input())

graph = [[0] * (n+1) for _ in range(n+1)]
visited = [0] * (n+1)
cnt = 0

def dfs(v):
    global cnt

    if visited[v] == 1:
        return
    
    visited[v] = 1
    cnt += 1
    for i in range(1, n+1):
        if graph[v][i] == 1:
            dfs(i)


for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b], graph[b][a] = 1, 1


dfs(1)

print(cnt - 1)

