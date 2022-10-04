def solution(s):
    answer = ''
    
    cnt = 0
    for i in range(len(s)):
        if s[i] == ' ':
            answer += ' '
            cnt = 0
            continue
        
        if cnt % 2 == 1:
            c = s[i].lower()
            answer += c
            
        else:
            c = s[i].upper()
            answer += c
        
        cnt += 1
            
    return answer