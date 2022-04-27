import sys
input = sys.stdin.readline

n, k = map(int, input().split())

visited = [0] * (100001)
dp = [0] * (100001)

def search(v):
    
    queue = []
    queue.append(v)

    while queue:
        vertex = queue.pop(0)

        if vertex == k:
            return

        visited[vertex] = 1

        nv = vertex - 1
        if 0 <= nv <= 100000 and visited[nv] == 0:
            visited[nv] = 1
            dp[nv] = dp[vertex] + 1
            queue.append(nv)
        
        nv = vertex + 1
        if 0 <= nv <= 100000 and visited[nv] == 0:
            visited[nv] = 1
            dp[nv] = dp[vertex] + 1
            queue.append(nv)

        nv = vertex * 2
        if 0 <= nv <= 100000 and visited[nv] == 0:
            visited[nv] = 1
            dp[nv] = dp[vertex] + 1
            queue.append(nv)
        
search(n)

print(dp[k])

# cnt = 0
# while True:
#     if k == n:
#         break

#     elif k == n-1 or k == n+1:
#         cnt += 1
#         break

#     else:
#         if k % 2 == 1:
#             cnt += 1
        
#         k = k // 2
#         cnt += 1

# print(cnt)


'''
17 -> 8 -> 4


9 16

2 -> 4 -> 8 -> 9


'''