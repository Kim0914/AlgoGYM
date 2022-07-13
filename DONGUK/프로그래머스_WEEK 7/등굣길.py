from collections import deque

dp = [[0] * (101) for _ in range(101)]

def search(m, n):
    dx = [0, 1]
    dy = [1, 0]
    
    dp[1][1] = 1
    
    q = deque()
    q.append((1, 1))
    
    while q:
        x, y = q.popleft()
        
        for i in range(2):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 1 <= nx <= n and 1 <= ny <= m:
                if dp[nx][ny] == -1:
                    continue
                else:
                    dp[nx][ny] += dp[x][y]
                    
                    if (nx, ny) not in q:
                        q.append((nx, ny))
                        
    return dp[n][m] % 1000000007



def solution(m, n, puddles):
    answer = 0
    
    for puddle in puddles:
        x, y = puddle[0], puddle[1]
        dp[y][x] = -1
        
    answer = search(m, n)
    
    return answer



################## 구글링해서 알게 된 코드 ######################
def solution(m, n, puddles):
    answer = 0
    
    dp = [[0] * (m+1) for _ in range(n+1)]
    
    for puddle in puddles:
        x, y = puddle[0], puddle[1]
        dp[y][x] = -1
        
    
    for i in range(1, n+1):
        for j in range(1, m+1):
            if i == 1 and j == 1:
                dp[i][j] = 1
            
            else:
                if dp[i][j] == -1:
                    continue
                    
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j] + dp[i][j-1])
    
    answer = dp[n][m] % 1000000007
    return answer

################## 구글링해서 알게 된 코드 ######################