import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n = int(input())
m = int(input())
city = [[0] * (1+n) for _ in range(1+n)]
plan = []

def init():
    global plan
    for i in range(1, n+1):
        data = list(map(int, input().split()))
        for j in range(n):
            if data[j] == 1:
                city[i][j+1] = 1
                city[j+1][i] = 1

    plan = list(map(int, input().split()))


def search():
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if city[i][j] == 0:
                    if city[i][k] == 1 and city[k][j] == 1:
                        city[i][j] = 1
                        

def floyd():
    flag = True
    for i in range(len(plan) - 1):
        start, end = plan[i], plan[i+1]

        if city[start][end] == 0 and start != end: # 자기 자신은 갈 수 있는 것이 조건
            flag = False
            break

    return flag

init()
search()


if floyd():
    print('YES')

else:
    print('NO')
