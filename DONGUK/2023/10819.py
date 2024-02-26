import sys

input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))

ans = 0
arr = []
visited = [0] * N
def calc(arr):
    global ans
    if len(arr) == N:
        sum_ = 0
        for i in range(N-1):
            sum_ += abs(arr[i] - arr[i+1])
        ans = max(ans, sum_)
        return

    for i in range(N):
        if visited[i] == 0:
            visited[i] = 1
            arr.append(nums[i])
            calc(arr)
            arr.pop(-1)
            visited[i] = 0


calc(arr)
print(ans)
