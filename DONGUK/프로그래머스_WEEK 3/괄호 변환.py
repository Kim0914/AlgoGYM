from collections import deque

def retUV(p):
    u, v = '', ''
    N = len(p)
    
    q = deque()
    open_cnt, close_cnt = 0, 0
    for i in range(N):
        if p[i] == '(':
            open_cnt += 1
        else:
            close_cnt += 1
            
        u += p[i]
        
        if (open_cnt > 0) and (close_cnt > 0) and (open_cnt == close_cnt):
            break
    
    if i != N-1:
        v = p[i+1:]
        
    return u, v

def check(p):
    q = deque()
    
    N = len(p)
    for i in range(N):
        if p[i] == '(':
            q.append(p[i])
        
        else:
            if len(q) == 0:
                return False
                
            else:
                top = q.pop()
                
                if top != '(':
                    return False
    return True


def search(p):
    if len(p) == 0:
        return ''

    else:
        u, v = retUV(p)
        if check(u):
            return u + search(v)

        else:
            tmp = '('
            tmp += search(v)
            tmp += ')'

            u_list = deque(u)
            
            u_list.popleft()
            u_list.pop()
            
            if len(u_list):
                for data in u_list:
                    if data == '(':
                        tmp += ')'
                    else:
                        tmp += '('

            return tmp
    
def solution(p):
    if check(p):
        answer = p
        
    else:
        answer = search(p)
    return answer