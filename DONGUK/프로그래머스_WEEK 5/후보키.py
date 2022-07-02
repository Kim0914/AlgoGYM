from itertools import combinations

def solution(relation):
    answer = 0
    row = len(relation)
    col = len(relation[0])
    
    target = [i for i in range(col)]
    
    
    candidate = []
    for i in range(1, col+1):
        for comb in list(combinations(target, i)):
            flag = True
            check = []
            
            for rel in relation:
                temp = []
                for key in comb:
                    temp.append(rel[key])
                    
                if temp in check: # 중복 확인
                    flag = False
                    break
                    
                else:
                    check.append(temp)
            
            
            if flag:
                # 최소성 체크
                currKey = ''.join(map(str,comb))
                minimality = True
                
            
                for existKey in candidate:
                    count = len(existKey)
                    for ek in existKey:
                        for ck in currKey:
                            if ek == ck:
                                count -= 1
                    # 다 겹치면 X
                    if count == 0:
                        minimality = False
                        break
                        
                if minimality:
                    candidate.append(currKey)
                        
    answer = len(candidate)
    return answer