import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

candidate = []
for i in range(n):
    if len(candidate) == 0:
        candidate.append(nums[i])
    
    else:
        num = nums[i]
        
        for j in range(len(candidate)):
            diff = abs(num - candidate[j])
            add = num + candidate[j]

            candidate.append(num)
            candidate.append(diff)
            candidate.append(add)
    
    candidate = list(set(candidate))
    


t = int(input())
test = list(map(int, input().split()))

ans = []
for tc in test:
    if tc in candidate:
        ans.append('Y')
    
    else:
        ans.append('N')

print(*ans)