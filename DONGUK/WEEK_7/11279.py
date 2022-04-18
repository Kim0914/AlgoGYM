import heapq, sys

input = sys.stdin.readline

n = int(input())

heap = []
for _ in range(n):
    c = int(input())

    if c == 0:
        if len(heap) == 0:
            print(0)
        
        else:
            print(heapq.heappop(heap)[1])
    
    else:
        heapq.heappush(heap, (-c, c))