def solution(n, m):
    answer = []
    
    N = min(n, m)
    
    gcd = 1
    q1, q2 = 1, 1
    for i in range(1, N+1):
        if n % i == 0 and m % i == 0:
            gcd = i
            q1 = n // i
            q2 = m // i
    
    answer.append(gcd)
    answer.append(gcd * q1 * q2)
    return answer