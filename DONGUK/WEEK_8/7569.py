import sys
from collections import deque
input = sys.stdin.readline

m, n, h = map(int, input().split())
queue = deque()

def search():
    dx = [1, -1, 0, 0]
    dy = [0, 0, -1, 1]
    df = [1, -1]

    while queue:
        top = queue.popleft()
        f, x, y = top[0], top[1], top[2]
        visited[f][x][y] = 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if visited[f][nx][ny] == 0 and board[f][nx][ny] == 0:
                    queue.append((f, nx, ny))
                    visited[f][nx][ny] = 1
                    board[f][nx][ny] = board[f][x][y] + 1
            
        for i in range(2):
            nf = f + df[i]

            if 0 <= nf < h :
                if visited[nf][x][y] == 0 and board[nf][x][y] == 0:
                    queue.append((nf, x, y))
                    visited[nf][x][y] = 1
                    board[nf][x][y] = board[f][x][y] + 1


visited = []
board = []
for _ in range(h):
    data = []
    visit = [[0] * m for _ in range(n)]
    for _ in range(n):
        data.append(list(map(int, input().split())))

    board.append(data)
    visited.append(visit)


for k in range(h): # 몇 층 인지
    for i in range(n):
        for j in range(m):
            if board[k][i][j] == 1:
                queue.append((k, i, j)) # 층, x좌표, y좌표

search()

zero_flag = False
max_val = -99999999
for k in range(h): # 몇 층 인지
    for i in range(n):
        for j in range(m):
            if board[k][i][j] == 0:
                zero_flag = True

            max_val = max(max_val, board[k][i][j])

if zero_flag:
    print(-1)

else:
    print(max_val - 1)