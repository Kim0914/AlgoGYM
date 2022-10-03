def solution(strings, n):
    answer = []
    
    strings.sort(key = lambda x: (x[n], x))
    
    answer = strings
    return answer