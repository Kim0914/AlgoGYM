visited = [[0] * 10 for _ in range(10)]
cmp = []
result = []

def dfs(ind, candidate):
    if ind == len(candidate):
        data = list(cmp)
        data.sort()
        
        if data not in result:
            result.append(data)
        return
    
    for i in range(len(candidate[ind])):
        if visited[ind][i] == 0:
            if candidate[ind][i] in cmp:
                continue
                
            visited[ind][i] = 1
            cmp.append(candidate[ind][i])
            
            dfs(ind+1, candidate)
            
            cmp.pop()
            visited[ind][i] = 0
    
    
    
def solution(user_id, banned_id):
    answer = 0
    
    d = {}
    
    for pattern in banned_id:
        d[pattern] = []
        
        for user in user_id:
            if len(user) != len(pattern):
                continue
            
            flag = True
            for i in range(len(user)):
                if user[i] != pattern[i]:
                    if pattern[i] == '*':
                        continue
                    else:
                        flag = False
                        break
                
            if flag:
                d[pattern].append(user)
    
    candidate = []
    for pattern in banned_id:
        candidate.append(d[pattern])
    
    
    dfs(0, candidate)
    
    answer = len(result)
    return answer