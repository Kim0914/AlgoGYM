from collections import deque
import sys

input = sys.stdin.readline

q = deque()

n = int(input())

for _ in range(n):
    s = input().rstrip().split()

    if s[0] == 'push_back':
        q.append(s[1])
    
    elif s[0] == 'push_front':
        q.appendleft(s[1])

    elif s[0] == 'pop_front':
        if len(q) == 0:
            print(-1)
        
        else:
            print(q.popleft())
    
    elif s[0] == 'pop_back':
        if len(q) == 0:
            print(-1)
        
        else:
            print(q.pop())

        
    elif s[0] == 'size':
        print(len(q))

    
    elif s[0] == 'empty':
        if len(q) == 0:
            print(1)
        
        else:
            print(0)

    elif s[0] == 'front':
        if len(q) == 0:
            print(-1)
        
        else:
            print(q[0])

    elif s[0] == 'back':
        if len(q) == 0:
            print(-1)
        
        else:
            print(q[-1])

    else:
        continue
