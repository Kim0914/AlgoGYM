def solution(s):
    answer = True
    
    if len(s) != 4 and len(s) != 6:
        return False
    
    for i in range(len(s)):
        if '0' <= s[i] <= '9':
            continue
            
        else:
            return False
        
    return answer