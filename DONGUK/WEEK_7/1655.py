import heapq, sys
input = sys.stdin.readline

n = int(input())

heap = []
for i in range(n):
    num = int(input())
    heapq.heappush(heap, num)

    if i == 0:
        print(heap[0])
        continue

    ind = i // 2
    if len(heap) % 2 == 1:
        print(heap[ind])
        
    else:
        print(min(heap[ind], heap[ind + 1]))
    
    print(heap)
