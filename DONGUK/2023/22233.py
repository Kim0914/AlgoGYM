import sys

input = sys.stdin.readline

N, M = map(int, input().split())

word_dict = dict()
keyword_count = 0

for _ in range(N):
    word = input().strip()

    if word not in word_dict:
        word_dict[word] = 1
        keyword_count += 1


for _ in range(M):
    keywords = input().strip().split(',')

    for keyword in keywords:
        if keyword in word_dict and word_dict[keyword] > 0:
            word_dict[keyword] -= 1
            keyword_count -= 1

    print(keyword_count)