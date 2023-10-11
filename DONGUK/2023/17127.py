import sys

input = sys.stdin.readline

n = int(input())

nums = list(map(int, input().split()))

indexes = [[n-3, 1, 1, 1], [1, n-3, 1, 1], [1, 1, n-3, 1], [1, 1, 1, n-3]]

answer = 0
for index in indexes:
    i = 0
    sum = 0
    for iter in index:
        mul = 1
        for _ in range(iter):
            mul = mul * nums[i]
            i += 1
        sum += mul
    
    answer = max(answer, sum)

print(answer)