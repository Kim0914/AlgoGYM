import sys
input = sys.stdin.readline

n, k = map(int, input().split())

data = []
for _ in range(n):
    data.append(int(input()))

data.sort(reverse=True)


ans = 0
for num in data:
    if num > k:
        continue

    else:
        ans += (k // num)
        k -= num * (k // num)
    
    if k == 0:
        break

print(ans)

