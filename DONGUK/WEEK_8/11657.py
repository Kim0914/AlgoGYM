import sys, math, heapq
input = sys.stdin.readline
INF = math.inf

N, M = map(int, input().split()) # 도시, 버스 노선

def search(start):
    dp[start] = 0

    for i in range(1, N+1):
        for j in range(M):
            now, next, cost = graph[j][0], graph[j][1], graph[j][2]
            if dp[now] != INF and dp[next] > dp[now] + cost:
                dp[next] = dp[now] + cost
                
                if i == N:
                    return True
    
    return False


graph = []
dp = [INF] * (N+1)
for _ in range(M):
    a, b, c = map(int, input().split())

    graph.append((a, b, c))

flag = search(1)

if flag == False:
    for i in range(2, N+1):    
        if dp[i] == INF:
            print(-1)
        else:
            print(dp[i])

else:
    print(-1)
