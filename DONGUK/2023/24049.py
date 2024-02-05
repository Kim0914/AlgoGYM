import sys

input = sys.stdin.readline

N, M = map(int, input().split())

garden = [[0] * (M+1) for _ in range(N+1)]

lefts = list(map(int, input().split()))
ups = list(map(int, input().split()))

for i in range(1, N+1):
    garden[i][0] = lefts[i-1]

for j in range(1, M+1):
    garden[0][j] = ups[j-1]

for i in range(1, N+1):
    for j in range(1, M+1):
        left = garden[i][j-1]
        up = garden[i-1][j]

        if (left == up):
            garden[i][j] = 0
        else:
            garden[i][j] = 1

print(garden[N][M])
