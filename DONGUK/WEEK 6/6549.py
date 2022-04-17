import sys
from collections import deque

input = sys.stdin.readline


while True:
    data = list(map(int, input().split()))

    if len(data) == 1 and data[0] == 0:
        break
    
    N = data.pop(0)
    d = deque()
    ans = 0
    for i in range(N):
        while len(d) > 0 and data[d[-1]] > data[i]:
            tmp = d.pop()

            width = 0
            if len(d) == 0:
                width = i
            
            else:
                width = i - d[-1] - 1
            
            ans = max(ans, width * data[tmp])

        d.append(i)
    
    while len(d) > 0:
        tmp = d.pop()

        width = 0
        if len(d) == 0:
            width = N
            
        else:
            width = N - d[-1] - 1
        
        
        ans = max(ans, width * data[tmp])

    print(ans)