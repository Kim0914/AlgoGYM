from itertools import permutations
from collections import deque

def init(expression):
    opers = deque()
    exp_list = deque()
    
    tmp = ''
    for s in expression:
        if s == '+' or s == '-' or s == '*':
            exp_list.append(int(tmp))
            exp_list.append(s)
            tmp = ''
            
            if s not in opers:
                opers.append(s)
        else:
            tmp += s
        
    exp_list.append(int(tmp))
    
    return opers, exp_list
    

def solution(expression):
    answer = 0
    
    opers, exp_list = init(expression)   
    
    oper_list = list(permutations(opers, len(opers)))
    
    val = []
    for oper in oper_list:
        cmp = deque(exp_list)
        
        for sign in oper:
            s = deque()
        
            while cmp:
                top = cmp.popleft()
                
                if top == sign: # 처리 할 부호가 나옴
                    oper1 = s.pop()
                    oper2 = cmp.popleft()
                    
                    if sign == '*':
                        s.append(oper1 * oper2)
                    elif sign == '+':
                        s.append(oper1 + oper2)
                    elif sign == '-':
                        s.append(oper1 - oper2)
                
                else:
                    s.append(top)        
    
            cmp = s
            
            if len(s) == 1:
                val.append(abs(s.popleft()))
                
    answer = max(val)
    return answer