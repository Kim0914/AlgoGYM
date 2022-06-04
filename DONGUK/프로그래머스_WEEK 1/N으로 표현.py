def solution(N, number):
    if N == number:
        return 1
    
    dp = [[] for _ in range(9)]
    
    dp[1].append(N)
    for i in range(2, 9):
        dp[i].append(int(str(N) * i))
        for j in range(1, i):
            for a in dp[j]:
                for b in dp[i-j]:
                    dp[i].append(a + b)
                    dp[i].append(a * b)
                    dp[i].append(a - b)
                    
                    if b != 0:
                        dp[i].append(a // b)
            
        dp[i] = list(set(dp[i]))

        if number in dp[i]:
            return i
    
    return -1