from collections import deque

def solution(number, k):
    answer = deque()
    
    N = len(number) - k

    for num in number:
        if len(answer) == 0:
            answer.append(num)
            continue
        
        while answer and answer[-1] < num:
            if k <= 0:
                break
            
            answer.pop()
            k -= 1
        
        answer.append(num)
        
        
    while len(answer) > N:
        answer.pop()
        
    answer = "".join(answer)
            
    return answer