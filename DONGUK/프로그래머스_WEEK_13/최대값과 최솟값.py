def solution(s):
    answer = ''
    nums = s.split()
    
    for i in range(len(nums)):
        nums[i] = int(nums[i])
    
    nums = sorted(nums)
    
    answer += str(nums[0])
    answer += ' '
    answer += str(nums[-1])
    return answer