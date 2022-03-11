import sys
input = sys.stdin.readline

N = int(input())

nums = []
sum_a = 0
min_a = 4000
max_a = -4000
d = {}
for _ in range(N):
    num = int(input())
    sum_a += num
    nums.append(num)
    
    if num not in d:
        d[num] = 1
    
    else:
        d[num] += 1

    if num > max_a: # 최댓값 찾기
        max_a = num
    
    if num < min_a: # 최솟값 찾기
        min_a = num

# 가장 빈도가 높은 수 체크
key_list = []
high = 0
often = 0
for key, value in d.items():
    if value >= high:
        key_list.append(key)
        high = value

key_list = sorted(key_list)

# 빈도가 2개 이상인 것 체크
if len(key_list) > 1:
    often = key_list[1]

else:
    often = key_list[0]

mean = round(sum_a / N)
mid = sorted(nums)[N//2]
range = max_a - min_a
print(d)

print(mean)
print(mid)
print(often)
print(range)