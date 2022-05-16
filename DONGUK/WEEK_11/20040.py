import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n, m = map(int, input().split())
parents = [0] * (n)

def init():
    for i in range(n):
        parents[i] = i


def find(x):
    if parents[x] != x:
        parents[x] = find(parents[x])
    
    return parents[x]


def union(a, b):
    p1, p2 = find(a), find(b)

    if p1 == p2:
        return True

    else:
        if p1 > p2:
            parents[p1] = p2
        
        else:
            parents[p2] = p1

        
def solve():
    cnt = 0
    flag = False
    for i in range(1, m+1):
        a, b = map(int, input().split())

        if union(a, b) and flag == False:
            cnt = i
            flag = True
            
        
    if flag:
        print(cnt)

    else:
        print(0)

init()

solve()