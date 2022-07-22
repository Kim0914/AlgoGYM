from collections import deque

def solution(people, limit):
    answer = 0
    people.sort()
    
    q = deque(people)
    
    while q:
        top = q[0]
        
        if top + q[-1] <= limit:
            if q:
                q.popleft()
            if q:
                q.pop()
            answer += 1
            
        else:
            if q:
                q.pop()
                answer += 1
            
    return answer