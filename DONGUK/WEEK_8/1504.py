import sys, heapq, math
input = sys.stdin.readline
INF = math.inf

def search(start):
    pq = []
    heapq.heappush(pq, (0, start))

    while pq:
        top = heapq.heappop(pq)
        now = top[1]   # 현재 방문중인 노드
        dist = top[0]   # start에서 현재 노드까지의 거리
        dp[now][now] = 0

        if dist > dp[start][now]:
            continue

        for vertex in queue[now]: # 현재 노드와 연결된 노드들 탐색
            neighbor = vertex[0]
            cost = dist + vertex[1]

            if cost < dp[start][neighbor]:
                dp[start][neighbor] = cost
                heapq.heappush(pq, (cost, neighbor))
            
            
N, E = map(int, input().split())

queue = [[] for _ in range(N+1)]
dp = [[INF] * (N+1) for _ in range(N+1)]

for _ in range(E):
    a, b, c  = map(int, input().split())
    queue[a].append((b, c)) # 노드, 거리
    queue[b].append((a, c))

v1, v2 = map(int, input().split())

search(1)
search(v1)
search(v2)

if dp[1][v1] == INF or dp[v1][v2] == INF or dp[v2][N] == INF:
    print(-1)

else:
    print(min(dp[1][v1] + dp[v1][v2] + dp[v2][N], dp[1][v2] + dp[v2][v1] + dp[v1][N]))
