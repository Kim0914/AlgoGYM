def check(s):
    stack = []

    for i in range(len(s)):
        if s[i] == ')':
            if len(stack) == 0:
                return False
            
            else:
                stack.pop()

        
        else:
            stack.append(s[i])

    if len(stack) > 0:
        return False

    else:
        return True


n = int(input())

for _ in range(n):
    s = input()

    if check(s):
        print('YES')
    
    else:
        print('NO')