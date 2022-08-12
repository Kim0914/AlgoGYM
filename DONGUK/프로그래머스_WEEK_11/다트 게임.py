def solution(dartResult):
    answer = []
    
    i = 0
    prev_num = 0
    while i < len(dartResult):
        c = dartResult[i]
        
        if '0' <= dartResult[i+1] <= '9':
            c += dartResult[i+1]
            i += 1
        
        if '0' <= c[0] <= '9':
            tmp = ''
            i += 1
            while 'A' <= dartResult[i] <= 'Z' or dartResult[i] == '#' or  dartResult[i] == '*':
                tmp += dartResult[i]
                i += 1
                
                if i == len(dartResult):
                    break
            
            num = int(c)
            add = 0
            for j in range(len(tmp)):
                if tmp[j] == 'S':
                    add += (num)
                    
                elif tmp[j] == 'D':
                    add += (num ** 2)
                    
                elif tmp[j] == 'T':
                    add += (num ** 3)
                    
                elif tmp[j] == '*':
                    if i == 3:
                        add = add * 2
                    else:
                        answer[-1] = answer[-1] * 2
                        add = add * 2
                        
                elif tmp[j] == '#':
                    add = add * -1
                    
            answer.append(add)
    
    answer = sum(answer)
    return answer