def solution(n, money):
    answer = 0
    
    dp = [0] * (n+1)
    
    dp[0] = 1
    for coin in money:
        for num in range(coin, n+1):
            dp[num] += dp[num - coin]
        
        
    answer = dp[n]
    
    return answer