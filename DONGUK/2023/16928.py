import sys, heapq

input = sys.stdin.readline

N, M = map(int, input().split())

ladders = dict()
snakes = dict()
for _ in range(N):
    src, dest = map(int, input().split())
    ladders[src] = dest

for _ in range(M):
    src, dest = map(int, input().split())
    snakes[src] = dest

q = []
heapq.heappush(q, (0, -1))
visited = [0] * 101
ans = 0
while q:
    top = heapq.heappop(q)
    now, dist = -top[1], top[0]

    if visited[now] == 1:
        continue
    
    if now == 100:
        ans = dist
        break

    visited[now] = 1

    for i in range(1, 7):
        next_num = now + i

        if next_num > 100:
            continue

        if next_num in ladders:
            jump_num = ladders[next_num]
            heapq.heappush(q, (dist + 1, -jump_num))
        elif next_num in snakes:
            jump_num = snakes[next_num]
            heapq.heappush(q, (dist + 1, -jump_num))
        else:
            heapq.heappush(q, (dist + 1, -next_num))

print(ans)