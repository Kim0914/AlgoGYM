import sys
from collections import deque
input = sys.stdin.readline

case = 1
while True:
    n, m = map(int, input().split())

    if n == 0 and m == 0:
        break
    
    tree = [[] * (1+n) for _ in range(1+n)]
    visited = [0] * (1+n)

    def search(v):
        q = deque()
        q.append(v)

        flag = True
        while q:
            now = q.popleft()

            if visited[now] == 1:
                flag = False
                
            visited[now] = 1
            for vertex in tree[now]:
                if visited[vertex] == 0:
                    q.append(vertex)

        return flag
    
    for _ in range(m):
        a, b = map(int, input().split())
        tree[a].append(b)
        tree[b].append(a)

    ans = 0
    for i in range(1, n+1):
        if visited[i] == 0:
            if search(i):
                ans += 1
            
    if ans > 1:
        print('Case {}: A forest of {} trees.'.format(case, ans))
    
    elif ans == 1:
        print('Case {}: There is one tree.'.format(case))

    else:
        print('Case {}: No trees.'.format(case))
    
    case += 1