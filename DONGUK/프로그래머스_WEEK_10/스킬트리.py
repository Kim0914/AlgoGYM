from collections import deque

def solution(skill, skill_trees):
    answer = 0
    d = {}
    
    for i in range(len(skill)):
        d[skill[i]] = i
    
    for skill in skill_trees:
        s_ind = []
        
        for i in range(len(skill)):
            if skill[i] in d:
                s_ind.append(d[skill[i]])
            
        
        flag = True
        store = []
        for ind in s_ind:
            if ind == 0:
                store.append(ind)
            
            else:
                if len(store) == 0 or store[-1] != ind-1:
                    flag = False
                    break
                    
                else:
                    store.append(ind)
        
        if flag:
            answer += 1
        
    return answer