from collections import deque
import heapq

def solution(jobs):
    answer = 0
    
    jobs.sort(key=lambda x: (x[0], x[1]))
    
    q = deque(jobs)
    time = q[0][0]
    
    wait = []
    first = q.popleft()
    heapq.heappush(wait, (first[1], first[0]))
    
    
    while wait:
        
        top = heapq.heappop(wait)
        process_time, request_time = top[0], top[1]
        
        cnt = 0
        while cnt < process_time:
            if q and q[0][0] <= time+1: 
                head = q.popleft()
                heapq.heappush(wait, (head[1], head[0]))
            
            cnt += 1
            time += 1
        
        answer += (time - request_time)    
        
        if len(wait) == 0 and len(q) > 0:
            head = q.popleft()
            time = head[0]
            heapq.heappush(wait, (head[1], head[0]))
        
    
    answer = answer // len(jobs)
    return answer