from itertools import permutations

def solution(k, dungeons):
    answer = 0
    
    N = len(dungeons)
    
    orders = [i for i in range(1, N+1)]
    
    perm_orders = list(permutations(orders, N))
    
    for order in perm_orders:
        now_hp = k
        cnt = 0
        for ind in order:
            req_hp, lose_hp = dungeons[ind-1][0], dungeons[ind-1][1]
            
            if now_hp >= req_hp:
                cnt += 1
                now_hp -= lose_hp
                
            else:
                break
                
        answer = max(answer, cnt)
        
    return answer