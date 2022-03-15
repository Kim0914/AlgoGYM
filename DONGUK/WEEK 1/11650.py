N = int(input())

coords = []
for _ in range(N):
    x, y = map(int, input().split())
    coords.append((x,y))


coords = sorted(coords, key=lambda x: (x[0], x[1]))

for x, y in coords:
    print(x,y)