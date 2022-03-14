import sys
input = sys.stdin.readline

N = int(input())

nums = list(map(int, input().split()))
d = {}

set_nums = list(set(nums))
set_nums.sort()

for i in range(len(set_nums)):
    d[set_nums[i]] = i


for num in nums:
    print(d[num], end=' ')