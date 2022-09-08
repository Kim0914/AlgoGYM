def solution(arr):
    answer = 0
    
    num = max(arr)
    while True:
        flag = True
        for i in range(len(arr)):
            if num % arr[i] != 0:
                flag = False
                break
        
        if flag:
            answer = num
            break
        
        num += 1
        
    return answer