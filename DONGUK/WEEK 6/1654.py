import sys
input = sys.stdin.readline

n, k = map(int, input().split())

nums = []
for _ in range(n):
    nums.append(int(input()))

nums.sort()

left, right = 1, nums[-1] # 랜선길이를 최소 1부터 배열 내에서 최대값으로 잡아줌
res = 0
while left <= right:
    mid = (left + right) // 2

    cnt = 0
    for num in nums:
        if num >= mid:
            cnt += num // mid

    if cnt >= k:
        left = mid + 1
        res = mid

    else:
        right = mid - 1

print(res)

