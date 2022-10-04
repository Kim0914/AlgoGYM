import heapq

def solution(n, works):
    answer = 0
    
    if sum(works) <= n:
        return 0
    
    q = []
    for work in works:
        heapq.heappush(q, (-work, work))
        
    
    max_val = q[0][1]
    while n:
        top = heapq.heappop(q)
        top_val = top[1]
        
        if top_val <= max_val:
            max_val = top_val
        
        top_val -= 1
        n -= 1
        
        heapq.heappush(q, (-top_val, top_val))
    
    
    for data in q:
        answer += (data[1] ** 2)
        
    return answer