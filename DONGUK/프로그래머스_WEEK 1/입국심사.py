def solution(n, times):
    answer = 0
    
    start, end = 1, 1000000000000000000
    while start <= end:
        mid = (start + end) // 2
        
        cnt = 0
        for time in times:
            q = mid // time
            cnt += q
        
        if cnt >= n:
            answer = mid
            end = mid - 1
            
        else:
            start = mid + 1
            
    return answer