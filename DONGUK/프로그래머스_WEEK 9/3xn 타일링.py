def solution(n):
    answer = 0
    
    if n % 2 == 1:
        return answer
    
    dp = [0] * (n+1)
    
    dp[2] = 3
    dp[4] = 11

    for i in range(6, n+1, 2):
        dp[i] = ((dp[i-2] * 4) - (dp[i-4])) % 1000000007
        
    
    answer = dp[n]
    return answer