from collections import deque

def solution(numbers, target):
    answer = 0
     
    q = deque()
    q.append((0, 0))
    
    while q:
        top = q.popleft()
        sum_, index = top[0], top[1]
        
        if index <= len(numbers) - 1:
            q.append((sum_ + numbers[index], index + 1))
            q.append((sum_ - numbers[index], index + 1))
        
        if index == len(numbers):
            if sum_ == target:
                answer += 1
        
    return answer