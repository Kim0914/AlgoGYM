import sys
# 0 <= N <= 50 -> 현재 휴게소 개수
# 1 <= M <= 100 -> 더 지으려고 하는 휴게소 개수
# 100 <= L <= 1,000

input = sys.stdin.readline

N, M, L = map(int, input().split())

loads = []
if N > 0:
    loads = list(map(int, input().split()))
loads.append(L)
loads.sort()

diffs = [0] * (N + 1)
diffs[0] = loads[0]
for i in range(1, N+1):
    diffs[i] = loads[i] - loads[i-1]

ans = 0
left, right = 1, L
while left <= right:
    mid = (left + right) // 2

    cnt = 0
    for diff in diffs:
        if diff % mid == 0:
            cnt += (diff // mid) - 1
        else:
            cnt += diff // mid
    # print(left, right, mid, cnt)
    if cnt > M:
        left = mid + 1
        
    else:
        ans = mid
        right = mid - 1
    
print(ans)