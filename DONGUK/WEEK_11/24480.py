import sys, heapq
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n, m, r = map(int, input().split())
ans = [0] * (n+1)
cnt = 1

def dfs(i):
    
    global cnt
    
    ans[i] = cnt

    cnt += 1
    for num in graph[i]:
        if ans[num] == 0:
            dfs(num)


graph = [[] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    

for g in graph:
    g.sort(reverse=True)

dfs(r)

for i in range(1, n+1):
    print(ans[i])