import sys, math, heapq
input = sys.stdin.readline

n = int(input())

d = {}
star = []
distance = [[] * n for _ in range(n)]

def getDistance(x1, y1, x2, y2):
    return math.sqrt(abs(x2 - x1) ** 2 + abs(y2 - y1) ** 2)


def search(i):
    data = star[i]

    q = []
    heapq.heappush(q, (0, data))
    
    cnt = 0
    weight = 0
    while q:
        top = heapq.heappop(q)
        dis, now = top[0], top[1]

        if d[now] == 1:
            continue
        
        d[now] = 1
        cnt += 1
        weight += dis

        if cnt == n:
            print(round(weight, 2))
            return

        ind = star.index(now)
        for data in distance[ind]:
            neigbor, cost = data[0], data[1]
            if d[neigbor] == 0:
                heapq.heappush(q, (cost, neigbor))
    
    

def init():
    for _ in range(n):
        a, b = map(float, input().split())
        d[(a,b)] = 0
        star.append((a, b))

    for i in range(n):
        x1, y1 = star[i][0], star[i][1]
        for j in range(n):
            if j != i:
                x2, y2 = star[j][0], star[j][1]
                dis = getDistance(x1, y1, x2, y2)
                distance[i].append([(x2, y2), dis])
init()
search(0)