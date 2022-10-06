import math
from itertools import combinations

def isPrime(x):
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False 
        
    return True 


def solution(nums):
    answer = 0

    comb_list = list(combinations(nums, 3))
    
    ans_list = []
    
    for data in comb_list:
        if isPrime(sum(data)):
            answer += 1
            
    
    return answer