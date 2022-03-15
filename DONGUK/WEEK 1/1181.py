import sys
input = sys.stdin.readline

N = int(input())
strings = []

for _ in range(N):
    c = input().rstrip('\n')
    strings.append((c, len(c))) # (단어, 길이)

strings = list(set(strings)) # 중복제거
answer = sorted(strings, key=lambda x: (x[1], x[0]))

for ans in answer:
    print(ans[0])