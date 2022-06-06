def solution(n):
    nums = ['4', '1', '2']
    s = ''
    answer = 0
    while True:
        q = n // 3
        r = n % 3
        
        if r == 0:
            q = q - 1
            
        s = s + nums[r]
        
        n = q
        if q == 0:
            break
    
    answer = s[::-1]
    return answer

'''
1: 1
2: 2
3: 4 -> 1 0

4: 11 -> 1 1
5: 12
6: 14 -> 2 0

7: 21
8: 22
9: 24 -> 3 0

10: 41
11: 42
12: 44 -> 4 0

13: 111 4 1 ->  111
14: 112 4 2 -> 112
    
'''