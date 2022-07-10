def solution(brown, yellow):
    answer = []
    cnt = brown + yellow
    
    candidate = []
    for i in range(2, cnt):
        if cnt % i == 0:
            q = cnt // i
            r = cnt // q
            
            if q >= r:
                candidate.append((q, r))
    
    for data in candidate:
        garo, sero = data[0], data[1]
        
        sum_ = (garo * 2) + (sero - 2) * 2
        
        if sum_ == brown:
            answer = data
            break
    return answer


