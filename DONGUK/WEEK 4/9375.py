n = int(input())

for _ in range(n):
    T = int(input())
    d = {}
    for _ in range(T):
        s1, s2 = input().split()
        if s2 not in d:
            d[s2] = 1
        
        else:
            d[s2] += 1
    
    ans = 1
    for key, value in d.items():
        ans = ans * (value + 1)
    
    print(ans - 1)