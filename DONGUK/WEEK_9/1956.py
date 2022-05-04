import sys, math
input = sys.stdin.readline
INF = math.inf

v, e = map(int, input().split())

graph = [[INF] * (v+1) for _ in range(v+1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a][b] = c


for k in range(1, v+1):
    for i in range(1, v+1):
        for j in range(1, v+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

ans = []
for i in range(1, v+1):
    ans.append(graph[i][i])


ans = min(ans)
if ans == INF:
    print(-1)
else:
    print(ans)
