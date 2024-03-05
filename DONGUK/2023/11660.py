# 1 <= N <= 1024
# 1 <= N^2 <= 1,000,000
# 1 <= M <= 100,000

import sys

input = sys.stdin.readline

N, M = map(int, input().split())

graphs = []
for _ in range(N):
    nums = list(map(int, input().split()))
    for i in range(1, N):
        nums[i] = nums[i] + nums[i-1]
    graphs.append(nums)


for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())

    ans = 0
    for i in range(x1-1, x2):
        if y1-1 == 0:
            ans += graphs[i][y2-1]
        else:
            ans += (graphs[i][y2-1] - graphs[i][y1-2])

    print(ans)