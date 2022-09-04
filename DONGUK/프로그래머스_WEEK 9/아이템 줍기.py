from collections import deque

graph = [[0] * 101 for _ in range(101)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def search(start_x, start_y, target_x, target_y):
    q = deque()
    q.append((start_x, start_y, 0))
    
    dp = [[0] * 101 for _ in range(101)]
    
    dp[start_x][start_y] = 0
    while q:
        top = q.popleft()
        x, y = top[0], top[1]
        
        graph[x][y] = -1
        
        if x == target_x and y == target_y:
            break
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < 101 and 0 <= ny < 101:
                if graph[nx][ny] == 1:
                    graph[nx][ny] = -1
                    dp[nx][ny] = dp[x][y] + 1
                    q.append((nx, ny))
    
    
    return (dp[target_x][target_y] // 2)


def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    
    for data in rectangle:
        x1, y1, x2, y2 = data[0]*2, data[1]*2, data[2]*2, data[3]*2
        
        for i in range(x1, x2+1):
            if graph[i][y1] != 2:
                graph[i][y1] = 1
            
            if graph[i][y2] != 2:
                graph[i][y2] = 1
        
        
        for j in range(y1, y2+1):
            if graph[x1][j] != 2:
                graph[x1][j] = 1
            
            if graph[x2][j] != 2:
                graph[x2][j] = 1
        
        for i in range(x1+1, x2):
            for j in range(y1+1, y2):
                graph[i][j] = 2
    
    
    answer = search(characterX*2, characterY*2, itemX*2, itemY*2)
    return answer