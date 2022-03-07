N = int(input())
res = []

for num in range(N, 0, -1):
    num_split = list(str(num))

    add = 0
    for n in num_split:
        add += int(n)

    if num + add == N:
        res.append(num)

if len(res) == 0:
    print(0)
else:
    print(min(res))