import sys
input = sys.stdin.readline

T = int(input())

def find(x):
    if d[x] != x:
        d[x] = find(d[x])
    
    return d[x]


def union(f1, f2):
    p1, p2 = find(f1), find(f2)

    if p1 != p2:
        d[p2] = p1
        cnt[p1] += cnt[p2]
    


for _ in range(T):
    n = int(input())

    d, cnt = {}, {}
    for _ in range(n):
        f1, f2 = input().split()

        if f1 not in d:
            d[f1] = f1
            cnt[f1] = 1
        
        if f2 not in d:
            d[f2] = f2
            cnt[f2] = 1

        
        union(f1, f2)
        print(cnt[find(f1)])

      
        
