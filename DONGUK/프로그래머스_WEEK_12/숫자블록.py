import math

def isPrime(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True

def solution(begin, end):
    answer = []
        
    for num in range(begin, end+1):
        q = 0
        
        if num == 1:
            answer.append(0)
            continue
        
        if isPrime(num):
            answer.append(1)
            continue
            
        else:
            for i in range(2, int(num ** 0.5)+1):
                if num % i == 0:
                    q = num // i
                    
                    if q > 10000000:
                        q = 1
                        continue
                    
                    else:
                        break
                         
            answer.append(q)
            
    return answer

