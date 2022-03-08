N = int(input())

info = []
answer = []

for _ in range(N):
    a, b = map(int, input().split())
    info.append((a,b))

print(info)

for data in info:
    cnt = 0
    for other_data in info:
        if data == other_data:
            continue
        else:
            if data[0] < other_data[0] and data[1] < other_data[1]:
                cnt += 1
    
    answer.append(cnt + 1)

for ans in answer:
    print(ans, end = ' ')