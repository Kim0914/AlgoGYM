import heapq

summits_dict = {}
gates_dict = {}

MAX = 10000001
def search(graph, gate):
    global summits_dict
    
    q = []
    
    heapq.heappush(q, (0, gate))
    visited = [0] * 50001
    
    intensity = MAX
    while q:
        top = heapq.heappop(q)
        
        cost, now = top[0], top[1]
        
        if cost >= intensity:
            continue
        
        if now in summits_dict:
            summits_dict[now] = min(summits_dict[now], cost)
            intensity = summits_dict[now]
            continue
        
        visited[now] = 1
        
        for data in graph[now]:
            dist, neighbor = data[0], data[1]
            
            if neighbor in gates_dict:
                continue
            
            if visited[neighbor] == 1:
                continue
                
            if dist >= intensity:
                continue
            
            heapq.heappush(q, (max(cost, dist), neighbor))
            
def solution(n, paths, gates, summits):

    graph = [[] for _ in range(n+1)]
    
    for summit in summits:
        summits_dict[summit] = MAX
        
    for gate in gates:
        gates_dict[gate] = MAX
        
    for path in paths:
        start, end, weight = path[0], path[1], path[2]
        graph[start].append((weight, end))
        graph[end].append((weight, start))
    
    for gate in gates:
        search(graph, gate)
    
    sorted_dict = sorted(summits_dict.items(), key = lambda item: (item[1], item[0]))
    
    answer = [sorted_dict[0][0], sorted_dict[0][1]]

    return answer