import heapq
def solution(lines):
    answer = 0
    time_data = []
    for line in lines:
        line = line.split(' ')
        
        end_time = line[1] # 시간
        response_time = float(line[2][:-1]) # 처리시간
    
        
        end_time = end_time.split(':')
        
        hour, minute, sec = int(end_time[0]), int(end_time[1]), float(end_time[2])
        
        time = (hour * 3600.0) + (minute * 60.0) + sec
        
        time_data.append((time - response_time + 0.001, time)) # 시작시간, 완료시간
    
    time_data.sort()
    
    q = []
    for data in time_data:
        start, end = data[0], data[1]
        
        while q:
            now_min_end = q[0][1][1]
            if start - 1 >= now_min_end:
                heapq.heappop(q)
            
            else:
                break
        
        heapq.heappush(q, (end, data))
        answer = max(answer, len(q))
        
    return answer