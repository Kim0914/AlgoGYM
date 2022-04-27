import sys
from collections import deque
input = sys.stdin.readline

def search(x, y):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    queue = deque()
    queue.append((x, y, False))
    

    while queue:
        top = queue.popleft()
        x, y, flag = top[0], top[1], top[2]

        if x == n-1 and y == m-1:
            return visited[x][y][flag]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                # 다음 이동할 곳이 벽이고, 벽파괴기회를 사용하지 않은 경우
                if board[nx][ny] == '1' and flag == 0 :
                    visited[nx][ny][1] = visited[x][y][0] + 1
                    queue.append((nx, ny, 1))
                # 다음 이동할 곳이 벽이 아니고, 아직 한 번도 방문하지 않은 곳이면
                elif board[nx][ny] == '0' and visited[nx][ny][flag] == 0:
                    visited[nx][ny][flag] = visited[x][y][flag] + 1
                    queue.append((nx, ny, flag))
                
    return -1

n, m = map(int, input().split())

dp = [[0] * m for _ in range(n)]
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
visited[0][0][0] = 1

board = []
for _ in range(n):
    board.append(list(input().rstrip()))

print(search(0, 0))




'''
8 8
01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100
답: 29


5 10
0000011000
1101011010
0000000010
1111111110
1111000000
답 14


5 5
01100
01000
01110
01000
00010
답 9


8 4
0000
0110
1110
0000
0111
0000
1110
0000
답 11

'''