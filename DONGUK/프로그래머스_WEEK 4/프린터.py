from collections import deque

def solution(priorities, location):
    q = deque()
    for i in range(len(priorities)):
        q.append((i, priorities[i]))
    
    answer = 1
    while q:
        ind, prior = q.popleft()
        
        flag = True
        for i in range(len(q)):
            if prior < q[i][1]:
                q.append((ind, prior))
                flag = False
                break
        
        # 우선순위가 젤 높으면
        if flag:
            if ind == location:
                break
            else:
                answer += 1
                
    return answer