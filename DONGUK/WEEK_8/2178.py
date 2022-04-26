import sys
input = sys.stdin.readline

n, m = map(int, input().split())
visited = [[0] * m for _ in range(n)]
dp = [[0] * m for _ in range(n)]

def search(x, y):

    visited[x][y] = 1

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    queue = []
    queue.append((x, y))
    dp[x][y] = 1

    while queue:
        top = queue.pop(0)
        x, y = top[0], top[1]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx == n-1 and ny == m-1:
                dp[nx][ny] = dp[x][y] + 1
                return

            if 0 <= nx < n and 0 <= ny < m:
                if board[nx][ny] == '1' and visited[nx][ny] == 0:
                    queue.append((nx, ny))
                    visited[nx][ny] = 1
                    dp[nx][ny] = dp[x][y] + 1
                    

        
       
board = []
for _ in range(n):
    board.append(list(input().rstrip()))

search(0, 0)

print(dp[n-1][m-1])