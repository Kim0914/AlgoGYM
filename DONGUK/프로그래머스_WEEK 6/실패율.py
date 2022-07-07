def solution(N, stages):
    answer = []
    stages.sort()
    
    d = {}
    for i in range(1, N+1):
        d[i] = 0
    
    for stage in stages:
        if stage == N+1:
            continue
            
        d[stage] += 1
    
    
    people = len(stages)
    for i in range(1, N+1):
        num = d[i]
        if num == 0:
            continue
            
        d[i] = (num / people)
        people -= num
    
    sorted_dict = sorted(d.items(), key = lambda x: x[1], reverse=True)
    
    for data in sorted_dict:
        answer.append(data[0])
        
    return answer