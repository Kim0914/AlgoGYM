from collections import deque

def search(n, wires):
    graph = [[]  for _ in range(n+1)]
    visited = [0] * (n+1)
    for a, b in wires:
        graph[a].append(b)
        graph[b].append(a)
    
    cnt = 0
    q = deque()
    q.append(1)
    
    while q:
        top = q.popleft()

        if visited[top] == 1:
            continue
        
        visited[top] = 1
        cnt += 1
        
        for data in graph[top]:
            if visited[data] == 0:
                q.append(data)
    
    return cnt


def solution(n, wires):
    answer = []
    
    wires = deque(wires)
    for _ in range(n):
        top = wires.popleft()
        ret = search(n, wires)
        answer.append((ret, n - ret))
        wires.append(top)
        
    answer.sort(key=lambda x: abs(x[0] - x[1]))
    
    answer = abs(answer[0][0] - answer[0][1])
    
    return answer