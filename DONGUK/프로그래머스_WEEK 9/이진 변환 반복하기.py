def solution(s):
    answer = []
    mod_cnt, zero_cnt = 0, 0
    
    while True:
        if s == '1':
            break
            
        tmp = ''
        for c in s:
            if c == '0':
                zero_cnt += 1
            else:
                tmp += c
        
        s = bin(len(tmp))[2:]
        mod_cnt += 1
    
    answer = [mod_cnt, zero_cnt]
    return answer