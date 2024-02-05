import sys

input = sys.stdin.readline

N = int(input())

boards = [[0] * (N+1) for _ in range(N+1)]

direction_dict = {}

# key = (현재 방향, 다음 방향)
# value = (다음 dx, dy, 다음 방향)
direction_dict[('R', 'L')] = ((-1, 0), 'U')
direction_dict[('R', 'D')] = ((1, 0), 'D')
direction_dict[('L', 'L')] = ((1, 0), 'D')
direction_dict[('L', 'D')] = ((-1, 0), 'U')
direction_dict[('U', 'D')] = ((0, 1), 'R')
direction_dict[('U', 'L')] = ((0, -1), 'L')
direction_dict[('D', 'D')] = ((0, -1), 'L')
direction_dict[('D', 'L')] = ((0, 1), 'R')

K = int(input())

for _ in range(K):
    x, y = map(int, input().split())
    boards[x][y] = 1

L = int(input())

routes = dict()
for _ in range(L):
    time, direction = map(str, input().split())
    routes[int(time)] = direction

answer = -1
snake_dict = dict()
snake_x, snake_y = 1, 1
cur_direction = 'R'
dx, dy = 0, 1
for time in range(1, 100001):
    if time in routes:
        rotation = routes[time]
        data = direction_dict[(cur_direction, rotation)]
        dx, dy = data[0][0], data[0][1]
        cur_direction = data[1]
    
    snake_x += dx
    snake_y += dy

    if not (1 <= snake_x <= N) or not (1 <= snake_y <= N):
        answer = time + 1
        break