from collections import deque

def solution(s):
    answer = -1
    
    if len(s) == 1:
        return 0
    
    q = []
    
    for i in range(len(s)):
        if i == 0:
            q.append(s[0])
        
        else:
            if len(q) == 0:
                q.append(s[i])
                continue
                
            if s[i] == q[-1]:
                q.pop()
            
            else:
                q.append(s[i])
                
    if q:
        answer = 0
    else:
        answer = 1
    return answer