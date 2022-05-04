import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
nums.sort()

start, end = 0, n-1


max_val = 2000000000
while start < end:
    val = nums[start] + nums[end]

    abs_val = abs(nums[start] + nums[end])
    if abs_val < max_val:
        x, y = nums[start], nums[end]
        max_val = abs_val
    
    if val < 0:
        start += 1
    
    else: 
        end -= 1

print(x, y)