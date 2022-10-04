def solution(a):
    answer = 0
    MAX = 1000000001
    ballons = {}
    
    left_min = MAX
    N = len(a)
    for i in range(N):
        if i == 0:
            left_min = a[i]
            ballons[a[i]] = 1
            continue
        
        if i == N-1:
            ballons[a[i]] = 1
            continue
        
        
        if a[i] < left_min:
            ballons[a[i]] = 1
            left_min = a[i]
    
    
    right_min = a[-1]
    for i in range(N-2, -1, -1):
        if a[i] < right_min:
            right_min = a[i]
            
            if a[i] not in ballons:
                ballons[a[i]] = 1
                
    answer = len(ballons)
    
    return answer

