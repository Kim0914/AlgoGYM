data = input().split('-')

nums = []
for s in data:
    nums.append(s.split('+'))

ans = 0

for i in range(len(nums)):
    for j in range(len(nums[i])):
        if i == 0:
            ans += int(nums[i][j])
        
        else:
            ans -= int(nums[i][j])

print(ans)
