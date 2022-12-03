def solution(board):
    answer = 0
    max_length = 0
    
    N = len(board)
    M = len(board[0])
    
    dp = [[0] * (M+1) for _ in range(N+1)]
    
    for i in range(1, N+1):
        for j in range(1, M+1):
            if board[i-1][j-1] == 1:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                
                if dp[i][j] > max_length:
                    max_length = dp[i][j]
    
    answer = max_length ** 2
                
    return answer