n, m = map(int, input().split())

board = []
cnt = 0

def search(x, y):
    global cnt

    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    queue = []
    queue.append([x,y])
    while queue:
        top = queue.pop()
        x, y = top[0], top[1]

        if x == n-1 and y == m-1:
            cnt += 1
            continue

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if board[x][y] > board[nx][ny]:
                    queue.append([nx, ny])
                

for _ in range(n):
    board.append(list(map(int, input().split())))


search(0,0)
print(cnt)