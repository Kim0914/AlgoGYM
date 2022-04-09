from collections import deque
import sys

input = sys.stdin.readline

q = deque()

n, m = map(int, input().split())
nums = list(map(int, input().split()))


for i in range(1, n+1):
    q.append(i)


left_cnt, right_cnt = 0, 0
while nums:
    val = nums[0]
    ind = q.index(val)
    q_len = len(q) // 2

    if ind == 0: # 삭제
        q.popleft()
        nums.pop(0)
    
    elif ind > 0 and ind <= q_len:
        tmp = q.popleft()
        q.append(tmp)
        left_cnt += 1

    
    else:
        tmp = q.pop()
        q.appendleft(tmp)
        right_cnt += 1

print(left_cnt + right_cnt)