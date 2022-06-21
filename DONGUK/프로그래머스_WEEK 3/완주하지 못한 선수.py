def solution(participant, completion):
    answer = ''
    
    d = {}
    
    for human in completion:
        if human not in d:
            d[human] = 1
        
        else:
            d[human] += 1
    
    
    for human in participant:
        if human not in d:
            answer = human
            break
            
        if d[human] > 0:
            d[human] -= 1
        
        else:
            answer = human
            break
    
    return answer