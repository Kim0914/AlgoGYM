def solution(a, b):
    answer = ''
    
    DAYS = ["SUN","MON","TUE","WED","THU","FRI","SAT"]
    
    cal = [[] for _ in range(13)]
    
    ind = 5
    for i in range(1, 13):
        if i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12:
            for _ in range(31):
                cal[i].append(DAYS[ind])
                ind += 1
                if ind > 6:
                    ind= ind % 7
                
        elif i == 2:
            for _ in range(29):
                cal[i].append(DAYS[ind])
                ind += 1
                if ind > 6:
                    ind = ind % 7
                
        else:
            for _ in range(30):
                cal[i].append(DAYS[ind])
                ind += 1
                if ind > 6:
                    ind = ind % 7
        
    answer = cal[a][b-1]
    return answer