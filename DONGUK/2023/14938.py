import sys, math

input = sys.stdin.readline

INF = math.inf

# 지역 수(n), 수색 범위(m), 길의 개수(r)
n, m, r = map(int, input().split())

graphs = [[INF] * (n) for _ in range(n)] 
items = list(map(int, input().split()))

for _ in range(r):
    a, b, l = map(int, input().split())
    graphs[a-1][b-1] = l
    graphs[b-1][a-1] = l

for k in range(n):
    for i in range(n):
        if i == k:
            continue
        for j in range(n):
            if graphs[i][j] > graphs[i][k] + graphs[k][j]:
                graphs[i][j] = graphs[i][k] + graphs[k][j]


ans = -1

for i in range(n):
    cnt = 0
    for j in range(n):
        if i == j:
            cnt += items[i]
            continue

        if graphs[i][j] <= m:
            cnt += items[j]
    ans = max(ans, cnt)
print(ans)