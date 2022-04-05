def check(s):
    if len(s) == 0:
        return True
    
    stack = []
    for i in range(len(s)):
        if s[i] == '(' or s[i] == '[':
            stack.append(s[i])
        
        else:
            if len(stack) == 0:
                return False

            top = stack.pop()
            if s[i] == ')':
                if top!= '(':
                    return False
            
            elif s[i] == ']':
                if top != '[':
                    return False
    
    if len(stack) > 0:
        return False
    
    else:
        return True

                


while True:
    s = list(input())
    
    if s[0] == '.':
        break
    
    param = ''
    for i in range(len(s)):
        if s[i] == '(' or s[i] == ')' or s[i] == '[' or s[i] == ']':
            param += s[i]


    if check(param):
        print('yes')

    else:
        print('no')
