def check(li):
    stack = []

    for data in li:
        if data == '(': 
            stack.append(data)

        else: 
            if len(stack) == 0:
                return False
            
            stack.pop()
            
    
    if len(stack) == 0:
        return True
    
    else:
        return False
            
        

def solution(s):
    answer = check(s)
    return answer