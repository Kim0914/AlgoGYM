import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

graph = []
for _ in range(N):
    graph.append(list(map(int, input().rstrip())))

result = [[0] * M for _ in range(N)]
dp = [[-1] * M for _ in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

zero_visited = set()
zero_dict = {}
num = 100
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0 and (i, j) not in zero_visited:
            q = deque()
            q.append((i, j))
            zero_visited.add((i, j))
            cnt = 0
            while q:
                top = q.popleft()
                x, y = top[0], top[1]
                dp[x][y] = num
                cnt += 1
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]

                    if 0 <= nx < N and 0 <= ny < M:
                        if graph[nx][ny] == 0 and (nx, ny) not in zero_visited:
                            zero_visited.add((nx, ny))
                            q.append((nx, ny))
            zero_dict[num] = cnt % 10
            num += 1

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            q = deque()
            q.append((i, j))
            cnt = 0
            while q:
                top = q.popleft()
                x, y = top[0], top[1]
                cnt += 1
                num_set = set()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]

                    if 0 <= nx < N and 0 <= ny < M:
                        if graph[nx][ny] == 0:
                            zero_num = dp[nx][ny]
                            if zero_num not in num_set:
                                num_set.add(zero_num)
                    
                for num in num_set:
                    cnt += zero_dict[num]
            result[i][j] = cnt % 10
        
for res in result:
    print(''.join(str(s) for s in res))