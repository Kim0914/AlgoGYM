import sys, math
from collections import deque
input = sys.stdin.readline
INF = math.inf

N = int(input())
M = int(input())

city = [[INF] * (1+N) for _ in range(1+N)]
trace = [[0] * (1+N) for _ in range(1+N)]

def init():
    for _ in range(M):

        a, b, c = map(int, input().split())

        if city[a][b] != INF:
            if c < city[a][b]:
                city[a][b] = c
            
        else:
            city[a][b] = c
            
            
def floyd():
    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if i == j:
                    city[i][j] = 0
                    continue

                if city[i][j] > city[i][k] + city[k][j]:
                    city[i][j] = city[i][k] + city[k][j]
                    trace[i][j] = k

def find(i, j):
    if trace[i][j] == 0:
        return []
    
    k = trace[i][j]
    return find(i, k) + [k] + find(k, j)


def route():
    for i in range(1, N+1):
        for j in range(1, N+1):
            if city[i][j] == INF:
                print(0, end=' ')
            
            else:
                print(city[i][j], end = ' ')
        print()

    for i in range(1, N+1):
        for j in range(1, N+1):
            if i == j or city[i][j] == INF:
                print(0)
                continue

            path = [i] + find(i, j) + [j]
            
            print(len(path), end = ' ')
            print(*path)


init()
floyd()
route()

