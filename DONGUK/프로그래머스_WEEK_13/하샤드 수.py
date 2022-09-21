def solution(x):
    answer = False
    str_x = list(str(x))
    
    sum_ = 0
    for s in str_x:
        sum_ += int(s)
    
    if x % sum_ == 0:
        answer = True
        
    return answer