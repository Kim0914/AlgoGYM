def solution(nums):
    answer = 0
    d = {}
    
    for num in nums:
        if num not in d:
            d[num] = 1
        else:
            d[num] += 1
    
    if len(d) <= len(nums) // 2:
        answer = len(d)
    
    else:
        answer = len(nums) // 2 
        
    return answer