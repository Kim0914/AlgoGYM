import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# S = (A[0] * B[0]) + (A[1] * B[1]) + .... (A[N-1] * B[N-1])
A.sort()
B.sort(reverse=True)

ans = 0
for i in range(N):
    ans += A[i] * B[i]

print(ans)