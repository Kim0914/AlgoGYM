import sys
input = sys.stdin.readline

N = int(input())
W = int(input())


dp = [[0] * (W) for _ in range(3)]
coord = [[0] * (W) for _ in range(3)]

locates = []
for _ in range(W):
    a, b = map(int, input().split())
    locates.append((a,b))

for i in range(W):
    locate = locates[i]
    x, y = locate[0], locate[1]

    

