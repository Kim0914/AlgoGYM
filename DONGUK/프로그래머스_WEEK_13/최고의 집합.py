def solution(n, s):
    answer = []
    
    q = s // n
    r = s % n
    
    if q == 0:
        answer.append(-1)
    else:
        for _ in range(n-r):
            answer.append(q)
            
        for _ in range(r):
            answer.append(q+1)
        
    
    return answer