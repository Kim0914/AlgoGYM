def solution(numbers):
    answer = ''
    nums = []
    
    for num in numbers:
        nums.append(str(num))
    
    nums.sort(key = lambda x: x*3, reverse=True)    
    answer = str(int(''.join(nums)))
        
    return answer

