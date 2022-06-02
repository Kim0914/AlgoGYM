def solution(s):
    
    N = len(s)
    answer = N
    
    if N == 1:
        return 1
    
    

    for i in range(1, (N//2) + 1):
        cmp = s[:i]
        res = ''
        cnt = 1
        
        for j in range(i, N, i):
            if s[j:j+i] == cmp:
                cnt += 1
                
            else:
                if cnt == 1:
                    res += cmp
                
                else:
                    res += str(cnt) + cmp
                    
                cnt = 1
                cmp = s[j:j+i]
            
            
        if cnt == 1:
            res += cmp

        else:
            res = str(cnt) + res + cmp
            
            

        answer = min(answer, len(res))
        
    return answer