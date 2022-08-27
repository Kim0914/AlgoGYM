from collections import deque
import math

INF = math.inf

def search(x, y, board):
    N = len(board)
    
    dp = [[[INF] * N for _ in range(N)] for _ in range(4)]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    
    q = deque()
    
    for z in range(4):
        dp[z][0][0] = 0
    
    # (x, y, cost, dir)
    q.append((0, 0, 0, -1))
    
    while q:
        top = q.popleft()
        x, y, cost, direction = top[0], top[1], top[2], top[3]
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < N:
                if board[nx][ny] == 0:
                    n_cost = cost
                    if direction == -1:
                        n_cost += 100
                    
                    elif i == direction:
                        n_cost += 100
                        
                    else:
                        n_cost += 600
                    
                    if n_cost < dp[i][nx][ny]:
                        q.append((nx, ny, n_cost, i))
                        dp[i][nx][ny] = n_cost
    
    
    return min(dp[0][-1][-1], dp[1][-1][-1], dp[2][-1][-1], dp[3][-1][-1])
    
    
def solution(board):
    answer = 0
    
    answer = search(0, 0, board)
    return answer