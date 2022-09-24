def solution(stones, k):
    answer = 0
    
    N = len(stones)
    
    start = 0
    end = max(stones)
    
    while start <= end:
        mid = (start + end) // 2
        
        dis = 0
        flag = True
        for i in range(N):
            if stones[i] < mid:
                dis += 1
                
                if dis >= k:
                    break
            
            else:
                if dis >= k:
                    break
                    
                else:
                    dis = 0
            
            
        if dis >= k:
            flag = False
            
        if flag:
            start = mid + 1
            answer = mid
            
        else:
            end = mid - 1
            
    return answer