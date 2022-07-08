def solution(citations):
    answer = 0
    citations.sort()
    
    N = len(citations)
    
    
    for i in range(N):
        if citations[i] >= N - i:
            answer = N - i
            break
    
    return answer