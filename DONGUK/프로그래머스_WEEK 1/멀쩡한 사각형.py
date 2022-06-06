import math

def solution(w,h):
    # 최대 공약수 계산
    gcd = math.gcd(w,h)
    sub = 0
    if gcd == 1:
        sub = w+h-1
    
    else:
        sub = w+h - gcd
    
    answer = w*h - sub
    return answer