from collections import deque

def solution(numbers):
    answer = []
    
    for num in numbers:
        bin_num = deque(bin(num)[2:])
        bin_num.appendleft('0')
        
        N = len(bin_num)
        ind = 0
        for i in range(N-1, -1, -1):
            if bin_num[i] == '0':
                ind = i
                break
        
        if bin_num[-1] == '0':
            answer.append(num+1)
        
        
        else:
            bin_num[ind] = '1'
            bin_num[ind+1] = '0'
            
            j = 0
            res = 0
            for i in range(N-1, -1, -1):
                if bin_num[i] == '1':
                    res += 2**j
                j+=1
            answer.append(res)
            
    return answer

