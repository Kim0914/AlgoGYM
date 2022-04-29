from collections import deque

RED = 1
BLUE = -1

k = int(input())

for _ in range(k):
    v, e = map(int, input().split())

    graph = [[] for _ in range(v+1)]
    visited = [0] * (v+1)
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    
    queue = deque()
    color = 1
    flag = True
    for i in range(1, v+1):
        if visited[i] == 0:
            visited[i] = 1
            queue.append(i)

            while queue: # 연결된 노드들은 다른 색으로 칠하기
                v = queue.popleft()
                for vertex in graph[v]:
                    if visited[vertex] == 0:
                        queue.append(vertex)
                        visited[vertex] = -1 * visited[v] # 블루로 칠하기
                    
                    elif visited[v] == visited[vertex]: # 방문한 좌표인데 서로 색이 같으면
                        flag = False
                        break
                        
    
    if flag:
        print('YES')
    
    else:
        print('NO')

                
            
