def solution(s):
    answer = ''
    s = s.lower()
    
    tmp = ''
    for i in range(len(s)):
        if s[i] == ' ':
            answer += tmp
            answer += ' '
            tmp = ''
            
        else:
            if not tmp and 'a' <= s[i] <= 'z':
                tmp += s[i].upper()
            else:
                tmp += s[i]
    
        
        if i == len(s)-1:
            answer += tmp
    return answer