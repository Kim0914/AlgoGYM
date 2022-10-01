from collections import deque
import math

def solution(n, stations, w):
    answer = 0
    
    stations = deque(stations)
    wide = 2 * w + 1
    start = 1
    while stations:
        now = stations.popleft()
        end = now - w
        
        if start < end:
            before = end - start
            answer += math.ceil(before / wide)
            
        start = now + w + 1
    
    if start <= n:
        before = n - (now + w)
        answer += math.ceil(before / wide)
        
    return answer