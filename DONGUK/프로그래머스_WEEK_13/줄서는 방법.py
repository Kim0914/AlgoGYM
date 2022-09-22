flag = False
cnt = 0

def bt(data, numbers, location):
    global flag, cnt
    
    if len(data) == len(numbers):
        cnt += 1
        
        if cnt == location:
            flag = True
            
        return
    
    for i in range(len(numbers)):
        
        if numbers[i] not in data:
            data.append(numbers[i])
            bt(data, numbers, location)
            if flag:
                break
            data.pop()
    
    return data

def factorial(n):
    ret = 1
    
    for i in range(n, 0, -1):
        ret = ret * i
    
    return ret


def solution(n, k):
    
    numbers = [i for i in range(1, n+1)]
    
    diff = factorial(n-1)
    
    start_num = (k // diff) + 1
    location = k % diff
    
    data = [start_num]
    answer = bt(data, numbers, location)
    
    return answer