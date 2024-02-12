import sys

input = sys.stdin.readline

N, M = map(int, input().split())

colors = []
for _ in range(M):
    colors.append(int(input()))


left = 1
right = max(colors)

ans = right
while left <= right:
    mid = (left + right) // 2

    count = 0
    for color in colors:
        if color % mid == 0:
            count += color // mid
        else:
            count += (color // mid) + 1

    if count <= N:
        ans = min(ans, mid)
        right = mid - 1 
    else:
        left = mid + 1

print(ans)