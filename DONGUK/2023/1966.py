import sys
from collections import deque
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    N, M = map(int, input().split())

    nums = deque()
    
    input_nums = list(map(int, input().split()))
    i = 0
    for num in input_nums:
        nums.append((num, i))
        i += 1
    
    input_nums = deque(sorted(input_nums, reverse=True))
    max_num = input_nums.popleft()

    cnt = 1
    while nums:
        val, index = nums.popleft()

        if val == max_num:
            if index == M:
                print(cnt)
                break
            else:
                cnt += 1
                max_num = input_nums.popleft()
            
        nums.append((val, index))