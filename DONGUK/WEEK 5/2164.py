from collections import deque
from re import L

queue = deque()

n = int(input())

for i in range(n):
    queue.append(i+1)

ind = 1
while True:
    if n == 1:
        break

    if ind % 2 == 1:
        queue.popleft()

    else:
        num = queue.popleft()
        queue.append(num)
    ind += 1

    if len(queue) == 1:
        break

if n == 1:
    print(1)

else:
    print(queue[0])
