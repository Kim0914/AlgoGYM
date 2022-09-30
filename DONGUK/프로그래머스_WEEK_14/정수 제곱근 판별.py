def solution(n):
    answer = 0
    
    a = str(n ** (1/2))
    
    a = a.split('.')
    b = a[1]
    
    if len(b) == 1 and b == '0':
        answer = (int(a[0]) + 1) ** 2
    else:
        answer = -1
    
    return answer