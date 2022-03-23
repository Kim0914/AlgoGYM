import sys
input = sys.stdin.readline

n = int(input())

nums = list(map(int, input().split()))

ans = []
for i in range(n):
    val = nums[i]
    cnt = 1
    for j in range(i+1, n):
        if nums[j] > val:
            cnt += 1
            val = nums[j]

    ans.append(cnt)

print(max(ans))

'''
10 20 10 30 20 50
'''