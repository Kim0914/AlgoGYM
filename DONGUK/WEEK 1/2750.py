N = int(input())
nums = []

for _ in range(N):
    nums.append(int(input()))

nums = sorted(nums)

for num in nums:
    print(num)