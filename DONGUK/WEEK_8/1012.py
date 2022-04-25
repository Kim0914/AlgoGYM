import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

T = int(input())


def search(x, y):
    if visited[x][y] == 1:
        return
    
    visited[x][y] = 1

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < m and 0 <= ny < n:
            if board[nx][ny] == 1:
                search(nx, ny)

for _ in range(T):
    m, n, k = map(int, input().split())

    board = [[0] * (n+1) for _ in range(m+1)]
    visited = [[0] * (n+1) for _ in range(m+1)]

    for _ in range(k):
        a, b = map(int, input().split())
        board[a][b] = 1

    cnt = 0
    for i in range(m):
        for j in range(n):
            if board[i][j] == 1 and visited[i][j] == 0:
                search(i, j)
                cnt += 1
    print(cnt)

