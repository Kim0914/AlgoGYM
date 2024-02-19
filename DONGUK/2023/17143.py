import sys
from collections import deque

input = sys.stdin.readline

R, C, M = map(int, input().split())
ans = 0
graph = [[[] for _ in range(C)] for _ in range(R)]

for _ in range(M):
    r, c, s, d, z = map(int, input().split())
    graph[r-1][c-1] = [s, d, z]

def catch(pos):
    size = 0
    for i in range(R):
        if graph[i][pos]:
            size += graph[i][pos][2]
            graph[i][pos] = []
            break
        
    return size

def move():
    # (r, c) = (s, d, z) 로 다음 위치 dict에 저장
    candidate = deque()
    pos_dict = {}
    for i in range(R):
        for j in range(C):
            if not graph[i][j]:
                continue
            speed, direction, size = graph[i][j][0], graph[i][j][1], graph[i][j][2]
            candidate.append((i, j, speed, direction, size))
            graph[i][j] = []
    
    while candidate:
        top = candidate.popleft()
        x, y, speed, direction, size = top[0], top[1], top[2], top[3], top[4]
        dirs = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        
        if direction in [1, 2]:
            move = speed % ((R - 1) * 2)
            while move:
                if x == 0:
                    direction = 2
                if x == R - 1:
                    direction = 1
                x += dirs[direction - 1][0]
                move -= 1
            
        elif direction in [3, 4]:
            move = speed % ((C - 1)  * 2)
            while move:
                if y == 0:
                    direction = 3
                if y == C - 1:
                    direction = 4
                y += dirs[direction - 1][1]
                move -= 1

        if (x, y) not in pos_dict:
            pos_dict[(x, y)] = (speed, direction, size)
        else:
            prior_size = pos_dict[(x, y)][2]

            if size > prior_size:
                pos_dict[(x, y)] = (speed, direction, size)

    for key, value in pos_dict.items():
        x, y = key[0], key[1]
        speed, direction, size = value[0], value[1], value[2]
        graph[x][y] = [speed, direction, size]


for k in range(C):
    ans += catch(k)
    move()

print(ans)