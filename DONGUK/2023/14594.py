import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
M = int(input())

actions = []

for _ in range(M):
    left, right = map(int, input().split())
    actions.append((left, right))

sorted_actions = sorted(actions, key=lambda x: x[0])

answer = 0
left, right = 0, 0
for i in range(M):
    next_left, next_right = sorted_actions[i][0], sorted_actions[i][1]

    if next_left > right:
        answer += next_left - right
        left = next_left
        right = max(right, next_right)
    else:
        right = max(right, next_right)

answer += N - right

print(answer)
    