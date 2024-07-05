import sys

input = sys.stdin.readline

N, K = map(int, input().split())

scores = list(map(int, input().split()))

scores_sum = [0] * (N + 1)
scores_sum[1] = 1
for i in range(1, N+1):
    scores_sum[i] = scores[i-1] + scores_sum[i-1]

for _ in range(K):
    left, right = map(int, input().split())
    score_sum = scores_sum[right] - scores_sum[left - 1]
    mean_score = score_sum / (right - left + 1)
    print(round(mean_score, 2))