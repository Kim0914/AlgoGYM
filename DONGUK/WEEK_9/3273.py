import sys

input = sys.stdin.readline

n = int(input()) # max 100000
nums = list(map(int, input().split()))
x = int(input())

d = {}

for i in range(n):
    num = nums[i]

    if num not in d:
        d[num] = (num, i) # 숫자, 인덱스로 저장

cnt = 0
for i in range(n):
    num = nums[i]
    sub = x - num

    if sub in d and i < d[sub][1]:
        cnt +=1

print(cnt)