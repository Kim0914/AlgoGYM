from collections import deque

def check(li):
    
    stack = []
    
    for i in range(len(li)):
        top = li[i]
        
        if top == '(' or top == '{' or top == '[':
            stack.append(top)
            
        else:
            if len(stack) == 0:
                return False
            
            stack_top = stack.pop()
            if top == ')':
                if stack_top != '(':
                    return False
            elif top == '}':
                if stack_top != '{':
                    return False
            
            else:
                if stack_top != '[':
                    return False
        
    return True
    

def solution(s):
    answer = 0
    
    if len(s) % 2 == 1:
        return answer
    
    if check(s):
        answer += 1
    
    for _ in range(len(s) - 1):
        top = s[0]
        s = s[1::]
        s += top

        if check(s):
            answer += 1
        
    return answer
