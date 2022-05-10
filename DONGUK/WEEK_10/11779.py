import sys, math, heapq
from collections import deque
INF = math.inf
input = sys.stdin.readline

def search(start):
    q = []

    heapq.heappush(q, (0, start))

    while q:
        top = heapq.heappop(q)
        dist = top[0]
        now = top[1]

        if dist > dp[now]:
            continue

        for city in cities[now]:
            neighbor = city[0]
            cost = city[1] + dist

            if cost < dp[neighbor]:
                dp[neighbor] = cost
                prior[neighbor] = now
                heapq.heappush(q, (cost, neighbor))


def route(prior, start, end):
    ans = deque()
    ans.append(end)

    target = prior[end]

    if target == start:
        ans.appendleft(start)
        print(len(ans))
        print(*ans)
        return

    while target != start:
        ans.appendleft(target)

        target = prior[target]

        if target == start:
            ans.appendleft(target)
    
    print(len(ans))
    print(*ans)


n = int(input())
m = int(input())

cities = [[] for _ in range(n+1)]
dp = [INF] * (1 + n)
prior = [0] * (1 + n)

for _ in range(m):
    a, b, c = map(int, input().split())
    cities[a].append((b, c))

start, end = map(int, input().split())

search(start)

print(dp[end])

route(prior, start, end)

