def solution(lottos, win_nums):
    answer = []
    rank = {6:1, 5:2, 4:3, 3:4, 2:5, 1:6, 0:6}
    high, low = 1, 6
    
    candidate = []
    wrong_cnt = 0
    for num in lottos:
        if num not in win_nums:
            candidate.append(num)
            
            if num != 0:
                wrong_cnt += 1
    
            
    N = len(candidate)
    if N == 0: # 다 맞는 경우
        high, low = 1, 1
        answer.append(high)
        answer.append(low)
    
    else:
        answer.append(rank[6-wrong_cnt])
        answer.append(rank[6-N])
    
    return answer