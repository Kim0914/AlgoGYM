import sys, math, heapq
from collections import deque
input = sys.stdin.readline
INF = math.inf

V = int(input())


tree = [[] * (1+V) for _ in range(1+V)]
visited = [0] * (1+V)
max_val = 0

def search(start):
    global max_val

    q = []
    heapq.heappush(q, (0, start))

    dp = [INF for _ in range(V+1)]
    dp[start] = 0

    while q:
        top = heapq.heappop(q)
        dist, now = top[0], top[1]

        if dp[now] < dist:
            continue
            
        for data in tree[now]:
            neighbor = data[0]
            cost = data[1] + dist

            if cost < dp[neighbor]:
                dp[neighbor] = cost
                heapq.heappush(q, (cost, neighbor))

    
    ind = 0
    for i in range(1, V+1):
        if dp[i] > max_val:
            max_val = dp[i]
            ind = i

    return ind



def init():
    for _ in range(V):
        data = deque(map(int, input().split()))
        data.pop()

        now = data.popleft()
        for i in range(0, len(data), 2):
            node, cost = data[i], data[i+1]
            tree[now].append((node, cost))

init()

search((search(1)))

print(max_val)

'''
트리 지름 구하기
1. 트리 중 어떤 한 점에서 가장 먼 점을 찾음
2. 가장 먼 점에서 부터 제일 긴 길이를 찾으면 된다.
'''