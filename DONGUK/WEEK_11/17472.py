import sys, heapq
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]
island = []
distance = []
num = 1

def bfs(num, x, y):
    if visited[x][y] == 1:
        return

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    q = deque()
    q.append((x, y))
    island.append((num, x, y))

    visited[x][y] = 1
    board[x][y] = num

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 1:
                if visited[nx][ny] == 0:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    board[nx][ny] = num

def init():
    global num
    
    for i in range(n):
        for j in range(m):
            if visited[i][j] == 0 and board[i][j] == 1:
                bfs(num, i, j)
                num += 1



distance = [[] for _ in range(num)]
def calcDistance():
    for i in range(n):
        for j in range(m):
            if board[i][j] != 0:
                node = board[i][j]

                # 행으로 확인
                if j == m-1:
                    pass

                else:
                    for k in range(j+1, m):
                        nnode = board[i][k]
                        if nnode != node and nnode != 0:
                            dis = abs(k - j) - 1
                            distance[node].append((dis, nnode))
                            distance[nnode].append((dis, node))
                            break

                        else:
                            if nnode == 0:
                                continue
                            
                            else:
                                break

                # 열로 확인

                if i == n-1:
                    pass

                else:
                    for k in range(i+1, n):
                        nnode = board[k][j]
                        if nnode != node and nnode != 0:
                            dis = abs(k - i) - 1
                            distance[node].append((dis, nnode))
                            distance[nnode].append((dis, node))
                            break

                        else:
                            if nnode == 0:
                                continue
                            
                            else:
                                break

def search(node):
    q = []
    heapq.heappush(q, (0, node))

    visited = [0] * (num)
    cnt = 0
    ans = 0
    while q:
        top = heapq.heappop(q)
        dis, now = top[0], top[1]
        

        if visited[now] == 1:
            continue

        visited[now] = 1
        ans += dis
        cnt += 1
        

        if cnt == num-1:
            print(ans)
            return
        
        for data in distance[now]:
            neighbor, cost = data[1], data[0]
            if visited[neighbor] == 0 and cost > 1:
                heapq.heappush(q, (cost, neighbor))
    
    print(-1)

init()
calcDistance()
search(1)