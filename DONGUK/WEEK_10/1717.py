import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n, m = map(int, input().split())
parents = [0] * (1+n)

def find(x):
    if parents[x] != x:
        parents[x] = find(parents[x])
    
    return parents[x]

def union(a, b):
    a, b = find(a), find(b)

    if a < b:
        parents[b] = a
    
    else:
        parents[a] = b
    

for i in range(n+1):
    parents[i] = i


for _ in range(m):
    cal, a, b = map(int, input().split())

    if cal == 0:
        union(a, b)

    else:
        if find(a) == find(b):
            print('YES')
        
        else:
            print('NO')

