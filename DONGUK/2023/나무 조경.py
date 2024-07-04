import sys

input = sys.stdin.readline

n = int(input())

answer = 0

def dfs(graph, visited, pairs):
    global n, answer

    if n == 2 and len(pairs) == n:
        sum_ = 0
        for pair in pairs:
            sum_ += graph[pair[0][0]][pair[0][1]] + graph[pair[1][0]][pair[1][1]]

        answer = max(answer, sum_)
        return

    if len(pairs) == 4:
        sum_ = 0
        for pair in pairs:
            sum_ += graph[pair[0][0]][pair[0][1]] + graph[pair[1][0]][pair[1][1]]

        answer = max(answer, sum_)
        return
    
    dx = [1, 0]
    dy = [0, 1]
    
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 1:
                continue
            for k in range(2):
                nx, ny = i + dx[k], j + dy[k]
                if 0 <= nx < n and 0 <= ny < n:
                    if visited[nx][ny] == 0:
                        visited[i][j] = 1
                        visited[nx][ny] = 1
                        pairs.append([(i, j), (nx, ny)])
                        dfs(graph, visited, pairs)
                        pairs.pop()
                        visited[nx][ny] = 0
                        visited[i][j] = 0
                
graph = [[] for _ in range(n)]

for i in range(n):
    row = list(map(int, input().split()))
    graph[i] = row

visited = [[0] * n for _ in range(n)]

dfs(graph, visited, [])

print(answer)