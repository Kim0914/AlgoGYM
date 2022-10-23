def solution(elements):
    answer = 0
    
    result = {}
    
    N = len(elements)
    
    elements = elements * 2
    for i in range(N):
        for j in range(N):
            part_sum = sum(elements[j:j+i+1])
            
            if part_sum not in result:
                result[part_sum] = 1
                
    answer = len(result)
    return answer