import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())
visited = [[0] * m for _ in range(n)]
queue = deque() # 탐색해야할 좌표

def search():
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while queue:
        top = queue.popleft()
        x, y = top[0], top[1]

        visited[x][y] = 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if visited[nx][ny] == 0 and board[nx][ny] == 0:
                    visited[nx][ny] = 1
                    queue.append((nx, ny))
                    board[nx][ny] = board[x][y] + 1

    
                    
        
# 1: 익은거, 0: 안익은거, -1: 토마토 X
board = []
for _ in range(n):
    board.append(list(map(int, input().split())))

zero_flag = True
for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            queue.append((i, j))
        
        elif board[i][j] == 0:
            zero_flag = False

       

if zero_flag:
    print(0)

else:
    search()
    
    flag = False
    max_val = -9999999
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                flag = True
                
            elif board[i][j] > 0:
                max_val = max(max_val, board[i][j])


    if flag:
        print(-1)

    else:
        print(max_val - 1)