def solution(n):
    ans = 0

    while True:
        if n == 1:
            ans += 1
            break
            
        else:
            if n%2 == 0:
                n = n / 2
            
            else:
                ans += 1
                n = (n-1) / 2

    return ans