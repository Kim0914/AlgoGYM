def solution(n):
    answer = 0
    
    dp = [1] * (n+1)
    
    for i in range(2, int(n ** (1/2)) + 1):
        if dp[i] == 1:
            j = 2
            while i * j <= n:
                dp[i*j] = 0
                j += 1
            
    for i in range(2, n+1):
        if dp[i] == 1:
            answer += 1
            
    return answer