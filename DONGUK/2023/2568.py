import sys

input = sys.stdin.readline

N = int(input())

infos = []
starts = {}
for _ in range(N):
    a, b = map(int, input().split())
    infos.append([a, b])
    starts[b] = a

infos.sort(key = lambda x : x[0])

lis = [infos[0][1]]
tmp = [1]
for i in range(1, N):
    top_num = lis[-1]
    cur_num = infos[i][1]

    if cur_num > top_num:
        lis.append(cur_num)
        tmp.append(len(lis))
    else:
        left, right = 0, len(lis) - 1
        while left < right:
            mid = (left + right) // 2

            if lis[mid] >= cur_num:
                right = mid
            else:
                left = mid + 1
        lis[right] = cur_num
        tmp.append(right + 1)

print(tmp)
print(lis)

V = len(lis)
print(N - len(lis))
for i in range(len(tmp) - 1, -1, -1):
    if tmp[i] == V:
        V -= 1
    else:
        print(infos[i][0])