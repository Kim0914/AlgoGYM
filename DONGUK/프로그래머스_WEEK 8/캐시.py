from collections import deque

def solution(cacheSize, cities):
    answer = 0
    cache = deque()
    
    if cacheSize == 0:
        answer = len(cities) * 5
        return answer
    
    for city in cities:
        city = city.lower()
        if city not in cache:
            answer += 5
            
            if len(cache) < cacheSize:
                cache.append(city)
            
            else:
                cache.popleft()
                cache.append(city)
            
            
        else:
            answer += 1
            
            cache.remove(city)
            cache.append(city)
    
    
    return answer