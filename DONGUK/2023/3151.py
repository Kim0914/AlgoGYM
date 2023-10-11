import sys

input = sys.stdin.readline

N = int(input())

scores = list(map(int, input().split()))

answer = 0

scores.sort()
for i in range(N-2):
    target_score = -scores[i]

    start = i + 1
    end = N - 1
    mx_idx = N
    while start < end:
        if scores[start] + scores[end] < target_score:
            start += 1
        elif scores[start] + scores[end] > target_score:
            end -= 1
        else:
            if scores[start] == scores[end]:
                answer += end - start
            else:
                if mx_idx > end:
                        mx_idx = end
                        while mx_idx >= 0 and scores[mx_idx - 1] == scores[end]:
                            mx_idx -= 1
                answer += end - mx_idx + 1
            start += 1
print(answer)