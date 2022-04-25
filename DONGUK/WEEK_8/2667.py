import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

n = int(input())

board = []
visited = [[0] * n for _ in range(n)]
cnt = 0
for _ in range(n):
    board.append(list(input().rstrip()))

def search(x, y):
    global cnt

    if visited[x][y] == 1:
        return
    
    cnt += 1
    visited[x][y] = 1

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < n:
            if board[nx][ny] == '1':
                search(nx, ny)



ans = []
for i in range(n):
    for j in range(n):
        if board[i][j] == '1' and visited[i][j] == 0:
            search(i, j)
            ans.append(cnt)
            cnt = 0
            

ans.sort()

print(len(ans))
for a in ans:
    print(a)