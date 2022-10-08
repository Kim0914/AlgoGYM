def solution(X, Y):
    answer = ''
    d = {}
    
    x_list = list(X)
    y_list = list(Y)
    for i in range(10):
        cnt_x, cnt_y = 0, 0
        if str(i) in x_list:
            cnt_x = x_list.count(str(i))
            
        
        if str(i) in y_list:
            cnt_y = y_list.count(str(i))
            
            
        d[i] = min(cnt_x, cnt_y)
    
    zero_flag = True
    candidate = []
    for key, value in d.items():
        if value > 0:
            if key != 0:
                zero_flag = False
                
            for _ in range(value):
                candidate.append(key)
                
    candidate.sort(reverse = True)
    
    if not candidate:
        answer = '-1'
        
    else:
        if zero_flag:
            answer = '0'
            
        else:
            for num in candidate:
                answer += str(num)
    return answer