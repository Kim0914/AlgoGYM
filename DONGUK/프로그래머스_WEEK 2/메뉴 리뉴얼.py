from itertools import combinations

def solution(orders, course):
    answer = []
    
    for num in course:
        dic = {}
        
        for order in orders: # 주문 탐색
            if len(order) < num:
                continue
            
            comb_list = list(combinations(order, num)) # 주문에서 coure 개수만큼 조합 뽑기
            
            for comb in comb_list:
                res = "".join(comb)
                
                if res in dic:
                    continue
                
                
                for order_cmp in orders:
                    flag = True
                    for c in comb:
                        if c not in order_cmp:
                            flag = False
                            break
                    
                    if flag:
                        if res not in dic:
                            dic[res] = 1

                        else:
                            dic[res] += 1
        
        dic = sorted(dic.items(), key=lambda x: x[1], reverse = True)
        
        if len(dic) == 0:
            continue
        
        else:
            max_val = dic[0][1]
            if max_val == 1:
                continue
                
            for d in dic:
                if d[1] == max_val: # xw, wx와 같은 같은 원소가 포함된 문자열 걸러줌
                    ch_list = list(d[0])
                    ch_list.sort()
                    cmp = "".join(ch_list)
                    
                    if cmp not in answer:
                        answer.append(cmp)
                else:
                    break
        
    answer.sort()
    return answer