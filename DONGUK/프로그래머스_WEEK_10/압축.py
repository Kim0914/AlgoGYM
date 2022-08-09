from collections import deque

def solution(msg):
    answer = []
    d = {}
    for i in range(1, 27):
        d[chr(i + 64)] = i 
    
    msg = deque(msg)
    ind = 27
    while msg:
        top = msg.popleft()
        
        w = top
        if msg:
            while msg and w + msg[0] in d:
                next_top = msg.popleft()
                w += next_top
            
            answer.append(d[w])
            
            if msg:
                d[w+msg[0]] = ind
                ind += 1
        
        else:
            answer.append(d[w])
        
    return answer