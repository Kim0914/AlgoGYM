from collections import deque

def search(index, n, graph):
    dp = [0] * (n+1)
    visited = [0] * (n+1)
    
    q = deque()
    q.append(index)
    visited[index] = 1
    while q:
        top = q.popleft()
        
        for data in graph[top]:
            if visited[data] == 0:
                visited[data] = 1
                dp[data] = dp[top] + 1
                q.append(data)
                
    return dp.count(max(dp))       

def solution(n, edge):
    answer = 0
    
    graph = [[] for _ in range(n+1)]
    
    for data in edge:
        a, b = data[0], data[1]
        graph[a].append(b)
        graph[b].append(a)
    
    answer = search(1, n, graph)
    return answer