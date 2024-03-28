import sys, heapq, math
from collections import deque

INF = math.inf

input = sys.stdin.readline

n = int(input())
m = int(input())

graph = {i+1: [] for i in range(n)}
for _ in range(m):
    go, to, cost = map(int, input().split())
    graph[go].append((to, cost))

start, end = map(int, input().split())
dp = [INF] * (1+n)
routes = [-1] * (1+n)

q = []
visited = set()
visited.add(start)
routes[start] = start
heapq.heappush(q, (0, start))
while q:
    top = heapq.heappop(q)

    cost, now = top[0], top[1]

    if cost > dp[now]:
        continue

    for neighbor in graph[now]:
        next, distance = neighbor[0], neighbor[1]

        if cost + distance >= dp[next]:
            continue
        
        dp[next] = cost + distance
        routes[next] = now
        heapq.heappush(q, (cost + distance, next))

shortes_route = deque()
target = end
while True:
    shortes_route.appendleft(target)
    if target == start:
        break

    target = routes[target]

print(dp[end])
print(len(shortes_route))
print(*shortes_route)