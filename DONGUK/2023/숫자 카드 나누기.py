def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)


def solution(arrayA, arrayB):
    answer = 0
    
    a_gcd = arrayA[0]
    N = len(arrayA)
    for i in range(1, N):
        a_gcd = gcd(a_gcd, arrayA[i])
        
    b_gcd = arrayB[0]
    for i in range(1, N):
        b_gcd = gcd(b_gcd, arrayB[i])
    
    if a_gcd > 1:
        a_flag = True
        for num in arrayB:
            if num % a_gcd == 0:
                a_flag = False
                break

        if a_flag:
            answer = a_gcd
    
    if b_gcd > 1:
        b_flag = True
        for num in arrayA:
            if num % b_gcd == 0:
                b_flag = False
                break

        if b_flag:
            answer = max(answer, b_gcd)
    return answer