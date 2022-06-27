def solution(n, lost, reserve):
    answer = 0
    
    new_lost = []
    for num in lost:
        if num in reserve:
            reserve.remove(num)
        else:
            new_lost.append(num)
    
    new_lost.sort()
    reserve.sort()
    
    answer = n - len(new_lost)
    
    while reserve:
        top = reserve.pop(0)
    
        if top-1 in new_lost:
            new_lost.remove(top-1)
            answer += 1
        
        elif top+1 in new_lost:
            new_lost.remove(top+1)
            answer += 1
    
    return answer