import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def search(x, y):
    if dp[x][y] != -1:
        return dp[x][y]
    
    if x == m-1 and y == n-1:
        return 1

    dp[x][y] = 0

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < m and 0 <= ny < n:
            if board[x][y] > board[nx][ny]:
                dp[x][y] += search(nx, ny)

    return dp[x][y]


m, n = map(int ,input().split())
board = [list(map(int, input().split())) for _ in range(m)]

dp = [[-1] * n for _ in range(m)]

print(search(0,0))

for d in dp:
    print(d)
