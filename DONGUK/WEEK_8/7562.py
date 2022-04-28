import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

def search(l, x, y, t_x, t_y):
    board = [[0] * l for _ in range(l)]

    dx = [-2, -1, 1, 2, -2, -1, 1, 2]
    dy = [-1, -2, -2, -1, 1, 2, 2, 1]


    queue = deque()
    queue.append((x, y))

    while queue:
        top = queue.popleft()
        x, y = top[0], top[1]

        if x == t_x and y == t_y:
            print(board[t_x][t_y])
            return

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < l and 0 <= ny < l:
                if board[nx][ny] == 0:
                    board[nx][ny] = board[x][y] + 1
                    queue.append((nx, ny))

for _ in range(t):
    l = int(input())
    start_x, start_y = map(int, input().split())
    target_x, target_y = map(int, input().split())

    search(l, start_x, start_y, target_x, target_y)
