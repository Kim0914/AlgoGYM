n, m, v = map(int, input().split())


def dfs(vertex):
    if dfs_visited[vertex] == 1:
        return

    dfs_ans.append(vertex)
    dfs_visited[vertex] = 1

    candidate = graph[vertex]

    for i in range(len(candidate)):
        if candidate[i] == 1:
            dfs(i)


def bfs(vertex):
    queue = []
    queue.append(vertex)

    while queue:
        ind = queue.pop(0)
        bfs_visited[ind] = 1
        bfs_ans.append(ind)

        for i in range(1, n+1):
            if graph[ind][i] == 1 and bfs_visited[i] == 0:
                queue.append(i)
                bfs_visited[i] = 1


graph = [[0] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b], graph[b][a] = 1, 1


dfs_visited = [0] * (n+1)
bfs_visited = [0] * (n+1)
dfs_ans = []
bfs_ans = []

dfs(v)
bfs(v)

print(*dfs_ans)
print(*bfs_ans)