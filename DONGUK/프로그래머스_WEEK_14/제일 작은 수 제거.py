def solution(arr):
    answer = []
    if len(arr) == 1:
        answer.append(-1)
        
    else:
        min_v = min(arr)
        
        for a in arr:
            if a != min_v:
                answer.append(a)
    return answer