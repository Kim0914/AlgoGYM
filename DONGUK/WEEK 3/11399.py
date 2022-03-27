import sys

input = sys.stdin.readline


n = int(input())
people = list(map(int, input().split()))


people.sort()

res = [0] * n

for i in range(n):
    if i == 0:
        res[i] = people[i]
    
    else:
        res[i] = res[i-1] + people[i]

print(sum(res))