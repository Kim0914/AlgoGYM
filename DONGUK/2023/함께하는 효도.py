import sys
from itertools import product

input = sys.stdin.readline

def search(path, x, y, routes):
    global n
    
    dx = [1, -1, 0, 0]    
    dy = [0, 0, 1, -1]

    if len(path) == 4:
        routes.append(path[:])
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < n:
            if (nx, ny) not in path:
                path.append((nx, ny))
                search(path, nx, ny, routes)
                path.pop()


def calculate(routes):
    global graphs
    
    result = 0
    visited = set()
    for route in routes:
        for x, y in route:
            if (x, y) in visited:
                continue
            visited.add((x, y))
            result += graphs[x][y]

    return result


n, m = map(int, input().split())

graphs = []

for _ in range(n):
    info = list(map(int, input().split()))
    graphs.append(info)

pos = []
for _ in range(m):
    x, y = map(int, input().split())
    pos.append((x-1, y-1))

all_routes = []
for x, y in pos:
    routes = []
    search([(x, y)], x, y, routes)
    all_routes.append(routes)

res = 0
for comb in product(*all_routes):
    res = max(res, calculate(comb))
    
print(res)