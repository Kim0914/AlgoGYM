import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
dp = [0] * (N+1)
prior_num = [0] * (N+1)

def search(node):
    queue = deque()
    queue.append(node)

    while queue:
        top = queue.popleft()
        
        if top == 1:
            return

        if dp[top-1] == 0:
            dp[top-1] = dp[top] + 1
            prior_num[top - 1] = top

            queue.append(top-1)

        if top % 2 == 0 and dp[top//2] == 0:
            dp[top//2] = dp[top] + 1
            prior_num[top // 2] = top

            queue.append(top//2)

        if top % 3 == 0 and dp[top//3] == 0:
            dp[top//3] = dp[top] + 1
            prior_num[top // 3] = top

            queue.append(top//3)
        
        
search(N)

print(dp[1])

if N == 1:
    print(1)

else:
    ans = [1]
    next_num = prior_num[1]

    if next_num == N:
        ans.append(next_num)

    while next_num != N:
        ans.append(next_num)
        next_num = prior_num[next_num]

        if next_num == N:
            ans.append(next_num)

    print(*ans[::-1])