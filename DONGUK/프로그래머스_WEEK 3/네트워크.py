from collections import deque

visited = [0] * 201

def search(graph, i):
    q = deque()
    
    q.append(i)
    
    while q:
        top = q.popleft()
        
        visited[top] = 1
        
        for data in graph[top]:
            if visited[data] == 0:
                q.append(data)
    

def solution(n, computers):
    answer = 0
    
    graph = [[]  for _ in range(n+1)]
    
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i != j and computers[i-1][j-1] == 1:
                graph[i].append(j)
    
    
    for i in range(1, n+1):
        if visited[i] == 0:
            answer += 1
            search(graph, i)
            
    return answer