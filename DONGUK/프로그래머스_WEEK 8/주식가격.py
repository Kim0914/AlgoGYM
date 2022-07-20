def solution(prices):
    answer = []
    
    N = len(prices)
    
    for i in range(N):
        cnt = 0
        for j in range(i+1, N):
            if prices[i] > prices[j]:
                cnt += 1
                break
                
            else:
                cnt += 1
        answer.append(cnt)
        
    return answer