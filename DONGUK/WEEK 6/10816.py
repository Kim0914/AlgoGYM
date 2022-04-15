n = int(input())
nums = list(map(int, input().split()))
nums.sort()

d = {}

for num in nums:
    if num not in d:
        d[num] = 1
    
    else:
        d[num] += 1

m = int(input())
cards = list(map(int, input().split()))

ans = []
for card in cards:
    start, end = 0, n-1
    cnt = 0

    while start <= end:
        mid = (start + end) // 2

        if nums[mid] == card:
            cnt = d[card]
            break
            
            
        elif nums[mid] < card:
            start = mid + 1

        else:
            end = mid - 1
    ans.append(cnt)

print(*ans)
