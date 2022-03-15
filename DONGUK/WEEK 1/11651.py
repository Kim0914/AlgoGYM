import sys

input = sys.stdin.readline

N = int(input())

coords = []
for _ in range(N):
    x, y = map(int, input().split())
    coords.append((x,y))


coords = sorted(coords, key=lambda x: (x[1], x[0]))

for x, y in coords:
    print(x,y)