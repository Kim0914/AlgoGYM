def solution(land):
    answer = 0

    dp = [[0] * 4 for _ in range(len(land))]

    for i in range(4):
        dp[0][i] = land[0][i]

    N = len(land)
    for i in range(1, N):
        for j in range(4):
            data = []
            for k in range(4):
                if k != j:
                    data.append(dp[i-1][k])

            dp[i][j] = max(data) + land[i][j]
            
    answer = max(dp[-1])
    return answer