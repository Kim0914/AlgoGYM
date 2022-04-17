n, c = map(int,input().split())

dis = []
for _ in range(n):
    dis.append(int(input()))

dis.sort()

start, end = 1, (dis[-1] - dis[0] + 1)

res = 0
while start <= end:
    mid = (start + end) // 2  # 집 간 간격을 변수로 둔다

    cnt = 1
    tmp = dis[0]
    for i in range(1, n):
        if dis[i] - tmp >= mid:
            cnt += 1
            tmp = dis[i]

    
    if cnt >= c:
        start = mid + 1
        res = mid
    
    else:
        end = mid - 1

print(res)
