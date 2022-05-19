import sys, math, heapq
input = sys.stdin.readline

n, m = map(int, input().split())

space = []
distance = [[] for _ in range(n+1)]
visited = [0] * (n+1)


def getDistance(x1, y1, x2, y2):
    return math.sqrt(abs(x2 - x1) ** 2 + abs(y2 - y1) ** 2)


def search(start):
    q = []
    heapq.heappush(q, (0, start))

    cnt = 0
    ans = 0
    while q:
        top = heapq.heappop(q)

        dist, now = top[0], top[1]

        if visited[now] == 1:
            continue

        visited[now] = 1
        cnt += 1
        ans += dist

        if cnt == n:
            print(format(ans, ".2f"))
            return

        for data in distance[now]:
            neighbor, cost = data[0], data[1]

            if visited[neighbor] == 0:
                heapq.heappush(q, (cost, neighbor))


def calcDistance():
    global distance

    for i in range(n):
        x1, y1 = space[i][0], space[i][1]
        for j in range(n):
            if i != j:
                x2, y2 = space[j][0], space[j][1]
                dis = getDistance(x1, y1, x2, y2)
                distance[i+1].append((j+1, dis))


def init():
    for _ in range(n):
        a, b = map(int, input().split())
        space.append((a, b))
        

    for _ in range(m):
        n1, n2 = map(int, input().split())
        distance[n1].append((n2, 0))
        distance[n2].append((n1, 0))
        

init()

calcDistance()

search(1)