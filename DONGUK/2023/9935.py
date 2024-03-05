from collections import deque
import sys

input = sys.stdin.readline

words = input().strip()

bomb = input().rstrip()
N = len(bomb)
stack = list()

for word in words:
    stack.append(word)
    S = len(stack)
    if stack and S >= N:
        cmp = stack[S-N:S]
        cmp = ''.join(cmp)
        if cmp == bomb:
            for _ in range(N):
                stack.pop(-1)
        
if stack:
    print(''.join(stack))
else:
    print('FRULA')