import sys, heapq

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

m, n = map(int ,input().split())
board = [list(map(int, input().split())) for _ in range(m)]

def search(x, y):
    q = []
    heapq.heappush(q, (-board[x][y], x, y))

    visited = [[0] * n for _ in range(m)]
    visited[x][y] = 1

    while q:
        now, x, y = heapq.heappop(q)
        now = now * -1 # heapq에 음수로 들어가 있음

        if x == m-1 and y == n-1:
            continue

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < m and 0 <= ny < n:
                if board[nx][ny] < board[x][y]:
                    if visited[nx][ny] == 0:
                        heapq.heappush(q, (-board[nx][ny], nx, ny))

                    visited[nx][ny] += visited[x][y]
                    
    return visited[-1][-1]

print(search(0,0))

