from collections import deque

def solution(queue1, queue2):
    answer = 0
    
    N = len(queue1)
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    
    if (sum(queue1) + sum(queue2)) % 2 == 1:
        return -1
    
    sum_1 = sum(queue1)
    sum_2 = sum(queue2)
    while True:
        
        if sum_1 == sum_2:
            break
        
        elif sum_1 > sum_2:
            top = queue1.popleft()
            queue2.append(top)
            sum_1 -= top
            sum_2 += top
        
        else:
            top = queue2.popleft()
            queue1.append(top)
            sum_1 += top
            sum_2 -= top
        
        answer += 1
        
        if answer >= 3*N:
            answer = -1
            break
        
    return answer