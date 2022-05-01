import sys, math, heapq
input = sys.stdin.readline

INF = 2000000000

def search(start):
    pq = []
    heapq.heappush(pq, (0, start))

    while pq:
        top = heapq.heappop(pq)
        dist = top[0]
        now = top[1]
        dp[now][now] = 0

        if dist > dp[start][now]:
            continue

        for data in graph[now]:
            neighbor = data[0]
            cost = data[1] + dist

            if cost < dp[start][neighbor]:
                dp[start][neighbor] = cost
                heapq.heappush(pq, (cost, neighbor))



T = int(input())

for _ in range(T):
    n, m, t = map(int, input().split()) # 교차로, 도로, 목적지 후보의 개수
    s, g, h = map(int, input().split()) # 출발지, 지나간 도로의 양 끝 교차로

    graph = [[] * (n+1) for _ in range(n+1)]
    dp = [[INF] * (n+1) for _ in range(n+1)]
    for _ in range(m):
        a, b, d = map(int, input().split())
        graph[a].append((b, d)) # 교차로, 비용 순서
        graph[b].append((a, d)) 
    
    dest = []
    for _ in range(t):
        dest.append(int(input()))

    dest.sort()

    search(s)
    search(g)
    search(h)

    ans = []
    for target in dest:
        res1 = dp[s][g] + dp[g][h] + dp[h][target]
        res2 = dp[s][h] + dp[h][g] + dp[g][target]

        if dp[s][target] == res1 or dp[s][target] == res2:
            ans.append(target)
           
    print(*ans)
