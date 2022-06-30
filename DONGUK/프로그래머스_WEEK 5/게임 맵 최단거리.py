import math
from collections import deque

INF = math.inf

def search(maps):
    N = len(maps)
    M = len(maps[0])
    
    dp = [[INF] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    dp[0][0] = 1
    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    q = deque()
    q.append((0, 0))
    
    while q:
        top = q.popleft()
        x, y = top[0], top[1]
        
        if visited[x][y] == 1:
            continue
        
        visited[x][y] = 1
        
        if x == N and y == M:
            continue
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < M:
                if maps[nx][ny] == 1:
                    if visited[nx][ny] == 0:
                        dp[nx][ny] = min(dp[nx][ny], dp[x][y] + 1)
                        q.append((nx, ny))
                        
    return dp[-1][-1]
        
        
def solution(maps):
    answer = search(maps)
    
    if answer == INF:
        answer = -1
    
    return answer