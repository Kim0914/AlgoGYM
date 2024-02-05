import sys

input = sys.stdin.readline

N = int(input())

nums = []
for _ in range(N):
    nums.append(int(input()))

nums.sort(reverse=True)


answer = []
for i in range(1, N+1):
    weight = nums[i-1] * i

    answer.append(weight)

print(max(answer))