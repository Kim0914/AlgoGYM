import heapq, sys
input = sys.stdin.readline

n = int(input())

max_heap = []
min_heap = []
for i in range(n):
    num = int(input())

    if i == 0:
        heapq.heappush(max_heap, (-num, num))
        print(max_heap[0][1])
        continue
    
    if len(max_heap) == len(min_heap):
        heapq.heappush(max_heap, (-num, num))

    else:
        heapq.heappush(min_heap, num)

    
    if max_heap[0][1] > min_heap[0]: 
        max_top = heapq.heappop(max_heap)[1]
        min_top = heapq.heappop(min_heap)

        heapq.heappush(max_heap, (-min_top, min_top))
        heapq.heappush(min_heap, max_top)

    
    print(max_heap[0][1])