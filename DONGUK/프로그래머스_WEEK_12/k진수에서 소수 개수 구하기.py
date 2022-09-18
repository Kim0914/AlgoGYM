import math

def isPrime(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True


def convert(num, base):
    tmp = '0123456789ABCDEF'
    q = num // base
    r = num % base

    ret_str = tmp[r]

    if q == 0:
        return tmp[r]

    while q > 0:
        r = q % base
        q = q // base
        ret_str += tmp[r]

    ret_str = ret_str[::-1]
    return ret_str


def solution(n, k):
    answer = 0
    ret = convert(n, k)

    ret = ret.split('0')
    
    for num in ret:
        if num == '1' or num == '0' or num == '':
            continue
        
        num = int(num)
        if isPrime(num):
            answer += 1
    
    return answer