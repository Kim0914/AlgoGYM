import sys, math, heapq

input = sys.stdin.readline

n = int(input())
space = []
distance = [[] for _ in range(n)]
visited = [0] * n

def getDistance(x1, y1, z1, x2, y2, z2):
    return min(abs(x1 - x2), abs(y1 - y2), abs(z1 - z2))


def calDistance():
    for i in range(n-1):
        x1, y1, z1, i1 = space_x[i][0], space_x[i][1], space_x[i][2], space_x[i][3]
        x2, y2, z2, i2 = space_x[i+1][0], space_x[i+1][1], space_x[i+1][2], space_x[i+1][3]
        dis = getDistance(x1, y1, z1, x2, y2, z2)
        distance[i1].append((i2, dis))
        distance[i2].append((i1, dis))
    
        
        x1, y1, z1, i1 = space_y[i][0], space_y[i][1], space_y[i][2], space_y[i][3]
        x2, y2, z2, i2 = space_y[i+1][0], space_y[i+1][1], space_y[i+1][2], space_y[i+1][3]
        dis = getDistance(x1, y1, z1, x2, y2, z2)
        distance[i1].append((i2, dis))
        distance[i2].append((i1, dis))

        
        x1, y1, z1, i1 = space_z[i][0], space_z[i][1], space_z[i][2], space_z[i][3]
        x2, y2, z2, i2 = space_z[i+1][0], space_z[i+1][1], space_z[i+1][2], space_z[i+1][3]
        dis = getDistance(x1, y1, z1, x2, y2, z2)
        distance[i1].append((i2, dis))
        distance[i2].append((i1, dis))


def search(index):
    q = []
    heapq.heappush(q, (0, index))

    cnt = 0
    ans = 0
    while q:
        top = heapq.heappop(q)
        dist, now = top[0], top[1]
        
        if visited[now] == 1:
            continue
        
        visited[now] = 1
        ans += dist
        cnt += 1

        if cnt == n:
            print(ans)
            return
        
        for data in distance[now]:
            neighbor, cost = data[0], data[1]
            if visited[neighbor] == 0:
                heapq.heappush(q, (cost, neighbor))


def init():
    for i in range(n):
        a, b, c = map(int, input().split())
        space.append((a, b, c, i))


init()

space_x = sorted(space, key=lambda x: x[0])
space_y = sorted(space, key=lambda x: x[1])
space_z = sorted(space, key=lambda x: x[2])

calDistance()

search(0)

