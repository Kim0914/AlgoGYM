from collections import deque

n, k = map(int, input().split())

q = deque()

for i in range(1, n+1):
    q.append(i)

ans = []
while q:
    for i in range(k):
        if i == k-1:
            ans.append(q.popleft())

        else:
            num = q.popleft()
            q.append(num)

res = list(ans)
N = len(res)
print('<', end='')
for i in range(N):
    if i < N-1:
        print(str(res[i]) + ',', end=' ')
    
    else:
        print(str(res[i])+ '>')