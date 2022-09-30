def solution(s):
    s = s.lower()
    p_cnt, y_cnt = 0, 0
    
    for i in range(len(s)):
        if s[i] == 'p':
            p_cnt += 1
        elif s[i] == 'y':
            y_cnt += 1
    
    if p_cnt == y_cnt:
        return True
    else:
        return False