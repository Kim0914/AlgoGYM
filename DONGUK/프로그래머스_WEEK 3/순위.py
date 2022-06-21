
def solution(n, results):
    answer = 0
    graph = [[0] * (n+1) for _ in range(n+1)]
    
    for result in results:
        win, lose = result[0], result[1]
        graph[win][lose] = 1
    
    
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] == 1 and graph[k][j] == 1:
                    graph[i][j] = 1
    
    
    for i in range(1, n+1):
        row_cnt = graph[i].count(1)
        col_cnt = 0
        for j in range(1, n+1):
            if graph[j][i] == 1:
                col_cnt += 1
        
        if row_cnt + col_cnt == n-1:
            answer += 1
            
    return answer