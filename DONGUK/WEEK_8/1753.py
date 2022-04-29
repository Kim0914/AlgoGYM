import sys, math, heapq
from collections import deque


input = sys.stdin.readline

INF = math.inf


def search(start):
    dp[start] = 0

    pq = []
    heapq.heappush(pq, (0, start)) # [cost, node]

    while pq:
        min_node = heapq.heappop(pq) 
        cost = min_node[0]      # 해당 정점에서 연결된 노드까지의 거리
        link_node = min_node[1] # 해당 정점과 연결된 노드

        if cost > dp[link_node]: # 
            continue
    
        for data in queue[link_node]:
            neighbor = data[0]
            weigh = dp[link_node] + data[1]

            if weigh < dp[neighbor]:
                dp[neighbor] = weigh
                heapq.heappush(pq, (weigh, neighbor))

                

v, e = map(int, input().split())
start = int(input())
dp = [INF] * (v+1)

queue = [[] for _ in range(v+1)]
for _ in range(e):
    v1, v2, e = map(int, input().split())
    queue[v1].append((v2, e)) # v1과 연결된 (v2 노드, 가중치)

search(start)

for i in range(1, v+1):
    if dp[i] == INF:
        print('INF')
    
    else:
        print(dp[i])

