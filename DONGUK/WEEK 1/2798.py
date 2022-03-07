N, M = map(int, input().split())

nums = list(map(int, input().split()))


res = 0
for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            if nums[i] + nums[j] + nums[k] > M:
                continue
            else:
                res = max(res, nums[i] + nums[j] + nums[k])

print(res)
