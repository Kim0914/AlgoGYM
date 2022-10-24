from collections import deque

def solution(topping):
    answer = 0
    
    N = len(topping)
    left_dict = {}
    right_dict = {}
    
    right = deque(topping)
    for num in right:
        if num not in right_dict:
            right_dict[num] = 1
        else:
            right_dict[num] += 1
    
    left_cnt = 0
    right_cnt = len(right_dict)
    for _ in range(N-1):
        top = right.popleft()
        
        right_dict[top] -= 1
        
        if right_dict[top] == 0:
            right_cnt -= 1
        
        if top not in left_dict:
            left_dict[top] = 1
            left_cnt += 1
        
        if left_cnt == right_cnt:
            answer += 1
        
    return answer