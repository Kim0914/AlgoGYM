from itertools import permutations

def isPrime(n):
    if n == 0 or n == 1:
        return False
    
    for i in range(2, n):
        if n % i == 0:
            return False
    
    return True


def solution(numbers):
    answer = []
    
    nums = list(map(int, numbers))
    
    for num in nums:
        if isPrime(num) and num not in answer:
            answer.append(num)
            
    
    nums = list(map(str, numbers))
    for i in range(2, len(nums) + 1):
        data_list = list(permutations(nums, i))
        for data in data_list:
            num = int(''.join(data))
            
            if num not in answer and isPrime(num):
                answer.append(num)
                
    answer = len(answer)
    return answer