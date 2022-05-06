import sys, math
input = sys.stdin.readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))


start, end = 0, 0
arr_sum = 0
min_len = math.inf

while True:
    if arr_sum >= S:
        min_len = min(min_len, end - start)
        arr_sum -= nums[start]
        start += 1
    
    elif end == N:
        break

    else:
        arr_sum += nums[end]
        end += 1


if min_len == math.inf:
    print(0)

else:
    print(min_len)
        
