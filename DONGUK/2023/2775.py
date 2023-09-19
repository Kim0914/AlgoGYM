import sys

input = sys.stdin.readline

t = int(input())

boards = [[0] * 15 for _ in range(15)]

for i in range(15):
    for j in range(15):
        if i == 0:
            boards[i][j] = j+1
            continue
        
        if j == 0:
            boards[i][j] = boards[i-1][j]
        else:
            boards[i][j] = boards[i][j-1] + boards[i-1][j]

for _ in range(t):
    n = int(input())
    k = int(input())

    print(boards[n][k-1])