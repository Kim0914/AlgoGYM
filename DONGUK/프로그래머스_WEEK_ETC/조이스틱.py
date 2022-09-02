from collections import deque

def solution(name):
    answer = 0
    N = len(name)
    
    ind_list = []
    
    target = 'A' * N
    
    for i in range(N):
        if name[i] != target[i]:
            diff_a = abs(ord(name[i]) - ord(target[i]))
            diff_b = abs(ord('Z') - ord(name[i]) + 1)
            ind_list.append((i, min(diff_a, diff_b)))
        else:
            ind_list.append((i, 0))
        
    if not ind_list:
        return answer
    
    
    q = deque(ind_list)
    first = q.popleft()
    answer += first[1]
    
    flag = False
    while q:
        if flag == False:
            if q[0][1] == 0:
                q.popleft()
                flag = True
                
            else:
                answer += 1
                top = q.popleft()
                answer += top[1]
                
        
        else:
            if q[-1][1] == 0:
                q.pop()
                flag = False
                
            else:
                answer += 1
                bottom = q.pop()
                answer += bottom[1]
                
        
    return answer