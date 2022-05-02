import sys, math, heapq
input = sys.stdin.readline

INF = math.inf

n = int(input()) # 도시 개수
m = int(input())

graph = [[0] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())

    if graph[a][b] > 0:
        graph[a][b] = min(graph[a][b], c)
    
    else:
        graph[a][b] = c


for i in range(1, n+1):
    for j in range(1, n+1):
        if i == j:
            continue
        else:
            if graph[i][j] == 0:
                graph[i][j] = INF



for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])


for i in range(1, n+1):
    for j in range(1,n +1):
        if graph[i][j] == INF:
            print(0, end=' ')
        else:
            print(graph[i][j], end=' ')
    print()


# N * E log E -> 100 * 100000 * log 100000 -> 시간초과..