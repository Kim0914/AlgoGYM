import heapq

def solution(operations):
    
    max_heap = []
    min_heap = []
    
    for oper in operations:
        oper = oper.split()
        
        c, num = oper[0], int(oper[1])
        if c == 'I':
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, (-num, num))
        
        else:
            if not min_heap:
                continue
            
            if num == 1:
                heapq.heappop(max_heap)
                min_heap.pop()
            else:
                heapq.heappop(min_heap)
                max_heap.pop()
    
        # print(min_heap, max_heap)
        
    a, b = 0, 0
    if min_heap:
        a, b = max_heap[0][1], min_heap[0]
        
    answer = [a, b]
    
    return answer