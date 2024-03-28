N, K = map(int, input().split())

temps = list(map(int, input().split()))

max_temp = -1000000000
start, end = 0, K-1
temp_sum = sum(temps[start:end+1])
while True:
    max_temp = max(max_temp, temp_sum)
    temp_sum -= temps[start]
    start += 1
    end += 1
    if end == N:
        break
    temp_sum += temps[end]

print(max_temp)