from collections import deque

def minuteToHourSec(minute):
    hour = minute // 60
    sec = minute - (hour * 60)
    
    if hour < 10:
        hour = '0' + str(hour)
    
    if sec < 10:
        sec = '0' + str(sec)
    
    return str(hour) + ':' + str(sec)
    

def solution(n, t, m, timetable):
    answer = ''
    
    time_data = []
    bus_data = deque()
    for time in timetable:
        time = time.split(':')
        hour, minute = int(time[0]), int(time[1])
        time_data.append(hour*60 + minute)
    
    now = 540 # 09:00
    for _ in range(n):
        bus_data.append(now)
        now = now + t
    
    time_data.sort()
    
    max_cnt = m * len(bus_data)

    
    time_data = deque(time_data)
    if bus_data[-1] < time_data[0]:
        answer = minuteToHourSec(bus_data[-1])
    
    else:
        while bus_data:
            bus_time = bus_data.popleft()
            
            cnt = 0
            top = 0
            while time_data and bus_time >= time_data[0]:
                top = time_data.popleft()
                cnt += 1
                
                if cnt >= m:
                    break
            
            if not bus_data:
                if cnt == m:
                    answer = minuteToHourSec(top-1)
                else:
                    answer = minuteToHourSec(bus_time)
            
        
    return answer