import copy

maxDiff = 0
candidates = []

def caclResult(apeach, ryan):
    apeach_score = 0
    ryan_score = 0
    for i in range(11):
        score = 10 - i
        if apeach[i] == 0 and ryan[i] == 0:
            continue
            
        if apeach[i] >= ryan[i]:
            apeach_score += score
        
        else:
            ryan_score += score
        
    return ryan_score - apeach_score


def dfs(ryan, i, info, n):
    global maxDiff, candidates
    
    if i == 11:
        if n > 0:
            ryan[i-1] = n
        diff = caclResult(info, ryan)
        if diff <= 0:
            return
        
        res = copy.deepcopy(ryan)
        if maxDiff < diff:
            maxDiff = diff
            candidates = [res]
            return
        
        if maxDiff == diff:
            candidates.append(res)
            
        return
    
    if info[i] < n:
        ryan.append(info[i] + 1)
        dfs(ryan, i+1, info, n-info[i]-1)
        ryan.pop()
    
    ryan.append(0)
    dfs(ryan, i+1, info, n)
    ryan.pop()
    

def solution(n, info):
    answer = []
    
    dfs([], 0, info, n)
        
    if not candidates:
        answer.append(-1)
    else:
        candidates.sort(key=lambda x: x[::-1], reverse=True)
        answer = candidates[0]
        
    return answer