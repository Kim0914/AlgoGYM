def three(n):
    ret = ''
    
    while n >= 1:
        q = n // 3
        r = n % 3
        ret += str(r)
        n = q
    
    return ret

def solution(n):
    answer = 0
    ret_str = three(n)
    
    mul = 0
    for i in range(len(ret_str)-1, -1, -1):
        if ret_str[i] != '0':
            answer += int(ret_str[i]) * (3 ** mul)
        mul += 1
    
    return answer