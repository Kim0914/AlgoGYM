def solution(s, n):
    answer = ''
    
    for i in range(len(s)):
        if s[i] == ' ':
            answer += s[i]
            continue
            
        else:
            n_s = ord(s[i]) + n
            
            if 'A' <= s[i] <= 'Z':
                if n_s > 90:
                    n_s -= 26
            
            if 'a' <= s[i] <= 'z':
                if n_s > 122:
                    n_s -= 26
                
            answer += chr(n_s)
                  
    return answer