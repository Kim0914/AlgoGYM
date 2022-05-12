import sys, heapq, math

INF = math.inf
input = sys.stdin.readline

n = int(input())
max_val = 0
tree = [[] * (n+1) for _ in range(n+1)]

def init():
    for _ in range(n-1):
        a, b, c = map(int, input().split())

        tree[a].append((b, c))
        tree[b].append((a, c))

def search(start):
    global max_val

    q = []
    dp = [INF] * (1+n)

    heapq.heappush(q, (0, start))
    dp[start] = 0
    while q:
        top = heapq.heappop(q)
        now, dist = top[1], top[0]

        if dist > dp[now]:
            continue
        
        for data in tree[now]:
            neighbor = data[0]
            cost = data[1] + dist

            if cost < dp[neighbor]:
                dp[neighbor] = cost
                heapq.heappush(q, (cost, neighbor))

    max_val = 0
    for i in range(1, n+1):
        if max_val < dp[i] and dp[i] != INF:
            max_val = dp[i]

    ind = dp.index(max_val)
    return ind

init()

search(search(1))

print(max_val)
