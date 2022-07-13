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