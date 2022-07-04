import math

INF = math.inf

def solution(N, road, K):
    answer = 0
    graph = [[INF] * (N+1) for _ in range(N+1)]
    
    for data in road:
        start, end, dis = data[0], data[1], data[2]
        
        if graph[start][end] != INF:
            graph[start][end] = min(graph[start][end], dis)
            
        else:
            graph[start][end] = dis
        
        if graph[end][start] != INF:
            graph[end][start] = min(graph[end][start], dis)
            
        else:
            graph[end][start] = dis
    
    
    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if i == j:
                    graph[i][j] = 0
                    continue
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
                
    
    for num in graph[1]:
        if num <= K:
            answer += 1

    return answer