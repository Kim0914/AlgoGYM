from collections import deque

def solution(routes):
    answer = 0
    routes.sort(key = lambda x: (x[1], x[0]))
    
    q = deque(routes)
    
    while q:
        top = q.popleft()
        cur_start, cur_end = top[0], top[1]
        answer += 1
        
        while q and cur_end >= q[0][0]:
            q.popleft()
                
    return answer