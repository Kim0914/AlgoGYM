import sys
input = sys.stdin.readline

N = int(input())

costs = []
# R G B
for _ in range(N):
    cost = list(map(int, input().split()))
    costs.append(cost)


for i in range(1, N):
    costs[i][0] += min(costs[i-1][1], costs[i-1][2])
    costs[i][1] += min(costs[i-1][0], costs[i-1][2])
    costs[i][2] += min(costs[i-1][0], costs[i-1][1])

print(min(costs[N-1]))