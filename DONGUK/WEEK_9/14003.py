import sys
from collections import deque
from bisect import bisect_left
input = sys.stdin.readline

n = int(input())
prior_ind = [0] * n
nums = list(map(int, input().split()))
max_len = 0

stack = deque()
for i in range(n):
    if i == 0:
        stack.append(nums[i])
        prior_ind[i] = 1
        continue

    if nums[i] > stack[-1]:
        stack.append(nums[i])
        prior_ind[i] = len(stack)
        max_len = prior_ind[i]

    else:
        ind = bisect_left(stack, nums[i])
        stack[ind] = nums[i]
        prior_ind[i] = ind + 1


print(max_len)

ans = deque()
for i in range(n-1, -1, -1):
    if prior_ind[i] == max_len:
        ans.appendleft(nums[i])
        max_len -= 1

    if max_len == 0:
        break

print(*ans)

'''
해당 자리에 있을 때 스택의 길이를 저장해 놓는 것이 포인트
최대 길이 부터 하나씩 내려가면서 해당 길이를 가지는 원소를 찾으면 된다
'''
