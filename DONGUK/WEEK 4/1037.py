n = int(input())

nums = list(map(int, input().split()))

nums.sort()

ans = 0
if len(nums) == 1:
    ans = nums[0] * nums[0]

else:
    ans  = nums[0] * nums[-1]

print(ans)