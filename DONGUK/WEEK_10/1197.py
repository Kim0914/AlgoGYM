import sys, heapq

input = sys.stdin.readline

v, e = map(int, input().split())
weight = 0


def search(vertex):
    global weight

    q = []
    heapq.heappush(q, (0, vertex))

    cnt = 0
    while q:
        top = heapq.heappop(q)
        now, dist = top[1], top[0]

        if visited[now] == 1:
            continue

        visited[now] = 1
        weight += dist
        cnt += 1
        
        if cnt == v:
            print(weight)
            return 

        for data in graph[now]:
            neighbor, cost = data[1], data[0]
            if visited[neighbor] == 0:
                heapq.heappush(q, (cost, neighbor))


graph = [[] * (1+v) for _ in range(1+v)]
visited = [0] * (1+v)

for _ in range(e):
    a, b, w = map(int, input().split())

    heapq.heappush(graph[a], (w, b))
    heapq.heappush(graph[b], (w, a))

search(1)