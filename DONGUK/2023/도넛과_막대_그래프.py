from collections import deque

def solution(edges):
    answer = []
    add_vertex = -1
    dough = 0
    stick = 0
    eight = 0
    
    graphs = {}
    vertexes = set()
    input_info = {}
    output_info = {}
    for edge in edges:
        a, b = edge[0], edge[1]
        vertexes.add(a)
        
        if a not in graphs:
            graphs[a] = [b]
        else:
            graphs[a].append(b)

        if a not in output_info:
            output_info[a] = 1
        else:
            output_info[a] += 1
        
        if b not in input_info:
            input_info[b] = 1
        else:
            input_info[b] += 1
            
    for v in graphs.keys():
        if len(graphs[v]) >= 2 and v not in input_info:
            add_vertex = v
            break
    
    searches = []
    for v in graphs[add_vertex]:
        searches.append(v)
    
    visited = [0] * 1000001
    for v in searches:
        visit_vertex =  []
        q = deque()
        q.append(v)
        visit_vertex.append(v)
        visited[v] = 1
        vertex_cnt = 0
        edge_cnt = 0
        while q:
            top = q.popleft()
            vertex_cnt += 1
            
            if top not in graphs:
                continue
            
            for neighbor in graphs[top]:
                if visited[neighbor] == 0:
                    q.append(neighbor)
                    visited[neighbor] = 1
                    visit_vertex.append(neighbor)
        
        for a in visit_vertex:
            if a in graphs:
                edge_cnt += len(graphs[a])
        
        if vertex_cnt == edge_cnt:
            dough += 1
        elif vertex_cnt == edge_cnt + 1:
            stick += 1
        elif vertex_cnt + 1 == edge_cnt:
            eight += 1
        
    
    answer.append(add_vertex)
    answer.append(dough)
    answer.append(stick)
    answer.append(eight)
            
    return answer