N = int(input())

def isPrime(num):
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False

    return True

# 4000000 * 2000 = 8000000000 < 2초
nums = []
for i in range(2, N+1):
    if isPrime(i):
        nums.append(i)

sum_prime = [0] * (len(nums) + 1)
for i in range(len(nums)):
    sum_prime[i+1] = sum_prime[i] + nums[i] 



ans = 0
start, end = 0, 0
while end <= len(nums):
    tmp_sum = sum_prime[end] - sum_prime[start]
    
    if tmp_sum == N:
        ans += 1
        end += 1
    
    elif tmp_sum < N:
        end += 1
    
    else:
        start += 1
        
print(ans)