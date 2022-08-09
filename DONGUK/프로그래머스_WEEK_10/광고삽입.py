from collections import deque

MIN_TIME = 0
MAX_TIME = 360000

def getSecByTime(time):
    time = time.split(':')
    time_sec = int(time[0])*3600 + int(time[1])*60 + int(time[2])
    
    return time_sec


def getTimeBySec(sec):
    h = sec // 3600
    h = '0' + str(h) if h < 10 else str(h)
    sec = sec % 3600
    
    m = sec // 60
    m = '0' + str(m) if m < 10 else str(m)
    sec = sec % 60
    
    s = '0' + str(sec) if sec < 10 else str(sec)
    return h + ':' + m + ':' + s
    

    
def solution(play_time, adv_time, logs):
    answer = ''
    
    dp = [0] * MAX_TIME
    
    if play_time == adv_time:
        return "00:00:00"
    
    play_time = getSecByTime(play_time)
    adv_time = getSecByTime(adv_time)
    
    
    for log in logs:
        data = log.split('-')
        start, end = getSecByTime(data[0]), getSecByTime(data[1])
        dp[start] += 1
        dp[end] -= 1
    
    # ex) 1 -> 6초 까지 시청했다고 체크, end time은 시청 X
    # 1 0 0 0 0 -1
    # 1 1 1 1 1 0
    for i in range(1, MAX_TIME):
        dp[i] = dp[i] + dp[i-1]
        
    
    # 누적 시청자
    for i in range(1, MAX_TIME):
        dp[i] = dp[i] + dp[i-1]
    
    
    max_cnt, time = 0, 0
    for now in range(adv_time-1, play_time):
        if now >= adv_time:
            if max_cnt < dp[now] - dp[now - adv_time]:
                max_cnt = dp[now] - dp[now - adv_time]
                time = now - adv_time + 1
        
        else:
            if max_cnt < dp[now]:
                max_cnt = dp[now]
                time = now - adv_time + 1
    

    answer = getTimeBySec(time)
    return answer