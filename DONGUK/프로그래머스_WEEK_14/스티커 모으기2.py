def solution(sticker):
    answer = 0
    
    N = len(sticker)
    if N == 1:
        return sticker[0]
    
    dp_one = [0] * N
    dp_two = [0] * N
    
    for i in range(N-1): # 첫번재 컷 할때
        if i == 0:
            dp_one[i] = sticker[i]
        
        else:
            dp_one[i] = max(dp_one[i-2] + sticker[i], dp_one[i-1])
            
    
    for i in range(N):# 첫번재 컷 안함
        if i == 0:
            dp_two[i] = 0
            
        elif i == 1:
            dp_two[i] = sticker[i]
        
        else:
            dp_two[i] = max(dp_two[i-2] + sticker[i], dp_two[i-1])
    
    
    answer = max(dp_one[-2], dp_two[-1])
    
    
    return answer