import sys
input = sys.stdin.readline

n = int(input())

conf = []

for _ in range(n):
    s, e = map(int, input().split())
    conf.append((s,e))

conf.sort(key=lambda x: (x[1], x[0]))

end_time = 0
cnt = 0

for start, end in conf:
    if start >= end_time:
        cnt += 1
        end_time = end

print(cnt)