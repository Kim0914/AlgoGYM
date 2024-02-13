import sys

input = sys.stdin.readline

N = int(input())

moneys = list(map(int, input().split()))

M = int(input())

start, end = 1, max(moneys)

ans = 1
while start <= end:
    mid = (start + end) // 2

    sum_ = 0
    for money in moneys:
        if money >= mid:
            sum_ += mid
        else:
            sum_ += money
    
    if sum_ <= M:
        ans = max(ans, mid)
        start = mid + 1
    else:
        end = mid - 1

print(ans)