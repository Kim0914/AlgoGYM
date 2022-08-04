from collections import deque

def solution(n, arr1, arr2):
    answer = []
    
    for i in range(len(arr1)):
        bin_arr1 = deque(bin(arr1[i])[2:])
        bin_arr2 = deque(bin(arr2[i])[2:])
        
        while len(bin_arr1) < n:
            bin_arr1.appendleft('0')
        
        while len(bin_arr2) < n:
            bin_arr2.appendleft('0')
        
        input_str = ''
        for j in range(n):
            if bin_arr1[j] == '0' and bin_arr2[j] == '0':
                input_str += ' '
            else:
                input_str += '#'
        answer.append(input_str)
    return answer