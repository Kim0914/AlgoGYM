import math

INF = math.inf

def solution(alp, cop, problems):
    answer = 0
    
    max_alp, max_cop = -1, -1
    for problem in problems:
        cmp_alp, cmp_cop = problem[0], problem[1]
        
        if cmp_alp > max_alp:
            max_alp = cmp_alp
        
        if cmp_cop > max_cop:
            max_cop = cmp_cop
            
    
    if alp > max_alp:
        max_alp = alp
    
    if cop > max_cop:
        max_cop = cop
            
    
    dp = [[INF] * (max_cop + 1) for _ in range(max_alp + 1)]
    
    dp[alp][cop] = 0
    for i in range(alp, max_alp + 1):
        for j in range(cop, max_cop + 1):
            
            if i + 1 <= max_alp:
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1)
                
            if j + 1 <= max_cop:
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1)
            
    
            for problem in problems:
                req_alp, req_cop = problem[0], problem[1]
                alp_rwd, cop_rwd = problem[2], problem[3]
                cost = problem[4]
                
                if i >= req_alp and j >= req_cop:
                    next_alp = min(max_alp, i + alp_rwd)
                    next_cop = min(max_cop, j + cop_rwd)
                    
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost)
        
        
    answer = dp[-1][-1]
                
    return answer